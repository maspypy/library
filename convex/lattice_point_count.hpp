#include "convex/line_min_function.hpp"
#include "mod/floor_sum_of_linear.hpp"

// ax+by<=c という半平面たち
// 有界でないときは 0 を返す
// （格子点が 0 個ということはあるので答えが inf とは限らない）
// 入力が pow(10,18) 以下とかであればオーバーフローしないつもり
i128 lattice_point_count(vc<tuple<ll, ll, ll>> LINE) {
  ll L = -infty<ll>, R = infty<ll>;
  vc<tuple<ll, ll, ll>> LINE1, LINE2;
  for (auto& [a, b, c]: LINE) {
    if (b == 0) {
      assert(a != 0);
      if (a > 0) { chmin(R, floor<ll>(c, a) + 1); }
      elif (a < 0) { chmax(L, ceil<ll>(-c, -a)); }
    } else {
      if (b > 0) { LINE2.eb(-a, c, b); }
      if (b < 0) { LINE1.eb(a, -c, -b); }
    }
  }
  if (L >= R) return 0;
  if (LINE1.empty() || LINE2.empty()) return 0;

  auto LOWER = line_max_function_rational(LINE1, L, R);
  auto UPPER = line_min_function_rational(LINE2, L, R);

  i128 ANS = 0;

  bool bad = 0;
  auto wk = [&](ll L, ll R, ll a1, ll b1, ll c1, ll a2, ll b2, ll c2) -> void {
    // 交点 t/s
    i128 s = i128(a2) * c1 - i128(a1) * c2;
    i128 t = i128(b1) * c2 - i128(b2) * c1;
    if (s == 0) {
      if (t > 0) return;
    }
    if (s > 0) { chmax(L, ceil<i128>(t, s)); }
    if (s < 0) { chmin(R, floor<i128>(-t, -s) + 1); }
    if (L >= R) return;
    if (L == -infty<ll> || R == infty<ll>) {
      bad = 1;
      return;
    }
    ANS += floor_sum_of_linear<i128, i128>(L, R, a2, b2, c2);
    ANS -= floor_sum_of_linear<i128, i128>(L, R, a1, b1 - 1, c1);
  };

  merge_58(LOWER, UPPER, wk);
  if (bad) return 0;
  return ANS;
}
