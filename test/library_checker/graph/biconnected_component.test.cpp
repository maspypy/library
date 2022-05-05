#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/biconnected_component.hpp"

void solve() {
  LL(N, M);
  Graph G(N);
  G.read_graph(M, 0, 0);

  Biconnected_Component BC(G);
  print(len(BC.comp));
  for (auto&& C: BC.comp) { print(len(C), C); }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(_, T) solve();

  return 0;
}
