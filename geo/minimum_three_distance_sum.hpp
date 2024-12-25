#include "geo/cross_point.hpp"

// Fermat point OR vertex
// https://codeforces.com/problemset/problem/1662/K
template <typename Re>
Re minimum_three_distance_sum(Point<Re> A, Point<Re> B, Point<Re> C) {
  using P = Point<Re>;
  const Re PI = acos(-1);
  if (ccw(A, B, C) == -1) { swap(B, C); }
  Re ANS = infty<Re>;
  Re AB = dist<Re>(A, B);
  Re AC = dist<Re>(A, C);
  Re BC = dist<Re>(B, C);
  chmin(ANS, AB + AC);
  chmin(ANS, AB + BC);
  chmin(ANS, AC + BC);

  auto get = [&](P A, P B) -> Circle<Re> {
    P p = B - A;
    p = p.rotate(-PI / 6);
    p = p * (sqrtl(Re(1.0) / 3));
    Re r = p.norm();
    return Circle<Re>(A + p, r);
  };

  Circle<Re> C1 = get(A, B), C2 = get(B, C);
  auto [ok, p1, p2] = cross_point_circle<Re, Re>(C1, C2);
  for (auto& p: {p1, p2}) {
    Re d = 0;
    for (P q: {A, B, C}) d += dist<Re>(p, q);
    chmin(ANS, d);
  }
  return ANS;
}
