#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/maximum_independent_set_weighted.hpp"

void solve() {
  LL(N, M);
  Graph<bool, 0> G(N);
  G.read_graph(M, 0, 0);
  vc<int> wt(N, 1);
  vc<int> V = maximum_independent_set_weighted(G, wt);
  print(len(V));
  print(V);
}

signed main() {
  solve();
  return 0;
}