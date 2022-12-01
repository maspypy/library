#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"
#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/offline_query/rectangleunion.hpp"

void solve() {
  LL(N);
  RectangleUnion<int> RU;
  FOR(N) {
    LL(a, b, c, d);
    RU.add_rect(a, c, b, d);
  }
  print(RU.calc());
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
