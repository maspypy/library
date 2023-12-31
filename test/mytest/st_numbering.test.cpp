#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "graph/st_numbering.hpp"
#include "random/random_graph.hpp"
#include "graph/block_cut.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "graph/shortest_path/bfs01.hpp"
#include "graph/shortest_path/restore_path.hpp"

void test() {
  // valid な output になっていることは最後にチェックしているので
  // invalid と言われたときに構築不可能であることを確かめればよい
  FOR(N, 2, 20) {
    FOR(100) {
      Graph<int, 0> G(N);
      for (auto& [a, b]: random_graph<0>(N, false)) { G.add(a, b); };
      G.build();

      auto BCT = block_cut(G);
      UnionFind uf(N);
      for (auto& e: G.edges) uf.merge(e.frm, e.to);
      auto check = [&](int s, int t) -> bool {
        if (uf.n_comp >= 2) return false;
        if (s == t) return false;
        // BCT における st パスがすべての component を通るかどうか
        auto [dist, par] = bfs01<int>(BCT, s);
        vc<int> path = restore_path(par, t);
        vc<int> pass(BCT.N);
        for (auto& x: path) pass[x] = 1;
        FOR(i, N, BCT.N) if (!pass[i]) return false;
        return true;
      };
      FOR(s, N) FOR(t, N) {
        auto ST = st_numbering(G, s, t);
        if (!ST.empty()) continue;
        assert(!check(s, t));
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
