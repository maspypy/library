template <typename Monoid>
struct Xor_DisjointSparse {
  using MX = Monoid;
  using X = typename Monoid::value_type;
  int log;
  vvc<X> dat;

  Xor_DisjointSparse() {}
  Xor_DisjointSparse(int n) { build(n); }
  template <typename F>
  Xor_DisjointSparse(int n, F f) {
    build(n, f);
  }
  Xor_DisjointSparse(const vc<X>& v) { build(v); }

  void build(int m) {
    build(m, [](int i) -> X { return MX::unit(); });
  }
  void build(const vc<X>& v) {
    build(len(v), [&](int i) -> X { return v[i]; });
  }
  template <typename F>
  void build(int m, F f) {
    log = 0;
    while ((1 << log) < m) ++log;
    assert(m == (1 << log));
    // 各 k, i に対して、prod_{0<=j<2^k} A[i^j] を持つ
    dat.resize(log + 1);
    dat[0].reserve(1 << log);
    FOR(i, 1 << log) dat[0].eb(f(i));
    FOR(k, log) {
      dat[k + 1].assign(1 << log, MX::unit());
      FOR(i, 1 << log) {
        dat[k + 1][i] = MX::op(dat[k][i], dat[k][i ^ (1 << k)]);
      }
    }
  }

  // calculate prod_{l<=i<r} A[x xor i], in O(log N) time.
  X prod(int l, int r, int xor_val) {
    X xl = xr = MX::unit();
    FOR(k, log + 1) {
      if (l >= r) break;
      if (l & 1 << k) {
        xl = MX::op(xl, dat[k][l ^ xor_val]);
        l += (1 << k);
      }
      if (r & 1 << k) {
        r -= (1 << k);
        xr = MX::op(dat[k][r ^ xor_val], xr);
      }
    }
    return MX::op(xl, xr);
  }
};