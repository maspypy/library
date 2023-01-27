#define PROBLEM "https://yukicoder.me/problems/no/1641"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/ds/tree_abelgroup.hpp"
#include "alg/monoid/xor.hpp"

void solve() {
  LL(N, Q);
  Graph G(N);
  VEC(int, A, N);
  G.read_tree();
  Tree tree(G);
  Tree_AbelGroup<decltype(tree), Monoid_Xor<int>, 0, 0, 1> TA(tree, A);
  FOR(Q) {
    LL(t, x, y);
    --x;
    if (t == 1) { TA.add(x, y); }
    if (t == 2) { print(TA.prod_subtree(x)); }
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
