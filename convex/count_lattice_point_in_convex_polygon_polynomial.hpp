#include "convex/line_min_function.hpp"
#include "mod/floor_sum_of_linear_polynomial.hpp"

// 格子点 (x,y) に対して x^iy^j の sum. i<=K, j<=L
template <typename mint, int K1, int K2>
array<array<mint, K2 + 1>, K1 + 1> count_lattice_point_in_convex_polygon_polynomial(ll L, ll R, vc<tuple<ll, ll, ll>> LINE) {
  vc<tuple<ll, ll, ll>> LINE1, LINE2;
  for (auto &[a, b, c]: LINE) {
    if (b == 0) {
      // ax<=c
      assert(a != 0);
      if (a > 0) { chmin(R, floor<ll>(c, a) + 1); }
      elif (a < 0) { chmax(L, ceil<ll>(-c, -a)); }
    } else {
      if (b > 0) {
        LINE2.eb(-a, c, b);
      } else {
        LINE1.eb(a, -c, -b);
      }
    }
  }
  if (L >= R) { return {}; }
  assert(!LINE1.empty());
  assert(!LINE2.empty());

  auto LOWER = line_max_function_rational(LINE1, L, R);
  auto UPPER = line_min_function_rational(LINE2, L, R);

  array<array<mint, K2 + 2>, K1 + 1> S;
  FOR(i, K1 + 1) FOR(j, K2 + 1) S[i][j] = 0;

  auto wk = [&](ll L, ll R, ll a1, ll b1, ll c1, ll a2, ll b2, ll c2) -> void {
    // 交点 t/s
    i128 s = i128(a2) * c1 - i128(a1) * c2;
    i128 t = i128(b1) * c2 - i128(b2) * c1;
    if (s == 0) {
      if (t > 0) return;
    }
    elif (s > 0) {
      // 上側の方が傾きが大きい
      i128 x = ceil<i128>(t, s);
      chmax(L, x);
    }
    else {
      i128 x = floor<i128>(-t, -s);
      chmin(R, x + 1);
    }
    if (L >= R) return;
    auto ADD = floor_sum_of_linear_polynomial<mint, K1, K2 + 1, ll>(L, R, a2, b2, c2);
    auto SUB = floor_sum_of_linear_polynomial<mint, K1, K2 + 1, ll>(L, R, a1, b1 - 1, c1);
    FOR(i, K1 + 1) FOR(j, K2 + 2) S[i][j] += ADD[i][j] - SUB[i][j];
  };

  merge_58(LOWER, UPPER, wk);
  array<array<mint, K2 + 1>, K1 + 1> ANS;
  FOR(i, K1 + 1) FOR(j, K2 + 1) ANS[i][j] = 0;

  static vvc<mint> CF;
  if (CF.empty()) { CF = faulhaber_formula_2d<mint>(K2); }
  FOR(i, K1 + 1) {
    FOR(j, K2 + 1) {
      FOR(k, j + 2) { ANS[i][j] += CF[j][k] * S[i][k]; }
    }
  }
  return ANS;
}
