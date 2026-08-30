u64 mod_pow_u64(u64 a, u64 n) {
  u64 x = 1;
  while (n) {
    if (n & 1) x *= a;
    a *= a, n >>= 1;
  }
  return x;
}