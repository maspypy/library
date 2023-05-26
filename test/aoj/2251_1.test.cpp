#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2251"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/shortest_path/dijkstra.hpp"
#include "graph/dag_path_cover.hpp"
#include "graph/toposort.hpp"

void solve(ll N, ll M, ll L) {
  vv(ll, dist, N, N);
  {
    Graph<ll> G(N);
    G.read_graph(M, 1, 0);
    FOR(v, N) { dist[v] = dijkstra<ll>(G, v).fi; }
  }
  VEC(pi, PT, L);
  N = L;
  Graph<int, 1> G(N);
  FOR(a, N) FOR(b, N) {
    if (a == b) continue;
    auto [pa, ta] = PT[a];
    auto [pb, tb] = PT[b];
    if (ta + dist[pa][pb] <= tb) G.add(a, b);
  }
  G.build();

  auto V = toposort(G);
  G = G.rearrange(V).fi;

  auto color = dag_path_cover(G);
  print(MAX(color) + 1);
}

signed main() {
  while (1) {
    LL(N, M, L);
    if (N + M + L == 0) break;
    solve(N, M, L);
  }

  return 0;
}
