---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':question:'
    path: nt/discrete_log.hpp
    title: nt/discrete_log.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc270_g.test.cpp
    title: test/atcoder/abc270_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/acted_set/from_monoid.hpp\"\ntemplate <typename Monoid>\n\
    struct ActedSet_From_Monoid {\n  using Monoid_A = Monoid;\n  using A = typename\
    \ Monoid::value_type;\n  using S = A;\n  static S act(const S &x, const A &g)\
    \ { return Monoid::op(x, g); }\n};\n"
  code: "template <typename Monoid>\nstruct ActedSet_From_Monoid {\n  using Monoid_A\
    \ = Monoid;\n  using A = typename Monoid::value_type;\n  using S = A;\n  static\
    \ S act(const S &x, const A &g) { return Monoid::op(x, g); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/acted_set/from_monoid.hpp
  requiredBy:
  - nt/discrete_log.hpp
  - mod/mod_log.hpp
  timestamp: '2022-11-28 21:09:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1339.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test/atcoder/abc270_g.test.cpp
documentation_of: alg/acted_set/from_monoid.hpp
layout: document
redirect_from:
- /library/alg/acted_set/from_monoid.hpp
- /library/alg/acted_set/from_monoid.hpp.html
title: alg/acted_set/from_monoid.hpp
---
