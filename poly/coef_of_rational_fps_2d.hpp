#include "poly/convolution.hpp"
#include "poly/fps_div.hpp"

// P, Q が x について O(1) 次であるとする
// ANS(x) = [y^N]P/Q を M 次まで
// https://atcoder.jp/contests/nadafes2022_day2/tasks/nadafes2022_day2_p
template <typename mint>
vc<mint> coef_of_rational_fps_2d(vvc<mint> P, vvc<mint> Q, int N, int M) {
  int m = max(len(P[0]) - 1, len(Q[0]) - 1);
  chmin(m, N);
  FOR(i, len(P)) P[i].resize(m + 1);
  FOR(i, len(Q)) Q[i].resize(m + 1);
  if (len(P) > M + 1) P.resize(M + 1);
  if (len(Q) > M + 1) Q.resize(M + 1);
  while (len(P) < len(Q)) P.eb(vc<mint>(m + 1));
  while (len(Q) < len(P)) Q.eb(vc<mint>(m + 1));

  // P(y)Q(-y) の特定の parity, Q(y)Q(-y) の偶数次を取り出す
  while (N > 0) {
    if (len(P[0]) > N + 1) FOR(i, len(P)) P[i].resize(N + 1);
    if (len(Q[0]) > N + 1) FOR(i, len(Q)) Q[i].resize(N + 1);
    if (len(P) > M + 1) P.resize(M + 1);
    if (len(Q) > M + 1) Q.resize(M + 1);

    int H = len(P), W = len(P[0]);
    assert(len(Q) == H && len(Q[0]) == W);
    // (H,W) and (H,W)
    // (i,j) -> 2Wi + j
    ll L = 1;
    while (L < 4 * H * W) L *= 2;
    vc<mint> F(L), G(L);
    FOR(i, H) FOR(j, W) F[2 * W * i + j] = P[i][j];
    FOR(i, H) FOR(j, W) G[2 * W * i + j] = Q[i][j];

    int parity = N & 1;

    ntt(F, false);
    ntt(G, false);
    FOR(i, L / 2) F[2 * i + 0] *= G[2 * i + 1], F[2 * i + 1] *= G[2 * i + 0];
    FOR(i, L / 2) G[i] = G[2 * i + 0] * G[2 * i + 1];
    G.resize(L / 2);
    ntt(F, true); // さぼり
    ntt(G, true);

    vv(mint, nxtP, 2 * H - 1, W);
    vv(mint, nxtQ, 2 * H - 1, W);
    FOR(i, 2 * H - 1) FOR(j, W) { nxtP[i][j] = F[2 * W * i + (2 * j + parity)]; }
    FOR(i, 2 * H - 1) FOR(j, W) { nxtQ[i][j] = G[W * i + j]; }
    swap(P, nxtP), swap(Q, nxtQ);
    N /= 2;
  }
  vc<mint> f(M + 1), g(M + 1);
  FOR(i, M + 1) if (i < len(P)) f[i] = P[i][0];
  FOR(i, M + 1) if (i < len(Q)) g[i] = Q[i][0];
  return fps_div<mint>(f, g);
}
