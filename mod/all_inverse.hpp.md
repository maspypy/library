---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: seq/famous/q_binomial.hpp
    title: seq/famous/q_binomial.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/all_inverse.hpp\"\ntemplate <typename mint>\nvc<mint>\
    \ all_inverse(vc<mint>& X) {\n  for (auto&& x: X) assert(x != mint(0));\n  int\
    \ N = len(X);\n  vc<mint> res(N + 1);\n  res[0] = mint(1);\n  FOR(i, N) res[i\
    \ + 1] = res[i] * X[i];\n  mint t = res.back().inverse();\n  res.pop_back();\n\
    \  FOR_R(i, N) {\n    res[i] *= t;\n    t *= X[i];\n  }\n  return res;\n}\n"
  code: "template <typename mint>\nvc<mint> all_inverse(vc<mint>& X) {\n  for (auto&&\
    \ x: X) assert(x != mint(0));\n  int N = len(X);\n  vc<mint> res(N + 1);\n  res[0]\
    \ = mint(1);\n  FOR(i, N) res[i + 1] = res[i] * X[i];\n  mint t = res.back().inverse();\n\
    \  res.pop_back();\n  FOR_R(i, N) {\n    res[i] *= t;\n    t *= X[i];\n  }\n \
    \ return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/all_inverse.hpp
  requiredBy:
  - seq/famous/q_binomial.hpp
  timestamp: '2022-08-07 13:08:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/all_inverse.hpp
layout: document
redirect_from:
- /library/mod/all_inverse.hpp
- /library/mod/all_inverse.hpp.html
title: mod/all_inverse.hpp
---
