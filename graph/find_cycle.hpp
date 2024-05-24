#include "graph/base.hpp"

// {vs, es} or empty. minimal.
template <typename GT>
pair<vc<int>, vc<int>> find_cycle_directed(GT& G) {
  static_assert(GT::is_directed);
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

  // minimal cycle
  vc<int> nxt(N, -1);
  for (auto&& eid: es) nxt[G.edges[eid].frm] = eid;

  for (auto&& e: G.edges) {
    int a = e.frm, b = e.to;
    if (nxt[a] == -1 || nxt[b] == -1) continue;
    if (G.edges[nxt[a]].to == e.to) continue;
    while (a != b) {
      int t = G.edges[nxt[a]].to;
      nxt[a] = -1;
      a = t;
    }
    nxt[e.frm] = e.id;
  }
  es.clear();
  FOR(v, N) {
    if (nxt[v] == -1) continue;
    int x = v;
    while (1) {
      vs.eb(x);
      es.eb(nxt[x]);
      x = G.edges[nxt[x]].to;
      if (x == v) break;
    }
    break;
  }
  return {vs, es};
}

// {vs, es} or empty. minimal.
template <typename GT>
pair<vc<int>, vc<int>> find_cycle_undirected(GT& G) {
  assert(!GT::is_directed);
  assert(G.is_prepared());
  const int N = G.N;
  const int M = G.M;
  vc<int> dep(N, -1);
  vc<bool> used_e(M);
  vc<int> par(N, -1); // edge idx

  auto dfs = [&](auto& dfs, int v, int d) -> void {
    dep[v] = d;
    for (auto&& e: G[v]) {
      if (dep[e.to] != -1) continue;
      used_e[e.id] = 1;
      par[e.to] = e.id;
      dfs(dfs, e.to, d + 1);
    }
  };

  vc<int> vs, es;
  FOR(v, N) {
    if (dep[v] == -1) dfs(dfs, v, 0);
  }
  int mi_len = infty<int>;
  int back_e = -1;
  for (auto& e: G.edges) {
    if (used_e[e.id]) continue;
    int d = abs(dep[e.frm] - dep[e.to]);
    if (chmin(mi_len, d)) back_e = e.id;
  }
  if (back_e == -1) return {vs, es};
  int a = G.edges[back_e].frm, b = G.edges[back_e].to;
  if (dep[a] > dep[b]) swap(a, b);
  es.eb(back_e), vs.eb(a);
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
