#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/random_graph.hpp"
#include "ds/unionfind/unionfind.hpp"

#include "graph/ds/remove_one_vertex_connectivity.hpp"

void test() {
  FOR(N, 20) {
    FOR(1000) {
      Graph<int, 0> G(N);
      for (auto& [a, b]: random_graph<false>(N, false)) G.add(a, b);
      G.build();
      Remove_One_Vertex_Connectivity X(G);
      FOR(rm, N) {
        UnionFind uf(N);
        for (auto& e: G.edges) {
          if (e.frm == rm || e.to == rm) continue;
          uf.merge(e.frm, e.to);
        }
        assert(X.n_comp(rm) == uf.n_comp - 1);
        FOR(u, N) FOR(v, N) {
          if (u == rm || v == rm) continue;
          assert(X.is_connected(rm, u, v) == (uf[u] == uf[v]));
        }
        FOR(v, N) if (v != rm) assert(X.size(rm, v) == uf.size(v));
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
