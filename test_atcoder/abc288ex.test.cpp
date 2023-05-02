#define PROBLEM "https://atcoder.jp/contests/abc288/tasks/abc288_Ex"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/fps_pow.hpp"
#include "other/count_seq_with_fixed_xor_value.hpp"

using mint = modint998;
using poly = vc<mint>;

void solve() {
  LL(N, M, X);
  ++M;
  // vc<mint> F(N + 1);
  // FOR(n, N + 1) F[n] = count_seq_with_fixed_xor<mint>(n, M, X);
  vc<mint> F = count_seq_with_fixed_xor_iota<mint>(N, M, X);
  // print("F", F);

  // あとは相異なるようにする
  // ちょうど k 種からなる原始解を n 個にする方法は？

  // f_k(x) = sinh(x)^k cosh(x)^{M-k} を k=0,1,...N で求める
  // f_k' = kf_{k-1} + (M-k-1)f_{k+1} を使って低次から順に

  vv(mint, dp, N + 1, N + 1);
  dp[0][0] = mint(1);
  FOR(i, 1, N + 1) FOR(k, i + 1) {
    mint x = 0;
    if (k) x += mint(k) * dp[k - 1][i - 1];
    if (k + 1 <= N) x += mint(M - k) * dp[k + 1][i - 1];
    if (k == 1 && i == 0) print(k, i, x);
    dp[k][i] = x *= inv<mint>(i);
  }
  FOR(k, N + 1) FOR(i, N + 1) dp[k][i] *= fact<mint>(i);

  /*
  FOR(k, N + 1) {
    if (k > M) break;
    poly f(N + 1), g(N + 1);
    FOR(i, N + 1) {
      if (i % 2 == 1) f[i] += fact_inv<mint>(i);
      if (i % 2 == 0) g[i] += fact_inv<mint>(i);
    }
    f = fps_pow(f, k);
    g = fps_pow(g, M - k);
    f = convolution(f, g);
    f.resize(N + 1);
    FOR(i, N + 1) f[i] *= fact<mint>(i);
    dp[k] = f;
  }
  */

  FOR(j, N + 1) {
    FOR(i, j) { F[j] -= F[i] * dp[i][j]; }
    F[j] /= dp[j][j];
  }

  poly f = {1, 0, -1};
  f.resize(N + 1);
  f = fps_pow_1(f, -mint(M));

  mint ANS = 0;
  FOR(k, N + 1) { ANS += F[k] * f[N - k]; }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}