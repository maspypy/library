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
  bundledCode: "#line 1 \"alg/XSet/affine.hpp\"\n// 1 \u6B21\u5143\u30D9\u30AF\u30C8\
    \u30EB\u7A7A\u9593\u306B\u3001\u30A2\u30D5\u30A3\u30F3\u5909\u63DB\u304C\u4F5C\
    \u7528\ntemplate <typename T>\nstruct XSet_Affine {\n  using Monoid = Monoid_Affine<T>;\n\
    \  using operator_type = typename Monoid::value_type;\n  using element_type =\
    \ T;\n  using X = operator_type;\n  using S = element_type;\n  static S act(const\
    \ S &x, const X &g) { return g.fi * x + g.se; }\n};\n"
  code: "// 1 \u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u7A7A\u9593\u306B\u3001\u30A2\u30D5\
    \u30A3\u30F3\u5909\u63DB\u304C\u4F5C\u7528\ntemplate <typename T>\nstruct XSet_Affine\
    \ {\n  using Monoid = Monoid_Affine<T>;\n  using operator_type = typename Monoid::value_type;\n\
    \  using element_type = T;\n  using X = operator_type;\n  using S = element_type;\n\
    \  static S act(const S &x, const X &g) { return g.fi * x + g.se; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/XSet/affine.hpp
  requiredBy: []
  timestamp: '2022-11-27 20:29:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/XSet/affine.hpp
layout: document
redirect_from:
- /library/alg/XSet/affine.hpp
- /library/alg/XSet/affine.hpp.html
title: alg/XSet/affine.hpp
---
