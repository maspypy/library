---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C_rollinghash_2d.test.cpp
    title: test/aoj/ALDS1_14_C_rollinghash_2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/rollinghash_2d.hpp\"\n\nstruct RollingHash_2D {\n\
    \  using M61 = modint61;\n  const M61 b1, b2;\n  vc<M61> pow1;\n  vc<M61> pow2;\n\
    \n  RollingHash_2D()\n      : b1(generate_base()), b2(generate_base()), pow1{M61(1)},\
    \ pow2{M61(1)} {}\n\n  template <typename STRING>\n  vvc<M61> build(const vc<STRING>&\
    \ S) {\n    int H = len(S);\n    int W = len(S[0]);\n    vv(M61, res, H + 1, W\
    \ + 1);\n    FOR(x, H) {\n      FOR(y, W) { res[x + 1][y + 1] = res[x + 1][y]\
    \ * b2 + M61(S[x][y] + 1); }\n      FOR(y, W + 1) res[x + 1][y] += b1 * res[x][y];\n\
    \    }\n    return res;\n  }\n\n  M61 query(const vvc<M61>& A, int xl, int yl,\
    \ int xr, int yr) {\n    assert(0 <= xl && xl <= xr && xr <= len(A));\n    assert(0\
    \ <= yl && yl <= yr && yr <= len(A[0]));\n    expand(pow1, b1, xr - xl);\n   \
    \ expand(pow2, b2, yr - yl);\n    M61 res = A[xr][yr];\n    res -= A[xl][yr] *\
    \ pow1[xr - xl];\n    res -= A[xr][yl] * pow2[yr - yl];\n    res += A[xl][yl]\
    \ * pow1[xr - xl] * pow2[yr - yl];\n    return res;\n  }\n\nprivate:\n  static\
    \ inline u64 generate_base() {\n    RandomNumberGenerator RNG;\n    return RNG(M61::get_mod());\n\
    \  }\n\n  void expand(vc<M61>& pow, const M61& b, int n) {\n    while (len(pow)\
    \ <= n) pow.eb(pow.back() * b);\n  }\n};\n"
  code: "\nstruct RollingHash_2D {\n  using M61 = modint61;\n  const M61 b1, b2;\n\
    \  vc<M61> pow1;\n  vc<M61> pow2;\n\n  RollingHash_2D()\n      : b1(generate_base()),\
    \ b2(generate_base()), pow1{M61(1)}, pow2{M61(1)} {}\n\n  template <typename STRING>\n\
    \  vvc<M61> build(const vc<STRING>& S) {\n    int H = len(S);\n    int W = len(S[0]);\n\
    \    vv(M61, res, H + 1, W + 1);\n    FOR(x, H) {\n      FOR(y, W) { res[x + 1][y\
    \ + 1] = res[x + 1][y] * b2 + M61(S[x][y] + 1); }\n      FOR(y, W + 1) res[x +\
    \ 1][y] += b1 * res[x][y];\n    }\n    return res;\n  }\n\n  M61 query(const vvc<M61>&\
    \ A, int xl, int yl, int xr, int yr) {\n    assert(0 <= xl && xl <= xr && xr <=\
    \ len(A));\n    assert(0 <= yl && yl <= yr && yr <= len(A[0]));\n    expand(pow1,\
    \ b1, xr - xl);\n    expand(pow2, b2, yr - yl);\n    M61 res = A[xr][yr];\n  \
    \  res -= A[xl][yr] * pow1[xr - xl];\n    res -= A[xr][yl] * pow2[yr - yl];\n\
    \    res += A[xl][yl] * pow1[xr - xl] * pow2[yr - yl];\n    return res;\n  }\n\
    \nprivate:\n  static inline u64 generate_base() {\n    RandomNumberGenerator RNG;\n\
    \    return RNG(M61::get_mod());\n  }\n\n  void expand(vc<M61>& pow, const M61&\
    \ b, int n) {\n    while (len(pow) <= n) pow.eb(pow.back() * b);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rollinghash_2d.hpp
  requiredBy: []
  timestamp: '2022-05-28 05:14:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_C_rollinghash_2d.test.cpp
documentation_of: string/rollinghash_2d.hpp
layout: document
redirect_from:
- /library/string/rollinghash_2d.hpp
- /library/string/rollinghash_2d.hpp.html
title: string/rollinghash_2d.hpp
---
