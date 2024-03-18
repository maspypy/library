#include "poly/differentiate.hpp"
#include "poly/composition.hpp"
#include "poly/fps_div.hpp"
#include "poly/coef_of_fps_pows.hpp"

// O(N^2)
template <typename mint>
vc<mint> compositional_inverse_old(const vc<mint>& F) {
  const int N = len(F);
  if (N == 0) return {};
  assert(F[0] == mint(0));
  if (N == 1) return F;
  assert(F[0] == mint(0) && F[1] != mint(0));
  vc<mint> DF = differentiate(F);

  vc<mint> G(2);
  G[1] = mint(1) / F[1];
  while (len(G) < N) {
    // G:= G(x)-(F(G(x))-x)/DF(G(x))
    int n = len(G);
    vc<mint> G1, G2;
    {
      vc<mint> FF(2 * n), GG(2 * n), DFF(n);
      FOR(i, min<int>(len(F), 2 * n)) FF[i] = F[i];
      FOR(i, min<int>(len(DF), n)) DFF[i] = DF[i];
      FOR(i, n) GG[i] = G[i];
      G1 = composition(FF, GG);
      G2 = composition(DFF, G);
    }
    G1 = {G1.begin() + n, G1.end()};
    G1 = fps_div(G1, G2);
    G.resize(2 * n);
    FOR(i, n) G[n + i] -= G1[i];
  }
  G.resize(N);
  return G;
}

// https://noshi91.hatenablog.com/entry/2024/03/16/224034
// O(Nlog^2N)
template <typename mint>
vc<mint> compositional_inverse(vc<mint> f) {
  const int n = len(f) - 1;
  if (n == -1) return {};
  assert(f[0] == mint(0));
  if (n == 0) return f;
  assert(f[1] != mint(0));
  mint c = f[1];
  for (auto& x: f) x /= c;

  vc<mint> A = coef_of_fps_pows<mint>(f, n, n);
  for (auto& x: A) x *= mint(n);
  vc<mint> h(n);
  FOR(k, 1, n + 1) { h[n - k] = A[k] * inv<mint>(k); }
  h = fps_pow_1<mint>(h, -inv<mint>(n));
  h.insert(h.begin(), 0);
  mint pow = 1;
  FOR(i, len(h)) h[i] *= pow, pow /= c;
  return h;
}

// G->F(G), G->DF(G) を与える
// len(G) まで求める. len(F) まで求めてもいいよ.
// 計算量は合成とだいたい同等
template <typename mint, typename F1, typename F2>
vc<mint> compositional_inverse(const vc<mint>& F, F1 comp_F, F2 comp_DF) {
  const int N = len(F);
  assert(N <= 0 || F[0] == mint(0));
  assert(N <= 1 || F[1] != mint(0));

  vc<mint> G(2);
  G[1] = mint(1) / F[1];
  while (len(G) < N) {
    int n = len(G);
    // G:= G(x)-(F(G(x))-x)/DF(G(x))
    vc<mint> G2 = comp_DF(G);
    G.resize(2 * n);
    vc<mint> G1 = comp_F(G);
    G1 = {G1.begin() + n, G1.end()};
    G1 = fps_div(G1, G2);
    FOR(i, n) G[n + i] -= G1[i];
  }
  G.resize(N);
  return G;
}