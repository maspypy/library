#define PROBLEM "https://judge.yosupo.jp/problem/manhattanmst"
#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/manhattan_mst.hpp"

void solve() {
  LL(N);
  using P = pair<int, int>;
  VEC(P, XY, N);
  auto G = manhattan_mst<int>(XY);
  ll ANS = 0;
  for (auto&& e: G.edges) { ANS += e.cost; }
  print(ANS);
  for (auto&& e: G.edges) { print(e.frm, e.to); }
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
