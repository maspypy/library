#define PROBLEM \
  "https://judge.yosupo.jp/problem/counting_spanning_tree_directed"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/count/count_spanning_tree.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, M, r);
  Graph<int, 1> G(N);
  G.read_graph(M, 0, 0);
  mint ANS = count_spanning_tree_directed<mint, false>(G, r);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
