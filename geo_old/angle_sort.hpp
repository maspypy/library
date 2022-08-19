#include "geo/base.hpp"

// 偏角ソートに対する argsort
template<typename Point>
vector<int> angle_argsort(vector<Point>& P) {
  auto is_lower = [](Point P) { return (P.y < 0) || (P.y == 0 && P.x > 0); };
  vector<int> lower, origin, upper;
  Point O = {0, 0};
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

// inplace に偏角ソートする
// index が欲しい場合は angle_argsort
template<typename Point>
void angle_sort(vector<Point>& P) {
  auto I = angle_argsort(P);
  vc<Point> Q(len(P));
  FOR(i, len(P)) Q[i] = P[I[i]];
  P = Q;
}
