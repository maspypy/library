#define PROBLEM "https://atcoder.jp/contests/abc321/tasks/abc321_g"
#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "setfunc/sps_log.hpp"

using mint = modint998;

void solve() {
  LL(N, M);

  auto get = [&]() -> vc<int> {
    vc<int> dp(1 << N);
    vc<int> deg(N);
    FOR(M) {
      INT(x);
      --x;
      deg[x]++;
    }
    FOR(i, N) { FOR(s, 1 << i) dp[s | 1 << i] = dp[s] + deg[i]; }
    return dp;
  };

  auto A = get(), B = get();
  vc<mint> F(1 << N);
  FOR(s, 1 << N) {
    if (A[s] == B[s]) { F[s] = fact<mint>(A[s]); }
  }
  F = sps_log<mint, 18>(F);
  // print(A);
  // print(B);
  // print(F);
  mint ANS = 0;
  FOR(s, 1, 1 << N) {
    mint x = F[s];
    if (A[s] == B[s]) {
      ll n = A[s];
      ANS += x * C_inv<mint>(M, n) * fact_inv<mint>(n);
      // print(s, n);
    }
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
