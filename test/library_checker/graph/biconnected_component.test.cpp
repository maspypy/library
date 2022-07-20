#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/biconnected_component.hpp"


void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);

  Biconnected_Component<decltype(G)> BC(G);
  auto& ANS = BC.comp_v;
  print(len(ANS));
  for (auto&& C: ANS) { print(len(C), C); }
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
