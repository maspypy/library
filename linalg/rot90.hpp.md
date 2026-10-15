---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/linalg/rot90.hpp
  bundledCode: "#line 1 \"linalg/rot90.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/linalg/rot90.hpp\n\
    template <typename VC>\nvc<VC> rot90(const vc<VC>& A, bool counter_clockwise =\
    \ true, int H = -1,\n             int W = -1) {\n  if (H == -1) { H = len(A),\
    \ W = len(A[0]); }\n  vc<VC> B(W, VC(H, A[0][0]));\n  if (counter_clockwise) {\n\
    \    FOR(x, H) FOR(y, W) B[W - 1 - y][x] = A[x][y];\n  } else {\n    FOR(x, H)\
    \ FOR(y, W) B[y][H - 1 - x] = A[x][y];\n  }\n  return B;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/linalg/rot90.hpp\n\
    template <typename VC>\nvc<VC> rot90(const vc<VC>& A, bool counter_clockwise =\
    \ true, int H = -1,\n             int W = -1) {\n  if (H == -1) { H = len(A),\
    \ W = len(A[0]); }\n  vc<VC> B(W, VC(H, A[0][0]));\n  if (counter_clockwise) {\n\
    \    FOR(x, H) FOR(y, W) B[W - 1 - y][x] = A[x][y];\n  } else {\n    FOR(x, H)\
    \ FOR(y, W) B[y][H - 1 - x] = A[x][y];\n  }\n  return B;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/rot90.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/rot90.hpp
layout: document
redirect_from:
- /library/linalg/rot90.hpp
- /library/linalg/rot90.hpp.html
title: linalg/rot90.hpp
---
