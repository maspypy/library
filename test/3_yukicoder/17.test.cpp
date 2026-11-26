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
  FOR(i, N) SHOW(dist[i]);
  ll ANS = infty<ll>;
  FOR3(i, 1, N - 1) FOR3(j, 1, N - 1) if (i != j) {
    i128 ans =
        i128(dist[0][i]) + dist[i][j] + dist[j][N - 1] + COST[i] + COST[j];
    chmin(ans, infty<ll>);
    chmin(ANS, ans);
  }
  print(ANS);
}

signed main() {
  solve();

  return 0;
}