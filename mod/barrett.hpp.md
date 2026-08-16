---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/count/BEST.hpp
    title: graph/count/BEST.hpp
  - icon: ':heavy_check_mark:'
    path: graph/count/count_labeled_bipartite.hpp
    title: graph/count/count_labeled_bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: graph/count/count_spanning_tree.hpp
    title: graph/count/count_spanning_tree.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/det.hpp
    title: linalg/det.hpp
  - icon: ':warning:'
    path: mod/dynamic_modint_64.hpp
    title: mod/dynamic_modint_64.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: random/random_matrix.hpp
    title: random/random_matrix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/blackbox_solve_linear.test.cpp
    title: test/1_mytest/blackbox_solve_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_bipartite.test.cpp
    title: test/1_mytest/count_bipartite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/count_spanning_tree_directed_sparse.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_directed_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/counting_eulerian_dense.test.cpp
    title: test/2_library_checker/graph/counting_eulerian_dense.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/counting_eulerian_sparse.test.cpp
    title: test/2_library_checker/graph/counting_eulerian_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/det_mod.test.cpp
    title: test/2_library_checker/linear_algebra/det_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/matrix_det.test.cpp
    title: test/2_library_checker/linear_algebra/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/sqrt_mod.test.cpp
    title: test/2_library_checker/number_theory/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/2_library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/2_library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1303.test.cpp
    title: test/3_yukicoder/1303.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/3229.test.cpp
    title: test/3_yukicoder/3229.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp
  bundledCode: "#line 1 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n"
  code: "\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
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
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mod/barrett.hpp
  requiredBy:
  - linalg/det.hpp
  - graph/count/count_spanning_tree.hpp
  - graph/count/BEST.hpp
  - graph/count/count_labeled_bipartite.hpp
  - poly/fps_sqrt.hpp
  - random/random_matrix.hpp
  - mod/mod_pow.hpp
  - mod/mod_sqrt.hpp
  - mod/dynamic_modint_64.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/blackbox_solve_linear.test.cpp
  - test/1_mytest/count_bipartite.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_directed_sparse.test.cpp
  - test/2_library_checker/graph/counting_eulerian_dense.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
  - test/2_library_checker/graph/counting_eulerian_sparse.test.cpp
  - test/2_library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/2_library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/2_library_checker/linear_algebra/det_mod.test.cpp
  - test/2_library_checker/linear_algebra/matrix_det.test.cpp
  - test/2_library_checker/number_theory/sqrt_mod.test.cpp
  - test/3_yukicoder/3229.test.cpp
  - test/3_yukicoder/1303.test.cpp
documentation_of: mod/barrett.hpp
layout: document
redirect_from:
- /library/mod/barrett.hpp
- /library/mod/barrett.hpp.html
title: mod/barrett.hpp
---
