#pragma once
#include "nt/nimber/nimber_impl.hpp"

template <typename UINT>
struct Nimber {
  using F = Nimber;
  UINT val;

  constexpr Nimber(UINT x = 0) : val(x) {}
  F &operator+=(const F &p) {
    val ^= p.val;
    return *this;
  }
  F &operator-=(const F &p) {
    val ^= p.val;
    return *this;
  }
  F &operator*=(const F &p) {
    val = NIM_PRODUCT::prod(val, p.val);
    return *this;
  }
  F &operator/=(const F &p) {
    *this *= p.inverse();
    return *this;
  }
  F operator-() const { return *this; }
  F operator+(const F &p) const { return F(*this) += p; }
  F operator-(const F &p) const { return F(*this) -= p; }
  F operator*(const F &p) const { return F(*this) *= p; }
  F operator/(const F &p) const { return F(*this) /= p; }
  bool operator==(const F &p) const { return val == p.val; }
  bool operator!=(const F &p) const { return val != p.val; }
  F inverse() const { return NIM_PRODUCT::inverse(val); }
  F pow(u64 n) const {
    assert(n >= 0);
    UINT ret = 1, mul = val;
    while (n > 0) {
      if (n & 1) ret = NIM_PRODUCT::prod(ret, mul);
      mul = NIM_PRODUCT::square(mul);
      n >>= 1;
    }
    return F(ret);
  }
  F square() { return F(NIM_PRODUCT::square(val)); }
  F sqrt() { return F(NIM_PRODUCT::sqrt(val)); }
};

#ifdef FASTIO
template <typename T>
void rd(Nimber<T> &x) {
  fastio::rd(x.val);
}
template <typename T>
void wt(Nimber<T> &x) {
  fastio::wt(x.val);
}
#endif

using Nimber16 = Nimber<u16>;
using Nimber32 = Nimber<u32>;
using Nimber64 = Nimber<u64>;
