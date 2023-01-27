#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/tree.hpp"

void solve() {
  LL(N, Q);
  Graph<int, 1> G(N);
  FOR3(v, 1, N) {
    LL(p);
    G.add(p, v);
  }
  G.build();
  Tree tree(G);

  FOR(_, Q) {
    LL(a, b);
    print(tree.LCA(a, b));
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();
  return 0;
}
