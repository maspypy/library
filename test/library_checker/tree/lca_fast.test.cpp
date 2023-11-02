#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/fast_lca.hpp"

void solve() {
  INT(N, Q);
  Graph<int, 1> G(N);
  FOR(v, 1, N) {
    INT(p);
    G.add(p, v);
  }
  G.build();

  Tree<decltype(G)> tree(G);
  Fast_Lca<decltype(tree), false> LCA(tree);

  FOR(Q) {
    INT(a, b);
    print(LCA.lca(a, b));
  }
}

signed main() {
  solve();
  return 0;
}