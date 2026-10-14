---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/z_algorithm.hpp
    title: string/z_algorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/2858.test.cpp
    title: test/3_yukicoder/2858.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/interpolate_periodic_sequence.hpp\"\n\n#line 1 \"string/z_algorithm.hpp\"\
    \n\ntemplate <typename STRING>  // string, vector \u3069\u3061\u3089\u3067\u3082\
    \nvector<int> z_algorithm(const STRING& s) {\n  int n = int(s.size());\n  if (n\
    \ == 0) return {};\n  vector<int> z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0;\
    \ i < n; i++) {\n    int& k = z[i];\n    k = (j + z[j] <= i) ? 0 : min(j + z[j]\
    \ - i, z[i - j]);\n    while (i + k < n && s[k] == s[i + k]) k++;\n    if (j +\
    \ z[j] < i + z[i]) j = i;\n  }\n  z[0] = n;\n  return z;\n}\n#line 3 \"seq/interpolate_periodic_sequence.hpp\"\
    \n\n// 012[345][345][345] \u307F\u305F\u3044\u306A\u3084\u3064\ntemplate <typename\
    \ T>\nstruct Interpolate_Periodic_Sequence {\n  vc<T> dat;\n  int p;\n\n  Interpolate_Periodic_Sequence(vc<T>\
    \ A) : dat(A) {\n    reverse(all(A));\n    auto Z = z_algorithm(A);\n    Z[0]\
    \ = 0;\n    p = max_element(all(Z)) - Z.begin();\n  }\n\n  T operator[](ll n)\
    \ {\n    if (n < len(dat)) return dat[n];\n    ll k = ceil<ll>(n - (len(dat) -\
    \ 1), p);\n    n -= k * p;\n    return dat[n];\n  }\n};\n\n// \u5DEE\u5206\u304C\
    \ 012[345][345][345] \u307F\u305F\u3044\u306A\u3084\u3064\ntemplate <typename\
    \ T>\nstruct Interpolate_Difference_Periodic_Sequence {\n  vc<T> dat;\n  T d;\n\
    \  int p;\n\n  Interpolate_Difference_Periodic_Sequence(vc<T> A) : dat(A) {\n\
    \    vc<T> diff;\n    FOR(i, len(A) - 1) diff.eb(A[i + 1] - A[i]);\n    reverse(all(diff));\n\
    \    auto Z = z_algorithm(diff);\n    Z[0] = 0;\n    p = max_element(all(Z)) -\
    \ Z.begin();\n    ll n = len(A);\n    d = A[n - 1] - A[n - p - 1];\n  }\n\n  T\
    \ operator[](ll n) {\n    if (n < len(dat)) return dat[n];\n    ll k = ceil<ll>(n\
    \ - (len(dat) - 1), p);\n    n -= k * p;\n    return dat[n] + k * d;\n  }\n};\n"
  code: "\n#include \"string/z_algorithm.hpp\"\n\n// 012[345][345][345] \u307F\u305F\
    \u3044\u306A\u3084\u3064\ntemplate <typename T>\nstruct Interpolate_Periodic_Sequence\
    \ {\n  vc<T> dat;\n  int p;\n\n  Interpolate_Periodic_Sequence(vc<T> A) : dat(A)\
    \ {\n    reverse(all(A));\n    auto Z = z_algorithm(A);\n    Z[0] = 0;\n    p\
    \ = max_element(all(Z)) - Z.begin();\n  }\n\n  T operator[](ll n) {\n    if (n\
    \ < len(dat)) return dat[n];\n    ll k = ceil<ll>(n - (len(dat) - 1), p);\n  \
    \  n -= k * p;\n    return dat[n];\n  }\n};\n\n// \u5DEE\u5206\u304C 012[345][345][345]\
    \ \u307F\u305F\u3044\u306A\u3084\u3064\ntemplate <typename T>\nstruct Interpolate_Difference_Periodic_Sequence\
    \ {\n  vc<T> dat;\n  T d;\n  int p;\n\n  Interpolate_Difference_Periodic_Sequence(vc<T>\
    \ A) : dat(A) {\n    vc<T> diff;\n    FOR(i, len(A) - 1) diff.eb(A[i + 1] - A[i]);\n\
    \    reverse(all(diff));\n    auto Z = z_algorithm(diff);\n    Z[0] = 0;\n   \
    \ p = max_element(all(Z)) - Z.begin();\n    ll n = len(A);\n    d = A[n - 1] -\
    \ A[n - p - 1];\n  }\n\n  T operator[](ll n) {\n    if (n < len(dat)) return dat[n];\n\
    \    ll k = ceil<ll>(n - (len(dat) - 1), p);\n    n -= k * p;\n    return dat[n]\
    \ + k * d;\n  }\n};"
  dependsOn:
  - string/z_algorithm.hpp
  isVerificationFile: false
  path: seq/interpolate_periodic_sequence.hpp
  requiredBy: []
  timestamp: '2026-08-17 09:36:33+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/2858.test.cpp
documentation_of: seq/interpolate_periodic_sequence.hpp
layout: document
redirect_from:
- /library/seq/interpolate_periodic_sequence.hpp
- /library/seq/interpolate_periodic_sequence.hpp.html
title: seq/interpolate_periodic_sequence.hpp
---
