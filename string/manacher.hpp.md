---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/string/enumerate_palindromes.test.cpp
    title: test/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/manacher.hpp\"\n// \u6975\u5927\u56DE\u6587 [L, R)\
    \ \u3092\u5217\u6319\u3059\u308B\r\ntemplate <typename STRING>\r\nvc<pair<int,\
    \ int>> manacher(STRING s) {\r\n  int n = len(s);\r\n  assert(n > 0);\r\n  s.resize(2\
    \ * n - 1);\r\n  FOR_R(i, n) s[2 * i] = s[i];\r\n  FOR(i, n - 1) s[2 * i + 1]\
    \ = '~';\r\n  vector<int> dp(len(s));\r\n  int i = 0, j = 0;\r\n  while (i < len(s))\
    \ {\r\n    while (i - j >= 0 && i + j < len(s) && s[i - j] == s[i + j]) ++j;\r\
    \n    dp[i] = j;\r\n    int k = 1;\r\n    while (i - k >= 0 && i + k < len(s)\
    \ && k + dp[i - k] < j) {\r\n      dp[i + k] = dp[i - k];\r\n      ++k;\r\n  \
    \  }\r\n    i += k, j -= k;\r\n  }\r\n  FOR(i, len(dp)) if (!((i ^ dp[i]) & 1))--\
    \ dp[i];\r\n  vc<pair<int, int>> res;\r\n  res.reserve(len(dp));\r\n  FOR(i, len(dp))\
    \ {\r\n    if (dp[i] == 0) continue;\r\n    int l = (i - dp[i] + 1) / 2;\r\n \
    \   int r = (i + dp[i] + 1) / 2;\r\n    res.eb(l, r);\r\n  }\r\n  return res;\r\
    \n}\r\n"
  code: "// \u6975\u5927\u56DE\u6587 [L, R) \u3092\u5217\u6319\u3059\u308B\r\ntemplate\
    \ <typename STRING>\r\nvc<pair<int, int>> manacher(STRING s) {\r\n  int n = len(s);\r\
    \n  assert(n > 0);\r\n  s.resize(2 * n - 1);\r\n  FOR_R(i, n) s[2 * i] = s[i];\r\
    \n  FOR(i, n - 1) s[2 * i + 1] = '~';\r\n  vector<int> dp(len(s));\r\n  int i\
    \ = 0, j = 0;\r\n  while (i < len(s)) {\r\n    while (i - j >= 0 && i + j < len(s)\
    \ && s[i - j] == s[i + j]) ++j;\r\n    dp[i] = j;\r\n    int k = 1;\r\n    while\
    \ (i - k >= 0 && i + k < len(s) && k + dp[i - k] < j) {\r\n      dp[i + k] = dp[i\
    \ - k];\r\n      ++k;\r\n    }\r\n    i += k, j -= k;\r\n  }\r\n  FOR(i, len(dp))\
    \ if (!((i ^ dp[i]) & 1))-- dp[i];\r\n  vc<pair<int, int>> res;\r\n  res.reserve(len(dp));\r\
    \n  FOR(i, len(dp)) {\r\n    if (dp[i] == 0) continue;\r\n    int l = (i - dp[i]\
    \ + 1) / 2;\r\n    int r = (i + dp[i] + 1) / 2;\r\n    res.eb(l, r);\r\n  }\r\n\
    \  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2022-04-23 14:12:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: string/manacher.hpp
---
