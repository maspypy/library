#pragma once

template <unsigned int mod>
struct modint {
  static constexpr bool is_modint = true;
  unsigned int val;
  constexpr modint(const long long val = 0) noexcept
      : val(val >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}
  bool operator<(const modint &other) const {
    return val < other.val;
  } // To use std::map
  modint &operator+=(const modint &p) {
    if ((val += p.val) >= mod) val -= mod;
    return *this;
  }
  modint &operator-=(const modint &p) {
    if ((val += mod - p.val) >= mod) val -= mod;
    return *this;
  }
  modint &operator*=(const modint &p) {
    val = (unsigned int)(1LL * val * p.val % mod);
    return *this;
  }
  modint &operator/=(const modint &p) {
    *this *= p.inverse();
    return *this;
  }
  modint operator-() const { return modint(get_mod() - val); }
  modint operator+(const modint &p) const { return modint(*this) += p; }
  modint operator-(const modint &p) const { return modint(*this) -= p; }
  modint operator*(const modint &p) const { return modint(*this) *= p; }
  modint operator/(const modint &p) const { return modint(*this) /= p; }
  bool operator==(const modint &p) const { return val == p.val; }
  bool operator!=(const modint &p) const { return val != p.val; }
  modint inverse() const {
    int a = val, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return modint(u);
  }
  modint pow(int64_t n) const {
    modint ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  static constexpr unsigned int get_mod() { return mod; }
};

struct ArbitraryModInt {
  static constexpr bool is_modint = true;
  unsigned int val;
  ArbitraryModInt() : val(0) {}
  ArbitraryModInt(int64_t y)
      : val(y >= 0 ? y % get_mod()
                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}
  bool operator<(const ArbitraryModInt &other) const {
    return val < other.val;
  } // To use std::map<ArbitraryModInt, T>
  static unsigned int &get_mod() {
    static unsigned int mod = 0;
    return mod;
  }
  static void set_mod(int md) { get_mod() = md; }
  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if ((val += p.val) >= get_mod()) val -= get_mod();
    return *this;
  }
  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();
    return *this;
  }
  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    unsigned long long a = (unsigned long long)val * p.val;
    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(get_mod()));
    val = m;
    return *this;
  }
  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  ArbitraryModInt operator-() const { return ArbitraryModInt(get_mod() - val); }
  ArbitraryModInt operator+(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) += p;
  }
  ArbitraryModInt operator-(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) -= p;
  }
  ArbitraryModInt operator*(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) *= p;
  }
  ArbitraryModInt operator/(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) /= p;
  }
  bool operator==(const ArbitraryModInt &p) const { return val == p.val; }
  bool operator!=(const ArbitraryModInt &p) const { return val != p.val; }
  ArbitraryModInt inverse() const {
    int a = val, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }
  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
};

template <typename mint>
mint inv(int n) {
  static const int mod = mint::get_mod();
  static vector<mint> dat = {0, 1};
  assert(0 <= n);
  if (n >= mod) n %= mod;
  while (int(dat.size()) <= n) {
    int k = dat.size();
    auto q = (mod + k - 1) / k;
    int r = k * q - mod;
    dat.emplace_back(dat[r] * mint(q));
  }
  return dat[n];
}

template <typename mint>
mint fact(int n) {
  static const int mod = mint::get_mod();
  static vector<mint> dat = {1, 1};
  assert(0 <= n);
  if (n >= mod) return 0;
  while (int(dat.size()) <= n) {
    int k = dat.size();
    dat.emplace_back(dat[k - 1] * mint(k));
  }
  return dat[n];
}

template <typename mint>
mint fact_inv(int n) {
  static const int mod = mint::get_mod();
  static vector<mint> dat = {1, 1};
  assert(0 <= n && n < mod);
  while (int(dat.size()) <= n) {
    int k = dat.size();
    dat.emplace_back(dat[k - 1] * inv<mint>(k));
  }
  return dat[n];
}

template <typename mint>
mint C_dense(int n, int k) {
  static vvc<mint> C;
  static int H = 0, W = 0;

  auto calc = [&](int i, int j) -> mint {
    if (i == 0) return (j == 0 ? mint(1) : mint(0));
    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);
  };

  if (W <= k) {
    FOR(i, H) {
      C[i].resize(k + 1);
      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }
    }
    W = k + 1;
  }
  if (H <= n) {
    FOR(i, H, n + 1) {
      FOR(j, W) { C[i][j] = calc(i, j); }
    }
    H = n + 1;
  }
  return C[n][k];
}

template <typename mint, bool large = false, bool dense = false>
mint C(ll n, ll k) {
  assert(n >= 0);
  if (k < 0 || n < k) return 0;
  if (dense) return C_dense(n, k);
  if (!large) return fact<mint>(n) * fact_inv<mint>(k) * fact_inv<mint>(n - k);
  k = min(k, n - k);
  mint x(1);
  FOR(i, k) { x *= mint(n - i); }
  x *= fact_inv<mint>(k);
  return x;
}

template <typename mint, bool large = false>
mint C_inv(ll n, ll k) {
  assert(n >= 0);
  assert(0 <= k && k <= n);
  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);
  return mint(1) / C<mint, 1>(n, k);
}

// [x^d](1-x)^{-n} の計算
template <typename mint, bool large = false, bool dense = false>
mint C_negative(ll n, ll d) {
  assert(n >= 0);
  if (d < 0) return mint(0);
  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }
  return C<mint, large, dense>(n + d - 1, n);
}

using modint107 = modint<1000000007>;
using modint998 = modint<998244353>;
using amint = ArbitraryModInt;