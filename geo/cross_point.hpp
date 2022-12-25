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
int count_cross(Segment<T> S1, Segment<T> S2, bool include_ends) {
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

// 0 または 1
// real だと誤差によっては間違った答を返す可能性あり。
template <typename T>
int count_cross(Segment<T> S1, Segment<T> S2) {
  Line<T> L1 = S1.to_Line();
  Line<T> L2 = S2.to_Line();
  T a1 = L2.eval(S1.A), b1 = L2.eval(S1.B);
  T a2 = L1.eval(S2.A), b2 = L1.eval(S2.B);
  if (a1 > b1) swap(a1, b1);
  if (a2 > b2) swap(a2, b2);
  bool ok1 = 0, ok2 = 0;
  ok1 = (a1 <= 0) && (0 <= b1);
  ok2 = (a2 <= 0) && (0 <= b2);
  return (ok1 && ok2 ? 1 : 0);
}

// 唯一の交点を持つことを仮定
template <typename REAL, typename T>
Point<REAL> cross_point(Segment<T> S1, Segment<T> S2) {
  Line<T> L1 = S1.to_Line();
  Line<T> L2 = S2.to_Line();
  return cross_point<REAL, T>(L1, L2);
}
