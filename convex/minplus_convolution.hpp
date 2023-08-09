#include "convex/monotone_minima.hpp"

template <typename T>
vc<T> minplus_convolution_convex_convex(vc<T>& A, vc<T>& B) {
  const int n = len(A), m = len(B);
  if (n == 0 && m == 0) return {};
  vc<T> C(n + m - 1);
  int a = 0, b = 0;
  C[0] = A[0] + B[0];
  for (int i = 1; i < n + m - 1; ++i) {
    if (b == m - 1 || (a != n - 1 && A[a + 1] + B[b] < A[a] + B[b + 1])) {
      C[i] = A[++a] + B[b];
    } else {
      C[i] = A[a] + B[++b];
    }
  }
  return C;
}

template <typename T>
vc<T> minplus_convolution_arbitrary_convex(vc<T>& a, vc<T>& b) {
  int n = len(a), m = len(b);
  auto select = [&](int i, int j, int k) -> bool {
    if (i < k) return false;
    if (i - j >= m) return true;
    return a[j] + b[i - j] >= a[k] + b[i - k];
  };
  vc<int> J = smawk(n + m - 1, n, select);
  // vc<int> J = monotone_minima(n + m - 1, n, select);
  vc<T> c(n + m - 1);
  FOR(i, n + m - 1) c[i] = a[J[i]] + b[i - J[i]];
  return c;
}

template <typename T, bool convA, bool convB>
vc<T> minplus_convolution(vc<T>& A, vc<T>& B) {
  static_assert(convA || convB);
  if constexpr (convA && convB) return minplus_convolution_convex_convex(A, B);
  if constexpr (convA && !convB)
    return minplus_convolution_arbitrary_convex(B, A);
  if constexpr (convB && !convA)
    return minplus_convolution_arbitrary_convex(A, B);
  return {};
}
