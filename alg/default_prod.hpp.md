---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/alg/default_prod.hpp
  bundledCode: "#line 1 \"alg/default_prod.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/default_prod.hpp\n\
    template <class Monoid>\nstruct DefaultUnitProd {\n  using X = typename Monoid::value_type;\n\
    \  static constexpr bool unit_only = true;\n  X operator()(long long, long long)\
    \ const { return Monoid::id(); }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/alg/default_prod.hpp\n\
    template <class Monoid>\nstruct DefaultUnitProd {\n  using X = typename Monoid::value_type;\n\
    \  static constexpr bool unit_only = true;\n  X operator()(long long, long long)\
    \ const { return Monoid::id(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/default_prod.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/default_prod.hpp
layout: document
redirect_from:
- /library/alg/default_prod.hpp
- /library/alg/default_prod.hpp.html
title: alg/default_prod.hpp
---
