#include "ds/fenwick.hpp"
template <typename AbelGroup>
struct FenwickRAQ {
  using E = typename AbelGroup::value_type;
  int n;
  FenwickTree<AbelGroup> bit0;
  FenwickTree<AbelGroup> bit1;

  FenwickRAQ() : FenwickRAQ(0) {}
  FenwickRAQ(int n) : n(n), bit0(n), bit1(n) {}
  FenwickRAQ(vc<E> v) : n(len(v)), bit0(v), bit1(len(v)) {}

  void add(ll i, E val) { bit0.add(i, val); }

  void add(ll L, ll R, E val) {
    bit0.add(L, AbelGroup::power(val, -L));
    bit0.add(R, AbelGroup::power(val, R));
    bit1.add(L, val);
    bit1.add(R, AbelGroup::inverse(val));
  }

  E sum(ll L, ll R) {
    E sum_R = AbelGroup::op(AbelGroup::power(bit1.sum(R), R), bit0.sum(R));
    E sum_L = AbelGroup::op(AbelGroup::power(bit1.sum(L), L), bit0.sum(L));
    return AbelGroup::op(AbelGroup::inverse(sum_L), sum_R);
  }
};
