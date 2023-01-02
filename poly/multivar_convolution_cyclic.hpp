#include "poly/multipoint.hpp"
#include "mod/primitive_root.hpp"

/*
(n0, n1, n2, ...) 進法での繰り上がりのない足し算に関する畳み込み

example : ns = (2, 3) → 1 の位から順に 2, 3 進法
[a0, a1, a2, a3, a4, a5] = [a(0,0), a(1,0), a(0,1), a(1,1), a(0,2), a(1,2)]
[b0, b1, b2, b3, b4, b5] = [b(0,0), b(1,0), b(0,1), b(1,1), b(0,2), b(1,2)]
c(0,2) = a(0,0)b(0,2) + a(0,1)b(0,1) + a(0,2)b(1,1)
c4 = a0b4 + a2b2 + a4b0

example : ns = (2, 2, ..., 2, 2) → subset convolution
*/
template <typename mint>
vc<mint> multivar_convolution_cyclic(vc<int> ns, vc<mint> f, vc<mint>& g) {
  int p = mint::get_mod();
  for (auto&& n: ns) assert((p - 1) % n == 0);
  mint r = primitive_root(p);
  mint ir = r.inverse();

  int K = len(ns);
  int N = 1;
  for (auto&& n: ns) N *= n;
  assert(len(f) == N);
  assert(len(g) == N);
  vc<mint> root(K), iroot(K);

  FOR(k, K) { root[k] = r.pow((p - 1) / ns[k]); }
  FOR(k, K) { iroot[k] = ir.pow((p - 1) / ns[k]); }

  int step = 1;
  FOR(k, K) {
    int n = ns[k];
    FOR(i, N) if (i % (step * n) < step) {
      vc<mint> a(n), b(n);
      FOR(j, n) {
        a[j] = f[i + step * j];
        b[j] = g[i + step * j];
      }
      a = multipoint_eval_on_geom_seq(a, mint(1), root[k], n);
      b = multipoint_eval_on_geom_seq(b, mint(1), root[k], n);
      FOR(j, n) {
        f[i + step * j] = a[j];
        g[i + step * j] = b[j];
      }
    }
    step *= n;
  }

  FOR(i, N) f[i] *= g[i];

  step = 1;
  FOR(k, K) {
    int n = ns[k];
    FOR(i, N) if (i % (step * n) < step) {
      vc<mint> a(n);
      FOR(j, n) { a[j] = f[i + step * j]; }
      a = multipoint_eval_on_geom_seq(a, mint(1), iroot[k], n);
      FOR(j, n) { f[i + step * j] = a[j]; }
    }
    step *= n;
  }

  mint cf = mint(N).inverse();
  for (auto&& x: f) x *= cf;
  return f;
}

template <typename mint>
vc<vc<mint>> multivar_convolution_cyclic_2d(vc<vc<mint>>& f, vc<vc<mint>>& g) {
  int H = len(f);
  int W = len(f[0]);
  assert(len(g) == H);
  assert(len(g[0]) == W);
  vc<mint> F(H * W), G(H * W);
  FOR(x, H) FOR(y, W) F[x + H * y] = f[x][y];
  FOR(x, H) FOR(y, W) G[x + H * y] = g[x][y];
  F = multivar_convolution_cyclic(vc<int>({H, W}), F, G);
  vv(mint, h, H, W);
  FOR(x, H) FOR(y, W) h[x][y] = F[x + H * y];
  return h;
}
