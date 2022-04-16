---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/enumerate_palindromes.test.cpp
    title: test/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/manacher.hpp\"\ntemplate <bool CALC_ALL, typename\
    \ STRING>\r\nvector<int> longest_palindrome(STRING s) {\r\n  if (CALC_ALL) {\r\
    \n    int n = len(s);\r\n    assert(n > 0);\r\n    s.resize(2 * n - 1);\r\n  \
    \  FOR_R(i, n) s[2 * i] = s[i];\r\n    FOR(i, n - 1) s[2 * i + 1] = '-';\r\n \
    \ }\r\n  vector<int> A(len(s));\r\n  int i = 0, j = 0;\r\n  while (i < len(s))\
    \ {\r\n    while (i - j >= 0 && i + j < len(s) && s[i - j] == s[i + j]) ++j;\r\
    \n    A[i] = j;\r\n    int k = 1;\r\n    while (i - k >= 0 && i + k < len(s) &&\
    \ k + A[i - k] < j) {\r\n      A[i + k] = A[i - k];\r\n      ++k;\r\n    }\r\n\
    \    i += k, j -= k;\r\n  }\r\n  if (CALC_ALL) {\r\n    FOR(i, len(A)) {\r\n \
    \     if (!((i ^ A[i]) & 1)) A[i]--;\r\n    }\r\n  } else {\r\n    for (auto&&\
    \ x: A) x = 2 * x - 1;\r\n  }\r\n  return A;\r\n}\r\n"
  code: "template <bool CALC_ALL, typename STRING>\r\nvector<int> longest_palindrome(STRING\
    \ s) {\r\n  if (CALC_ALL) {\r\n    int n = len(s);\r\n    assert(n > 0);\r\n \
    \   s.resize(2 * n - 1);\r\n    FOR_R(i, n) s[2 * i] = s[i];\r\n    FOR(i, n -\
    \ 1) s[2 * i + 1] = '-';\r\n  }\r\n  vector<int> A(len(s));\r\n  int i = 0, j\
    \ = 0;\r\n  while (i < len(s)) {\r\n    while (i - j >= 0 && i + j < len(s) &&\
    \ s[i - j] == s[i + j]) ++j;\r\n    A[i] = j;\r\n    int k = 1;\r\n    while (i\
    \ - k >= 0 && i + k < len(s) && k + A[i - k] < j) {\r\n      A[i + k] = A[i -\
    \ k];\r\n      ++k;\r\n    }\r\n    i += k, j -= k;\r\n  }\r\n  if (CALC_ALL)\
    \ {\r\n    FOR(i, len(A)) {\r\n      if (!((i ^ A[i]) & 1)) A[i]--;\r\n    }\r\
    \n  } else {\r\n    for (auto&& x: A) x = 2 * x - 1;\r\n  }\r\n  return A;\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: string/manacher.hpp
---
