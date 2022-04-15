#include "linalg/spmat_min_poly.hpp"

template <typename T>
T spmat_det(int N, vc<tuple<int, int, T>> dat) {
  RandomNumberGenerator RNG;
  vc<T> c(N);
  FOR(i, N) c[i] = RNG(1, T::get_mod());
  T r = 1;
  FOR(i, N) r *= c[i];
  for (auto&& [i, j, x]: dat) x *= c[i];
  auto f = spmat_min_poly(N, dat);
  f.resize(N + 1);
  T det = f.back();
  if (N & 1) det *= -1;
  det /= r;
  return det;
}
