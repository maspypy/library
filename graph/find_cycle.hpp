#include "graph/base.hpp"

template <typename GT>
pair<vc<int>, vc<int>> find_cycle_directed(GT& G) {
  assert(G.is_directed());
  assert(G.is_prepared());

  int N = G.N;
  vc<int> used(N);
  vc<pair<int, int>> par(N);
  vector<int> es, vs;

  auto dfs = [&](auto self, int v) -> void {
    used[v] = 1;
    for (auto&& e: G[v]) {
      if (len(es)) return;
      if (!used[e.to]) {
        par[e.to] = {v, e.id};
        self(self, e.to);
      }
      elif (used[e.to] == 1) {
        es = {e.id};
        int cur = v;
        while (cur != e.to) {
          es.eb(par[cur].se);
          cur = par[cur].fi;
        }
        reverse(all(es));
        return;
      }
    }
    used[v] = 2;
  };
  FOR(v, N) if (!used[v]) dfs(dfs, v);
  if (es.empty()) return {vs, es};

  vs.resize(len(es));
  FOR(i, len(es)) { vs[i] = G.edges[es[i]].frm; }
  return {vs, es};
}

template <typename GT>
pair<vc<int>, vc<int>> find_cycle_undirected(GT& G) {
  const int N = G.N;
  const int M = G.M;
  vc<int> dep(N, -1);
  vc<bool> used_e(M);
  vc<int> par(N, -1);

  auto dfs = [&](auto& dfs, int v, int d) -> int {
    dep[v] = d;
    for (auto&& e: G[v]) {
      if (used_e[e.id]) continue;
      if (dep[e.to] != -1) return e.id;
      used_e[e.id] = 1;
      par[e.to] = e.id;
      int res = dfs(dfs, e.to, d + 1);
      if (res != -1) return res;
    }
    return -1;
  };

  vc<int> vs, es;
  FOR(v, N) {
    if (dep[v] != -1) continue;
    int e0 = dfs(dfs, v, 0);
    if (e0 == -1) continue;
    int a = G.edges[e0].frm, b = G.edges[e0].to;
    if (dep[a] > dep[b]) swap(a, b);
    es.eb(e0);
    vs.eb(a);
    while (1) {
      int x = vs.back();
      auto& e = G.edges[es.back()];
      int y = e.frm + e.to - x;
      if (y == a) break;
      vs.eb(y);
      es.eb(par[y]);
    }
    return {vs, es};
  }
  return {vs, es};
}

// {vs, es} ：辺の列と頂点の列を返す。es[i] は vs[i] から vs[i+1]。
template <typename GT>
pair<vc<int>, vc<int>> find_cycle(GT& G) {
  if (G.is_directed()) return find_cycle_directed(G);
  return find_cycle_undirected(G);
}
