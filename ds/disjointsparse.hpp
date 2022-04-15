template <class Monoid>
struct DisjointSparse {
  using X = typename Monoid::value_type;
  using value_type = X;
  int n, log;
  vc<vc<X>> dat;

  DisjointSparse(vc<X>& A) : n(len(A)) {
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

  void debug() {
    print("disjoint sparse table");
    FOR(i, log) print(dat[i]);
  }
};