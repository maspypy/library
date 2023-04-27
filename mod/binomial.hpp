#include "nt/factor.hpp"
#include "mod/barrett.hpp"

// mod を素因数分解して階乗を前計算 → 二項係数クエリ
// O(mod) 時間前計算
struct Binomial {
  int mod;
  vc<pair<ll, int>> pf;
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
      FOR(e) pp[s] *= p;
      auto& F = fact[s];
      // mod pp での fact の周期
      F.resize(pp[s] * 2);
      F[0] = 1;
      Barrett bt_p(p);
      Barrett bt_pp(pp[s]);
      FOR(x, 1, len(F)) {
        if (bt_p.modulo(x) == 0)
          F[x] = F[x - 1];
        else
          F[x] = bt_p.mul(F[x - 1], x);
      }
      int other = bt_pp.floor(mod);
      while (bt_pp.modulo(crt_coef[s]) != 1) crt_coef[s] += other;
    }
  }

  int mod_pow(int a, int n, Barrett& bt) {
    ll x = 1, p = a;
    while (n) {
      if (n & 1) x = bt.mul(x, p);
      p = bt.mul(p, p);
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
      Barrett bt_p(p);
      Barrett bt_pp(pp[s]);
      Barrett bt_len(len(fact[s]));
      auto get_fact = [&](ll n) -> pi {
        // p^e * x として、(e, x mod pp) を返す
        ll x = 1, e = 0;
        while (n) {
          x = bt_pp.mul(x, fact[s][bt_len.modulo(n)]);
          n = bt_p.floor(n);
          e += n;
        }
        return {e, x};
      };
      auto a = get_fact(n);
      auto b = get_fact(k);
      auto c = get_fact(n - k);
      ll e = a.fi - b.fi - c.fi;
      ll x = a.se;
      ll y = bt_pp.mul(b.se, c.se);
      int phi = pp[s] - pp[s] / pf[s].fi;
      x = bt_pp.mul(x, mod_pow(y, phi - 1, bt_pp));
      FOR(min<int>(e, pf[s].se)) x *= p;
      ANS += bt_pp.modulo(x) * crt_coef[s];
    }
    return ANS % mod;
  }
};
