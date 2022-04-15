#include "graph/reverse_graph.hpp"
template <typename Graph, typename INT>
void solve_dag_game(Graph& G, vc<INT>& DP) {
  /*
  -1: unknown
  0 : lose
  1 : win

  予め遷移先のない頂点には、0 または 1 を入れておく
  */
  int N = G.N;
  vc<int> outdeg(N);
  for (auto&& e: G.edges) outdeg[e.frm]++;

  G = reverse_graph(G);
  vc<int> que;
  FOR(v, N) {
    assert((outdeg[v] == 0) == (DP[v] != -1));
    if (outdeg[v] == 0) que.eb(v);
  }
  while (!que.empty()) {
    int v = que.back();
    que.pop_back();
    for (auto&& e: G[v]) {
      if (DP[e.to] != -1) continue;
      if (DP[v] == 0) {
        DP[e.to] = 1;
        que.eb(e.to);
      }
      elif (DP[v] == 1) {
        outdeg[e.to]--;
        if (outdeg[e.to] == 0) {
          DP[e.to] = 0;
          que.eb(e.to);
        }
      }
    }
  }
}
