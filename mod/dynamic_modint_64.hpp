#pragma once

#include "mod/modint_common.hpp"
#include "mod/barrett.hpp"

// https://codeforces.com/contest/453/problem/D
template <int id>
struct Dynamic_Modint_64 {
  static constexpr bool is_modint = true;
  using mint = Dynamic_Modint_64;
  u64 val;
  static Barrett_64 bt;
  static u64 umod() { return bt.umod(); }

  static ll get_mod() { return (ll)(bt.umod()); }
  static void set_mod(ll m) {
    assert(1 <= m);
    bt = Barrett_64(m);
  }

  Dynamic_Modint_64() : val(0) {}
  Dynamic_Modint_64(u64 x) : val(bt.modulo(x)) {}
  Dynamic_Modint_64(u128 x) : val(bt.modulo(x)) {}
  Dynamic_Modint_64(int x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}
  Dynamic_Modint_64(ll x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}
  Dynamic_Modint_64(i128 x) : val((x %= get_mod()) < 0 ? x + get_mod() : x) {}

  mint& operator+=(const mint& rhs) {
    val = (val += rhs.val) < umod() ? val : val - umod();
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    val = (val += umod() - rhs.val) < umod() ? val : val - umod();
    return *this;
  }
  mint& operator*=(const mint& rhs) {
    val = bt.mul(val, rhs.val);
    return *this;
  }
  mint& operator/=(const mint& rhs) { return *this = *this * rhs.inverse(); }
  mint operator-() const { return mint() - *this; }
  mint pow(ll n) const {
    assert(0 <= n);
    mint x = *this, r = u64(1);
    while (n) {
      if (n & 1) r *= x;
      x *= x, n >>= 1;
    }
    return r;
  }
  mint inverse() const {
    ll x = val, mod = get_mod();
    ll a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    if (u < 0) u += mod;
    return u64(u);
  }

  friend mint operator+(const mint& lhs, const mint& rhs) {
    return mint(lhs) += rhs;
  }
  friend mint operator-(const mint& lhs, const mint& rhs) {
    return mint(lhs) -= rhs;
  }
  friend mint operator*(const mint& lhs, const mint& rhs) {
    return mint(lhs) *= rhs;
  }
  friend mint operator/(const mint& lhs, const mint& rhs) {
    return mint(lhs) /= rhs;
  }
  friend bool operator==(const mint& lhs, const mint& rhs) {
    return lhs.val == rhs.val;
  }
  friend bool operator!=(const mint& lhs, const mint& rhs) {
    return lhs.val != rhs.val;
  }
#ifdef FASTIO
  void write() { fastio::printer.write(val); }
  void read() {
    fastio::scanner.read(val);
    val = bt.modulo(val);
  }
#endif
};

using dmint64 = Dynamic_Modint_64<-1>;
template <int id>
Barrett_64 Dynamic_Modint_64<id>::bt;
