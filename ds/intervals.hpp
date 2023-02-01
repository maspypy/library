// https://codeforces.com/contest/1638/problem/E
// https://codeforces.com/contest/897/problem/E
// 持つ値のタイプ T、座標タイプ X
// コンストラクタでは T none_val を指定する
template <typename T = ll, typename X = ll>
struct Intervals {
  static constexpr X LLIM = -INF<X>;
  static constexpr X RLIM = INF<X>;
  const T none_val;
  // none_val でない区間の個数と長さ合計
  int total_num;
  X total_len;
  map<X, T> dat;

  Intervals(T none_val) : none_val(none_val), total_num(0), total_len(0) {
    dat[LLIM] = none_val;
    dat[RLIM] = none_val;
  }

  tuple<X, X, T> get(X x) {
    auto it = dat.upper_bound(x);
    X r = (*it).fi;
    auto [l, t] = *prev(it);
    return {l, r, t};
  }

  template <typename ADD, typename RM>
  void set(X L, X R, T t, ADD& add_f, RM& rm_f) {
    if (L == R) return;
    assert(L < R);
    // 区間 [l, r) を t に変更する
    // まずは、重なるか隣り合う区間を全列挙
    vc<tuple<X, X, T>> tmp;
    auto it = prev(dat.lower_bound(L));
    while (1) {
      auto [l, t] = *it;
      if (R < l) break;
      it = next(it);
      X r = (*it).fi;
      tmp.eb(l, r, t);
    }
    auto [lx, _, lt] = tmp[0];
    auto [__, rx, rt] = tmp.back();
    // とりあえず全部削除
    for (auto&& [l, r, t]: tmp) {
      dat.erase(l);
      if (t == none_val) continue;
      total_num--;
      total_len -= r - l;
      rm_f(l, r, t);
    }
    if (lt == t) chmin(L, lx);
    if (rt == t) chmax(R, rx);
    if (lx < L) {
      // [lx, L)
      dat[lx] = lt;
      if (lt != none_val) {
        total_num++;
        total_len += L - lx;
        add_f(lx, L, lt);
      }
    }
    if (R < rx) {
      // [R, rx)
      dat[R] = rt;
      if (rt != none_val) {
        total_num++;
        total_len += rx - R;
        add_f(R, rx, rt);
      }
    }
    // [L, R)
    dat[L] = t;
    if (t != none_val) {
      total_num++;
      total_len += R - L;
      add_f(L, R, t);
    }
  }

  void set(X L, X R, T t = 1) {
    auto f = [&](X L, X R, T t) -> void {};
    set(L, R, t, f, f);
  }

  void erase(X L, X R) {
    auto f = [&](X L, X R, T t) -> void {};
    set(L, R, none_val, f, f);
  }

  // L, R 内のデータ (l, r, t) を全部取得する
  vc<tuple<X, X, T>> get(X L, X R) {
    vc<tuple<X, X, T>> res;
    auto it = dat.lower_bound(L);
    if (it != dat.begin()) it = prev(it);
    while (1) {
      auto [l, t] = *it;
      if (R <= l) break;
      it = next(it);
      X r = (*it).fi;
      X l0 = max(l, L);
      X r0 = min(r, R);
      if (l0 < r0) res.eb(l0, r0, t);
    }
    return res;
  }

  vc<tuple<X, X, T>> get_all() { return get(LLIM, RLIM); }

  void debug() {
    auto it = dat.begin();
    print("Intervals");
    print("total_num", total_num);
    print("total_len", total_len);
    while (1) {
      auto [l, t] = *it;
      ++it;
      if (it == dat.end()) break;
      X r = (*it).fi;
      print("l, r, t", l, r, t);
    }
  }
};

#include "ds/fastset.hpp"

// FastSet で高速化したもの
template <typename T>
struct Intervals_Fast {
  const int LLIM, RLIM;
  const T none_val;
  // none_val でない区間の個数と長さ合計
  int total_num;
  int total_len;
  vc<T> dat;
  FastSet ss;

  Intervals_Fast(int N, T none_val)
      : LLIM(0),
        RLIM(N),
        none_val(none_val),
        total_num(0),
        total_len(0),
        dat(N, none_val),
        ss(N + 1) {
    ss.insert(0);
    ss.insert(N);
  }

  tuple<int, int, T> get(int x) {
    auto l = ss.prev(x);
    auto r = ss.next(x + 1);
    return {l, r, dat[l]};
  }

  template <typename ADD, typename RM>
  void set(int L, int R, T t, ADD& add_f, RM& rm_f) {
    assert(LLIM <= L && L <= R && R <= RLIM);
    if (L == R) return;
    assert(L < R);
    // 区間 [l, r) を t に変更する
    // まずは、重なるか隣り合う区間を全列挙
    vc<tuple<int, int, T>> tmp;
    auto l = ss.prev(L);
    while (l < R) {
      auto r = ss.next(l + 1);
      auto t = dat[l];
      tmp.eb(l, r, t);
      l = r;
    }
    auto [lx, _, lt] = tmp[0];
    auto [__, rx, rt] = tmp.back();
    // とりあえず全部削除
    for (auto&& [l, r, t]: tmp) {
      ss.erase(l);
      if (t == none_val) continue;
      total_num--;
      total_len -= r - l;
      rm_f(l, r, t);
    }
    if (lt == t) chmin(L, lx);
    if (rt == t) chmax(R, rx);
    if (lx < L) {
      // [lx, L)
      ss.insert(lx);
      dat[lx] = lt;
      if (lt != none_val) {
        total_num++;
        total_len += L - lx;
        add_f(lx, L, lt);
      }
    }
    if (R < rx) {
      // [R, rx)
      ss.insert(R);
      dat[R] = rt;
      if (rt != none_val) {
        total_num++;
        total_len += rx - R;
        add_f(R, rx, rt);
      }
    }
    // [L, R)
    ss.insert(L);
    dat[L] = t;
    if (t != none_val) {
      total_num++;
      total_len += R - L;
      add_f(L, R, t);
    }
  }

  void set(int L, int R, T t) {
    auto f = [&](int L, int R, T t) -> void {};
    set(L, R, t, f, f);
  }

  void erase(int L, int R) {
    auto f = [&](int L, int R, T t) -> void {};
    set(L, R, none_val, f, f);
  }

  // L, R 内のデータ (l, r, t) を全部取得する
  vc<tuple<int, int, T>> get(int L, int R) {
    assert(LLIM <= L && L <= R && R <= RLIM);
    vc<tuple<int, int, T>> res;
    auto l = ss.prev(L);
    while (l < R) {
      auto t = dat[l];
      auto r = ss.next(l + 1);
      int l0 = max(l, L);
      int r0 = min(r, R);
      if (l0 < r0) res.eb(l0, r0, t);
      l = r;
    }
    return res;
  }

  vc<tuple<int, int, T>> get_all() { return get(LLIM, RLIM); }

  void debug() {
    print("Intervals");
    print("total_num", total_num);
    print("total_len", total_len);
    int l = 0;
    while (l < RLIM) {
      auto t = dat[l];
      auto r = ss.next(l + 1);
      print("l, r, t", l, r, t);
      l = r;
    }
  }
};
