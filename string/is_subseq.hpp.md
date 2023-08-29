---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1643.test.cpp
    title: test/yukicoder/1643.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/is_subseq.hpp\"\ntemplate <typename STRING>\r\nbool\
    \ is_subseq(STRING& S, STRING& T) {\r\n  ll p = 0;\r\n  for (auto&& s: S) {\r\n\
    \    while (p < len(T) && T[p] != s) ++p;\r\n    if (p == len(T)) return false;\r\
    \n    ++p;\r\n  }\r\n  return true;\r\n}\n"
  code: "template <typename STRING>\r\nbool is_subseq(STRING& S, STRING& T) {\r\n\
    \  ll p = 0;\r\n  for (auto&& s: S) {\r\n    while (p < len(T) && T[p] != s) ++p;\r\
    \n    if (p == len(T)) return false;\r\n    ++p;\r\n  }\r\n  return true;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/is_subseq.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1643.test.cpp
documentation_of: string/is_subseq.hpp
layout: document
redirect_from:
- /library/string/is_subseq.hpp
- /library/string/is_subseq.hpp.html
title: string/is_subseq.hpp
---
