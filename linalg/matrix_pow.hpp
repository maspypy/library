#include "linalg/matrix_mul.hpp"

template <typename T>
vc<vc<T>> matrix_pow(vc<vc<T>> A, ll n) {
  int N = len(A);
  vv(T, ret, N, N);
  FOR(i, N) ret[i][i] = T(1);
  while (n) {
    if (n & 1) ret = matrix_mul(ret, A, N, N, N);
    n /= 2;
    if (n) A = matrix_mul(A, A, N, N, N);
  }
  return ret;
}

template <typename T, int N>
array<array<T, N>, N> matrix_pow(array<array<T, N>, N> A, ll n) {
  array<array<T, N>, N> ret{};
  FOR(i, N) ret[i][i] = T(1);
  while (n) {
    if (n & 1) ret = matrix_mul<T, N>(ret, A);
    n /= 2;
    if (n) A = matrix_mul<T, N>(A, A);
  }
  return ret;
}