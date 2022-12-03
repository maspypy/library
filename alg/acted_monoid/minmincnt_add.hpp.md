---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':warning:'
    path: alg/monoid/minmincnt.hpp
    title: alg/monoid/minmincnt.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: other/rectangleunion.hpp
    title: other/rectangleunion.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/minmincnt.hpp\"\n\r\n// \u6700\u5C0F\u5024\u3001\
    \u6700\u5C0F\u5024\u306E\u500B\u6570\r\ntemplate <typename E>\r\nstruct Monoid_MinMincnt\
    \ {\r\n  using value_type = tuple<E, E, E>;\r\n  using X = value_type;\r\n  static\
    \ X from_element(E x) { return {x, 1}; }\r\n  static X op(X x, X y) {\r\n    auto\
    \ [xmin, xmincnt] = x;\r\n    auto [ymin, ymincnt] = y;\r\n    if (xmin > ymin)\
    \ return {ymin, ymincnt};\r\n    if (xmin == ymin) return {xmin, xmincnt + ymincnt};\r\
    \n    return {xmin, xmincnt};\r\n  }\r\n  static constexpr X unit() { return {numeric_limits<E>::max(),\
    \ 0}; }\r\n  static constexpr bool commute = true;\r\n};\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\
    \n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\n  static\
    \ constexpr X unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 3 \"alg/acted_monoid/minmincnt_add.hpp\"\n\r\ntemplate <typename\
    \ E>\r\nstruct ActedMonoid_CntMinMincnt_Add {\r\n  using Monoid_X = Monoid_CntMinMincnt<E>;\r\
    \n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    auto [xmin, xmincnt] = x;\r\n   \
    \ if (xmin == numeric_limits<ll>::max()) return x;\r\n    return {xmin + a, xmincnt};\r\
    \n  }\r\n};\r\n"
  code: "#include \"alg/monoid/minmincnt.hpp\"\r\n#include \"alg/monoid/add.hpp\"\r\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_CntMinMincnt_Add {\r\n  using\
    \ Monoid_X = Monoid_CntMinMincnt<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n\
    \  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  static constexpr X act(const X &x, const A &a, const ll &size) {\r\n    auto\
    \ [xmin, xmincnt] = x;\r\n    if (xmin == numeric_limits<ll>::max()) return x;\r\
    \n    return {xmin + a, xmincnt};\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/minmincnt.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: alg/acted_monoid/minmincnt_add.hpp
  requiredBy:
  - other/rectangleunion.hpp
  timestamp: '2022-12-03 07:16:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/acted_monoid/minmincnt_add.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/minmincnt_add.hpp
- /library/alg/acted_monoid/minmincnt_add.hpp.html
title: alg/acted_monoid/minmincnt_add.hpp
---
