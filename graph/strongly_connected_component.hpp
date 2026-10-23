// Source: https://github.com/maspypy/library/blob/main/graph/strongly_connected_component.hpp
#include "graph/base.hpp"

template <typename GT>
pair<int, vc<int>> strongly_connected_component(GT& G) {
  static_assert(GT::is_directed);
  assert(G.is_prepared());
  int N = G.N;
  int nc = 0;
  vc<int> comp(N), low(N), ord(N, -1), path;
  vc<int> par(N, -1), it = G.indptr;
  int now = 0;

  FOR(s, N) {
    if (ord[s] != -1) continue;
    int v = s;
    low[v] = ord[v] = now++;
    path.eb(v);

    while (v != -1) {
      if (it[v] < G.indptr[v + 1]) {
        int to = G.csr_edges[it[v]++].to;
        if (ord[to] == -1) {
          par[to] = v;
          v = to;
          low[v] = ord[v] = now++;
          path.eb(v);
        } else {
          chmin(low[v], ord[to]);
        }
      } else {
        if (low[v] == ord[v]) {
          while (1) {
            int u = POP(path);
            ord[u] = N, comp[u] = nc;
            if (u == v) break;
          }
          ++nc;
        }
        int p = par[v];
        if (p != -1) chmin(low[p], low[v]);
        v = p;
      }
    }
  }
  FOR(v, N) comp[v] = nc - 1 - comp[v];
  return {nc, comp};
}

template <typename GT>
Graph<int, 1> scc_dag(GT& G, int nc, vc<int>& comp) {
  Graph<int, 1> DAG(nc);
  vvc<int> edges(nc);
  for (auto&& e : G.edges) {
    int x = comp[e.frm], y = comp[e.to];
    if (x == y) continue;
    edges[x].eb(y);
  }
  FOR(c, nc) {
    UNIQUE(edges[c]);
    for (auto&& to : edges[c]) DAG.add(c, to);
  }
  DAG.build();
  return DAG;
}