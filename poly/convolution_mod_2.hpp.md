---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/poly/convolution_mod_2.hpp
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.15/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/bit.hpp:\
    \ line -1: no such header\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/poly/convolution_mod_2.hpp\n\
    #include <wmmintrin.h>\n#include \"ds/bit_array.hpp\"\n\n__attribute__((target(\"\
    pclmul\"))) void clmul_naive(\n    const u64* a, int n, const u64* b, int m, u64*\
    \ c) {\n  // c[0, n+m) \u306F\u3042\u3089\u304B\u3058\u3081 0 \u3068\u3059\u308B\
    \n  FOR(i, n) FOR(j, m) {\n    __m128i A = _mm_set_epi64x(0, a[i]);\n    __m128i\
    \ B = _mm_set_epi64x(0, b[j]);\n    __m128i C = _mm_clmulepi64_si128(A, B, 0x00);\n\
    \    alignas(16) u64 w[2];\n    _mm_store_si128((__m128i*)w, C);\n    c[i + j]\
    \ ^= w[0];\n    c[i + j + 1] ^= w[1];\n  }\n}\n\n// a,b: n limbs, n \u306F 2 \u51AA\
    \n// c: 2n limbs, \u547C\u3073\u51FA\u3057\u6642\u70B9\u3067\u5168\u90E8 0\n//\
    \ scratch \u306F 4n limbs \u3042\u308C\u3070\u5341\u5206\n__attribute__((target(\"\
    pclmul\"))) void clmul_karatsuba_rec(\n    const u64* a, const u64* b, u64* c,\
    \ int n, u64* scratch) {\n  constexpr int TH = 32;\n  if (n <= TH) {\n    clmul_naive(a,\
    \ n, b, n, c);\n    return;\n  }\n  int m = n / 2;\n  clmul_karatsuba_rec(a, b,\
    \ c, m, scratch);\n  clmul_karatsuba_rec(a + m, b + m, c + 2 * m, m, scratch);\n\
    \  u64* sa = scratch;\n  u64* sb = scratch + m;\n  u64* z1 = scratch + 2 * m;\n\
    \  u64* sub = scratch + 4 * m;\n  FOR(i, m) {\n    sa[i] = a[i] ^ a[m + i];\n\
    \    sb[i] = b[i] ^ b[m + i];\n  }\n  fill(z1, z1 + 2 * m, u64(0));\n  clmul_karatsuba_rec(sa,\
    \ sb, z1, m, sub);\n  FOR(i, 2 * m) z1[i] ^= c[i] ^ c[2 * m + i];\n  FOR(i, 2\
    \ * m) c[m + i] ^= z1[i];\n}\n\n__attribute__((target(\"pclmul\"))) Bit_Array\
    \ convolution(\n    const Bit_Array& a, const Bit_Array& b) {\n  int na = a.size(),\
    \ nb = b.size();\n  if (!na || !nb) return {};\n  int A = len(a.dat), B = len(b.dat);\n\
    \  int N = na + nb - 1;\n  Bit_Array res(64 * (A + B));\n  if (min(A, B) <= 16)\
    \ {\n    clmul_naive(a.dat.data(), A, b.dat.data(), B, res.dat.data());\n    res.resize(N);\n\
    \    return res;\n  }\n  int n = 1;\n  while (n < max(A, B)) n <<= 1;\n  vc<u64>\
    \ x(n), y(n);\n  copy(all(a.dat), x.begin());\n  copy(all(b.dat), y.begin());\n\
    \  res.resize(128 * n);\n  vc<u64> scratch(4 * n);\n  clmul_karatsuba_rec(x.data(),\
    \ y.data(), res.dat.data(), n, scratch.data());\n  res.resize(N);\n  return res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/convolution_mod_2.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/convolution_mod_2.hpp
layout: document
redirect_from:
- /library/poly/convolution_mod_2.hpp
- /library/poly/convolution_mod_2.hpp.html
title: poly/convolution_mod_2.hpp
---
