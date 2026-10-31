#include "graph/base.hpp"
#include "flow/maxflow.hpp"

// 任意のカットが infty<T> 未満であるという前提
template <typename T>
Graph<T, 0> gomory_hu_tree(const Graph<T, 0> &G) {
  int N = G.N;
  vc<int> par(N, -1);
  vc<T> wt(N);
  FOR(v, 1, N) par[v] = 0;

  FOR(s, 1, N) {
    int t = par[s];
    MaxFlow<T> F(N, s, t);
    for (auto &e : G.edges) {
      F.add(e.frm, e.to, e.cost, e.cost);
    }
    auto [val, cut] = F.cut();
    wt[s] = val;

    FOR(v, 1, N) {
      if (v != s && par[v] == t && cut[v] == 0) par[v] = s;
    }
    if (par[t] != -1 && cut[par[t]] == 0) {
      par[s] = par[t], par[t] = s, wt[s] = wt[t], wt[t] = val;
    }
  }
  Graph<T, 0> ANS(N);
  FOR(v, 1, N) ANS.add(par[v], v, wt[v]);
  ANS.build();
  return ANS;
}
