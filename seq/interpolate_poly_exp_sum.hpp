#include "poly/lagrange_interpolate_iota.hpp"
#include "seq/interpolate_poly_exp.hpp"

template <typename mint>
mint interpolate_poly_exp_sum(vc<mint> a, mint r, ll n) {
  /*
  a[i] = (prefix sum of r^i * (polynomial of i)) となっている場合の補間
  fps では (1-rx)^d(1-x) の形の分母を持つ場合ということになる
  f(x) = g(x) / (1-rx)^d + c / (1-x) として、c が知りたい
  (1-rx)^d をかけて、d 次の係数をとれば、c が手に入る
  */
  if (r == mint(1)) return lagrange_interpolate_iota(a, mint(n));
  mint c = 0;
  int d = len(a) - 1;
  mint p = 1;
  FOR(i, d + 1) {
    c += a[d - i] * p * C<mint>(d, i);
    p *= -r;
  }
  c /= (mint(1) - r).pow(d);
  for (auto&& x: a) x -= c;
  return interpolate_poly_exp(a, r, n) + c;
}
