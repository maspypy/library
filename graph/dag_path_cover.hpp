#include "graph/base.hpp"
#include "flow/maxflow.hpp"
#include "ds/unionfind/unionfind.hpp"

// 各頂点の色をかえす。各色はひとつのパス上にあるようにする
template <typename DAG>
vc<int> dag_path_cover(DAG& G) {
  assert(G.is_directed());
  for (auto&& e: G.edges) assert(e.frm < e.to);

  int N = G.N;
  int source = 2 * N, sink = 2 * N + 1;
  MaxFlow<int> F(2 * N + 2, source, sink);
  FOR(v, N) {
    F.add(source, 2 * v + 1, 1);
    F.add(2 * v + 0, sink, 1);
    F.add(2 * v + 0, 2 * v + 1, infty<int>);
  }
  for (auto&& e: G.edges) F.add(2 * e.frm + 1, 2 * e.to + 0, infty<int>);

  F.flow();
  auto paths = F.path_decomposition();

  UnionFind uf(N);
  for (auto& P: paths) {
    int a = P[1], b = P[len(P) - 2];
    uf.merge(a / 2, b / 2);
  }

  vc<int> ANS(N, -1);
  int p = 0;
  FOR(v, N) if (uf[v] == v) ANS[v] = p++;
  FOR(v, N) if (uf[v] != v) ANS[v] = ANS[uf[v]];
  return ANS;
};
