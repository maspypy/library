#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/maximum_independent_set.hpp"

void solve() {
  LL(N, M);
  Graph<int> G(N);
  G.read_graph(M, 0, 0);
  auto mis = maximum_independent_set<40>(G);
  print(len(mis));
  print(mis);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
