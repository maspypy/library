#include "linalg/spmat_min_poly.hpp"

template <typename T>
T spmat_det(int N, vc<tuple<int, int, T>> dat) {
  vc<T> c(N);
  FOR(i, N) c[i] = RNG(1, T::get_mod());
  T r = 1;
  FOR(i, N) r *= c[i];
  for (auto&& [i, j, x]: dat) x *= c[i];
  vc<T> f = spmat_min_poly(N, dat);
  T det = (len(f) == N + 1 ? f[0] : T(0));
  if (N & 1) det *= -1;
  det /= r;
  return det;
}
