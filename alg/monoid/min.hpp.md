---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/acted_monoid/max_min.hpp
    title: alg/acted_monoid/max_min.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/min_add.hpp
    title: alg/acted_monoid/min_add.hpp
  - icon: ':x:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/min_max.hpp
    title: alg/acted_monoid/min_max.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/min_min.hpp
    title: alg/acted_monoid/min_min.hpp
  - icon: ':x:'
    path: ds/offline_query/range_mex_query.hpp
    title: ds/offline_query/range_mex_query.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508_2.test.cpp
    title: test/aoj/1508_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  - icon: ':x:'
    path: test/mytest/range_mex.test.cpp
    title: test/mytest/range_mex.test.cpp
  - icon: ':x:'
    path: test/mytest/rbst_am.test.cpp
    title: test/mytest/rbst_am.test.cpp
  - icon: ':x:'
    path: test/mytest/rbst_am_persistent.test.cpp
    title: test/mytest/rbst_am_persistent.test.cpp
  - icon: ':x:'
    path: test/mytest/rbst_test.test.cpp
    title: test/mytest/rbst_test.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1212.test.cpp
    title: test/yukicoder/1212.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <class X>\r\nstruct Monoid_Min\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return min(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class X>\r\nstruct Monoid_Min {\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return min(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/min.hpp
  requiredBy:
  - alg/acted_monoid/min_add.hpp
  - alg/acted_monoid/min_assign.hpp
  - alg/acted_monoid/min_min.hpp
  - alg/acted_monoid/min_max.hpp
  - alg/acted_monoid/max_min.hpp
  - ds/offline_query/range_mex_query.hpp
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1212.test.cpp
  - test/mytest/range_mex.test.cpp
  - test/mytest/rbst_am.test.cpp
  - test/mytest/rbst_am_persistent.test.cpp
  - test/mytest/rbst_test.test.cpp
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
  - test/aoj/1508_2.test.cpp
documentation_of: alg/monoid/min.hpp
layout: document
redirect_from:
- /library/alg/monoid/min.hpp
- /library/alg/monoid/min.hpp.html
title: alg/monoid/min.hpp
---
