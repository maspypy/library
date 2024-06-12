template <typename T, bool isMin>
struct CHT_monotone {
  static_assert(is_same_v<T, ll> || std::is_floating_point_v<T>);
  struct Line {
    T a, b;
    int idx;
  };
  deque<Line> H;
  int nxt_idx = 0;

  CHT_monotone() = default;

  bool empty() const { return H.empty(); }
  void clear() { H.clear(); }

  inline int sgn(T x) { return x == 0 ? 0 : (x < 0 ? -1 : 1); }
  using D = long double;
  inline bool check(const Line &a, const Line &b, const Line &c) {
    if (b.b == a.b || c.b == b.b)
      return sgn(b.a - a.a) * sgn(c.b - b.b) >= sgn(c.a - b.a) * sgn(b.b - a.b);
    // return (b.a-a.a)*(c.b-b.b) >= (b.b-a.b)*(c.a-b.a);
    return D(b.a - a.a) * sgn(c.b - b.b) / D(abs(b.b - a.b))
           >= D(c.a - b.a) * sgn(b.b - a.b) / D(abs(c.b - b.b));
  }

  void add(T a, T b, int idx = -1) {
    if (idx == -1) { idx = nxt_idx++; }
    if (!isMin) a *= -1, b *= -1;
    Line L{a, b, idx};
    if (empty()) {
      H.emplace_front(L);
      return;
    }
    if (H.front().a <= a) {
      if (H.front().a == a) {
        if (H.front().b <= b) return;
        H.pop_front();
      }
      while (H.size() >= 2 && check(L, H.front(), H[1])) { H.pop_front(); }
      H.emplace_front(L);
    } else {
      assert(a <= H.back().a);
      if (H.back().a == a) {
        if (H.back().b <= b) return;
        H.pop_back();
      }
      while (H.size() >= 2 && check(H[H.size() - 2], H.back(), L)) H.pop_back();
      H.emplace_back(L);
    }
  }

  inline T get_y(const Line &a, const T &x) { return a.a * x + a.b; }

  pair<T, int> query(T x) {
    assert(!empty());
    int l = -1, r = H.size() - 1;
    while (l + 1 < r) {
      int m = (l + r) >> 1;
      if (get_y(H[m], x) >= get_y(H[m + 1], x))
        l = m;
      else
        r = m;
    }
    if (isMin) return {get_y(H[r], x), H[r].idx};
    return {-get_y(H[r], x), H[r].idx};
  }

  pair<T, int> query_monotone_inc(T x) {
    assert(!empty());
    while (H.size() >= 2 && get_y(H.front(), x) >= get_y(H[1], x))
      H.pop_front();
    if (isMin) return {get_y(H.front(), x), H.front().idx};
    return {-get_y(H.front(), x), H.front().idx};
  }

  pair<T, int> query_monotone_dec(T x) {
    assert(!empty());
    while (H.size() >= 2 && get_y(H.back(), x) >= get_y(H[H.size() - 2], x))
      H.pop_back();
    if (isMin) return {get_y(H.back(), x), H.back().idx};
    return {-get_y(H.back(), x), H.back().idx};
  }
};