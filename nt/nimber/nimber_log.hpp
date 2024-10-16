#include "nt/nimber/base.hpp"
#include "ds/hashmap.hpp"
#include "mod/crt3.hpp"

// primitive root
const Nimber64 root_64 = u64(1) << 32 | 6;
const Nimber32 root_32 = 2147483651;
const Nimber16 root_16 = 41899;

u64 nimber_log(Nimber16 x) {
  assert(x != 0);
  u32 ans = u32(37991) * NIM_PRODUCT::L[x.val];
  return ans % 65535;
}

u64 nimber_log(Nimber32 x) {
  using F = Nimber32;
  assert(x != 0);
  static HashMap<u32> MP(330);
  static F g = 0;
  if (len(MP) == 0) {
    // build
    g = root_32.pow(65535); // 65537 乗根
    F gg = g.pow(200);
    F pow = 1;
    FOR(i, 330) MP[pow.val] = i, pow *= gg;
  }
  u64 a = [&]() -> u32 {
    F x1 = x.pow(65535);
    FOR(i, 200) {
      u32 k = MP.get(x1.val, -1);
      if (k != u32(-1)) { return (65537 + 200 * k - i) % 65537; }
      x1 *= g;
    }
    assert(0);
    return 0;
  }();
  u64 b = nimber_log(Nimber16(x.pow(65537).val));
  return CRT2<u64, 65535, 65537>(b, a);
}

u64 nimber_log(Nimber64 x) {
  using F = Nimber64;
  assert(x != 0);
  const u64 mod1 = u32(-1);
  const u64 mod2 = mod1 + 2;
  const u32 p1 = 641;
  const u32 p2 = 6700417;
  static HashMap<u32> MP1(3400);
  static HashMap<u32> MP2(641);
  static F g1, g2;
  if (len(MP1) == 0) {
    g1 = root_64.pow(mod1 * p1); // p2 乗根
    g2 = root_64.pow(mod1 * p2); // p1 乗根
    F gg = g1.pow(2000);
    F pow = 1;
    FOR(i, 3400) MP1[pow.val] = i, pow *= gg;
    pow = 1;
    FOR(i, 641) MP2[pow.val] = i, pow *= g2;
  }
  u64 a1 = [&]() -> u64 {
    F x1 = x.pow(mod1 * p1);
    FOR(i, 2000) {
      u32 k = MP1.get(x1.val, -1);
      if (k != u32(-1)) { return (p2 + 2000 * k - i) % p2; }
      x1 *= g1;
    }
    assert(0);
    return 0;
  }();
  u64 a2 = MP2[x.pow(mod1 * p2).val];
  u64 b = nimber_log(Nimber32(x.pow(mod2).val));
  u64 a = CRT2<u64, p1, p2>(a2, a1);
  u128 ans = u128(a) * (u64(-1) - mod1) + u128(b) * mod2;
  if (ans & 1) ans += u64(-1);
  return (ans / 2) % u64(-1);
}

// 最小解. ちょうど -1 を false の意味に使える.
template <typename F>
u64 nimber_log(F x, F y) {
  u64 X = nimber_log(x), Y = nimber_log(y);
  // X*n = Y mod (2^64-1)
  u64 mod = -1;
  u64 a = X, b = mod;
  i128 u = 1, v = 0, t;
  while (b > 0) {
    t = a / b;
    swap(a -= t * b, b), swap(u -= t * v, v);
  }
  if (Y % a != 0) return -1;
  if (u < 0) u += mod;
  return (Y / a) * u % (mod / a);
}