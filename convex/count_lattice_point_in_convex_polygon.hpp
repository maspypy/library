#include "convex/line_min_function.hpp"
#include "mod/floor_sum_of_linear.hpp"

// L<=x<R, ax+by>=c という半平面たち
// 有界でないときは -1 を返す
// ab がオーバーフローしないなど
// https://codeforces.com/contest/1098/submission/299841182
i128 count_lattice_point_in_convex_polygon(ll L, ll R, vc<tuple<ll, ll, ll>> LINE) {
  vc<tuple<ll, ll, ll>> LINE1, LINE2;
  for (auto& [a, b, c]: LINE) {
    if (b == 0) {
      // ax>=c
      assert(a != 0);
      if (a > 0) { chmax(L, ceil<ll>(c, a)); }
      elif (a < 0) { chmin(R, floor<ll>(-c, -a) + 1); }
    } else {
      if (b > 0) {
        LINE1.eb(-a, c, b);
      } else {
        LINE2.eb(a, -c, -b);
      }
    }
  }
  if (L >= R) return 0;
  if (LINE1.empty() || LINE2.empty()) return -1;

  auto LOWER = line_max_function_rational(LINE1, L, R);
  auto UPPER = line_min_function_rational(LINE2, L, R);

  i128 ANS = 0;

  auto wk = [&](ll L, ll R, ll a1, ll b1, ll c1, ll a2, ll b2, ll c2) -> void {
    if (a1 * c2 > a2 * c1) {
      a1 = -a1, b1 = -b1;
      a2 = -a2, b2 = -b2;
    }
    i128 lhs = i128(a1 * L + b1) * c2;
    i128 rhs = i128(a2 * L + b2) * c1;
    if (lhs > rhs) {
      ll s = a2 * c1 - a1 * c2;
      ll t = b1 * c2 - b2 * c1;
      if (s == 0) return;
      chmax(L, ceil<ll>(t, s));
    }
    if (L >= R) return;
    ANS += floor_sum_of_linear<i128, ll>(L, R, a2, b2, c2);
    ANS -= floor_sum_of_linear<i128, ll>(L, R, a1, b1 - 1, c1);
  };

  reverse(all(LOWER));
  reverse(all(UPPER));
  while (len(LOWER) && len(UPPER)) {
    auto [L1, R1, a1, b1, c1] = POP(LOWER);
    auto [L2, R2, a2, b2, c2] = POP(UPPER);
    assert(L1 == L2);
    ll R = min(R1, R2);
    wk(L1, R, a1, b1, c1, a2, b2, c2);
    if (R < R1) LOWER.eb(R, R1, a1, b1, c1);
    if (R < R2) UPPER.eb(R, R2, a2, b2, c2);
  }
  return ANS;
}
