#include "random/shuffle.hpp"

// return: +1,-1 の列
vc<int> random_bracket(int N) {
  vc<int> A(2 * N + 1);
  FOR(i, N + 1) A[i] = 1;
  FOR(i, N + 1, 2 * N + 1) A[i] = -1;
  shuffle(A);
  vc<int> B(2 * N + 2);
  FOR(i, 2 * N + 1) B[i + 1] = B[i] + A[i];
  int k = 0;
  FOR(i, 2 * N + 1) if (B[k] >= B[i]) k = i;
  rotate(A.begin(), A.begin() + k, A.end());
  return A;
}
