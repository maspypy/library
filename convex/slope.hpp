struct Slope_Trick {
  static constexpr ll LMIN = numeric_limits<ll>::lowest() / 2;
  static constexpr ll RMAX = numeric_limits<ll>::max() / 2;
  pq<ll> que_l;
  pqg<ll> que_r;

  ll add_l, add_r;
  i128 min_f; // INF を足し引きしても壊れないようにする

  Slope_Trick() : add_l(0), add_r(0), min_f(0) {}
  Slope_Trick(vc<ll> left, vc<ll> right)
      : que_l(all(left)), que_r(all(right)), add_l(0), add_r(0), min_f(0) {}

  int size() { return len(que_l) + len(que_r); }
  tuple<ll, ll, i128> get_min() { return {top_L(), top_R(), min_f}; }

  void add_const(ll a) { min_f += a; }

  // O(|a| log N)
  void add_linear(ll a, ll b) {
    min_f += b;
    FOR(max<int>(a, 0)) {
      ll x = pop_L();
      min_f += x;
      push_R(x);
    }
    FOR(max<int>(-a, 0)) {
      ll x = pop_R();
      min_f -= x;
      push_L(x);
    }
  }

  // (a-x)+
  void add_a_minus_x(ll a) {
    min_f += max<ll>(0, a - top_R());
    push_R(a), push_L(pop_R());
  }
  // (x-a)+
  void add_x_minus_a(ll a) {
    min_f += max<ll>(0, top_L() - a);
    push_L(a), push_R(pop_L());
  }

  // |x-a|
  void add_abs(ll a) {
    add_a_minus_x(a);
    add_x_minus_a(a);
  }

  // 増加側を消して、減少側のみにする
  void clear_right() { que_r = pqg<ll>(); }
  // 減少側を消して、増加側のみにする
  void clear_left() { que_l = pq<ll>(); }
  void shift(const ll &a) { add_l += a, add_r += a; }

  // g(x) = min_{x-b <= y <= x-a} f(y)
  void sliding_window_minimum(const ll &a, const ll &b) {
    add_l += a, add_r += b;
  }

  // O(size log(size))
  i128 eval(ll x) {
    i128 y = min_f;
    pq<ll> que_l_copy = que_l;
    pqg<ll> que_r_copy = que_r;
    while (len(que_l_copy)) { y += max<ll>(0, (POP(que_l_copy) + add_l) - x); }
    while (len(que_r_copy)) { y += max<ll>(0, x - (POP(que_r_copy) + add_r)); }
    return y;
  }

  void push_R(const ll &x) { que_r.emplace(x - add_r); }
  void push_L(const ll &x) { que_l.emplace(x - add_l); }
  ll top_R() {
    if (que_r.empty()) que_r.emplace(RMAX);
    return que_r.top() + add_r;
  }
  ll top_L() {
    if (que_l.empty()) que_l.emplace(LMIN);
    return que_l.top() + add_l;
  }
  ll pop_R() {
    ll res = top_R();
    que_r.pop();
    return res;
  }
  ll pop_L() {
    ll res = top_L();
    que_l.pop();
    return res;
  }

  void debug() {
    vi left, right;
    pq<ll> que_l_copy = que_l;
    pqg<ll> que_r_copy = que_r;
    while (len(que_l_copy)) { left.eb(POP(que_l_copy) + add_l); }
    while (len(que_r_copy)) { right.eb(POP(que_r_copy) + add_r); }
    sort(all(left));
    sort(all(right));
    print("min_f", min_f, "left", left, "right", right);
  }
};