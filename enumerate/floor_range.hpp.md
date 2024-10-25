---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: nt/mertens.hpp
    title: nt/mertens.hpp
  - icon: ':heavy_check_mark:'
    path: nt/range_rational_count.hpp
    title: nt/range_rational_count.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/floor_ceil_ranges.test.cpp
    title: test/1_mytest/floor_ceil_ranges.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/enumerate_quotients.test.cpp
    title: test/2_library_checker/number_theory/enumerate_quotients.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1260.test.cpp
    title: test/3_yukicoder/1260.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1276.test.cpp
    title: test/3_yukicoder/1276.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1573.test.cpp
    title: test/3_yukicoder/1573.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2266.test.cpp
    title: test/3_yukicoder/2266.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/4954.test.cpp
    title: test/3_yukicoder/4954.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/floor_range.hpp\"\n// \u5546\u304C q \u306E\u533A\
    \u9593 [l,r) \u3092 q \u306B\u3064\u3044\u3066\u6607\u9806\r\ntemplate <typename\
    \ F>\r\nvoid floor_range(u64 N, F f, bool Q_ASC = true, bool INCLUDE_Q_IS_0 =\
    \ false) {\r\n  u64 sq = sqrtl(N);\r\n  u32 n = (sq * sq + sq <= N ? sq : sq -\
    \ 1);\r\n  if (Q_ASC) {\r\n    if (INCLUDE_Q_IS_0) f(0, N + 1, infty<ll>);\r\n\
    \    for (u32 q = 1; q <= n; ++q) { f(q, N / (q + 1) + 1, N / q + 1); }\r\n  \
    \  for (u32 l = sq; l >= 1; --l) { f(N / l, l, l + 1); }\r\n  } else {\r\n   \
    \ for (u32 l = 1; l <= sq; ++l) { f(N / l, l, l + 1); }\r\n    for (u32 q = n;\
    \ q >= 1; --q) { f(q, N / (q + 1) + 1, N / q + 1); }\r\n    if (INCLUDE_Q_IS_0)\
    \ f(0, N + 1, infty<ll>);\r\n  }\r\n}\r\n"
  code: "// \u5546\u304C q \u306E\u533A\u9593 [l,r) \u3092 q \u306B\u3064\u3044\u3066\
    \u6607\u9806\r\ntemplate <typename F>\r\nvoid floor_range(u64 N, F f, bool Q_ASC\
    \ = true, bool INCLUDE_Q_IS_0 = false) {\r\n  u64 sq = sqrtl(N);\r\n  u32 n =\
    \ (sq * sq + sq <= N ? sq : sq - 1);\r\n  if (Q_ASC) {\r\n    if (INCLUDE_Q_IS_0)\
    \ f(0, N + 1, infty<ll>);\r\n    for (u32 q = 1; q <= n; ++q) { f(q, N / (q +\
    \ 1) + 1, N / q + 1); }\r\n    for (u32 l = sq; l >= 1; --l) { f(N / l, l, l +\
    \ 1); }\r\n  } else {\r\n    for (u32 l = 1; l <= sq; ++l) { f(N / l, l, l + 1);\
    \ }\r\n    for (u32 q = n; q >= 1; --q) { f(q, N / (q + 1) + 1, N / q + 1); }\r\
    \n    if (INCLUDE_Q_IS_0) f(0, N + 1, infty<ll>);\r\n  }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/floor_range.hpp
  requiredBy:
  - nt/mertens.hpp
  - nt/range_rational_count.hpp
  timestamp: '2024-09-14 09:20:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2266.test.cpp
  - test/3_yukicoder/4954.test.cpp
  - test/3_yukicoder/1260.test.cpp
  - test/3_yukicoder/1276.test.cpp
  - test/3_yukicoder/1573.test.cpp
  - test/1_mytest/floor_ceil_ranges.test.cpp
  - test/2_library_checker/number_theory/enumerate_quotients.test.cpp
documentation_of: enumerate/floor_range.hpp
layout: document
redirect_from:
- /library/enumerate/floor_range.hpp
- /library/enumerate/floor_range.hpp.html
title: enumerate/floor_range.hpp
---
