---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: poly/sparse_FODE.hpp
    title: poly/sparse_FODE.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1080_2.test.cpp
    title: test/yukicoder/1080_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \    f[n + 1] = df[n] * inv<mint>(n + 1);\n  }\n  return f;\n}\n#line 2 \"poly/sparse_exp_of_div.hpp\"\
    \n\n// exp(f/g) \u3067 f,g \u304C sparse\ntemplate <typename mint>\nvc<mint> sparse_exp_of_div(const\
    \ vc<mint>& f, const vc<mint>& g) {\n  const int N = len(f);\n  assert(f[0] ==\
    \ mint(0));\n  assert(g[0] == mint(1));\n  using P = pair<int, mint>;\n  vc<P>\
    \ dat_f, dat_g;\n  FOR(i, len(f)) if (f[i] != mint(0)) dat_f.eb(i, f[i]);\n  FOR(i,\
    \ len(g)) if (g[i] != mint(0)) dat_g.eb(i, g[i]);\n  vc<mint> a(N), b(N);\n  //\
    \ a = g^2, b = fg'-f'g\n  for (auto&& [i, x]: dat_g) {\n    for (auto&& [j, y]:\
    \ dat_g) {\n      if (i + j < N) { a[i + j] += x * y; }\n    }\n  }\n  for (auto&&\
    \ [i, x]: dat_f) {\n    for (auto&& [j, y]: dat_g) {\n      if (i + j - 1 >= N)\
    \ continue;\n      b[i + j - 1] += x * y * mint(j - i);\n    }\n  }\n  return\
    \ sparse_FODE(a, b);\n}\n"
  code: "#include \"poly/sparse_FODE.hpp\"\n\n// exp(f/g) \u3067 f,g \u304C sparse\n\
    template <typename mint>\nvc<mint> sparse_exp_of_div(const vc<mint>& f, const\
    \ vc<mint>& g) {\n  const int N = len(f);\n  assert(f[0] == mint(0));\n  assert(g[0]\
    \ == mint(1));\n  using P = pair<int, mint>;\n  vc<P> dat_f, dat_g;\n  FOR(i,\
    \ len(f)) if (f[i] != mint(0)) dat_f.eb(i, f[i]);\n  FOR(i, len(g)) if (g[i] !=\
    \ mint(0)) dat_g.eb(i, g[i]);\n  vc<mint> a(N), b(N);\n  // a = g^2, b = fg'-f'g\n\
    \  for (auto&& [i, x]: dat_g) {\n    for (auto&& [j, y]: dat_g) {\n      if (i\
    \ + j < N) { a[i + j] += x * y; }\n    }\n  }\n  for (auto&& [i, x]: dat_f) {\n\
    \    for (auto&& [j, y]: dat_g) {\n      if (i + j - 1 >= N) continue;\n     \
    \ b[i + j - 1] += x * y * mint(j - i);\n    }\n  }\n  return sparse_FODE(a, b);\n\
    }"
  dependsOn:
  - poly/sparse_FODE.hpp
  isVerificationFile: false
  path: poly/sparse_exp_of_div.hpp
  requiredBy: []
  timestamp: '2022-11-06 13:30:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1080_2.test.cpp
documentation_of: poly/sparse_exp_of_div.hpp
layout: document
redirect_from:
- /library/poly/sparse_exp_of_div.hpp
- /library/poly/sparse_exp_of_div.hpp.html
title: poly/sparse_exp_of_div.hpp
---
