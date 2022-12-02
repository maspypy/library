---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: mod/all_inverse.hpp
    title: mod/all_inverse.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/all_inverse.hpp\"\ntemplate <typename mint>\nvc<mint>\
    \ all_inverse(vc<mint>& X) {\n  for (auto&& x: X) assert(x != mint(0));\n  int\
    \ N = len(X);\n  vc<mint> res(N + 1);\n  res[0] = mint(1);\n  FOR(i, N) res[i\
    \ + 1] = res[i] * X[i];\n  mint t = res.back().inverse();\n  res.pop_back();\n\
    \  FOR_R(i, N) {\n    res[i] *= t;\n    t *= X[i];\n  }\n  return res;\n}\n#line\
    \ 2 \"seq/famous/q_binomial.hpp\"\n\n// \\prod_{i=0}^M (1+q^ix) \u3092 [x^N] \u307E\
    \u3067\u8A08\u7B97\n// 0 <= i <= N \u306B\u5BFE\u3057\u3066 q^i-1 \u304C 0 \u306B\
    \u306A\u3089\u306A\u3044\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u305F\u5B9F\u88C5\
    \n// O(N + log(mod)) \u6642\u9593\ntemplate <typename mint>\nvc<mint> q_binomial(int\
    \ N, mint q, ll M) {\n  vc<mint> f(N + 1);\n  f[0] = mint(1);\n  mint c = q.pow(M\
    \ + 1);\n  vc<mint> den(N + 1, 1);\n  {\n    mint a = mint(1);\n    FOR(i, N)\
    \ {\n      f[i + 1] = f[i] * (c - a);\n      a *= q;\n      den[i + 1] = den[i]\
    \ * (a - mint(1));\n    }\n  }\n  den = all_inverse(den);\n  FOR(i, N + 1) { f[i]\
    \ *= den[i]; }\n  return f;\n}\n"
  code: "#include \"mod/all_inverse.hpp\"\n\n// \\prod_{i=0}^M (1+q^ix) \u3092 [x^N]\
    \ \u307E\u3067\u8A08\u7B97\n// 0 <= i <= N \u306B\u5BFE\u3057\u3066 q^i-1 \u304C\
    \ 0 \u306B\u306A\u3089\u306A\u3044\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u305F\u5B9F\
    \u88C5\n// O(N + log(mod)) \u6642\u9593\ntemplate <typename mint>\nvc<mint> q_binomial(int\
    \ N, mint q, ll M) {\n  vc<mint> f(N + 1);\n  f[0] = mint(1);\n  mint c = q.pow(M\
    \ + 1);\n  vc<mint> den(N + 1, 1);\n  {\n    mint a = mint(1);\n    FOR(i, N)\
    \ {\n      f[i + 1] = f[i] * (c - a);\n      a *= q;\n      den[i + 1] = den[i]\
    \ * (a - mint(1));\n    }\n  }\n  den = all_inverse(den);\n  FOR(i, N + 1) { f[i]\
    \ *= den[i]; }\n  return f;\n}"
  dependsOn:
  - mod/all_inverse.hpp
  isVerificationFile: false
  path: seq/famous/q_binomial.hpp
  requiredBy: []
  timestamp: '2022-11-23 08:11:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/famous/q_binomial.hpp
layout: document
redirect_from:
- /library/seq/famous/q_binomial.hpp
- /library/seq/famous/q_binomial.hpp.html
title: seq/famous/q_binomial.hpp
---
