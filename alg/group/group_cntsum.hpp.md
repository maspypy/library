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
  bundledCode: "#line 1 \"alg/group/group_cntsum.hpp\"\ntemplate <typename E = long\
    \ long>\r\nstruct Group_CntSum {\r\n  using value_type = pair<E, E>;\r\n  using\
    \ X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\r\n   \
    \ return {x.fi + y.fi, x.se + y.se};\r\n  }\r\n  static constexpr X inverse(const\
    \ X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr X unit() { return {0,\
    \ 0}; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <typename E = long long>\r\nstruct Group_CntSum {\r\n  using value_type\
    \ = pair<E, E>;\r\n  using X = value_type;\r\n  static constexpr X op(const X\
    \ &x, const X &y) {\r\n    return {x.fi + y.fi, x.se + y.se};\r\n  }\r\n  static\
    \ constexpr X inverse(const X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr\
    \ X unit() { return {0, 0}; }\r\n  static constexpr bool commute = true;\r\n};\r\
    \n"
  dependsOn: []
  isVerificationFile: false
  path: alg/group/group_cntsum.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/group/group_cntsum.hpp
layout: document
redirect_from:
- /library/alg/group/group_cntsum.hpp
- /library/alg/group/group_cntsum.hpp.html
title: alg/group/group_cntsum.hpp
---
