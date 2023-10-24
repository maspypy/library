#include "geo/base.hpp"
#include "random/shuffle.hpp"
#include "geo/outcircle.hpp"

// randomize を利用した expected O(N) アルゴリズム
// Computational Geometry, Section 4.7
// https://codeforces.com/problemset/problem/119/E
template <typename REAL, typename T>
Circle<REAL> minimum_enclosing_circle(vc<Point<T>> points, REAL eps = 1e-12) {
  using C = Circle<REAL>;
  shuffle(points);
  const int n = len(points);
  assert(n >= 1);

  if (n == 1) { return C(points[0].x, points[0].y, 0); }
  auto contain = [&](C& c, Point<T> p) -> bool {
    REAL x = c.O.x - p.x;
    REAL y = c.O.y - p.y;
    return x * x + y * y <= (1 + eps) * (c.r * c.r);
  };
  auto make2 = [&](int i, int j) -> C {
    REAL x = (points[i].x + points[j].x) * 0.5;
    REAL y = (points[i].y + points[j].y) * 0.5;
    REAL r = dist<REAL, T>(points[i], points[j]) * 0.5;
    return C(x, y, r);
  };
  auto make3 = [&](int i, int j, int k) -> C {
    return outcircle<REAL, T>(points[i], points[j], points[k]);
  };

  C c = make2(0, 1);
  FOR(i, 2, n) {
    if (contain(c, points[i])) continue;
    // min disc with point i
    c = make2(0, i);
    FOR(j, 1, i) {
      if (contain(c, points[j])) continue;
      // min disc with point i, j
      c = make2(i, j);
      FOR(k, j) {
        if (contain(c, points[k])) continue;
        c = make3(i, j, k);
      }
    }
  }
  return c;
}