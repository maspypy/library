#include "mod/mod_inv.hpp"
#include "nt/coprime_factorization.hpp"
#include "nt/factor.hpp"
#include "mod/barrett.hpp"

// 非負最小解を mod new_mod で返す (garner)
template <typename T>
i128 CRT(vc<T> vals, vc<T> mods, ll new_mod = -1, bool coprime = false) {
  int n = len(vals);
  FOR(i, n) {
    vals[i] = ((vals[i] %= mods[i]) >= 0 ? vals[i] : vals[i] + mods[i]);
  }

  bool ng = 0;
  auto reduction_by_factor = [&]() -> void {
    unordered_map<T, pair<T, int>> MP;
    FOR(i, n) {
      for (auto&& [p, e]: factor(mods[i])) {
        T mod = 1;
        FOR(e) mod *= p;
        T val = vals[i] % mod;
        if (!MP.count(p)) {
          MP[p] = {mod, val % mod};
          continue;
        }
        auto& [mod1, val1] = MP[p];
        if (mod < mod1) swap(mod, mod1), swap(val, val1);
        if (val % mod1 != val1) {
          ng = 1;
          return;
        }
        MP[p] = {mod1, val1};
      }
    }
    mods.clear(), vals.clear();
    for (auto&& [p, x]: MP) {
      auto [mod, val] = x;
      mods.eb(mod), vals.eb(val);
    }
    n = len(vals);
  };
  auto reduction_by_coprime_factor = [&]() -> void {
    auto [basis, pfs] = coprime_factorization<T>(mods);
    int k = len(basis);
    vc<pair<T, int>> dat(k, {1, 0});
    FOR(i, n) {
      for (auto&& [pid, exp]: pfs[i]) {
        T mod = 1;
        FOR(exp) mod *= basis[pid];
        T val = vals[i] % mod;
        auto& [mod1, val1] = dat[pid];
        if (mod > mod1) swap(mod, mod1), swap(val, val1);
        if (val % mod1 != val1) {
          ng = 1;
          return;
        }
        dat[pid] = {mod1, val1};
      }
    }
    mods.clear(), vals.clear();
    for (auto&& [mod, val]: dat) { mods.eb(mod), vals.eb(val); }
    n = len(vals);
  };
  if (!coprime) {
    (n <= 10 ? reduction_by_coprime_factor() : reduction_by_factor());
  }

  if (ng) return -1;
  if (n == 0) return 0;

  vc<ll> cfs(n);
  if (MAX(mods) < (1LL << 31)) {
    FOR(i, n) {
      Barrett bt(mods[i]);
      ll a = vals[i], prod = 1;
      FOR(j, i) {
        a = bt.modulo(a + cfs[j] * (mods[i] - prod));
        prod = bt.mul(prod, mods[j]);
      }
      cfs[i] = bt.mul(mod_inv(prod, mods[i]), a);
    }
  } else {
    FOR(i, n) {
      ll a = vals[i], prod = 1;
      FOR(j, i) {
        a = (a + i128(cfs[j]) * (mods[i] - prod)) % mods[i];
        prod = i128(prod) * mods[j] % mods[i];
      }
      cfs[i] = mod_inv(prod, mods[i]) * i128(a) % mods[i];
    }
  }
  i128 ret = 0, prod = 1;
  FOR(i, n) {
    ret += prod * cfs[i], prod *= mods[i];
    if (new_mod != -1) { ret %= new_mod, prod %= new_mod; }
  }
  return ret;
}