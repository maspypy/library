#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H"
#include "my_template.hpp"
#include "other/io.hpp"
#include "dp/knapsack01.hpp"

void solve() {
  LL(N, W);
  vc<ll> wt, val;
  FOR(i, N) {
    LL(b, a);
    wt.eb(a), val.eb(b);
  }
  print(knapsack01<ll, ll>(wt, val, W));
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
