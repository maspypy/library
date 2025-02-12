
// sum_{i=0}^{n-1}r^i
template <typename T>
T geometric_sequence_sum(T r, ll n) {
  if (n == 0) return T(0);
  // (r^n, 1+...+r^{n-1})
  auto dfs = [&](auto& dfs, ll n) -> pair<T, T> {
    if (n == 1) return {r, 1};
    auto [x, y] = dfs(dfs, n / 2);
    tie(x, y) = mp(x * x, x * y + y);
    if (n % 2 == 0) return {x, y};
    return {x * r, y + x};
  };
  return dfs(dfs, n).se;
}

// sum_{i=0}^{n-1}i^kr^i を k=0,1,...,K
template <typename T, int K>
array<T, K + 1> geometric_sequence_sum_K(T r, ll n) {
  array<array<T, K + 1>, K + 1> comb{};
  comb[0][0] = 1;
  FOR(i, K) {
    FOR(j, i + 1) { comb[i + 1][j] += comb[i][j], comb[i + 1][j + 1] += comb[i][j]; }
  }

  // (n, r^n, sum i^kr^i)
  using X = tuple<T, T, array<T, K + 1>>;
  auto mul = [&](X& l, X& r) -> X {
    auto& [n1, r1, A] = l;
    auto& [n2, r2, B] = r;
    array<T, K + 1> C;
    FOR(k, K + 1) {
      C[k] = A[k];
      T c = r1;
      FOR(j, k + 1) { C[k] += comb[k][j] * c * B[k - j], c *= n1; }
    }
    return {n1 + n2, r1 * r2, C};
  };

  X res = {T(0), T(1), array<T, K + 1>{}};
  X a = {T(1), T(r), array<T, K + 1>{}};
  get<2>(a)[0] = 1;

  while (n) {
    if (n & 1) res = mul(res, a);
    a = mul(a, a), n /= 2;
  }
  return get<2>(res);
}
