---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/zalgorithm.hpp
    title: string/zalgorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/zalgorithm.hpp\"\ntemplate <typename STRING>  //\
    \ string, vector \u3069\u3061\u3089\u3067\u3082\nvector<int> zalgorithm(const\
    \ STRING& s) {\n  int n = int(s.size());\n  if (n == 0) return {};\n  vector<int>\
    \ z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0; i < n; i++) {\n    int& k = z[i];\n\
    \    k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);\n    while (i + k\
    \ < n && s[k] == s[i + k]) k++;\n    if (j + z[j] < i + z[i]) j = i;\n  }\n  z[0]\
    \ = n;\n  return z;\n}\n#line 2 \"seq/interpolate_periodic_sequence.hpp\"\n\n\
    // 012[345][345][345] \u307F\u305F\u3044\u306A\u3084\u3064\ntemplate <typename\
    \ T>\nstruct Interpolate_Periodic_Sequence {\n  vc<T> dat;\n  int p;\n\n  Interpolate_Periodic_Sequence(vc<T>\
    \ A) : dat(A) {\n    reverse(all(A));\n    auto Z = zalgorithm(A);\n    Z[0] =\
    \ 0;\n    p = max_element(all(Z)) - Z.begin();\n  }\n\n  T operator[](ll n) {\n\
    \    if (n < len(dat)) return dat[n];\n    ll k = ceil(n - (len(dat) - 1), p);\n\
    \    n -= k * p;\n    return dat[n];\n  }\n};\n"
  code: "#include \"string/zalgorithm.hpp\"\n\n// 012[345][345][345] \u307F\u305F\u3044\
    \u306A\u3084\u3064\ntemplate <typename T>\nstruct Interpolate_Periodic_Sequence\
    \ {\n  vc<T> dat;\n  int p;\n\n  Interpolate_Periodic_Sequence(vc<T> A) : dat(A)\
    \ {\n    reverse(all(A));\n    auto Z = zalgorithm(A);\n    Z[0] = 0;\n    p =\
    \ max_element(all(Z)) - Z.begin();\n  }\n\n  T operator[](ll n) {\n    if (n <\
    \ len(dat)) return dat[n];\n    ll k = ceil(n - (len(dat) - 1), p);\n    n -=\
    \ k * p;\n    return dat[n];\n  }\n};"
  dependsOn:
  - string/zalgorithm.hpp
  isVerificationFile: false
  path: seq/interpolate_periodic_sequence.hpp
  requiredBy: []
  timestamp: '2023-02-23 07:06:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/interpolate_periodic_sequence.hpp
layout: document
redirect_from:
- /library/seq/interpolate_periodic_sequence.hpp
- /library/seq/interpolate_periodic_sequence.hpp.html
title: seq/interpolate_periodic_sequence.hpp
---
