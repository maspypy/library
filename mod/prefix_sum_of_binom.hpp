template <typename mint>
struct Prefix_Sum_Of_Binom {
  static constexpr u32 mod = mint::get_mod();
  static constexpr u64 ADD = -(u64(-1) / mod * mod);
  const int MAX_N;
  const int B;
  vc<mint> POW;
  vvc<mint> dat;

  Prefix_Sum_Of_Binom(int MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N + 1)) {
    POW.resize(MAX_N + 1, mint(1));
    FOR(i, MAX_N) POW[i + 1] = POW[i] + POW[i];
    int K = ceil(MAX_N, B + B) + 2;
    dat.resize(K);
    FOR(k, 0, K) {
      // [0, kB] での closed sum
      vc<mint>& f = dat[k];
      f.resize(MAX_N + 1 - k * B);
      int m = k * B;
      f[0] = POW[m] * fact<mint>(m);
      FOR(i, MAX_N - m) {
        f[i + 1] = f[i] + f[i] - fact<mint>(i + m) * fact_inv<mint>(i);
      }
    }
  }

  // \sum_{k=0}^m binom(n,k)
  mint query(int n, int m) {
    assert(0 <= m && m <= n + 1);
    if (m == 0) return mint(0);
    if (m + m > n + 1) return POW[n] - query(n, n + 1 - m);
    --m;
    int a = m / B;

    if (m <= a * B + B / 2) {
      u64 t = 0;
      FOR(i, a * B + 1, m + 1) {
        u64 add = u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n - i).val);
        if (__builtin_uaddll_overflow(t, add, &t)) t += ADD;
      }
      return get(n, a) + mint(t) * fact<mint>(n);
    } else {
      u64 t = 0;
      FOR(i, m + 1, (a + 1) * B + 1) {
        u64 add = u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n - i).val);
        if (__builtin_uaddll_overflow(t, add, &t)) t += ADD;
      }
      return get(n, a + 1) - mint(t) * fact<mint>(n);
    }
    return 0;
  }

  mint get(int n, int k) {
    if (n <= k * B) return POW[n];
    return dat[k][n - k * B] * fact_inv<mint>(k * B);
  }
};