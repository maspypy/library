#define PROBLEM "https://yukicoder.me/problems/no/1240"
#include "my_template.hpp"
#include "other/io.hpp"
#include "other/xor_range.hpp"

void solve() {
  const int K = 20;
  LL(N, X);
  VEC(ll, A, N);
  sort(all(A));

  // 桁ごとの累積和
  vv(int, dp, K, N);
  FOR(k, K) FOR(i, N) dp[k][i] = (A[i] & 1 << k ? 1 : 0);
  FOR(k, K) dp[k] = cumsum<int>(dp[k]);

  ll ANS = 0;
  FOR(i, N) {
    for (auto&& [l, r]: xor_range(A[i], 0, X)) {
      // [l, r) 内の j
      l = LB(A, l);
      r = LB(A, r);
      chmax(l, i + 1);
      if (l >= r) continue;
      // FOR(j, l, r) ANS += A[i] | A[j];

      FOR(k, K) {
        if (A[i] & 1 << k) {
          ANS += (r - l) << k;
          continue;
        }
        ANS += ll(dp[k][r] - dp[k][l]) << k;
      }
    }
  }
  print(ANS);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
