#pragma once

#include "geo/base.hpp"

template <typename T>
vector<int> ConvexHull(vector<Point<T>>& XY, string mode = "full",
                       bool sorted = false) {
  assert(mode == "full" || mode == "lower" || mode == "upper");
  ll N = XY.size();
  if (N == 1) return {0};
  if (N == 2) {
    if (XY[0] < XY[1]) return {0, 1};
    if (XY[1] < XY[0]) return {1, 0};
    return {0};
  }
  vc<int> I(N);
  if (sorted) {
    FOR(i, N) I[i] = i;
  } else {
    I = argsort(XY);
  }

  auto check = [&](ll i, ll j, ll k) -> bool {
    auto xi = XY[i].x, yi = XY[i].y;
    auto xj = XY[j].x, yj = XY[j].y;
    auto xk = XY[k].x, yk = XY[k].y;
    auto dx1 = xj - xi, dy1 = yj - yi;
    auto dx2 = xk - xj, dy2 = yk - yj;
    T det = dx1 * dy2 - dy1 * dx2;
    return det > 0;
  };

  auto calc = [&]() {
    vector<int> P;
    for (auto&& k: I) {
      while (P.size() > 1) {
        auto i = P[P.size() - 2];
        auto j = P[P.size() - 1];
        if (check(i, j, k)) break;
        P.pop_back();
      }
      P.eb(k);
    }
    return P;
  };

  vc<int> P;
  if (mode == "full" || mode == "lower") {
    vc<int> Q = calc();
    P.insert(P.end(), all(Q));
  }
  if (mode == "full" || mode == "upper") {
    if (!P.empty()) P.pop_back();
    reverse(all(I));
    vc<int> Q = calc();
    P.insert(P.end(), all(Q));
  }
  if (mode == "upper") reverse(all(P));
  while (len(P) >= 2 && XY[P[0]] == XY[P.back()]) P.pop_back();
  return P;
}