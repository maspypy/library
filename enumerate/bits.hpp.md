---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/bits.hpp\"\ntemplate <typename F>\nvoid enumerate_bits(int\
    \ s, F f) {\n  while (s) {\n    int i = __builtin_ctz(s);\n    f(i);\n    s ^=\
    \ 1 << i;\n  }\n}\n\ntemplate <typename BS, typename F>\nvoid enumerate_bits_bitset(BS&\
    \ b, int L, int R, F f) {\n  int p = (b[L] ? L : b._Find_next(L));\n  while (p\
    \ < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n"
  code: "template <typename F>\nvoid enumerate_bits(int s, F f) {\n  while (s) {\n\
    \    int i = __builtin_ctz(s);\n    f(i);\n    s ^= 1 << i;\n  }\n}\n\ntemplate\
    \ <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int R, F\
    \ f) {\n  int p = (b[L] ? L : b._Find_next(L));\n  while (p < R) {\n    f(p);\n\
    \    p = b._Find_next(p);\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/bits.hpp
  requiredBy: []
  timestamp: '2023-02-23 16:42:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/bits.hpp
layout: document
redirect_from:
- /library/enumerate/bits.hpp
- /library/enumerate/bits.hpp.html
title: enumerate/bits.hpp
---
