#include "geo/base.hpp"
#include "random/shuffle.hpp"
#include "geo/outcircle.hpp"

// randomize を利用した expected O(N) アルゴリズム
// 座標の 4 乗が登場！オーバーフロー注意！
// return: {C,0,-1,-1} or {C,i,j,-1} or {C,i,j,k}
// https://codeforces.com/problemset/problem/119/E
// https://qoj.ac/contest/1452/problem/7934
template <typename REAL, typename T>
tuple<Circle<REAL>, int, int, int> minimum_enclosing_circle(vc<Point<T>> points) {
  const int n = len(points);
  assert(n >= 1);
  if (n == 1) {
    Circle<REAL> C(points[0].x, points[0].y, 0);
    return {C, 0, -1, -1};
  }
  vc<int> I(n);
  FOR(i, n) I[i] = i;
  shuffle(I);

  points = rearrange(points, I);

  tuple<int, int, int> c = {0, -1, -1};
  auto contain = [&](Point<T> p) -> bool {
    auto [i, j, k] = c;
    if (j == -1) { return p == points[i]; }
    if (k == -1) { return (points[i] - p).dot(points[j] - p) <= 0; }
    return outcircle_side(points[i], points[j], points[k], p) >= 0;
  };

  FOR(i, 1, n) {
    if (contain(points[i])) continue;
    c = {0, i, -1};
    FOR(j, 1, i) {
      if (contain(points[j])) continue;
      c = {i, j, -1};
      FOR(k, j) {
        if (contain(points[k])) continue;
        c = {i, j, k};
      }
    }
  }
  auto [i, j, k] = c;
  if (k == -1) {
    REAL x1 = points[i].x;
    REAL y1 = points[i].y;
    REAL x2 = points[j].x;
    REAL y2 = points[j].y;
    Point<REAL> O = {0.5 * (x1 + x2), 0.5 * (y1 + y2)};
    REAL r = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) / 2;
    Circle<REAL> C(O, r);
    return {C, I[i], I[j], -1};
  }
  Circle<REAL> C = outcircle<REAL>(points[i], points[j], points[k]);
  return {C, I[i], I[j], I[k]};
}