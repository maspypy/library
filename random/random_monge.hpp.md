---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/check_monge.test.cpp
    title: test/1_mytest/check_monge.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/monge_shortest_path.test.cpp
    title: test/1_mytest/monge_shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/monotone_minima.test.cpp
    title: test/1_mytest/monotone_minima.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/smawk.test.cpp
    title: test/1_mytest/smawk.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 2 \"random/random_monge.hpp\"\n\n\
    // A[i1][j1] + A[i2][j2] <= A[i1][j2] + A[i2][j1] for i1 < i2, j1 < j2.\nvvc<ll>\
    \ random_monge_matrix(int H, int W) {\n  ll LIM = 10;\n  vv(ll, D, H, W);\n  FOR(i,\
    \ H) FOR(j, W) D[i][j] = RNG(0, LIM + 1);\n\n  vv(ll, A, H, W);\n  FOR(i, H) FOR(j,\
    \ W) {\n    ll x = D[i][j];\n    if (i) x += A[i - 1][j];\n    if (j) x += A[i][j\
    \ - 1];\n    if (i && j) x -= A[i - 1][j - 1];\n    A[i][j] = x;\n  }\n\n  vc<ll>\
    \ row(H), col(W);\n  FOR(i, H) row[i] = RNG(-LIM * W, LIM * W + 1);\n  FOR(j,\
    \ W) col[j] = RNG(-LIM * H, LIM * H + 1);\n\n  FOR(i, H) FOR(j, W) A[i][j] = -A[i][j]\
    \ + row[i] + col[j];\n  return A;\n}\n"
  code: "#include \"random/base.hpp\"\n\n// A[i1][j1] + A[i2][j2] <= A[i1][j2] + A[i2][j1]\
    \ for i1 < i2, j1 < j2.\nvvc<ll> random_monge_matrix(int H, int W) {\n  ll LIM\
    \ = 10;\n  vv(ll, D, H, W);\n  FOR(i, H) FOR(j, W) D[i][j] = RNG(0, LIM + 1);\n\
    \n  vv(ll, A, H, W);\n  FOR(i, H) FOR(j, W) {\n    ll x = D[i][j];\n    if (i)\
    \ x += A[i - 1][j];\n    if (j) x += A[i][j - 1];\n    if (i && j) x -= A[i -\
    \ 1][j - 1];\n    A[i][j] = x;\n  }\n\n  vc<ll> row(H), col(W);\n  FOR(i, H) row[i]\
    \ = RNG(-LIM * W, LIM * W + 1);\n  FOR(j, W) col[j] = RNG(-LIM * H, LIM * H +\
    \ 1);\n\n  FOR(i, H) FOR(j, W) A[i][j] = -A[i][j] + row[i] + col[j];\n  return\
    \ A;\n}"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: random/random_monge.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:41:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/check_monge.test.cpp
  - test/1_mytest/monotone_minima.test.cpp
  - test/1_mytest/monge_shortest_path.test.cpp
  - test/1_mytest/smawk.test.cpp
documentation_of: random/random_monge.hpp
layout: document
redirect_from:
- /library/random/random_monge.hpp
- /library/random/random_monge.hpp.html
title: random/random_monge.hpp
---
