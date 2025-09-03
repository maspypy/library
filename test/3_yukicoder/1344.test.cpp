#define PROBLEM "https://yukicoder.me/problems/no/1344"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/warshall_floyd.hpp"

void solve() {
  LL(N, M);
  Graph<ll, 1> G(N);
  G.read_graph(M, 1);
  auto dist = warshall_floyd<ll>(G);
  FOR(v, N) {
    ll ANS = 0;
    FOR(w, N) if (dist[v][w] != infty<ll>) ANS += dist[v][w];
    print(ANS);
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
