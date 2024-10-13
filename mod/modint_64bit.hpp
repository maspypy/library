// https://qoj.ac/problem/969
template <ll mod>
struct modint_64bit {
  using T = modint_64bit;
  static constexpr u64 umod = u64(mod);
  static_assert(umod < u64(1) << 63);
  u64 val;
  constexpr modint_64bit() : val(0) {}
  constexpr modint_64bit(u64 x) : val(x % umod) {}
  constexpr modint_64bit(u128 x) : val(x % umod) {}
  constexpr modint_64bit(int x) : val((x %= mod) < 0 ? x + mod : x){};
  constexpr modint_64bit(ll x) : val((x %= mod) < 0 ? x + mod : x){};
  constexpr modint_64bit(i128 x) : val((x %= mod) < 0 ? x + mod : x){};
  static T raw(u64 v) {
    T x;
    x.val = v;
    return x;
  }
  bool operator<(const T& other) const { return val < other.val; }
  T& operator+=(const T& p) {
    if ((val += p.val) >= umod) val -= umod;
    return *this;
  }
  T& operator-=(const T& p) {
    if ((val += umod - p.val) >= umod) val -= umod;
    return *this;
  }
  T& operator*=(const T& p) {
    val = u128(val) * p.val % umod;
    return *this;
  }
  T& operator/=(const T& p) {
    *this *= p.inverse();
    return *this;
  }
  T operator-() const { return raw(val ? mod - val : u32(0)); }
  T operator+(const T& p) const { return modint_64bit(*this) += p; }
  T operator-(const T& p) const { return modint_64bit(*this) -= p; }
  T operator*(const T& p) const { return modint_64bit(*this) *= p; }
  T operator/(const T& p) const { return modint_64bit(*this) /= p; }
  bool operator==(const T& p) const { return val == p.val; }
  bool operator!=(const T& p) const { return val != p.val; }
  T inverse() const {
    int a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint_64bit(u);
  }
  T pow(ll n) const {
    assert(n >= 0);
    T ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul, n >>= 1;
    }
    return ret;
  }
  static constexpr ll get_mod() { return mod; }
  // (n, r), r は 1 の 2^n 乗根
  static constexpr pair<ll, ll> ntt_info() { return {-1, -1}; }
  static constexpr bool can_ntt() { return ntt_info().fi != -1; }
};
#ifdef FASTIO
template <ll mod>
void rd(modint_64bit<mod>& x) {
  fastio::rd(x.val);
  x.val %= mod;
}
template <ll mod>
void wt(modint_64bit<mod> x) {
  fastio::wt(x.val);
}
#endif
