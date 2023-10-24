#pragma once
#include "mod/modint.hpp"

template <class T, typename enable_if<has_mod<T>::value>::type* = nullptr>
vc<vc<T>> matrix_mul(const vc<vc<T>>& A, const vc<vc<T>>& B, int N1 = -1,
                     int N2 = -1, int N3 = -1) {
  if (N1 == -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }
  vv(u32, b, N2, N3);
  FOR(i, N2) FOR(j, N3) b[j][i] = B[i][j].val;
  vv(T, C, N1, N3);

  if ((T::get_mod() < (1 << 30)) && N2 <= 16) {
    FOR(i, N1) FOR(j, N3) {
      u64 sm = 0;
      FOR(m, N2) sm += u64(A[i][m].val) * b[j][m];
      C[i][j] = sm;
    }
  } else {
    FOR(i, N1) FOR(j, N3) {
      u128 sm = 0;
      FOR(m, N2) sm += u64(A[i][m].val) * b[j][m];
      C[i][j] = T::raw(sm % (T::get_mod()));
    }
  }
  return C;
}

template <class T, typename enable_if<!has_mod<T>::value>::type* = nullptr>
vc<vc<T>> matrix_mul(const vc<vc<T>>& A, const vc<vc<T>>& B, int N1 = -1,
                     int N2 = -1, int N3 = -1) {
  if (N1 == -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }
  vv(T, b, N2, N3);
  FOR(i, N2) FOR(j, N3) b[j][i] = B[i][j];
  vv(T, C, N1, N3);
  FOR(n, N1) FOR(m, N2) FOR(k, N3) C[n][k] += A[n][m] * b[k][m];
  return C;
}
