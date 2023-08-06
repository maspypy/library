#pragma once

// https : // yosupo.hatenablog.com/entry/2023/08/06/181942
struct modint61 {
  using u128 = unsigned __int128;
  static constexpr u64 MOD = (1ULL << 61) - 1;
  static constexpr u64 MOD8 = MOD * 8;
  u64 val;
  constexpr modint61() : val(0ULL) {}
  constexpr modint61(u32 x) : val(x) {}
  constexpr modint61(u64 x) : val(x % mod) {}
  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod)) : x) {}
  constexpr modint61(ll x)
      : val(((x %= static_cast<ll>(mod)) < 0) ? (x + static_cast<ll>(mod))
                                              : x) {}
  static constexpr u64 get_mod() { return mod; }
  modint61 &operator+=(const modint61 &a) {
    val = ((val += a.val) >= mod) ? (val - mod) : val;
    return *this;
  }
  modint61 &operator-=(const modint61 &a) {
    val = ((val -= a.val) >= mod) ? (val + mod) : val;
    return *this;
  }
  modint61 &operator*=(const modint61 &a) {
    const unsigned __int128 y = static_cast<unsigned __int128>(val) * a.val;
    val = (y >> 61) + (y & mod);
    val = (val >= mod) ? (val - mod) : val;
    return *this;
  }
  modint61 &operator/=(const modint61 &a) { return (*this *= a.inverse()); }
  modint61 operator+(const modint61 &p) const { return modint61(*this) += p; }
  modint61 operator-(const modint61 &p) const { return modint61(*this) -= p; }
  modint61 operator*(const modint61 &p) const { return modint61(*this) *= p; }
  modint61 operator/(const modint61 &p) const { return modint61(*this) /= p; }
  bool operator==(const modint61 &p) const { return val == p.val; }
  bool operator!=(const modint61 &p) const { return val != p.val; }
  modint61 inverse() const {
    ll a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint61(u);
  }
  modint61 pow(ll n) const {
    assert(n >= 0);
    modint61 ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul, n >>= 1;
    }
    return ret;
  }

  u64 mul(u64 a, u64 b) {}
#ifdef FASTIO
  void write() { fastio::printer.write(val); }
  void read() {
    ll x;
    fastio::scanner.read(x);
    val = (val >= 0 ? val % mod : (mod - (-val) % mod) % mod);
  }
#endif
};