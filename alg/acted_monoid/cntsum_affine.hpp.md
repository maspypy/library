---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  - icon: ':question:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/255.test.cpp
    title: test/3_yukicoder/255.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add_pair.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Monoid_Add_Pair {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) {\r\n    return {x.fi + y.fi,\
    \ x.se + y.se};\r\n  }\r\n  static constexpr X inverse(const X &x) { return {-x.fi,\
    \ -x.se}; }\r\n  static constexpr X unit() { return {0, 0}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/affine.hpp\"\n\n// op(F,\
    \ G) = comp(G,F), F \u306E\u3042\u3068\u3067 G\ntemplate <typename K>\nstruct\
    \ Monoid_Affine {\n  using F = pair<K, K>;\n  using value_type = F;\n  using X\
    \ = value_type;\n  static constexpr F op(const F &x, const F &y) noexcept {\n\
    \    return F({x.first * y.first, x.second * y.first + y.second});\n  }\n  static\
    \ constexpr F inverse(const F &x) {\n    auto [a, b] = x;\n    a = K(1) / a;\n\
    \    return {a, a * (-b)};\n  }\n  static constexpr K eval(const F &f, K x) noexcept\
    \ {\n    return f.first * x + f.second;\n  }\n  static constexpr F unit() { return\
    \ {K(1), K(0)}; }\n  static constexpr bool commute = false;\n};\n#line 3 \"alg/acted_monoid/cntsum_affine.hpp\"\
    \n\ntemplate <typename E>\nstruct ActedMonoid_CntSum_Affine {\n  using Monoid_X\
    \ = Monoid_Add_Pair<E>;\n  using Monoid_A = Monoid_Affine<E>;\n  using X = typename\
    \ Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\n    return {x.fi,\
    \ x.se * a.fi + x.fi * a.se};\n  }\n};\n"
  code: "#include \"alg/monoid/add_pair.hpp\"\n#include \"alg/monoid/affine.hpp\"\n\
    \ntemplate <typename E>\nstruct ActedMonoid_CntSum_Affine {\n  using Monoid_X\
    \ = Monoid_Add_Pair<E>;\n  using Monoid_A = Monoid_Affine<E>;\n  using X = typename\
    \ Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\n    return {x.fi,\
    \ x.se * a.fi + x.fi * a.se};\n  }\n};"
  dependsOn:
  - alg/monoid/add_pair.hpp
  - alg/monoid/affine.hpp
  isVerificationFile: false
  path: alg/acted_monoid/cntsum_affine.hpp
  requiredBy: []
  timestamp: '2023-07-25 22:13:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/255.test.cpp
documentation_of: alg/acted_monoid/cntsum_affine.hpp
layout: document
redirect_from:
- /library/alg/acted_monoid/cntsum_affine.hpp
- /library/alg/acted_monoid/cntsum_affine.hpp.html
title: alg/acted_monoid/cntsum_affine.hpp
---
