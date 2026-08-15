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
    \ <typename T>\nstruct PrimeSum_Mod_4 {\n  ll N;\n  ll sqN;\n\n  PrimeSum<T> A,\
    \ B;\n  PrimeSum_Mod_4(ll N) : N(N), sqN(sqrtl(N)), A(N), B(N) {}\n\n  pair<T,\
    \ T> operator[](ll x) {\n    T a = A[x], b = B[x];\n    return {(a + b) / T(2),\
    \ (a - b) / T(2)};\n  }\n\n  void calc_count() {\n    A.calc([](ll x) -> T { return\
    \ (x + 1) / 2; });\n    B.calc([](ll x) -> T { return ((x + 3) % 4 <= 1 ? 1 :\
    \ 0); });\n  }\n\n  void calc_sum() {\n    A.calc([](ll x) -> T {\n      ll n\
    \ = (x + 1) / 2;\n      return T(n) * T(n);\n    });\n    B.calc([](ll x) -> T\
    \ {\n      ll n = (x + 1) / 2;\n      return (n % 2 == 0 ? T(-n) : T(n));\n  \
    \  });\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/primesum_mod4.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/primesum_mod4.hpp
layout: document
redirect_from:
- /library/nt/primesum_mod4.hpp
- /library/nt/primesum_mod4.hpp.html
title: nt/primesum_mod4.hpp
---
