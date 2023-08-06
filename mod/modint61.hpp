
// https : // yosupo.hatenablog.com/entry/2023/08/06/181942
// x の代わりに 8x を [8, 8MOD] で持つ
struct modint61 {
  using u128 = unsigned __int128;
  static constexpr u64 MOD = (1ULL << 61) - 1;
  static constexpr u64 MOD8 = MOD * 8;
  u64 x8;
  constexpr modint61() : x8(0ULL) {}
  constexpr modint61(u32 x) : x8((x + MOD - 1) % MOD * 8 + 8) {}
  constexpr modint61(u64 x) : x8((x + MOD - 1) % MOD * 8 + 8) {}
  constexpr modint61(int x) : x8((x + MOD - 1) % MOD * 8 + 8) {}
  constexpr modint61(ll x)
      : x8(8 * (((x %= ll(MOD)) <= 0) ? (x + ll(MOD)) : x)) {}

  static constexpr u64 get_mod() { return MOD; }
  modint61 &operator+=(const modint61 &a) {
    if (__builtin_uaddll_overflow(x8, a.x8, &x8)) x8 -= MOD8;
    return *this;
  }
  modint61 &operator-=(const modint61 &a) {
    if (__builtin_uaddll_overflow(x8, MOD8 - a.x8, &x8)) x8 -= MOD8;
    return *this;
  }
  modint61 &operator*=(const modint61 &a) {
    u128 c = u128(x8) * (a.x8);
    u64 x = c >> 67 << 3, y = c << 61 >> 64;
    if (__builtin_uaddll_overflow(x, y, &x8)) x8 -= MOD8;
    return *this;
  }
  modint61 &operator/=(const modint61 &a) { return (*this *= a.inverse()); }
  modint61 operator+(const modint61 &p) const { return modint61(*this) += p; }
  modint61 operator-(const modint61 &p) const { return modint61(*this) -= p; }
  modint61 operator*(const modint61 &p) const { return modint61(*this) *= p; }
  modint61 operator/(const modint61 &p) const { return modint61(*this) /= p; }
  bool operator==(const modint61 &p) const { return x8 == p.x8; }
  bool operator!=(const modint61 &p) const { return x8 != p.x8; }
  u64 val() const { return (x8 == MOD8 ? 0 : x8 >> 3); }
  modint61 inverse() const {
    ll a = val(), b = MOD, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint61(u);
  }
  modint61 pow(ll n) const {
    assert(n >= 0);
    modint61 ret(1);
    modint61 mul = (*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul, n >>= 1;
    }
    return ret;
  }

#ifdef FASTIO
  void write() { fastio::printer.write(val()); }
  void read() {
    ll x;
    fastio::scanner.read(x);
    x8 = 8 * (((x %= ll(MOD)) <= 0) ? (x + ll(MOD)) : x);
  }
#endif
};