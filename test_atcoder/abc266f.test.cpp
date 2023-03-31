#define PROBLEM "https://atcoder.jp/contests/abc266/tasks/abc266_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/unicyclic.hpp"
#include "graph/tree.hpp"

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_graph(N);

  UnicyclicGraph<decltype(G), true> X(G);
  auto tree = X.build();

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
  solve();
  return 0;
}
