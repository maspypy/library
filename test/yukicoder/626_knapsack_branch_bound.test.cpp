#define PROBLEM "https://yukicoder.me/problems/no/626"
#include "my_template.hpp"
#include "other/io.hpp"
#include "dp/knapsack_branch_bound.hpp"

void solve() {
  LL(N, LIM);
  vi wt(N), val(N);
  FOR(i, N) {
    LL(a, b);
    val[i] = a, wt[i] = b;
  }

  ll ANS = knapsack_branch_bound(wt, val, LIM);
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
