#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/base.hpp"

void solve() {
  LL(N);
  VEC(pi, XY, N);
  Polygon<ll> P(XY);
  print(P.is_convex() ? 1 : 0);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
