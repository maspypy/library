template <typename mint>
struct Prefix_Sum_Of_Binom {
  const int MAX_N;
  const int B;
  vvc<mint> dat;

  Prefix_Sum_Of_Binom(int MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N + 1)) {
    int K = ceil(MAX_N, B + B) + 2;
    dat.resize(K);
    FOR(k, 0, K) {
      // [0, kB] での closed sum
      vc<mint>& f = dat[k];
      f.resize(MAX_N + 1);
      int m = k * B;
      f[0] = fact<mint>(m);
      FOR(i, MAX_N) {
        f[i + 1] = f[i] + f[i]
                   - (i >= m ? fact<mint>(i) * fact_inv<mint>(i - m) : 0);
      }
    }
  }

  // \sum_{k=0}^m binom(n,k)
  mint query(int n, int m) {
    assert(0 <= m && m <= n + 1);
    if (m == 0) return mint(0);
    if (m + m > n + 1) return mint(2).pow(n) - query(n, n + 1 - m);
    --m;
    int a = m / B;
    if (m <= a * B + B / 2) {
      mint x = dat[a][n] * fact_inv<mint>(a * B);
      mint t = 0;
      FOR(i, a * B + 1, m + 1) t += fact_inv<mint>(i) * fact_inv<mint>(n - i);
      return x + t * fact<mint>(n);
    } else {
      mint x = dat[a + 1][n] * fact_inv<mint>((a + 1) * B);
      mint t = 0;
      FOR(i, m + 1, (a + 1) * B + 1)
      t += fact_inv<mint>(i) * fact_inv<mint>(n - i);
      return x - t * fact<mint>(n);
    }
    return 0;
  }
};
