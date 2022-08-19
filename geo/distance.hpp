#include "geo/cross_point.hpp"

template <typename REAL, typename T, typename U>
REAL distance(Point<T> S, Point<U> P) {
  REAL dx = P.x - S.x;
  REAL dy = P.y - S.y;
  return sqrt(dx * dx + dy * dy);
}

template <typename REAL, typename T, typename U>
REAL distance(Segment<T> S, Point<U> P) {
  Point<T> A = S.A, B = S.B;
  bool b1 = (B - A).dot(P - A) >= 0;
  bool b2 = (A - B).dot(P - B) >= 0;
  if (b1 && !b2) { return distance<REAL, T, T>(B, P); }
  if (!b1 && b2) { return distance<REAL, T, T>(A, P); }
  Line<T> L = S.to_Line();
  // 点と直線の距離
  return REAL(abs(L.eval(P))) / sqrt(REAL(L.a) * L.a + REAL(L.b) * L.b);
}

template <typename REAL, typename T>
REAL distance(Segment<T> S1, Segment<T> S2) {
  if (count_cross<T>(S1, S2, true)) return REAL(0);
  REAL res = distance<REAL, T, T>(S1, S2.A);
  chmin(res, distance<REAL, T, T>(S1, S2.B));
  chmin(res, distance<REAL, T, T>(S2, S1.A));
  chmin(res, distance<REAL, T, T>(S2, S1.B));
  return res;
}
