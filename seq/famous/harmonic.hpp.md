---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2645.test.cpp
    title: test/3_yukicoder/2645.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/famous/harmonic.hpp\"\n\n// \u8AA4\u5DEE O(N^{-6})\n\
    long double Harmonic(ll N) {\n  using Re = long double;\n  static vc<Re> dp(1000);\n\
    \  static bool prepare = 0;\n  if (!prepare) {\n    prepare = 1;\n    FOR(n, 1,\
    \ 1000) dp[n] = dp[n - 1] + Re(1) / n;\n  }\n  if (N < 1000) return dp[N];\n \
    \ Re x = logl(N);\n  Re gamma = 0.577215664901532860606512090;\n  x += gamma;\n\
    \  x += 0.5 / N;\n  x -= 1.0 / 12 / N / N;\n  x += 1.0 / 120 / N / N / N / N;\n\
    \  return x;\n}\n"
  code: "\n// \u8AA4\u5DEE O(N^{-6})\nlong double Harmonic(ll N) {\n  using Re = long\
    \ double;\n  static vc<Re> dp(1000);\n  static bool prepare = 0;\n  if (!prepare)\
    \ {\n    prepare = 1;\n    FOR(n, 1, 1000) dp[n] = dp[n - 1] + Re(1) / n;\n  }\n\
    \  if (N < 1000) return dp[N];\n  Re x = logl(N);\n  Re gamma = 0.577215664901532860606512090;\n\
    \  x += gamma;\n  x += 0.5 / N;\n  x -= 1.0 / 12 / N / N;\n  x += 1.0 / 120 /\
    \ N / N / N / N;\n  return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/harmonic.hpp
  requiredBy: []
  timestamp: '2024-09-12 07:35:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2645.test.cpp
documentation_of: seq/famous/harmonic.hpp
layout: document
redirect_from:
- /library/seq/famous/harmonic.hpp
- /library/seq/famous/harmonic.hpp.html
title: seq/famous/harmonic.hpp
---
