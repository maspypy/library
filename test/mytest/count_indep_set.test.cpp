#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"
#include "random/random_graph.hpp"
#include "graph/base.hpp"
#include "graph/count_independent_set.hpp"

void test() {
  FOR(100) {
    FOR(n, 10) {
      auto G = random_graph<0>(n, 1);
      vv(int, adj, n, n);

      for (auto&& e: G.edges) adj[e.frm][e.to] = adj[e.to][e.frm] = 1;
      auto X = count_independent_set<decltype(G)>(G);
      auto Y = count_independent_set_by_size<decltype(G)>(G);
      FOR(s, 1 << n) {
        bool ok = 1;
        FOR(i, n) FOR(j, n) {
          if ((s >> i & 1) && (s >> j & 1) && adj[i][j]) ok = 0;
        }
        if (!ok) continue;
        --X;
        --Y[popcnt(s)];
      }
      assert(X == 0);
      assert(len(Y) == n + 1);
      FOR(i, n + 1) assert(Y[i] == 0);
    }
  }
}

void solve() {
  LL(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}
