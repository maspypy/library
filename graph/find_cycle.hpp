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

// {vs, es}、存在しなければ empty
// 極小なものを返す
template <typename GT>
pair<vc<int>, vc<int>> find_cycle_undirected(GT& G) {
  const int N = G.N;
  const int M = G.M;
  vc<int> dep(N, -1);
  vc<bool> used_e(M);
  vc<int> par(N, -1); // 辺番号

  auto dfs = [&](auto& dfs, int v, int d) -> int {
    dep[v] = d;
    for (auto&& e: G[v]) {
      if (used_e[e.id]) continue;
      if (dep[e.to] != -1) return v;
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
    // v からの dfs 木において、w が後退辺を持つ
    int w = dfs(dfs, v, 0);
    if (w == -1) continue;
    int b = -1, back_e = -1;
    while (1) {
      for (auto&& e: G[w]) {
        if (used_e[e.id]) continue;
        if (dep[e.to] > dep[w] || dep[e.to] == -1) continue;
        b = w, back_e = e.id;
      }
      if (w == v) break;
      auto& e = G.edges[par[w]];
      w = e.frm + e.to - w;
    }
    // b からの後退辺 back_e を使ってサイクルを作る
    int a = G.edges[back_e].frm + G.edges[back_e].to - b;
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
  return {vs, es};
}

// {vs, es} ：辺の列と頂点の列を返す。es[i] は vs[i] から vs[i+1]。
// とりあえず無向のときには極小なものを返すことにした。
template <typename GT>
pair<vc<int>, vc<int>> find_cycle(GT& G) {
  if (G.is_directed()) return find_cycle_directed(G);
  return find_cycle_undirected(G);
}
