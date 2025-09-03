#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/link_cut_tree.hpp"
#include "alg/monoid/add.hpp"
#include "graph/ds/lct_node_commutative_monoid.hpp"

using Node = LCT_Node_Commutative_Monoid<Monoid_Add<ll>, true>;

void solve() {
  LL(N, Q);
  Link_Cut_Tree<Node> LCT(N);

  VEC(ll, A, N);
  FOR(i, N) { LCT.set(i, A[i]); }
  FOR(N - 1) {
    INT(a, b);
    LCT.link(a, b);
  }

  FOR(q, Q) {
    LL(t);
    if (t == 0) {
      LL(a, b, c, d);
      LCT.cut(a, b);
      LCT.link(c, d);
    }
    if (t == 1) {
      LL(i, x);
      A[i] += x;
      LCT.set(i, A[i]);
    }
    if (t == 2) {
      LL(a, b);
      print(LCT.prod_subtree(a, b));
    }
  }
}

signed main() {
  solve();
  return 0;
}
