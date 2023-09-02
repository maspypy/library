#define PROBLEM "https://judge.yosupo.jp/problem/general_matching"
#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/maximum_matching.hpp"
#include "graph/maximum_matching_size.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M, 0, 0);

  auto [ans, mu] = maximum_matching(G);

  vc<pair<int, int>> ANS;
  FOR(v, N) if (v < mu[v]) ANS.eb(v, mu[v]);
  print(ans);
  for (auto&& x: ANS) print(x);
  assert(ans == maximum_matching_size(G));
}

signed main() {
  solve();
  return 0;
}