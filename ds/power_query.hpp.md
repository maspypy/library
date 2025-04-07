---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/count/count_labeled_bipartite.hpp
    title: graph/count/count_labeled_bipartite.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_bipartite.test.cpp
    title: test/1_mytest/count_bipartite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/powerquery.test.cpp
    title: test/1_mytest/powerquery.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/mul.hpp\"\n\r\ntemplate <class T>\r\nstruct Monoid_Mul\
    \ {\r\n  using value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return\
    \ X(1); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/power_query.hpp\"\
    \n\n// \u5B9A\u6570\u3092\u3079\u304D\u4E57\u3059\u308B\u30AF\u30A8\u30EA\u3002\
    \ B \u4E57\u5206\u305A\u3064\u524D\u8A08\u7B97\u3002\ntemplate <typename Mono,\
    \ int B = 1024>\nstruct Power_Query {\n  using X = typename Mono::value_type;\n\
    \  vvc<X> dat;\n\n  Power_Query(X a) { dat.eb(make_pow(a)); }\n\n  X operator()(ll\
    \ n) {\n    X res = Mono::unit();\n    int k = 0;\n    while (n) {\n      int\
    \ r = n % B;\n      n /= B;\n      if (len(dat) == k) { dat.eb(make_pow(dat[k\
    \ - 1].back())); }\n      res = Mono::op(res, dat[k][r]);\n      ++k;\n    }\n\
    \    return res;\n  }\n\n  X operator[](ll n) { return (*this)(n); }\n\nprivate:\n\
    \  vc<X> make_pow(X a) {\n    vc<X> res = {Mono::unit()};\n    FOR(B) { res.eb(Mono::op(res.back(),\
    \ a)); }\n    return res;\n  }\n};\n"
  code: "#include \"alg/monoid/mul.hpp\"\n\n// \u5B9A\u6570\u3092\u3079\u304D\u4E57\
    \u3059\u308B\u30AF\u30A8\u30EA\u3002 B \u4E57\u5206\u305A\u3064\u524D\u8A08\u7B97\
    \u3002\ntemplate <typename Mono, int B = 1024>\nstruct Power_Query {\n  using\
    \ X = typename Mono::value_type;\n  vvc<X> dat;\n\n  Power_Query(X a) { dat.eb(make_pow(a));\
    \ }\n\n  X operator()(ll n) {\n    X res = Mono::unit();\n    int k = 0;\n   \
    \ while (n) {\n      int r = n % B;\n      n /= B;\n      if (len(dat) == k) {\
    \ dat.eb(make_pow(dat[k - 1].back())); }\n      res = Mono::op(res, dat[k][r]);\n\
    \      ++k;\n    }\n    return res;\n  }\n\n  X operator[](ll n) { return (*this)(n);\
    \ }\n\nprivate:\n  vc<X> make_pow(X a) {\n    vc<X> res = {Mono::unit()};\n  \
    \  FOR(B) { res.eb(Mono::op(res.back(), a)); }\n    return res;\n  }\n};\n"
  dependsOn:
  - alg/monoid/mul.hpp
  isVerificationFile: false
  path: ds/power_query.hpp
  requiredBy:
  - graph/count/count_labeled_bipartite.hpp
  timestamp: '2022-12-05 18:15:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/count_bipartite.test.cpp
  - test/1_mytest/powerquery.test.cpp
documentation_of: ds/power_query.hpp
layout: document
redirect_from:
- /library/ds/power_query.hpp
- /library/ds/power_query.hpp.html
title: ds/power_query.hpp
---
