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
  bundledCode: "#line 1 \"linalg/transpose.hpp\"\n// vvc<T> \u3068 vc<string> \u3092\
    \u60F3\u5B9A\ntemplate <typename VC>\nvc<VC> transpose(const vc<VC>& A) {\n  int\
    \ H = len(A), W = len(A[0]);\n  vc<VC> B(W, VC(H, A[0][0]));\n  FOR(x, H) FOR(y,\
    \ W) B[y][x] = A[x][y];\n  return B;\n}\n"
  code: "// vvc<T> \u3068 vc<string> \u3092\u60F3\u5B9A\ntemplate <typename VC>\n\
    vc<VC> transpose(const vc<VC>& A) {\n  int H = len(A), W = len(A[0]);\n  vc<VC>\
    \ B(W, VC(H, A[0][0]));\n  FOR(x, H) FOR(y, W) B[y][x] = A[x][y];\n  return B;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/transpose.hpp
  requiredBy: []
  timestamp: '2022-10-21 20:37:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/transpose.hpp
layout: document
redirect_from:
- /library/linalg/transpose.hpp
- /library/linalg/transpose.hpp.html
title: linalg/transpose.hpp
---
