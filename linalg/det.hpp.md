---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/count/BEST.hpp
    title: graph/count/BEST.hpp
  - icon: ':x:'
    path: graph/count/count_spanning_tree.hpp
    title: graph/count/count_spanning_tree.hpp
  - icon: ':heavy_check_mark:'
    path: random/random_matrix.hpp
    title: random/random_matrix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/blackbox_solve_linear.test.cpp
    title: test/1_mytest/blackbox_solve_linear.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/count_spanning_tree_directed_sparse.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_directed_sparse.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/counting_eulerian_dense.test.cpp
    title: test/2_library_checker/graph/counting_eulerian_dense.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/counting_eulerian_sparse.test.cpp
    title: test/2_library_checker/graph/counting_eulerian_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/det_mod.test.cpp
    title: test/2_library_checker/linear_algebra/det_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/matrix_det.test.cpp
    title: test/2_library_checker/linear_algebra/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1303.test.cpp
    title: test/3_yukicoder/1303.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/linalg/det.hpp
  bundledCode: "#line 1 \"linalg/det.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/linalg/det.hpp\n\
    #line 1 \"mod/barrett.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/mod/barrett.hpp\n\
    \n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 3 \"\
    linalg/det.hpp\"\n\nint det_mod(vvc<int> A, int mod) {\n  Barrett bt(mod);\n \
    \ const int n = len(A);\n  ll det = 1;\n  FOR(i, n) FOR(j, n) {\n    if (A[i][j]\
    \ < 0) A[i][j] += mod;\n  }\n  FOR(i, n) {\n    FOR(j, i, n) {\n      if (A[j][i]\
    \ == 0) continue;\n      if (i != j) {\n        swap(A[i], A[j]), det = mod -\
    \ det;\n      }\n      break;\n    }\n    FOR(j, i + 1, n) {\n      while (A[i][i]\
    \ != 0) {\n        ll c = mod - A[j][i] / A[i][i];\n        FOR_R(k, i, n) { A[j][k]\
    \ = bt.modulo(A[j][k] + A[i][k] * c); }\n        swap(A[i], A[j]), det = mod -\
    \ det;\n      }\n      swap(A[i], A[j]), det = mod - det;\n    }\n  }\n  FOR(i,\
    \ n) det = bt.mul(det, A[i][i]);\n  return det % mod;\n}\n\ntemplate <typename\
    \ mint>\nmint det(vvc<mint>& A) {\n  const int n = len(A);\n  vv(int, B, n, n);\n\
    \  FOR(i, n) FOR(j, n) B[i][j] = A[i][j].val;\n  return det_mod(B, mint::get_mod());\n\
    }\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/linalg/det.hpp\n\
    #include \"mod/barrett.hpp\"\n\nint det_mod(vvc<int> A, int mod) {\n  Barrett\
    \ bt(mod);\n  const int n = len(A);\n  ll det = 1;\n  FOR(i, n) FOR(j, n) {\n\
    \    if (A[i][j] < 0) A[i][j] += mod;\n  }\n  FOR(i, n) {\n    FOR(j, i, n) {\n\
    \      if (A[j][i] == 0) continue;\n      if (i != j) {\n        swap(A[i], A[j]),\
    \ det = mod - det;\n      }\n      break;\n    }\n    FOR(j, i + 1, n) {\n   \
    \   while (A[i][i] != 0) {\n        ll c = mod - A[j][i] / A[i][i];\n        FOR_R(k,\
    \ i, n) { A[j][k] = bt.modulo(A[j][k] + A[i][k] * c); }\n        swap(A[i], A[j]),\
    \ det = mod - det;\n      }\n      swap(A[i], A[j]), det = mod - det;\n    }\n\
    \  }\n  FOR(i, n) det = bt.mul(det, A[i][i]);\n  return det % mod;\n}\n\ntemplate\
    \ <typename mint>\nmint det(vvc<mint>& A) {\n  const int n = len(A);\n  vv(int,\
    \ B, n, n);\n  FOR(i, n) FOR(j, n) B[i][j] = A[i][j].val;\n  return det_mod(B,\
    \ mint::get_mod());\n}\n"
  dependsOn:
  - mod/barrett.hpp
  isVerificationFile: false
  path: linalg/det.hpp
  requiredBy:
  - graph/count/BEST.hpp
  - graph/count/count_spanning_tree.hpp
  - random/random_matrix.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/blackbox_solve_linear.test.cpp
  - test/3_yukicoder/1303.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
  - test/2_library_checker/graph/counting_eulerian_sparse.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_directed_sparse.test.cpp
  - test/2_library_checker/graph/counting_eulerian_dense.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
  - test/2_library_checker/linear_algebra/det_mod.test.cpp
  - test/2_library_checker/linear_algebra/matrix_det.test.cpp
documentation_of: linalg/det.hpp
layout: document
redirect_from:
- /library/linalg/det.hpp
- /library/linalg/det.hpp.html
title: linalg/det.hpp
---
