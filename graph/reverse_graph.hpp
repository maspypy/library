#include "graph/base.hpp"

template <typename T>
Graph<T, 1> reverse_graph(Graph<T, 1>& G) {
  assert(G.is_directed());
  Graph<T, 1> G1(G.N);
  for (auto&& e: G.edges) { G1.add(e.to, e.frm, e.cost, e.id); }
  G1.build();
  return G1;
}
