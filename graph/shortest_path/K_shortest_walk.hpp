#include "ds/meldable_heap.hpp"
#include "graph/shortest_path/dijkstra.hpp"
#include "graph/reverse_graph.hpp"

// INF 埋めして必ず長さ K にしたものをかえす。
template <typename T, typename GT, int NODES>
vc<T> K_shortest_walk(GT &G, int s, int t, int K, T INF) {
  assert(G.is_directed());
  int N = G.N;
  auto RG = reverse_graph(G);
  auto [dist, par] = dijkstra<ll, decltype(RG)>(RG, t, INF);
  if (dist[s] == INF) { return vc<T>(K, INF); }

  using P = pair<T, int>;
  Meldable_Heap<P, true, NODES> X;
  using np = typename decltype(X)::np;
  vc<np> nodes(N, nullptr);

  vc<bool> vis(N);
  vc<int> st = {t};
  vis[t] = 1;
  while (len(st)) {
    int v = POP(st);
    bool done = 0;
    for (auto &&e: G[v]) {
      if (dist[e.to] == INF) continue;
      if (!done && par[v] == e.to && dist[v] == dist[e.to] + e.cost) {
        done = 1;
        continue;
      }
      T cost = -dist[v] + e.cost + dist[e.to];
      nodes[v] = X.push(nodes[v], {cost, e.to});
    }
    for (auto &&e: RG[v]) {
      if (vis[e.to]) continue;
      if (par[e.to] == v) {
        nodes[e.to] = X.meld(nodes[e.to], nodes[v]);
        vis[e.to] = 1;
        st.eb(e.to);
      }
    }
  }

  T base = dist[s];
  vc<T> ANS = {base};
  if (nodes[s]) {
    using PAIR = pair<ll, np>;
    auto comp = [](auto a, auto b) { return a.fi > b.fi; };
    priority_queue<PAIR, vc<PAIR>, decltype(comp)> que(comp);
    que.emplace(base + X.top(nodes[s]).fi, nodes[s]);
    while (len(ANS) < K && len(que)) {
      auto [d, n] = que.top();
      que.pop();
      ANS.eb(d);
      if (n->l) que.emplace(d + (n->l->x.fi) - (n->x.fi), n->l);
      if (n->r) que.emplace(d + (n->r->x.fi) - (n->x.fi), n->r);
      np m = nodes[n->x.se];
      if (m) { que.emplace(d + m->x.fi, m); }
    }
  }
  while (len(ANS) < K) ANS.eb(INF);
  return ANS;
}
