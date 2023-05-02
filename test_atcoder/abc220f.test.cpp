#define PROBLEM "https://atcoder.jp/contests/abc220/tasks/abc220_f"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/tree_dp/subtree_depth_sum.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_tree();
  Tree<decltype(G)> tree(G);

  SubTree_DepthSum<decltype(tree), ll> dp(tree);
  FOR(v, N) print(dp[v].se);
}

signed main() {
  solve();
  return 0;
}