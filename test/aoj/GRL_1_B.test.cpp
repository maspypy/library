#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/bellmanford.hpp"

void solve() {
  LL(N, M, s);
  Graph<int, 1> G(N);
  G.read_graph(M, 1, 0);
  const int INF = 1 << 30;

  auto [dist, par] = BellmanFord<int, INF>(G, s);
  if (MIN(dist) == -INF) { return print("NEGATIVE CYCLE"); }
  for (auto&& x: dist) {
    if (x == INF)
      print("INF");
    else
      print(x);
  }
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
