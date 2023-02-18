#include "geo/base.hpp"
#include "random/shuffle.hpp"
#include "geo/outcircle.hpp"

// randomize を利用した O(N) アルゴリズム
// Computational Geometry, Section 4.7
template <typename REAL, typename T>
Circle<REAL> minimum_enclosing_circle(vc<Point<T>> points) {
  using C = Circle<REAL>;
  shuffle(points);
  const int n = len(points);
  assert(n >= 1);
  if (n == 1) { return C(points[0].x, points[0].y, 0); }
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
    if (c.contain(points[i])) continue;
    // i を含むという制約で作り直す。
    // これをやるのは確率 O(1/i) で、O(i) 時間かける。
    c = make2(0, i);
    FOR(j, 1, i) {
      if (c.contain(points[j])) continue;
      c = make2(i, j);
      FOR(k, j) {
        if (c.contain(points[k])) continue;
        c = make3(i, j, k);
      }
    }
  }
  return c;
}