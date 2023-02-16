#define PROBLEM "https://atcoder.jp/contests/abc283/tasks/abc283_f"
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/manhattan_mst.hpp"

void solve() {
  LL(N);
  vc<pair<int, int>> dat(N);
  FOR(i, N) {
    INT(p);
    dat[i] = {i, p};
  }
  auto G = manhattan_mst(dat);
  const int INF = 1 << 30;
  vc<int> ANS(N, INF);
  for (auto&& e: G.edges) {
    chmin(ANS[e.frm], e.cost);
    chmin(ANS[e.to], e.cost);
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}