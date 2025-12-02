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
  bundledCode: "#line 1 \"alg/default_prod.hpp\"\ntemplate <class Monoid>\nstruct\
    \ DefaultUnitProd {\n  using X = typename Monoid::value_type;\n  static constexpr\
    \ bool unit_only = true;\n  X operator()(long long, long long) const { return\
    \ Monoid::unit(); }\n};\n"
  code: "template <class Monoid>\nstruct DefaultUnitProd {\n  using X = typename Monoid::value_type;\n\
    \  static constexpr bool unit_only = true;\n  X operator()(long long, long long)\
    \ const { return Monoid::unit(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/default_prod.hpp
  requiredBy: []
  timestamp: '2025-09-01 19:47:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/default_prod.hpp
layout: document
redirect_from:
- /library/alg/default_prod.hpp
- /library/alg/default_prod.hpp.html
title: alg/default_prod.hpp
---
