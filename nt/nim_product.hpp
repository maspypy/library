
namespace NIM_PRODUCT {
u16 E[65535 * 2 + 7];
u16 L[65536];

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
}

u16 p16(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b]] : 0); }
u16 p16_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 3] : 0); }
u16 p16_15_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 6] : 0); }
u16 mul_15(u16 a) { return (a ? E[3 + L[a]] : 0); }
u32 p32(u32 a, u32 b) {
  u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;
  u16 c = p16(al, bl);
  return u32(p16(al ^ ah, bl ^ bh) ^ c) << 16 | (p16_15(ah, bh) ^ c);
}

u32 p32_mul_31(u32 a, u32 b) {
  u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;
  u16 x = p16_15(al, bl);
  u16 y = p16_15_15(ah, bh);
  u16 z = p16_15(al ^ ah, bl ^ bh);
  return u32(y ^ z) << 16 | mul_15(z ^ x);
}

u64 p64(u64 a, u64 b) {
  u32 al = a & 0xffffffff, ah = a >> 32, bl = b & 0xffffffff, bh = b >> 32;
  u32 c = p32(al, bl);
  return u64(p32(al ^ ah, bl ^ bh) ^ c) << 32 ^ (p32_mul_31(ah, bh) ^ c);
}
} // namespace NIM_PRODUCT

u64 nim_product(u64 a, u64 b) { return NIM_PRODUCT::p64(a, b); }
