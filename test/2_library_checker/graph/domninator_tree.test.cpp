#define PROBLEM "https://judge.yosupo.jp/problem/dominatortree"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/dominator_tree.hpp"

void solve() {
  LL(N, M, root);
  Graph<int, 1> G(N);
  G.read_graph(M, 0, 0);
  auto idom = dominator_tree(G, root);
  idom[root] = root;
  print(idom);
}

signed main() {
  solve();
  return 0;
}
