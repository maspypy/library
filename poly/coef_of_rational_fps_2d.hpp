#include "poly/convolution.hpp"
#include "poly/fps_div.hpp"
#include "linalg/transpose.hpp"

// P, Q が x について O(1) 次であるとする
// ANS(x) = [y^N]P/Q を M 次まで
// https://atcoder.jp/contests/nadafes2022_day2/tasks/nadafes2022_day2_p
// (2^n,2^m) 次がたくさん出てきていると定数倍がひどくなってしまう
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

/*
[y^N] F(x,y)/G(x,y) を [x^M] まで。
[y^0] G = 1 を仮定している。
deg G = (3, 1) の (N,M)=(3×10^6,10^6) で 400 ms の実績があるが、かなり疎だからかも。
https://atcoder.jp/contests/agc058/tasks/agc058_d
*/
template <typename mint>
vc<mint> coef_of_rational_fps_2d_old(vector<vector<mint>> F, vector<vector<mint>> G, int N, int M) {
  using poly = vc<mint>;
  assert(G[0][0] == mint(1));
  F = transpose(F), G = transpose(G);
  FOR(j, 1, len(G[0])) assert(G[0][j] == mint(0));

  // x^N mod reverse(G) を計算する
  int m = len(G) - 1;

  auto add_at = [&](poly& f, int i, mint x) -> void {
    if (len(f) <= i) f.resize(i + 1);
    f[i] += x;
  };

  auto simplify = [&](poly& f) -> void {
    if (len(f) >= M + 1) f.resize(M + 1);
    while (len(f) && f.back() == mint(0)) f.pop_back();
  };

  auto dfs = [&](auto& dfs, int n) -> vc<poly> {
    if (n == 0) { return {poly({mint(1)})}; }
    vc<poly> f = dfs(dfs, n / 2);
    // 2 乗したい
    int nf = 0;
    FOR(i, len(f)) chmax(nf, len(f[i]));
    int K = 1;
    while (K < 2 * nf) K *= 2;
    FOR(i, len(f)) {
      f[i].resize(K);
      ntt(f[i], 0);
    }
    vc<poly> g(2 * len(f) - 1);
    FOR(i, 2 * len(f) - 1) g[i].resize(K);
    FOR(i, len(f)) FOR(j, len(f)) { FOR(k, K) g[i + j][k] += f[i][k] * f[j][k]; }
    FOR(i, len(g)) ntt(g[i], 1);
    swap(f, g);

    if (n % 2 == 1) { f.insert(f.begin(), poly({})); }
    FOR_R(i, m, len(f)) {
      FOR(j, 1, m + 1) {
        FOR(ny, len(G[j])) {
          mint cf = -G[j][ny];
          if (cf == mint(0)) continue;
          FOR(k, len(f[i])) {
            mint& x = f[i][k];
            if (x == mint(0)) continue;
            add_at(f[i - j], k + ny, cf * x);
          }
        }
      }
    }
    f.resize(m);
    FOR(i, m) simplify(f[i]);
    return f;
  };

  vc<poly> h = dfs(dfs, N);
  // 線形漸化式の最初の方を求める
  vc<poly> A(m);
  FOR(i, m) {
    A[i] = (i < len(F) ? F[i] : poly());
    FOR(j, 1, i + 1) {
      int k = i - j;
      poly tmp = convolution(A[k], G[j]);
      FOR(t, len(tmp)) { add_at(A[i], t, -tmp[t]); }
    }
  }

  vc<mint> res(M + 1);
  FOR(i, m) {
    vc<mint> f = convolution(h[i], A[i]);
    f.resize(M + 1);
    FOR(i, len(f)) add_at(res, i, f[i]);
  }
  return res;
}