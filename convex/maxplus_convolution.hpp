#include "convex/monotone_minima.hpp"

template <typename T>
vc<T> maxplus_convolution_concave_concave(vc<T>& A, vc<T>& B) {
  int n = len(A), m = len(B);
  if (n == 0 && m == 0) return {};
  vc<T> C(n + m - 1, -infty<T>);
  while (n > 0 && A[n - 1] == -infty<T>) --n;
  while (m > 0 && B[m - 1] == -infty<T>) --m;
  if (n == 0 && m == 0) return C;
  int a = 0, b = 0;
  while (a < n && A[a] == -infty<T>) ++a;
  while (b < m && B[b] == -infty<T>) ++b;
  C[a + b] = A[a] + B[b];
  for (int i = a + b + 1; i < n + m - 1; ++i) {
    if (b == m - 1 || (a != n - 1 && A[a + 1] + B[b] > A[a] + B[b + 1])) {
      chmax(C[i], A[++a] + B[b]);
    } else {
      chmax(C[i], A[a] + B[++b]);
    }
  }
  return C;
}

template <typename T>
vc<T> maxplus_convolution_arbitrary_concave(vc<T>& A, vc<T>& B) {
  int n = len(A), m = len(B);
  if (n == 0 && m == 0) return {};
  vc<T> C(n + m - 1, -infty<T>);
  while (m > 0 && B[m - 1] == -infty<T>) --m;
  if (m == 0) return C;
  int b = 0;
  while (b < m && B[b] == -infty<T>) ++b;

  auto select = [&](int i, int j, int k) -> bool {
    if (i < k) return false;
    if (i - j >= m - b) return true;
    return A[j] + B[b + i - j] <= A[k] + B[b + i - k];
  };
  vc<int> J = monotone_minima(n + m - b - 1, n, select);
  FOR(i, n + m - b - 1) {
    T x = A[J[i]], y = B[b + i - J[i]];
    if (x > -infty<T> && y > -infty<T>) C[b + i] = x + y;
  }
  return C;
}

template <typename T, bool conA, bool conB>
vc<T> maxplus_convolution(vc<T>& A, vc<T>& B) {
  static_assert(conA || conB);
  if constexpr (conA && conB) return maxplus_convolution_concave_concave(A, B);
  if constexpr (conA && !conB)
    return maxplus_convolution_arbitrary_concave(B, A);
  if constexpr (conB && !conA)
    return maxplus_convolution_arbitrary_concave(A, B);
  return {};
}
