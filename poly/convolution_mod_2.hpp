
__attribute__((target("pclmul"))) void clmul_schoolbook(const u64* a,
                                                        const u64* b, u64* c,
                                                        int n) {
  // c[0, 2n) はあらかじめ 0 とする
  FOR(i, n) FOR(j, n) {
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
//
// scratch は 4n limbs あれば十分。
__attribute__((target("pclmul"))) void clmul_karatsuba_rec(const u64* a,
                                                           const u64* b, u64* c,
                                                           int n,
                                                           u64* scratch) {
  // ここは実測調整
  constexpr int TH = 32;

  if (n <= TH) {
    clmul_schoolbook(a, b, c, n);
    return;
  }

  int m = n / 2;

  // z0 = a0*b0
  clmul_karatsuba_rec(a, b, c, m, scratch);

  // z2 = a1*b1
  clmul_karatsuba_rec(a + m, b + m, c + 2 * m, m, scratch);

  /*
    scratch:
      [0, m)     : a0+a1
      [m, 2m)    : b0+b1
      [2m, 4m)   : z1
      [4m, ...)  : recursive scratch
  */
  u64* sa = scratch;
  u64* sb = scratch + m;
  u64* z1 = scratch + 2 * m;
  u64* sub = scratch + 4 * m;

  FOR(i, m) {
    sa[i] = a[i] ^ a[m + i];
    sb[i] = b[i] ^ b[m + i];
  }

  fill(z1, z1 + 2 * m, u64(0));

  // z1 = (a0+a1)(b0+b1)
  clmul_karatsuba_rec(sa, sb, z1, m, sub);

  // cross = z1 + z0 + z2
  // 先に全部 z1 内で完成させる。
  // c[m+i] に書きながら c[i] を読むと overlap して壊れるので注意。
  FOR(i, 2 * m) { z1[i] ^= c[i] ^ c[2 * m + i]; }

  // c = z0 + x^m cross + x^(2m) z2
  FOR(i, 2 * m) { c[m + i] ^= z1[i]; }
}

__attribute__((target("pclmul"))) vc<modint<2>> convolution_mod_2(
    const vc<modint<2>>& a, const vc<modint<2>>& b) {
  int na = len(a), nb = len(b);
  if (!na || !nb) return {};

  int A = (na + 63) >> 6;
  int B = (nb + 63) >> 6;

  // この実装は square に padding するので、
  // 極端に非対称なら rectangular schoolbook の方がよい。
  int n = 1;
  while (n < max(A, B)) n <<= 1;

  vc<u64> x(n), y(n), z(2 * n);
  vc<u64> scratch(4 * n);

  FOR(i, na) { x[i >> 6] |= u64(a[i].val) << (i & 63); }
  FOR(i, nb) { y[i >> 6] |= u64(b[i].val) << (i & 63); }

  clmul_karatsuba_rec(x.data(), y.data(), z.data(), n, scratch.data());

  vc<modint<2>> res(na + nb - 1);
  FOR(i, len(res)) { res[i] = modint<2>::raw((z[i >> 6] >> (i & 63)) & 1); }
  return res;
}
