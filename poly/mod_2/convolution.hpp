#include <wmmintrin.h>

#include "ds/bit_array.hpp"

constexpr int CLMUL_TH = 8;

__attribute__((target("pclmul"))) void clmul_naive(
    const u64* a, int n, const u64* b, int m, u64* c) {
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

// a,b: n words, n は 2 冪
// c: 2n words, 呼び出し時点で全部 0
// scratch: 4n words
__attribute__((target("pclmul"))) void clmul_karatsuba_rec(
    const u64* a, const u64* b, u64* c, int n, u64* scratch) {
  if (n <= CLMUL_TH) {
    clmul_naive(a, n, b, n, c);
    return;
  }

  int m = n / 2;

  // z0 = a0*b0
  clmul_karatsuba_rec(a, b, c, m, scratch);
  // z2 = a1*b1
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

// c は A+B words 以上あり、あらかじめ 0 にしておく。
__attribute__((target("pclmul"))) void clmul_rec(
    const u64* a, int A, const u64* b, int B, u64* c) {
  if (A > B) {
    clmul_rec(b, B, a, A, c);
    return;
  }

  // A <= B
  if (A <= CLMUL_TH) {
    clmul_naive(a, A, b, B, c);
    return;
  }

  if (2 * A <= B) {
    // b = b0 + x^(B-A) b1
    // |b0| = B-A, |b1| = A
    int M = B - A;

    clmul_rec(a, A, b, M, c);
    clmul_rec(a, A, b + M, A, c + M);
    return;
  }

  // A <= B < 2A
  assert(A <= B && B < 2 * A);
  int n = 1;
  while (n < B) n <<= 1;
  vc<u64> x(n), y(n), z(2 * n), scratch(4 * n);
  copy(a, a + A, x.begin());
  copy(b, b + B, y.begin());
  clmul_karatsuba_rec(x.data(), y.data(), z.data(), n, scratch.data());
  FOR(i, A + B) c[i] ^= z[i];
}

__attribute__((target("pclmul"))) Bit_Array convolution(
    const Bit_Array& a, const Bit_Array& b) {
  int na = a.size(), nb = b.size();
  if (!na || !nb) return {};

  int A = len(a.dat), B = len(b.dat);
  // clmul_rec は A+B words に書き込む可能性がある。
  Bit_Array res(64 * (A + B));
  clmul_rec(a.dat.data(), A, b.dat.data(), B, res.dat.data());
  res.resize(na + nb - 1);
  return res;
}