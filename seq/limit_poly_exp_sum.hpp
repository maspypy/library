#include "mod/modint.hpp"
template <typename mint>
mint limit_poly_exp_sum(vc<mint> a, mint r) {
  /*
  a[i] = (prefix sum of r^i * (polynomial of i)) となっているものの極限
  fps では (1-rx)^d(1-x) の形の分母を持つ場合ということになる
  f(x) = g(x) / (1-rx)^d + c / (1-x) として、c が答である
  */
  mint c = 0;
  int d = len(a) - 1;
  mint p = 1;
  FOR(i, d + 1) {
    c += a[d - i] * p * C<mint>(d, i);
    p *= -r;
  }
  c /= (mint(1) - r).pow(d);
  return c;
}
