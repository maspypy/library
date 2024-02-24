
#include "graph/ds/link_cut_tree.hpp"
#include "graph/ds/lct_node_commutative_monoid.hpp"
#include "alg/monoid/min.hpp"
#include "graph/base.hpp"
#include "ds/fenwicktree/fenwicktree_01.hpp"

// https://codeforces.com/problemset/problem/1386/C (TLE)
// query(L,R) = # of component if edge L,...,R-1 are used.
struct Range_Edge_Conneced_Component_Query {
  Graph<int, 0>& G;
  vc<pair<int, int>> query;

  Range_Edge_Conneced_Component_Query(Graph<int, 0>& G) : G(G) {}

  void add_query(int l, int r) { query.eb(l, r); }

  using Mono = Monoid_Min<int>;
  using Node = LCT_Node_Commutative_Monoid<Mono>;

  vc<int> calc() {
    int N = G.N, M = G.M;
    Link_Cut_Tree<Node> LCT(N + M);
    int Q = len(query);
    vc<int> ANS(Q);
    vvc<int> QID(M);
    FOR(q, Q) {
      auto [l, r] = query[q];
      assert(0 <= l && l <= r && r <= M);
      if (r) QID[r - 1].eb(q);
    }

    FenwickTree_01 bit(M);
    FOR(i, M) {
      int a = G.edges[i].frm, b = G.edges[i].to;
      if (a != b && LCT.get_root(a) == LCT.get_root(b)) {
        int k = LCT.prod_path(a, b);
        int c = G.edges[k].frm, d = G.edges[k].to;
        bit.add(k, -1);
        LCT.cut(c, N + k), LCT.cut(d, N + k);
      }
      if (a != b) {
        LCT.set(N + i, i);
        LCT.link(a, N + i), LCT.link(b, N + i);
        bit.add(i, 1);
      }
      for (auto& q: QID[i]) {
        auto [l, r] = query[q];
        ANS[q] = N - bit.sum(l, r);
      }
    }
    return ANS;
  }
};