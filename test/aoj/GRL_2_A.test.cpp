#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/minimum_spanning_tree.hpp"

void solve() {
  LL(N, M);
  Graph G(N);
  G.read_graph(M, 1, 0);
  auto [cost, in_mst, tree] = minimum_spanning_tree(G);
  print(cost);
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
