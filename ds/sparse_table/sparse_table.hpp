
// 冪等なモノイドであることを仮定。disjoint sparse table より x 倍高速
template <class Monoid>
struct Sparse_Table {
  using MX = Monoid;
  using X = typename MX::value_type;
  int n, log;
  vvc<X> dat;

  Sparse_Table() {}
  Sparse_Table(int n) { build(n); }
  template <typename F>
  Sparse_Table(int n, F f) {
    build(n, f);
  }
  Sparse_Table(const vc<X>& v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> X { return MX::unit(); });
  }
  void build(const vc<X>& v) {
    build(len(v), [&](int i) -> X { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    n = m, log = 1;
    while ((1 << log) < n) ++log;
    dat.resize(log);
    dat[0].resize(n);
    FOR(i, n) dat[0][i] = f(i);

    FOR(i, log - 1) {
      dat[i + 1].resize(len(dat[i]) - (1 << i));
      FOR(j, len(dat[i]) - (1 << i)) {
        dat[i + 1][j] = MX::op(dat[i][j], dat[i][j + (1 << i)]);
      }
    }
  }

  X prod(int L, int R) {
    if (L == R) return MX::unit();
    if (R == L + 1) return dat[0][L];
    int k = topbit(R - L - 1);
    return MX::op(dat[k][L], dat[k][R - (1 << k)]);
  }

  template <class F>
  int max_right(const F check, int L) {
    assert(0 <= L && L <= n && check(MX::unit()));
    if (L == n) return n;
    int ok = L, ng = n + 1;
    while (ok + 1 < ng) {
      int k = (ok + ng) / 2;
      bool bl = check(prod(L, k));
      if (bl) ok = k;
      if (!bl) ng = k;
    }
    return ok;
  }

  template <class F>
  int min_left(const F check, int R) {
    assert(0 <= R && R <= n && check(MX::unit()));
    if (R == 0) return 0;
    int ok = R, ng = -1;
    while (ng + 1 < ok) {
      int k = (ok + ng) / 2;
      bool bl = check(prod(k, R));
      if (bl) ok = k;
      if (!bl) ng = k;
    }
    return ok;
  }
};
