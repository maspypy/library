struct fast_div {
  // Min25 https://judge.yosupo.jp/submission/46090
  // 同じ定数で何度も除算するときの高速化に使える
  using i64 = long long;
  using u64 = unsigned long long;
  using u128 = __uint128_t;
  constexpr fast_div() : m(), s(), x() {}
  constexpr fast_div(int n)
      : m(n), s(std::__lg(n - 1)), x(((u128(1) << (s + 64)) + n - 1) / n) {}
  constexpr friend u64 operator/(u64 n, const fast_div& d) {
    return (u128(n) * d.x >> d.s) >> 64;
  }
  constexpr friend int operator%(u64 n, const fast_div& d) {
    return n - n / d * d.m;
  }
  constexpr std::pair<i64, int> divmod(u64 n) const {
    u64 q = n / *this;
    return {q, n - q * m};
  }

  int m;
  int s;
  u64 x;
};
