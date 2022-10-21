#include "graph/base.hpp"

template <typename Graph>
vc<int> find_cycle_directed(Graph& G, bool is_edge = 0) {
  assert(G.is_directed());
  assert(G.is_prepared());
  if (!is_edge) {
    auto C = find_cycle_directed(G, true);
    if (len(C) == 0) return C;
    vc<int> ANS(len(C));
    FOR(i, len(C)) {
      auto e = G.edges[C[i]];
      ANS[i] = e.frm;
    }
    return ANS;
  }

  int N = G.N;
  vc<int> used(N);
  vc<pair<int, int>> par(N);
  vector<int> ANS;

  auto dfs = [&](auto self, int v) -> void {
    used[v] = 1;
    for (auto&& e: G[v]) {
      if (len(ANS)) return;
      if (!used[e.to]) {
        par[e.to] = {v, e.id};
        self(self, e.to);
      }
      elif (used[e.to] == 1) {
        ANS = {e.id};
        int cur = v;
        while (cur != e.to) {
          ANS.eb(par[cur].se);
          cur = par[cur].fi;
        }
        reverse(all(ANS));
        return;
      }
    }
    used[v] = 2;
  };
  FOR(v, N) if (!used[v]) dfs(dfs, v);
  return ANS;
}

template <typename Graph>
vc<int> find_cycle_undirected(Graph& G, bool is_edge = 0) {
  assert(!G.is_directed());
  assert(G.is_prepared());

  int N = G.N;
  vc<int> used_e(G.M);
  vc<int> used_v(G.N);
  vc<pair<int, int>> par(N);
  vector<int> ANS;

  auto dfs = [&](auto& dfs, int v) -> void {
    used_v[v] = 1;
    for (auto&& e: G[v]) {
      if (len(ANS)) return;
      if (used_e[e.id]) continue;
      used_e[e.id] = 1;
      if (!used_v[e.to]) {
        par[e.to] = {v, e.id};
        dfs(dfs, e.to);
      } else {
        if (is_edge) ANS = {e.id};
        if (!is_edge) ANS = {v};
        int cur = v;
        while (cur != e.to) {
          if (is_edge) ANS.eb(par[cur].se);
          if (!is_edge) ANS.eb(par[cur].fi);
          cur = par[cur].fi;
        }
        reverse(all(ANS));
        return;
      }
    }
  };
  FOR(v, N) if (!used_v[v]) dfs(dfs, v);
  return ANS;
}

// 辺の列 or 頂点列の vector を返す
// 見つからなかった場合には、空 vector
template <typename Graph>
vc<int> find_cycle(Graph& G, bool is_edge = 0) {
  if (G.is_directed()) return find_cycle_directed(G, is_edge);
  return find_cycle_undirected(G, is_edge);
}
