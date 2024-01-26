#include "mod/floor_sum_of_linear.hpp"

// sum_{x in [L,R)} floor(ax + b, mod)
// I は範囲内で ax+b がオーバーフローしない程度
template <typename O = i128, typename I = long long>
I range_freq_of_linear(I L, I R, I a, I b, I mod, I lo, I hi) {
  if (lo >= hi) return 0;
  assert(0 <= lo && lo < hi && hi <= mod);

  O x1 = floor_sum_of_linear<O, I>(L, R, a, b - lo, mod);
  O x2 = floor_sum_of_linear<O, I>(L, R, a, b - hi, mod);
  return x1 - x2;
}
