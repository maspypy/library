#include "ds/fenwicktree/fenwicktree.hpp"

template <typename T, bool SMALL>
ll inversion(vc<T> A) {
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
