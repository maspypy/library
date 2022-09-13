#define PROBLEM "https://yukicoder.me/problems/no/1601"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/dijkstra.hpp"
#include "graph/reverse_graph.hpp"

void solve() {
  LL(N, M);
  Graph<ll, 1> G(N + N);
  FOR(M) {
    LL(a, b, c, x);
    --a, --b;
    FOR(2) {
      swap(a, b);
      if (x == 0) {
        G.add(2 * a + 0, 2 * b + 0, c);
        G.add(2 * a + 1, 2 * b + 1, c);
      }
      if (x == 1) {
        G.add(2 * a + 0, 2 * b + 1, c);
        G.add(2 * a + 1, 2 * b + 1, c);
      }
    }
  }
  G.build();

  G = reverse_graph(G);

  const ll INF = 1LL << 60;
  auto [dist, par] = dijkstra(G, 2 * (N - 1) + 1, INF);
  FOR(v, N - 1) print(dist[2 * v + 0]);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
