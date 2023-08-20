#include "mod/mod_inv.hpp"
#include "nt/coprime_factorization.hpp"

// 非負最小解を mod new_mod で返す (garner)
template <typename T>
i128 CRT(vc<T> vals, vc<T> mods, ll new_mod = -1, bool coprime = false) {
  int n = len(vals);
  FOR(i, n) {
    vals[i] = ((vals[i] %= mods[i]) >= 0 ? vals[i] : vals[i] + mods[i]);
  }
  if (!coprime) {
    auto [basis, pfs] = coprime_factorization<T>(mods);
    int k = len(basis);
    vc<int> max_exp(k);
    FOR(i, n) {
      for (auto&& [pid, exp]: pfs[i]) { chmax(max_exp[pid], exp); }
    }
    vc<T> xx(k), mm(k);
    FOR(i, n) {
      for (auto&& [pid, exp]: pfs[i]) {
        if (exp == max_exp[pid]) {
          mm[pid] = 1;
          FOR(exp) mm[pid] *= basis[pid];
          xx[pid] = vals[i] % mm[pid];
        }
      }
    }
    FOR(i, n) {
      for (auto&& [pid, exp]: pfs[i]) {
        T mod = 1;
        FOR(exp) mod *= basis[pid];
        if (xx[pid] % mod != vals[i] % mod) return -1;
      }
    }
    swap(vals, xx);
    swap(mods, mm);
    n = len(vals);
  }

  vc<ll> cfs(n);
  FOR(i, n) {
    ll a = vals[i];
    ll prod = 1;
    FOR(j, i) {
      a = (a + i128(cfs[j]) * (mods[i] - prod)) % mods[i];
      prod = i128(prod) * mods[j] % mods[i];
    }
    cfs[i] = mod_inv(prod, mods[i]) * i128(a) % mods[i];
  }
  i128 ret = 0, prod = 1;
  FOR(i, n) {
    ret += prod * cfs[i], prod *= mods[i];
    if (new_mod != -1) { ret %= new_mod, prod %= new_mod; }
  }
  return ret;
}