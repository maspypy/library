#include "ds/offline_query/mo.hpp"

template <typename mint>
struct Prefix_Sum_of_Binom {
  static constexpr u32 mod = mint::get_mod();
  const int MAX_N;
  const int B;
  vc<mint> POW;
  vvc<mint> dat;

  Prefix_Sum_of_Binom(int MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N + 1)) {
    assert(MAX_N >= 0);
    int K = ceil(MAX_N, B + B) + 2;
    int p = max(MAX_N, K * B);
    POW.assign(p + 1, mint(1));
    FOR(i, p) POW[i + 1] = POW[i] + POW[i];
    dat.resize(K);
    FOR(k, 0, K) {
      // [0, kB] での closed sum
      vc<mint>& f = dat[k];
      if (MAX_N + 1 - k * B <= 0) continue;
      f.resize(MAX_N + 1 - k * B);
      int m = k * B;
      f[0] = POW[m] * fact<mint>(m);
      FOR(i, MAX_N - m) {
        f[i + 1] = f[i] + f[i] - fact<mint>(i + m) * fact_inv<mint>(i);
      }
    }
  }

  // \sum_{k=0}^{m-1} binom(n,k)
  mint query(int n, int m) {
    assert(0 <= m);
    chmin(m, n + 1);
    if (m == 0) return mint(0);
    if (m + m > n + 1) return POW[n] - query(n, n + 1 - m);
    --m;
    int a = m / B;

    if (m <= a * B + B / 2) {
      u128 t = 0;
      FOR(i, a * B + 1, m + 1) {
        t += u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n - i).val);
      }
      return _get(n, a) + mint::raw(t % mod) * fact<mint>(n);
    } else {
      u128 t = 0;
      FOR(i, m + 1, (a + 1) * B + 1) {
        t += u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n - i).val);
      }
      return _get(n, a + 1) - mint::raw(t % mod) * fact<mint>(n);
    }
    return 0;
  }

 private:
  mint _get(int n, int k) {
    if (n <= k * B) return POW[n];
    return dat[k][n - k * B] * fact_inv<mint>(k * B);
  }
};

template <typename mint>
struct Prefix_Sum_of_Binom_Offline {
  vc<pair<int, int>> query;

  void add(int n, int m) { query.eb(n, m); }

  vc<mint> calc() {
    int Q = len(query);
    vc<mint> ANS(Q);
    auto I = Mo::get_mo_order(query);
    int n = 0, m = 0;
    mint ans = 0;
    mint inv2 = inv<mint>(2);
    for (auto& i : I) {
      auto [nn, mm] = query[i];
      while (n < nn) {
        ans = ans + ans - C<mint>(n, m - 1);
        n++;
      }
      while (n > nn) {
        ans += C<mint>(n - 1, m - 1);
        ans *= inv2;
        --n;
      }
      while (m < mm) {
        ans += C<mint>(n, m++);
      }
      while (m > mm) {
        ans -= C<mint>(n, --m);
      }
      ANS[i] = ans;
    }
    return ANS;
  }
};
