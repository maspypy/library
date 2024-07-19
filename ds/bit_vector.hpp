struct Bit_Vector {
  int n;
  vc<pair<u64, u32>> dat;
  Bit_Vector(int n) : n(n) { dat.assign((n + 127) >> 6, {0, 0}); }
  void set(int i) { dat[i >> 6].fi |= u64(1) << (i & 63); }
  void reset() { fill(all(dat), pair<u64, u32>{0, 0}); }
  void build() {
    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);
  }
  // [0, k) 内の 1 の個数
  int count(int k, bool f) {
    auto [a, b] = dat[k >> 6];
    int ret = b + popcnt(a & ((u64(1) << (k & 63)) - 1));
    return (f ? ret : k - ret);
  }
  int count(int L, int R, bool f) { return count(R, f) - count(L, f); }
  string to_string() {
    string ans;
    FOR(i, n) ans += '0' + (dat[i / 64].fi >> (i % 64) & 1);
    return ans;
  }
};
