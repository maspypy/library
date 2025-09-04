---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linalg/xor/transpose.hpp
    title: linalg/xor/transpose.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/monoid/merge_vector_space.hpp
    title: alg/monoid/merge_vector_space.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/QOJ5445.test.cpp
    title: test/1_mytest/QOJ5445.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/linear_algebra/vector_space_intersection.test.cpp
    title: test/2_library_checker/linear_algebra/vector_space_intersection.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/184.test.cpp
    title: test/3_yukicoder/184.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linalg/xor/transpose.hpp\"\n\n// n x m \u884C\u5217\u306E\
    \ transpose\u3002O((n+m)log(n+m)) \u6642\u9593\u3002\n// https://github.com/dsnet/matrix-transpose\n\
    template <typename UINT>\nvc<UINT> transpose(int n, int m, vc<UINT>& A, bool keep_A\
    \ = 1) {\n  assert(max(n, m) <= numeric_limits<UINT>::digits);\n  assert(len(A)\
    \ == n);\n  vc<UINT> tmp;\n  if (keep_A) tmp = A;\n  int LOG = 0;\n  while ((1\
    \ << LOG) < max(n, m)) ++LOG;\n  A.resize(1 << LOG);\n  int width = 1 << LOG;\n\
    \  UINT mask = 1;\n  FOR(i, LOG) mask = mask | (mask << (1 << i));\n  FOR(t, LOG)\
    \ {\n    width >>= 1;\n    mask = mask ^ (mask >> width);\n    FOR(i, 1 << t)\
    \ {\n      FOR(j, width) {\n        UINT* x = &A[width * (2 * i + 0) + j];\n \
    \       UINT* y = &A[width * (2 * i + 1) + j];\n        *x = ((*y << width) &\
    \ mask) ^ *x;\n        *y = ((*x & mask) >> width) ^ *y;\n        *x = ((*y <<\
    \ width) & mask) ^ *x;\n      }\n    }\n  }\n  A.resize(m);\n  if (!keep_A) return\
    \ A;\n  swap(A, tmp);\n  return tmp;\n}\n#line 2 \"linalg/xor/vector_space.hpp\"\
    \n\ntemplate <typename UINT>\nstruct Vector_Space {\n#define SP Vector_Space\n\
    \  vc<UINT> dat;\n\n  Vector_Space() {}\n  Vector_Space(vc<UINT> dat, bool is_reduced\
    \ = false) : dat(dat) {\n    if (!is_reduced) reduce();\n  }\n\n  int size() {\
    \ return dat.size(); }\n  int dim() { return dat.size(); }\n\n  bool add_element(UINT\
    \ v) {\n    for (auto&& e: dat) {\n      if (e == 0 || v == 0) break;\n      chmin(v,\
    \ v ^ e);\n    }\n    if (v) {\n      dat.eb(v);\n      return true;\n    }\n\
    \    return false;\n  }\n\n  bool contain(UINT v) {\n    for (auto&& w: dat) {\n\
    \      if (v == 0) break;\n      chmin(v, v ^ w);\n    }\n    return v == 0;\n\
    \  }\n\n  UINT get_max(UINT xor_val = 0) {\n    UINT res = xor_val;\n    for (auto&&\
    \ x: dat) chmax(res, res ^ x);\n    return res;\n  }\n\n  UINT get_min(UINT xor_val)\
    \ {\n    UINT res = xor_val;\n    for (auto&& x: dat) chmin(res, res ^ x);\n \
    \   return res;\n  }\n\n  static SP merge(SP x, SP y) {\n    if (len(x) < len(y))\
    \ swap(x, y);\n    for (auto v: y.dat) { x.add_element(v); }\n    return x;\n\
    \  }\n\n  static SP intersection(SP& x, SP& y) {\n    // \u3068\u308A\u3042\u3048\
    \u305A\n    static_assert(is_same_v<UINT, u32>);\n    vc<u64> xx;\n    for (auto&\
    \ v: x.dat) xx.eb(v | static_cast<u64>(v) << 32);\n    Vector_Space<u64> z(xx,\
    \ true);\n    for (auto& v: y.dat) z.add_element(static_cast<u64>(v) << 32);\n\
    \    vc<u32> xy;\n    for (auto& v: z.dat) {\n      if (v <= u32(-1)) xy.eb(v);\n\
    \    }\n    return SP(xy, true);\n  }\n\n  SP orthogonal_space(int max_dim) {\n\
    \    normalize();\n    int m = max_dim;\n    // pivot[k] == k \u3068\u306A\u308B\
    \u3088\u3046\u306B\u884C\u306E\u9806\u756A\u3092\u5909\u3048\u308B\n    vc<u64>\
    \ tmp(m);\n    FOR(i, len(dat)) tmp[topbit(dat[i])] = dat[i];\n    tmp = transpose(m,\
    \ m, tmp, 0);\n    SP res;\n    FOR(j, m) {\n      if (tmp[j] >> j & 1) continue;\n\
    \      res.add_element(tmp[j] | UINT(1) << j);\n    }\n    return res;\n  }\n\n\
    \  void normalize(bool dec = true) {\n    int n = len(dat);\n    // \u4E09\u89D2\
    \u5316\n    FOR(j, n) FOR(i, j) chmin(dat[i], dat[i] ^ dat[j]);\n    sort(all(dat));\n\
    \    if (dec) reverse(all(dat));\n  }\n\nprivate:\n  void reduce() {\n    SP y;\n\
    \    for (auto&& e: dat) y.add_element(e);\n    (*this) = y;\n  }\n#undef SP\n\
    };\n"
  code: "#include \"linalg/xor/transpose.hpp\"\n\ntemplate <typename UINT>\nstruct\
    \ Vector_Space {\n#define SP Vector_Space\n  vc<UINT> dat;\n\n  Vector_Space()\
    \ {}\n  Vector_Space(vc<UINT> dat, bool is_reduced = false) : dat(dat) {\n   \
    \ if (!is_reduced) reduce();\n  }\n\n  int size() { return dat.size(); }\n  int\
    \ dim() { return dat.size(); }\n\n  bool add_element(UINT v) {\n    for (auto&&\
    \ e: dat) {\n      if (e == 0 || v == 0) break;\n      chmin(v, v ^ e);\n    }\n\
    \    if (v) {\n      dat.eb(v);\n      return true;\n    }\n    return false;\n\
    \  }\n\n  bool contain(UINT v) {\n    for (auto&& w: dat) {\n      if (v == 0)\
    \ break;\n      chmin(v, v ^ w);\n    }\n    return v == 0;\n  }\n\n  UINT get_max(UINT\
    \ xor_val = 0) {\n    UINT res = xor_val;\n    for (auto&& x: dat) chmax(res,\
    \ res ^ x);\n    return res;\n  }\n\n  UINT get_min(UINT xor_val) {\n    UINT\
    \ res = xor_val;\n    for (auto&& x: dat) chmin(res, res ^ x);\n    return res;\n\
    \  }\n\n  static SP merge(SP x, SP y) {\n    if (len(x) < len(y)) swap(x, y);\n\
    \    for (auto v: y.dat) { x.add_element(v); }\n    return x;\n  }\n\n  static\
    \ SP intersection(SP& x, SP& y) {\n    // \u3068\u308A\u3042\u3048\u305A\n   \
    \ static_assert(is_same_v<UINT, u32>);\n    vc<u64> xx;\n    for (auto& v: x.dat)\
    \ xx.eb(v | static_cast<u64>(v) << 32);\n    Vector_Space<u64> z(xx, true);\n\
    \    for (auto& v: y.dat) z.add_element(static_cast<u64>(v) << 32);\n    vc<u32>\
    \ xy;\n    for (auto& v: z.dat) {\n      if (v <= u32(-1)) xy.eb(v);\n    }\n\
    \    return SP(xy, true);\n  }\n\n  SP orthogonal_space(int max_dim) {\n    normalize();\n\
    \    int m = max_dim;\n    // pivot[k] == k \u3068\u306A\u308B\u3088\u3046\u306B\
    \u884C\u306E\u9806\u756A\u3092\u5909\u3048\u308B\n    vc<u64> tmp(m);\n    FOR(i,\
    \ len(dat)) tmp[topbit(dat[i])] = dat[i];\n    tmp = transpose(m, m, tmp, 0);\n\
    \    SP res;\n    FOR(j, m) {\n      if (tmp[j] >> j & 1) continue;\n      res.add_element(tmp[j]\
    \ | UINT(1) << j);\n    }\n    return res;\n  }\n\n  void normalize(bool dec =\
    \ true) {\n    int n = len(dat);\n    // \u4E09\u89D2\u5316\n    FOR(j, n) FOR(i,\
    \ j) chmin(dat[i], dat[i] ^ dat[j]);\n    sort(all(dat));\n    if (dec) reverse(all(dat));\n\
    \  }\n\nprivate:\n  void reduce() {\n    SP y;\n    for (auto&& e: dat) y.add_element(e);\n\
    \    (*this) = y;\n  }\n#undef SP\n};\n"
  dependsOn:
  - linalg/xor/transpose.hpp
  isVerificationFile: false
  path: linalg/xor/vector_space.hpp
  requiredBy:
  - alg/monoid/merge_vector_space.hpp
  timestamp: '2024-05-04 19:37:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/184.test.cpp
  - test/2_library_checker/linear_algebra/vector_space_intersection.test.cpp
  - test/1_mytest/QOJ5445.test.cpp
documentation_of: linalg/xor/vector_space.hpp
layout: document
redirect_from:
- /library/linalg/xor/vector_space.hpp
- /library/linalg/xor/vector_space.hpp.html
title: linalg/xor/vector_space.hpp
---
