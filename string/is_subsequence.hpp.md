---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1643.test.cpp
    title: test/3_yukicoder/1643.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/is_subsequence.hpp\"\ntemplate <typename STRING>\r\
    \nbool is_subsequence(STRING& S, STRING& T) {\r\n  ll p = 0;\r\n  for (auto&&\
    \ s : S) {\r\n    while (p < len(T) && T[p] != s) ++p;\r\n    if (p == len(T))\
    \ return false;\r\n    ++p;\r\n  }\r\n  return true;\r\n}\n"
  code: "template <typename STRING>\r\nbool is_subsequence(STRING& S, STRING& T) {\r\
    \n  ll p = 0;\r\n  for (auto&& s : S) {\r\n    while (p < len(T) && T[p] != s)\
    \ ++p;\r\n    if (p == len(T)) return false;\r\n    ++p;\r\n  }\r\n  return true;\r\
    \n}"
  dependsOn: []
  isVerificationFile: false
  path: string/is_subsequence.hpp
  requiredBy: []
  timestamp: '2026-08-17 12:32:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1643.test.cpp
documentation_of: string/is_subsequence.hpp
layout: document
redirect_from:
- /library/string/is_subsequence.hpp
- /library/string/is_subsequence.hpp.html
title: string/is_subsequence.hpp
---
