#include "geo/base.hpp"
#include "geo/triangle_area.hpp"

template <typename REAL, typename T>
Circle<REAL> outcircle(Point<T> A, Point<T> B, Point<T> C) {
  REAL b1 = B.x - A.x, b2 = B.y - A.y;
  REAL c1 = C.x - A.x, c2 = C.y - A.y;
  REAL bb = (b1 * b1 + b2 * b2) / 2;
  REAL cc = (c1 * c1 + c2 * c2) / 2;

  REAL det = b1 * c2 - b2 * c1;
  REAL x = (b1 * cc - bb * c1) / det;
  REAL y = (bb * c2 - b2 * cc) / det;
  REAL r = sqrt(x * x + y * y);
  x += A.x, y += A.y;
  return Circle<REAL>(x, y, r);
}