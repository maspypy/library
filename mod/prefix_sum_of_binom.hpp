// \sum_{k=0}^m binom(n,k) を求めるクエリにオンラインで答える
template <typename mint>
struct Prefix_Sum_Of_Binom {
  const int MAX_N;
  const int B;
  vvc<mint> dat;

  Prefix_Sum_Of_Binom(int MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N + 1)) {
    int K = ceil(MAX_N, B + B) + 2;
    dat.resize(K);
    FOR(k, 1, K) {
      // kB 個の和
      vc<mint>& f = dat[k];
      f.resize(MAX_N + 1);
      f[0] = mint(1);
      FOR(i, MAX_N) f[i + 1] = f[i] + f[i] - C<mint>(i, k * B - 1);
    }
  }

  // \sum_{k=0}^m binom(n,k)
  mint query(int n, int m) {
    assert(0 <= m && m <= n + 1);
    if (m == 0) return mint(0);
    if (m + m > n + 1) return mint(2).pow(n) - query(n, n + 1 - m);
    int a = m / B;
    mint t = 0;
    if (m <= a * B + (B / 2)) {
      FOR(i, a * B, m) t += fact_inv<mint>(i) * fact_inv<mint>(n - i);
      return (a == 0 ? mint(0) : dat[a][n]) + t * fact<mint>(n);
    } else {
      FOR(i, m, (a + 1) * B) t += fact_inv<mint>(i) * fact_inv<mint>(n - i);
      return dat[a + 1][n] - t * fact<mint>(n);
    }
    return 0;
  }
};