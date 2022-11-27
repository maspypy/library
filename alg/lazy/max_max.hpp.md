---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/max.hpp
    title: alg/monoid/max.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_max.test.cpp
    title: test/mytest/max_max.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/max.hpp\"\ntemplate <class X>\r\nstruct Monoid_Max\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::lowest();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/lazy/max_max.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Lazy_Max_Max {\r\n  using MX = Monoid_Max<E>;\r\
    \n  using MA = Monoid_Max<E>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) { return max(x, a); }\r\n};\r\
    \n"
  code: "#include \"alg/monoid/max.hpp\"\r\n\r\ntemplate <typename E>\r\nstruct Lazy_Max_Max\
    \ {\r\n  using MX = Monoid_Max<E>;\r\n  using MA = Monoid_Max<E>;\r\n  using X_structure\
    \ = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) { return max(x, a); }\r\n};\r\n"
  dependsOn:
  - alg/monoid/max.hpp
  isVerificationFile: false
  path: alg/lazy/max_max.hpp
  requiredBy: []
  timestamp: '2022-10-24 13:59:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/max_max.test.cpp
documentation_of: alg/lazy/max_max.hpp
layout: document
redirect_from:
- /library/alg/lazy/max_max.hpp
- /library/alg/lazy/max_max.hpp.html
title: alg/lazy/max_max.hpp
---
