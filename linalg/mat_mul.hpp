#pragma once

template <class T, is_modint_t<T>* = nullptr>
vc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {
  const int mod = T::get_mod();
  auto N = len(A), M = len(B), K = len(B[0]);
  vv(int, b, K, M);
  FOR(i, M) FOR(j, K) b[j][i] = B[i][j].val;
  vv(T, C, N, K);
  FOR(i, N) {
    FOR(j, K) {
      i128 sm = 0;
      FOR(m, M) { sm += ll(A[i][m].val) * b[j][m]; }
      C[i][j] = sm % mod;
    }
  }
  return C;
}

template <class T, is_not_modint_t<T>* = nullptr>
vc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {
  auto N = len(A), M = len(B), K = len(B[0]);
  vv(T, C, N, K);
  FOR(n, N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * B[m][k];
  return C;
}
