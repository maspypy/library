
#include "seq/geometric_sequence_sum_formula.hpp"
#include "convex/line_min_function.hpp"
#include "convex/lattice_point_sum_polynomial.hpp"
#include "mod/floor_sum_of_linear_polynomial.hpp"
#include "mod/floor_sum_of_linear_polynomial_pq.hpp"

// 格子点 (x,y) に対して p^xq^yx^iy^j の sum. i<=K, j<=L
template <typename mint, int K1, int K2>
array<array<mint, K2 + 1>, K1 + 1> lattice_point_sum_polynomial_pq(mint p, mint q, vc<tuple<ll, ll, ll>> LINE) {
  assert(p != 0 && q != 0);
  if (p == 1 && q == 1) return lattice_point_sum_polynomial<mint, K1, K2>(LINE);
  if (q == 1) {
    for (auto& [a, b, c]: LINE) { swap(a, b); }
    auto tmp = lattice_point_sum_polynomial_pq<mint, K2, K1>(q, p, LINE);
    array<array<mint, K2 + 1>, K1 + 1> ANS{};
    FOR(i, K1 + 1) FOR(j, K2 + 1) ANS[i][j] = tmp[j][i];
    return ANS;
  }
  assert(q != 1);
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
  if (L >= R) { return {}; }
  if (LINE1.empty() || LINE2.empty()) return {};

  auto LOWER = line_max_function_rational(LINE1, L, R);
  auto UPPER = line_min_function_rational(LINE2, L, R);

  array<array<mint, K2 + 1>, K1 + 1> S{};
  array<mint, K1 + 1> T{};

  bool bad = 0;
  auto wk = [&](ll L, ll R, ll a1, ll b1, ll c1, ll a2, ll b2, ll c2) -> void {
    if (bad) return;
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
    b2 = b2 + c2, b1 = b1 - 1 + c1;
    auto ADD_S = floor_sum_of_linear_polynomial_pq<mint, K1, K2, ll>(p, q, L, R, a2, b2, c2);
    auto SUB_S = floor_sum_of_linear_polynomial_pq<mint, K1, K2, ll>(p, q, L, R, a1, b1, c1);
    auto ADD_T = floor_sum_of_linear_polynomial_pq<mint, K1, 0, ll>(p, 1, L, R, a2, b2, c2);
    auto SUB_T = floor_sum_of_linear_polynomial_pq<mint, K1, 0, ll>(p, 1, L, R, a1, b1, c1);
    FOR(i, K1 + 1) FOR(j, K2 + 1) S[i][j] += ADD_S[i][j] - SUB_S[i][j];
    FOR(i, K1 + 1) T[i] += ADD_T[i][0] - SUB_T[i][0];
  };

  merge_58(LOWER, UPPER, wk);
  array<array<mint, K2 + 1>, K1 + 1> ANS{};
  if (bad) return ANS;

  FOR(k, K2 + 1) {
    auto [c, f] = geometric_sequence_sum_formula(q, k);
    FOR(i, K1 + 1) {
      ANS[i][k] += c * T[i];
      FOR(j, k + 1) { ANS[i][k] += f[j] * S[i][j]; }
    }
  }

  return ANS;
}
