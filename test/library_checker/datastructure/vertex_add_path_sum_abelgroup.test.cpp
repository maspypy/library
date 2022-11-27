#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/treeabelgroup.hpp"
#include "alg/monoid/add.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  Graph G(N);
  G.read_tree(0, 0);

  TREE tree(G);
  TreeAbelGroup<decltype(tree), Monoid_Add<ll>, false, true, false> TA(tree, A);

  FOR(_, Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      TA.add(v, x);
    } else {
      LL(u, v);
      print(TA.prod_path(u, v));
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
