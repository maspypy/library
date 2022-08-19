#include "geo/base.hpp"

// 平行でないことを仮定
template <typename REAL, typename T>
Point<REAL> cross_point(const Line<T> L1, const Line<T> L2) {
  T det = L1.a * L2.b - L1.b * L2.a;
  assert(det != 0);
  REAL x = -REAL(L1.c) * L2.b + REAL(L1.b) * L2.c;
  REAL y = -REAL(L1.a) * L2.c + REAL(L1.c) * L2.a;
  return Point<REAL>(x / det, y / det);
}

// 0: 交点なし
// 1: 一意な交点
// 2：2 つ以上の交点（整数型を利用して厳密にやる）
template <typename T, enable_if_t<is_integral<T>::value, int> = 0>
int count_cross(Segment<T> S1, Segment<T> S2) {
  return 0;
}

//
template <typename T>
int count_cross(Segment<T> S1, Segment<T> S2) {
  return 0;
}

// 唯一の交点を持つことを仮定
template <typename REAL, typename T>
Point<REAL> cross_point(const Segment<T> S1, const Segment<T> S2) {
  return cross_point(S1.to_Line(), S2.to_Line());
}
