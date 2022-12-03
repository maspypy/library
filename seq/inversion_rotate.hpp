#include "ds/fenwicktree/fenwicktree.hpp"

// i 番目：A_i が先頭になるように rotate したときの転倒数
template <typename T>
vi inversion_rotate(vc<T>& A, bool SMALL = false) {
  const int N = len(A);
  if (!SMALL) {
    auto key = A;
    UNIQUE(key);
    for (auto&& x: A) x = LB(key, x);
  }
  ll K = MAX(A) + 1;
  ll ANS = 0;
  FenwickTree<Monoid_Add<int>> bit(K);
  for (auto&& x: A) {
    ANS += bit.sum(x + 1, K);
    bit.add(x, 1);
  }
  vi res(N);
  FOR(i, N) {
    res[i] = ANS;
    ll x = A[i];
    ANS = ANS + bit.sum(x + 1, K) - bit.prefix_sum(x);
  }
  return res;
}
