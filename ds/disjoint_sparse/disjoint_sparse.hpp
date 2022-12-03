#pragma once

template <class Monoid>
struct Disjoint_Sparse {
  using X = typename Monoid::value_type;
  using value_type = X;
  int n, log;
  vc<vc<X>> dat;

  Disjoint_Sparse() {}
  Disjoint_Sparse(vc<X>& A) { build(A); }

  template <typename F>
  Disjoint_Sparse(int n, F f) {
    vc<X> A(n);
    FOR(i, n) A[i] = f(i);
    build(A);
  }

  void build(vc<X>& A) {
    n = len(A);
    log = 1;
    while ((1 << log) < n) ++log;
    dat.assign(log, A);

    FOR(i, log) {
      auto& v = dat[i];
      int b = 1 << i;
      for (int m = b; m <= n; m += 2 * b) {
        int L = m - b, R = min(n, m + b);
        FOR3_R(j, L + 1, m) v[j - 1] = Monoid::op(v[j - 1], v[j]);
        FOR3(j, m, R - 1) v[j + 1] = Monoid::op(v[j], v[j + 1]);
      }
    }
  }

  X prod(int L, int R) {
    if (L == R) return Monoid::unit();
    --R;
    if (L == R) return dat[0][L];
    int k = 31 - __builtin_clz(L ^ R);
    return Monoid::op(dat[k][L], dat[k][R]);
  }

  template <class F>
  int max_right(const F& check, int L) {
    assert(0 <= L && L <= n && check(Monoid::unit()));
    if (L == n) return n;
    int ok = L, ng = n + 1;
    while (ok + 1 < ng) {
      int k = (ok + ng) / 2;
      if (check(prod(L, k))) {
        ok = k;
      } else {
        ng = k;
      }
    }
    return ok;
  }

  template <class F>
  int min_left(const F& check, int R) {
    assert(0 <= R && R <= n && check(Monoid::unit()));
    if (R == 0) return 0;
    int ok = R, ng = -1;
    while (ng + 1 < ok) {
      int k = (ok + ng) / 2;
      if (check(prod(k, R))) {
        ok = k;
      } else {
        ng = k;
      }
    }
    return ok;
  }

  void debug() {
    print("disjoint sparse table");
    FOR(i, log) print(dat[i]);
  }
};