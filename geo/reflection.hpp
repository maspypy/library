#pragma once

#include "geo/base.hpp"

template <typename REAL, typename T, typename U>
Point<REAL> reflection(Point<T> P, Line<U> L) {
  REAL t = REAL(L.eval(P)) / (L.a * L.a + L.b * L.b);
  REAL x = P.x - 2 * t * L.a;
  REAL y = P.y - 2 * t * L.b;
  return Point<REAL>(x, y);
};
