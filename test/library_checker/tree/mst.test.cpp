#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/minimum_spanning_tree.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M, 1, 0);
  auto [cost, in_mst, MST] = minimum_spanning_tree<ll>(G);
  vc<int> ANS;
  FOR(i, M) if (in_mst[i]) ANS.eb(i);
  print(cost);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}