#pragma once

constexpr u32 mod_pow_constexpr(u64 a, u64 n, u32 mod) {
  a %= mod;
  u64 res = 1;
  FOR(32) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod, n /= 2;
  }
  return res;
}

template <typename T, u32 p0, u32 p1>
T CRT2(u64 a0, u64 a1) {
  static_assert(p0 < p1);
  static constexpr u64 x0_1 = mod_pow_constexpr(p0, p1 - 2, p1);
  u64 c = (a1 - a0 + p1) * x0_1 % p1;
  return a0 + c * p0;
}

template <typename T, u32 p0, u32 p1, u32 p2>
T CRT3(u64 a0, u64 a1, u64 a2) {
  static_assert(p0 < p1 && p1 < p2);
  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2, p1);
  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);
  static constexpr u64 p01 = u64(p0) * p1;
  u64 c = (a1 - a0 + p1) * x1 % p1;
  u64 ans_1 = a0 + c * p0;
  c = (a2 - ans_1 % p2 + p2) * x2 % p2;
  return T(ans_1) + T(c) * T(p01);
}

template <typename T, u32 p0, u32 p1, u32 p2, u32 p3>
T CRT4(u64 a0, u64 a1, u64 a2, u64 a3) {
  static_assert(p0 < p1 && p1 < p2 && p2 < p3);
  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2, p1);
  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);
  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3 * p2 % p3, p3 - 2, p3);
  static constexpr u64 p01 = u64(p0) * p1;
  u64 c = (a1 - a0 + p1) * x1 % p1;
  u64 ans_1 = a0 + c * p0;
  c = (a2 - ans_1 % p2 + p2) * x2 % p2;
  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);
  c = (a3 - ans_2 % p3 + p3) * x3 % p3;
  return T(ans_2) + T(c) * T(p01) * T(p2);
}

template <typename T, u32 p0, u32 p1, u32 p2, u32 p3, u32 p4>
T CRT5(u64 a0, u64 a1, u64 a2, u64 a3, u64 a4) {
  static_assert(p0 < p1 && p1 < p2 && p2 < p3 && p3 < p4);
  static constexpr u64 x1 = mod_pow_constexpr(p0, p1 - 2, p1);
  static constexpr u64 x2 = mod_pow_constexpr(u64(p0) * p1 % p2, p2 - 2, p2);
  static constexpr u64 x3 = mod_pow_constexpr(u64(p0) * p1 % p3 * p2 % p3, p3 - 2, p3);
  static constexpr u64 x4 = mod_pow_constexpr(u64(p0) * p1 % p4 * p2 % p4 * p3 % p4, p4 - 2, p4);
  static constexpr u64 p01 = u64(p0) * p1;
  static constexpr u64 p23 = u64(p2) * p3;
  u64 c = (a1 - a0 + p1) * x1 % p1;
  u64 ans_1 = a0 + c * p0;
  c = (a2 - ans_1 % p2 + p2) * x2 % p2;
  u128 ans_2 = ans_1 + c * static_cast<u128>(p01);
  c = static_cast<u64>(a3 - ans_2 % p3 + p3) * x3 % p3;
  u128 ans_3 = ans_2 + static_cast<u128>(c * p2) * p01;
  c = static_cast<u64>(a4 - ans_3 % p4 + p4) * x4 % p4;
  return T(ans_3) + T(c) * T(p01) * T(p23);
}
