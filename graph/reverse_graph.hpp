#include "graph/base.hpp"

template <typename GT>
GT reverse_graph(GT& G) {
  static_assert(GT::is_directed);
  GT G1(G.N);
  for (auto&& e: G.edges) { G1.add(e.to, e.frm, e.cost, e.id); }
  G1.build();
  return G1;
}
