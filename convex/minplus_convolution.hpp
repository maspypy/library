#pragma once

template <typename T>
vc<T> minplus_convolution_convex_convex(vc<T>& A, vc<T>& B) {
  int n = len(A), m = len(B);
  if (n == 0 || m == 0) return {};
  vc<T> C(n + m - 1, infty<T>);
  while (n > 0 && A[n - 1] == infty<T>) --n;
  while (m > 0 && B[m - 1] == infty<T>) --m;
  if (n == 0 || m == 0) return C;
  int a = 0, b = 0;
  while (a < n && A[a] == infty<T>) ++a;
  while (b < m && B[b] == infty<T>) ++b;
  C[a + b] = A[a] + B[b];
  for (int i = a + b + 1; i < n + m - 1; ++i) {
    if (b == m - 1 || (a != n - 1 && A[a + 1] + B[b] < A[a] + B[b + 1])) {
      chmin(C[i], A[++a] + B[b]);
    } else {
      chmin(C[i], A[a] + B[++b]);
    }
  }
  return C;
}

template <typename T>
vc<T> minplus_convolution_arbitrary_convex(vc<T>& A, vc<T>& B) {
  int n = len(A), m0 = len(B);
  if (n == 0 || m0 == 0) return {};
  vc<T> C(n + m0 - 1, infty<T>);
  int m = m0;
  while (m > 0 && B[m - 1] == infty<T>) --m;
  if (m == 0) return C;
  int b = 0;
  while (b < m && B[b] == infty<T>) ++b;

  int z = n + m - b - 1;
  vc<int> idx(z + 1);
  C[b] = A[0] + B[b];
  idx[0] = 0, idx[z] = n - 1;

  int d = 1;
  while (d < z) d <<= 1;
  for (int q = d >> 1; q > 0; q >>= 1) {
    for (int h = q; h < z; h += q << 1) {
      int l = h - q;
      int r = min(h + q, z);
      idx[h] = idx[l];
      for (int j = idx[l]; j <= idx[r]; ++j) {
        if (j <= h && h - j < m - b && C[b + h] >= A[j] + B[b + h - j]) {
          C[b + h] = A[j] + B[b + h - j];
          idx[h] = j;
        }
      }
    }
  }
  return C;
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
