#include "ds/fenwicktree/fenwicktree.hpp"

// 右にある小さいやつの個数 [2,0,3,1] → [2,0,1,0]
vc<int> to_factorial_digit_system(vc<int>& A) {
  int N = len(A);
  for (auto&& x: A) assert(0 <= x && x < N);
  FenwickTree<Monoid_Add<int>> bit(N);
  vc<int> B(N);
  FOR_R(i, N) B[i] = bit.sum(0, A[i]), bit.add(A[i], 1);
  return B;
}

// 右にある小さいやつの個数 [2,0,1,0] → [2,0,3,1]
vc<int> from_factorial_digit_system(vc<int>& A) {
  int N = len(A);
  for (auto&& x: A) assert(0 <= x && x < N);
  vc<int> ANS(N);
  FenwickTree<Monoid_Add<int>> bit(N, [&](int i) -> int { return 1; });
  FOR(i, N) {
    ANS[i] = bit.kth(A[i]);
    bit.add(ANS[i], -1);
  }
  return ANS;
}