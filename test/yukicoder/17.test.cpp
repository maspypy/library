#define PROBLEM "https://yukicoder.me/problems/no/17"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/warshall_floyd.hpp"

void solve() {
  LL(N);
  VEC(ll, COST, N);
  Graph<ll> G(N);
  LL(M);
  G.read_graph(M, 1, 0);

  auto dist = warshall_floyd<ll>(G);

  ll ANS = infty<ll>;
  FOR3(i, 1, N - 1) FOR3(j, 1, N - 1) if (i != j) {
    chmin(ANS, dist[0][i] + dist[i][j] + dist[j][N - 1] + COST[i] + COST[j]);
  }
  print(ANS);
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
