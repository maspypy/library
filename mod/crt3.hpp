
constexpr u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {
  a %= mod;
  u64 res = 1;
  FOR(32) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod, n /= 2;
  }
  return res;
}

template <typename T, u32 p0, u32 p1, u32 p2>
T CRT3(u64 a0, u64 a1, u64 a2) {
  static_assert(p0 < p1 && p1 < p2);
  static constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);
  static constexpr u64 x01_2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);
  u64 c = (a1 - a0 + p1) * x0_1 % p1;
  u64 a = a0 + c * p0;
  c = (a2 - a % p2 + p2) * x01_2 % p2;
  return T(a) + T(c) * T(p0) * T(p1);
}
