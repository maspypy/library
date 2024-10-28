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
  auto [C, i, j, k] = minimum_enclosing_circle<Re>(points);
  print(C.r);
}

signed main() {
  solve();
  return 0;
}