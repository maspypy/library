// https://codeforces.com/blog/entry/86731)
// chmin(A[x],ax+b), A[x]+=ax+b, get A[x]
template <bool MINIMIZE>
struct Extended_LiChao_Tree_1 {
  // 入出力以外では minimize している
  struct F {
    ll a, b;
    F(ll a = 0, ll b = 0) : a(a), b(b) {}
    ll operator()(ll x) { return a * x + b; }
    void add(F &other) {
      if (b == infty<ll> || other.b == infty<ll>) {
        a = 0, b = infty<ll>;
      } else {
        a += other.a, b += other.b;
      }
    }
  };

  vi X;
  vc<F> dat, lazy;
  int n, log, size;

  Extended_LiChao_Tree_1(vi X_) : X(X_) {
    UNIQUE(X);
    n = len(X), log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, F(0, infty<ll>));
    lazy.assign(size << 1, F(0, 0));
  }

  // O(logN). f(x) := min(f(x), ax+b).
  void chmin_line(ll a, ll b) {
    static_assert(MINIMIZE);
    chmin_line_rec(1, F(a, b), 0, n);
  }

  // O(logN). f(x) := max(f(x), ax+b).
  void chmax_line(ll a, ll b) {
    static_assert(!MINIMIZE);
    chmin_line_rec(1, F(-a, -b), 0, n);
  }

  // O(log^2N). f(x) := min(f(x), ax+b) for L<=x<R.
  // index ではなくて X[] の範囲.
  void chmin_segment(ll L, ll R, ll a, ll b) {
    static_assert(MINIMIZE);
    chmin_segment_rec(1, LB(X, L), LB(X, R), F(a, b), 0, n);
  }

  // O(log^2N). f(x) := max(f(x), ax+b) for L<=x<R.
  // index ではなくて X[] の範囲.
  void chmax_segment(ll L, ll R, ll a, ll b) {
    static_assert(!MINIMIZE);
    chmin_segment_rec(1, LB(X, L), LB(X, R), F(-a, -b), 0, n);
  }

  // O(1). f(x) := f(x)+ax+b.
  void add_line(ll a, ll b) {
    if (!MINIMIZE) a = -a, b = -b;
    add_segment_rec(1, 0, n, F(a, b), 0, n);
  }

  // O(log^2N). f(x) := f(x)+ax+b for L<=x<R.
  // index ではなくて X[] の範囲.
  void add_segment(ll L, ll R, ll a, ll b) {
    if (!MINIMIZE) a = -a, b = -b;
    add_segment_rec(1, LB(X, L), LB(X, R), F(a, b), 0, n);
  }

  ll query(ll x) {
    int idx = LB(X, x);
    assert(0 <= idx && idx < n && X[idx] == x);
    ll ans = query_rec(1, idx, 0, n, F(0, 0));
    return MINIMIZE ? ans : -ans;
  }

private:
  void push(int i) {
    dat[2 * i + 0].add(lazy[i]), lazy[2 * i + 0].add(lazy[i]);
    dat[2 * i + 1].add(lazy[i]), lazy[2 * i + 1].add(lazy[i]);
    lazy[i] = F(0, 0);
  }

  void chmin_segment_rec(int i, ll xl, ll xr, F f, ll node_l, ll node_r) {
    chmax(xl, node_l), chmin(xr, node_r);
    if (xl >= xr) return;
    if (node_l < xl || xr < node_r) {
      ll node_m = (node_l + node_r) / 2;
      push(i);
      chmin_segment_rec(2 * i + 0, xl, xr, f, node_l, node_m);
      chmin_segment_rec(2 * i + 1, xl, xr, f, node_m, node_r);
      return;
    }
    chmin_line_rec(i, f, node_l, node_r);
  }

  void chmin_line_rec(int i, F f, ll node_l, ll node_r) {
    F g = dat[i];
    ll fl = f(X[node_l]), fr = f(X[node_r - 1]);
    ll gl = g(X[node_l]), gr = g(X[node_r - 1]);
    if (fl <= gl && fr <= gr) {
      dat[i] = f;
      return;
    }
    if (fl >= gl && fr >= gr) { return; }
    ll node_m = (node_l + node_r) / 2;
    ll fm = f(X[node_m]), gm = g(X[node_m]);
    push(i);
    if (fm < gm && fl < gl) dat[i] = f, chmin_line_rec(2 * i + 1, g, node_m, node_r);
    elif (fm < gm && fl >= gl) dat[i] = f, chmin_line_rec(2 * i + 0, g, node_l, node_m);
    elif (fm >= gm && gl < fl) chmin_line_rec(2 * i + 1, f, node_m, node_r);
    elif (fm >= gm && gl >= fl) chmin_line_rec(2 * i + 0, f, node_l, node_m);
  }

  void add_segment_rec(int i, ll xl, ll xr, F f, ll node_l, ll node_r) {
    chmax(xl, node_l), chmin(xr, node_r);
    if (xl >= xr) return;
    if (node_l < xl || xr < node_r) {
      ll node_m = (node_l + node_r) / 2;
      push(i);
      chmin_line_rec(2 * i + 0, dat[i], node_l, node_m);
      chmin_line_rec(2 * i + 1, dat[i], node_m, node_r);
      dat[i] = F(0, infty<ll>);
      add_segment_rec(2 * i + 0, xl, xr, f, node_l, node_m);
      add_segment_rec(2 * i + 1, xl, xr, f, node_m, node_r);
      return;
    }
    dat[i].add(f), lazy[i].add(f);
  }

  ll query_rec(int i, ll x, ll node_l, ll node_r, F laz) {
    ll res = dat[i](X[x]);
    if (res < infty<ll>) res += laz(X[x]);
    ll node_m = (node_l + node_r) / 2;
    laz.add(lazy[i]);
    if (node_r == node_l + 1) return res;
    if (x < node_m) { chmin(res, query_rec(2 * i + 0, x, node_l, node_m, laz)); }
    if (x >= node_m) { chmin(res, query_rec(2 * i + 1, x, node_m, node_r, laz)); }
    return res;
  }
};
