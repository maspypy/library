struct Bit_Vector {
  int n;
  vc<pair<u32, u32>> dat;
  Bit_Vector(int n) : n(n) { dat.assign((n + 63) >> 5, {0, 0}); }
  void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }
  void reset() { fill(all(dat), pair<u32, u32>{0, 0}); }
  void build() {
    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);
  }
  // [0, k) 内の 1 の個数
  int count(int k, bool f) {
    auto [a, b] = dat[k >> 5];
    int ret = b + popcnt(a & ((u32(1) << (k & 31)) - 1));
    return (f ? ret : k - ret);
  }
  int count(int L, int R, bool f) { return count(R, f) - count(L, f); }
  string to_string() {
    string ans;
    FOR(i, n) ans += '0' + (dat[i / 32].fi >> (i % 32) & 1);
    return ans;
  }
};
