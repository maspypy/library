
// https://qoj.ac/problem/5
// precompute O(p^{2/3}), query O(1)
// 10^8 query: 3sec
template <typename mint>
mint O1_inverse(int a) {
  /*
  n^3>=p となるように n をとり, n^2までは前計算.
  a/p を有理数近似する x/y. |a/p-x/y|<=|1/ny となると
  |ay-px|<=p/n<=n^2 より(ay)^{-1}が前計算されているのでできる.

  x/y は分母 n 未満の Farey 数列の前後どちらかが満たす.
  n^2 bucket に分割しておくと bucket ごとの有理数は distinct.
  前後のうち良い方を選べばよい.
  */
  static int p = 0;
  static double cp = 0.0;
  static vc<int> FRAC;
  static vc<mint> invs;
  if (p != mint::get_mod()) {
    p = mint::get_mod();
    int k = min(2 << 20, p);
    invs.resize(k);
    invs[1] = 1;
    FOR(i, 2, k) {
      int q = (p + i - 1) / i;
      invs[i] = invs[i * q - p] * mint::raw(q);
    }
    assert(p <= (1 << 30));
    FRAC.assign(1 << 20, -1);
    cp = 1.0 * (1 << 20) / p;
    for (int y = 1023; y >= 1; --y) {
      for (int x = 0; x < y; ++x) { FRAC[(x << 20) / y] = {x << 10 | y}; }
    }
    FOR(i, 1, len(FRAC)) if (FRAC[i] == -1) FRAC[i] = FRAC[i - 1];
    int nxt = 1025;
    FOR_R(i, 1, len(FRAC)) {
      if (FRAC[i] != FRAC[i - 1]) {
        nxt = FRAC[i];
        continue;
      }
      int x1 = FRAC[i] >> 10, y1 = FRAC[i] & 1023;
      int x2 = nxt >> 10, y2 = nxt & 1023;
      int c1 = i * y1 - (x1 << 20);
      int c2 = i * y2 - (x2 << 20);
      if (abs(c2) < abs(c1)) FRAC[i] = nxt;
    }
  }
  assert(0 <= a && a < p);
  if (a < len(invs)) return invs[a];

  int k = a * cp;
  ll x = FRAC[k] >> 10, y = FRAC[k] & 1023;
  int c = ll(a) * y - ll(p) * x;
  if (c < 0) c = -c, y = -y;
  return invs[c] * mint(y);
}
