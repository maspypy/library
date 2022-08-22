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
  bundledCode: "#line 1 \"alg/group_reverse.hpp\"\ntemplate <class Group>\r\nstruct\
    \ Group_Reverse {\r\n  using value_type = typename Group::value_type;\r\n  using\
    \ X = value_type;\r\n  static constexpr X op(const X &x, const X &y) { return\
    \ Group::op(y, x); }\r\n  static constexpr X inverse(const X &x) { return Group::inverse(x);\
    \ }\r\n  static constexpr X unit() { return Group::unit(); }\r\n  static const\
    \ bool commute = Group::commute;\r\n};\r\n"
  code: "template <class Group>\r\nstruct Group_Reverse {\r\n  using value_type =\
    \ typename Group::value_type;\r\n  using X = value_type;\r\n  static constexpr\
    \ X op(const X &x, const X &y) { return Group::op(y, x); }\r\n  static constexpr\
    \ X inverse(const X &x) { return Group::inverse(x); }\r\n  static constexpr X\
    \ unit() { return Group::unit(); }\r\n  static const bool commute = Group::commute;\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/group_reverse.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/group_reverse.hpp
layout: document
redirect_from:
- /library/alg/group_reverse.hpp
- /library/alg/group_reverse.hpp.html
title: alg/group_reverse.hpp
---
