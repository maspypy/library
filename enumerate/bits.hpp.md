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
  bundledCode: "#line 1 \"enumerate/bits.hpp\"\ntemplate <typename BS, typename F>\n\
    void enumerate_bits(BS& b, int L, int R, F f) {\n  int p = (b[L] ? L : b._Find_next(L));\n\
    \  while (p < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n"
  code: "template <typename BS, typename F>\nvoid enumerate_bits(BS& b, int L, int\
    \ R, F f) {\n  int p = (b[L] ? L : b._Find_next(L));\n  while (p < R) {\n    f(p);\n\
    \    p = b._Find_next(p);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/bits.hpp
  requiredBy: []
  timestamp: '2023-02-16 20:24:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: enumerate/bits.hpp
layout: document
redirect_from:
- /library/enumerate/bits.hpp
- /library/enumerate/bits.hpp.html
title: enumerate/bits.hpp
---
