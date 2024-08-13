---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: geo/closest_pair.hpp
    title: geo/closest_pair.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/geometry/closest_pair.test.cpp
    title: test/2_library_checker/geometry/closest_pair.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/geometry/closest_pair_dc.test.cpp
    title: test/2_library_checker/geometry/closest_pair_dc.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2167.test.cpp
    title: test/3_yukicoder/2167.test.cpp
  - icon: ':x:'
    path: test/4_aoj/CGL_5_A.test.cpp
    title: test/4_aoj/CGL_5_A.test.cpp
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
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"random/hash_pair.hpp\"\
    \n\ntemplate <typename T>\nu64 hash_pair(pair<T, T> X) {\n  static ll hash_base\
    \ = 0;\n  if (hash_base == 0) hash_base = RNG_64();\n  return hash_base * X.fi\
    \ + X.se;\n}\n"
  code: "#include \"random/base.hpp\"\n\ntemplate <typename T>\nu64 hash_pair(pair<T,\
    \ T> X) {\n  static ll hash_base = 0;\n  if (hash_base == 0) hash_base = RNG_64();\n\
    \  return hash_base * X.fi + X.se;\n}\n"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: random/hash_pair.hpp
  requiredBy:
  - geo/closest_pair.hpp
  timestamp: '2023-01-31 21:39:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
