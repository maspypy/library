
#include "poly/poly_taylor_shift.hpp"
#include "poly/partial_frac_decomposition_1.hpp"
#include "seq/famous/stirling_number_1.hpp"

// f(log(1-x))
template <typename mint>
vc<mint> composition_f_log_1_minus_x(vc<mint> f) {
  int N = len(f) - 1;
  FOR(i, N + 1) f[i] *= fact<mint>(i);
  vc<mint> S = stirling_number_1_n<mint>(N + 1, true);
  reverse(all(S));
  f = convolution<mint>(f, S);
  f.resize(N + 1);
  vc<mint> A(N + 1);
  FOR(i, N + 1) A[i] = mint::raw(i);
  f = partial_frac_decomposition_1(f, A);
  FOR(i, len(f)) if (i & 1) f[i] = -f[i];
  f = poly_taylor_shift<mint>(f, -1);
  return f;
}
