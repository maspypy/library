#include "ds/segtree/segtree.hpp"

// INF+x==INF みたいな処理は入れていない
// N=Q=10^6 で lazysegtree より 40% 程度高速
template <typename T>
struct Range_Add_Range_MaxIdx {
  struct Data {
    T sum, max;
    int idx;
  };

  struct Mono {
    using value_type = Data;
    using X = value_type;
    static X op(X L, X R) {
      if (L.max >= L.sum + R.max) {
        return {L.sum + R.sum, L.max, L.idx};
      }
      return {L.sum + R.sum, L.sum + R.max, R.idx};
    }
    static constexpr X unit() { return {0, -2 * infty<T>, -1}; }
    static constexpr bool commute = false;
  };
  int n;
  T lazy;
  SegTree<Mono> seg;

  Range_Add_Range_MaxIdx() {}
  // (n) だけだと 0 埋めで初期化します
  Range_Add_Range_MaxIdx(int n) { build(n); }
  template <typename F>
  Range_Add_Range_MaxIdx(int n, F f) {
    build(n, f);
  }
  Range_Add_Range_MaxIdx(const vc<T>& v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> T { return 0; });
  }
  void build(const vc<T>& v) {
    build(len(v), [&](int i) -> T { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    lazy = 0;
    n = m;
    T pre = 0;
    seg.build(n, [&](int i) -> Data {
      T t = f(i) - pre;
      pre += t;
      return Data{t, t, i};
    });
  }

  pair<T, int> prod(int L, int R) {
    if (L == R) return {-infty<T>, -1};
    Data x = seg.prod(L, R);
    T ans = x.max;
    L += seg.size;
    for (; L > 0; L /= 2) {
      if (L & 1) ans += seg.dat[--L].sum;
    }
    return {ans + lazy, x.idx};
  }

  pair<T, int> prod_all() { return prod(0, n); }

  // 基本デバッグ用というつもりでさぼり O(NlogN) になっている
  vc<T> get_all() {
    vc<T> ANS(n);
    FOR(i, n) ANS[i] = prod(i, i + 1).fi;
    return ANS;
  }

  void apply(int L, int R, T x) { apply_suffix(L, x), apply_suffix(R, -x); }

  // [0,i)
  void apply_prefix(int i, T x) {
    lazy += x;
    apply_suffix(i, -x);
  }

  // [i,n)
  void apply_suffix(int i, T x) {
    if (i == n) return;
    T t = seg.get(i).max + x;
    seg.set(i, {t, t, i});
  }
  void apply_all(T x) { lazy += x; }

  void set(int i, T x) {
    T now = prod(i, i + 1).fi;
    apply(i, i + 1, x - now);
  }

  void multiply(int i, T x) {
    T now = prod(i, i + 1).fi;
    if (now < x) apply(i, i + 1, x - now);
  }
};
