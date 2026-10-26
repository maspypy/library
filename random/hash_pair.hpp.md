---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: geo/closest_pair.hpp
    title: geo/closest_pair.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/closest_pair.test.cpp
    title: test/2_library_checker/geometry/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/closest_pair_dc.test.cpp
    title: test/2_library_checker/geometry/closest_pair_dc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2167.test.cpp
    title: test/3_yukicoder/2167.test.cpp
  - icon: ':x:'
    path: test/4_aoj/CGL_5_A.test.cpp
    title: test/4_aoj/CGL_5_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/random/hash_pair.hpp
  bundledCode: "#line 1 \"random/hash_pair.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/random/hash_pair.hpp\n\
    #line 1 \"random/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/random/base.hpp\n\
    \nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 3 \"random/hash_pair.hpp\"\n\ntemplate\
    \ <typename T>\nu64 hash_pair(pair<T, T> X) {\n  static u64 hash_base = 0;\n \
    \ if (hash_base == 0) hash_base = RNG_64();\n  return hash_base * u64(X.fi) +\
    \ u64(X.se);\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/random/hash_pair.hpp\n\
    #include \"random/base.hpp\"\n\ntemplate <typename T>\nu64 hash_pair(pair<T, T>\
    \ X) {\n  static u64 hash_base = 0;\n  if (hash_base == 0) hash_base = RNG_64();\n\
    \  return hash_base * u64(X.fi) + u64(X.se);\n}\n"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: random/hash_pair.hpp
  requiredBy:
  - geo/closest_pair.hpp
  timestamp: '2026-10-25 17:23:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2167.test.cpp
  - test/2_library_checker/geometry/closest_pair_dc.test.cpp
  - test/2_library_checker/geometry/closest_pair.test.cpp
  - test/4_aoj/CGL_5_A.test.cpp
documentation_of: random/hash_pair.hpp
layout: document
redirect_from:
- /library/random/hash_pair.hpp
- /library/random/hash_pair.hpp.html
title: random/hash_pair.hpp
---
