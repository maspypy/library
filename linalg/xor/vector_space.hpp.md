---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linalg/xor/solve_linear.hpp
    title: linalg/xor/solve_linear.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/xor/transpose.hpp
    title: linalg/xor/transpose.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/merge_vector_space.hpp
    title: alg/monoid/merge_vector_space.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/QOJ5445.test.cpp
    title: test/mytest/QOJ5445.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/184.test.cpp
    title: test/yukicoder/184.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/xor/solve_linear.hpp\"\n// solve Ax = b \u3092\u89E3\
    \u304F\u3002[0] \u306B\u7279\u6B8A\u89E3\u3001[1]\uFF5E \u306B Ker A \u306E\u57FA\
    \u5E95\u304C\u5165\u308B\u3002\u89E3\u306A\u3057\u306F\n// empty\u3002 A \u306E\
    \u884C\u30D9\u30AF\u30C8\u30EB\u3092 UINT \u3067\u6301\u305F\u305B\u308B\u3002\
    \ntemplate <typename UINT>\nvc<UINT> solve_linear(int n, int m, vc<UINT>& A, UINT\
    \ b) {\n  assert(max(n, m) <= numeric_limits<UINT>::digits);\n  assert(len(A)\
    \ == n);\n  int rk = 0;\n  FOR(j, m) {\n    if (rk == n) break;\n    FOR(i, rk,\
    \ n) if (A[i] >> j & 1) {\n      if (i == rk) break;\n      swap(A[rk], A[i]);\n\
    \      if ((b >> rk & 1) != (b >> i & 1)) b ^= (UINT(1) << rk) | (UINT(1) << i);\n\
    \      break;\n    }\n    if (!(A[rk] >> j & 1)) continue;\n    FOR(i, n) if (i\
    \ != rk) {\n      if (A[i] >> j & 1) {\n        A[i] ^= A[rk];\n        b ^= (b\
    \ >> rk & 1) << i;\n      }\n    }\n    ++rk;\n  }\n  if (b >> rk) { return {};\
    \ }\n  vc<UINT> res(1);\n  vc<int> pivot(m, -1);\n  int p = 0;\n  FOR(i, rk) {\n\
    \    while (!(A[i] >> p & 1)) ++p;\n    res[0] |= (b >> i & 1) << p;\n    pivot[p]\
    \ = i;\n  }\n  FOR(j, m) if (pivot[j] == -1) {\n    UINT x = 0;\n    x |= UINT(1)\
    \ << j;\n    FOR(k, j) if (pivot[k] != -1 && (A[pivot[k]] >> j & 1)) {\n     \
    \ x |= UINT(1) << k;\n    }\n    res.eb(x);\n  }\n  return res;\n}\n#line 2 \"\
    linalg/xor/transpose.hpp\"\n\n// n x m \u884C\u5217\u306E transpose\u3002O((n+m)log(n+m))\
    \ \u6642\u9593\u3002\n// https://github.com/dsnet/matrix-transpose\ntemplate <typename\
    \ UINT>\nvc<UINT> transpose(int n, int m, vc<UINT>& A, bool keep_A = 1) {\n  assert(max(n,\
    \ m) <= numeric_limits<UINT>::digits);\n  assert(len(A) == n);\n  vc<UINT> tmp;\n\
    \  if (keep_A) tmp = A;\n  int LOG = 0;\n  while ((1 << LOG) < max(n, m)) ++LOG;\n\
    \  A.resize(1 << LOG);\n  int width = 1 << LOG;\n  UINT mask = 1;\n  FOR(i, LOG)\
    \ mask = mask | (mask << (1 << i));\n  FOR(t, LOG) {\n    width >>= 1;\n    mask\
    \ = mask ^ (mask >> width);\n    FOR(i, 1 << t) {\n      FOR(j, width) {\n   \
    \     UINT* x = &A[width * (2 * i + 0) + j];\n        UINT* y = &A[width * (2\
    \ * i + 1) + j];\n        *x = ((*y << width) & mask) ^ *x;\n        *y = ((*x\
    \ & mask) >> width) ^ *y;\n        *x = ((*y << width) & mask) ^ *x;\n      }\n\
    \    }\n  }\n  A.resize(m);\n  if (!keep_A) return A;\n  swap(A, tmp);\n  return\
    \ tmp;\n}\n#line 3 \"linalg/xor/vector_space.hpp\"\n\ntemplate <typename UINT>\n\
    struct Vector_Space {\n#define SP Vector_Space\n  vc<UINT> dat;\n\n  Vector_Space()\
    \ {}\n  Vector_Space(vc<UINT> dat, bool is_reduced = false) : dat(dat) {\n   \
    \ if (!is_reduced) reduce();\n  }\n\n  int size() { return dat.size(); }\n\n \
    \ bool add_element(UINT v) {\n    for (auto&& e: dat) {\n      if (e == 0 || v\
    \ == 0) break;\n      chmin(v, v ^ e);\n    }\n    if (v) {\n      dat.eb(v);\n\
    \      return true;\n    }\n    return false;\n  }\n\n  void reduce() {\n    SP\
    \ y;\n    for (auto&& e: dat) y.add_element(e);\n    (*this) = y;\n  }\n\n  bool\
    \ contain(UINT v) {\n    for (auto&& w: dat) {\n      if (v == 0) break;\n   \
    \   chmin(v, v ^ w);\n    }\n    return v == 0;\n  }\n\n  UINT get_max(UINT xor_val\
    \ = 0) {\n    UINT res = xor_val;\n    for (auto&& x: dat) chmax(res, res ^ x);\n\
    \    return res;\n  }\n\n  UINT get_min(UINT xor_val) {\n    UINT res = xor_val;\n\
    \    for (auto&& x: dat) chmin(res, res ^ x);\n    return res;\n  }\n\n  static\
    \ SP merge(SP x, SP y) {\n    if (len(x) < len(y)) swap(x, y);\n    for (auto\
    \ v: y.dat) { x.add_element(v); }\n    return x;\n  }\n\n  static SP intersection(SP&\
    \ x, SP& y, int max_dim) {\n    SP xx = x.orthogonal_space(max_dim);\n    SP yy\
    \ = y.orthogonal_space(max_dim);\n    xx = merge(xx, yy);\n    return xx.orthogonal_space(max_dim);\n\
    \  }\n\n  SP orthogonal_space(int max_dim) {\n    int n = len(dat);\n    // \u4E09\
    \u89D2\u5316\n    FOR(j, n) FOR(i, j) chmin(dat[i], dat[i] ^ dat[j]);\n    int\
    \ m = max_dim;\n    // pivot[k] == k \u3068\u306A\u308B\u3088\u3046\u306B\u884C\
    \u306E\u9806\u756A\u3092\u5909\u3048\u308B\n    vc<u64> tmp(m);\n    FOR(i, len(dat))\
    \ tmp[topbit(dat[i])] = dat[i];\n    tmp = transpose(m, m, tmp, 0);\n    SP res;\n\
    \    FOR(j, m) {\n      if (tmp[j] >> j & 1) continue;\n      res.add_element(tmp[j]\
    \ | UINT(1) << j);\n    }\n    return res;\n  }\n#undef SP\n};\n"
  code: "#include \"linalg/xor/solve_linear.hpp\"\n#include \"linalg/xor/transpose.hpp\"\
    \n\ntemplate <typename UINT>\nstruct Vector_Space {\n#define SP Vector_Space\n\
    \  vc<UINT> dat;\n\n  Vector_Space() {}\n  Vector_Space(vc<UINT> dat, bool is_reduced\
    \ = false) : dat(dat) {\n    if (!is_reduced) reduce();\n  }\n\n  int size() {\
    \ return dat.size(); }\n\n  bool add_element(UINT v) {\n    for (auto&& e: dat)\
    \ {\n      if (e == 0 || v == 0) break;\n      chmin(v, v ^ e);\n    }\n    if\
    \ (v) {\n      dat.eb(v);\n      return true;\n    }\n    return false;\n  }\n\
    \n  void reduce() {\n    SP y;\n    for (auto&& e: dat) y.add_element(e);\n  \
    \  (*this) = y;\n  }\n\n  bool contain(UINT v) {\n    for (auto&& w: dat) {\n\
    \      if (v == 0) break;\n      chmin(v, v ^ w);\n    }\n    return v == 0;\n\
    \  }\n\n  UINT get_max(UINT xor_val = 0) {\n    UINT res = xor_val;\n    for (auto&&\
    \ x: dat) chmax(res, res ^ x);\n    return res;\n  }\n\n  UINT get_min(UINT xor_val)\
    \ {\n    UINT res = xor_val;\n    for (auto&& x: dat) chmin(res, res ^ x);\n \
    \   return res;\n  }\n\n  static SP merge(SP x, SP y) {\n    if (len(x) < len(y))\
    \ swap(x, y);\n    for (auto v: y.dat) { x.add_element(v); }\n    return x;\n\
    \  }\n\n  static SP intersection(SP& x, SP& y, int max_dim) {\n    SP xx = x.orthogonal_space(max_dim);\n\
    \    SP yy = y.orthogonal_space(max_dim);\n    xx = merge(xx, yy);\n    return\
    \ xx.orthogonal_space(max_dim);\n  }\n\n  SP orthogonal_space(int max_dim) {\n\
    \    int n = len(dat);\n    // \u4E09\u89D2\u5316\n    FOR(j, n) FOR(i, j) chmin(dat[i],\
    \ dat[i] ^ dat[j]);\n    int m = max_dim;\n    // pivot[k] == k \u3068\u306A\u308B\
    \u3088\u3046\u306B\u884C\u306E\u9806\u756A\u3092\u5909\u3048\u308B\n    vc<u64>\
    \ tmp(m);\n    FOR(i, len(dat)) tmp[topbit(dat[i])] = dat[i];\n    tmp = transpose(m,\
    \ m, tmp, 0);\n    SP res;\n    FOR(j, m) {\n      if (tmp[j] >> j & 1) continue;\n\
    \      res.add_element(tmp[j] | UINT(1) << j);\n    }\n    return res;\n  }\n\
    #undef SP\n};\n"
  dependsOn:
  - linalg/xor/solve_linear.hpp
  - linalg/xor/transpose.hpp
  isVerificationFile: false
  path: linalg/xor/vector_space.hpp
  requiredBy:
  - alg/monoid/merge_vector_space.hpp
  timestamp: '2023-02-03 03:39:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/184.test.cpp
  - test/mytest/QOJ5445.test.cpp
documentation_of: linalg/xor/vector_space.hpp
layout: document
redirect_from:
- /library/linalg/xor/vector_space.hpp
- /library/linalg/xor/vector_space.hpp.html
title: linalg/xor/vector_space.hpp
---
