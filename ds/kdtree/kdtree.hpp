template <typename XY>
struct KDTree {
  // 小数も考慮すると、閉で持つ設計方針になる。ただし、クエリはいつもの半開を使う
  vc<tuple<XY, XY, XY, XY>> closed_range;
  // 同じ座標の点も集約しないようにして、座標ごとに unique なデータを使う
  vc<int> dat;
  int n;

  KDTree(vc<XY> xs, vc<XY> ys) : n(len(xs)) {
    int log = 0;
    while ((1 << log) < n) ++log;
    dat.assign(1 << (log + 1), -1);
    closed_range.resize(1 << (log + 1));
    vc<int> vs(n);
    iota(all(vs), 0);
    build(1, xs, ys, vs);
  }

  // [xl, xr) x [yl, yr)
  vc<int> collect_rect(XY xl, XY xr, XY yl, XY yr, int max_size = -1) {
    assert(xl <= xr && yl <= yr);
    if (max_size == -1) max_size = n;
    vc<int> res;
    rect_rec(1, xl, xr, yl, yr, res, max_size);
    return res;
  }

  // 計算量保証なし、点群がランダムなら O(logN)
  // N = Q = 10^5 で、約 1 秒
  int nearest_neighbor_search(XY x, XY y) {
    pair<int, XY> res = {-1, INF<XY>};
    nns_rec(1, x, y, res);
    assert(res.fi != -1);
    return res.fi;
  }

private:
  void build(int idx, vc<XY> xs, vc<XY> ys, vc<int> vs, bool divx = true) {
    int n = len(xs);
    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];
    xmin = ymin = INF<XY>;
    xmax = ymax = -INF<XY>;

    FOR(i, n) {
      auto x = xs[i], y = ys[i];
      chmin(xmin, x), chmax(xmax, x), chmin(ymin, y), chmax(ymax, y);
    }
    if (n == 1) {
      dat[idx] = vs[0];
      return;
    }

    int m = n / 2;
    vc<int> I(n);
    iota(all(I), 0);
    if (divx) {
      nth_element(I.begin(), I.begin() + m, I.end(),
                  [xs](int i, int j) { return xs[i] < xs[j]; });
    } else {
      nth_element(I.begin(), I.begin() + m, I.end(),
                  [ys](int i, int j) { return ys[i] < ys[j]; });
    }
    xs = rearrange(xs, I), ys = rearrange(ys, I), vs = rearrange(vs, I);
    build(2 * idx + 0, {xs.begin(), xs.begin() + m},
          {ys.begin(), ys.begin() + m}, {vs.begin(), vs.begin() + m}, !divx);
    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},
          {vs.begin() + m, vs.end()}, !divx);
  }

  void rect_rec(int i, XY x1, XY x2, XY y1, XY y2, vc<int>& res, int ms) {
    if (len(res) == ms) return;
    auto& [xmin, xmax, ymin, ymax] = closed_range[i];
    if (x2 <= xmin || xmax < x1) return;
    if (y2 <= ymin || ymax < y1) return;
    if (dat[i] != -1) {
      res.eb(dat[i]);
      return;
    }
    rect_rec(2 * i + 0, x1, x2, y1, y2, res, ms);
    rect_rec(2 * i + 1, x1, x2, y1, y2, res, ms);
  }

  XY best_dist_squared(int i, XY x, XY y) {
    auto& [xmin, xmax, ymin, ymax] = closed_range[i];
    XY dx = x - clamp(x, xmin, xmax);
    XY dy = y - clamp(y, ymin, ymax);
    return dx * dx + dy * dy;
  }

  void nns_rec(int i, XY x, XY y, pair<int, XY>& res) {
    XY d = best_dist_squared(i, x, y);
    if (d >= res.se) return;
    if (dat[i] != -1) {
      res = {dat[i], d};
      return;
    }
    XY d0 = best_dist_squared(2 * i + 0, x, y);
    XY d1 = best_dist_squared(2 * i + 1, x, y);
    if (d0 < d1) {
      nns_rec(2 * i + 0, x, y, res), nns_rec(2 * i + 1, x, y, res);
    } else {
      nns_rec(2 * i + 1, x, y, res), nns_rec(2 * i + 0, x, y, res);
    }
  }
};
