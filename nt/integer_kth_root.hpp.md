---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/kth_root_integer.test.cpp
    title: test/library_checker/math/kth_root_integer.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1260.test.cpp
    title: test/yukicoder/1260.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1666.test.cpp
    title: test/yukicoder/1666.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/integer_kth_root.hpp\"\nuint64_t integer_kth_root(uint64_t\
    \ k, uint64_t a) {\r\n  assert(k >= 1);\r\n  if (a == 0 || a == 1 || k == 1) return\
    \ a;\r\n  if (k >= 64) return 1;\r\n  if (k == 2) return sqrtl(a);\r\n  if (a\
    \ == uint64_t(-1)) --a;\r\n  struct S {\r\n    uint64_t v;\r\n    S& operator*=(const\
    \ S& o) {\r\n      v = v <= uint64_t(-1) / o.v ? v * o.v : uint64_t(-1);\r\n \
    \     return *this;\r\n    }\r\n  };\r\n  auto power = [&](S x, ll n) -> S {\r\
    \n    S v{1};\r\n    while (n) {\r\n      if (n & 1) v *= x;\r\n      x *= x;\r\
    \n      n /= 2;\r\n    }\r\n    return v;\r\n  };\r\n  uint64_t res = pow(a, nextafter(1\
    \ / double(k), 0));\r\n  while (power(S{res + 1}, k).v <= a) ++res;\r\n  return\
    \ res;\r\n}\r\n"
  code: "uint64_t integer_kth_root(uint64_t k, uint64_t a) {\r\n  assert(k >= 1);\r\
    \n  if (a == 0 || a == 1 || k == 1) return a;\r\n  if (k >= 64) return 1;\r\n\
    \  if (k == 2) return sqrtl(a);\r\n  if (a == uint64_t(-1)) --a;\r\n  struct S\
    \ {\r\n    uint64_t v;\r\n    S& operator*=(const S& o) {\r\n      v = v <= uint64_t(-1)\
    \ / o.v ? v * o.v : uint64_t(-1);\r\n      return *this;\r\n    }\r\n  };\r\n\
    \  auto power = [&](S x, ll n) -> S {\r\n    S v{1};\r\n    while (n) {\r\n  \
    \    if (n & 1) v *= x;\r\n      x *= x;\r\n      n /= 2;\r\n    }\r\n    return\
    \ v;\r\n  };\r\n  uint64_t res = pow(a, nextafter(1 / double(k), 0));\r\n  while\
    \ (power(S{res + 1}, k).v <= a) ++res;\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/integer_kth_root.hpp
  requiredBy: []
  timestamp: '2022-12-23 11:04:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1260.test.cpp
  - test/yukicoder/1666.test.cpp
  - test/library_checker/math/kth_root_integer.test.cpp
documentation_of: nt/integer_kth_root.hpp
layout: document
redirect_from:
- /library/nt/integer_kth_root.hpp
- /library/nt/integer_kth_root.hpp.html
title: nt/integer_kth_root.hpp
---
