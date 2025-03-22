
// 列 A[i] が multiset としてどうなっているかを管理する.
// A[i]:=x, A[i]:=min(A[i],x)
// https://codeforces.com/contest/1572/problem/F
template <typename T>
struct Beats_Multiset_Chmin {
  int n, log, size;
  struct Data {
    T max, max2;
    int cnt, maxc;
    T lazy;
  };

  Data from_element(T x) { return {x, -infty<T>, 1, 1, infty<T>}; }
  vc<Data> dat;

  Data op(Data& L, Data& R) {
    if (L.cnt == 0) return R;
    if (R.cnt == 0) return L;
    Data ANS;
    ANS.max = max(L.max, R.max);
    ANS.max2 = -infty<T>;
    if (L.max < ANS.max) chmax(ANS.max2, L.max);
    if (L.max2 < ANS.max) chmax(ANS.max2, L.max2);
    if (R.max < ANS.max) chmax(ANS.max2, R.max);
    if (R.max2 < ANS.max) chmax(ANS.max2, R.max2);
    ANS.maxc = 0;
    if (L.max == ANS.max) ANS.maxc += L.maxc;
    if (R.max == ANS.max) ANS.maxc += R.maxc;
    ANS.lazy = infty<T>;
    return ANS;
  }

  Beats_Multiset_Chmin() {}
  Beats_Multiset_Chmin(int n) { build(vc<T>(n)); }
  template <typename F>
  Beats_Multiset_Chmin(int n, F f) {
    build(n, f);
  }
  Beats_Multiset_Chmin(const vc<T>& v) { build(v); }
  void build(const vc<T>& v) {
    build(len(v), [&](int i) -> T { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m, log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.resize(size << 1, {-infty<T>, -infty<T>, 0, 0, infty<T>});
    FOR(i, n) { dat[size + i] = from_element(f(i)); }
    FOR_R(i, 1, size) update(i);
  }

  void update(int i) { dat[i] = op(dat[2 * i + 0], dat[2 * i + 1]); }

  // f(before, after, cnt)
  template <typename F>
  void set(int i, T x, F f) {
    auto dfs = [&](auto& dfs, int idx, int a, int b) -> void {
      if (idx == size + i) {
        T now = dat[idx].max;
        if (now != x) f(now, x, 1);
        dat[idx] = from_element(x);
        return;
      }
      int c = (a + b) / 2;
      push(idx);
      if (a <= i && i < c) dfs(dfs, 2 * idx + 0, a, c);
      if (c <= i && i < b) dfs(dfs, 2 * idx + 1, c, b);
      update(idx);
    };
    dfs(dfs, 1, 0, size);
  }

  // f(before, after, cnt)
  template <typename F>
  void chmin(int L, int R, T x, F f) {
    auto dfs = [&](auto& dfs, int idx, int a, int b) -> void {
      if (R <= a || b <= L) return;
      Data& X = dat[idx];
      if (X.max <= x) return;
      if (L <= a && b <= R && X.max2 < x) {
        f(X.max, x, X.maxc);
        X.max = x;
        X.lazy = x;
        return;
      }
      push(idx);
      int c = (a + b) / 2;
      dfs(dfs, 2 * idx + 0, a, c), dfs(dfs, 2 * idx + 1, c, b);
      update(idx);
    };
    dfs(dfs, 1, 0, size);
  }

  // うまく作用できているところの子なのでこれだけでよい
  void push(int i) {
    assert(i < size);
    T x = dat[i].lazy;
    for (int j: {2 * i + 0, 2 * i + 1}) {
      ::chmin(dat[j].max, x);
      ::chmin(dat[j].lazy, x);
    }
  }
};
