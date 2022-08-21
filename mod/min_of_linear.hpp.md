---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/min_of_mod_of_linear.test.cpp
    title: test/library_checker/math/min_of_mod_of_linear.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/min_of_linear.hpp\"\n// min_{x in [L, R)} (ax+b mod)\n\
    pair<ll, int> min_of_linear(ll L, ll R, int a, int b, int mod) {\n  ll n = R -\
    \ L;\n  b = (b + a * L) % mod;\n  if (b < 0) b += mod;\n  auto [X, DX] = min_of_linear_segments(a,\
    \ b, mod);\n  int x = 0;\n  for (int i = 0; i < int(X.size()) - 1; ++i) {\n  \
    \  int xl = X[i], xr = X[i + 1];\n    if (xr < n) {\n      x = xr;\n      continue;\n\
    \    }\n    x = xl + (n - 1 - x) / DX[i] * DX[i];\n    break;\n  }\n  int y =\
    \ (ll(a) * x + b) % mod;\n  return {L + x, y};\n}\n"
  code: "// min_{x in [L, R)} (ax+b mod)\npair<ll, int> min_of_linear(ll L, ll R,\
    \ int a, int b, int mod) {\n  ll n = R - L;\n  b = (b + a * L) % mod;\n  if (b\
    \ < 0) b += mod;\n  auto [X, DX] = min_of_linear_segments(a, b, mod);\n  int x\
    \ = 0;\n  for (int i = 0; i < int(X.size()) - 1; ++i) {\n    int xl = X[i], xr\
    \ = X[i + 1];\n    if (xr < n) {\n      x = xr;\n      continue;\n    }\n    x\
    \ = xl + (n - 1 - x) / DX[i] * DX[i];\n    break;\n  }\n  int y = (ll(a) * x +\
    \ b) % mod;\n  return {L + x, y};\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/min_of_linear.hpp
  requiredBy: []
  timestamp: '2022-08-21 18:00:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/min_of_mod_of_linear.test.cpp
documentation_of: mod/min_of_linear.hpp
layout: document
redirect_from:
- /library/mod/min_of_linear.hpp
- /library/mod/min_of_linear.hpp.html
title: mod/min_of_linear.hpp
---
