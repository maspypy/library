// evaluate を書き変えると、totally monotone な関数群にも使える
template <typename T, bool COMPRESS, bool MINIMIZE>
struct LiChao_Tree {
  using FUNC = pair<T, T>;
  vc<FUNC> funcs;

  static inline T evaluate(FUNC& f, ll x) { return f.fi * x + f.se; }

  vc<ll> points;
  vc<int> FID;
  int n, log, size;

  LiChao_Tree(int m) {
    static_assert(!COMPRESS);
    n = m, log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    FID.assign(size << 1, -1);
  }
  template <typename XY>
  LiChao_Tree(const vc<XY> pts) {
    static_assert(COMPRESS);
    for (auto&& x: pts) points.eb(x);
    UNIQUE(points);
    n = len(points), log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    FID.assign(size << 1, -1);
  }

  void add_line(FUNC f) {
    int fid = len(funcs);
    funcs.eb(f);
    return add_line_at(1, fid);
  }
  void add_segment(ll xl, ll xr, FUNC f) {
    int fid = len(funcs);
    funcs.eb(f);
    if (COMPRESS) xl = LB(points, xl), xr = LB(points, xr);
    xl += size, xr += size;
    while (xl < xr) {
      if (xl & 1) add_line_at(xl++, fid);
      if (xr & 1) add_line_at(--xr, fid);
      xl >>= 1, xr >>= 1;
    }
  }
  pair<T, int> query(ll x) {
    if (COMPRESS) {
      int ix = LB(points, x);
      assert(points[ix] == x);
      x = ix;
    }
    int i = x + size;
    pair<T, int> res;
    if (!MINIMIZE) res = {-infty<T>, -1};
    if (MINIMIZE) res = {infty<T>, -1};
    while (i) {
      if (FID[i] != -1 && FID[i] != res.se) {
        pair<T, int> res1 = {evaluate_inner(FID[i], x), FID[i]};
        res = (MINIMIZE ? min(res, res1) : max(res, res1));
      }
      i >>= 1;
    }
    return res;
  }

  void add_line_at(int i, int fid) {
    int upper_bit = 31 - __builtin_clz(i);
    int l = (size >> upper_bit) * (i - (1 << upper_bit));
    int r = l + (size >> upper_bit);
    while (l < r) {
      int gid = FID[i];
      T fl = evaluate_inner(fid, l), fr = evaluate_inner(fid, r - 1);
      T gl = evaluate_inner(gid, l), gr = evaluate_inner(gid, r - 1);
      bool bl = (MINIMIZE ? fl < gl : fl > gl);
      bool br = (MINIMIZE ? fr < gr : fr > gr);
      if (bl && br) {
        FID[i] = fid;
        return;
      }
      if (!bl && !br) return;
      int m = (l + r) / 2;
      T fm = evaluate_inner(fid, m), gm = evaluate_inner(gid, m);
      bool bm = (MINIMIZE ? fm < gm : fm > gm);
      if (bm) {
        FID[i] = fid;
        fid = gid;
        if (!bl) { i = 2 * i + 0, r = m; }
        if (bl) { i = 2 * i + 1, l = m; }
      }
      if (!bm) {
        if (bl) { i = 2 * i + 0, r = m; }
        if (!bl) { i = 2 * i + 1, l = m; }
      }
    }
  }

  T evaluate_inner(int fid, ll x) {
    if (fid == -1) return (MINIMIZE ? infty<T> : -infty<T>);
    return evaluate(funcs[fid], (COMPRESS ? points[x] : x));
  }
};
