#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/two_edge_component.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);
  auto [C, comp] = two_edge_component(G);
  vc<pi> ANS;
  for (auto&& e: G.edges) {
    auto a = e.frm, b = e.to;
    if (a > b) swap(a, b);
    if (comp[a] != comp[b]) ANS.eb(a, b);
  }
  sort(all(ANS));
  for (auto&& x: ANS) print(x);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
