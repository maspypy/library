/*
struct F {
  using value_type = ll;  // operator() の戻り値
  int a;
  ll b;
  ll operator()(ll x) { return a * x + b; }
};
*/

// 評価点は ll
// FUNC f には T operator() を定義する, T は比較可能な型
// 1次式：FUNC = LiChaoTree_Line
template <typename FUNC, bool COMPRESS, bool MINIMIZE>
struct LiChao_Tree {
  using T = typename FUNC::value_type;
  vc<ll> X;
  ll lo, hi;
  vc<FUNC> dat;
  int n, log, size;

  inline int get_idx(ll x) {
    if constexpr (COMPRESS) { return LB(X, x); }
    assert(lo <= x && x <= hi);
    return x - lo;
  }

  LiChao_Tree(const vc<ll>& pts, FUNC default_fn) {
    static_assert(COMPRESS);
    for (auto&& x: pts) X.eb(x);
    UNIQUE(X);
    if (X.empty()) X.eb(0);
    n = len(X), log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, default_fn);
  }

  LiChao_Tree(ll lo, ll hi, FUNC default_fn) : lo(lo), hi(hi) {
    static_assert(!COMPRESS);
    n = hi - lo, log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, default_fn);
  }

  void chmin_line(FUNC f) {
    static_assert(MINIMIZE);
    return add_line_at(1, f);
  }
  void chmax_line(FUNC f) {
    static_assert(!MINIMIZE);
    return add_line_at(1, f);
  }

  void chmin_segment(ll xl, ll xr, FUNC f) {
    static_assert(MINIMIZE);
    xl = get_idx(xl), xr = get_idx(xr);
    xl += size, xr += size;
    while (xl < xr) {
      if (xl & 1) add_line_at(xl++, f);
      if (xr & 1) add_line_at(--xr, f);
      xl >>= 1, xr >>= 1;
    }
  }

  void chmax_segment(ll xl, ll xr, FUNC f) {
    static_assert(!MINIMIZE);
    xl = get_idx(xl), xr = get_idx(xr);
    xl += size, xr += size;
    while (xl < xr) {
      if (xl & 1) add_line_at(xl++, f);
      if (xr & 1) add_line_at(--xr, f);
      xl >>= 1, xr >>= 1;
    }
  }

  // 最適な値と FUNC の pair
  pair<T, FUNC> query(ll x) {
    FUNC f = dat[0]; // default_fn
    T fx = f(x);
    int i = get_idx(x) + size;
    while (i) {
      FUNC g = dat[i];
      T gx = g(x);
      if ((MINIMIZE && gx < fx) || (!MINIMIZE && gx > fx)) { f = g, fx = gx; }
      i >>= 1;
    }
    return {fx, f};
  }

  void add_line_at(int i, FUNC f) {
    int upper_bit = 31 - __builtin_clz(i);
    int l = (size >> upper_bit) * (i - (1 << upper_bit));
    int r = l + (size >> upper_bit);
    while (l < r) {
      FUNC g = dat[i];
      T fl = evaluate_inner(f, l), fr = evaluate_inner(f, r - 1);
      T gl = evaluate_inner(g, l), gr = evaluate_inner(g, r - 1);
      bool bl = (MINIMIZE ? fl < gl : fl > gl);
      bool br = (MINIMIZE ? fr < gr : fr > gr);
      if (bl && br) {
        dat[i] = f;
        return;
      }
      if (!bl && !br) return;
      int m = (l + r) / 2;
      T fm = evaluate_inner(f, m), gm = evaluate_inner(g, m);
      bool bm = (MINIMIZE ? fm < gm : fm > gm);
      if (bm) {
        dat[i] = f;
        f = g;
        if (!bl) { i = 2 * i + 0, r = m; }
        if (bl) { i = 2 * i + 1, l = m; }
      }
      if (!bm) {
        if (bl) { i = 2 * i + 0, r = m; }
        if (!bl) { i = 2 * i + 1, l = m; }
      }
    }
  }

private:
  inline T evaluate_inner(FUNC& f, ll x) { return f((COMPRESS ? X[min<int>(x, n - 1)] : min<int>(x + lo, hi - 1))); }
};
