#pragma once
#include "mod/modint_common.hpp"

struct Dynamic_ModInt {
  static constexpr bool is_modint = true;
  int val;
  Dynamic_ModInt() : val(0) {}
  Dynamic_ModInt(int64_t y)
      : val(y >= 0 ? y % get_mod()
                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}
  bool operator<(const Dynamic_ModInt &other) const {
    return val < other.val;
  } // To use std::map<Dynamic_ModInt, T>
  static int &get_mod() {
    static int mod = 0;
    return mod;
  }
  static void set_mod(int md) { get_mod() = md; }
  Dynamic_ModInt &operator+=(const Dynamic_ModInt &p) {
    if ((val += p.val) >= get_mod()) val -= get_mod();
    return *this;
  }
  Dynamic_ModInt &operator-=(const Dynamic_ModInt &p) {
    if ((val += get_mod() - p.val) >= get_mod()) val -= get_mod();
    return *this;
  }
  Dynamic_ModInt &operator*=(const Dynamic_ModInt &p) {
    long long a = (long long)val * p.val;
    int xh = (int)(a >> 32), xl = (int)a, d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(get_mod()));
    val = m;
    return *this;
  }
  Dynamic_ModInt &operator/=(const Dynamic_ModInt &p) {
    *this *= p.inverse();
    return *this;
  }
  Dynamic_ModInt operator-() const { return Dynamic_ModInt(get_mod() - val); }
  Dynamic_ModInt operator+(const Dynamic_ModInt &p) const {
    return Dynamic_ModInt(*this) += p;
  }
  Dynamic_ModInt operator-(const Dynamic_ModInt &p) const {
    return Dynamic_ModInt(*this) -= p;
  }
  Dynamic_ModInt operator*(const Dynamic_ModInt &p) const {
    return Dynamic_ModInt(*this) *= p;
  }
  Dynamic_ModInt operator/(const Dynamic_ModInt &p) const {
    return Dynamic_ModInt(*this) /= p;
  }
  bool operator==(const Dynamic_ModInt &p) const { return val == p.val; }
  bool operator!=(const Dynamic_ModInt &p) const { return val != p.val; }
  Dynamic_ModInt inverse() const {
    int a = val, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b), swap(u -= t * v, v);
    }
    return Dynamic_ModInt(u);
  }
  Dynamic_ModInt pow(int64_t n) const {
    assert(n >= 0);
    Dynamic_ModInt ret(1), mul(val);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
#ifdef FASTIO
  void write() { fastio::printer.write(val); }
  void read() { fastio::scanner.read(val); }
#endif
  static constexpr pair<int, int> ntt_info() { return {-1, -1}; }
};

using dmint = Dynamic_ModInt;
