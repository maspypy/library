#pragma once

#include "geo/base.hpp"

// 偏角ソートに対する argsort
template <typename T>
vector<int> angle_sort(vector<Point<T>>& P) {
  vector<int> lower, origin, upper;
  const Point<T> O = {0, 0};
  FOR(i, len(P)) {
    if (P[i] == O) origin.eb(i);
    elif ((P[i].y < 0) || (P[i].y == 0 && P[i].x > 0)) lower.eb(i);
    else upper.eb(i);
  }
  sort(all(lower), [&](auto& i, auto& j) { return P[i].det(P[j]) > 0; });
  sort(all(upper), [&](auto& i, auto& j) { return P[i].det(P[j]) > 0; });
  auto& I = lower;
  I.insert(I.end(), all(origin));
  I.insert(I.end(), all(upper));
  return I;
}

// 偏角ソートに対する argsort
template <typename T>
vector<int> angle_sort(vector<pair<T, T>>& P) {
  vc<Point<T>> tmp(len(P));
  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);
  return angle_sort<T>(tmp);
}
