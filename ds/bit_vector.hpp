struct Bit_Vector {
  vc<pair<u32, u32>> dat;
  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }

  void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }

  void build() {
    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);
  }

  // [0, k) 内の 1 の個数
  int rank(int k, bool f = 1) {
    auto [a, b] = dat[k >> 5];
    int ret = b + popcnt(a & ((u32(1) << (k & 31)) - 1));
    return (f ? ret : k - ret);
  }
};
