#include "ds/fenwick/fenwick.hpp"
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

  E prod(ll L, ll R) {
    E prod_R = AbelGroup::op(AbelGroup::power(bit1.prod(R), R), bit0.prod(R));
    E prod_L = AbelGroup::op(AbelGroup::power(bit1.prod(L), L), bit0.prod(L));
    return AbelGroup::op(AbelGroup::inverse(prod_L), prod_R);
  }
};
