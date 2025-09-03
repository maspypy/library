#define PROBLEM "https://yukicoder.me/problems/no/1868"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/range_to_range_graph.hpp"
#include "graph/shortest_path/bfs01.hpp"

void solve() {
  LL(N);
  Range_to_Range_Graph<int> RRG(N);
  FOR(i, N - 1) {
    LL(r);
    RRG.add_to_range(i, i + 1, r, 1);
  }
  auto G = RRG.build();
  auto [dist, par] = bfs01<int>(G, 0);
  print(dist[N - 1]);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
