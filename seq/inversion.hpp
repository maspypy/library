#include "ds/fenwick/fenwick.hpp"

template <typename T>
ll inversion(vc<T> A, bool SMALL = false) {
  if (!SMALL) {
    auto key = A;
    UNIQUE(key);
    for (auto&& x: A) x = LB(key, x);
  }
  ll ANS = 0;
  ll K = MAX(A) + 1;
  FenwickTree<Monoid_Add<int>> bit(K);
  for (auto&& x: A) {
    ANS += bit.sum(x + 1, K);
    bit.add(x, 1);
  }
  return ANS;
}
