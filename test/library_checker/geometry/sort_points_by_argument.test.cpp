#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"
#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/angle_sort.hpp"

void solve() {
  LL(N);
  vc<Point<ll>> P(N);
  FOR(i, N) read(P[i].x), read(P[i].y);
  angle_sort(P);
  FOR(i, N) print(P[i].x, P[i].y);
}

signed main() {
  solve();

  return 0;
}
