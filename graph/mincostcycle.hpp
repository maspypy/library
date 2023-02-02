#include "graph/shortest_path/dijkstra.hpp"
#include "graph/shortest_path/bfs01.hpp"

template <typename T, typename Graph>
T MinCostCycle(Graph& G) {
  int M = G.M;
  int N = G.N;
  T mx = 0;
  T res = infty<T>;

  FOR(i, M) {
    auto& e = G.edges[i];
    T cost = e.cost;
    int frm = e.to, to = e.frm;
    Graph Gi(N);
    FOR(j, M) if (i != j) {
      auto& e = G.edges[j];
      Gi.add(e.frm, e.to, e.cost);
    }
    Gi.build();

    T x = (mx <= 1 ? bfs01<T>(Gi, frm).fi[to]
                   : dijkstra<T>(Gi, frm).fi[to]);
    if (x == -1) x = infty<T>;
    chmin(res, cost + x);
  }
  if (res == infty<T>) res = -1;
  return res;
}
