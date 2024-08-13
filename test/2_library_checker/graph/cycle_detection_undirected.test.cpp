#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/find_cycle.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);
  auto [vs, es] = find_cycle_undirected(G);
  int L = len(vs);
  if (L == 0) return print(-1);
  print(L);
  print(vs);
  print(es);
}

signed main() {
  solve();
  return 0;
}
