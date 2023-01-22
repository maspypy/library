#define PROBLEM "https://yukicoder.me/problems/no/2108"
#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/convolution.hpp"
#include "linalg/implicit_matrix/pascal.hpp"
#include "linalg/transpose.hpp"

using mint = modint998;

void solve() {
  ll LIM = 2000;
  using poly = vc<mint>;
  poly f(LIM + 1);
  FOR(a, 1, LIM + 1) { f[a] = mint(a).pow(a) * fact_inv<mint>(a); }
  vv(mint, dp, LIM + 1, LIM + 1);
  dp[0][0] = mint(1);
  FOR(i, LIM) {
    poly g = convolution(dp[i], f);
    g.resize(LIM + 1);
    dp[i + 1] = g;
  }
  FOR(i, LIM + 1) FOR(j, LIM + 1) { dp[i][j] *= fact_inv<mint>(i); }

  dp = transpose(LIM + 1, LIM + 1, dp);

  FOR(N, LIM + 1) {
    mint pow_N = inv<mint>(N).pow(4);
    FOR(i, 1, N + 1) {
      pow_N *= mint(N * N);
      dp[N][i] *= fact<mint>(N) * pow_N;
    }
  }

  vv(mint, ANS, LIM + 1, LIM + 1);
  FOR(N, 1, LIM + 1) {
    vc<mint> A = {dp[N].begin() + 1, dp[N].begin() + N + 1};
    reverse(all(A));
    A = pascal_2(A, true);
    FOR(i, N) ANS[N][i] = A[i];
  }

  LL(T);
  FOR(T) {
    LL(a, b);
    print(ANS[a][b]);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
