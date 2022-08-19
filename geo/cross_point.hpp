#include "geo/base.hpp"

// 平行であるときには、完全に一致するときも含めて false をかえす
// false のときには原点が返る。
template <typename REAL, typename T>
pair<bool, Point<REAL>> cross_point(const Line<T>& L1, const Line<T>& L2) {
  T det = L1.a * L2.b - L1.b * L2.a;
  if (det == 0) return {false, Point<REAL>(0, 0)};
  REAL x = -REAL(L1.c) * L2.b + REAL(L1.b) * L2.c;
  REAL y = -REAL(L1.a) * L2.c + REAL(L1.c) * L2.a;
  return {true, Point<REAL>(x / det, y / det)};
}