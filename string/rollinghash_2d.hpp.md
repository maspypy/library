---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"string/rollinghash_2d.hpp\"\
    \n\nstruct RollingHash_2D {\n  using M61 = modint61;\n  const M61 b1, b2;\n  vc<M61>\
    \ pow1;\n  vc<M61> pow2;\n\n  RollingHash_2D()\n      : b1(generate_base()), b2(generate_base()),\
    \ pow1{M61(1)}, pow2{M61(1)} {}\n\n  template <typename STRING>\n  vvc<M61> build(const\
    \ vc<STRING>& S) {\n    int H = len(S);\n    int W = len(S[0]);\n    vv(M61, res,\
    \ H + 1, W + 1);\n    FOR(x, H) {\n      FOR(y, W) { res[x + 1][y + 1] = res[x\
    \ + 1][y] * b2 + M61(S[x][y] + 1); }\n      FOR(y, W + 1) res[x + 1][y] += b1\
    \ * res[x][y];\n    }\n    return res;\n  }\n\n  M61 query(const vvc<M61>& A,\
    \ int xl, int yl, int xr, int yr) {\n    assert(0 <= xl && xl <= xr && xr <= len(A));\n\
    \    assert(0 <= yl && yl <= yr && yr <= len(A[0]));\n    expand(pow1, b1, xr\
    \ - xl);\n    expand(pow2, b2, yr - yl);\n    M61 res = A[xr][yr];\n    res -=\
    \ A[xl][yr] * pow1[xr - xl];\n    res -= A[xr][yl] * pow2[yr - yl];\n    res +=\
    \ A[xl][yl] * pow1[xr - xl] * pow2[yr - yl];\n    return res;\n  }\n\nprivate:\n\
    \  static inline u64 generate_base() { return RNG(M61::get_mod()); }\n\n  void\
    \ expand(vc<M61>& pow, const M61& b, int n) {\n    while (len(pow) <= n) pow.eb(pow.back()\
    \ * b);\n  }\n};\n"
  code: "#include \"random/base.hpp\"\n\nstruct RollingHash_2D {\n  using M61 = modint61;\n\
    \  const M61 b1, b2;\n  vc<M61> pow1;\n  vc<M61> pow2;\n\n  RollingHash_2D()\n\
    \      : b1(generate_base()), b2(generate_base()), pow1{M61(1)}, pow2{M61(1)}\
    \ {}\n\n  template <typename STRING>\n  vvc<M61> build(const vc<STRING>& S) {\n\
    \    int H = len(S);\n    int W = len(S[0]);\n    vv(M61, res, H + 1, W + 1);\n\
    \    FOR(x, H) {\n      FOR(y, W) { res[x + 1][y + 1] = res[x + 1][y] * b2 + M61(S[x][y]\
    \ + 1); }\n      FOR(y, W + 1) res[x + 1][y] += b1 * res[x][y];\n    }\n    return\
    \ res;\n  }\n\n  M61 query(const vvc<M61>& A, int xl, int yl, int xr, int yr)\
    \ {\n    assert(0 <= xl && xl <= xr && xr <= len(A));\n    assert(0 <= yl && yl\
    \ <= yr && yr <= len(A[0]));\n    expand(pow1, b1, xr - xl);\n    expand(pow2,\
    \ b2, yr - yl);\n    M61 res = A[xr][yr];\n    res -= A[xl][yr] * pow1[xr - xl];\n\
    \    res -= A[xr][yl] * pow2[yr - yl];\n    res += A[xl][yl] * pow1[xr - xl] *\
    \ pow2[yr - yl];\n    return res;\n  }\n\nprivate:\n  static inline u64 generate_base()\
    \ { return RNG(M61::get_mod()); }\n\n  void expand(vc<M61>& pow, const M61& b,\
    \ int n) {\n    while (len(pow) <= n) pow.eb(pow.back() * b);\n  }\n};\n"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: string/rollinghash_2d.hpp
  requiredBy: []
  timestamp: '2022-10-23 11:21:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_14_C.test.cpp
documentation_of: string/rollinghash_2d.hpp
layout: document
redirect_from:
- /library/string/rollinghash_2d.hpp
- /library/string/rollinghash_2d.hpp.html
title: string/rollinghash_2d.hpp
---
