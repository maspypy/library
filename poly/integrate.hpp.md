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
  bundledCode: "#line 2 \"poly/integrate.hpp\"\n\ntemplate <typename mint>\nvc<mint>\
    \ integrate(const vc<mint>& f) {\n  vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g))\
    \ g[i] = f[i - 1] * inv<mint>(i);\n  return g;\n}\n"
  code: "#pragma once\n\ntemplate <typename mint>\nvc<mint> integrate(const vc<mint>&\
    \ f) {\n  vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g)) g[i] = f[i - 1] * inv<mint>(i);\n\
    \  return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/integrate.hpp
  requiredBy: []
  timestamp: '2022-05-02 13:06:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/integrate.hpp
layout: document
redirect_from:
- /library/poly/integrate.hpp
- /library/poly/integrate.hpp.html
title: poly/integrate.hpp
---
