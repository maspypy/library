---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  _extendedRequiredBy: []
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
    \ * b); }\n};\n\nstruct Barrett_64 {\n  u128 mod, mh, ml;\n\n  explicit Barrett_64(u64\
    \ mod = 1) : mod(mod) {\n    u128 m = u128(-1) / mod;\n    if (m * mod + mod ==\
    \ u128(0)) ++m;\n    mh = m >> 64;\n    ml = m & u64(-1);\n  }\n\n  u64 umod()\
    \ const { return mod; }\n\n  u64 modulo(u128 x) {\n    u128 z = (x & u64(-1))\
    \ * ml;\n    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n    z = (x\
    \ >> 64) * mh + (z >> 64);\n    x -= z * mod;\n    return x < mod ? x : x - mod;\n\
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 2 \"\
    linalg/det.hpp\"\n\r\nint det_mod(vvc<int> A, int mod) {\r\n  Barrett bt(mod);\r\
    \n  const int n = len(A);\r\n  ll det = 1;\r\n  FOR(i, n) {\r\n    FOR(j, i, n)\
    \ {\r\n      if (A[j][i] == 0) continue;\r\n      if (i != j) { swap(A[i], A[j]),\
    \ det = mod - det; }\r\n      break;\r\n    }\r\n    FOR(j, i + 1, n) {\r\n  \
    \    while (A[i][i] != 0) {\r\n        ll c = mod - A[j][i] / A[i][i];\r\n   \
    \     FOR_R(k, i, n) { A[j][k] = bt.modulo(A[j][k] + A[i][k] * c); }\r\n     \
    \   swap(A[i], A[j]), det = mod - det;\r\n      }\r\n      swap(A[i], A[j]), det\
    \ = mod - det;\r\n    }\r\n  }\r\n  FOR(i, n) det = bt.mul(det, A[i][i]);\r\n\
    \  return det % mod;\r\n}\r\n\r\ntemplate <typename mint>\r\nmint det(vvc<mint>&\
    \ A) {\r\n  const int n = len(A);\r\n  vv(int, B, n, n);\r\n  FOR(i, n) FOR(j,\
    \ n) B[i][j] = A[i][j].val;\r\n  return det_mod(B, mint::get_mod());\r\n}\r\n"
  code: "#include \"mod/barrett.hpp\"\r\n\r\nint det_mod(vvc<int> A, int mod) {\r\n\
    \  Barrett bt(mod);\r\n  const int n = len(A);\r\n  ll det = 1;\r\n  FOR(i, n)\
    \ {\r\n    FOR(j, i, n) {\r\n      if (A[j][i] == 0) continue;\r\n      if (i\
    \ != j) { swap(A[i], A[j]), det = mod - det; }\r\n      break;\r\n    }\r\n  \
    \  FOR(j, i + 1, n) {\r\n      while (A[i][i] != 0) {\r\n        ll c = mod -\
    \ A[j][i] / A[i][i];\r\n        FOR_R(k, i, n) { A[j][k] = bt.modulo(A[j][k] +\
    \ A[i][k] * c); }\r\n        swap(A[i], A[j]), det = mod - det;\r\n      }\r\n\
    \      swap(A[i], A[j]), det = mod - det;\r\n    }\r\n  }\r\n  FOR(i, n) det =\
    \ bt.mul(det, A[i][i]);\r\n  return det % mod;\r\n}\r\n\r\ntemplate <typename\
    \ mint>\r\nmint det(vvc<mint>& A) {\r\n  const int n = len(A);\r\n  vv(int, B,\
    \ n, n);\r\n  FOR(i, n) FOR(j, n) B[i][j] = A[i][j].val;\r\n  return det_mod(B,\
    \ mint::get_mod());\r\n}\r\n"
  dependsOn:
  - mod/barrett.hpp
  isVerificationFile: false
  path: linalg/det.hpp
  requiredBy: []
  timestamp: '2023-10-24 14:53:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/matrix/det_mod.test.cpp
  - test/library_checker/matrix/matrix_det.test.cpp
  - test/yukicoder/1303.test.cpp
documentation_of: linalg/det.hpp
layout: document
redirect_from:
- /library/linalg/det.hpp
- /library/linalg/det.hpp.html
title: linalg/det.hpp
---
