#include "geo/base.hpp"

// https://codeforces.com/contest/2/problem/C
template <typename REAL, typename T>
Circle<REAL> apollonian_circle(Point<T> A, Point<T> B, T a, T b) {
  assert(a != b);
  Point<REAL> X = (A * b + B * a) / (a + b);
  Point<REAL> Y = (A * b - B * a) / (b - a);
  Point<REAL> O = (X + Y) / 2.0;
  REAL r = dist<REAL>(X, O);
  return Circle<REAL>(O.x, O.y, r);
}