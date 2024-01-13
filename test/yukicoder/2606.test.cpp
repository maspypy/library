#define PROBLEM "https://yukicoder.me/problems/no/2606"
#include "my_template.hpp"
#include "other/io.hpp"

#include "string/palindromic_tree.hpp"

void solve() {
  STR(S);
  Palindromic_Tree<26> X(S, 'a');

  auto CNT = X.count();
  ll n = len(X.nodes);
  vi dp(n);
  FOR(i, 2, n) {
    int p = X.nodes[i].link;
    ll cnt = CNT[i];
    ll L = X.nodes[i].length;
    chmax(dp[i], dp[p] + cnt * L);
  }
  print(MAX(dp));
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
