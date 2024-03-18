#include "poly/convolution2d.hpp"
#include "poly/fps_div.hpp"
#include "poly/fps_pow.hpp"

// https://noshi91.hatenablog.com/entry/2024/03/16/224034
// k を固定して [x^k]f(x)^ig(x) を i=0,1,...,n で求める.
template <typename mint>
vc<mint> coef_of_fps_pows(vc<mint> f, int k, int n, vc<mint> g = {mint(1)}) {
  assert(len(f) == k + 1);
  vv(mint, P, k + 1, 2);
  vv(mint, Q, k + 1, 2);
  Q[0][0] = 1;
  FOR(i, len(g)) if (i <= k) P[i][0] = g[i];
  FOR(i, len(f)) if (i <= k) Q[i][1] = -f[i];
  FOR(i, len(f)) Q[i][1] = -f[i];

  while (k > 0) {
    int H = len(P), W = len(P[0]);
    vvc<mint> R = Q;
    FOR(i, H) {
      if (i % 2 == 0) continue;
      FOR(j, W) { R[i][j] = -R[i][j]; }
    }
    vvc<mint> F = convolution2d<mint>(P, R);
    vvc<mint> G = convolution2d<mint>(Q, R);
    P.resize(k / 2 + 1);
    Q.resize(k / 2 + 1);
    FOR(i, len(P)) P[i] = F[2 * i | (k & 1)];
    FOR(i, len(Q)) Q[i] = G[2 * i];
    k /= 2;
    FOR(i, len(P)) if (len(P[i]) > n + 1) P[i].resize(n + 1);
    FOR(i, len(Q)) if (len(Q[i]) > n + 1) Q[i].resize(n + 1);
  }
  vc<mint> F = P[0], G = Q[0];
  F.resize(n + 1), G.resize(n + 1);
  return fps_div<mint>(F, G);
}
