#include "alg/monoid/add.hpp"

// update O(1) / query O(sqrt N)
// b_sz は sqrt(N/2) が目安
template <typename AbelGroup, int b_sz = 256>
struct Point_Set_Range_Sum_Sqrt {
  using G = AbelGroup;
  static_assert(G::commute);
  using MX = AbelGroup;
  using E = typename G::value_type;
  int n, b_num;
  vc<E> A, B;
  E total;

  Point_Set_Range_Sum_Sqrt(int N = 0) { build(N); }
  template <typename F>
  Point_Set_Range_Sum_Sqrt(int N, F f) {
    build(N, f);
  }

  void build(int N) {
    build(N, [&](int i) -> E { return G::id(); });
  }
  void build(const vc<E> &v) {
    build(len(v), [&](int i) -> E { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m;
    b_num = ceil<int>(n, b_sz);
    A.assign(b_sz * b_num, G::id()), B.assign(b_num, G::id());
    FOR(i, n) A[i] = f(i);
    for (int l = 0, b = 0; b < b_num; ++b, l += b_sz) {
      E x = G::id();
      FOR(i, l, l + b_sz) x = G::op(x, A[i]);
      B[b] = x;
    }
    total = G::id();
    for (E x : B) total = G::op(total, x);
  }

  E prod_all() const { return total; }
  E sum_all() const { return total; }
  E sum(int k) const { return sum(0, k); }
  E prod(int k) const { return sum(0, k); }
  E sum(int L, int R) const { return prod(L, R); }
  E prod(int L, int R) const {
    assert(0 <= L && L <= R && R <= n);
    auto [b1, k1] = divmod<int>(L, b_sz);
    E add = G::id(), sub = G::id();
    if (k1 <= b_sz / 2) {
      FOR(i, b1 * b_sz, L) sub = G::op(sub, A[i]);
    } else {
      ++b1;
      FOR(i, L, b1 * b_sz) add = G::op(add, A[i]);
    }
    auto [b2, k2] = divmod<int>(R, b_sz);
    if (k2 <= b_sz / 2) {
      FOR(i, b2 * b_sz, R) add = G::op(add, A[i]);
    } else {
      ++b2;
      FOR(i, R, b2 * b_sz) sub = G::op(sub, A[i]);
    }
    // [b1,b2) を足す
    if (b2 - b1 <= b_num / 2) {
      FOR(b, b1, b2) add = G::op(add, B[b]);
    } else {
      add = G::op(add, total);
      FOR(b, b1) sub = G::op(sub, B[b]);
      FOR(b, b2, b_num) sub = G::op(sub, B[b]);
    }
    return G::op(add, G::inverse(sub));
  }

  void add(int k, E x) { multiply(k, x); }
  void multiply(int k, E x) {
    assert(0 <= k && k < n);
    total = G::op(total, x);
    A[k] = G::op(A[k], x), B[k / b_sz] = G::op(B[k / b_sz], x);
  }
  void set(int k, E x) {
    assert(0 <= k && k < n);
    x = G::op(x, G::inverse(A[k]));
    add(k, x);
  }
};