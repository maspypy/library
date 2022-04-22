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
  bundledCode: "#line 1 \"alg/monoid_cntsum.hpp\"\nstruct Monoid_CntSum {\n  static\
    \ constexpr ll INF = 1LL << 60;\n  using value_type = pi;\n  using X = value_type;\n\
    \  static X op(X x, X y) {\n    auto [xc, xs] = x;\n    auto [yc, ys] = y;\n \
    \   return {xc + yc, xs + ys};\n  }\n  static constexpr X unit() { return {0,\
    \ 0}; }\n  static constexpr bool commute = true;\n};\n"
  code: "struct Monoid_CntSum {\n  static constexpr ll INF = 1LL << 60;\n  using value_type\
    \ = pi;\n  using X = value_type;\n  static X op(X x, X y) {\n    auto [xc, xs]\
    \ = x;\n    auto [yc, ys] = y;\n    return {xc + yc, xs + ys};\n  }\n  static\
    \ constexpr X unit() { return {0, 0}; }\n  static constexpr bool commute = true;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_cntsum.hpp
  requiredBy: []
  timestamp: '2022-04-23 03:42:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_cntsum.hpp
layout: document
redirect_from:
- /library/alg/monoid_cntsum.hpp
- /library/alg/monoid_cntsum.hpp.html
title: alg/monoid_cntsum.hpp
---
