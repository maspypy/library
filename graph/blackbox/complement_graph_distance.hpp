#include "graph/blackbox/complement_graph_bfs.hpp"

// 距離 2 以上の 2 点組の列挙. {v,w,dvw}.
template <typename GT>
vc<tuple<int, int, int>> complement_graph_all_distance(GT& G) {
  const int N = G.N;
  auto deg = G.deg_array();
  int S = min_element(all(deg)) - deg.begin();
  vc<int> nbd(N);
  for (auto& e: G[S]) { nbd[e.to] = 1; }

  vc<tuple<int, int, int>> res;
  for (auto& e: G.edges) {
    if (nbd[e.frm] || nbd[e.to]) continue;
    // a -> S -> b
    int a = e.frm, b = e.to;
    res.eb(a, b, 2);
  }

  for (auto& e: G[S]) {
    int a = e.to;
    auto dist = complement_graph_bfs(G, a).fi;
    FOR(b, N) {
      if (dist[b] <= 1) continue;
      if (nbd[b] && a >= b) continue;
      res.eb(a, b, dist[b]);
    }
  }
  return res;
}
