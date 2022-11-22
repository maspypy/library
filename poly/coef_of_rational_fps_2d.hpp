#include "poly/convolution.hpp"

/*
[x^N] F(x,y)/G(x,y) の計算。結果は y の多項式。
[x^0] G = 1 を仮定している。
deg G = (3, 1) の N = 3×10^6 で 500 ms の実績があるが、かなり疎だからかも。
https://atcoder.jp/contests/agc058/tasks/agc058_d
*/
template <typename mint>
vc<mint> coef_of_rational_fps_2d(vector<vector<mint>> F, vector<vector<mint>> G,
                                 int N) {
  using poly = vc<mint>;

  // x^N mod reverse(G) を計算する
  int m = len(G) - 1;

  auto add_at = [&](poly& f, int i, mint x) -> void {
    if (len(f) <= i) f.resize(i + 1);
    f[i] += x;
  };

  auto simplify = [&](poly& f) -> void {
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
    FOR(i, len(f)) FOR(j, len(f)) {
      FOR(k, K) g[i + j][k] += f[i][k] * f[j][k];
    }
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

  vc<mint> res;
  FOR(i, m) {
    vc<mint> f = convolution(h[i], A[i]);
    FOR(i, len(f)) add_at(res, i, f[i]);
  }
  return res;
}
