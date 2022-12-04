#define PROBLEM "https://judge.yosupo.jp/problem/k_shortest_walk"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "graph/shortest_path/K_shortest_walk.hpp"

void solve() {
  INT(N, M, s, t, K);
  Graph<int, 1> G1(N);
  G1.read_graph(M, 1, 0);
  const ll INF = 1LL << 60;
  auto ANS = K_shortest_walk<ll, decltype(G1), 500>(G1, s, t, K, INF);
  for (auto &&x: ANS) {
    if (x == INF) x = -1;
    print(x);
  }
}

signed main() {
  solve();
  return 0;
}