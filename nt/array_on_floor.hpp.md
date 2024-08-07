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
    path: test/library_checker/math/enumerate_quotients2.test.cpp
    title: test/library_checker/math/enumerate_quotients2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2266.test.cpp
    title: test/yukicoder/2266.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/array_on_floor.hpp\"\n// N=10 \u3060\u3068 dat = {dp[1],\
    \ dp[2], dp[3], dp[5], dp[10]} \u307F\u305F\u3044\u306B\u306A\u308B\n// hashmap\
    \ \u3088\u308A\u6570\u500D\u9AD8\u901F\ntemplate <typename T>\nstruct Array_On_Floor\
    \ {\n  u64 N;\n  u32 n, sq;\n  vc<T> dat;\n  Array_On_Floor() {}\n  Array_On_Floor(u64\
    \ N, T default_value = T{}) : N(N) {\n    assert(N <= u64(1) << 50);\n    sq =\
    \ sqrtl(N);\n    n = (u64(sq) * sq + sq <= N ? sq : sq - 1);\n    dat.resize(n\
    \ + sq, default_value);\n  }\n\n  u32 size() { return dat.size(); }\n\n  T& operator[](u64\
    \ d) {\n    int i = get_index(d);\n    return dat[i];\n  }\n\n  inline u32 get_index(u64\
    \ d) {\n    assert(d > 0);\n    if (d <= n) return d - 1;\n    return dat.size()\
    \ - u32(double(N) / d);\n  }\n\n  // dat[i] \u306B\u5BFE\u5FDC\u3059\u308B floor\n\
    \  u64 get_floor(u32 i) { return (i < n ? 1 + i : double(N) / (n + sq - i)); }\n\
    \n  template <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(dat)) {\
    \ f(get_floor(i), dat[i]); }\n  }\n};\n"
  code: "// N=10 \u3060\u3068 dat = {dp[1], dp[2], dp[3], dp[5], dp[10]} \u307F\u305F\
    \u3044\u306B\u306A\u308B\n// hashmap \u3088\u308A\u6570\u500D\u9AD8\u901F\ntemplate\
    \ <typename T>\nstruct Array_On_Floor {\n  u64 N;\n  u32 n, sq;\n  vc<T> dat;\n\
    \  Array_On_Floor() {}\n  Array_On_Floor(u64 N, T default_value = T{}) : N(N)\
    \ {\n    assert(N <= u64(1) << 50);\n    sq = sqrtl(N);\n    n = (u64(sq) * sq\
    \ + sq <= N ? sq : sq - 1);\n    dat.resize(n + sq, default_value);\n  }\n\n \
    \ u32 size() { return dat.size(); }\n\n  T& operator[](u64 d) {\n    int i = get_index(d);\n\
    \    return dat[i];\n  }\n\n  inline u32 get_index(u64 d) {\n    assert(d > 0);\n\
    \    if (d <= n) return d - 1;\n    return dat.size() - u32(double(N) / d);\n\
    \  }\n\n  // dat[i] \u306B\u5BFE\u5FDC\u3059\u308B floor\n  u64 get_floor(u32\
    \ i) { return (i < n ? 1 + i : double(N) / (n + sq - i)); }\n\n  template <typename\
    \ F>\n  void enumerate_all(F f) {\n    FOR(i, len(dat)) { f(get_floor(i), dat[i]);\
    \ }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: nt/array_on_floor.hpp
  requiredBy:
  - nt/range_rational_count.hpp
  - nt/mertens.hpp
  timestamp: '2023-11-24 15:08:08+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/2266.test.cpp
  - test/library_checker/math/enumerate_quotients2.test.cpp
documentation_of: nt/array_on_floor.hpp
layout: document
redirect_from:
- /library/nt/array_on_floor.hpp
- /library/nt/array_on_floor.hpp.html
title: nt/array_on_floor.hpp
---
