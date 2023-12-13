#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"
#include "my_template.hpp"
#include "random/random_graph.hpp"
#include "graph/maximum_matching_size.hpp"
#include "graph/maximum_matching_of_line_graph.hpp"

void test() {
  FOR(100) {
    FOR(n, 10) {
      Graph<int, 0> G(n);
      for (auto& [a, b]: random_graph<false>(n, true)) G.add(a, b);
      G.build();
      int m = G.M;
      Graph<int, 0> LG(m);
      FOR(i, m) FOR(j, i) if (i != j) {
        auto ei = G.edges[i];
        auto ej = G.edges[j];
        bool ok = 0;
        if (ei.frm == ej.frm) ok = 1;
        if (ei.frm == ej.to) ok = 1;
        if (ei.to == ej.frm) ok = 1;
        if (ei.to == ej.to) ok = 1;
        if (ok) LG.add(i, j);
      }
      LG.build();
      vc<pair<int, int>> res = maximum_matching_of_line_graph(G);
      assert(len(res) == maximum_matching_size(LG));
      vc<int> done(m);
      for (auto&& [a, b]: res) {
        assert(!done[a]);
        assert(!done[b]);
        done[a] = done[b] = 1;
        auto ei = G.edges[a];
        auto ej = G.edges[b];
        bool ok = 0;
        if (ei.frm == ej.frm) ok = 1;
        if (ei.frm == ej.to) ok = 1;
        if (ei.to == ej.frm) ok = 1;
        if (ei.to == ej.to) ok = 1;
        assert(ok);
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