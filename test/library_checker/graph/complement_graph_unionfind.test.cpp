#define PROBLEM \
  "https://judge.yosupo.jp/problem/connected_components_of_complement_graph"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/blackbox/complement_graph_unionfind.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);
  auto uf = complement_graph_unionfind(G);

  vvc<int> vs(N);
  FOR(v, N) { vs[uf[v]].eb(v); }

  print(uf.n_comp);
  for (auto &V: vs) {
    if (!V.empty()) print(len(V), V);
  }
}

signed main() {
  solve();
  return 0;
}