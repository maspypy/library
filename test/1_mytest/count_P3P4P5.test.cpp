#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/random_graph.hpp"
#include "graph/count/count_P3_P4_P5.hpp"

void test() {
  FOR(N, 20) {
    FOR(50) {
      Graph<int, 0> G(N);
      for (auto& [a, b]: random_graph<false>(N, true)) G.add(a, b);
      G.build();
      vv(int, adj, N, N);
      for (auto& e: G.edges) adj[e.frm][e.to] += 1, adj[e.to][e.frm] += 1;
      vi A(N), B(N), C(N);
      FOR(a, N) FOR(b, N) FOR(c, N) {
        int s = (1 << a) | (1 << b) | (1 << c);
        if (popcnt(s) != 3) continue;
        A[a] += adj[a][b] * adj[b][c];
      }
      FOR(a, N) FOR(b, N) FOR(c, N) FOR(d, N) {
        int s = (1 << a) | (1 << b) | (1 << c) | (1 << d);
        if (popcnt(s) != 4) continue;
        B[a] += adj[a][b] * adj[b][c] * adj[c][d];
      }
      FOR(a, N) FOR(b, N) FOR(c, N) FOR(d, N) FOR(e, N) {
        int s = (1 << a) | (1 << b) | (1 << c) | (1 << d) | (1 << e);
        if (popcnt(s) != 5) continue;
        C[a] += adj[a][b] * adj[b][c] * adj[c][d] * adj[d][e];
      }
      auto [X, Y, Z] = count_P3_P4_P5_pointwise(G);
      assert(A == X);
      assert(B == Y);
      assert(C == Z);
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
