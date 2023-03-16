
// https://oeis.org/A000272
template <typename mint>
vc<mint> count_tree(ll nmax) {
  vc<mint> f(nmax + 1);
  FOR(n, 1, nmax + 1) { f[n] = (n == 1 ? mint(1) : mint(n).pow(n - 2)); }
  return f;
}