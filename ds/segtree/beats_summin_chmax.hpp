#include "ds/segtree/segtree_beats.hpp"
template <typename T>
struct Beats_SumMin_Chmax {
  static constexpr T INF = numeric_limits<T>::max() / 2 - 1;
  struct SumMin {
    struct X {
      T sum, min, minc, min2;
      bool fail;
    };
    using value_type = X;
    static X op(const X& x, const X& y) {
      if (x.min == INF) return y;
      if (y.min == -INF) return x;
      X z;
      z.sum = x.sum + y.sum;

      z.min = min(x.min, y.min);
      z.minc = (x.min == z.min ? x.minc : 0) + (y.min == z.min ? y.minc : 0);

      z.min2 = INF;
      if (z.min < x.min && x.min < z.min2) z.min2 = x.min;
      if (z.min < x.min2 && x.min2 < z.min2) z.min2 = x.min2;
      if (z.min < y.min && y.min < z.min2) z.min2 = y.min;
      if (z.min < y.min2 && y.min2 < z.min2) z.min2 = y.min2;

      z.fail = 0;
      return z;
    }
    static constexpr X unit() { return {0, INF, 0, INF, 0}; }
    bool commute = true;
  };
  struct AddChmax {
    using X = pair<T, T>;
    using value_type = X;
    static constexpr X op(const X& x, const X& y) {
      auto [a, c] = x;
      auto [d, f] = y;
      a += d, c += d, c = max(c, f);
      return {a, c};
    }
    static constexpr X unit() { return {0, -INF}; }
    bool commute = false;
  };
  struct Beats {
    using Monoid_X = SumMin;
    using Monoid_A = AddChmax;
    using X = typename Monoid_X::value_type;
    using A = typename Monoid_A::value_type;
    static X act(X& x, const A& a, int cnt) {
      assert(!x.fail);
      if (x.min == INF) return x;
      auto [add, ma] = a;
      x.sum += cnt * add, x.min += add, x.min2 += add;
      if (ma == -INF) return x;

      T before_min = x.min;
      x.min = max(x.min, ma);
      if (x.minc == cnt) { x.min2 = x.min, x.sum = cnt * x.min; }
      elif (x.min2 > x.min) { x.sum += (x.min - before_min) * x.minc; }
      else {
        x.fail = 1;
      }
      return x;
    }
  };
  using X = typename SumMin::X;
  SegTree_Beats<Beats> seg;
  Beats_SumMin_Chmax(vc<T>& A) {
    seg.build(len(A), [&](int i) -> X { return from_element(A[i]); });
  }

  void set(int i, ll x) { seg.set(i, from_element(x)); }

  // (sum, min)
  pair<T, T> prod(int l, int r) {
    auto e = seg.prod(l, r);
    return {e.sum, e.min};
  }
  static X from_element(T x) { return {x, x, 1, x}; }

  void chmax(int l, int r, T x) { seg.apply(l, r, {0, x}); }
  void add(int l, int r, T x) { seg.apply(l, r, {x, -INF}); }
};
