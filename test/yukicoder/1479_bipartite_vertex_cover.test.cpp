#define PROBLEM "https://yukicoder.me/problems/no/1479"
#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"
#include "flow/bipartite.hpp"

void solve() {
  LL(H, W);
  ll LIM = 500000;
  vvc<pi> dat(LIM + 1);
  FOR(x, H) FOR(y, W) {
    LL(v);
    dat[v].eb(x, y);
  }
  ll ANS = 0;
  FOR3(v, 1, LIM + 1) {
    auto& XY = dat[v];
    if (len(XY) == 0) continue;
    vi X, Y;
    for (auto&& [x, y]: XY) {
      X.eb(x);
      Y.eb(y);
    }
    UNIQUE(X);
    UNIQUE(Y);
    Graph G(len(X) + len(Y));
    for (auto&& [x, y]: XY) {
      x = LB(X, x);
      y = LB(Y, y);
      G.add(x, len(X) + y);
    }
    G.build();
    BipartiteMatching BM(G);
    auto cov = BM.vertex_cover();
    ANS += len(cov);
    // print(v, len(cov));
  }
  print(ANS);
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
