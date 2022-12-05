#define PROBLEM "https://yukicoder.me/problems/no/2026"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/sliding_window_aggregation.hpp"
#include "alg/monoid/max.hpp"

using Mono = Monoid_Max<ll>;

void solve() {
  LL(N);
  VEC(pi, CV, N);
  CV.insert(CV.begin(), {0, 0});

  const ll INF = 1LL << 60;
  // count, weight
  vv(ll, dp, N + 1, N + 1, -INF);
  dp[0][0] = 0;

  FOR_R(wt, 1, N + 1) {
    auto [cnt, val] = CV[wt];
    int LIM = N / wt;
    FOR(i, LIM + 1) FOR(j, N + 1) {
      if (i >= 1 && j >= wt) continue;
      int n = min(LIM - i, (N - j) / wt);
      vi A(n + 1);
      FOR(k, n + 1) A[k] = dp[i + k][j + wt * k];

      Sliding_Window_Aggregation<Mono> X;
      FOR(k, n + 1) {
        X.push(A[k] - val * k);
        if (len(X) > cnt + 1) X.pop();
        A[k] = X.prod() + val * k;
      }
      FOR(k, n + 1) dp[i + k][j + wt * k] = A[k];
    }
  }
  FOR(k, 1, N + 1) print(MAX(dp[k]));
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
