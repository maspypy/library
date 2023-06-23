// [x^n]C(x)^pow
template <typename mint>
mint catalan_convolution(ll pow, ll n) {
  if (pow == 0) return (n == 0 ? mint(1) : mint(0));
  return mint(pow) * inv<mint>(n + n + pow) * C<mint>(n + n + pow, n);
}