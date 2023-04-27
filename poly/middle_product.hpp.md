---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: linalg/implicit_matrix/vandermonde.hpp
    title: linalg/implicit_matrix/vandermonde.hpp
  - icon: ':question:'
    path: poly/multipoint.hpp
    title: poly/multipoint.hpp
  - icon: ':x:'
    path: poly/multivar_convolution_cyclic.hpp
    title: poly/multivar_convolution_cyclic.hpp
  - icon: ':x:'
    path: poly/partial_frac_decomposition.hpp
    title: poly/partial_frac_decomposition.hpp
  - icon: ':x:'
    path: poly/slice_rational_fps.hpp
    title: poly/slice_rational_fps.hpp
  - icon: ':x:'
    path: string/wildcard_pattern_matching.hpp
    title: string/wildcard_pattern_matching.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
    title: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/multipoint_evaluation.test.cpp
    title: test/library_checker/polynomial/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/multipoint_evaluation_on_geom.test.cpp
    title: test/library_checker/polynomial/multipoint_evaluation_on_geom.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/multipoint_evaluation_on_geom_2.test.cpp
    title: test/library_checker/polynomial/multipoint_evaluation_on_geom_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/polynomial_interpolation.test.cpp
    title: test/library_checker/polynomial/polynomial_interpolation.test.cpp
  - icon: ':x:'
    path: test/mytest/chirp_z.test.cpp
    title: test/mytest/chirp_z.test.cpp
  - icon: ':x:'
    path: test/mytest/partial_frac.test.cpp
    title: test/mytest/partial_frac.test.cpp
  - icon: ':x:'
    path: test/mytest/slice_rational_fps.test.cpp
    title: test/mytest/slice_rational_fps.test.cpp
  - icon: ':x:'
    path: test/mytest/vandermonde.test.cpp
    title: test/mytest/vandermonde.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2166.test.cpp
    title: test/yukicoder/2166.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2231.test.cpp
    title: test/yukicoder/2231.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2243.test.cpp
    title: test/yukicoder/2243.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc267g.test.cpp
    title: test_atcoder/abc267g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc272_h.test.cpp
    title: test_atcoder/abc272_h.test.cpp
  - icon: ':x:'
    path: test_atcoder/agc013e.test.cpp
    title: test_atcoder/agc013e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/middle_product.hpp\"\n\n#line 2 \"poly/ntt.hpp\"\n\r\
    \ntemplate <class mint>\r\nvoid ntt(vector<mint>& a, bool inverse) {\r\n  assert(mint::can_ntt());\r\
    \n  const int rank2 = mint::ntt_info().fi;\r\n  const int mod = mint::get_mod();\r\
    \n  static array<mint, 30> root;\r\n  static array<mint, 30> iroot;\r\n  static\
    \ array<mint, 30> rate2, irate2;\r\n  static array<mint, 30> rate3, irate3;\r\n\
    \r\n  static bool prepared = 0;\r\n  if (!prepared) {\r\n    prepared = 1;\r\n\
    \    root[rank2] = mint::ntt_info().se;\r\n    iroot[rank2] = mint(1) / root[rank2];\r\
    \n    FOR_R(i, rank2) {\r\n      root[i] = root[i + 1] * root[i + 1];\r\n    \
    \  iroot[i] = iroot[i + 1] * iroot[i + 1];\r\n    }\r\n    mint prod = 1, iprod\
    \ = 1;\r\n    for (int i = 0; i <= rank2 - 2; i++) {\r\n      rate2[i] = root[i\
    \ + 2] * prod;\r\n      irate2[i] = iroot[i + 2] * iprod;\r\n      prod *= iroot[i\
    \ + 2];\r\n      iprod *= root[i + 2];\r\n    }\r\n    prod = 1, iprod = 1;\r\n\
    \    for (int i = 0; i <= rank2 - 3; i++) {\r\n      rate3[i] = root[i + 3] *\
    \ prod;\r\n      irate3[i] = iroot[i + 3] * iprod;\r\n      prod *= iroot[i +\
    \ 3];\r\n      iprod *= root[i + 3];\r\n    }\r\n  }\r\n\r\n  int n = int(a.size());\r\
    \n  int h = topbit(n);\r\n  assert(n == 1 << h);\r\n  if (!inverse) {\r\n    int\
    \ len = 0;\r\n    while (len < h) {\r\n      if (h - len == 1) {\r\n        int\
    \ p = 1 << (h - len - 1);\r\n        mint rot = 1;\r\n        FOR(s, 1 << len)\
    \ {\r\n          int offset = s << (h - len);\r\n          FOR(i, p) {\r\n   \
    \         auto l = a[i + offset];\r\n            auto r = a[i + offset + p] *\
    \ rot;\r\n            a[i + offset] = l + r;\r\n            a[i + offset + p]\
    \ = l - r;\r\n          }\r\n          rot *= rate2[topbit(~s & -~s)];\r\n   \
    \     }\r\n        len++;\r\n      } else {\r\n        int p = 1 << (h - len -\
    \ 2);\r\n        mint rot = 1, imag = root[2];\r\n        for (int s = 0; s <\
    \ (1 << len); s++) {\r\n          mint rot2 = rot * rot;\r\n          mint rot3\
    \ = rot2 * rot;\r\n          int offset = s << (h - len);\r\n          for (int\
    \ i = 0; i < p; i++) {\r\n            u64 mod2 = u64(mod) * mod;\r\n         \
    \   u64 a0 = a[i + offset].val;\r\n            u64 a1 = u64(a[i + offset + p].val)\
    \ * rot.val;\r\n            u64 a2 = u64(a[i + offset + 2 * p].val) * rot2.val;\r\
    \n            u64 a3 = u64(a[i + offset + 3 * p].val) * rot3.val;\r\n        \
    \    u64 a1na3imag = (a1 + mod2 - a3) % mod * imag.val;\r\n            u64 na2\
    \ = mod2 - a2;\r\n            a[i + offset] = a0 + a2 + a1 + a3;\r\n         \
    \   a[i + offset + 1 * p] = a0 + a2 + (2 * mod2 - (a1 + a3));\r\n            a[i\
    \ + offset + 2 * p] = a0 + na2 + a1na3imag;\r\n            a[i + offset + 3 *\
    \ p] = a0 + na2 + (mod2 - a1na3imag);\r\n          }\r\n          rot *= rate3[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len += 2;\r\n      }\r\n    }\r\n  } else {\r\
    \n    mint coef = mint(1) / mint(len(a));\r\n    FOR(i, len(a)) a[i] *= coef;\r\
    \n    int len = h;\r\n    while (len) {\r\n      if (len == 1) {\r\n        int\
    \ p = 1 << (h - len);\r\n        mint irot = 1;\r\n        FOR(s, 1 << (len -\
    \ 1)) {\r\n          int offset = s << (h - len + 1);\r\n          FOR(i, p) {\r\
    \n            u64 l = a[i + offset].val;\r\n            u64 r = a[i + offset +\
    \ p].val;\r\n            a[i + offset] = l + r;\r\n            a[i + offset +\
    \ p] = (mod + l - r) * irot.val;\r\n          }\r\n          irot *= irate2[topbit(~s\
    \ & -~s)];\r\n        }\r\n        len--;\r\n      } else {\r\n        int p =\
    \ 1 << (h - len);\r\n        mint irot = 1, iimag = iroot[2];\r\n        FOR(s,\
    \ (1 << (len - 2))) {\r\n          mint irot2 = irot * irot;\r\n          mint\
    \ irot3 = irot2 * irot;\r\n          int offset = s << (h - len + 2);\r\n    \
    \      for (int i = 0; i < p; i++) {\r\n            u64 a0 = a[i + offset + 0\
    \ * p].val;\r\n            u64 a1 = a[i + offset + 1 * p].val;\r\n           \
    \ u64 a2 = a[i + offset + 2 * p].val;\r\n            u64 a3 = a[i + offset + 3\
    \ * p].val;\r\n            u64 x = (mod + a2 - a3) * iimag.val % mod;\r\n    \
    \        a[i + offset] = a0 + a1 + a2 + a3;\r\n            a[i + offset + 1 *\
    \ p] = (a0 + mod - a1 + x) * irot.val;\r\n            a[i + offset + 2 * p] =\
    \ (a0 + a1 + 2 * mod - a2 - a3) * irot2.val;\r\n            a[i + offset + 3 *\
    \ p] = (a0 + 2 * mod - a1 - x) * irot3.val;\r\n          }\r\n          irot *=\
    \ irate3[topbit(~s & -~s)];\r\n        }\r\n        len -= 2;\r\n      }\r\n \
    \   }\r\n  }\r\n}\r\n#line 4 \"poly/middle_product.hpp\"\n\n// n, m \u6B21\u591A\
    \u9805\u5F0F (n>=m) a, b \u2192 n-m \u6B21\u591A\u9805\u5F0F c\n// c[i] = sum_j\
    \ b[j]a[i+j]\ntemplate <typename mint>\nvc<mint> middle_product(vc<mint>& a, vc<mint>&\
    \ b) {\n  assert(len(a) >= len(b));\n  if (b.empty()) return vc<mint>(len(a) -\
    \ len(b) + 1);\n  if (min(len(b), len(a) - len(b) + 1) <= 60) {\n    return middle_product_naive(a,\
    \ b);\n  }\n  if constexpr (mint::ntt_info().fi == -1) {\n    return middle_product_garner(a,\
    \ b);\n  } else {\n    int n = 1 << __lg(2 * len(a) - 1);\n    vc<mint> fa(n),\
    \ fb(n);\n    copy(a.begin(), a.end(), fa.begin());\n    copy(b.rbegin(), b.rend(),\
    \ fb.begin());\n    ntt(fa, 0), ntt(fb, 0);\n    FOR(i, n) fa[i] *= fb[i];\n \
    \   ntt(fa, 1);\n    fa.resize(len(a));\n    fa.erase(fa.begin(), fa.begin() +\
    \ len(b) - 1);\n    return fa;\n  }\n}\n\ntemplate <typename mint>\nvc<mint> middle_product_garner(vc<mint>&\
    \ a, vc<mint> b) {\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n\
    \  static const long long nttprimes[] = {754974721, 167772161, 469762049};\n \
    \ using mint0 = modint<754974721>;\n  using mint1 = modint<167772161>;\n  using\
    \ mint2 = modint<469762049>;\n  vc<mint0> a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n\
    \  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i]\
    \ = a[i].val;\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n\
    \  auto c0 = middle_product<mint0>(a0, b0);\n  auto c1 = middle_product<mint1>(a1,\
    \ b1);\n  auto c2 = middle_product<mint2>(a2, b2);\n  static const long long m01\
    \ = 1LL * nttprimes[0] * nttprimes[1];\n  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;\n\
    \  static const long long m01_inv_m2 = mint2(m01).inverse().val;\n  static const\
    \ int mod = mint::get_mod();\n  auto garner = [&](mint0 x0, mint1 x1, mint2 x2)\
    \ -> mint {\n    int r0 = x0.val, r1 = x1.val, r2 = x2.val;\n    int v1 = (m0_inv_m1\
    \ * (r1 + nttprimes[1] - r0)) % nttprimes[1];\n    auto v2 = (mint2(r2) - r0 -\
    \ mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);\n    return mint(r0 + 1LL * nttprimes[0]\
    \ * v1 + m01 % mod * v2.val);\n  };\n  vc<mint> c(len(c0));\n  FOR(i, len(c))\
    \ c[i] = garner(c0[i], c1[i], c2[i]);\n  return c;\n}\n\ntemplate <typename mint>\n\
    vc<mint> middle_product_naive(vc<mint>& a, vc<mint>& b) {\n  vc<mint> res(len(a)\
    \ - len(b) + 1);\n  FOR(i, len(res)) FOR(j, len(b)) res[i] += b[j] * a[i + j];\n\
    \  return res;\n}\n"
  code: "#pragma once\n\n#include \"poly/ntt.hpp\"\n\n// n, m \u6B21\u591A\u9805\u5F0F\
    \ (n>=m) a, b \u2192 n-m \u6B21\u591A\u9805\u5F0F c\n// c[i] = sum_j b[j]a[i+j]\n\
    template <typename mint>\nvc<mint> middle_product(vc<mint>& a, vc<mint>& b) {\n\
    \  assert(len(a) >= len(b));\n  if (b.empty()) return vc<mint>(len(a) - len(b)\
    \ + 1);\n  if (min(len(b), len(a) - len(b) + 1) <= 60) {\n    return middle_product_naive(a,\
    \ b);\n  }\n  if constexpr (mint::ntt_info().fi == -1) {\n    return middle_product_garner(a,\
    \ b);\n  } else {\n    int n = 1 << __lg(2 * len(a) - 1);\n    vc<mint> fa(n),\
    \ fb(n);\n    copy(a.begin(), a.end(), fa.begin());\n    copy(b.rbegin(), b.rend(),\
    \ fb.begin());\n    ntt(fa, 0), ntt(fb, 0);\n    FOR(i, n) fa[i] *= fb[i];\n \
    \   ntt(fa, 1);\n    fa.resize(len(a));\n    fa.erase(fa.begin(), fa.begin() +\
    \ len(b) - 1);\n    return fa;\n  }\n}\n\ntemplate <typename mint>\nvc<mint> middle_product_garner(vc<mint>&\
    \ a, vc<mint> b) {\n  int n = len(a), m = len(b);\n  if (!n || !m) return {};\n\
    \  static const long long nttprimes[] = {754974721, 167772161, 469762049};\n \
    \ using mint0 = modint<754974721>;\n  using mint1 = modint<167772161>;\n  using\
    \ mint2 = modint<469762049>;\n  vc<mint0> a0(n), b0(m);\n  vc<mint1> a1(n), b1(m);\n\
    \  vc<mint2> a2(n), b2(m);\n  FOR(i, n) a0[i] = a[i].val, a1[i] = a[i].val, a2[i]\
    \ = a[i].val;\n  FOR(i, m) b0[i] = b[i].val, b1[i] = b[i].val, b2[i] = b[i].val;\n\
    \  auto c0 = middle_product<mint0>(a0, b0);\n  auto c1 = middle_product<mint1>(a1,\
    \ b1);\n  auto c2 = middle_product<mint2>(a2, b2);\n  static const long long m01\
    \ = 1LL * nttprimes[0] * nttprimes[1];\n  static const long long m0_inv_m1 = mint1(nttprimes[0]).inverse().val;\n\
    \  static const long long m01_inv_m2 = mint2(m01).inverse().val;\n  static const\
    \ int mod = mint::get_mod();\n  auto garner = [&](mint0 x0, mint1 x1, mint2 x2)\
    \ -> mint {\n    int r0 = x0.val, r1 = x1.val, r2 = x2.val;\n    int v1 = (m0_inv_m1\
    \ * (r1 + nttprimes[1] - r0)) % nttprimes[1];\n    auto v2 = (mint2(r2) - r0 -\
    \ mint2(nttprimes[0]) * v1) * mint2(m01_inv_m2);\n    return mint(r0 + 1LL * nttprimes[0]\
    \ * v1 + m01 % mod * v2.val);\n  };\n  vc<mint> c(len(c0));\n  FOR(i, len(c))\
    \ c[i] = garner(c0[i], c1[i], c2[i]);\n  return c;\n}\n\ntemplate <typename mint>\n\
    vc<mint> middle_product_naive(vc<mint>& a, vc<mint>& b) {\n  vc<mint> res(len(a)\
    \ - len(b) + 1);\n  FOR(i, len(res)) FOR(j, len(b)) res[i] += b[j] * a[i + j];\n\
    \  return res;\n}"
  dependsOn:
  - poly/ntt.hpp
  isVerificationFile: false
  path: poly/middle_product.hpp
  requiredBy:
  - linalg/implicit_matrix/vandermonde.hpp
  - string/wildcard_pattern_matching.hpp
  - poly/multipoint.hpp
  - poly/partial_frac_decomposition.hpp
  - poly/multivar_convolution_cyclic.hpp
  - poly/slice_rational_fps.hpp
  timestamp: '2023-04-27 05:11:08+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc272_h.test.cpp
  - test_atcoder/agc013e.test.cpp
  - test_atcoder/abc267g.test.cpp
  - test/yukicoder/2231.test.cpp
  - test/yukicoder/2243.test.cpp
  - test/yukicoder/2166.test.cpp
  - test/library_checker/polynomial/multipoint_evaluation.test.cpp
  - test/library_checker/polynomial/polynomial_interpolation.test.cpp
  - test/library_checker/polynomial/multipoint_evaluation_on_geom.test.cpp
  - test/library_checker/polynomial/multipoint_evaluation_on_geom_2.test.cpp
  - test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - test/mytest/partial_frac.test.cpp
  - test/mytest/vandermonde.test.cpp
  - test/mytest/chirp_z.test.cpp
  - test/mytest/slice_rational_fps.test.cpp
documentation_of: poly/middle_product.hpp
layout: document
redirect_from:
- /library/poly/middle_product.hpp
- /library/poly/middle_product.hpp.html
title: poly/middle_product.hpp
---
