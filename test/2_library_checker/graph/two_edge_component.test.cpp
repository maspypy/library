#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/two_edge_component.hpp"

void solve() {
  LL(N, M);
  Graph G(N);
  G.read_graph(M, false, 0);

  auto [C, comp] = two_edge_component(G);
  vc<vc<int>> ANS(C);
  FOR(v, N) ANS[comp[v]].eb(v);
  print(len(ANS));
  for (auto&& ans: ANS) print(len(ans), ans);
}

signed main() {
  solve();

  return 0;
}
