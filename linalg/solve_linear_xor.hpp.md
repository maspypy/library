---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1421.test.cpp
    title: test/yukicoder/1421.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/solve_linear_xor.hpp\"\n/*\na \u306F 01 \u884C\u5217\
    \u3001b \u306F long long\nXOR = b \u3092\u89E3\u304F\u3002\n\u89E3\u306A\u3057\
    \uFF1Aempty\u3001\u89E3\u3042\u308A\uFF1A\u305D\u306E\u3072\u3068\u3064\n\u30FB\
    \u89E3\u7A7A\u9593\u306E\u8A73\u3057\u3044\u69CB\u9020\u304C\u6B32\u3057\u3044\
    \u5834\u5408\u306B\u306F\u3001\u6841\u3054\u3068\u306B F2 \u7DDA\u5F62\u4EE3\u6570\
    \u3059\u308B\u3053\u3068\uFF01\n*/\ntemplate <typename T>\nvc<T> solve_linear_xor(const\
    \ int n, const int m, vc<vc<T>> a, vc<T> b) {\n  int rk = 0;\n  FOR(j, m) {\n\
    \    if (a[rk][j] == 0) {\n      FOR3(i, rk + 1, n) if (a[i][j] != 0) {\n    \
    \    swap(a[rk], a[i]);\n        swap(b[rk], b[i]);\n        break;\n      }\n\
    \    }\n    if (a[rk][j] == 0) continue;\n    FOR(i, n) if (i != rk) {\n     \
    \ if (!a[i][j]) continue;\n      b[i] ^= b[rk];\n      FOR3(k, j, m) { a[i][k]\
    \ ^= a[rk][k]; }\n    }\n    ++rk;\n    if (rk == n) break;\n  }\n  FOR3(i, rk,\
    \ n) if (b[i] != 0) return {};\n  vc<T> x(m);\n  int p = 0;\n  FOR(i, rk) {\n\
    \    while (a[i][p] == 0) ++p;\n    x[p] = b[i];\n  }\n  return x;\n}\n"
  code: "/*\na \u306F 01 \u884C\u5217\u3001b \u306F long long\nXOR = b \u3092\u89E3\
    \u304F\u3002\n\u89E3\u306A\u3057\uFF1Aempty\u3001\u89E3\u3042\u308A\uFF1A\u305D\
    \u306E\u3072\u3068\u3064\n\u30FB\u89E3\u7A7A\u9593\u306E\u8A73\u3057\u3044\u69CB\
    \u9020\u304C\u6B32\u3057\u3044\u5834\u5408\u306B\u306F\u3001\u6841\u3054\u3068\
    \u306B F2 \u7DDA\u5F62\u4EE3\u6570\u3059\u308B\u3053\u3068\uFF01\n*/\ntemplate\
    \ <typename T>\nvc<T> solve_linear_xor(const int n, const int m, vc<vc<T>> a,\
    \ vc<T> b) {\n  int rk = 0;\n  FOR(j, m) {\n    if (a[rk][j] == 0) {\n      FOR3(i,\
    \ rk + 1, n) if (a[i][j] != 0) {\n        swap(a[rk], a[i]);\n        swap(b[rk],\
    \ b[i]);\n        break;\n      }\n    }\n    if (a[rk][j] == 0) continue;\n \
    \   FOR(i, n) if (i != rk) {\n      if (!a[i][j]) continue;\n      b[i] ^= b[rk];\n\
    \      FOR3(k, j, m) { a[i][k] ^= a[rk][k]; }\n    }\n    ++rk;\n    if (rk ==\
    \ n) break;\n  }\n  FOR3(i, rk, n) if (b[i] != 0) return {};\n  vc<T> x(m);\n\
    \  int p = 0;\n  FOR(i, rk) {\n    while (a[i][p] == 0) ++p;\n    x[p] = b[i];\n\
    \  }\n  return x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/solve_linear_xor.hpp
  requiredBy: []
  timestamp: '2022-11-06 01:50:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1421.test.cpp
documentation_of: linalg/solve_linear_xor.hpp
layout: document
redirect_from:
- /library/linalg/solve_linear_xor.hpp
- /library/linalg/solve_linear_xor.hpp.html
title: linalg/solve_linear_xor.hpp
---
