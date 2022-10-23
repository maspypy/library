
template <int LOG = 20>
struct HashSetLL {
  int N;
  int sz;
  ll* keys;
  bitset<1 << LOG> used;
  const int shift;
  const uint64_t r = 11995408973635179863ULL;
  HashSetLL() : N(1 << LOG), sz(0), keys(new ll[N]), shift(64 - __lg(N)) {}
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

  void insert(const ll& key) {
    int i = index(key);
    if (!used[i]) used[i] = 1, keys[i] = key, ++sz;
  }

  void erase(const ll& key) {
    int i = index(key);
    used[i] = 0;
    --sz;
  }

  bool count(const ll& key) {
    int i = index(key);
    return used[i] && keys[i] == key;
  }

  int size() { return sz; }
};