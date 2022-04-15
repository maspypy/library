#include "nt/factor.hpp"
#include "mod/fast_div.hpp"
struct Binomial {
  // mod を素因数分解して階乗を前計算 → 二項係数クエリ
  // O(mod) 時間前計算
  int mod;
  vc<pi> pf;
  vc<int> pp;
  vc<vc<int>> fact;
  vc<int> crt_coef;

  Binomial(int mod) : mod(mod) {
    pf = factor(mod);
    int S = len(pf);
    pp.resize(S);
    fact.resize(S);
    crt_coef.resize(S);
    FOR(s, S) {
      auto [p, e] = pf[s];
      pp[s] = 1;
      FOR_(e) pp[s] *= p;
      auto& F = fact[s];
      // mod pp での fact の周期
      F.resize(pp[s] * 2);
      F[0] = 1;
      fast_div fd_p(p);
      fast_div fd_pp(pp[s]);
      FOR3(x, 1, len(F)) {
        if (x % fd_p == 0)
          F[x] = F[x - 1];
        else
          F[x] = F[x - 1] * x % fd_pp;
      }
      int other = mod / fd_pp;
      while (crt_coef[s] % fd_pp != 1) crt_coef[s] += other;
    }
  }

  int mod_pow(int a, int n, fast_div d) {
    ll x = 1, p = a;
    while (n) {
      if (n & 1) x = x * p % d;
      p = p * p % d;
      n >>= 1;
    }
    return x;
  }

  int C(ll n, ll k) {
    assert(n >= 0);
    if (k < 0 || k > n) return 0;
    ll ANS = 0;
    FOR(s, len(pf)) {
      int p = pf[s].fi;
      fast_div fd_p(p);
      fast_div fd_pp(pp[s]);
      fast_div fd_len(len(fact[s]));
      auto get_fact = [&](ll n) -> pi {
        // p^e * x として、(e, x mod pp) を返す
        ll x = 1, e = 0;
        while (n) {
          x = x * fact[s][n % fd_len] % fd_pp;
          n = n / fd_p;
          e += n;
        }
        return {e, x};
      };
      auto a = get_fact(n);
      auto b = get_fact(k);
      auto c = get_fact(n - k);
      ll e = a.fi - b.fi - c.fi;
      ll x = a.se;
      ll y = b.se * c.se % fd_pp;
      int phi = pp[s] - pp[s] / pf[s].fi;
      x = x * mod_pow(y, phi - 1, fd_pp) % fd_pp;
      FOR_(min(e, pf[s].se)) x *= p;
      x = x % fd_pp;
      ANS += x * crt_coef[s];
    }
    return ANS % mod;
  }
};
