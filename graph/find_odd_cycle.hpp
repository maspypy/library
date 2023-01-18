#include "graph/strongly_connected_component.hpp"

// (頂点番号列, 辺番号列)
// https://yukicoder.me/problems/no/1436
template <typename GT>
pair<vc<int>, vc<int>> find_odd_cycle(GT& G) {
  int N = G.N;
  vc<int> comp(N);
  if (G.is_directed()) {
    comp = strongly_connected_component<decltype(G)>(G).se;
  }
  // 同じ強連結成分内の点しか探索しないようにして
  // とりあえず奇 walk を探す
  const ll INF = 1 << 30;
  vc<int> dist(2 * N, INF);
  vc<int> par(2 * N, -1); // edge index
  deque<int> que;
  auto add = [&](int v, int d, int p) -> void {
    if (chmin(dist[v], d)) {
      que.eb(v);
      par[v] = p;
    }
  };
  FOR(root, N) {
    if (dist[2 * root] != INF || dist[2 * root + 1] != INF) continue;
    add(2 * root, 0, -1);
    while (len(que)) {
      auto v = POP(que);
      auto [a, b] = divmod(v, 2);
      for (auto&& e: G[a]) {
        if (comp[e.frm] != comp[e.to]) continue;
        int w = 2 * e.to + (b ^ 1);
        add(w, dist[v] + 1, e.id);
      }
    }
    if (dist[2 * root + 1] == INF) continue;
    // found
    vc<int> edges;
    vc<int> vs;
    vs.eb(root);
    int v = 2 * root + 1;
    while (par[v] != -1) {
      int i = par[v];
      edges.eb(i);
      auto& e = G.edges[i];
      v = 2 * (e.frm + e.to) + 1 - v;
      vs.eb(v / 2);
    }
    reverse(all(edges));
    reverse(all(vs));
    // walk -> cycle
    vc<int> used(N, -1);
    int l = -1, r = -1;
    FOR(i, len(vs)) {
      if (used[vs[i]] == -1) {
        used[vs[i]] = i;
        continue;
      }
      l = used[vs[i]];
      r = i;
      break;
    }
    assert(l != -1);
    vs = {vs.begin() + l, vs.begin() + r};
    edges = {edges.begin() + l, edges.begin() + r};
    return {vs, edges};
  }
  return {};
}