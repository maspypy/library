#include "graph/base.hpp"

template <typename Graph>
vector<int> degree(Graph& G) {
  vector<int> deg(G.N);
  for(auto&& e : G.edges) deg[e.frm]++, deg[e.to]++;
  return deg;
}

template <typename Graph>
pair<vector<int>, vector<int>> degree_inout(Graph& G) {
  vector<int> indeg(G.N), outdeg(G.N);
  for (auto&& e: G.edges) { indeg[e.to]++, outdeg[e.frm]++; }
  return {indeg, outdeg};
}
