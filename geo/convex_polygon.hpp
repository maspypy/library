
template <typename T>
struct ConvexPolygon {
  using P = Point<T>;
  int n;
  vc<P> point;

  ConvexPolygon(vc<P> point) : n(len(point)), point(point) { assert(n >= 1); }

  // 比較関数 comp(i,j)
  template <typename F>
  int periodic_min_comp(F comp) {
    int L = 0, M = n, R = n + n;
    while (1) {
      if (R - L == 2) break;
      int L1 = (L + M) / 2, R1 = (M + R + 1) / 2;
      if (comp(L1, M)) { R = M, M = L1; }
      elif (comp(R1, M)) { L = M, M = R1; }
      else {
        L = L1, R = R1;
      }
    }
    return M % n;
  }

  int nxt_idx(int i) { return (i + 1 == n ? 0 : i + 1); }
  int prev_idx(int i) { return (i == 0 ? n - 1 : i - 1); }

  // 中：1, 境界：0, 外：-1
  // int side(P p) {}

  pair<int, T> min_dot(P p) {
    int idx = periodic_min_comp([&](int i, int j) -> bool {
      return point[i % n].dot(p) < point[j % n].dot(p);
    });
    return {idx, point[idx].dot(p)};
  }
  pair<int, T> max_dot(P p) {
    int idx = periodic_min_comp([&](int i, int j) -> bool {
      return point[i % n].dot(p) > point[j % n].dot(p);
    });
    return {idx, point[idx].dot(p)};
  }
  // pair<int, int> visible_range(P p) {}
};