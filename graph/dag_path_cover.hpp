#include "graph/base.hpp"
#include "flow/maxflow.hpp"
#include "ds/unionfind/unionfind.hpp"

// 各頂点の色をかえす。各色はひとつのパス上にあるようにする
template <typename DAG>
vc<int> dag_path_cover(DAG& G) {
  assert(G.is_directed());
  for (auto&& e: G.edges) assert(e.frm < e.to);

  int N = G.N;
  MaxFlowGraph<int> F(2 * N + 2);
  int source = 2 * N, sink = 2 * N + 1;
  FOR(v, N) {
    F.add(source, 2 * v + 1, 1);
    F.add(2 * v + 0, sink, 1);
    F.add(2 * v + 0, 2 * v + 1, infty<int>);
  }
  for (auto&& e: G.edges) F.add(2 * e.frm + 1, 2 * e.to + 0, infty<int>);
  F.build();

  int flow = F.flow(source, sink);

  vvc<pair<int, int>> flow_edges(N + N + 2);
  for (auto&& [a, b, c]: F.get_flow_edges()) { flow_edges[a].eb(b, c); }

  UnionFind uf(N);
  for (auto&& [a, f]: flow_edges[source]) {
    assert(f == 1);
    int b = a;
    while (1) {
      auto [to, x] = POP(flow_edges[b]);
      x -= 1;
      if (x > 0) flow_edges[b].eb(to, x);
      if (to == sink) break;
      b = to;
    }
    uf.merge(a / 2, b / 2);
  }

  vc<int> ANS(N, -1);
  int p = 0;
  FOR(v, N) if (uf[v] == v) ANS[v] = p++;
  FOR(v, N) if (uf[v] != v) ANS[v] = ANS[uf[v]];
  return ANS;
};