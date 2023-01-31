#pragma once
#include "random/base.hpp"

// u64 -> Val
template <typename Val, int LOG = 20>
struct HashMap {
  int N;
  u64* keys;
  Val* vals;
  vc<int> IDS;
  bitset<1 << LOG> used;
  const int shift;
  const u64 r = 11995408973635179863ULL;
  HashMap()
      : N(1 << LOG), keys(new u64[N]), vals(new Val[N]), shift(64 - __lg(N)) {}
  int hash(ll x) {
    static const u64 FIXED_RANDOM
        = std::chrono::steady_clock::now().time_since_epoch().count();
    return (u64(x + FIXED_RANDOM) * r) >> shift;
  }

  int index(const u64& key) {
    int i = 0;
    for (i = hash(key); used[i] && keys[i] != key; (i += 1) &= (N - 1)) {}
    return i;
  }

  // [] した時点で要素は作られる
  Val& operator[](const u64& key) {
    int i = index(key);
    if (!used[i]) IDS.eb(i), used[i] = 1, keys[i] = key, vals[i] = Val{};
    return vals[i];
  }

  Val get(const u64& key, Val default_value) {
    int i = index(key);
    if (!used[i]) return default_value;
    return vals[i];
  }

  bool count(const u64& key) {
    int i = index(key);
    return used[i] && keys[i] == key;
  }

  void reset() {
    for (auto&& i: IDS) used[i] = 0;
    IDS.clear();
  }

  // f(key, val)
  template <typename F>
  void enumerate_all(F f) {
    for (auto&& i: IDS) f(keys[i], vals[i]);
  }
};
