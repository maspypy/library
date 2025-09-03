#define PROBLEM "https://yukicoder.me/problems/no/1526"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/beats_summin_chmax.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  for (auto&& x: A) --x;

  // dp[L] := mex[L,R)>=k となる R の min
  vi dp(N);
  FOR(i, N) dp[i] = i + 1;
  Beats_SumMin_Chmax<ll> X(dp);

  vvc<int> IDS(N + 1);
  FOR(i, N) IDS[A[i]].eb(i);

  ll ANS = 0;
  FOR(x, N + 1) {
    // ANS += (N + 1) * N - SUM<int>(dp);
    ANS += (N + 1) * N - X.prod(0, N).fi;
    auto& I = IDS[x];
    I.insert(I.begin(), -1);
    I.eb(N);
    FOR(t, len(I) - 1) {
      auto i = I[t], j = I[t + 1];
      // FOR(k, i + 1, j) chmax(dp[k], j + 1);
      X.chmax(i + 1, j, j + 1);
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