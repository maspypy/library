struct Bit_Vector {
  int n;
  bool prepared = 0;
  vc<pair<u64, u32>> dat;
  Bit_Vector(int n = 0) : n(n) { dat.assign((n + 127) >> 6, {0, 0}); }
  void set(int i) {
    assert(!prepared && (0 <= i && i < n));
    dat[i >> 6].fi |= u64(1) << (i & 63);
  }
  void reset() {
    fill(all(dat), pair<u64, u32>{0, 0});
    prepared = 0;
  }
  void build() {
    prepared = 1;
    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);
  }
  // [0, k) 内の 1 の個数
  bool operator[](int i) { return dat[i >> 6].fi >> (i & 63) & 1; }
  int count_prefix(int k, bool f = true) {
    assert(prepared);
    auto [a, b] = dat[k >> 6];
    int ret = b + popcnt(a & ((u64(1) << (k & 63)) - 1));
    return (f ? ret : k - ret);
  }
  int count(int L, int R, bool f = true) { return count_prefix(R, f) - count_prefix(L, f); }
  string to_string() {
    string ans;
    FOR(i, n) ans += '0' + (dat[i / 64].fi >> (i % 64) & 1);
    return ans;
  }
};
