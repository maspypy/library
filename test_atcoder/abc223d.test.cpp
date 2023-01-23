#define PROBLEM "https://atcoder.jp/contests/abc223/tasks/abc223_d"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/toposort.hpp"

void solve() {
  LL(N, M);
  Graph<bool, 1> G(N);
  G.read_graph(M);
  auto I = toposort(G);
  if (I.empty()) return print(-1);
  for (auto&& x: I) ++x;
  print(I);
}

signed main() {
  solve();
  return 0;
}
