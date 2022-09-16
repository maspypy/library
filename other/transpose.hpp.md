---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1434.test.cpp
    title: test/yukicoder/1434.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/transpose.hpp\"\n// vvc<T> \u3068 vc<string> \u3092\
    \u60F3\u5B9A\ntemplate <typename VC>\nvc<VC> transpose(const vc<VC>& A) {\n  int\
    \ H = len(A), W = len(A[0]);\n  vc<VC> B(W, VC(H, A[0][0]));\n  FOR(x, H) FOR(y,\
    \ W) B[y][x] = A[x][y];\n  return B;\n}\n"
  code: "// vvc<T> \u3068 vc<string> \u3092\u60F3\u5B9A\ntemplate <typename VC>\n\
    vc<VC> transpose(const vc<VC>& A) {\n  int H = len(A), W = len(A[0]);\n  vc<VC>\
    \ B(W, VC(H, A[0][0]));\n  FOR(x, H) FOR(y, W) B[y][x] = A[x][y];\n  return B;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: other/transpose.hpp
  requiredBy: []
  timestamp: '2022-09-16 18:52:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1434.test.cpp
documentation_of: other/transpose.hpp
layout: document
redirect_from:
- /library/other/transpose.hpp
- /library/other/transpose.hpp.html
title: other/transpose.hpp
---
