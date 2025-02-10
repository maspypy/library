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
    path: test/2_library_checker/number_theory/enumerate_quotients2.test.cpp
    title: test/2_library_checker/number_theory/enumerate_quotients2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2266.test.cpp
    title: test/3_yukicoder/2266.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/array_on_floor.hpp\"\n// N=10 \u3060\u3068 dat = {dp[1],\
    \ dp[2], dp[3], dp[5], dp[10]} \u307F\u305F\u3044\u306B\u306A\u308B\n// hashmap\
    \ \u3088\u308A\u6570\u500D\u9AD8\u901F\ntemplate <typename T>\nstruct Array_On_Floor\
    \ {\n  u64 N;\n  u32 t, sq;\n  vc<T> dat;\n  Array_On_Floor() {}\n  Array_On_Floor(u64\
    \ N, T default_value = T{}) : N(N) {\n    assert(N <= u64(1) << 50);\n    sq =\
    \ sqrtl(N);\n    t = (u64(sq) * sq + sq <= N ? sq : sq - 1);\n    dat.resize(t\
    \ + sq, default_value);\n  }\n\n  u32 size() { return dat.size(); }\n\n  T& operator[](u64\
    \ d) {\n    int i = get_index(d);\n    return dat[i];\n  }\n\n  inline u32 get_index(u64\
    \ d) {\n    assert(d > 0);\n    if (d <= t) return d - 1;\n    return dat.size()\
    \ - u32(double(N) / d);\n  }\n\n  // dat[i] \u306B\u5BFE\u5FDC\u3059\u308B floor\n\
    \  u64 get_floor(u32 i) { return (i < t ? 1 + i : double(N) / (t + sq - i)); }\n\
    \n  template <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(dat)) {\
    \ f(get_floor(i), dat[i]); }\n  }\n};\n"
  code: "// N=10 \u3060\u3068 dat = {dp[1], dp[2], dp[3], dp[5], dp[10]} \u307F\u305F\
    \u3044\u306B\u306A\u308B\n// hashmap \u3088\u308A\u6570\u500D\u9AD8\u901F\ntemplate\
    \ <typename T>\nstruct Array_On_Floor {\n  u64 N;\n  u32 t, sq;\n  vc<T> dat;\n\
    \  Array_On_Floor() {}\n  Array_On_Floor(u64 N, T default_value = T{}) : N(N)\
    \ {\n    assert(N <= u64(1) << 50);\n    sq = sqrtl(N);\n    t = (u64(sq) * sq\
    \ + sq <= N ? sq : sq - 1);\n    dat.resize(t + sq, default_value);\n  }\n\n \
    \ u32 size() { return dat.size(); }\n\n  T& operator[](u64 d) {\n    int i = get_index(d);\n\
    \    return dat[i];\n  }\n\n  inline u32 get_index(u64 d) {\n    assert(d > 0);\n\
    \    if (d <= t) return d - 1;\n    return dat.size() - u32(double(N) / d);\n\
    \  }\n\n  // dat[i] \u306B\u5BFE\u5FDC\u3059\u308B floor\n  u64 get_floor(u32\
    \ i) { return (i < t ? 1 + i : double(N) / (t + sq - i)); }\n\n  template <typename\
    \ F>\n  void enumerate_all(F f) {\n    FOR(i, len(dat)) { f(get_floor(i), dat[i]);\
    \ }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: nt/array_on_floor.hpp
  requiredBy:
  - nt/mertens.hpp
  - nt/range_rational_count.hpp
  timestamp: '2024-08-13 20:27:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2266.test.cpp
  - test/2_library_checker/number_theory/enumerate_quotients2.test.cpp
documentation_of: nt/array_on_floor.hpp
layout: document
redirect_from:
- /library/nt/array_on_floor.hpp
- /library/nt/array_on_floor.hpp.html
title: nt/array_on_floor.hpp
---
