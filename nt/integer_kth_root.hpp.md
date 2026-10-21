---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: nt/dirichlet.hpp
    title: nt/dirichlet.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/dirichlet.test.cpp
    title: test/1_mytest/dirichlet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/dirichlet.test.cpp
    title: test/2_library_checker/number_theory/dirichlet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/dirichlet_inv.test.cpp
    title: test/2_library_checker/number_theory/dirichlet_inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/kth_root_integer.test.cpp
    title: test/2_library_checker/number_theory/kth_root_integer.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1260.test.cpp
    title: test/3_yukicoder/1260.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1666.test.cpp
    title: test/3_yukicoder/1666.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/nt/integer_kth_root.hpp
  bundledCode: "#line 1 \"nt/integer_kth_root.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/integer_kth_root.hpp\n\
    u64 integer_kth_root(u64 k, u64 a) {\n  assert(k >= 1);\n  if (a == 0 || a ==\
    \ 1 || k == 1) return a;\n  if (k >= 64) return 1;\n  if (k == 2) return sqrtl(a);\n\
    \  if (a == u64(-1)) --a;\n  struct S {\n    u64 v;\n    S& operator*=(const S&\
    \ o) {\n      v = v <= u64(-1) / o.v ? v * o.v : u64(-1);\n      return *this;\n\
    \    }\n  };\n  auto power = [&](S x, ll n) -> S {\n    S v{1};\n    while (n)\
    \ {\n      if (n & 1) v *= x;\n      x *= x;\n      n /= 2;\n    }\n    return\
    \ v;\n  };\n  u64 res = pow(a, nextafter(1 / double(k), 0));\n  while (power(S{res\
    \ + 1}, k).v <= a) ++res;\n  return res;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/nt/integer_kth_root.hpp\n\
    u64 integer_kth_root(u64 k, u64 a) {\n  assert(k >= 1);\n  if (a == 0 || a ==\
    \ 1 || k == 1) return a;\n  if (k >= 64) return 1;\n  if (k == 2) return sqrtl(a);\n\
    \  if (a == u64(-1)) --a;\n  struct S {\n    u64 v;\n    S& operator*=(const S&\
    \ o) {\n      v = v <= u64(-1) / o.v ? v * o.v : u64(-1);\n      return *this;\n\
    \    }\n  };\n  auto power = [&](S x, ll n) -> S {\n    S v{1};\n    while (n)\
    \ {\n      if (n & 1) v *= x;\n      x *= x;\n      n /= 2;\n    }\n    return\
    \ v;\n  };\n  u64 res = pow(a, nextafter(1 / double(k), 0));\n  while (power(S{res\
    \ + 1}, k).v <= a) ++res;\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/integer_kth_root.hpp
  requiredBy:
  - nt/dirichlet.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1666.test.cpp
  - test/3_yukicoder/1260.test.cpp
  - test/1_mytest/dirichlet.test.cpp
  - test/2_library_checker/number_theory/dirichlet_inv.test.cpp
  - test/2_library_checker/number_theory/kth_root_integer.test.cpp
  - test/2_library_checker/number_theory/dirichlet.test.cpp
documentation_of: nt/integer_kth_root.hpp
layout: document
redirect_from:
- /library/nt/integer_kth_root.hpp
- /library/nt/integer_kth_root.hpp.html
title: nt/integer_kth_root.hpp
---
