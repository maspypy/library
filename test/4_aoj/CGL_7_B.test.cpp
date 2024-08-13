#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_B"
#define ERROR 0.000001

#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/base.hpp"
#include "geo/distance.hpp"
#include "geo/incircle.hpp"

void solve() {
  LL(a, b, c, d, e, f);
  Point<ll> A(a, b), B(c, d), C(e, f);
  auto X = incircle<double>(A, B, C);
  print(X.O.x, X.O.y, X.r);
}

signed main() {
  cout << fixed << setprecision(15);

  ll T = 1;
  // LL(T);
  FOR(T) solve();

  return 0;
}
