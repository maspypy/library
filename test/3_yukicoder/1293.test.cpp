#define PROBLEM "https://yukicoder.me/problems/no/1293"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/strongly_connected_component.hpp"

void solve() {
  LL(N, D, W);
  Graph<int, 1> G(N + N);
  FOR(D) {
    LL(a, b);
    --a, --b;
    G.add(2 * a, 2 * b);
    G.add(2 * b, 2 * a);
  }
  FOR(W) {
    LL(a, b);
    --a, --b;
    G.add(2 * a + 1, 2 * b + 1);
    G.add(2 * b + 1, 2 * a + 1);
  }
  FOR(v, N) G.add(2 * v, 2 * v + 1);
  G.build();

  auto [C, comp] = strongly_connected_component(G);
  auto DAG = scc_dag(G, C, comp);
  vi DP(C);
  FOR(v, N) { DP[comp[2 * v + 0]]++; }
  FOR(c, C) {
    for (auto&& e: DAG[c]) { DP[e.to] += DP[c]; }
  }

  ll ANS = 0;
  FOR(v, N) ANS += DP[comp[2 * v + 1]] - 1;

  print(ANS);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
