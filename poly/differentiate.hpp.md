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
  bundledCode: "#line 2 \"poly/differentiate.hpp\"\n\ntemplate <typename mint>\nvc<mint>\
    \ differentiate(const vc<mint>& f) {\n  if (len(f) <= 1) return {};\n  vc<mint>\
    \ g(len(f) - 1);\n  FOR(i, len(g)) g[i] = f[i + 1] * mint(i + 1);\n  return g;\n\
    }\n"
  code: "#pragma once\n\ntemplate <typename mint>\nvc<mint> differentiate(const vc<mint>&\
    \ f) {\n  if (len(f) <= 1) return {};\n  vc<mint> g(len(f) - 1);\n  FOR(i, len(g))\
    \ g[i] = f[i + 1] * mint(i + 1);\n  return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/differentiate.hpp
  requiredBy: []
  timestamp: '2022-05-02 13:06:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/differentiate.hpp
layout: document
redirect_from:
- /library/poly/differentiate.hpp
- /library/poly/differentiate.hpp.html
title: poly/differentiate.hpp
---
