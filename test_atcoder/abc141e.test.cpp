#define PROBLEM "https://atcoder.jp/contests/abc141/tasks/abc141_e"
#include "my_template.hpp"
#include "other/io.hpp"
#include "string/all_pair_lcp.hpp"

void solve() {
  LL(N);
  STR(S);
  auto dp = all_pair_lcp(S, S);
  ll ANS = 0;
  FOR(j, N) FOR(i, j) { chmax(ANS, min<int>(dp[i][j], j - i)); }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
