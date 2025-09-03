#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/bellmanford.hpp"

void solve() {
  LL(N, M, s);
  Graph<int, 1> G(N);
  G.read_graph(M, 1, 0);

  auto [dist, par] = BellmanFord<int, true>(G, s);
  if (dist.empty()) { return print("NEGATIVE CYCLE"); }
  for (auto&& x: dist) {
    if (x == infty<int>)
      print("INF");
    else
      print(x);
  }
}

signed main() {
  solve();

  return 0;
}
