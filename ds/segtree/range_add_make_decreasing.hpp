
#include "ds/segtree/dual_segtree.hpp"
#include "alg/monoid/add.hpp"
#include "ds/fastset.hpp"

// 区間加算 / ある範囲を prefix 側から単調(増加/減少)になるように修正
// 指定しなかった場合 0 埋めで初期化される
// https://atcoder.jp/contests/joisc2019/tasks/joisc2019_e
// https://atcoder.jp/contests/joisp2024/tasks/joisp2024_i
struct Range_Add_Make_Monotonic_Decreasing {
  // 代表点の集合を持つ. 代表点に対する値を双対セグ木で持つ.
  // A[i-1]>A[i] となっている i 全体も持つ.
  int n;
  FastSet S, INC;
  Dual_SegTree<Monoid_Add<ll>> seg;

  Range_Add_Make_Monotonic_Decreasing() {}
  Range_Add_Make_Monotonic_Decreasing(int n) { build(n); }
  template <typename F>
  Range_Add_Make_Monotonic_Decreasing(int n, F f) {
    build(n, f);
  }
  Range_Add_Make_Monotonic_Decreasing(const vi& v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> ll { return 0; });
  }
  template <typename F>
  void build(int m, F f) {
    vi v(m);
    FOR(i, m) v[i] = f(i);
    build(v);
  }
  void build(const vi& v) {
    n = len(v);
    seg.build(n, [&](int i) -> ll { return v[i]; }), S.build(n), INC.build(n + 1);
    FOR(i, n) S.insert(i);
    FOR(i, 1, n) if (v[i - 1] < v[i]) INC.insert(i);
  }

  ll get(int i) { return seg.get(S.prev(i)); }
  vi get_all() {
    auto A = seg.get_all();
    int p = 0;
    FOR(i, n) {
      if (S[i]) p = i;
      A[i] = A[p];
    }
    return A;
  }
  void set(int i, ll x) {
    split(i), split(i + 1);
    seg.set(i, x);
    INC.insert(i), INC.insert(i + 1);
  }
  void range_add(int L, int R, ll x) {
    split(L), split(R);
    if (x > 0) INC.insert(L);
    if (x < 0) INC.insert(R);
    seg.apply(L, R, x);
  }
  void range_assign(int L, int R, ll x) {
    split(L), split(R);
    INC.insert(L), INC.insert(R);
    S.enumerate(L, R, [&](int i) -> void { S.erase(i); });
    S.insert(L);
    seg.set(L, x);
  }
  void make_increasing(int L, int R) {
    split(L), split(R);
    INC.enumerate(L + 1, R, [&](int i) -> void {
      ll mi = get(i - 1);
      while (i < R) {
        INC.erase(i);
        ll now = get(i);
        if (mi > now) break;
        S.erase(i);
        i = S.next(i);
      }
    });
  }

private:
  void split(int p) {
    if (p == 0 || p == n || S[p]) return;
    seg.set(p, get(p));
    S.insert(p);
  }
};
