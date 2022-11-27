#pragma once
#include "mod/fast_div.hpp"
#include "mod/mod_inv.hpp"
#include "nt/factor.hpp"

// 最小解を mod new_mod で返す
// 解なしなら -1 を返す
i128 CRT(vc<int> vals, vc<int> mods, ll new_mod = -1, bool coprime = false) {
  int n = len(vals);
  FOR(i, n) {
    vals[i] %= mods[i];
    if (vals[i] < 0) vals[i] += mods[i];
  }
  if (!coprime) {
    unordered_map<ll, vc<pi>> MP;
    FOR(i, n) {
      for (auto&& [p, e]: factor(mods[i])) {
        int mod = 1;
        FOR(e) mod *= p;
        MP[p].eb(vals[i] % mod, mod);
      }
    }
    vc<int> xx, mm;
    for (auto&& [p, dat]: MP) {
      int mod = 1;
      int val = 0;
      for (auto&& [x, m]: dat)
        if (chmax(mod, m)) val = x;
      for (auto&& [x, m]: dat)
        if ((val - x) % m != 0) return -1;
      xx.eb(val);
      mm.eb(mod);
    }
    swap(vals, xx);
    swap(mods, mm);
    n = len(vals);
  }

  vc<int> cfs(n);
  FOR(i, n) {
    auto mod = fast_div(mods[i]);
    ll a = vals[i];
    ll prod = 1;
    FOR(j, i) {
      a = (a + cfs[j] * (mods[i] - prod)) % mod;
      prod = prod * mods[j] % mod;
    }
    cfs[i] = mod_inv(prod, mods[i]) * a % mod;
  }
  i128 ret = 0;
  i128 prod = 1;
  FOR(i, n) {
    ret += prod * cfs[i];
    prod *= mods[i];
    if (new_mod != -1) {
      ret %= new_mod;
      prod %= new_mod;
    }
  }
  return ret;
}
