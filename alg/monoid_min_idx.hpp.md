---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geo/manhattan_nns.hpp
    title: geo/manhattan_nns.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_min_idx.hpp\"\ntemplate <typename T>\r\nstruct\
    \ Monoid_Min_Idx {\r\n  using value_type = pair<T, ll>;\r\n  using X = value_type;\r\
    \n  static X op(X x, X y) { return min(x, y); }\r\n  static constexpr X unit()\
    \ { return {numeric_limits<T>::max(), -1}; }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  code: "template <typename T>\r\nstruct Monoid_Min_Idx {\r\n  using value_type =\
    \ pair<T, ll>;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return\
    \ min(x, y); }\r\n  static constexpr X unit() { return {numeric_limits<T>::max(),\
    \ -1}; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_min_idx.hpp
  requiredBy:
  - geo/manhattan_nns.hpp
  timestamp: '2022-05-13 21:02:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid_min_idx.hpp
layout: document
redirect_from:
- /library/alg/monoid_min_idx.hpp
- /library/alg/monoid_min_idx.hpp.html
title: alg/monoid_min_idx.hpp
---
