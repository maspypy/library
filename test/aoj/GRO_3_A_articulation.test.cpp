#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/biconnected_component.hpp"

void solve() {
  LL(N, M);
  Graph G(N);
  G.read_graph(M, 0, 0);
  Biconnected_Component BC(G);
  FOR(v, N) if (BC.is_articulation(v)) print(v);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
