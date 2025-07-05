---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/kth_root_integer.test.cpp
    title: test/2_library_checker/number_theory/kth_root_integer.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1260.test.cpp
    title: test/3_yukicoder/1260.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1666.test.cpp
    title: test/3_yukicoder/1666.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/integer_kth_root.hpp\"\nu64 integer_kth_root(u64 k, u64\
    \ a) {\r\n  assert(k >= 1);\r\n  if (a == 0 || a == 1 || k == 1) return a;\r\n\
    \  if (k >= 64) return 1;\r\n  if (k == 2) return sqrtl(a);\r\n  if (a == u64(-1))\
    \ --a;\r\n  struct S {\r\n    u64 v;\r\n    S& operator*=(const S& o) {\r\n  \
    \    v = v <= u64(-1) / o.v ? v * o.v : u64(-1);\r\n      return *this;\r\n  \
    \  }\r\n  };\r\n  auto power = [&](S x, ll n) -> S {\r\n    S v{1};\r\n    while\
    \ (n) {\r\n      if (n & 1) v *= x;\r\n      x *= x;\r\n      n /= 2;\r\n    }\r\
    \n    return v;\r\n  };\r\n  u64 res = pow(a, nextafter(1 / double(k), 0));\r\n\
    \  while (power(S{res + 1}, k).v <= a) ++res;\r\n  return res;\r\n}\r\n"
  code: "u64 integer_kth_root(u64 k, u64 a) {\r\n  assert(k >= 1);\r\n  if (a == 0\
    \ || a == 1 || k == 1) return a;\r\n  if (k >= 64) return 1;\r\n  if (k == 2)\
    \ return sqrtl(a);\r\n  if (a == u64(-1)) --a;\r\n  struct S {\r\n    u64 v;\r\
    \n    S& operator*=(const S& o) {\r\n      v = v <= u64(-1) / o.v ? v * o.v :\
    \ u64(-1);\r\n      return *this;\r\n    }\r\n  };\r\n  auto power = [&](S x,\
    \ ll n) -> S {\r\n    S v{1};\r\n    while (n) {\r\n      if (n & 1) v *= x;\r\
    \n      x *= x;\r\n      n /= 2;\r\n    }\r\n    return v;\r\n  };\r\n  u64 res\
    \ = pow(a, nextafter(1 / double(k), 0));\r\n  while (power(S{res + 1}, k).v <=\
    \ a) ++res;\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/integer_kth_root.hpp
  requiredBy: []
  timestamp: '2023-11-07 17:48:08+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/number_theory/kth_root_integer.test.cpp
  - test/3_yukicoder/1666.test.cpp
  - test/3_yukicoder/1260.test.cpp
documentation_of: nt/integer_kth_root.hpp
layout: document
redirect_from:
- /library/nt/integer_kth_root.hpp
- /library/nt/integer_kth_root.hpp.html
title: nt/integer_kth_root.hpp
---
