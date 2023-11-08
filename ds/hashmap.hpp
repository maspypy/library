#pragma once

// u64 -> Val
template <typename Val, int LOG = 20, bool KEEP_IDS = false>
struct HashMap {
  static constexpr int N = (1 << LOG);
  u64* key;
  Val* val;
  vc<int> IDS;
  bitset<N> used;
  const int shift;
  const u64 r = 11995408973635179863ULL;
  HashMap() : key(new u64[N]), val(new Val[N]), shift(64 - LOG) {}
  u32 hash(u64 x) {
    static const u64 FIXED_RANDOM
        = std::chrono::steady_clock::now().time_since_epoch().count();
    return (u64(x + FIXED_RANDOM) * r) >> shift;
  }

  int index(const u64& k) {
    int i = 0;
    for (i = hash(k); used[i] && key[i] != k; (i += 1) &= (N - 1)) {}
    return i;
  }

  Val& operator[](const u64& k) {
    int i = index(k);
    if (!used[i]) { set_used(i), key[i] = k, val[i] = Val{}; }
    return val[i];
  }

  Val get(const u64& k, Val default_value) {
    int i = index(k);
    if (!used[i]) return default_value;
    return val[i];
  }

  bool count(const u64& k) {
    int i = index(k);
    return used[i] && key[i] == k;
  }

  void set_used(int i) {
    used[i] = 1;
    if constexpr (KEEP_IDS) IDS.eb(i);
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
    for (auto&& i: IDS) f(key[i], val[i]);
  }
};
