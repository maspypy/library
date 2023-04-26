---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: poly/middle_product.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/middle_product.hpp
layout: document
redirect_from:
- /library/poly/middle_product.hpp
- /library/poly/middle_product.hpp.html
title: poly/middle_product.hpp
---
