#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/shortest_path/dijkstra.hpp"
#include "graph/shortest_path/restore_path.hpp"

void solve() {
  LL(N, M, s, t);
  Graph<ll, true> G(N);
  G.read_graph(M, 1, 0);

  auto [dist, par] = dijkstra<ll>(G, s);
  if (dist[t] == infty<ll>) return print(-1);

  vector<int> pth = restore_path(par, t);
  print(dist[t], len(pth) - 1);
  FOR(i, len(pth) - 1) print(pth[i], pth[i + 1]);
}

signed main() {
  solve();
  return 0;
}
