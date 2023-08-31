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
  bundledCode: "#line 1 \"linalg/rot90.hpp\"\ntemplate <typename VC>\nvc<VC> rot90(const\
    \ int n, const int m, const vc<VC>& A,\n             bool counter_clockwise =\
    \ true) {\n  vc<VC> B(m, VC(n, A[0][0]));\n  if (counter_clockwise) {\n    FOR(x,\
    \ n) FOR(y, m) B[m - 1 - y][x] = A[x][y];\n  } else {\n    FOR(x, n) FOR(y, m)\
    \ B[y][n - 1 - x] = A[x][y];\n  }\n  return B;\n}\n"
  code: "template <typename VC>\nvc<VC> rot90(const int n, const int m, const vc<VC>&\
    \ A,\n             bool counter_clockwise = true) {\n  vc<VC> B(m, VC(n, A[0][0]));\n\
    \  if (counter_clockwise) {\n    FOR(x, n) FOR(y, m) B[m - 1 - y][x] = A[x][y];\n\
    \  } else {\n    FOR(x, n) FOR(y, m) B[y][n - 1 - x] = A[x][y];\n  }\n  return\
    \ B;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/rot90.hpp
  requiredBy: []
  timestamp: '2023-09-01 06:23:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/rot90.hpp
layout: document
redirect_from:
- /library/linalg/rot90.hpp
- /library/linalg/rot90.hpp.html
title: linalg/rot90.hpp
---
