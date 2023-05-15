#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2636"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/incremental_centroid.hpp"

void solve() {
  LL(N);
  Graph<ll, 1> G(N);
  FOR(v, 1, N) {
    LL(p, d);
    G.add(--p, v, d);
  }
  G.build();

  Tree<decltype(G)> tree(G);
  Incremental_Centroid<decltype(tree)> X(tree);

  ll ans = 0;

  FOR(v, N) {
    int cent = X.cent;
    X.add(v);
    int to = X.cent;
    ans += tree.dist_weighted(cent, v);
    ans -= tree.dist_weighted(cent, to);
    print(ans);
  }
}

signed main() {
  solve();
  return 0;
}