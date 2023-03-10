#include "graph/base.hpp"

struct UnicyclicGraph {
  int root;
  Graph<int, 1> tree;
  vc<int> TO;
  vc<int> cycle;     // 根に向かうような頂点列
  vc<bool> in_cycle; // vertex id -> bool

  template <typename GT>
  UnicyclicGraph(GT& G) : tree(G.N) {
    int N = G.N;
    assert(N == G.M);
    TO.assign(N, -1);
    vc<bool> done(N);
    vc<int> que;
    auto deg = G.deg_array();
    FOR(v, N) if (deg[v] == 1) que.eb(v);
    while (len(que)) {
      auto v = que.back();
      que.pop_back();
      for (auto&& e: G[v]) {
        if (done[e.id]) continue;
        done[e.id] = 1;
        int to = e.to;
        TO[v] = to;
        deg[to] -= 1;
        if (deg[to] == 1) que.eb(to);
      }
      deg[v] = 0;
    }
    root = -1;
    FOR(v, N) if (deg[v] == 2) root = v;
    assert(root != -1);
    vc<int> P = {root};
    while (1) {
      int v = P.back();
      bool upd = 0;
      for (auto&& e: G[v]) {
        if (done[e.id]) continue;
        done[e.id] = 1;
        P.eb(e.to);
        upd = 1;
        break;
      }
      if (!upd) break;
    }
    FOR(i, len(P) - 1) TO[P[i]] = P[i + 1];
    cycle = {P.begin() + 1, P.end()};
    reverse(all(cycle));
    in_cycle.assign(N, false);
    for (auto&& v: cycle) in_cycle[v] = 1;
    FOR(v, N) if (v != root) tree.add(TO[v], v);
    tree.build();
  }
};
