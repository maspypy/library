#pragma once
#include "mod/modint.hpp"

template <class T, typename enable_if<has_mod<T>::value>::type* = nullptr>
vc<vc<T>> matrix_mul(const vc<vc<T>>& A, const vc<vc<T>>& B, int N1 = -1,
                     int N2 = -1, int N3 = -1) {
  if (N1 == -1) { N1 = len(A), N2 = len(B), N3 = len(B[0]); }
  vv(u32, b, N3, N2);
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

// square-matrix defined as array
template <class T, int N,
          typename enable_if<has_mod<T>::value>::type* = nullptr>
array<array<T, N>, N> matrix_mul(const array<array<T, N>, N>& A,
                                 const array<array<T, N>, N>& B) {
  array<array<T, N>, N> C{};

  if ((T::get_mod() < (1 << 30)) && N <= 16) {
    FOR(i, N) FOR(k, N) {
      u64 sm = 0;
      FOR(j, N) sm += u64(A[i][j].val) * (B[j][k].val);
      C[i][k] = sm;
    }
  } else {
    FOR(i, N) FOR(k, N) {
      u128 sm = 0;
      FOR(j, N) sm += u64(A[i][j].val) * (B[j][k].val);
      C[i][k] = sm;
    }
  }
  return C;
}

// square-matrix defined as array
template <class T, int N,
          typename enable_if<!has_mod<T>::value>::type* = nullptr>
array<array<T, N>, N> matrix_mul(const array<array<T, N>, N>& A,
                                 const array<array<T, N>, N>& B) {
  array<array<T, N>, N> C{};
  FOR(i, N) FOR(j, N) FOR(k, N) C[i][k] += A[i][j] * B[j][k];
  return C;
}
