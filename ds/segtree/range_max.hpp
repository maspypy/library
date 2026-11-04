// Source: https://github.com/maspypy/library/blob/main/ds/segtree/range_max.hpp
#include "ds/segtree/range_min.hpp"

template <typename T>
struct Range_Max {
  static_assert(is_same_v<T, int> || is_same_v<T, ll>);
  using value_type = T;

  Range_Min<T> seg;

  Range_Max() {}
  Range_Max(int n) { build(n); }
  Range_Max(const vc<T>& a) { build(a); }

  template <typename F>
  Range_Max(int n, F f) {
    build(n, f);
  }

  void build(int n) { seg.build(n); }

  void build(const vc<T>& a) {
    build(len(a), [&](int i) -> T { return a[i]; });
  }

  template <typename F>
  void build(int n, F f) {
    seg.build(n, [&](int i) -> T { return -f(i); });
  }

  T get(int i) const { return -seg.get(i); }

  vc<T> get_all() const {
    auto a = seg.get_all();
    for (auto& x : a) x = -x;
    return a;
  }

  void set(int i, const T& x) { seg.set(i, -x); }

  void multiply(int i, const T& x) { seg.multiply(i, -x); }

  T prod(int l, int r) const { return -seg.prod(l, r); }

  T prod_all() const { return -seg.prod_all(); }

  template <typename F>
  int max_right(F check, int L) const {
    return seg.max_right([&](T x) { return check(-x); }, L);
  }

  template <typename F>
  int min_left(F check, int R) const {
    return seg.min_left([&](T x) { return check(-x); }, R);
  }
};
