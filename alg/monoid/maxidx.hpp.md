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
  bundledCode: "#line 1 \"alg/monoid/maxidx.hpp\"\n\ntemplate <typename T, bool tie_is_left\
    \ = true>\nstruct Monoid_MaxIdx {\n  using value_type = pair<T, int>;\n  using\
    \ X = value_type;\n  static X op(X x, X y) {\n    if (x.fi > y.fi) return x;\n\
    \    if (x.fi < y.fi) return y;\n    if (x.se > y.se) swap(x, y);\n    return\
    \ (tie_is_left ? x : y);\n  }\n  static constexpr X unit() { return {-infty<T>,\
    \ -1}; }\n  static constexpr bool commute = true;\n};\n"
  code: "\ntemplate <typename T, bool tie_is_left = true>\nstruct Monoid_MaxIdx {\n\
    \  using value_type = pair<T, int>;\n  using X = value_type;\n  static X op(X\
    \ x, X y) {\n    if (x.fi > y.fi) return x;\n    if (x.fi < y.fi) return y;\n\
    \    if (x.se > y.se) swap(x, y);\n    return (tie_is_left ? x : y);\n  }\n  static\
    \ constexpr X unit() { return {-infty<T>, -1}; }\n  static constexpr bool commute\
    \ = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/maxidx.hpp
  requiredBy: []
  timestamp: '2026-08-17 08:30:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/maxidx.hpp
layout: document
redirect_from:
- /library/alg/monoid/maxidx.hpp
- /library/alg/monoid/maxidx.hpp.html
title: alg/monoid/maxidx.hpp
---
