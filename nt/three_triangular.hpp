#include "nt/three_square.hpp"

// 3 つの x(x-1)/2 の和にする
tuple<ll, ll, ll> three_triangular(ll N) {
  auto [a, b, c] = three_square(8 * N + 3);
  a = (a + 1) / 2;
  b = (b + 1) / 2;
  c = (c + 1) / 2;
  return {a, b, c};
}
