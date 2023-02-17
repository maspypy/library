#define PROBLEM \
  "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"
#define ERROR 0.000001
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/closest_pair.hpp"

void solve() {
  LL(N);
  using Re = double;
  using P = Point<Re>;
  VEC(P, points, N);
  auto [i, j] = closest_pair(points);
  Re ANS = dist<Re>(points[i], points[j]);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}