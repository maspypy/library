#include "mod/primitive_root.hpp"
#include "mod/mod_inv.hpp"

struct Binomial_PrimePower {
  int p, e;
  int pp;
  int root;
  int ord;
  vc<int> exp;
  vc<int> log_fact;
  vc<int> power;
  Barrett bt_p, bt_pp;

  Binomial_PrimePower(int p, int e) : p(p), e(e), power(e + 1, 1) {
    FOR(i, e) power[i + 1] = power[i] * p;
    pp = power[e];
    bt_p = Barrett(p), bt_pp = Barrett(pp);
    vc<int> log;
    if (p == 2) {
      if (e <= 1) { return; }
      root = 5;
      ord = pp / 4;
      exp.assign(ord, 1);
      log.assign(pp, 0);
      FOR(i, ord - 1) { exp[i + 1] = (exp[i] * root) & (pp - 1); }
      FOR(i, ord) log[exp[i]] = log[pp - exp[i]] = i;
    } else {
      root = primitive_root(p);
      ord = pp / p * (p - 1);
      exp.assign(ord, 1);
      log.assign(pp, 0);
      FOR(i, ord - 1) { exp[i + 1] = bt_pp.mul(exp[i], root); }
      FOR(i, ord) log[exp[i]] = i;
    }
    log_fact.assign(pp, 0);
    FOR(i, 1, pp) {
      log_fact[i] = log_fact[i - 1] + log[i];
      if (log_fact[i] >= ord) log_fact[i] -= ord;
    }
  }

  int C(ll n, ll i) {
    assert(n >= 0);
    if (i < 0 || i > n) return 0;
    ll a = i, b = n - i;
    if (pp == 2) { return ((a & b) == 0 ? 1 : 0); }
    int log = 0, cnt_p = 0, sgn = 0;
    if (e > 1) {
      while (n && cnt_p < e) {
        auto [n1, nr1] = bt_pp.divmod(n);
        auto [a1, ar1] = bt_pp.divmod(a);
        auto [b1, br1] = bt_pp.divmod(b);
        log += log_fact[nr1] - log_fact[ar1] - log_fact[br1];
        if (p > 2) {
          sgn += (n1 & 1) + (a1 & 1) + (b1 & 1);
        } else {
          sgn += (((nr1 + 1) & 4) + ((ar1 + 1) & 4) + ((br1 + 1) & 4)) / 4;
        }
        n = bt_p.floor(n), a = bt_p.floor(a), b = bt_p.floor(b);
        cnt_p += n - a - b;
      }
    } else {
      while (n && cnt_p < e) {
        auto [n1, nr1] = bt_pp.divmod(n);
        auto [a1, ar1] = bt_pp.divmod(a);
        auto [b1, br1] = bt_pp.divmod(b);
        log += log_fact[nr1] - log_fact[ar1] - log_fact[br1];
        if (p > 2) {
          sgn += (n1 & 1) + (a1 & 1) + (b1 & 1);
        } else {
          sgn += ((nr1 + 1) >> 2 & 1) + ((ar1 + 1) >> 2 & 1)
                 + ((br1 + 1) >> 2 & 1);
        }
        n = n1, a = a1, b = b1;
        cnt_p += n - a - b;
      }
    }
    if (cnt_p >= e) return 0;
    log %= ord;
    if (log < 0) log += ord;
    int res = exp[log];
    if (sgn & 1) res = pp - res;
    return bt_pp.mul(power[cnt_p], res);
  }
};

struct Binomial {
  int mod;
  vc<Binomial_PrimePower> BPP;
  vc<int> crt_coef;
  Barrett bt;

  Binomial(int mod) : mod(mod), bt(mod) {
    for (auto&& [p, e]: factor(mod)) {
      int pp = 1;
      FOR(e) pp *= p;
      BPP.eb(Binomial_PrimePower(p, e));
      int other = mod / pp;
      crt_coef.eb(ll(other) * mod_inv(other, pp) % mod);
    }
  }

  int C(ll n, ll k) {
    assert(n >= 0);
    if (k < 0 || k > n) return 0;
    int ANS = 0;
    FOR(s, len(crt_coef)) {
      ANS = bt.modulo(ANS + u64(BPP[s].C(n, k)) * crt_coef[s]);
    }
    return ANS;
  }
};