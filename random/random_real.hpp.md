---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/random_real.hpp\"\n\n#line 1 \"random/base.hpp\"\n\
    \nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 3 \"random/random_real.hpp\"\n\ndouble\
    \ random_real(double a, double b) {\n  double x = RNG(0, 1 << 30);\n  x /= (1\
    \ << 30);\n  return a + (b - a) * x;\n}\n"
  code: "\n#include \"random/base.hpp\"\n\ndouble random_real(double a, double b)\
    \ {\n  double x = RNG(0, 1 << 30);\n  x /= (1 << 30);\n  return a + (b - a) *\
    \ x;\n}\n"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: random/random_real.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:41:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: random/random_real.hpp
layout: document
redirect_from:
- /library/random/random_real.hpp
- /library/random/random_real.hpp.html
title: random/random_real.hpp
---
