#include "graph/base.hpp"
template <typename Graph>
Graph reverse_graph(Graph& G) {
  assert(G.is_directed());
  Graph G1(G.N);
  for (auto&& e: G.edges) { G1.add(e.to, e.frm, e.cost, e.id); }
  G1.prepare();
  return G1;
}
