
// https://cyanmond.hatenablog.com/entry/2023/08/07/163326
// F f: f(fid,x)
template <typename T, bool MINIMIZE, typename F>
struct Monge_LiChao_Tree {
  int n, log, size;
  F f;
  vc<int> FID;

  Monge_LiChao_Tree(int n, F f) : n(n), f(f) {
    log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    FID.assign(size << 1, -1);
  }

  void add_line(int fid) { return add_line_at(1, fid); }
  void add_segment(int L, int R, int fid) {
    L += size, R += size;
    while (L < R) {
      if (L & 1) add_line_at(L++, fid);
      if (R & 1) add_line_at(--R, fid);
      L >>= 1, R >>= 1;
    }
  }

  // [fx, fid]
  pair<T, int> query(int x) {
    int i = x + size;
    pair<T, int> res;
    if (!MINIMIZE) res = {-infty<T>, -1};
    if (MINIMIZE) res = {infty<T>, -1};
    while (i) {
      pair<T, int> res1 = {evaluate(FID[i], x), FID[i]};
      res = (MINIMIZE ? min(res, res1) : max(res, res1));
      i >>= 1;
    }
    return res;
  }

private:
  void add_line_at(int i, int fid) {
    int upper_bit = 31 - __builtin_clz(i);
    int l = (size >> upper_bit) * (i - (1 << upper_bit));
    int r = l + (size >> upper_bit);
    while (l < r) {
      int gid = FID[i];
      T fl = evaluate(fid, l), fr = evaluate(fid, r - 1);
      T gl = evaluate(gid, l), gr = evaluate(gid, r - 1);
      bool bl = (MINIMIZE ? fl < gl : fl > gl);
      bool br = (MINIMIZE ? fr < gr : fr > gr);
      if (bl && br) {
        FID[i] = fid;
        return;
      }
      if (!bl && !br) return;
      int m = (l + r) / 2;
      T fm = evaluate(fid, m), gm = evaluate(gid, m);
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

  T evaluate(int fid, int x) {
    if (fid == -1) return (MINIMIZE ? infty<T> : -infty<T>);
    chmin(x, n - 1);
    return f(fid, x);
  }
};