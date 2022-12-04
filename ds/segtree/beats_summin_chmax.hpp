#include "ds/segtree/segtree_beats.hpp"

constexpr ll Beats_INF = 1LL << 40;

struct Beats_SumMin_Chmax {
  struct CntSumMin {
    struct X {
      ll cnt, sum, min, minc, min2;
      bool fail;
    };
    using value_type = X;
    static X op(const X& x, const X& y) {
      if (x.cnt == 0) return y;
      if (y.cnt == 0) return x;
      X z;
      z.cnt = x.cnt + y.cnt, z.sum = x.sum + y.sum;

      z.min = min(x.min, y.min);
      z.minc = (x.min == z.min ? x.minc : 0) + (y.min == z.min ? y.minc : 0);

      z.min2 = Beats_INF;
      if (z.min < x.min && x.min < z.min2) z.min2 = x.min;
      if (z.min < x.min2 && x.min2 < z.min2) z.min2 = x.min2;
      if (z.min < y.min && y.min < z.min2) z.min2 = y.min;
      if (z.min < y.min2 && y.min2 < z.min2) z.min2 = y.min2;

      z.fail = 0;
      return z;
    }
    static constexpr X unit() { return {0, 0, 0, 0, 0, 0}; }
    bool commute = true;
  };
  struct AddChmax {
    using X = pi;
    using value_type = X;
    static constexpr X op(const X& x, const X& y) {
      auto [a, c] = x;
      auto [d, f] = y;
      a += d, c += d;
      c = max(c, f);
      return {a, c};
    }
    static constexpr X unit() { return {0, -Beats_INF}; }
    bool commute = false;
  };
  struct Lazy {
    using MX = CntSumMin;
    using MA = AddChmax;
    using X_structure = MX;
    using A_structure = MA;
    using X = MX::value_type;
    using A = MA::value_type;
    static X act(X& x, const A& a) {
      if (x.cnt == 0) return x;
      assert(!x.fail);
      auto [add, ma] = a;
      x.sum += x.cnt * add;
      x.min += add, x.min2 += add;
      if (ma == -Beats_INF) return x;

      ll before_min = x.min;
      x.min = max(x.min, ma);
      if (x.minc == x.cnt) {
        x.min2 = x.min;
        x.sum = x.cnt * x.min;
        return x;
      }
      if (x.min2 > x.min) {
        x.sum += (x.min - before_min) * x.minc;
      } else {
        x.fail = 1;
      }
      return x;
    }
  };
  LazySegTreeBeats<Lazy> seg;
  Beats_SumMin_Chmax(vc<ll>& A) {
    using X = Lazy::MX::value_type;
    vc<X> seg_raw(len(A));
    FOR(i, len(A)) {
      ll x = A[i];
      seg_raw[i] = {1, x, x, 1, x};
    }
    seg = LazySegTreeBeats<Lazy>(seg_raw);
  }

  void set(int i, ll x) { seg.set(i, {1, x, x, 1, x}); }

  Lazy::MX::value_type prod(int l, int r) {
    auto e = seg.prod(l, r);
    return e;
  }

  void chmax(int l, int r, ll x) { seg.apply(l, r, {0, x}); }

  void add(int l, int r, ll x) { seg.apply(l, r, {x, -Beats_INF}); }

  void apply(int l, int r, pi addchmax) { seg.apply(l, r, addchmax); }
};
