#define PROBLEM \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/link_cut_subtree.hpp"
#include "alg/group_add.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  using Node = LCT_Subtree_Node<Group_Add<ll>>;
  LinkCutTree_SubTree<Node, 200'000> LCT(A);

  FOR(N - 1) {
    LL(a, b);
    LCT.link(a, b);
  }
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(a, b, c, d);
      LCT.cut(a, b);
      LCT.link(c, d);
    }
    if (t == 1) {
      LL(a, x);
      LCT.add(a, x);
    }
    if (t == 2) {
      LL(v, p);
      LCT.evert(p);
      print(LCT.sum(v));
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}