---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: nt/mertens.hpp
    title: nt/mertens.hpp
  - icon: ':x:'
    path: nt/range_rational_count.hpp
    title: nt/range_rational_count.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/floor_ceil_ranges.test.cpp
    title: test/1_mytest/floor_ceil_ranges.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/math/enumerate_quotients.test.cpp
    title: test/2_library_checker/math/enumerate_quotients.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1260.test.cpp
    title: test/3_yukicoder/1260.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1276.test.cpp
    title: test/3_yukicoder/1276.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1573.test.cpp
    title: test/3_yukicoder/1573.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2266.test.cpp
    title: test/3_yukicoder/2266.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/4954.test.cpp
    title: test/3_yukicoder/4954.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/floor_range.hpp\"\n// \u5546\u304C q \u306E\u533A\
    \u9593 [l,r) \u3092 q \u306B\u3064\u3044\u3066\u6607\u9806\r\ntemplate <typename\
    \ F>\r\nvoid floor_range(u64 N, F f) {\r\n  assert(N <= (u64(1) << 50));\r\n \
    \ u64 sq = sqrtl(N);\r\n  u32 n = (sq * sq + sq <= N ? sq : sq - 1);\r\n  u64\
    \ prev = N + 1;\r\n  for (u32 q = 1; q <= n; ++q) {\r\n    u64 x = double(N) /\
    \ (q + 1) + 1;\r\n    f(q, x, prev), prev = x;\r\n  }\r\n  for (u32 l = sq; l\
    \ >= 1; --l) { f(u64(double(N) / l), l, l + 1); }\r\n}\r\n"
  code: "// \u5546\u304C q \u306E\u533A\u9593 [l,r) \u3092 q \u306B\u3064\u3044\u3066\
    \u6607\u9806\r\ntemplate <typename F>\r\nvoid floor_range(u64 N, F f) {\r\n  assert(N\
    \ <= (u64(1) << 50));\r\n  u64 sq = sqrtl(N);\r\n  u32 n = (sq * sq + sq <= N\
    \ ? sq : sq - 1);\r\n  u64 prev = N + 1;\r\n  for (u32 q = 1; q <= n; ++q) {\r\
    \n    u64 x = double(N) / (q + 1) + 1;\r\n    f(q, x, prev), prev = x;\r\n  }\r\
    \n  for (u32 l = sq; l >= 1; --l) { f(u64(double(N) / l), l, l + 1); }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/floor_range.hpp
  requiredBy:
  - nt/range_rational_count.hpp
  - nt/mertens.hpp
  timestamp: '2023-11-24 15:08:08+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1276.test.cpp
  - test/3_yukicoder/4954.test.cpp
  - test/3_yukicoder/2266.test.cpp
  - test/3_yukicoder/1260.test.cpp
  - test/3_yukicoder/1573.test.cpp
  - test/2_library_checker/math/enumerate_quotients.test.cpp
  - test/1_mytest/floor_ceil_ranges.test.cpp
documentation_of: enumerate/floor_range.hpp
layout: document
redirect_from:
- /library/enumerate/floor_range.hpp
- /library/enumerate/floor_range.hpp.html
title: enumerate/floor_range.hpp
---
