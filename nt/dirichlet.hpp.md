---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: nt/integer_kth_root.hpp
    title: nt/integer_kth_root.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/dirichlet.test.cpp
    title: test/1_mytest/dirichlet.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/integer_kth_root.hpp\"\nu64 integer_kth_root(u64 k, u64\
    \ a) {\r\n  assert(k >= 1);\r\n  if (a == 0 || a == 1 || k == 1) return a;\r\n\
    \  if (k >= 64) return 1;\r\n  if (k == 2) return sqrtl(a);\r\n  if (a == u64(-1))\
    \ --a;\r\n  struct S {\r\n    u64 v;\r\n    S& operator*=(const S& o) {\r\n  \
    \    v = v <= u64(-1) / o.v ? v * o.v : u64(-1);\r\n      return *this;\r\n  \
    \  }\r\n  };\r\n  auto power = [&](S x, ll n) -> S {\r\n    S v{1};\r\n    while\
    \ (n) {\r\n      if (n & 1) v *= x;\r\n      x *= x;\r\n      n /= 2;\r\n    }\r\
    \n    return v;\r\n  };\r\n  u64 res = pow(a, nextafter(1 / double(k), 0));\r\n\
    \  while (power(S{res + 1}, k).v <= a) ++res;\r\n  return res;\r\n}\r\n#line 2\
    \ \"nt/dirichlet.hpp\"\n\n// Dirichlet \u7D1A\u6570\u81EA\u4F53\u306F vc<T> \u3067\
    \u6301\u3064\u3053\u3068\u306B\u3059\u308B.\n// \u3053\u306E\u69CB\u9020\u4F53\
    \u304C\u305D\u308C\u306B\u5BFE\u3059\u308B\u64CD\u4F5C\u3092\u6301\u3063\u3066\
    \u3044\u308B\u3053\u3068\u306B\u3059\u308B.\nstruct Dirichlet {\n  u64 N;\n  u32\
    \ t, sq, n;\n  Dirichlet(u64 N) : N(N) {\n    assert(N <= u64(1) << 50);\n   \
    \ sq = sqrtl(N);\n    t = (u64(sq) * sq + sq <= N ? sq : sq - 1);\n    n = t +\
    \ sq + 1;\n    // [0,1,...,t,N/sq,...,N/1] (t<sq \u306E\u5834\u5408\u306E sq \u3082\
    \u4E21\u5BFE\u5FDC)\n  };\n\n  inline u32 get_index(u64 d) {\n    assert(d > 0);\n\
    \    return (d <= t ? d : n - u32(double(N) / d));\n  }\n\n  inline u64 get_floor(u32\
    \ i) { return (i <= t ? i : double(N) / (n - i)); }\n\n  template <typename T>\n\
    \  vc<T> convolution(vc<T> &F, vc<T> &G) {\n    assert(len(F) == n && len(G) ==\
    \ n);\n    if (N == 1) return {T(0), F[1] * G[1]};\n    vc<T> f(n), g(n);\n  \
    \  FOR(i, 1, n) f[i] = F[i] - F[i - 1];\n    FOR(i, 1, n) g[i] = G[i] - G[i -\
    \ 1];\n\n    vc<T> H(n);\n    u64 K = integer_kth_root(3, N);\n    u64 S = K *\
    \ K;\n    // S \u4EE5\u4E0B\u3067\u3042\u308B\u3088\u3046\u306A\u5546\u306B\u3064\
    \u3044\u3066\n    for (u64 a = 1; a <= K; ++a) {\n      H[(a * a <= sq ? a * a\
    \ : n - N / (a * a))] += f[a] * g[a];\n      if (a * (a + 1) <= t) {  // a * small\
    \ = small\n        u64 ub = t / a;\n        for (u64 b = a + 1; b <= ub; ++b)\
    \ {\n          H[a * b] += f[a] * g[b] + f[b] * g[a];\n        }\n      }\n  \
    \    // a * small = large\n      {\n        u64 q = min<u64>(S / a, t);\n    \
    \    for (u64 b = max(a, t / a) + 1; b <= q; ++b) {\n          H[n - N / (a *\
    \ b)] += f[a] * g[b] + f[b] * g[a];\n        }\n      }\n      // a * large =\
    \ large\n      if (N / sq <= S / a) {\n        u64 p = N / (S / a + 1) + 1;\n\
    \        for (u64 b = p; b <= sq; ++b) {\n          H[n - N / (a * (N / b))] +=\
    \ f[a] * g[n - b] + g[a] * f[n - b];\n        }\n      }\n    }\n    FOR(i, 1,\
    \ n) H[i] += H[i - 1];\n    for (u64 z = 1; N / z > S; ++z) {\n      u64 M = N\
    \ / z;\n      u64 ub = sqrtl(M);\n      H[n - z] = 0;\n      for (u64 a = 1; a\
    \ <= ub; ++a) {\n        int idx = get_index(M / a);\n        H[n - z] += f[a]\
    \ * G[idx] + g[a] * F[idx];\n      }\n      H[n - z] -= F[ub] * G[ub];\n    }\n\
    \    return H;\n  }\n};\n"
  code: "#include \"nt/integer_kth_root.hpp\"\n\n// Dirichlet \u7D1A\u6570\u81EA\u4F53\
    \u306F vc<T> \u3067\u6301\u3064\u3053\u3068\u306B\u3059\u308B.\n// \u3053\u306E\
    \u69CB\u9020\u4F53\u304C\u305D\u308C\u306B\u5BFE\u3059\u308B\u64CD\u4F5C\u3092\
    \u6301\u3063\u3066\u3044\u308B\u3053\u3068\u306B\u3059\u308B.\nstruct Dirichlet\
    \ {\n  u64 N;\n  u32 t, sq, n;\n  Dirichlet(u64 N) : N(N) {\n    assert(N <= u64(1)\
    \ << 50);\n    sq = sqrtl(N);\n    t = (u64(sq) * sq + sq <= N ? sq : sq - 1);\n\
    \    n = t + sq + 1;\n    // [0,1,...,t,N/sq,...,N/1] (t<sq \u306E\u5834\u5408\
    \u306E sq \u3082\u4E21\u5BFE\u5FDC)\n  };\n\n  inline u32 get_index(u64 d) {\n\
    \    assert(d > 0);\n    return (d <= t ? d : n - u32(double(N) / d));\n  }\n\n\
    \  inline u64 get_floor(u32 i) { return (i <= t ? i : double(N) / (n - i)); }\n\
    \n  template <typename T>\n  vc<T> convolution(vc<T> &F, vc<T> &G) {\n    assert(len(F)\
    \ == n && len(G) == n);\n    if (N == 1) return {T(0), F[1] * G[1]};\n    vc<T>\
    \ f(n), g(n);\n    FOR(i, 1, n) f[i] = F[i] - F[i - 1];\n    FOR(i, 1, n) g[i]\
    \ = G[i] - G[i - 1];\n\n    vc<T> H(n);\n    u64 K = integer_kth_root(3, N);\n\
    \    u64 S = K * K;\n    // S \u4EE5\u4E0B\u3067\u3042\u308B\u3088\u3046\u306A\
    \u5546\u306B\u3064\u3044\u3066\n    for (u64 a = 1; a <= K; ++a) {\n      H[(a\
    \ * a <= sq ? a * a : n - N / (a * a))] += f[a] * g[a];\n      if (a * (a + 1)\
    \ <= t) {  // a * small = small\n        u64 ub = t / a;\n        for (u64 b =\
    \ a + 1; b <= ub; ++b) {\n          H[a * b] += f[a] * g[b] + f[b] * g[a];\n \
    \       }\n      }\n      // a * small = large\n      {\n        u64 q = min<u64>(S\
    \ / a, t);\n        for (u64 b = max(a, t / a) + 1; b <= q; ++b) {\n         \
    \ H[n - N / (a * b)] += f[a] * g[b] + f[b] * g[a];\n        }\n      }\n     \
    \ // a * large = large\n      if (N / sq <= S / a) {\n        u64 p = N / (S /\
    \ a + 1) + 1;\n        for (u64 b = p; b <= sq; ++b) {\n          H[n - N / (a\
    \ * (N / b))] += f[a] * g[n - b] + g[a] * f[n - b];\n        }\n      }\n    }\n\
    \    FOR(i, 1, n) H[i] += H[i - 1];\n    for (u64 z = 1; N / z > S; ++z) {\n \
    \     u64 M = N / z;\n      u64 ub = sqrtl(M);\n      H[n - z] = 0;\n      for\
    \ (u64 a = 1; a <= ub; ++a) {\n        int idx = get_index(M / a);\n        H[n\
    \ - z] += f[a] * G[idx] + g[a] * F[idx];\n      }\n      H[n - z] -= F[ub] * G[ub];\n\
    \    }\n    return H;\n  }\n};\n"
  dependsOn:
  - nt/integer_kth_root.hpp
  isVerificationFile: false
  path: nt/dirichlet.hpp
  requiredBy: []
  timestamp: '2025-08-07 22:56:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/dirichlet.test.cpp
documentation_of: nt/dirichlet.hpp
layout: document
redirect_from:
- /library/nt/dirichlet.hpp
- /library/nt/dirichlet.hpp.html
title: nt/dirichlet.hpp
---
