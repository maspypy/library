
#include "mod/floor_monoid_product.hpp"
#include "alg/monoid/monoid_for_floor_sum.hpp"

// sum(i^k*floor) for k=0,1,...,K
template <typename T, int K, typename U>
array<T, K + 1> floor_sum_of_linear_polynomial(U N, U a, U b, U mod) {
  static_assert(is_same_v<U, u64> || is_same_v<U, u128>);
  assert(a == 0 || N < (U(-1) - b) / a);
  using Mono = Monoid_for_floor_sum<T, K>;
  auto z = floor_monoid_product<Mono>(Mono::to_x(), Mono::to_y(), N, a, b, mod);
  return z.dp[1];
};