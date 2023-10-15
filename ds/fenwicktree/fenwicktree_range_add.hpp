
#include "ds/fenwicktree/fenwicktree.hpp"

// 遅延セグ木より 4 ～ 5 倍高速？
// https://maspypy.github.io/library/test/mytest/fenwick_raq.test.cpp
// https://codeforces.com/contest/860/submission/228355081
template <typename AbelGroup>
struct FenwickTree_Range_Add {
  using G = AbelGroup;
  using E = typename AbelGroup::value_type;
  int n;
  FenwickTree<G> bit0;
  FenwickTree<G> bit1;

  FenwickTree_Range_Add() {}
  FenwickTree_Range_Add(int n) { build(n); }
  template <typename F>
  FenwickTree_Range_Add(int n, F f) {
    build(n, f);
  }
  FenwickTree_Range_Add(const vc<E>& v) { build(v); }

  void build(int m) {
    n = m;
    bit0.build(n), bit1.build(n);
  }
  void build(const vc<E>& v) {
    build(len(v), [&](int i) -> E { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m;
    bit0.build(m, f);
    bit1.build(m);
  }

  void add_at(int i, E val) { bit0.add(i, val); }

  void add(int L, int R, E val) {
    bit0.add(L, G::power(val, -L));
    bit0.add(R, G::power(val, R));
    bit1.add(L, val);
    bit1.add(R, G::inverse(val));
  }

  E prod(int L, int R) {
    E prod_R = G::op(G::power(bit1.prod(R), R), bit0.prod(R));
    E prod_L = G::op(G::power(bit1.prod(L), L), bit0.prod(L));
    return G::op(G::inverse(prod_L), prod_R);
  }
};