// https://codeforces.com/contest/1638/problem/E
// https://codeforces.com/contest/897/problem/E
// 持つ値のタイプ T、座標タイプ X
// コンストラクタでは T none_val を指定する
template <typename T = ll, typename X = ll>
struct Intervals {
  static constexpr X INF = numeric_limits<X>::max();
  const T none_val;
  // none_val でない区間の個数と長さ合計
  int total_num;
  X total_len;
  map<X, T> dat;

  Intervals(T none_val) : none_val(none_val), total_num(0), total_len(0) {
    dat[-INF] = none_val;
    dat[INF] = none_val;
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
    auto it = prev(dat.lower_bound(L));
    while (1) {
      auto [l, t] = *it;
      if (R < l) break;
      it = next(it);
      X r = (*it).fi;
      X l0 = max(l, L);
      X r0 = min(r, R);
      if (l0 < r0) res.eb(l0, r0, t);
    }
    return res;
  }

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
