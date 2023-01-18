#include "graph/base.hpp"

// (cost, vs, es)
template <typename T>
vc<tuple<T, vc<int>, vc<int>>> K_shortest_path(Graph<T, 1>& G, int s, int t,
                                               int K) {
  const int N = G.N;

  // (cost, vs, es)
  vc<tuple<T, vc<int>, vc<int>>> res;
  // 探索の起点 (es, ng_edges)
  vc<pair<vc<int>, vc<int>>> nodes;
  // 答の候補 (cost, es, ng_es, n), (ng_es, n)：その path を見つけたときの条件
  vc<tuple<T, vc<int>, vc<int>, int>> paths;

  nodes.eb(vc<int>(), vc<int>());
  const T INF = numeric_limits<T>::max();

  vc<T> dist(N, INF);
  vc<bool> ng_v(N);
  vc<bool> ng_e(G.M);
  vc<int> par(N, -1);

  while (len(res) < K) {
    for (auto&& [es, ng_es]: nodes) {
      fill(all(par), -1);
      fill(all(ng_v), 0);
      fill(all(ng_e), 0);
      fill(all(dist), INF);

      T pref_cost = 0;
      for (auto&& x: es) pref_cost += G.edges[x].cost;

      for (auto&& x: es) ng_v[G.edges[x].frm] = 1, ng_e[x] = 1;
      for (auto&& x: ng_es) ng_e[x] = 1;
      // dijkstra
      pqg<pair<T, int>> que;
      auto add = [&](int v, T d, int p) -> void {
        if (chmin(dist[v], d)) {
          que.emplace(d, v);
          par[v] = p;
        }
      };
      int s0 = (es.empty() ? s : G.edges[es.back()].to);
      add(s0, pref_cost, -1);
      while (len(que)) {
        auto [dv, v] = POP(que);
        if (dv != dist[v]) continue;
        if (v == t) break;
        for (auto&& e: G[v]) {
          if (ng_e[e.id] || ng_v[e.to]) continue;
          add(e.to, dv + e.cost, e.id);
        }
      }
      // failed
      if (par[t] == -1) continue;
      // restore path
      vc<int> add_e;
      {
        int v = t;
        while (v != s0) {
          add_e.eb(par[v]);
          v = G.edges[par[v]].frm;
        }
      }
      reverse(all(add_e));
      int n = len(es);
      // find a path
      es.insert(es.end(), all(add_e));
      paths.eb(dist[t], es, ng_es, n);
    }
    // choose best path
    if (len(paths) == 0) break;
    pair<int, T> best = {-1, INF};
    FOR(i, len(paths)) {
      T cost = get<0>(paths[i]);
      if (chmin(best.se, cost)) best.fi = i;
    }
    int idx = best.fi;
    swap(paths[idx], paths[len(paths) - 1]);
    auto [cost, es, ng_es, n] = POP(paths);
    vc<int> vs = {s};
    for (auto&& x: es) vs.eb(G.edges[x].to);
    res.eb(cost, vs, es);

    nodes.clear();
    FOR(k, n, len(es)) {
      // k 番目の辺までを固定して
      vc<int> new_es = {es.begin(), es.begin() + k};
      vc<int> new_ng = ng_es;
      new_ng.eb(es[k]);
      nodes.eb(new_es, new_ng);
    }
  }
  return res;
}