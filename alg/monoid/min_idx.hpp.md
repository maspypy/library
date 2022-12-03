---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/acted_monoid/minidx_add.hpp
    title: alg/acted_monoid/minidx_add.hpp
  - icon: ':warning:'
    path: convex/dynamic_lichao.hpp
    title: convex/dynamic_lichao.hpp
  - icon: ':warning:'
    path: ds/pds/persistent_dynamic_lichao.hpp
    title: ds/pds/persistent_dynamic_lichao.hpp
  - icon: ':warning:'
    path: geo/manhattan_nns.hpp
    title: geo/manhattan_nns.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min_idx.hpp\"\n\r\ntemplate <typename T, bool\
    \ tie_is_left = true>\r\nstruct Monoid_Min_Idx {\r\n  using value_type = pair<T,\
    \ int>;\r\n  using X = value_type;\r\n  static constexpr bool is_small(const X&\
    \ x, const X& y) {\r\n    if (x.fi < y.fi) return true;\r\n    if (x.fi > y.fi)\
    \ return false;\r\n    return (tie_is_left ? (x.se < y.se) : (x.se >= y.se));\r\
    \n  }\r\n  static X op(X x, X y) { return (is_small(x, y) ? x : y); }\r\n  static\
    \ constexpr X unit() { return {numeric_limits<T>::max(), -1}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T, bool tie_is_left = true>\r\nstruct\
    \ Monoid_Min_Idx {\r\n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\
    \n  static constexpr bool is_small(const X& x, const X& y) {\r\n    if (x.fi <\
    \ y.fi) return true;\r\n    if (x.fi > y.fi) return false;\r\n    return (tie_is_left\
    \ ? (x.se < y.se) : (x.se >= y.se));\r\n  }\r\n  static X op(X x, X y) { return\
    \ (is_small(x, y) ? x : y); }\r\n  static constexpr X unit() { return {numeric_limits<T>::max(),\
    \ -1}; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/min_idx.hpp
  requiredBy:
  - alg/acted_monoid/minidx_add.hpp
  - convex/dynamic_lichao.hpp
  - geo/manhattan_nns.hpp
  - ds/pds/persistent_dynamic_lichao.hpp
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/min_idx.hpp
layout: document
redirect_from:
- /library/alg/monoid/min_idx.hpp
- /library/alg/monoid/min_idx.hpp.html
title: alg/monoid/min_idx.hpp
---
