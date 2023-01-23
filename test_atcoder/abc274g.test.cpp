#define PROBLEM "https://atcoder.jp/contests/abc274/tasks/abc274_g"
#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/bipartite.hpp"

void solve() {
  LL(H, W);
  VEC(string, S, H);
  Graph<bool, 0> G(2 * H * W);

  FOR(x, H) FOR(y, W) {
    if (S[x][y] == '#') continue;
    ll px = x;
    ll py = y;
    while (px > 0 && S[px - 1][y] == '.') --px;
    while (py > 0 && S[x][py - 1] == '.') --py;
    // (px,y), (x, py)
    ll a = W * px + y;
    ll b = W * x + py;
    G.add(a, b + H * W);
  }
  G.build();

  BipartiteMatching<decltype(G)> X(G);
  auto cov = X.vertex_cover();
  print(len(cov));
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}