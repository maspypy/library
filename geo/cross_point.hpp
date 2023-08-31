#pragma once

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

// 浮動小数点数はエラー
// 0: 交点なし
// 1: 一意な交点
// 2：2 つ以上の交点（整数型を利用して厳密にやる）
template <typename T>
int count_cross(Segment<T> S1, Segment<T> S2, bool include_ends) {
  static_assert(!std::is_floating_point<T>::value);
  Line<T> L1 = S1.to_Line();
  Line<T> L2 = S2.to_Line();
  if (L1.is_parallel(L2)) {
    if (L1.eval(S2.A) != 0) return 0;
    // 4 点とも同一直線上にある
    T a1 = S1.A.x, b1 = S1.B.x;
    T a2 = S2.A.x, b2 = S2.B.x;
    if (a1 == b1) {
      a1 = S1.A.y, b1 = S1.B.y;
      a2 = S2.A.y, b2 = S2.B.y;
    }
    if (a1 > b1) swap(a1, b1);
    if (a2 > b2) swap(a2, b2);
    T a = max(a1, a2);
    T b = min(b1, b2);
    if (a < b) return 2;
    if (a > b) return 0;
    return (include_ends ? 1 : 0);
  }
  // 平行でない場合
  T a1 = L2.eval(S1.A), b1 = L2.eval(S1.B);
  T a2 = L1.eval(S2.A), b2 = L1.eval(S2.B);
  if (a1 > b1) swap(a1, b1);
  if (a2 > b2) swap(a2, b2);
  bool ok1 = 0, ok2 = 0;

  if (include_ends) {
    ok1 = (a1 <= 0) && (0 <= b1);
    ok2 = (a2 <= 0) && (0 <= b2);
  } else {
    ok1 = (a1 < 0) && (0 < b1);
    ok2 = (a2 < 0) && (0 < b2);
  }
  return (ok1 && ok2 ? 1 : 0);
}

template <typename REAL, typename T>
vc<Point<REAL>> cross_point(const Circle<T> C, const Line<T> L) {
  T a = L.a, b = L.b, c = L.a * (C.O.x) + L.b * (C.O.y) + L.c;
  T r = C.r;
  // ax+by+c=0, x^2+y^2=r^2
  if (a == 0) {
    REAL y = REAL(-c) / b;
    REAL bbxx = b * b * r * r - c * c;
    if (bbxx < 0) return {};
    if (bbxx == 0) return {Point<REAL>(0 + C.O.x, y + C.O.y)};
    REAL x = sqrtl(bbxx) / b;
    return {Point<REAL>(-x + C.O.x, y + C.O.y),
            Point<REAL>(+x + C.O.x, y + C.O.y)};
  }
  T D = 4 * a * a * b * b - 4 * (a * a + b * b) * (c * c - a * a * r * r);
  if (D < 0) return {};
  REAL sqD = sqrtl(D);
  REAL y1 = (-2 * a * c + sqD) / (2 * (a * a + b * b));
  REAL y2 = (-2 * a * c - sqD) / (2 * (a * a + b * b));
  REAL x1 = (-b * y1 - c) / a;
  REAL x2 = (-b * y2 - c) / a;
  x1 += C.O.x, x2 += C.O.x;
  y1 += C.O.y, y2 += C.O.y;
  if (D == 0) return {Point<REAL>(x1, y1)};
  return {Point<REAL>(x1, y1), Point<REAL>(x2, y2)};
}
