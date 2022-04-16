template<typename mint>
mint count_surjection(ll n, ll m) {
  if (n < m) return 0;
  mint res = 0;
  FOR(i, m + 1) {
    mint sgn = ((m - i) & 1 ? -1 : 1);
    res += mint(i).pow(n) * C<mint>(m, i) * sgn;
  }
  return res;
}