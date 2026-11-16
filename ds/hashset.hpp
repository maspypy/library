
template <typename KEY>
struct HashSet {
  static_assert(is_same_v<KEY, u32> || is_same_v<KEY, u64>);

  // n は入れたいものの個数で ok
  HashSet(u32 n = 0) { build(n); }
  void build(u32 n) {
    u32 k = 8;
    while (k < n * 2) k *= 2;
    cap = k / 2, mask = k - 1;
    key.resize(k), used.assign(k, 0);
  }

  // size を保ったまま. size=0 にするときは build すること.
  void clear() {
    used.assign(len(used), 0);
    cap = (mask + 1) / 2;
  }
  int size() { return len(used) / 2 - cap; }

  int index(const KEY& k) {
    int i = 0;
    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {
    }
    return i;
  }

  bool operator[](const KEY& k) {
    int i = index(k);
    return used[i];
  }

  void insert(const KEY& k) {
    int i = index(k);
    if (used[i]) return;
    if (cap == 0) {
      extend();
      i = index(k);
    }
    used[i] = true;
    key[i] = k;
    --cap;
  }

  // f(key, val)
  template <typename F>
  void enumerate_all(F f) {
    bool end = false;
    FOR(i, len(used)) {
      if (used[i]) f(key[i], end);
      if (end) break;
    }
  }

 private:
  u32 cap, mask;
  vc<KEY> key;
  vc<bool> used;

  u32 hash(KEY x) {
    static const u64 FIXED_RANDOM =
        std::chrono::steady_clock::now().time_since_epoch().count();
    x += FIXED_RANDOM;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return (x ^ (x >> 31)) & mask;
  }

  void extend() {
    vc<KEY> dat;
    dat.reserve(len(used) / 2 - cap);
    FOR(i, len(used)) {
      if (used[i]) dat.eb(key[i]);
    }
    build(2 * len(dat));
    for (auto& a : dat) (*this).insert(a);
  }
};
