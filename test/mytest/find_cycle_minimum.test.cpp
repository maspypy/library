#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"

#include "random/random_graph.hpp"
#include "graph/base.hpp"
#include "graph/find_cycle.hpp"

template <int DIRECTED>
void test() {
  FOR(N, 1, 15) {
    FOR(1000) {
      auto edges = random_graph<DIRECTED>(N, true);
      Graph<int, DIRECTED> G(N);
      for (auto& [a, b]: edges) G.add(a, b);
      G.build();
      vc<int> vs, es;
      if constexpr (DIRECTED)
        tie(vs, es) = find_cycle_directed(G);
      else
        tie(vs, es) = find_cycle_undirected(G);
      if (vs.empty()) continue;
      vc<int> used(G.M);
      for (auto& eid: es) used[eid] = 1;
      vc<int> in_cyc(N);
      for (auto& v: vs) in_cyc[v] = 1;
      for (auto& e: G.edges) {
        if (used[e.id]) continue;
        assert(!in_cyc[e.frm] || !in_cyc[e.to]);
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
  test<0>();
  test<1>();
  solve();
}
