#define PROBLEM "https://atcoder.jp/contests/abc151/tasks/abc151_f"
#define ERROR 0.000001

#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/minimum_enclosing_circle.hpp"

void solve() {
  LL(N);
  using Re = double;
  using P = Point<Re>;
  VEC(P, points, N);
  auto [i, j, k] = minimum_enclosing_circle(points);
  if (k == -1) {
    Re r = dist<Re>(points[i], points[j]);
    print(r / 2);
  } else {
    auto c = outcircle<Re>(points[i], points[j], points[k]);
    print(c.r);
  }
}

signed main() {
  solve();
  return 0;
}