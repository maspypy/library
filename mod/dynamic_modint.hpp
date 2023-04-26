#pragma once
#include "mod/modint_common.hpp"
#include "mod/primitive_root.hpp"
#include "mod/barrett.hpp"

template <class T>
using is_signed_int =
    typename std::conditional<(is_integral<T>::value
                               && std::is_signed<T>::value),
                              std::true_type, std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value
                               && std::is_unsigned<T>::value),
                              std::true_type, std::false_type>::type;
template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

struct Dynamic_Modint {
  static constexpr bool is_modint = true;
  using mint = Dynamic_Modint;
  u32 val;
  static Barrett bt;
  static u32 umod() { return bt.umod(); }

  static int get_mod() { return (int)(bt.umod()); }
  static void set_mod(int m) {
    assert(1 <= m);
    bt = Barrett(m);
  }

  Dynamic_Modint() : val(0) {}
  template <class T, is_signed_int_t<T>* = nullptr>
  Dynamic_Modint(T v) {
    int x = v % get_mod();
    if (x < 0) x += get_mod();
    val = u32(x);
  }
  template <class T, is_unsigned_int_t<T>* = nullptr>
  Dynamic_Modint(T v) {
    val = bt.modulo(v);
  }

  mint& operator+=(const mint& rhs) {
    val += rhs.val;
    if (val >= umod()) val -= umod();
    return *this;
  }
  mint& operator-=(const mint& rhs) {
    val += umod() - rhs.val;
    if (val >= umod()) val -= umod();
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
    mint x = *this, r = 1;
    while (n) {
      if (n & 1) r *= x;
      x *= x;
      n >>= 1;
    }
    return r;
  }
  mint inverse() const {
    int x = val;
    int mod = get_mod();
    ll a = x, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    if (u < 0) u += mod;
    return u;
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
  void read() { fastio::scanner.read(val); }
#endif
  static pair<int, int>& get_ntt() {
    static pair<int, int> p = {-1, -1};
    return p;
  }
  static void set_ntt_info() {
    int mod = get_mod();
    int k = lowbit(mod - 1);
    int r = primitive_root(mod);
    r = mod_pow(r, (mod - 1) >> k, mod);
    get_ntt() = {k, r};
  }
  static pair<int, int> ntt_info() { return get_ntt(); }
  static bool can_ntt() { return ntt_info().fi != -1; }
};

using dmint = Dynamic_Modint;
Barrett dmint::bt(1);