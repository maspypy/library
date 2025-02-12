#include "mod/floor_monoid_product.hpp"
#include "alg/monoid/monoid_for_floor_sum_pq.hpp"

// 全部非負, T は答, U は ax+b がオーバーフローしない
template <typename T, int K1, int K2, typename U>
array<array<T, K2 + 1>, K1 + 1> floor_sum_of_linear_polynomial_nonnegative_pq(T p, T q, U N, U a, U b, U mod) {
  static_assert(is_same_v<U, u64> || is_same_v<U, u128>);
  assert(a == 0 || N < (U(-1) - b) / a);
  using Mono = Monoid_for_floor_sum_pq<T, K1, K2>;
  Mono::set_pq(p, q);
  auto x = floor_monoid_product<Mono>(Mono::to_x(), Mono::to_y(), N, a, b, mod);
  return x.dp;
};

// sum_{L<=x<R} x^i floor(ax+b,mod)^j
// a+bx が I, U でオーバーフローしない
template <typename T, int K1, int K2, typename I>
array<array<T, K2 + 1>, K1 + 1> floor_sum_of_linear_polynomial_pq(T p, T q, I L, I R, I a, I b, I mod) {
  static_assert(is_same_v<I, ll> || is_same_v<I, i128>);
  assert(L <= R && mod > 0);
  using Mono = Monoid_for_floor_sum_pq<T, K1, K2>;
  Mono::set_pq(p, q);
  if (a < 0) {
    auto ANS = floor_sum_of_linear_polynomial_pq<T, K1, K2, I>(p.inverse(), q, -R + 1, -L + 1, -a, b, mod);
    FOR(i, K1 + 1) {
      if (i % 2 == 1) { FOR(j, K2 + 1) ANS[i][j] = -ANS[i][j]; }
    }
    return ANS;
  }
  assert(a >= 0);
  I ADD_X = L;
  I N = R - L;
  b += a * L;
  I ADD_Y = floor<I>(b, mod);
  b -= ADD_Y * mod;
  assert(a >= 0 && b >= 0);

  using Mono = Monoid_for_floor_sum_pq<T, K1, K2>;
  using Data = typename Mono::Data;
  using U = std::conditional_t<is_same_v<I, ll>, u64, u128>;
  Data A = floor_monoid_product<Mono, Data, U>(Mono::to_x(), Mono::to_y(), N, a, b, mod);
  Data offset = Mono::unit();
  offset.dx = T(ADD_X), offset.dy = T(ADD_Y);
  A = Mono::op(offset, A);
  T mul = p.pow(ADD_X) * q.pow(ADD_Y);
  FOR(i, K1 + 1) FOR(j, K2 + 1) A.dp[i][j] *= mul;
  return A.dp;
};
