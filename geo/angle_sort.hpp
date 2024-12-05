#pragma once

#include "geo/base.hpp"

// lower: -1, origin: 0, upper: 1, (-pi,pi]
template <typename T> int lower_or_upper(const Point<T> &p) {
  if (p.y != 0)
    return (p.y > 0 ? 1 : -1);
  if (p.x > 0)
    return -1;
  if (p.x < 0)
    return 1;
  return 0;
}

// L<R:-1, L==R:0, L>R:1, (-pi,pi]
template <typename T> int angle_comp_3(const Point<T> &L, const Point<T> &R) {
  int a = lower_or_upper(L), b = lower_or_upper(R);
  if (a != b)
    return (a < b ? -1 : +1);
  T det = L.det(R);
  if (det > 0)
    return -1;
  if (det < 0)
    return 1;
  return 0;
}

// 偏角ソートに対する argsort, (-pi,pi]
template <typename T> vector<int> angle_sort(vector<Point<T>> &P) {
  vc<int> I(len(P));
  FOR(i, len(P)) I[i] = i;
  sort(all(I), [&](auto &L, auto &R) -> bool {
    return angle_comp_3(P[L], P[R]) == -1;
  });
  return I;
}

// 偏角ソートに対する argsort, (-pi,pi]
template <typename T> vector<int> angle_sort(vector<pair<T, T>> &P) {
  vc<Point<T>> tmp(len(P));
  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);
  return angle_sort<T>(tmp);
}
