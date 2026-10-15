// Source: https://github.com/maspypy/library/blob/main/poly/convolution_mod_2.hpp
#include <wmmintrin.h>
#include "ds/bit_array.hpp"

__attribute__((target("pclmul"))) void clmul_naive(
    const u64* a, int n, const u64* b, int m, u64* c) {
  // c[0, n+m) はあらかじめ 0 とする
  FOR(i, n) FOR(j, m) {
    __m128i A = _mm_set_epi64x(0, a[i]);
    __m128i B = _mm_set_epi64x(0, b[j]);
    __m128i C = _mm_clmulepi64_si128(A, B, 0x00);
    alignas(16) u64 w[2];
    _mm_store_si128((__m128i*)w, C);
    c[i + j] ^= w[0];
    c[i + j + 1] ^= w[1];
  }
}

// a,b: n limbs, n は 2 冪
// c: 2n limbs, 呼び出し時点で全部 0
// scratch は 4n limbs あれば十分
__attribute__((target("pclmul"))) void clmul_karatsuba_rec(
    const u64* a, const u64* b, u64* c, int n, u64* scratch) {
  constexpr int TH = 32;
  if (n <= TH) {
    clmul_naive(a, n, b, n, c);
    return;
  }
  int m = n / 2;
  clmul_karatsuba_rec(a, b, c, m, scratch);
  clmul_karatsuba_rec(a + m, b + m, c + 2 * m, m, scratch);
  u64* sa = scratch;
  u64* sb = scratch + m;
  u64* z1 = scratch + 2 * m;
  u64* sub = scratch + 4 * m;
  FOR(i, m) {
    sa[i] = a[i] ^ a[m + i];
    sb[i] = b[i] ^ b[m + i];
  }
  fill(z1, z1 + 2 * m, u64(0));
  clmul_karatsuba_rec(sa, sb, z1, m, sub);
  FOR(i, 2 * m) z1[i] ^= c[i] ^ c[2 * m + i];
  FOR(i, 2 * m) c[m + i] ^= z1[i];
}

__attribute__((target("pclmul"))) Bit_Array convolution(
    const Bit_Array& a, const Bit_Array& b) {
  int na = a.size(), nb = b.size();
  if (!na || !nb) return {};
  int A = len(a.dat), B = len(b.dat);
  int N = na + nb - 1;
  Bit_Array res(64 * (A + B));
  if (min(A, B) <= 16) {
    clmul_naive(a.dat.data(), A, b.dat.data(), B, res.dat.data());
    res.resize(N);
    return res;
  }
  int n = 1;
  while (n < max(A, B)) n <<= 1;
  vc<u64> x(n), y(n);
  copy(all(a.dat), x.begin());
  copy(all(b.dat), y.begin());
  res.resize(128 * n);
  vc<u64> scratch(4 * n);
  clmul_karatsuba_rec(x.data(), y.data(), res.dat.data(), n, scratch.data());
  res.resize(N);
  return res;
}
