#include "ds/segtree/segtree_beats.hpp"

// (x[i],y[i]) からなる列. a>=0 であるときに y[i] :- y[i] + ax[i] + b という作用ができる
// x には単調性は要らない. x,sum(a):T1, y,sum(b):T2, T1*T1<=T2.
// https://codeforces.com/blog/entry/82094#comment-688448
// https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d
template <typename T1, typename T2>
struct Beats_Kinetic_Max {
  struct Mono_X {
    struct X {
      T1 x;
      T2 y;
      T1 nxt_change;
      bool fail;
    };
    using value_type = X;
    static X op(X L, X R) {
      X M;
      if (L.y < R.y) { swap(L, R); }
      M.x = L.x, M.y = L.y;
      M.nxt_change = min(L.nxt_change, R.nxt_change);
      if (L.x < R.x) {
        T2 t = floor<T2>(L.y - R.y, R.x - L.x);
        chmin(M.nxt_change, t + 1);
      }
      M.fail = 0;
      return M;
    }
    static constexpr X unit() { return {0, -infty<T2>, infty<T1>, 0}; }
    bool commute = true;
  };
  struct Mono_A {
    using X = pair<T1, T2>;
    using value_type = X;
    static constexpr X op(const X& x, const X& y) { return {x.fi + y.fi, x.se + y.se}; }
    static constexpr X unit() { return {0, 0}; }
    bool commute = true;
  };
  struct Beats {
    using Monoid_X = Mono_X;
    using Monoid_A = Mono_A;
    using X = typename Monoid_X::value_type;
    using A = typename Monoid_A::value_type;
    static X act(X& M, const A& a, int cnt) {
      assert(!M.fail && a.fi >= 0);
      if (M.nxt_change <= a.fi) {
        M.fail = 1;
        return M;
      }
      M.y += T2(a.fi) * M.x + a.se;
      M.nxt_change -= a.fi;
      return M;
    }
  };
  using S = typename Mono_X::X;
  SegTree_Beats<Beats> seg;
  Beats_Kinetic_Max(vc<T1>& X, vc<T2>& Y) {
    seg.build(len(X), [&](int i) -> S { return {X[i], Y[i], infty<T1>, 0}; });
  }
  template <typename F>
  Beats_Kinetic_Max(int n, F f) {
    seg.build(n, [&](int i) -> S {
      auto [x, y] = f(i);
      return {x, y, infty<T1>, 0};
    });
  }

  void set(int i, T1 x, T2 y) { seg.set(i, {x, y, infty<T1>, 0}); }

  // (x,y)
  pair<T1, T2> prod(int l, int r) {
    auto e = seg.prod(l, r);
    return {e.x, e.y};
  }
  pair<T1, T2> prod_all() {
    auto e = seg.prod_all();
    return {e.x, e.y};
  }
  void apply(int l, int r, T1 a, T2 b) { seg.apply(l, r, {a, b}); }
};

// (x[i],y[i]) からなる列. a>=0 であるときに y[i] :- y[i] + ax[i] + b という作用ができる
// x には単調性は要らない. x,sum(a):T1, y,sum(b):T2, T1*T1<=T2.
// https://codeforces.com/blog/entry/82094#comment-688448
// https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d
template <typename T1, typename T2>
struct Beats_Kinetic_Min {
  struct Mono_X {
    struct X {
      T1 x;
      T2 y;
      T1 nxt_change;
      bool fail;
    };
    using value_type = X;
    static X op(X L, X R) {
      X M;
      if (L.y > R.y) { swap(L, R); }
      M.x = L.x, M.y = L.y;
      M.nxt_change = min(L.nxt_change, R.nxt_change);
      if (L.x > R.x) {
        T2 t = floor<T2>(R.y - L.y, L.x - R.x);
        chmin(M.nxt_change, t + 1);
      }
      M.fail = 0;
      return M;
    }
    static constexpr X unit() { return {0, infty<T2>, infty<T1>, 0}; }
    bool commute = true;
  };
  struct Mono_A {
    using X = pair<T1, T2>;
    using value_type = X;
    static constexpr X op(const X& x, const X& y) { return {x.fi + y.fi, x.se + y.se}; }
    static constexpr X unit() { return {0, 0}; }
    bool commute = true;
  };
  struct Beats {
    using Monoid_X = Mono_X;
    using Monoid_A = Mono_A;
    using X = typename Monoid_X::value_type;
    using A = typename Monoid_A::value_type;
    static X act(X& M, const A& a, int cnt) {
      assert(!M.fail && a.fi >= 0);
      if (M.nxt_change <= a.fi) {
        M.fail = 1;
        return M;
      }
      M.y += T2(a.fi) * M.x + a.se;
      M.nxt_change -= a.fi;
      return M;
    }
  };
  using S = typename Mono_X::X;
  SegTree_Beats<Beats> seg;
  Beats_Kinetic_Min(vc<T1>& X, vc<T2>& Y) {
    seg.build(len(X), [&](int i) -> S { return {X[i], Y[i], infty<T1>, 0}; });
  }
  template <typename F>
  Beats_Kinetic_Min(int n, F f) {
    seg.build(n, [&](int i) -> S {
      auto [x, y] = f(i);
      return {x, y, infty<T1>, 0};
    });
  }

  void set(int i, T1 x, T2 y) { seg.set(i, {x, y, infty<T1>, 0}); }

  // (x,y)
  pair<T1, T2> prod(int l, int r) {
    auto e = seg.prod(l, r);
    return {e.x, e.y};
  }
  pair<T1, T2> prod_all() {
    auto e = seg.prod_all();
    return {e.x, e.y};
  }
  void apply(int l, int r, T1 a, T2 b) { seg.apply(l, r, {a, b}); }
};
