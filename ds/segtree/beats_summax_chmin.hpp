#include "ds/segtree/segtree_beats.hpp"

constexpr ll Beats_INF = 1LL << 40;

struct Beats_SumMax_Chmin {
  struct CntSumMinMax {
    struct X {
      ll cnt, sum, max, maxc, max2;
      bool fail;
    };
    using value_type = X;
    static X op(const X& x, const X& y) {
      if (x.cnt == 0) return y;
      if (y.cnt == 0) return x;
      X z;
      z.cnt = x.cnt + y.cnt, z.sum = x.sum + y.sum;

      z.max = max(x.max, y.max);
      z.maxc = (x.max == z.max ? x.maxc : 0) + (y.max == z.max ? y.maxc : 0);

      z.max2 = -Beats_INF;
      if (z.max > x.max && x.max > z.max2) z.max2 = x.max;
      if (z.max > x.max2 && x.max2 > z.max2) z.max2 = x.max2;
      if (z.max > y.max && y.max > z.max2) z.max2 = y.max;
      if (z.max > y.max2 && y.max2 > z.max2) z.max2 = y.max2;

      z.fail = 0;
      return z;
    }
    static constexpr X unit() { return {0, 0, 0, 0, 0, 0}; }
    bool commute = true;
  };
  struct AddChmin {
    using X = pi;
    using value_type = X;
    static constexpr X op(const X& x, const X& y) {
      auto [a, b] = x;
      auto [d, e] = y;
      a += d, b += d;
      b = min(b, e);
      return {a, b};
    }
    static constexpr X unit() { return {0, Beats_INF}; }
    bool commute = false;
  };
  struct Lazy {
    using MX = CntSumMinMax;
    using MA = AddChmin;
    using X_structure = MX;
    using A_structure = MA;
    using X = MX::value_type;
    using A = MA::value_type;
    static X act(X& x, const A& a) {
      if (x.cnt == 0) return x;
      assert(!x.fail);
      auto [add, mi] = a;
      x.sum += x.cnt * add;
      x.max += add;
      x.max2 += add;

      if (mi == Beats_INF) return x;

      ll before_max = x.max;
      x.max = min(x.max, mi);
      if (x.maxc == x.cnt) {
        x.max2 = x.max;
        x.sum = x.cnt * x.max;
        return x;
      }
      if (x.max2 < x.max) {
        x.sum += (x.max - before_max) * x.maxc;
      } else {
        x.fail = 1;
      }
      return x;
    }
  };
  LazySegTreeBeats<Lazy> seg;
  Beats_SumMax_Chmin(vc<ll>& A) {
    using X = Lazy::MX::value_type;
    vc<X> seg_raw(len(A));
    FOR(i, len(A)) {
      ll x = A[i];
      seg_raw[i] = {1, x, x, 1, x};
    }
    seg = LazySegTreeBeats<Lazy>(seg_raw);
  }

  template <typename F>
  Beats_SumMax_Chmin(int N, F f) {
    using X = Lazy::MX::value_type;
    vc<X> seg_raw(N);
    FOR(i, N) {
      ll x = f(i);
      seg_raw[i] = {1, x, x, 1, x};
    }
    seg = LazySegTreeBeats<Lazy>(seg_raw);
  }

  void set(int i, ll x) { seg.set(i, {1, x, x, 1, x}); }

  Lazy::MX::value_type prod(int l, int r) {
    auto e = seg.prod(l, r);
    return e;
  }

  void chmin(int l, int r, ll x) { seg.apply(l, r, {0, x}); }

  void add(int l, int r, ll x) { seg.apply(l, r, {x, Beats_INF}); }
};
