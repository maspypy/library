#pragma once
#include "alg/monoid/add.hpp"

template <typename Monoid>
struct FenwickTree {
  using G = Monoid;
  using MX = Monoid;
  using E = typename G::value_type;
  int n;
  vector<E> dat;
  E total;

  FenwickTree() {}
  FenwickTree(int n) { build(n); }
  template <typename F>
  FenwickTree(int n, F f) {
    build(n, f);
  }
  FenwickTree(const vc<E>& v) { build(v); }

  void build(int m) {
    n = m;
    dat.assign(m, G::unit());
    total = G::unit();
  }
  void build(const vc<E>& v) {
    build(len(v), [&](int i) -> E { return v[i]; });
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
    total = prefix_sum(m);
  }

  E prod_all() { return total; }
  E sum_all() { return total; }
  E sum(int k) { return prefix_sum(k); }
  E prod(int k) { return prefix_prod(k); }
  E prefix_sum(int k) { return prefix_prod(k); }
  E prefix_prod(int k) {
    chmin(k, n);
    E ret = G::unit();
    for (; k > 0; k -= k & -k) ret = G::op(ret, dat[k - 1]);
    return ret;
  }
  E sum(int L, int R) { return prod(L, R); }
  E prod(int L, int R) {
    chmax(L, 0), chmin(R, n);
    if (L == 0) return prefix_prod(R);
    assert(0 <= L && L <= R && R <= n);
    E pos = G::unit(), neg = G::unit();
    while (L < R) { pos = G::op(pos, dat[R - 1]), R -= R & -R; }
    while (R < L) { neg = G::op(neg, dat[L - 1]), L -= L & -L; }
    return G::op(pos, G::inverse(neg));
  }

  vc<E> get_all() {
    vc<E> res(n);
    FOR(i, n) res[i] = prod(i, i + 1);
    return res;
  }

  void add(int k, E x) { multiply(k, x); }
  void multiply(int k, E x) {
    static_assert(G::commute);
    total = G::op(total, x);
    for (++k; k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);
  }
  void set(int k, E x) { add(k, G::op(G::inverse(prod(k, k + 1)), x)); }

  template <class F>
  int max_right(const F check, int L = 0) {
    assert(check(G::unit()));
    E s = G::unit();
    int i = L;
    // 2^k 進むとダメ
    int k = [&]() {
      while (1) {
        if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i - 1])), i -= 1; }
        if (i == 0) { return topbit(n) + 1; }
        int k = lowbit(i) - 1;
        if (i + (1 << k) > n) return k;
        E t = G::op(s, dat[i + (1 << k) - 1]);
        if (!check(t)) { return k; }
        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;
      }
    }();
    while (k) {
      --k;
      if (i + (1 << k) - 1 < len(dat)) {
        E t = G::op(s, dat[i + (1 << k) - 1]);
        if (check(t)) { i += (1 << k), s = t; }
      }
    }
    return i;
  }

  // check(i, x)
  template <class F>
  int max_right_with_index(const F check, int L = 0) {
    assert(check(L, G::unit()));
    E s = G::unit();
    int i = L;
    // 2^k 進むとダメ
    int k = [&]() {
      while (1) {
        if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i - 1])), i -= 1; }
        if (i == 0) { return topbit(n) + 1; }
        int k = lowbit(i) - 1;
        if (i + (1 << k) > n) return k;
        E t = G::op(s, dat[i + (1 << k) - 1]);
        if (!check(i + (1 << k), t)) { return k; }
        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;
      }
    }();
    while (k) {
      --k;
      if (i + (1 << k) - 1 < len(dat)) {
        E t = G::op(s, dat[i + (1 << k) - 1]);
        if (check(i + (1 << k), t)) { i += (1 << k), s = t; }
      }
    }
    return i;
  }

  template <class F>
  int min_left(const F check, int R) {
    assert(check(G::unit()));
    E s = G::unit();
    int i = R;
    // false になるところまで戻る
    int k = 0;
    while (i > 0 && check(s)) {
      s = G::op(s, dat[i - 1]);
      k = lowbit(i);
      i -= i & -i;
    }
    if (check(s)) {
      assert(i == 0);
      return 0;
    }
    // 2^k 進むと ok になる
    // false を維持して進む
    while (k) {
      --k;
      E t = G::op(s, G::inverse(dat[i + (1 << k) - 1]));
      if (!check(t)) { i += (1 << k), s = t; }
    }
    return i + 1;
  }

  int kth(E k, int L = 0) {
    return max_right([&k](E x) -> bool { return x <= k; }, L);
  }
};
