---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc222g.test.cpp
    title: test/5_atcoder/abc222g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc270_g.test.cpp
    title: test/5_atcoder/abc270_g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/affine.hpp\"\n\n// op(F, G) = comp(G,F), F \u306E\
    \u3042\u3068\u3067 G\ntemplate <typename K>\nstruct Monoid_Affine {\n  using F\
    \ = pair<K, K>;\n  using value_type = F;\n  using X = value_type;\n  static constexpr\
    \ F op(const F &x, const F &y) noexcept {\n    return F({x.first * y.first, x.second\
    \ * y.first + y.second});\n  }\n  static constexpr F inverse(const F &x) {\n \
    \   auto [a, b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static\
    \ constexpr K eval(const F &f, K x) noexcept {\n    return f.first * x + f.second;\n\
    \  }\n  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr\
    \ bool commute = false;\n};\n#line 2 \"alg/acted_set/affine.hpp\"\n\n// 1 \u6B21\
    \u5143\u30D9\u30AF\u30C8\u30EB\u7A7A\u9593\u306B\u3001\u30A2\u30D5\u30A3\u30F3\
    \u5909\u63DB\u304C\u4F5C\u7528\ntemplate <typename T>\nstruct ActedSet_Affine\
    \ {\n  using Monoid_A = Monoid_Affine<T>;\n  using A = typename Monoid_A::value_type;\n\
    \  using S = T;\n  static S act(const S &x, const A &g) { return g.fi * x + g.se;\
    \ }\n};\n"
  code: "#include \"alg/monoid/affine.hpp\"\n\n// 1 \u6B21\u5143\u30D9\u30AF\u30C8\
    \u30EB\u7A7A\u9593\u306B\u3001\u30A2\u30D5\u30A3\u30F3\u5909\u63DB\u304C\u4F5C\
    \u7528\ntemplate <typename T>\nstruct ActedSet_Affine {\n  using Monoid_A = Monoid_Affine<T>;\n\
    \  using A = typename Monoid_A::value_type;\n  using S = T;\n  static S act(const\
    \ S &x, const A &g) { return g.fi * x + g.se; }\n};\n"
  dependsOn:
  - alg/monoid/affine.hpp
  isVerificationFile: false
  path: alg/acted_set/affine.hpp
  requiredBy: []
  timestamp: '2023-07-25 22:13:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/5_atcoder/abc270_g.test.cpp
  - test/5_atcoder/abc222g.test.cpp
documentation_of: alg/acted_set/affine.hpp
layout: document
redirect_from:
- /library/alg/acted_set/affine.hpp
- /library/alg/acted_set/affine.hpp.html
title: alg/acted_set/affine.hpp
---
