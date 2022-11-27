#pragma once
#include "alg/monoid/add.hpp"

template <typename AbelGroup>
struct FenwickTree {
  using E = typename AbelGroup::value_type;
  int n;
  vector<E> dat;
  E total;

  FenwickTree(int n = 0) : n(n) {
    assert(AbelGroup::commute);
    reset(n);
  }
  FenwickTree(const vector<E>& v) {
    assert(AbelGroup::commute);
    build(v);
  }

  void build(const vc<E>& v) {
    n = len(v);
    total = AbelGroup::unit();
    for (int i = 0; i < n; ++i) total = AbelGroup::op(total, v[i]);
    dat = v;
    for (int i = 1; i <= n; ++i) {
      int j = i + (i & -i);
      if (j <= n) dat[j - 1] = AbelGroup::op(dat[i - 1], dat[j - 1]);
    }
  }

  void reset(int sz = 0) {
    if (sz) n = sz;
    total = AbelGroup::unit();
    dat.assign(n, AbelGroup::unit());
  }

  E prod(int k) {
    E ret = AbelGroup::unit();
    for (; k > 0; k -= k & -k) ret = AbelGroup::op(ret, dat[k - 1]);
    return ret;
  }

  E prod(int L, int R) {
    E pos = AbelGroup::unit();
    while (L < R) {
      pos = AbelGroup::op(pos, dat[R - 1]);
      R -= R & -R;
    }
    E neg = AbelGroup::unit();
    while (R < L) {
      neg = AbelGroup::op(neg, dat[L - 1]);
      L -= L & -L;
    }
    return AbelGroup::op(pos, AbelGroup::inverse(neg));
  }

  E prod_all() { return total; }

  E sum(int k) { return prod(k); }

  E sum(int L, int R) { return prod(L, R); }

  E sum_all() { return total; }

  void multiply(int k, E x) {
    total = AbelGroup::op(total, x);
    for (++k; k <= n; k += k & -k) dat[k - 1] = AbelGroup::op(dat[k - 1], x);
  }

  void add(int k, E x) { multiply(k, x); }

  template <class F>
  int max_right(F& check) {
    assert(check(E(0)));
    ll i = 0;
    E s = AbelGroup::unit();
    int k = 1;
    int N = dat.size() + 1;
    while (2 * k < N) k *= 2;
    while (k) {
      if (i + k < N && check(AbelGroup::op(s, dat[i + k - 1]))) {
        i += k;
        s = AbelGroup::op(s, dat[i - 1]);
      }
      k >>= 1;
    }
    return i;
  }

  int find_kth(E k) {
    auto check = [&](E x) -> bool { return x <= k; };
    return max_right(check);
  }

  void debug() { print("fenwick", dat); }
};
