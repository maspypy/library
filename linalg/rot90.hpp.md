---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc218c.test.cpp
    title: test_atcoder/abc218c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/rot90.hpp\"\ntemplate <typename VC>\nvc<VC> rot90(const\
    \ vc<VC>& A, bool counter_clockwise = true, int H = -1,\n             int W =\
    \ -1) {\n  if (H == -1) { H = len(A), W = len(A[0]); }\n  vc<VC> B(W, VC(H, A[0][0]));\n\
    \  if (counter_clockwise) {\n    FOR(x, H) FOR(y, W) B[W - 1 - y][x] = A[x][y];\n\
    \  } else {\n    FOR(x, H) FOR(y, W) B[y][H - 1 - x] = A[x][y];\n  }\n  return\
    \ B;\n}\n"
  code: "template <typename VC>\nvc<VC> rot90(const vc<VC>& A, bool counter_clockwise\
    \ = true, int H = -1,\n             int W = -1) {\n  if (H == -1) { H = len(A),\
    \ W = len(A[0]); }\n  vc<VC> B(W, VC(H, A[0][0]));\n  if (counter_clockwise) {\n\
    \    FOR(x, H) FOR(y, W) B[W - 1 - y][x] = A[x][y];\n  } else {\n    FOR(x, H)\
    \ FOR(y, W) B[y][H - 1 - x] = A[x][y];\n  }\n  return B;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/rot90.hpp
  requiredBy: []
  timestamp: '2023-10-24 14:07:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc218c.test.cpp
documentation_of: linalg/rot90.hpp
layout: document
redirect_from:
- /library/linalg/rot90.hpp
- /library/linalg/rot90.hpp.html
title: linalg/rot90.hpp
---
