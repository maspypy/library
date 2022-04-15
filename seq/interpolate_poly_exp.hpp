template <typename mint>
mint interpolate_poly_exp(vc<mint> a, mint r, ll n) {
  // a[i] = r^i * (polynomial of i) となっている場合の補間
  if (r == 0) return (n == 0 ? a[0] : 0);
  mint inv_r = mint(1) / r;
  mint p = 1;
  for (auto&& x: a) {
    x *= p;
    p *= inv_r;
  }
  return lagrange_interpolate_iota(a, mint(n)) * r.pow(n);
}
