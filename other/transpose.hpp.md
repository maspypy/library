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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/transpose.hpp
layout: document
redirect_from:
- /library/other/transpose.hpp
- /library/other/transpose.hpp.html
title: other/transpose.hpp
---
