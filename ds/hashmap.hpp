#pragma once
#include "random/base.hpp"

// long long -> Val
template <typename Val, int LOG = 20>
struct HashMap {
  int N;
  ll* keys;
  Val* vals;
  vc<int> IDS;
  bitset<1 << LOG> used;
  const int shift;
  const uint64_t r = 11995408973635179863ULL;
  HashMap()
      : N(1 << LOG), keys(new ll[N]), vals(new Val[N]), shift(64 - __lg(N)) {}
  int hash(ll x) {
    static const uint64_t FIXED_RANDOM
        = std::chrono::steady_clock::now().time_since_epoch().count();
    return (uint64_t(x + FIXED_RANDOM) * r) >> shift;
  }

  int index(const ll& key) {
    int i = 0;
    for (i = hash(key); used[i] && keys[i] != key; (i += 1) &= (N - 1)) {}
    return i;
  }

  Val& operator[](const ll& key) {
    int i = index(key);
    if (!used[i]) IDS.eb(i), used[i] = 1, keys[i] = key, vals[i] = Val{};
    return vals[i];
  }

  Val get(const ll& key, Val default_value) {
    int i = index(key);
    if (!used[i]) return default_value;
    return vals[i];
  }

  bool count(const ll& key) {
    int i = index(key);
    return used[i] && keys[i] == key;
  }

  void reset() {
    for (auto&& i: IDS) used[i] = 0;
    IDS.clear();
  }

  vc<pair<ll, Val>> items() {
    vc<pair<ll, Val>> res;
    res.reserve(len(IDS));
    for (auto&& i: IDS) res.eb(keys[i], vals[i]);
    return res;
  }
};
