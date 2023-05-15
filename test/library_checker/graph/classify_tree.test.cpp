#define PROBLEM \
  "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"

#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree_dp/subtree_hash.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  FOR(v, 1, N) {
    INT(p);
    G.add(p, v);
  }
  G.build();
  Tree<decltype(G)> tree(G);
  SubTree_Hash<decltype(tree)> X(tree);

  vi ANS(N);
  FOR(v, N) ANS[v] = X.get(0, v);
  vi key = ANS;
  UNIQUE(key);
  for (auto&& x: ANS) x = LB(key, x);
  print(MAX(ANS) + 1);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}