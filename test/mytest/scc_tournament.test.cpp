#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/strongly_connected_component.hpp"
#include "graph/scc_tounament_by_indegrees.hpp"
#include "random/base.hpp"

void test() {
  FOR(N, 1, 50) {
    FOR(100) {
      Graph<int, 1> G(N);
      FOR(b, N) FOR(a, b) {
        int x = RNG(0, 2);
        if (x) G.add(a, b);
        if (!x) G.add(b, a);
      }
      G.build();

      auto [indeg, outdeg] = G.deg_array_inout();
      assert(strongly_connected_component(G)
             == scc_tournament_by_indegrees(indeg));
    }
  }
}

void solve() {
  INT(a, b);
  print(a + b);
}

signed main() {
  test();
  solve();
  return 0;
}