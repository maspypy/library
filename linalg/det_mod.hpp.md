---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linalg/det.hpp
    title: linalg/det.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/det_mod.test.cpp
    title: test/library_checker/matrix/det_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_det.test.cpp
    title: test/library_checker/matrix/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return 0;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n#line 2 \"linalg/det_mod.hpp\"\n\nint det_mod(vvc<int> A, int m)\
    \ {\n  Barrett bt(m);\n  const int n = len(A);\n  ll det = 1;\n  FOR(i, n) {\n\
    \    FOR(j, i, n) {\n      if (A[j][i] == 0) continue;\n      if (i != j) { swap(A[i],\
    \ A[j]), det = m - det; }\n      break;\n    }\n    FOR(j, i + 1, n) {\n     \
    \ while (A[i][i] != 0) {\n        ll c = m - A[j][i] / A[i][i];\n        FOR_R(k,\
    \ i, n) { A[j][k] = bt.modulo(A[j][k] + A[i][k] * c); }\n        swap(A[i], A[j]),\
    \ det = m - det;\n      }\n      swap(A[i], A[j]), det = m - det;\n    }\n  }\n\
    \  FOR(i, n) det = bt.mul(det, A[i][i]);\n  return det;\n}\n"
  code: "#include \"mod/barrett.hpp\"\n\nint det_mod(vvc<int> A, int m) {\n  Barrett\
    \ bt(m);\n  const int n = len(A);\n  ll det = 1;\n  FOR(i, n) {\n    FOR(j, i,\
    \ n) {\n      if (A[j][i] == 0) continue;\n      if (i != j) { swap(A[i], A[j]),\
    \ det = m - det; }\n      break;\n    }\n    FOR(j, i + 1, n) {\n      while (A[i][i]\
    \ != 0) {\n        ll c = m - A[j][i] / A[i][i];\n        FOR_R(k, i, n) { A[j][k]\
    \ = bt.modulo(A[j][k] + A[i][k] * c); }\n        swap(A[i], A[j]), det = m - det;\n\
    \      }\n      swap(A[i], A[j]), det = m - det;\n    }\n  }\n  FOR(i, n) det\
    \ = bt.mul(det, A[i][i]);\n  return det;\n}"
  dependsOn:
  - mod/barrett.hpp
  isVerificationFile: false
  path: linalg/det_mod.hpp
  requiredBy:
  - linalg/det.hpp
  timestamp: '2023-05-12 18:15:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/matrix/det_mod.test.cpp
  - test/library_checker/matrix/matrix_det.test.cpp
  - test/yukicoder/1303.test.cpp
documentation_of: linalg/det_mod.hpp
layout: document
redirect_from:
- /library/linalg/det_mod.hpp
- /library/linalg/det_mod.hpp.html
title: linalg/det_mod.hpp
---
