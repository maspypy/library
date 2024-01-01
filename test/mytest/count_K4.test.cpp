#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/random_graph.hpp"
#include "graph/count/count_K4.hpp"

void test() {
  FOR(N, 20) {
    FOR(1000) {
      Graph<int, 0> G(N);
      for (auto& [a, b]: random_graph<false>(N, true)) G.add(a, b);
      G.build();
      vv(int, adj, N, N);
      for (auto& e: G.edges) adj[e.frm][e.to] = adj[e.to][e.frm] = 1;
      ll ans = 0;
      FOR(d, N) FOR(c, d) FOR(b, c) FOR(a, b) {
        ll n = 0;
        n += adj[a][b];
        n += adj[a][c];
        n += adj[a][d];
        n += adj[b][c];
        n += adj[b][d];
        n += adj[c][d];
        ans += n == 6;
      }
      ll x = count_K4(G);
      assert(ans == x);
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
