#include "graph/base.hpp"
#include "graph/tree.hpp"
#include "ds/unionfind/unionfind.hpp"

template <typename GT, bool DIRECTED = true>
struct UnicyclicGraph {
  using T = typename GT::cost_type;
  GT& G0;
  Graph<T, DIRECTED> G;
  int N;
  int root;
  int out_eid;
  vc<int> TO;
  vc<int> cycle;     // 根に向かうような頂点列
  vc<bool> in_cycle; // vertex id -> bool

  UnicyclicGraph(GT& G) : G0(G), N(G.N) {
    assert(!G.is_directed() && N == G.M);
    UnionFind uf(N);
    TO.assign(N, -1);
    FOR(eid, N) {
      auto& e = G.edges[eid];
      if (uf.merge(e.frm, e.to)) continue;
      out_eid = eid;
      root = e.frm;
      TO[root] = e.to;
      break;
    }
    vc<bool> done(N);
    vc<int> que = {root};
    while (len(que)) {
      int v = POP(que);
      done[v] = 1;
      for (auto&& e: G[v]) {
        if (done[e.to] || e.id == out_eid) continue;
        TO[e.to] = v;
        que.eb(e.to);
      }
    }
    cycle = {TO[root]};
    while (cycle.back() != root) cycle.eb(TO[cycle.back()]);
    in_cycle.assign(N, 0);
    for (auto&& v: cycle) in_cycle[v] = 1;
  }

  // tree を作る
  Tree<decltype(G)> build(bool keep_eid = false) {
    G.resize(N);
    FOR(eid, N) {
      if (eid == out_eid) continue;
      auto& e = G0.edges[eid];
      int a = e.frm, b = e.to;
      if (TO[a] == b) swap(a, b);
      assert(TO[b] == a);
      int k = (keep_eid ? eid : -1);
      G.add(a, b, e.cost, k);
    }
    G.build();
    return Tree<decltype(G)>(G, root);
  };
};