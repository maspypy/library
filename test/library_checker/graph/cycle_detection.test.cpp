#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/find_cycle.hpp"

void solve() {
  LL(N, M);
  Graph<bool, 1> G(N);
  G.read_graph(M, 0, 0);
  auto [vs, es] = find_cycle_directed(G);
  int L = len(vs);
  if (L == 0) return print(-1);
  print(L);
  for (auto&& x: es) print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  solve();

  return 0;
}
