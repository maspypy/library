#define PROBLEM "https://atcoder.jp/contests/abc214/tasks/abc214_h"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/strongly_connected_component.hpp"
#include "flow/mincostflow.hpp"

void solve() {
  LL(N, M, K);
  Graph<bool, 1> G0(N);
  G0.read_graph(M);

  auto [nc, comp] = strongly_connected_component(G0);
  auto DAG = scc_dag(G0, nc, comp);
  vi X(nc);
  FOR(v, N) {
    INT(x);
    X[comp[v]] += x;
  }

  auto idx1 = [&](int i) -> int { return 1 + 2 * i + 0; };
  auto idx2 = [&](int i) -> int { return 1 + 2 * i + 1; };
  int source = 0, sink = 1 + nc + nc;

  Min_Cost_Flow<int, ll, true> G(2 * nc + 2, source, sink);
  G.add(source, idx1(comp[0]), K, 0);
  FOR(v, nc) {
    G.add(idx1(v), idx2(v), 1, -X[v]);
    G.add(idx1(v), idx2(v), K, 0);
    G.add(idx2(v), sink, K, 0);
  }
  for (auto&& e: DAG.edges) { G.add(idx2(e.frm), idx1(e.to), K, 0); }

  auto [a, b] = G.flow();
  assert(a == K);
  print(-b);
}

signed main() {
  solve();
  return 0;
}