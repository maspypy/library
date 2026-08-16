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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/zalgorithm.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"string/zalgorithm.hpp\"\n\n// 012[345][345][345] \u307F\u305F\
    \u3044\u306A\u3084\u3064\ntemplate <typename T>\nstruct Interpolate_Periodic_Sequence\
    \ {\n  vc<T> dat;\n  int p;\n\n  Interpolate_Periodic_Sequence(vc<T> A) : dat(A)\
    \ {\n    reverse(all(A));\n    auto Z = zalgorithm(A);\n    Z[0] = 0;\n    p =\
    \ max_element(all(Z)) - Z.begin();\n  }\n\n  T operator[](ll n) {\n    if (n <\
    \ len(dat)) return dat[n];\n    ll k = ceil<ll>(n - (len(dat) - 1), p);\n    n\
    \ -= k * p;\n    return dat[n];\n  }\n};\n\n// \u5DEE\u5206\u304C 012[345][345][345]\
    \ \u307F\u305F\u3044\u306A\u3084\u3064\ntemplate <typename T>\nstruct Interpolate_Difference_Periodic_Sequence\
    \ {\n  vc<T> dat;\n  T d;\n  int p;\n\n  Interpolate_Difference_Periodic_Sequence(vc<T>\
    \ A) : dat(A) {\n    vc<T> diff;\n    FOR(i, len(A) - 1) diff.eb(A[i + 1] - A[i]);\n\
    \    reverse(all(diff));\n    auto Z = zalgorithm(diff);\n    Z[0] = 0;\n    p\
    \ = max_element(all(Z)) - Z.begin();\n    ll n = len(A);\n    d = A[n - 1] - A[n\
    \ - p - 1];\n  }\n\n  T operator[](ll n) {\n    if (n < len(dat)) return dat[n];\n\
    \    ll k = ceil<ll>(n - (len(dat) - 1), p);\n    n -= k * p;\n    return dat[n]\
    \ + k * d;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: seq/interpolate_periodic_sequence.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/interpolate_periodic_sequence.hpp
layout: document
redirect_from:
- /library/seq/interpolate_periodic_sequence.hpp
- /library/seq/interpolate_periodic_sequence.hpp.html
title: seq/interpolate_periodic_sequence.hpp
---
