#pragma once
#include "alg/monoid/add.hpp"

template <typename Monoid>
struct Fenwick_Tree {
  static_assert(G::commute);
  using G = Monoid;
  using E = typename G::value_type;
  int n;
  vector<E> dat;
  E total;

  Fenwick_Tree() {}
  Fenwick_Tree(int n) { build(n); }
  template <typename F>
  Fenwick_Tree(int n, F f) {
    build(n, f);
  }
  Fenwick_Tree(const vc<X>& v) { build(v); }

  void build(int m) {
    dat.assign(m, G::unit());
    total = G::unit();
  }
  void build(const vc<X>& v) {
    build(len(v), [&](int i) -> X { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m;
    dat.clear();
    dat.reserve(n);
    total = G::unit();
    FOR(i, n) { dat.eb(f(i)); }
    for (int i = 1; i <= n; ++i) {
      int j = i + (i & -i);
      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j - 1]);
    }
    total = sum(m);
  }

  E prod_all() { return total; }
  E sum_all() { return total; }
  E prefix_sum(int k) { return prefix_prod(k); }
  E prefix_prod(int k) {
    E ret = G::unit();
    for (; k > 0; k -= k & -k) ret = G::op(ret, dat[k - 1]);
    return ret;
  }
  E sum(int L, int R) { return prod(L, R); }
  E prod(int L, int R) {
    if (L == 0) return prod(R);
    E pos = G::unit(), neg = G::unit();
    while (L < R) { pos = G::op(pos, dat[R - 1]), R -= R & -R; }
    while (R < L) { neg = G::op(neg, dat[L - 1]), L -= L & -L; }
    return G::op(pos, G::inverse(neg));
  }

  void add(int k, E x) { multiply(k, x); }
  void multiply(int k, E x) {
    total = G::op(total, x);
    for (++k; k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);
  }

  template <class F>
  int max_right(const F check) {
    assert(check(G::unit()));
    int i = 0;
    E s = G::unit();
    int k = 1;
    while (2 * k <= n) k *= 2;
    while (k) {
      E t = G::op(s, dat[i + k - 1]);
      if (check(t)) { i += k, s = t; }
      k >>= 1;
    }
    return i;
  }

  int find_kth(E k) {
    return max_right([](E x) -> bool { return x <= k; });
  }
};
