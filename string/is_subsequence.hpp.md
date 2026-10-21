---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/1643.test.cpp
    title: test/3_yukicoder/1643.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/string/is_subsequence.hpp
  bundledCode: "#line 1 \"string/is_subsequence.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/string/is_subsequence.hpp\n\
    template <typename STRING>\nbool is_subsequence(const STRING& S, const STRING&\
    \ T) {\n  ll p = 0;\n  for (auto&& s : S) {\n    while (p < len(T) && T[p] !=\
    \ s) ++p;\n    if (p == len(T)) return false;\n    ++p;\n  }\n  return true;\n\
    }\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/string/is_subsequence.hpp\n\
    template <typename STRING>\nbool is_subsequence(const STRING& S, const STRING&\
    \ T) {\n  ll p = 0;\n  for (auto&& s : S) {\n    while (p < len(T) && T[p] !=\
    \ s) ++p;\n    if (p == len(T)) return false;\n    ++p;\n  }\n  return true;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: string/is_subsequence.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1643.test.cpp
documentation_of: string/is_subsequence.hpp
layout: document
redirect_from:
- /library/string/is_subsequence.hpp
- /library/string/is_subsequence.hpp.html
title: string/is_subsequence.hpp
---
