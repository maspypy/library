#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/strongly_connected_component.hpp"

void solve() {
  LL(N, M);
  Graph<int, 1> G(N);
  G.read_graph(M, 0, 0);

  auto [C, comp] = strongly_connected_component(G);
  vc<vc<int>> ANS(C);
  FOR(v, N) ANS[comp[v]].eb(v);
  print(len(ANS));
  for (auto&& C: ANS) print(len(C), C);
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << setprecision(15);

  solve();

  return 0;
}
