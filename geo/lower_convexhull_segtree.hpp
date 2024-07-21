// ALLOW_180=true のときに同一座標の点があると壊れる気がする
template <typename T, bool ALLOW_180 = false>
struct Lower_ConvexHull_SegTree {
  struct P {
    T x, y;
    P() : x(0), y(0) {}
    P(T x, T y) : x(x), y(y) {}
    P operator+=(const P p) {
      x += p.x, y += p.y;
      return *this;
    }
    P operator-=(const P p) {
      x -= p.x, y -= p.y;
      return *this;
    }
    P operator+(P p) const { return {x + p.x, y + p.y}; }
    P operator-(P p) const { return {x - p.x, y - p.y}; }
    bool operator<(P p) const { return (x != p.x ? x < p.x : y < p.y); }
    bool operator==(P p) const { return (x == p.x && y == p.y); }
    i128 dot(T a, T b) { return a * x + b * y; }
  };

  struct Data {
    int L, R;
    T max_x;
    bool exist() { return L != -1; };
  };
  int n, log, size;
  vc<P> point;
  vc<Data> dat;

  Lower_ConvexHull_SegTree() {}
  Lower_ConvexHull_SegTree(int n) { build(n); }
  template <typename F>
  Lower_ConvexHull_SegTree(int n, F f) {
    build(n, f);
  }
  void build(int m) {
    n = m, log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    point.assign(m, P(0, 0));
    dat.assign(2 * size, Data(-1, -1, 0));
  }
  template <typename F>
  void build(int m, F f) {
    n = m, log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    point.assign(m, P(0, 0));
    dat.assign(2 * size, Data(-1, -1, 0));
    FOR(i, m) {
      auto [exist, x, y] = f(i);
      point[i] = P(x, y);
      dat[size + i] = (exist ? Data(i, i, x) : Data(-1, -1, x));
    }
    FOR_R(i, 1, size) update(i);
  }

  void set(int i, bool exist, T x, T y) {
    point[i] = {x, y};
    dat[size + i] = (exist ? Data(i, i, x) : Data(-1, -1, x));
    i += size;
    while (i > 1) i /= 2, update(i);
  }

  // 中：1, 境界：0, 外：-1
  int side(T x, T y) {
    if (!dat[1].exist) return -1;
    P a(x, y);
    int p = 1;
    while (1) {
      down_while_trivial(p);
      P L = point[dat[p].L], R = point[dat[p].R];
      if (a < L) { p = 2 * p + 0; }
      elif (a == L) { return 0; }
      elif (L < a && a < R) { return -ccw(L, a, R); }
      elif (R == a) { return 0; }
      else {
        p = 2 * p + 1;
      }
      if (p >= 2 * size) return -1;
    }
  }
  i128 min_dot(T a, T b) { return min_dot_at(1, a, b); }
  i128 min_dot(int L, int R, T a, T b) {
    L += size, R += size;
    i128 ANS = infty<i128>;
    while (L < R) {
      if (L & 1) chmin(ANS, min_dot_at(L++, a, b));
      if (R & 1) chmin(ANS, min_dot_at(--R, a, b));
      L /= 2, R /= 2;
    }
    return ANS;
  }

  // 同一座標の点があると unique されたりされなかったりするはず？
  vc<int> get_hull() {
    vc<int> res;
    // closed range
    auto dfs = [&](auto& dfs, int p, int lo, int hi) -> void {
      if (!dat[p].exist() || hi < lo) return;
      down_while_trivial(p);
      if (size <= p) {
        res.eb(p - size);
        return;
      }
      if (!(dat[p].L < hi)) return dfs(dfs, 2 * p + 0, lo, hi);
      if (!(lo < dat[p].R)) return dfs(dfs, 2 * p + 1, lo, hi);
      dfs(dfs, 2 * p + 0, lo, dat[p].L);
      dfs(dfs, 2 * p + 1, dat[p].R, hi);
    };
    dfs(dfs, 1, 0, n - 1);
    return res;
  }

private:
  // A,B,C は昇順. 同一座標の点はタイブレイクする.
  int ccw(P A, P B, P C) {
    auto [x1, y1] = B - A;
    auto [x2, y2] = C - B;
    if (x1 == 0) y1 = 1;
    if (x2 == 0) y2 = 1;
    i128 d = i128(x1) * y2 - i128(x2) * y1;
    return (d != 0 ? (d > 0 ? 1 : -1) : 0);
  }

  inline void down_while_trivial(int& p) {
    while (p < size) {
      if (!dat[2 * p + 0].exist()) p = 2 * p + 1;
      elif (!dat[2 * p + 1].exist()) p = 2 * p + 0;
      else return;
    }
  }

  void update(int i) {
    assert(1 <= i && i < size);
    if (!dat[2 * i + 0].exist()) { dat[i] = dat[2 * i + 1]; }
    elif (!dat[2 * i + 1].exist()) { dat[i] = dat[2 * i + 0]; }
    else {
      dat[i].max_x = dat[2 * i + 1].max_x;
      tie(dat[i].L, dat[i].R) = find_bridge(i);
    }
  }

  pair<int, int> find_bridge(int i) {
    int p = 2 * i + 0, q = 2 * i + 1;
    while (1) {
      down_while_trivial(p), down_while_trivial(q);
      if (size <= p && size <= q) break;
      P A = point[dat[p].L], B = point[dat[p].R];
      P C = point[dat[q].L], D = point[dat[q].R];
      constexpr int ccw_thresh = (ALLOW_180 ? 0 : 1);
      if (p >= size) {
        q = (ccw(B, C, D) < ccw_thresh ? 2 * q + 1 : 2 * q + 0);
      }
      elif (q >= size) {
        p = (ccw(A, B, C) < ccw_thresh ? 2 * p + 0 : 2 * p + 1);
      }
      elif (ccw(A, B, C) < ccw_thresh) { p = 2 * p + 0; }
      elif (ccw(B, C, D) < ccw_thresh) { q = 2 * q + 1; }
      else {
        ll x1 = A.x, x2 = B.x, x3 = C.x, x4 = D.x;
        ll y1 = A.y, y2 = B.y, y3 = C.y, y4 = D.y;
        ll num
            = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - x4 * y3);
        ll den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (den == 0 || num <= dat[p].max_x * den)
          p = 2 * p + 1;
        else
          q = 2 * q + 0;
      }
    }
    return {p - size, q - size};
  }

  i128 min_dot_at(int p, T a, T b) {
    assert(b >= 0);
    if (!dat[p].exist) return infty<i128>;
    while (1) {
      down_while_trivial(p);
      if (size <= p) break;
      i128 x1 = point[dat[p].L].dot(a, b), x2 = point[dat[p].R].dot(a, b);
      if (x1 <= x2) p = 2 * p + 0;
      if (x1 > x2) p = 2 * p + 1;
    }
    return dat[p].L.dot(a, b);
  }
};
