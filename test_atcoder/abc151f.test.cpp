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
  auto c = minimum_enclosing_circle<Re, Re>(points);
  print(c.r);
}

signed main() {
  solve();
  return 0;
}