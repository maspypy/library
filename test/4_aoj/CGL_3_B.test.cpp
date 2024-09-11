#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_B"
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/polygon.hpp"

void solve() {
  LL(N);
  using P = Point<ll>;
  VEC(P, XY, N);
  Polygon<ll> A(XY);
  print(A.is_convex() ? 1 : 0);
}

signed main() {
  solve();

  return 0;
}