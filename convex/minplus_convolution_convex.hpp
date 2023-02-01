#include "convex/smawk.hpp"

template <typename T, bool convA, bool convB>
vc<T> minplus_convolution_convex(vc<T> A, vc<T> B) {
  static_assert(convA || convB);
  if (!convB) swap(A, B);
  int NA = len(A), NB = len(B);
  int N = NA + NB - 1;
  int L = 0, R = NB;
  while (L < R && B[L] == infty<T>) ++L;
  if (L == R) return vc<T>(N, infty<T>);
  while (B[R - 1] == infty<T>) --R;
  B = {B.begin() + L, B.begin() + R};
  int nB = R - L;
  int n = NA + nB - 1;

  auto select = [&](int i, int j, int k) -> int {
    if (i < k) return j;
    if (i - j >= nB) return k;
    return (A[j] + B[i - j] > A[k] + B[i - k] ? k : j);
  };

  vc<int> J = SMAWK(n, NA, select);
  vc<T> C(N, infty<T>);
  FOR(i, n) C[L + i] = (A[J[i]] == infty<T> ? infty<T> : A[J[i]] + B[i - J[i]]);
  return C;
}
