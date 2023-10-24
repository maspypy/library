#pragma once
#include "mod/dynamic_modint_64.hpp"

bool primetest(const u64 x) {
  if (x == 2 or x == 3 or x == 5 or x == 7) return true;
  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;
  if (x < 121) return x > 1;
  const u64 d = (x - 1) >> lowbit(x - 1);
  using m64 = Dynamic_Modint_64<20231024>;

  m64::set_mod(x);
  const m64 one(u64(1)), minus_one(x - 1);
  auto ok = [&](u64 a) -> bool {
    auto y = m64(a).pow(d);
    u64 t = d;
    while (y != one && y != minus_one && t != x - 1) y *= y, t <<= 1;
    if (y != minus_one && t % 2 == 0) return false;
    return true;
  };
  if (x < (1ull << 32)) {
    for (u64 a: {2, 7, 61})
      if (!ok(a)) return false;
  } else {
    for (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
      if (x <= a) return true;
      if (!ok(a)) return false;
    }
  }
  return true;
}