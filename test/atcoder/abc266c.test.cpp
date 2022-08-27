#define PROBLEM "https://atcoder.jp/contests/abc266/tasks/abc266_c"
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/incremental_convexhull.hpp"

void solve() {
  Incremental_ConvexHull<ll, true> X;
  FOR(4) {
    LL(a, b);
    Point<ll> P(a, b);
    X.add(P);
  }
  Yes(len(X) == 4);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
