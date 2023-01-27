#define PROBLEM "https://atcoder.jp/contests/abc266/tasks/abc266_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/unicyclic.hpp"
#include "graph/tree.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_graph(N);

  UnicyclicGraph X(G);
  auto T = X.tree;
  Tree<decltype(T)> tree(T, X.root);

  ll root = X.root;
  ll bottom = X.TO[X.root];

  LL(Q);
  FOR(Q) {
    LL(a, b);
    --a, --b;
    ll ca = tree.lca(a, bottom);
    ll cb = tree.lca(b, bottom);
    Yes(ca == cb);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
