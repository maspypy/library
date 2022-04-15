#include "poly/poly_taylor_shift.hpp"
template <typename mint>
vc<mint> stirling_number_1(int n) {
  // x(x-1)...(x-n+1) の係数 s(n, k)
  // 分割統治 + taylor shift で O(nlogn) 時間
  if (n == 0) return {1};
  if (n == 1) return {0, 1};
  auto f = stirling_number_1<mint>(n / 2);
  auto g = poly_taylor_shift(f, -mint(n / 2));
  f = convolution(f, g);
  if (n & 1) {
    g = {-(n - 1), 1};
    f = convolution(f, g);
  }
  return f;
}
