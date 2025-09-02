---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: setfunc/ranked_zeta.hpp
    title: setfunc/ranked_zeta.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/ranked_zeta.hpp\"\n\r\ntemplate <typename T, int\
    \ LIM>\r\nvc<array<T, LIM + 1>> ranked_zeta(const vc<T>& f) {\r\n  int n = topbit(len(f));\r\
    \n  assert(n <= LIM);\r\n  assert(len(f) == 1 << n);\r\n  vc<array<T, LIM + 1>>\
    \ Rf(1 << n);\r\n  for (int s = 0; s < (1 << n); ++s) Rf[s][popcnt(s)] = f[s];\r\
    \n  for (int i = 0; i < n; ++i) {\r\n    int w = 1 << i;\r\n    for (int p = 0;\
    \ p < (1 << n); p += 2 * w) {\r\n      for (int s = p; s < p + w; ++s) {\r\n \
    \       int t = s | 1 << i;\r\n        for (int d = 0; d <= n; ++d) Rf[t][d] +=\
    \ Rf[s][d];\r\n      }\r\n    }\r\n  }\r\n  return Rf;\r\n}\r\n\r\ntemplate <typename\
    \ T, int LIM>\r\nvc<T> ranked_mobius(vc<array<T, LIM + 1>>& Rf) {\r\n  int n =\
    \ topbit(len(Rf));\r\n  assert(len(Rf) == 1 << n);\r\n  for (int i = 0; i < n;\
    \ ++i) {\r\n    int w = 1 << i;\r\n    for (int p = 0; p < (1 << n); p += 2 *\
    \ w) {\r\n      for (int s = p; s < p + w; ++s) {\r\n        int t = s | 1 <<\
    \ i;\r\n        for (int d = 0; d <= n; ++d) Rf[t][d] -= Rf[s][d];\r\n      }\r\
    \n    }\r\n  }\r\n  vc<T> f(1 << n);\r\n  for (int s = 0; s < (1 << n); ++s) f[s]\
    \ = Rf[s][popcnt(s)];\r\n  return f;\r\n}\n#line 2 \"setfunc/sps_inv.hpp\"\n\n\
    template <typename mint, int LIM>\nvc<mint> sps_inv(vc<mint>& dp) {\n  const int\
    \ N = topbit(len(dp));\n  assert(len(dp) == (1 << N) && dp[0] == mint(1));\n \
    \ auto RA = ranked_zeta<mint, LIM>(dp);\n  array<mint, LIM + 1> g;\n  FOR(s, 1\
    \ << N) {\n    auto& f = RA[s];\n    g[0] = 1;\n    FOR(k, 1, N + 1) {\n     \
    \ g[k] = 0;\n      FOR(i, k) g[k] -= g[i] * f[k - i];\n    }\n    RA[s] = g;\n\
    \  }\n  return ranked_mobius<mint, LIM>(RA);\n}\n"
  code: "#include \"setfunc/ranked_zeta.hpp\"\n\ntemplate <typename mint, int LIM>\n\
    vc<mint> sps_inv(vc<mint>& dp) {\n  const int N = topbit(len(dp));\n  assert(len(dp)\
    \ == (1 << N) && dp[0] == mint(1));\n  auto RA = ranked_zeta<mint, LIM>(dp);\n\
    \  array<mint, LIM + 1> g;\n  FOR(s, 1 << N) {\n    auto& f = RA[s];\n    g[0]\
    \ = 1;\n    FOR(k, 1, N + 1) {\n      g[k] = 0;\n      FOR(i, k) g[k] -= g[i]\
    \ * f[k - i];\n    }\n    RA[s] = g;\n  }\n  return ranked_mobius<mint, LIM>(RA);\n\
    }\n"
  dependsOn:
  - setfunc/ranked_zeta.hpp
  isVerificationFile: false
  path: setfunc/sps_inv.hpp
  requiredBy: []
  timestamp: '2024-04-04 19:08:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/sps_inv.hpp
layout: document
redirect_from:
- /library/setfunc/sps_inv.hpp
- /library/setfunc/sps_inv.hpp.html
title: setfunc/sps_inv.hpp
---
