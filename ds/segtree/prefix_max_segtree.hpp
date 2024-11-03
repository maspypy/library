
/*
key[0],...,key[n-1] がある
モノイドの列 x[0],...,x[n-1] がある
query(l,r): l から見えるところに対する monoid product
見える: key[i]==max(key[0]...key[i])
Qlog^2n
https://qoj.ac/contest/1540/problem/8338
*/
template <typename KEY_TYPE, typename Monoid>
struct Prefix_Max_SegTree {
  using MX = Monoid;
  using KEY = KEY_TYPE;
  using X = typename MX::value_type;
  int n, size, log;
  struct Data {
    KEY max;
    X prod, rprod; // rprod はこの区間だけで計算したときの右側
  };

  vc<Data> dat;

  Prefix_Max_SegTree() {}
  Prefix_Max_SegTree(int n) { build(n); }
  template <typename F>
  Prefix_Max_SegTree(int n, F f) {
    build(n, f);
  }
  Prefix_Max_SegTree(const vc<X>& v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> pair<KEY, X> { return {-infty<int>, MX::unit()}; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m, log = 1;
    while ((1 << log) < n) ++log;
    size = 1 << log;
    dat.assign(size << 1, {-infty<int>, MX::unit(), MX::unit()});
    FOR(i, n) {
      auto [k, x] = f(i);
      dat[size + i] = {k, x, MX::unit()};
    }
    FOR_R(i, 1, size) update(i);
  }

  void set(int i, pair<KEY, X> p) {
    int k = p.fi;
    X x = p.se;
    i += size;
    dat[i] = {k, x, MX::unit()};
    while (i > 1) i /= 2, update(i);
  }

  X prod_all() { return dat[1].prod; }
  X prod(int L, int R) {
    KEY k = -infty<KEY>;
    vc<int> suff;
    L += size, R += size;
    X prod = MX::unit();
    while (L < R) {
      if (L & 1) { prod = MX::op(prod, dfs(L, k)), chmax(k, dat[L].max), ++L; }
      if (R & 1) { suff.eb(--R); }
      L /= 2, R /= 2;
    }
    reverse(all(suff));
    for (auto& v: suff) { prod = MX::op(prod, dfs(v, k)), chmax(k, dat[v].max); }
    return prod;
  }

  pair<KEY, X> get(int i) { return {dat[size + i].max, dat[size + i].prod}; }
  pair<vc<KEY>, vc<X>> get_all() {
    vc<KEY> key(n);
    vc<X> x(n);
    FOR(i, n) key[i] = dat[size + i].max, x[i] = dat[size + i].prod;
    return {key, x};
  }

private:
  void update(int i) {
    assert(0 <= i && i < size);
    dat[i].max = max(dat[2 * i + 0].max, dat[2 * i + 1].max);
    dat[i].rprod = dfs(2 * i + 1, dat[2 * i + 0].max);
    dat[i].prod = MX::op(dat[2 * i + 0].prod, dat[i].rprod);
  }

  X dfs(int v, KEY k) {
    // prefix に k を置いた場合の subtree(v) での値
    if (size <= v) { return (k <= dat[v].max ? dat[v].prod : MX::unit()); }
    if (k <= dat[2 * v + 0].max) { return MX::op(dfs(2 * v + 0, k), dat[v].rprod); }
    return dfs(2 * v + 1, k);
  }
};
