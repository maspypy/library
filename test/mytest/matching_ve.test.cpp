#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "graph/maximum_matching_between_vertex_edge.hpp"
#include "flow/bipartite.hpp"
#include "random/random_graph.hpp"

void test() {
  FOR(N, 50) {
    FOR(100) {
      Graph<int, 0> G(N);
      for (auto& [a, b]: random_graph<0>(N, false)) G.add(a, b);
      G.build();
      Graph<int, 0> VE(G.N + G.M);
      for (auto& e: G.edges) {
        VE.add(e.frm, N + e.id);
        VE.add(e.to, N + e.id);
      }
      VE.build();
      BipartiteMatching<decltype(G)> BM(VE);
      int n = len(BM.matching());

      auto match = maximum_matching_between_vertex_edge(G);
      assert(len(match) == n);
      vc<int> used_v(N), used_e(G.M);
      for (auto& [v, e]: match) {
        assert(!used_v[v]);
        assert(!used_e[e]);
        used_v[v] = used_e[e] = 1;
        auto& eg = G.edges[e];
        assert(eg.frm == v || eg.to == v);
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
