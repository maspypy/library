#pragma once

// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp
struct Barrett {
  u32 m;
  u64 im;
  explicit Barrett(u32 m) : m(m), im((unsigned long long)(-1) / m + 1) {}
  u32 umod() const { return m; }
  u32 modulo(u64 z) {
    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);
    u64 y = x * m;
    return (u32)(z - y + (z < y ? m : 0));
  }
  u32 floor(u64 z) {
    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);
    u64 y = x * m;
    return (u32)(z < y ? x - 1 : x);
  }
  u32 mul(u32 a, u32 b) { return modulo(u64(a) * b); }
};