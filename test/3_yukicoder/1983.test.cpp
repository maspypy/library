#define PROBLEM "https://yukicoder.me/problems/no/1983"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/two_edge_component.hpp"
#include "ds/unionfind/unionfind.hpp"

void solve() {
  LL(N, M, Q);
  Graph<int, 0> G(N);
  G.read_graph(M);
  auto [C, comp] = two_edge_component(G);
  UnionFind uf(N);
  for (auto&& e: G.edges) {
    int a = e.frm, b = e.to;
    if (comp[a] != comp[b]) uf.merge(a, b);
  }
  FOR(Q) {
    LL(a, b);
    Yes(uf[--a] == uf[--b]);
  }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
