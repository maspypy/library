---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: linalg/implicit_matrix/det.hpp
    title: linalg/implicit_matrix/det.hpp
  - icon: ':x:'
    path: linalg/implicit_matrix/min_poly.hpp
    title: linalg/implicit_matrix/min_poly.hpp
  - icon: ':x:'
    path: linalg/spmat_det.hpp
    title: linalg/spmat_det.hpp
  - icon: ':x:'
    path: linalg/spmat_min_poly.hpp
    title: linalg/spmat_min_poly.hpp
  - icon: ':x:'
    path: seq/interpolate_linear_rec.hpp
    title: seq/interpolate_linear_rec.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/find_linear_recurrence.test.cpp
    title: test/library_checker/math/find_linear_recurrence.test.cpp
  - icon: ':x:'
    path: test/library_checker/matrix/implicit_matrix.test.cpp
    title: test/library_checker/matrix/implicit_matrix.test.cpp
  - icon: ':x:'
    path: test/library_checker/matrix/sparse_matrix_det.test.cpp
    title: test/library_checker/matrix/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1500.test.cpp
    title: test/yukicoder/1500.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1516.test.cpp
    title: test/yukicoder/1516.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1547.test.cpp
    title: test/yukicoder/1547.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1561.test.cpp
    title: test/yukicoder/1561.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1755.test.cpp
    title: test/yukicoder/1755.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1844.test.cpp
    title: test/yukicoder/1844.test.cpp
  - icon: ':x:'
    path: test/yukicoder/310.test.cpp
    title: test/yukicoder/310.test.cpp
  - icon: ':x:'
    path: test/yukicoder/541.test.cpp
    title: test/yukicoder/541.test.cpp
  - icon: ':x:'
    path: test/yukicoder/578.test.cpp
    title: test/yukicoder/578.test.cpp
  - icon: ':x:'
    path: test/yukicoder/579.test.cpp
    title: test/yukicoder/579.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"seq/find_linear_rec.hpp\"\n\r\ntemplate <typename mint>\r\
    \nvector<mint> find_linear_rec(vector<mint>& A) {\r\n  int N = len(A);\r\n  vc<mint>\
    \ B = {1}, C = {1};\r\n  int l = 0, m = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\
    \n    mint d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }\r\n  \
    \  if (d == 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\n    auto tmp = C;\r\
    \n    mint q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(), len(B)\
    \ + m - len(C), 0);\r\n    FOR(j, len(B)) C[j + m] -= q * B[j];\r\n    if (l +\
    \ l <= i) {\r\n      B = tmp;\r\n      l = i + 1 - l, m = 1;\r\n      p = d;\r\
    \n    } else {\r\n      ++m;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename mint>\r\nvector<mint> find_linear_rec(vector<mint>&\
    \ A) {\r\n  int N = len(A);\r\n  vc<mint> B = {1}, C = {1};\r\n  int l = 0, m\
    \ = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\n    mint d = A[i];\r\n    FOR3(j,\
    \ 1, l + 1) { d += C[j] * A[i - j]; }\r\n    if (d == 0) {\r\n      ++m;\r\n \
    \     continue;\r\n    }\r\n    auto tmp = C;\r\n    mint q = d / p;\r\n    if\
    \ (len(C) < len(B) + m) C.insert(C.end(), len(B) + m - len(C), 0);\r\n    FOR(j,\
    \ len(B)) C[j + m] -= q * B[j];\r\n    if (l + l <= i) {\r\n      B = tmp;\r\n\
    \      l = i + 1 - l, m = 1;\r\n      p = d;\r\n    } else {\r\n      ++m;\r\n\
    \    }\r\n  }\r\n  return C;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/find_linear_rec.hpp
  requiredBy:
  - linalg/spmat_min_poly.hpp
  - linalg/implicit_matrix/min_poly.hpp
  - linalg/implicit_matrix/det.hpp
  - linalg/spmat_det.hpp
  - seq/interpolate_linear_rec.hpp
  timestamp: '2022-05-11 21:07:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/310.test.cpp
  - test/yukicoder/1844.test.cpp
  - test/yukicoder/578.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/1755.test.cpp
  - test/yukicoder/1516.test.cpp
  - test/yukicoder/1547.test.cpp
  - test/yukicoder/579.test.cpp
  - test/yukicoder/541.test.cpp
  - test/yukicoder/1500.test.cpp
  - test/library_checker/matrix/sparse_matrix_det.test.cpp
  - test/library_checker/matrix/implicit_matrix.test.cpp
  - test/library_checker/math/find_linear_recurrence.test.cpp
documentation_of: seq/find_linear_rec.hpp
layout: document
redirect_from:
- /library/seq/find_linear_rec.hpp
- /library/seq/find_linear_rec.hpp.html
title: seq/find_linear_rec.hpp
---
