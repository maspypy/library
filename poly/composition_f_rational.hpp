#include "poly/composition_f_polynomial_1.hpp"
#include "poly/fps_pow.hpp"

// f((a+bx)/(c+dx))
// only_numerator = true
//    -> (c+dx)^N f((a+bx)/(c+dx)) = sum f[i](a+bx)^i(c+dx)^{N-i}
template <typename mint, bool only_numerator>
vc<mint> composition_f_rational_1(vc<mint> f, mint a, mint b, mint c, mint d) {
  int N = len(f) - 1;

  if constexpr (!only_numerator) {
    assert(c != mint(0));
    vc<mint> F = composition_f_rational_1<mint, true>(f, a, b, c, d);
    d /= c;
    c = c.inverse().pow(N);
    // c(1+dx)^{-N}
    vc<mint> g = {1, d};
    g.resize(N + 1);
    g = fps_pow_1_sparse<mint>(g, -N);
    F = convolution(F, g);
    F.resize(N + 1);
    FOR(i, N + 1) F[i] *= c;
    return F;
  }

  if (mint(d) == 0) {
    mint pow_c = 1;
    FOR_R(i, N + 1) f[i] *= pow_c, pow_c *= c;
    return composition_f_polynomial_1<mint>(f, a, b);
  }
  // t = c+dx
  a = (a * d - b * c) / d, b = b / d;
  // sum f[i] (a+bt)^i t^{N-i}
  f = composition_f_polynomial_1(f, b, a);
  reverse(all(f));
  return composition_f_polynomial_1(f, c, d);
}