---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/_atcoder/abc270_g.test.cpp
    title: test/_atcoder/abc270_g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/acted_set/affine.hpp\"\n// 1 \u6B21\u5143\u30D9\u30AF\
    \u30C8\u30EB\u7A7A\u9593\u306B\u3001\u30A2\u30D5\u30A3\u30F3\u5909\u63DB\u304C\
    \u4F5C\u7528\ntemplate <typename T>\nstruct ActedSet_Affine {\n  using Monoid_A\
    \ = Monoid_Affine<T>;\n  using A = typename Monoid_A::value_type;\n  using S =\
    \ T;\n  static S act(const S &x, const A &g) { return g.fi * x + g.se; }\n};\n"
  code: "// 1 \u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u7A7A\u9593\u306B\u3001\u30A2\u30D5\
    \u30A3\u30F3\u5909\u63DB\u304C\u4F5C\u7528\ntemplate <typename T>\nstruct ActedSet_Affine\
    \ {\n  using Monoid_A = Monoid_Affine<T>;\n  using A = typename Monoid_A::value_type;\n\
    \  using S = T;\n  static S act(const S &x, const A &g) { return g.fi * x + g.se;\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/acted_set/affine.hpp
  requiredBy: []
  timestamp: '2022-11-28 21:09:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/_atcoder/abc270_g.test.cpp
documentation_of: alg/acted_set/affine.hpp
layout: document
redirect_from:
- /library/alg/acted_set/affine.hpp
- /library/alg/acted_set/affine.hpp.html
title: alg/acted_set/affine.hpp
---
