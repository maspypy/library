#include "geo/base.hpp"

// 偏角ソートに対する argsort
template <typename T>
vector<int> angle_argsort(vector<Point<T>>& P) {
  auto is_lower = [](Point<T> P) { return (P.y < 0) || (P.y == 0 && P.x > 0); };
  vector<int> lower, origin, upper;
  Point<T> O = {0, 0};
  FOR(i, len(P)) {
    if (P[i] == O) origin.eb(i);
    elif (is_lower(P[i])) lower.eb(i);
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
vector<int> angle_argsort(vector<pair<T, T>> P) {
  vc<Point<T>> tmp(len(P));
  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);
  return angle_argsort(tmp);
}

// inplace に偏角ソートする
// index が欲しい場合は angle_argsort
template <typename T>
void angle_sort(vector<T>& P) {
  auto I = angle_argsort<T>(P);
  P = rearrange(P, I);
}
