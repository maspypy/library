#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/random_graph.hpp"
#include "graph/count/count_C3_C4.hpp"
#include "graph/find_C4.hpp"

void test() {
  FOR(N, 20) {
    FOR(50) {
      Graph<int, 0> G(N);
      for (auto& [a, b]: random_graph<false>(N, true)) G.add(a, b);
      G.build();
      vv(int, adj, N, N);
      for (auto& e: G.edges) adj[e.frm][e.to] += 1, adj[e.to][e.frm] += 1;
      auto [a, b, c, d] = find_C4(G);
      ll cnt = count_C3_C4(G).se;
      if (cnt == 0) {
        assert(a == -1);
      } else {
        assert(adj[a][b] && adj[b][c] && adj[c][d] && adj[d][a]);
      }
    }
  }
}

void solve() {
  int a, b;
  cin >> a >> b;
  cout << a + b << "\n";
}

signed main() {
  test();
  solve();
  return 0;
}
