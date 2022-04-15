template <typename Val, int LOG = 20>
struct HashMapLL {
  int N;
  ll* keys;
  Val* vals;
  vc<int> IDS;
  bitset<1 << LOG> used;
  const int shift;
  const uint64_t r = 11995408973635179863ULL;
  HashMapLL()
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

  bool contain(const ll& key) {
    int i = index(key);
    return used[i] && keys[i] == key;
  }

  bool count(const ll& key) {
    int i = index(key);
    return used[i] && keys[i] == key;
  }

  void reset() {
    for (auto&& i: IDS) used[i] = 0;
    IDS.clear();
  }
};

template <typename KEY, typename VAL>
struct HashMap {
  HashMapLL<VAL, 20> MP;
  function<ll(KEY)> f;
  HashMap(function<ll(KEY)> f) : MP(), f(f) {}
  int index(const KEY& key) { return MP.index(f(key)); }

  VAL& operator[](const KEY& key) { return MP[f(key)]; }

  bool contain(const KEY& key) { return MP.contain(f(key)); }

  bool count(const KEY& key) { return MP.count(f(key)); }

  void reset() { MP.reset(); }
};
