template <int MAX_N, typename T = bool>
vvc<T> mat_inv_bitset(vvc<T> a) {
  const int N = len(a);
  using BS = bitset<MAX_N>;
  vc<BS> A(N), B(N);
  FOR(i, N) FOR(j, N) if (a[i][j]) A[i][j] = 1;
  FOR(n, N) B[n][n] = 1;
  FOR(i, N) {
    FOR(k, i, N) if (A[k][i]) {
      if (k != i) { swap(A[i], A[k]), swap(B[i], B[k]); }
      break;
    }
    if (!A[i][i]) return {};
    FOR(k, N) if (i != k) {
      if (!A[k][i]) continue;
      A[k] ^= A[i];
      B[k] ^= B[i];
    }
  }
  vv(T, b, N, N);
  FOR(i, N) FOR(j, N) if (B[i][j]) b[i][j] = 1;
  return b;
}
