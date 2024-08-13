#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_C"
#define ERROR 0.000001

#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/outcircle.hpp"

void solve() {
  using Re = double;
  LL(a, b, c, d, e, f);
  Point<ll> A(a, b);
  Point<ll> B(c, d);
  Point<ll> C(e, f);
  auto O = outcircle<Re>(A, B, C);
  print(O.O.x, O.O.y, O.r);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
