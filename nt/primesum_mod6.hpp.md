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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#include \"nt/primesum.hpp\"\n#include \"nt/primetable.hpp\"\n\ntemplate\
    \ <typename T>\nstruct PrimeSum_Mod_6 {\n  ll N;\n  ll sqN;\n\n  PrimeSum<T> A,\
    \ B;\n  PrimeSum_Mod_6(ll N) : N(N), sqN(sqrtl(N)), A(N), B(N) {}\n\n  pair<T,\
    \ T> operator[](ll x) {\n    T a = A[x], b = B[x];\n    return {(a + b) / T(2),\
    \ (a - b) / T(2)};\n  }\n\n  void calc_count() {\n    A.calc([](ll x) -> T { return\
    \ ((x + 2) / 3 - (x % 6 == 4)); });\n    B.calc([](ll x) -> T { return ((x + 5)\
    \ % 6 <= 3 ? 1 : 0); });\n  }\n\n  void calc_sum() {\n    A.calc([](ll x) -> T\
    \ {\n      ll n = (x + 2) / 3 - (x % 6 == 4);\n      ll k = n / 2;\n      if (n\
    \ % 2 == 0) { return T(6 * k) * T(k); }\n      return T(6 * k) * T(k) + T(6 *\
    \ k + 1);\n    });\n    B.calc([](ll x) -> T {\n      ll n = (x + 2) / 3 - (x\
    \ % 6 == 4);\n      ll k = n / 2;\n      if (n % 2 == 0) { return T(-4 * k); }\n\
    \      return T(-4 * k + 6 * k + 1);\n    });\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/primesum_mod6.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/primesum_mod6.hpp
layout: document
redirect_from:
- /library/nt/primesum_mod6.hpp
- /library/nt/primesum_mod6.hpp.html
title: nt/primesum_mod6.hpp
---
