#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E"
#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/add.hpp"
#include "graph/ds/lazy_tree_monoid.hpp"
#include "alg/acted_monoid/sum_add.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  FOR(v, N) {
    LL(k);
    FOR(k) {
      LL(to);
      G.add(v, to);
    }
  }
  G.build();
  TREE<decltype(G)> tree(G);
  vi seg_raw(N);
  using AM = ActedMonoid_Sum_Add<ll>;
  Lazy_Tree_Monoid<decltype(tree), AM, 1> TM(tree, seg_raw);
  LL(Q);
  FOR(Q) {
    LL(t);
    if (t == 0) {
      LL(v, x);
      TM.apply_path(0, v, x);
      // TM.apply_path(tree.parent[v], v, x);
    } else {
      LL(v);
      print(TM.prod_path(0, v));
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
