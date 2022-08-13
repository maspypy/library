#include "poly/convolution_all.hpp"
#include "poly/fps_log.hpp"
#include "poly/sum_of_rationals.hpp"

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

// sum ca^n を n=0,1,...,N で列挙
template <typename T>
vc<T> sum_of_powers_with_coef(const vc<T>& A, const vc<T>& C, int N) {
  using P = pair<vc<T>, vc<T>>;
  vc<P> dat;
  FOR(i, len(A)) { dat.eb(vc<T>({C[i]}), vc<T>({1, -A[i]})); }
  auto [num, den] = sum_of_rationals(dat);
  num.resize(N + 1);
  den.resize(N + 1);
  auto f = fps_inv(den);
  f = convolution(f, num);
  f.resize(N + 1);
  return f;
}