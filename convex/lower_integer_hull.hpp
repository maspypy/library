
#include "geo/base.hpp"
#include "convex/line_min_function.hpp"

// https://atcoder.jp/contests/arc130/tasks/arc130_f
// 整数傾きで下からおさえる. 2n-1点以下.
vc<Point<ll>> lower_integer_hull(vc<Point<ll>> point) {
  using P = Point<ll>;
  int n = len(point);
  assert(n > 0);
  P L(infty<ll>, infty<ll>), R(-infty<ll>, infty<ll>);
  for (auto& p: point) {
    if (L.x > p.x) L = p;
    if (R.x < p.x) R = p;
    if (L.x == p.x) chmin(L.y, p.y);
    if (R.x == p.x) chmin(R.y, p.y);
  }
  if (L.x == R.x) return {L};

  vc<pi> line;
  for (auto& p: point) line.eb(-p.x, p.y);
  auto dat = line_min_function_integer(line, -infty<ll>, infty<ll>);

  vc<P> ANS = {L};
  auto add = [&](ll x, ll y) -> void {
    if (ANS.back().x < x) ANS.eb(P(x, y));
  };
  FOR(i, len(dat) - 1) {
    auto [xx, a1, p1, q1] = dat[i];
    auto [a2, yy, p2, q2] = dat[i + 1];
    --a1;
    ll b1 = p1 * a1 + q1;
    ll b2 = p2 * a2 + q2;
    ll x = (b1 - b2) / (a2 - a1);
    ll y = a1 * x + b1;
    add(x, y);
    if (i == len(dat) - 2) break;
    a1 = a2, a2 = yy - 1;
    b1 = p2 * a1 + q2;
    b2 = p2 * a2 + q2;
    if (a1 < a2) {
      x = (b1 - b2) / (a2 - a1);
      y = a1 * x + b1;
      add(x, y);
    }
  }
  add(R.x, R.y);
  return ANS;
}
