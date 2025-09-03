#define PROBLEM "https://yukicoder.me/problems/no/1744"

#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "flow/bipartite.hpp"

void solve() {
  LL(N, M, L);
  using P = pair<int, int>;
  VEC(P, XY, L);
  Graph<bool, 0> G(N + M);
  for (auto&& [x, y]: XY) {
    --x, --y;
    y += N;
    G.add(x, y);
  }
  G.build();
  BipartiteMatching<decltype(G)> BM(G);

  auto [K, W] = BM.DM_decomposition();
  vc<int> CNT(K + 1);

  for (auto&& [x, y]: XY)
    if (W[x] == W[y]) CNT[W[x]]++;
  for (auto&& [x, y]: XY) { No(W[x] == W[y] && CNT[W[x]] == 1); }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
