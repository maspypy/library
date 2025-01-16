// x=INF で小さくなる（傾きが小さい）ものが back
// O(QlogQ) func call or O(Q) func call + O(Q) find
// https://contest.ucup.ac/contest/1893/problem/9737
// push front 使ったことなし
template <typename F, bool MINIMIZE>
struct CHT_monotone_F {
  using T = typename F::value_type;
  ll L, R;

  // func, L, R
  vc<tuple<F, ll, ll>> dat;
  CHT_monotone_F(ll L, ll R) : L(L), R(R) {}

  void push_back(F f) {
    auto find = [&](F f, F g, ll a, ll b) -> ll { return binary_search([&](ll x) -> bool { return select_right(f, g, x); }, b, a, 0); };
    push_back_with_find(f, find);
  }

  void push_front(F f) {
    auto find = [&](F f, F g, ll a, ll b) -> ll { return binary_search([&](ll x) -> bool { return select_right(f, g, x); }, b, a, 0); };
    push_front_with_find(f, find);
  }

  // find(f,g,a,b): f(a)<=g(a), g(b)<f(b) のとき g(x)<f(x) となる最小の x
  template <typename FIND>
  void push_back_with_find(F g, FIND find) {
    while (1) {
      if (dat.empty()) {
        dat.eb(g, L, R);
        break;
      }
      auto [f, a, b] = dat.back();
      if (select_right(f, g, a)) {
        dat.pop_back();
        if (len(dat)) get<2>(dat.back()) = b;
        continue;
      }
      if (!select_right(f, g, b - 1)) { break; }
      ll x = find(f, g, a, b - 1);
      get<2>(dat.back()) = x;
      dat.emplace_back(g, x, b);
      break;
    }
  }

  // find(f,g,a,b): f(a)<=g(a), g(b)<f(b) のとき g(x)<f(x) となる最小の x
  template <typename FIND>
  void push_front_with_find(F f, FIND find) {
    while (1) {
      if (dat.empty()) {
        dat.eb(f, L, R);
        break;
      }
      auto [g, a, b] = dat.front();
      if (!select_right(f, g, b - 1)) {
        dat.pop_front();
        if (len(dat)) get<1>(dat.front()) = L;
        continue;
      }
      if (select_right(f, g, a)) break;
      ll x = find(f, g, a, b - 1);
      get<1>(dat.front()) = x;
      dat.emplace_front(f, a, x);
      break;
    }
  }

  T query(ll x) {
    assert(!dat.empty());
    int k = binary_search([&](int i) -> bool { return get<1>(dat[i]) <= x; }, 0, len(dat));
    auto [f, a, b] = dat[k];
    assert(a <= x && x < b);
    return f(x);
  }

  int last = 0;
  T query_monotone(ll x) {
    assert(!dat.empty());
    chmin(last, len(dat) - 1);
    while (1) {
      auto [f, l, r] = dat[last];
      if (x < l) --last;
      elif (r <= x)++ last;
      else break;
    }
    auto [f, l, r] = dat[last];
    return f(x);
  }

private:
  bool select_right(F L, F R, ll x) { return (MINIMIZE ? !(L(x) < R(x)) : (L(x) < R(x))); }
};
