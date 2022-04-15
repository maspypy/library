---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/matrix/hafnian_of_matrix.test.cpp
    title: test/library_checker/matrix/hafnian_of_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/hafnian.hpp\"\ntemplate <typename mint, int LIM =\
    \ 50>\r\nmint Hufnian(vc<vc<mint>>& B0) {\r\n  // \u96A3\u63A5\u884C\u5217\u306B\
    \u5BFE\u3057\u3066\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u6570\u3048\
    \u308B\u3002\r\n  int n = len(B0) / 2;\r\n  using poly = array<mint, LIM / 2>;\r\
    \n  auto add_mul = [&](poly& p, poly& f, poly& g) -> void {\r\n    FOR(i, n) FOR(j,\
    \ n - i) p[i + j + 1] += f[i] * g[j];\r\n  };\r\n  auto dfs = [&](auto self, vc<vc<poly>>\
    \ B) -> poly {\r\n    poly res;\r\n    if (len(B) == 0) {\r\n      res[0] = 1;\r\
    \n      return res;\r\n    }\r\n    auto a = B.back();\r\n    B.pop_back();\r\n\
    \    auto b = B.back();\r\n    B.pop_back();\r\n    int m = len(B);\r\n    poly\
    \ p0 = self(self, B);\r\n    FOR(i, m) FOR(j, i) {\r\n      add_mul(B[i][j], a[i],\
    \ b[j]);\r\n      add_mul(B[i][j], a[j], b[i]);\r\n    }\r\n    poly p1 = self(self,\
    \ B);\r\n    add_mul(res, a[m], p1);\r\n    FOR(i, n + 1) res[i] += p1[i] - p0[i];\r\
    \n    return res;\r\n  };\r\n  vv(poly, B, n + n, n + n);\r\n  FOR(i, n + n) FOR(j,\
    \ n + n) B[i][j][0] = B0[i][j];\r\n  return dfs(dfs, B)[n];\r\n}\r\n"
  code: "template <typename mint, int LIM = 50>\r\nmint Hufnian(vc<vc<mint>>& B0)\
    \ {\r\n  // \u96A3\u63A5\u884C\u5217\u306B\u5BFE\u3057\u3066\u5B8C\u5168\u30DE\
    \u30C3\u30C1\u30F3\u30B0\u3092\u6570\u3048\u308B\u3002\r\n  int n = len(B0) /\
    \ 2;\r\n  using poly = array<mint, LIM / 2>;\r\n  auto add_mul = [&](poly& p,\
    \ poly& f, poly& g) -> void {\r\n    FOR(i, n) FOR(j, n - i) p[i + j + 1] += f[i]\
    \ * g[j];\r\n  };\r\n  auto dfs = [&](auto self, vc<vc<poly>> B) -> poly {\r\n\
    \    poly res;\r\n    if (len(B) == 0) {\r\n      res[0] = 1;\r\n      return\
    \ res;\r\n    }\r\n    auto a = B.back();\r\n    B.pop_back();\r\n    auto b =\
    \ B.back();\r\n    B.pop_back();\r\n    int m = len(B);\r\n    poly p0 = self(self,\
    \ B);\r\n    FOR(i, m) FOR(j, i) {\r\n      add_mul(B[i][j], a[i], b[j]);\r\n\
    \      add_mul(B[i][j], a[j], b[i]);\r\n    }\r\n    poly p1 = self(self, B);\r\
    \n    add_mul(res, a[m], p1);\r\n    FOR(i, n + 1) res[i] += p1[i] - p0[i];\r\n\
    \    return res;\r\n  };\r\n  vv(poly, B, n + n, n + n);\r\n  FOR(i, n + n) FOR(j,\
    \ n + n) B[i][j][0] = B0[i][j];\r\n  return dfs(dfs, B)[n];\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/hafnian.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/matrix/hafnian_of_matrix.test.cpp
documentation_of: linalg/hafnian.hpp
layout: document
redirect_from:
- /library/linalg/hafnian.hpp
- /library/linalg/hafnian.hpp.html
title: linalg/hafnian.hpp
---
