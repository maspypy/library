---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/random_real.hpp\"\n\n#line 2 \"random/base.hpp\"\n\
    \nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 3 \"random/random_real.hpp\"\n\ndouble random_real(double\
    \ a, double b) {\n  double x = RNG(0, 1 << 30);\n  x /= (1 << 30);\n  return a\
    \ + (b - a) * x;\n}\n"
  code: "\n#include \"random/base.hpp\"\n\ndouble random_real(double a, double b)\
    \ {\n  double x = RNG(0, 1 << 30);\n  x /= (1 << 30);\n  return a + (b - a) *\
    \ x;\n}\n"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: random/random_real.hpp
  requiredBy: []
  timestamp: '2025-06-27 11:35:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/random_real.hpp
layout: document
redirect_from:
- /library/random/random_real.hpp
- /library/random/random_real.hpp.html
title: random/random_real.hpp
---
