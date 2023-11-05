#pragma once
#include "random/base.hpp"

// u64 -> Val
template <typename Val, int LOG = 20, bool KEEP_IDS = false>
struct HashMap {
  using P = pair<u64, Val>;
  int N;
  P* dat;
  vc<int> IDS;
  bitset<1 << LOG> used;
  const int shift;
  const u64 r = 11995408973635179863ULL;
  HashMap() : N(1 << LOG), dat(new P[N]), shift(64 - __lg(N)) {}
  int hash(ll x) {
    static const u64 FIXED_RANDOM
        = std::chrono::steady_clock::now().time_since_epoch().count();
    return (u64(x + FIXED_RANDOM) * r) >> shift;
  }

  int index(const u64& key) {
    int i = 0;
    for (i = hash(key); used[i] && dat[i].fi != key; (i += 1) &= (N - 1)) {}
    return i;
  }

  Val& operator[](const u64& key) {
    int i = index(key);
    if (!used[i]) {
      used[i] = 1, dat[i] = {key, Val{}};
      if constexpr (KEEP_IDS) IDS.eb(i);
    }
    return dat[i].se;
  }

  Val get(const u64& key, Val default_value) {
    int i = index(key);
    if (!used[i]) return default_value;
    return dat[i].se;
  }

  bool count(const u64& key) {
    int i = index(key);
    return used[i] && dat[i].fi == key;
  }

  void reset() {
    static_assert(KEEP_IDS);
    for (auto&& i: IDS) used[i] = 0;
    IDS.clear();
  }

  // f(key, val)
  template <typename F>
  void enumerate_all(F f) {
    static_assert(KEEP_IDS);
    for (auto&& i: IDS) f(dat[i].fi, dat[i].se);
  }
};
