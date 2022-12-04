#pragma once

template <class Monoid>
struct DisjointSparse {
  using MX = Monoid;
  using X = typename MX::value_type;
  int n, log;
  vvc<X> dat;

  DisjointSparse() {}
  DisjointSparse(int n) { build(n); }
  template <typename F>
  DisjointSparse(int n, F f) {
    build(n, f);
  }
  DisjointSparse(const vc<X>& v) { build(v); }

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
    dat[0].reserve(n);
    FOR(i, n) dat[0].eb(f(i));
    FOR(i, 1, log) {
      auto& v = dat[i];
      v = dat[0];
      int b = 1 << i;
      for (int m = b; m <= n; m += 2 * b) {
        int L = m - b, R = min(n, m + b);
        FOR3_R(j, L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);
        FOR3(j, m, R - 1) v[j + 1] = MX::op(v[j], v[j + 1]);
      }
    }
  }

  X prod(int L, int R) {
    if (L == R) return MX::unit();
    --R;
    if (L == R) return dat[0][L];
    int k = 31 - __builtin_clz(L ^ R);
    return MX::op(dat[k][L], dat[k][R]);
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