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
  bundledCode: "#line 1 \"alg/group/reverse.hpp\"\ntemplate <class Group>\r\nstruct\
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
  path: alg/group/reverse.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/group/reverse.hpp
layout: document
redirect_from:
- /library/alg/group/reverse.hpp
- /library/alg/group/reverse.hpp.html
title: alg/group/reverse.hpp
---
