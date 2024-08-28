#include "nt/convex_floor_sum.hpp"

// sum_[1,N] sigma_0(n)
template <typename T = u64>
T sigma_0_sum_small(u64 N) {
  u32 sq = sqrtl(N);
  T ANS = 0;
  for (u32 d = 1; d <= sq; ++d) { ANS += N / d; }
  return 2 * ANS - u64(sq) * sq;
}

// https://oeis.org/A006218
// sigma0(1)+...+sigma0(N) = sum floor(N/i)
template <typename T = u64>
T sigma_0_sum_large(u64 N) {
  u32 sq = sqrtl(N);
  auto above = [&](u128 x, u128 y) -> bool { return y * (sq - x) > N; };
  auto slope = [&](u128 x, u128 a, u128 b) -> bool {
    x = sq - x;
    return a * x * x <= N * b;
  };
  T ANS = convex_floor_sum<u64, T>(sq, above, slope);
  return 2 * ANS - u64(sq) * sq;
}

template <typename T = u64>
T sigma_0_sum(u64 N) {
  return (N < (1e14) ? sigma_0_sum_small<T>(N) : sigma_0_sum_large<T>(N));
}
