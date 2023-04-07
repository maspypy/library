#define PROBLEM "https://yukicoder.me/problems/no/2264"
#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/primetest.hpp"

void solve() {
  LL(N);
  vc<int> dp(N + 1);
  dp[0] = dp[1] = 1;
  FOR(x, 2, N + 1) {
    FOR(p, 2, x + 1) {
      if (primetest(p) && dp[x - p] == 0) dp[x] = 1;
    }
  }
  print(dp[N] ? "Win" : "Lose");
}

signed main() {
  solve();
  return 0;
}