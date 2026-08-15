---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n#include \"nt/primetable.hpp\"\r\n\r\n/*\r\nN \u3068\u5B8C\
    \u5168\u4E57\u6CD5\u7684\u95A2\u6570 f \u306E prefix sum \u95A2\u6570 F \u3092\
    \u4E0E\u3048\u308B\u3002\r\nn = floor(N/d) \u3068\u306A\u308B n \u306B\u5BFE\u3059\
    \u308B sum_{p <= n} f(p) \u3092\u8A08\u7B97\u3059\u308B\u3002\r\n\u7279\u306B\u3001\
    \u7D20\u6570\u306E k \u4E57\u548C\u3084\u3001mod m \u3054\u3068\u3067\u306E\u7D20\
    \u6570\u306E k \u4E57\u548C\u304C\u8A08\u7B97\u3067\u304D\u308B\u3002\r\nComplexity:\
    \ O(N^{3/4}/logN) time, O(N^{1/2}) space.\r\n*/\r\ntemplate <typename T>\r\nstruct\
    \ PrimeSum {\r\n  ll N;\r\n  ll sqN;\r\n  vc<T> sum_lo, sum_hi;\r\n  bool calculated;\r\
    \n\r\n  PrimeSum(ll N) : N(N), sqN(sqrtl(N)), calculated(0) {}\r\n\r\n  // [1,\
    \ x] \u305F\u3060\u3057\u3001x = floor(N, i) \u306E\u5F62\r\n  T operator[](ll\
    \ x) {\r\n    assert(calculated);\r\n    return (x <= sqN ? sum_lo[x] : sum_hi[double(N)\
    \ / x]);\r\n  }\r\n\r\n  template <typename F>\r\n  void calc(const F f) {\r\n\
    \    auto primes = primetable<int>(sqN);\r\n    sum_lo.resize(sqN + 1);\r\n  \
    \  sum_hi.resize(sqN + 1);\r\n    FOR3(i, 1, sqN + 1) sum_lo[i] = f(i) - 1;\r\n\
    \    FOR3(i, 1, sqN + 1) sum_hi[i] = f(double(N) / i) - 1;\r\n    for (int p:\
    \ primes) {\r\n      ll pp = ll(p) * p;\r\n      if (pp > N) break;\r\n      int\
    \ R = min(sqN, N / pp);\r\n      int M = sqN / p;\r\n      T x = sum_lo[p - 1];\r\
    \n      T fp = sum_lo[p] - sum_lo[p - 1];\r\n      for (int i = 1; i <= M; ++i)\
    \ sum_hi[i] -= fp * (sum_hi[i * p] - x);\r\n      for (int i = M + 1; i <= R;\
    \ ++i) sum_hi[i] -= fp * (sum_lo[N / (double(i) * p)] - x);\r\n      for (int\
    \ n = sqN; n >= pp; --n) sum_lo[n] -= fp * (sum_lo[n / p] - x);\r\n    }\r\n \
    \   calculated = 1;\r\n  }\r\n\r\n  void calc_count() {\r\n    calc([](ll x) ->\
    \ T { return x; });\r\n  }\r\n\r\n  void calc_sum() {\r\n    calc([](ll x) ->\
    \ T {\r\n      ll a = x, b = x + 1;\r\n      if (!(x & 1)) a /= 2;\r\n      if\
    \ (x & 1) b /= 2;\r\n      return T(a) * T(b);\r\n    });\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: nt/primesum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/primesum.hpp
layout: document
redirect_from:
- /library/nt/primesum.hpp
- /library/nt/primesum.hpp.html
title: nt/primesum.hpp
---
