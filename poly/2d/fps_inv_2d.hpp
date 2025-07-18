#include "poly/fps_inv.hpp"

// 注意 (H+W)^2log(H+W) 時間になっているので正方形じゃないとダメなさぼり実装
template <typename mint>
vvc<mint> fps_inv_2d(vvc<mint> F) {
  int N = len(F) - 1, M = len(F[0]) - 1;
  int L = 1;
  while (L < N + M + 1) L *= 2;

  vv(mint, F1, L, N + M + 1);
  FOR(i, N + 1) FOR(j, M + 1) F1[i][i + j] = F[i][j];

  FOR(j, N + M + 1) {
    vc<mint> f(L);
    FOR(i, L) f[i] = F1[i][j];
    ntt(f, false);
    FOR(i, L) F1[i][j] = f[i];
  }
  FOR(i, L) F1[i] = fps_inv<mint>(F1[i]);
  FOR(j, N + M + 1) {
    vc<mint> f(L);
    FOR(i, L) f[i] = F1[i][j];
    ntt(f, true);
    FOR(i, L) F1[i][j] = f[i];
  }
  FOR(i, N + 1) FOR(j, M + 1) F[i][j] = F1[i][i + j];
  return F;
}

// template <typename mint>
// vvc<mint> fps_inv_2d(vvc<mint> F) {
//   // とりあえずこれはバグってるっぽいｗｗｗ
//   int n = len(F), m = len(F[0]);
//   assert(F[0][0] != mint(0));

//   auto ntt_x = [&](vvc<mint>& F, bool inverse) -> void {
//     // FOR(i, len(F)) ntt(F[i], inverse);
//     FOR(j, len(F[0])) {
//       vc<mint> f(len(F));
//       FOR(i, len(F)) f[i] = F[i][j];
//       ntt(f, inverse);
//       FOR(i, len(F)) F[i][j] = f[i];
//     }
//     return;
//   };

//   int W = 1;
//   while (W < 2 * len(F[0])) W *= 2;

//   FOR(i, n) F[i].resize(W);
//   vv(mint, G, n, W);
//   G[0] = fps_inv(F[0]);

//   FOR(i, n) ntt(F[i], false);
//   ntt(G[0], false);

//   int H = 1;
//   while (H < n) {
//     vv(mint, f, 2 * H, W);
//     vv(mint, g, 2 * H, W);
//     FOR(i, min(n, 2 * H)) FOR(j, W) f[i][j] = F[i][j];
//     FOR(i, H) FOR(j, W) g[i][j] = G[i][j];
//     ntt_x(f, false), ntt_x(g, false);
//     FOR(i, 2 * H) FOR(j, W) f[i][j] *= g[i][j];
//     ntt_x(f, true);
//     FOR(i, H, 2 * H) ntt(f[i], true);
//     FOR(i, H) FOR(j, W) f[i][j] = 0;
//     FOR(i, H, 2 * H) FOR(j, m, W) f[i][j] = 0;
//     FOR(i, H, 2 * H) ntt(f[i], false);
//     ntt_x(f, false);
//     FOR(i, 2 * H) FOR(j, W) f[i][j] *= g[i][j];
//     ntt_x(f, true);
//     FOR(i, H, min(n, 2 * H)) {
//       ntt(f[i], true);
//       FOR(j, m, W) f[i][j] = 0;
//       ntt(f[i], false);
//       FOR(j, W) { G[i][j] -= f[i][j]; }
//     }
//     H *= 2;
//   }
//   FOR(i, n) ntt(G[i], true);
//   FOR(i, n) G[i].resize(m);
//   return G;
// }