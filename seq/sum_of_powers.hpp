#include "poly/convolution_all.hpp"
#include "poly/fps_log.hpp"

// sum_{a in A} a^n を、n = 0, 1, ..., N で列挙
template <typename T>
vc<T> sum_of_powers(const vc<T>& A, ll N) {
  vvc<T> polys;
  for (auto&& a: A) polys.eb(vc<T>({T(1), -a}));
  auto f = convolution_all(polys);
  f.resize(N + 1);
  f = fps_log(f);
  FOR(i, len(f)) f[i] = -f[i] * T(i);
  f[0] = len(A);
  return f;
}
