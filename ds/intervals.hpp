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
        ss(N) {
    ss.insert(0);
  }

  // x を含む区間の情報の取得
  tuple<int, int, T> get(int x, bool ERASE) {
    int l = ss.prev(x);
    int r = ss.next(x + 1);
    T t = dat[l];
    if (t != none_val && ERASE) {
      --total_num, total_len -= r - l;
      dat[l] = none_val;
      merge_at(l);
      merge_at(r);
    }
    return {l, r, t};
  }

  // [L, R) 内の全データの取得
  template <typename F>
  void enumerate_range(int L, int R, F f, bool ERASE) {
    assert(LLIM <= L && L <= R && R <= RLIM);
    if (!ERASE) {
      int l = ss.prev(L);
      while (l < R) {
        int r = ss.next(l + 1);
        f(max(l, L), min(r, R), dat[l]);
        l = r;
      }
      return;
    }
    // 半端なところの分割
    int p = ss.prev(L);
    if (p < L) {
      ss.insert(L);
      dat[L] = dat[p];
      if (dat[L] != none_val) ++total_num;
    }
    p = ss.next(R);
    if (R < p) {
      dat[R] = dat[ss.prev(R)];
      ss.insert(R);
      if (dat[R] != none_val) ++total_num;
    }
    p = L;
    while (p < R) {
      int q = ss.next(p + 1);
      T x = dat[p];
      f(p, q, x);
      if (dat[p] != none_val) --total_num, total_len -= q - p;
      ss.erase(p);
      p = q;
    }
    ss.insert(L);
    dat[L] = none_val;
  }

  void set(int L, int R, T t) {
    enumerate_range(
        L, R, [](int l, int r, T x) -> void {}, true);
    ss.insert(L);
    dat[L] = t;
    if (t != none_val) total_num++, total_len += R - L;
    merge_at(L);
    merge_at(R);
  }

  template <typename F>
  void enumerate_all(F f) {
    enumerate_range(0, RLIM, f, false);
  }

  void merge_at(int p) {
    if (p <= 0 || RLIM <= p) return;
    int q = ss.prev(p - 1);
    if (dat[p] == dat[q]) {
      if (dat[p] != none_val) --total_num;
      ss.erase(p);
    }
  }
};

// https://codeforces.com/contest/1638/problem/E
// 持つ値のタイプ T、座標タイプ X
// コンストラクタでは T none_val を指定する
template <typename T, typename X = ll>
struct Intervals {
  static constexpr X LLIM = -infty<X>;
  static constexpr X RLIM = infty<X>;
  const T none_val;
  // none_val でない区間の個数と長さ合計
  int total_num;
  X total_len;
  map<X, T> dat;

  Intervals(T none_val) : none_val(none_val), total_num(0), total_len(0) {
    dat[LLIM] = none_val;
    dat[RLIM] = none_val;
  }

  // x を含む区間の情報の取得
  tuple<X, X, T> get(X x, bool ERASE) {
    auto it2 = dat.upper_bound(x);
    auto it1 = prev(it2);
    auto [l, tl] = *it1;
    auto [r, tr] = *it2;
    if (t != none_val && ERASE) {
      --total_num, total_len -= r - l;
      dat[l] = none_val;
      merge_at(l);
      merge_at(r);
    }
    return {l, r, tl};
  }

  // [L, R) 内の全データの取得
  template <typename F>
  void enumerate_range(X L, X R, F f, bool ERASE) {
    assert(LLIM <= L && L <= R && R <= RLIM);
    if (!ERASE) {
      auto it = prev(dat.upper_bound(L));
      while ((*it).fi < R) {
        auto it2 = next(it);
        f(max((*it).fi, L), min((*it2).fi, R), (*it).se);
        it = it2;
      }
      return;
    }
    // 半端なところの分割
    auto p = prev(dat.upper_bound(L));
    if ((*p).fi < L) {
      dat[L] = (*p).se;
      if (dat[L] != none_val) ++total_num;
    }
    p = dat.lower_bound(R);
    if (R < (*p).fi) {
      T t = (*prev(p)).se;
      dat[R] = t;
      if (t != none_val) ++total_num;
    }
    p = dat.lower_bound(L);
    while (1) {
      if ((*p).fi >= R) break;
      auto q = next(p);
      T t = (*p).se;
      f((*p).fi, (*q).fi, t);
      if (t != none_val) --total_num, total_len -= (*q).fi - (*p).fi;
      p = dat.erase(p);
    }
    dat[L] = none_val;
  }

  void set(X L, X R, T t) {
    enumerate_range(
        L, R, [](int l, int r, T x) -> void {}, true);
    dat[L] = t;
    if (t != none_val) total_num++, total_len += R - L;
    merge_at(L);
    merge_at(R);
  }

  template <typename F>
  void enumerate_all(F f) {
    enumerate_range(LLIM, RLIM, f, false);
  }

  void merge_at(X p) {
    if (p == LLIM || RLIM == p) return;
    auto itp = dat.lower_bound(p);
    assert((*itp).fi == p);
    auto itq = prev(itp);
    if ((*itp).se == (*itq).se) {
      if ((*itp).se != none_val) --total_num;
      dat.erase(itp);
    }
  }
};
