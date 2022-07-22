#include "mod/floor_sum_of_linear.hpp"

// L <= x < R のうちで、(ax+b mod) in [lo, hi) となるものの個数
ll range_freq_of_linear(ll L, ll R, ll a, ll b, ll mod, ll lo, ll hi) {
  if (lo >= hi) return 0;
  assert(0 <= lo && lo < hi && hi <= mod);

  i128 x1 = floor_sum_of_linear(L, R, a, b - lo, mod);
  i128 x2 = floor_sum_of_linear(L, R, a, b - hi, mod);
  return x1 - x2;
}
