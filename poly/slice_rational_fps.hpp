#include "poly/convolution.hpp"
#include "poly/middle_product.hpp"
#include "poly/transposed_ntt.hpp"
#include "poly/fps_div.hpp"
#include "poly/poly_divmod.hpp"

template <typename mint>
vc<mint> slice_rational_fps_ntt(vector<mint> P, vector<mint> Q, ll L, ll R) {
  while (len(Q) && Q.back() == mint(0)) POP(Q);
  assert(Q[0] == mint(1));
  if (len(Q) == 1) {
    vc<mint> ANS(R - L);
    FOR(i, L, R) if (i < len(P)) ANS[i - L] = P[i];
    return ANS;
  }
  vc<mint> Q0 = Q;

  int n = 1;
  while (n < len(Q)) n += n;
  Q.resize(2 * n), ntt(Q, 0);

  vc<mint> W(n);
  {
    vc<int> btr(n);
    int log = topbit(n);
    FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }
    int t = mint::ntt_info().fi;
    mint r = mint::ntt_info().se;
    mint dw = r.inverse().pow((1 << t) / (2 * n));
    mint w = 1;
    for (auto& i: btr) { W[i] = w, w *= dw; }
  }

  mint z = W[n / 2].inverse();
  auto doubling = [&](vc<mint> f, bool t) -> vc<mint> {
    mint r = 1;
    if (!t) {
      vc<mint> g(2 * n);
      copy(all(f), g.begin());
      ntt(f, 1);
      FOR(i, 1, n) r *= z, f[i] *= r;
      ntt(f, 0);
      copy(all(f), g.begin() + n);
      return g;
    } else {
      vc<mint> g = {f.begin(), f.begin() + n};
      f = {f.begin() + n, f.begin() + 2 * n};
      transposed_ntt(f, 0);
      FOR(i, 1, n) r *= z, f[i] *= r;
      transposed_ntt(f, 1);
      FOR(i, n) g[i] += f[i];
      return g;
    }
  };

  auto dfs = [&](auto& dfs, vc<mint> Q, ll N) -> vc<mint> {
    vc<mint> nxt_Q(2 * n);
    FOR(i, n) nxt_Q[i] = Q[2 * i] * Q[2 * i + 1];
    nxt_Q.resize(n);
    vc<mint> p;
    if (N / 2 >= n) {
      nxt_Q = doubling(nxt_Q, 0);
      p = dfs(dfs, nxt_Q, N / 2);
      p = doubling(p, 1);
    } else {
      ntt(nxt_Q, 1);
      nxt_Q = fps_inv<mint>(nxt_Q);
      p.resize(n);
      FOR(i, N / 2 + 1) p[i] += nxt_Q[N / 2 - i];
      transposed_ntt(p, 1);
    }
    assert(len(p) == n);
    p.resize(2 * n);
    if (N % 2 == 0) {
      FOR_R(i, n) {
        p[2 * i + 1] = Q[2 * i + 0] * inv<mint>(2) * p[i];
        p[2 * i + 0] = Q[2 * i + 1] * inv<mint>(2) * p[i];
      }
    } else {
      FOR_R(i, n) {
        p[2 * i + 1] = -Q[2 * i + 0] * inv<mint>(2) * W[i] * p[i];
        p[2 * i + 0] = Q[2 * i + 1] * inv<mint>(2) * W[i] * p[i];
      }
    }
    assert(len(p) == 2 * n);
    return p;
  };

  vc<mint> p = dfs(dfs, Q, L + n - 1);
  transposed_ntt(p, 0);
  p.resize(n);
  reverse(all(p));
  swap(Q, Q0);
  p.resize(len(Q) - 1);
  // 1/Q の L 以降が p ではじまる
  auto [f, g] = poly_divmod(P, Q);
  p = convolution<mint>(p, Q);
  p.resize(len(Q) - 1);
  p = convolution<mint>(p, g);
  p = poly_divmod(p, Q).se;
  p.resize(R - L);
  Q.resize(R - L);
  p = fps_div<mint>(p, Q);
  FOR(i, L, len(f)) if (i < R) p[i - L] += f[i];
  return p;
}

template <typename mint>
vc<mint> slice_rational_fps_convolution(vc<mint> P, vc<mint> Q, ll L, ll R) {
  assert(L >= 0 && Q[0] == mint(1) && len(P) < len(Q));
  const int d = len(Q) - 1;
  if (d == 0) { return vc<mint>(); }
  P.resize(len(Q) - 1);

  auto dfs = [&](auto& dfs, ll N, vc<mint> Q) -> vc<mint> {
    // 1/Q の [N-d+1, N]
    if (N == 0) {
      vc<mint> f(d);
      f[d - 1] = 1;
      return f;
    }
    vc<mint> R = Q;
    FOR(i, d + 1) if (i & 1) R[i] = -R[i];
    vc<mint> V = convolution(Q, R);
    FOR(i, d + 1) V[i] = V[2 * i];
    V.resize(d + 1);
    vc<mint> W = dfs(dfs, N / 2, V);
    vc<mint> S(d + d);
    if (N % 2 == 0) FOR(i, d) S[2 * i + 1] = W[i];
    if (N % 2 == 1) FOR(i, d) S[2 * i] = W[i];
    reverse(all(R));
    return middle_product(S, R);
  };
  vc<mint> A = dfs(dfs, L, Q);
  vc<mint> f = convolution(A, Q);
  f = {f.begin() + d, f.end() - 1};
  f = fps_div(f, Q);
  for (auto&& x: f) x = -x;
  A.insert(A.end(), all(f));
  reverse(all(P));
  f = middle_product(A, P);
  f = convolution<mint>(f, Q);
  f.resize(d);
  f.resize(R - L);
  f = fps_div<mint>(f, Q);
  return f;
}

template <typename mint>
vc<mint> slice_rational_fps(vc<mint>& P, vc<mint>& Q, ll L, ll R) {
  assert(L <= R);
  if (L == R) return {};
  if (R < 0) { return vc<mint>(R - L, 0); }
  if (L < 0) {
    vc<mint> f = slice_rational_fps<mint>(P, Q, 0, R);
    vc<mint> res(R - L);
    FOR(i, 0, R) res[i - L] = f[i];
    return res;
  }
  if constexpr (mint::can_ntt()) {
    return slice_rational_fps_ntt(P, Q, L, R);
  } else {
    return slice_rational_fps_convolution(P, Q, L, R);
  }
}