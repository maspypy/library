#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree_diameter.hpp"

void solve() {
  LL(N);
  Graph<ll> G(N);
  G.read_tree(1, 0);
  auto [diam, P] = tree_diameter<ll>(G);
  print(diam, len(P));
  print(P);
}

signed main() {
  solve();

  return 0;
}
