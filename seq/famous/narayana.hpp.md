---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/narayana.test.cpp
    title: test/1_mytest/narayana.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/agc070/tasks/agc070_c
  bundledCode: "#line 1 \"seq/famous/narayana.hpp\"\n\n// https://atcoder.jp/contests/agc070/tasks/agc070_c\n\
    // a>=b \u306E\u3068\u304D, (0,0) \u304B\u3089 (a,b) \u3078\u306E\u30D1\u30B9\u3067\
    \u3061\u3087\u3046\u3069 k \u56DE\u66F2\u304C\u308B.\n// \u666E\u901A\u306E narayana\
    \ number \u306F (n,n,2k-1)\ntemplate <typename mint>\nmint narayana_number(int\
    \ a, int b, int k) {\n  assert(0 <= a && 0 <= b && 0 <= k);\n  if (a < b) return\
    \ 0;\n  if (b == 0) return (k == 0 ? 1 : 0);\n\n  if (k % 2 == 1) {\n    k = (k\
    \ - 1) / 2;\n    return C<mint>(a - 1, k) * C<mint>(b - 1, k) - C<mint>(a - 1,\
    \ k - 1) * C<mint>(b - 1, k + 1);\n  }\n  k /= 2;\n  return C<mint>(a - 1, k)\
    \ * C<mint>(b - 1, k - 1) - C<mint>(a - 1, k - 1) * C<mint>(b - 1, k);\n}\n"
  code: "\n// https://atcoder.jp/contests/agc070/tasks/agc070_c\n// a>=b \u306E\u3068\
    \u304D, (0,0) \u304B\u3089 (a,b) \u3078\u306E\u30D1\u30B9\u3067\u3061\u3087\u3046\
    \u3069 k \u56DE\u66F2\u304C\u308B.\n// \u666E\u901A\u306E narayana number \u306F\
    \ (n,n,2k-1)\ntemplate <typename mint>\nmint narayana_number(int a, int b, int\
    \ k) {\n  assert(0 <= a && 0 <= b && 0 <= k);\n  if (a < b) return 0;\n  if (b\
    \ == 0) return (k == 0 ? 1 : 0);\n\n  if (k % 2 == 1) {\n    k = (k - 1) / 2;\n\
    \    return C<mint>(a - 1, k) * C<mint>(b - 1, k) - C<mint>(a - 1, k - 1) * C<mint>(b\
    \ - 1, k + 1);\n  }\n  k /= 2;\n  return C<mint>(a - 1, k) * C<mint>(b - 1, k\
    \ - 1) - C<mint>(a - 1, k - 1) * C<mint>(b - 1, k);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/narayana.hpp
  requiredBy: []
  timestamp: '2025-02-11 03:31:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/narayana.test.cpp
documentation_of: seq/famous/narayana.hpp
layout: document
redirect_from:
- /library/seq/famous/narayana.hpp
- /library/seq/famous/narayana.hpp.html
title: seq/famous/narayana.hpp
---
