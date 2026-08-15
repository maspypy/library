
#include "poly/fps_exp.hpp"
#include "poly/2d/fps_log_2d.hpp"
#include "poly/2d/convolution2d.hpp"

// 注意 (H+W)^2log(H+W) 時間になっているので正方形じゃないとダメなさぼり実装
// template <typename mint>
// vvc<mint> fps_exp_2d(vvc<mint> F) {
//   int N = len(F) - 1, M = len(F[0]) - 1;
//   int L = 1;
//   while (L < N + M + 1) L *= 2;

//   vv(mint, F1, L, N + M + 1);
//   FOR(i, N + 1) FOR(j, M + 1) F1[i][i + j] = F[i][j];

//   FOR(j, N + M + 1) {
//     vc<mint> f(L);
//     FOR(i, L) f[i] = F1[i][j];
//     ntt(f, false);
//     FOR(i, L) F1[i][j] = f[i];
//   }
//   FOR(i, L) { F1[i] = fps_exp<mint>(F1[i]); }
//   FOR(j, N + M + 1) {
//     vc<mint> f(L);
//     FOR(i, L) f[i] = F1[i][j];
//     ntt(f, true);
//     FOR(i, L) F1[i][j] = f[i];
//   }
//   FOR(i, N + 1) FOR(j, M + 1) F[i][j] = F1[i][i + j];
//   return F;
// }

template <typename mint>
vvc<mint> fps_exp_2d(vvc<mint> F) {
  int N = len(F), M = len(F[0]);
  assert(F[0][0] == mint(0));

  vv(mint, G, N, M);
  G[0] = fps_exp<mint>(F[0]);

  int H = 1;
  while (H < N) {
    int H2 = min(2 * H, N);

    vv(mint, f, H2, M);
    vv(mint, g, H2, M);
    FOR(i, H2) FOR(j, M) f[i][j] = F[i][j];
    FOR(i, H) FOR(j, M) g[i][j] = G[i][j];

    auto lg = fps_log_2d<mint>(g);

    // e = 1 + f - log(g)
    vv(mint, e, H2, M);
    FOR(i, H2) FOR(j, M) e[i][j] = f[i][j] - lg[i][j];
    e[0][0] += mint(1);

    g = convolution2d<mint>(g, e, true);
    FOR(i, H, H2) FOR(j, M) G[i][j] = g[i][j];
    H *= 2;
  }
  return G;
}
