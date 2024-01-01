#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/random_graph.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "graph/ds/remove_one_edge_connectivity.hpp"

void test() {
  FOR(N, 20) {
    FOR(1000) {
      Graph<int, 0> G(N);
      for (auto& [a, b]: random_graph<false>(N, false)) G.add(a, b);
      G.build();
      Remove_One_Edge_Connectivity X(G);
      FOR(e, G.M) {
        UnionFind uf(N);
        FOR(i, G.M) {
          if (e != i) uf.merge(G.edges[i].frm, G.edges[i].to);
        }
        assert(X.n_comp(e) == (uf.n_comp));
        FOR(u, N) FOR(v, N) {
          assert(X.is_connected(e, u, v) == (uf[u] == uf[v]));
        }
        FOR(v, N) assert(X.size(e, v) == uf.size(v));
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
