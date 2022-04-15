#include "ds/fenwick.hpp"

template <typename T>
ll inversion(vc<T>& A) {
  auto key = A;
  UNIQUE(key);
  ll ANS = 0;
  FenwickTree<Group_Add<int>> bit(len(key));
  for (auto&& a: A) {
    ll x = LB(key, a);
    ANS += bit.sum_all() - bit.sum(x + 1);
    bit.add(x, 1);
  }
  return ANS;
}
