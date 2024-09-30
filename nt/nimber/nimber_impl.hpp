#pragma once
namespace NIM_PRODUCT {
u16 E[65535 * 2 + 7];
u16 L[65536];
u64 S[4][65536];
u64 SR[4][65536];

u16 p16_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 3] : 0); }
u16 p16_15_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 6] : 0); }
u16 mul_15(u16 a) { return (a ? E[3 + L[a]] : 0); }
u16 mul_15_15(u16 a) { return (a ? E[6 + L[a]] : 0); }
u32 p32_mul_31(u32 a, u32 b) {
  u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;
  u16 x = p16_15(al, bl);
  u16 y = p16_15_15(ah, bh);
  u16 z = p16_15(al ^ ah, bl ^ bh);
  return u32(y ^ z) << 16 | mul_15(z ^ x);
}
u32 mul_31(u32 a) {
  u16 al = a & 65535, ah = a >> 16;
  return u32(mul_15(al ^ ah)) << 16 | mul_15_15(ah);
}

u16 prod(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b]] : 0); }
u32 prod(u32 a, u32 b) {
  u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;
  u16 c = prod(al, bl);
  return u32(prod(u16(al ^ ah), u16(bl ^ bh)) ^ c) << 16 | (p16_15(ah, bh) ^ c);
}
u64 prod(u64 a, u64 b) {
  u32 al = a & 0xffffffff, ah = a >> 32, bl = b & 0xffffffff, bh = b >> 32;
  u32 c = prod(al, bl);
  return u64(prod(al ^ ah, bl ^ bh) ^ c) << 32 ^ (p32_mul_31(ah, bh) ^ c);
}

u16 square(u16 a) { return S[0][a]; }
u32 square(u32 a) { return S[0][a & 65535] ^ S[1][a >> 16]; }
u64 square(u64 a) { return S[0][a & 65535] ^ S[1][a >> 16 & 65535] ^ S[2][a >> 32 & 65535] ^ S[3][a >> 48 & 65535]; }
u16 sqrt(u16 a) { return SR[0][a]; }
u32 sqrt(u32 a) { return SR[0][a & 65535] ^ SR[1][a >> 16]; }
u64 sqrt(u64 a) { return SR[0][a & 65535] ^ SR[1][a >> 16 & 65535] ^ SR[2][a >> 32 & 65535] ^ SR[3][a >> 48 & 65535]; }

// inv: 2^16 の共役が 2^16+1 であることなどを使う. x^{-1}=y(xy)^{-1} という要領.
u16 inverse(u16 a) { return E[65535 - L[a]]; }
u32 inverse(u32 a) {
  if (a < 65536) return inverse(u16(a));
  u16 al = a & 65535, ah = a >> 16;
  u16 norm = prod(al, al ^ ah) ^ E[L[ah] * 2 + 3];
  int k = 65535 - L[norm];
  al = (al ^ ah ? E[L[al ^ ah] + k] : 0), ah = E[L[ah] + k];
  return al | u32(ah) << 16;
}
u64 inverse(u64 a) {
  if (a <= u32(-1)) return inverse(u32(a));
  u32 al = a & 0xffffffff, ah = a >> 32;
  u32 norm = prod(al, al ^ ah) ^ mul_31(square(ah));
  u32 i = inverse(norm);
  return prod(al ^ ah, i) | u64(prod(ah, i)) << 32;
}

void __attribute__((constructor)) init_nim_table() {
  // 2^16 未満のところについて原始根 10279 での指数対数表を作る
  // 2^k との積
  u16 tmp[] = {10279, 15417, 35722, 52687, 44124, 62628, 15661, 5686, 3862, 1323, 334, 647, 61560, 20636, 4267, 8445};
  u16 nxt[65536];
  FOR(i, 16) {
    FOR(s, 1 << i) { nxt[s | 1 << i] = nxt[s] ^ tmp[i]; }
  }
  E[0] = 1;
  FOR(i, 65534) E[i + 1] = nxt[E[i]];
  memcpy(E + 65535, E, 131070);
  memcpy(E + 131070, E, 14);
  FOR(i, 65535) L[E[i]] = i;
  FOR(t, 4) {
    FOR(i, 16) {
      int k = 16 * t + i;
      u64 X = prod(u64(1) << k, u64(1) << k);
      FOR(s, 1 << i) S[t][s | 1 << i] = S[t][s] ^ X;
    }
  }
  FOR(t, 4) {
    FOR(i, 16) {
      int k = 16 * t + i;
      u64 X = u64(1) << k;
      FOR(63) X = square(X);
      FOR(s, 1 << i) SR[t][s | 1 << i] = SR[t][s] ^ X;
    }
  }
}
} // namespace NIM_PRODUCT
