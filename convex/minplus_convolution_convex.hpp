#include "convex/smawk.hpp"

template <typename T, bool convA, bool convB>
vc<T> minplus_convolution_convex(vc<T> A, vc<T> B, const T INF) {
  static_assert(convA || convB);
  assert(INF < INF + INF);
  if (!convB) swap(A, B);
  int NA = len(A), NB = len(B);
  int N = NA + NB - 1;
  int L = 0, R = NB;
  while (L < R && B[L] == INF) ++L;
  if (L == R) return vc<T>(N, INF);
  while (B[R - 1] == INF) --R;
  B = {B.begin() + L, B.begin() + R};
  int nB = R - L;
  int n = NA + nB - 1;

  auto select = [&](int i, int j, int k) -> bool {
    if (i < k) return false;
    if (i - j >= nB) return true;
    return A[j] + B[i - j] > A[k] + B[i - k];
  };

  vc<int> J = SMAWK(n, NA, select);
  vc<T> C(N, INF);
  FOR(i, n) C[L + i] = (A[J[i]] == INF ? INF : A[J[i]] + B[i - J[i]]);
  return C;
}
