---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1197.test.cpp
    title: test/yukicoder/1197.test.cpp
  - icon: ':x:'
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  - icon: ':x:'
    path: test/yukicoder/789_2.test.cpp
    title: test/yukicoder/789_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 1 \"alg/monoid/add_pair.hpp\"\
    \ntemplate <typename E>\r\nstruct Group_Add_Pair {\r\n  using value_type = pair<E,\
    \ E>;\r\n  using X = value_type;\r\n  static constexpr X op(const X &x, const\
    \ X &y) {\r\n    return {x.fi + y.fi, x.se + y.se};\r\n  }\r\n  static constexpr\
    \ X inverse(const X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr X unit()\
    \ { return {0, 0}; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line\
    \ 3 \"alg/lazy/cntsum_add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Lazy_CntSum_Add\
    \ {\r\n  using MX = Monoid_Add_Pair<E>;\r\n  using MA = Monoid_Add<E>;\r\n  using\
    \ X_structure = MX;\r\n  using A_structure = MA;\r\n  using X = typename MX::value_type;\r\
    \n  using A = typename MA::value_type;\r\n  static constexpr X act(const X &x,\
    \ const A &a) {\r\n    return {x.fi, x.se + x.fi * a};\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n#include \"alg/monoid/add_pair.hpp\"\r\
    \n\r\ntemplate <typename E>\r\nstruct Lazy_CntSum_Add {\r\n  using MX = Monoid_Add_Pair<E>;\r\
    \n  using MA = Monoid_Add<E>;\r\n  using X_structure = MX;\r\n  using A_structure\
    \ = MA;\r\n  using X = typename MX::value_type;\r\n  using A = typename MA::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a) {\r\n    return {x.fi, x.se\
    \ + x.fi * a};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  - alg/monoid/add_pair.hpp
  isVerificationFile: false
  path: alg/lazy/cntsum_add.hpp
  requiredBy: []
  timestamp: '2022-11-27 14:27:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/235.test.cpp
  - test/yukicoder/789_2.test.cpp
  - test/yukicoder/1197.test.cpp
  - test/aoj/GRL_5_E.test.cpp
documentation_of: alg/lazy/cntsum_add.hpp
layout: document
redirect_from:
- /library/alg/lazy/cntsum_add.hpp
- /library/alg/lazy/cntsum_add.hpp.html
title: alg/lazy/cntsum_add.hpp
---
