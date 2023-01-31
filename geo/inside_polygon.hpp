// https://qoj.ac/problem/5443
// 線分上に頂点や辺が来ることは許容
template <typename T>
bool inside_polygon(Segment<T> S, vc<Point<T>>& dat) {
  using P = Point<T>;
  int N = len(dat);
  int cnt = 0;
  P A = S.A, B = S.B;
  auto PREV = [&](int i) -> int { return (i == 0 ? N : i) - 1; };
  auto NEXT = [&](int i) -> int { return (i == N - 1 ? 0 : i + 1); };
  FOR(i, N) {
    P p = dat[i], q = dat[NEXT(i)], r = dat[PREV(i)];
    int a = ccw(A, B, p);
    int b = ccw(A, B, q);
    int c = ccw(A, B, r);
    if (a * b == -1) {
      Segment pq(p, q);
      auto L = pq.to_Line();
      T x = L.eval(A), y = L.eval(B);
      if (x < y) { x = -x, y = -y; }
      if (x <= 0) ++cnt;
      if (0 < x && x < x - y) return 0;
    }
    if (a == 0) {
      if (b != c && (b * c < 0 || ccw(p, q, r) > 0)) {
        T t = (p - A).dot(B - A), x = (B - A).dot(B - A);
        if (t <= 0) ++cnt;
        if (0 < t && t < x) return 0;
      }
    }
  }
  return cnt % 2 == 1;
}