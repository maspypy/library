#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/bracket_graph.hpp"
#include "graph/hld.hpp"

void solve() {
  LL(N, Q);
  STR(S);
  auto [G, LR] = bracket_graph(S);
  vi idx(N);
  FOR(i, 1, len(LR)) {
    auto [L, R] = LR[i];
    idx[L] = idx[R - 1] = i;
  }

  HLD hld(G);

  FOR(Q) {
    LL(a, b);
    --a, --b;
    int i = idx[a], j = idx[b];
    int k = hld.lca(i, j);
    if (k == 0)
      print(-1);
    else {
      auto [l, r] = LR[k];
      print(l + 1, r);
    }
  }
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
