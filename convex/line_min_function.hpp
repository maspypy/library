#include "geo/convex_hull.hpp"

// 1 次関数の max を [L,R,a,b] の列として出力
// https://qoj.ac/contest/1576/problem/8505
template <typename Re, typename T>
vc<tuple<Re, Re, Re, Re>> line_min_function_real(vc<pair<T, T>> LINE) {
  assert(!LINE.empty());
  using P = Point<T>;
  vc<P> point;
  for (auto& [x, y]: LINE) point.eb(P(x, y));
  auto I = ConvexHull(point, "lower");
  point = rearrange(point, I);
  int N = len(point);
  if (N >= 2 && point[N - 1].x == point[N - 2].x) { POP(point), --N; }
  reverse(all(point)); // 傾きは大きい方から
  Re l = -infty<Re>;
  vc<tuple<Re, Re, Re, Re>> ANS;
  FOR(i, N) {
    Re r = infty<Re>;
    auto [a, b] = point[i];
    if (i + 1 < N) {
      auto [c, d] = point[i + 1];
      if (a == c) continue;
      assert(a > c);
      r = Re(d - b) / (a - c);
      chmax(r, l), chmin(r, infty<Re>);
    }
    if (l < r) ANS.eb(l, r, a, b), l = r;
  }
  return ANS;
}

// 1 次関数の max を [L,R,a,b] の列として出力
template <typename Re, typename T>
vc<tuple<Re, Re, Re, Re>> line_max_function_real(vc<pair<T, T>> LINE) {
  assert(!LINE.empty());
  for (auto& [a, b]: LINE) a = -a, b = -b;
  auto ANS = line_min_function_real<Re, T>(LINE);
  for (auto& [l, r, a, b]: ANS) a = -a, b = -b;
  return ANS;
}
