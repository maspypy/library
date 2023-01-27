#define PROBLEM \
  "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/rerooting_classify_subtree.hpp"

void solve() {
  LL(N);
  int root = RNG(0, N);
  Graph<int, 0> G(N);

  G.read_parent(0);
  Tree<decltype(G)> tree(G, root);

  Rerooting_classify_subtree<decltype(tree)> X(tree);
  vc<ll> dp(N);
  FOR(v, N) dp[v] = X.get(0, v);
  auto key = dp;
  UNIQUE(key);
  for (auto&& x: dp) x = LB(key, x);
  print(MAX(dp) + 1);
  print(dp);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}