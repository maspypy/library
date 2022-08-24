#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0010"

#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/outcircle.hpp"

using Re = double;

void solve() {
  DBL(x1, y1, x2, y2, x3, y3);
  Point<Re> A(x1, y1);
  Point<Re> B(x2, y2);
  Point<Re> C(x3, y3);
  auto X = outcircle<Re, Re>(A, B, C);
  printf("%.3f %.3f %.3f\n", X.O.x, X.O.y, X.r);
}

signed main() {
  cout << fixed << setprecision(15);

  LL(T);
  FOR(T) solve();

  return 0;
}