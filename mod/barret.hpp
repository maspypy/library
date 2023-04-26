#pragma once

struct Barret_Reduction {
  using i64 = long long;
  using u64 = unsigned long long;
  using u128 = __uint128_t;
  int m, s;
  u64 x;
  constexpr Barret_Reduction() : m(), s(), x() {}
  constexpr Barret_Reduction(int n)
      : m(n), s(std::__lg(n - 1)), x(((u128(1) << (s + 64)) + n - 1) / n) {}
  constexpr friend u64 operator/(u64 n, const Barret_Reduction& d) {
    return (u128(n) * d.x >> d.s) >> 64;
  }
  constexpr friend int operator%(u64 n, const Barret_Reduction& d) {
    return n - n / d * d.m;
  }
  constexpr pair<i64, int> divmod(u64 n) const {
    u64 q = n / *this;
    return {q, n - q * m};
  }
};
