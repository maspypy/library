---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: poly/sparse_FODE.hpp
    title: poly/sparse_FODE.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/sparse_FODE.hpp\"\n\n// a(x)F'(x) + b(x)F(x) = 0 \u306E\
    \u5F62\u306E\u5FAE\u5206\u65B9\u7A0B\u5F0F\u3092\u89E3\u304F\n// [x^0]a=1 \u3092\
    \u4EEE\u5B9A\u3001[x^0]F=1 \u3068\u306A\u308B\u89E3\u3092\u6C42\u3081\u308B\n\
    // a, b \u304C sparse \u3067\u3042\u308B\u3068\u3057\u3066\u3001O(NK) \u6642\u9593\
    \ntemplate <typename mint>\nvc<mint> sparse_FODE(const vc<mint>& a, const vc<mint>&\
    \ b) {\n  const int N = len(a);\n  assert(len(b) == N);\n  assert(a[0] == mint(1));\n\
    \  using P = pair<int, mint>;\n\n  vc<P> dat_a, dat_b;\n  FOR(i, 1, N) if (a[i]\
    \ != mint(0)) dat_a.eb(i, a[i]);\n  FOR(i, 0, N) if (b[i] != mint(0)) dat_b.eb(i,\
    \ b[i]);\n\n  vc<mint> f(N);\n  vc<mint> df(N - 1);\n  f[0] = mint(1);\n  FOR(n,\
    \ N - 1) {\n    mint v = 0;\n    for (auto&& [i, ai]: dat_a) {\n      if (i >\
    \ n) break;\n      v += ai * df[n - i];\n    }\n    for (auto&& [i, bi]: dat_b)\
    \ {\n      if (i > n) break;\n      v += bi * f[n - i];\n    }\n    df[n] = -v;\n\
    \    f[n + 1] = df[n] * inv<mint>(n + 1);\n  }\n  return f;\n}\n#line 2 \"poly/sparse_pow_product.hpp\"\
    \n\n// f^ng^m\ntemplate <typename mint>\nvc<mint> sparse_pow_product(vc<mint>&\
    \ f, vc<mint>& g, mint n, mint m) {\n  const int N = len(f);\n  assert(f[0] ==\
    \ mint(1));\n  assert(g[0] == mint(1));\n  using P = pair<int, mint>;\n  vc<P>\
    \ dat_f, dat_g;\n  FOR(i, len(f)) if (f[i] != mint(0)) dat_f.eb(i, f[i]);\n  FOR(i,\
    \ len(g)) if (g[i] != mint(0)) dat_g.eb(i, g[i]);\n  vc<mint> a(N), b(N);\n  for\
    \ (auto&& [i, x]: dat_f) {\n    for (auto&& [j, y]: dat_g) {\n      if (i + j\
    \ >= N + 1) continue;\n      mint xy = x * y;\n      if (i + j < N) a[i + j] +=\
    \ xy;\n      if (0 < i + j && i + j <= N) {\n        b[i + j - 1] -= xy * (n *\
    \ mint(i) + m * mint(j));\n      }\n    }\n  }\n  return sparse_FODE(a, b);\n\
    }\n"
  code: "#include \"poly/sparse_FODE.hpp\"\n\n// f^ng^m\ntemplate <typename mint>\n\
    vc<mint> sparse_pow_product(vc<mint>& f, vc<mint>& g, mint n, mint m) {\n  const\
    \ int N = len(f);\n  assert(f[0] == mint(1));\n  assert(g[0] == mint(1));\n  using\
    \ P = pair<int, mint>;\n  vc<P> dat_f, dat_g;\n  FOR(i, len(f)) if (f[i] != mint(0))\
    \ dat_f.eb(i, f[i]);\n  FOR(i, len(g)) if (g[i] != mint(0)) dat_g.eb(i, g[i]);\n\
    \  vc<mint> a(N), b(N);\n  for (auto&& [i, x]: dat_f) {\n    for (auto&& [j, y]:\
    \ dat_g) {\n      if (i + j >= N + 1) continue;\n      mint xy = x * y;\n    \
    \  if (i + j < N) a[i + j] += xy;\n      if (0 < i + j && i + j <= N) {\n    \
    \    b[i + j - 1] -= xy * (n * mint(i) + m * mint(j));\n      }\n    }\n  }\n\
    \  return sparse_FODE(a, b);\n}"
  dependsOn:
  - poly/sparse_FODE.hpp
  isVerificationFile: false
  path: poly/sparse_pow_product.hpp
  requiredBy: []
  timestamp: '2022-11-06 03:50:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/sparse_pow_product.hpp
layout: document
redirect_from:
- /library/poly/sparse_pow_product.hpp
- /library/poly/sparse_pow_product.hpp.html
title: poly/sparse_pow_product.hpp
---
