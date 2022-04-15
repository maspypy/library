#define PROBLEM \
  "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/tree_all_distances.hpp"

void solve() {
  LL(N);
  Graph<int> G(N);
  G.read_tree(0, 0);

  vi ANS = tree_all_distances(G);
  ANS.erase(ANS.begin());
  for (auto&& x: ANS) x /= 2;
  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
