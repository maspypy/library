u64 naive_nim_product(u64 x, u64 y, int k = 6) {
  if (x == 0 || y == 0) return 0;
  if (x == 1) return y;
  if (y == 1) return x;
  int B = 1 << (k - 1);
  u64 mask = (1ULL << B) - 1;
  u64 a = x >> B, b = x & mask;
  u64 c = y >> B, d = y & mask;
  tie(a, b, c) = mt(naive_nim_product(a, c, k - 1),
                    naive_nim_product(a ^ b, c ^ d, k - 1),
                    naive_nim_product(b, d, k - 1));
  b = a ^ b ^ c;
  return (a << B) ^ naive_nim_product(1ULL << (B - 1), a, k - 1) ^ (b << B) ^ c;
}

u64 nim_product(u64 x, u64 y) {
  static bool prepared = false;
  // x * y, 256以下
  // 2^a * 2^b * x, 8, 8, 256
  static u64 memo1[256][256];
  static u64 memo2[8][8][256];
  if (!prepared) {
    prepared = true;
    FOR(x, 256) FOR(y, 256) memo1[x][y] = naive_nim_product(x, y, 4);
    FOR(a, 8) FOR(b, 8) {
      u64 v = naive_nim_product(1ULL << (8 * a), 1ULL << (8 * b));
      FOR(x, 256) memo2[a][b][x] = naive_nim_product(v, x);
    }
  } // end prepare

  u64 v = 0;
  FOR(a, 8) FOR(b, 8) {
    v ^= memo2[a][b][memo1[(x >> (8 * a)) & 255][(y >> (8 * b)) & 255]];
  }
  return v;
}