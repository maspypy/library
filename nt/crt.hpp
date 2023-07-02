#pragma once
#include "mod/barrett.hpp"
#include "mod/mod_inv.hpp"
#include "nt/factor.hpp"

// 最小解を mod new_mod で返す
// 解なしなら -1 を返す
// long のときのテスト不十分（例：https://codeforces.com/contest/338/problem/D）
template <typename T>
i128 CRT(vc<T> vals, vc<T> mods, ll new_mod = -1, bool coprime = false) {
  int n = len(vals);
  FOR(i, n) {
    vals[i] %= mods[i];
    if (vals[i] < 0) vals[i] += mods[i];
  }
  if (!coprime) {
    unordered_map<ll, vc<pi>> MP;
    FOR(i, n) {
      for (auto&& [p, e]: factor(mods[i])) {
        ll mod = 1;
        FOR(e) mod *= p;
        MP[p].eb(vals[i] % mod, mod);
      }
    }
    vc<T> xx, mm;
    for (auto&& [p, dat]: MP) {
      ll mod = 1;
      ll val = 0;
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

  vc<ll> cfs(n);
  FOR(i, n) {
    Barrett bt(mods[i]);
    ll a = vals[i];
    ll prod = 1;
    FOR(j, i) {
      a = (a + i128(cfs[j]) * (mods[i] - prod)) % mods[i];
      prod = i128(prod) * mods[j] % mods[i];
    }
    cfs[i] = mod_inv(prod, mods[i]) * i128(a) % mods[i];
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
