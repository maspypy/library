#pragma once
#include "mod/modint.hpp"

template <class T, typename enable_if<has_mod<T>::value>::type* = nullptr>
vc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {
  constexpr int mod = T::get_mod();
  auto N = len(A), M = len(B), K = len(B[0]);
  vv(int, b, K, M);
  FOR(i, M) FOR(j, K) b[j][i] = B[i][j].val;
  vv(T, C, N, K);

  if (M <= 16) {
    FOR(i, N) FOR(j, K) {
      u64 sm = 0;
      FOR(m, M) sm += u64(A[i][m].val) * b[j][m];
      C[i][j] = sm % mod;
    }
  } else {
    FOR(i, N) FOR(j, K) {
      i128 sm = 0;
      FOR(m, M) sm += ll(A[i][m].val) * b[j][m];
      C[i][j] = sm % mod;
    }
  }
  return C;
}

template <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>
vc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {
  auto N = len(A), M = len(B), K = len(B[0]);
  vv(T, b, K, M);
  FOR(i, M) FOR(j, K) b[j][i] = B[i][j];
  vv(T, C, N, K);
  FOR(n, N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * b[k][m];
  return C;
}
