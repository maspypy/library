#pragma once
template <typename T>
struct LiChaoTree {
  struct Line {
    T a, b;
    Line(T a, T b) : a(a), b(b) {}
    inline T eval(T x) const { return a * x + b; }
    inline bool over(const Line &other, const T &x) const {
      return eval(x) < other.eval(x);
    }
  };

  vector<T> xs;
  vector<Line> seg;
  int size;
  const T INF;
  // コンストラクタ。クエリの来る x 全体を渡す。ソート不要。
  LiChaoTree(const vector<T> &_xs, T INF) : xs(_xs), INF(INF) {
    if (len(xs) == 0) xs.eb(0);
    UNIQUE(xs);
    size = 1;
    while (size < len(xs)) size *= 2;
    while (len(xs) < size) xs.eb(xs.back());
    seg.assign(2 * size, Line(0, INF));
  }

  // y = ax + bなる直線を追加
  void add(T a, T b) { inner_update(a, b, 0, size, 1); }

  // [lx, rx) に線分 y = ax + b を追加
  void add(T lx, T rx, T a, T b) {
    int l = LB(xs, lx) + size;
    int r = LB(xs, rx) + size;
    while (l < r) {
      if (l & 1) inner_update(a, b, l++);
      if (r & 1) inner_update(a, b, --r);
      l >>= 1, r >>= 1;
    }
  }

  T get_min(T x) {
    int i = LB(xs, x);
    assert(xs[i] == x);
    return inner_query(x, i + size);
  }

  T get_min_by_idx(int i) { return inner_query(xs[i], i + size); }

  void debug() {
    print("xs", xs);
    print("seg");
    FOR(i, len(seg)) print(i, seg[i].a, seg[i].b);
  }

private:
  void inner_update(T a, T b, int l, int r, int idx) {
    Line line(a, b);
    while (1) {
      int m = (l + r) >> 1;
      bool l_over = line.over(seg[idx], xs[l]);
      bool r_over = line.over(seg[idx], xs[r - 1]);
      if (l_over == r_over) {
        if (l_over) swap(seg[idx], line);
        return;
      }
      bool m_over = line.over(seg[idx], xs[m]);
      if (m_over) swap(seg[idx], line);
      if (l_over != m_over)
        idx = (idx << 1) | 0, r = m;
      else
        idx = (idx << 1) | 1, l = m;
    }
  }

  void inner_update(T a, T b, int seg_idx) {
    int left, right;
    int upper_bit = 31 - __builtin_clz(seg_idx);
    left = (size >> upper_bit) * (seg_idx - (1 << upper_bit));
    right = left + (size >> upper_bit);
    inner_update(a, b, left, right, seg_idx);
  }

  T inner_query(T x, int idx) {
    T ret = INF;
    while (idx >= 1) {
      chmin(ret, seg[idx].eval(x));
      idx >>= 1;
    }
    return ret;
  }
};
