---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/string/enumerate_palindromes.test.cpp
    title: test/2_library_checker/string/enumerate_palindromes.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2858.test.cpp
    title: test/3_yukicoder/2858.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_c
  bundledCode: "#line 1 \"string/manacher.hpp\"\n\r\n// i<=j \u306B\u5BFE\u3057\u3066\
    \ match(i,j) \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B\u3068\u304D\u6975\
    \u5927\u56DE\u6587 [L,R) \u3092\u5217\u6319\u3059\u308B\r\n// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_c\r\
    \ntemplate <typename F>\r\nvc<pair<int, int>> manacher(int n, F match) {\r\n \
    \ assert(n > 0);\r\n  auto f = [&](int i, int j) -> bool {\r\n    if (i > j) return\
    \ 0;\r\n    assert((i + j) % 2 == 0);\r\n    if (i & 1) return 1;\r\n    return\
    \ match(i / 2, j / 2);\r\n  };\r\n  vector<int> dp(2 * n - 1);\r\n  int i = 0,\
    \ j = 0;\r\n  while (i < 2 * n - 1) {\r\n    while (i - j >= 0 && i + j < 2 *\
    \ n - 1 && f(i - j, i + j)) ++j;\r\n    dp[i] = j;\r\n    int k = 1;\r\n    while\
    \ (i - k >= 0 && i + k < 2 * n - 1 && k < j && dp[i - k] != j - k) { dp[i + k]\
    \ = min(j - k, dp[i - k]), ++k; }\r\n    i += k, j = max(j - k, 0);\r\n  }\r\n\
    \  vc<pair<int, int>> res;\r\n  FOR(i, len(dp)) {\r\n    if (dp[i] == 0) continue;\r\
    \n    int l = ceil<int>(i - dp[i] + 1, 2);\r\n    int r = floor<int>(i + dp[i]\
    \ - 1, 2);\r\n    if (l <= r) res.eb(l, r + 1);\r\n  }\r\n  return res;\r\n}\r\
    \n\r\n// \u6975\u5927\u56DE\u6587 [L, R) \u3092\u5217\u6319\u3059\u308B\r\ntemplate\
    \ <typename STRING>\r\nvc<pair<int, int>> manacher(STRING s) {\r\n  int n = len(s);\r\
    \n  assert(n > 0);\r\n  return manacher(n, [&](int i, int j) -> bool { return\
    \ s[i] == s[j]; });\r\n}\r\n"
  code: "\r\n// i<=j \u306B\u5BFE\u3057\u3066 match(i,j) \u304C\u5B9A\u7FA9\u3055\u308C\
    \u3066\u3044\u308B\u3068\u304D\u6975\u5927\u56DE\u6587 [L,R) \u3092\u5217\u6319\
    \u3059\u308B\r\n// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_c\r\
    \ntemplate <typename F>\r\nvc<pair<int, int>> manacher(int n, F match) {\r\n \
    \ assert(n > 0);\r\n  auto f = [&](int i, int j) -> bool {\r\n    if (i > j) return\
    \ 0;\r\n    assert((i + j) % 2 == 0);\r\n    if (i & 1) return 1;\r\n    return\
    \ match(i / 2, j / 2);\r\n  };\r\n  vector<int> dp(2 * n - 1);\r\n  int i = 0,\
    \ j = 0;\r\n  while (i < 2 * n - 1) {\r\n    while (i - j >= 0 && i + j < 2 *\
    \ n - 1 && f(i - j, i + j)) ++j;\r\n    dp[i] = j;\r\n    int k = 1;\r\n    while\
    \ (i - k >= 0 && i + k < 2 * n - 1 && k < j && dp[i - k] != j - k) { dp[i + k]\
    \ = min(j - k, dp[i - k]), ++k; }\r\n    i += k, j = max(j - k, 0);\r\n  }\r\n\
    \  vc<pair<int, int>> res;\r\n  FOR(i, len(dp)) {\r\n    if (dp[i] == 0) continue;\r\
    \n    int l = ceil<int>(i - dp[i] + 1, 2);\r\n    int r = floor<int>(i + dp[i]\
    \ - 1, 2);\r\n    if (l <= r) res.eb(l, r + 1);\r\n  }\r\n  return res;\r\n}\r\
    \n\r\n// \u6975\u5927\u56DE\u6587 [L, R) \u3092\u5217\u6319\u3059\u308B\r\ntemplate\
    \ <typename STRING>\r\nvc<pair<int, int>> manacher(STRING s) {\r\n  int n = len(s);\r\
    \n  assert(n > 0);\r\n  return manacher(n, [&](int i, int j) -> bool { return\
    \ s[i] == s[j]; });\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2024-09-05 12:30:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/string/enumerate_palindromes.test.cpp
  - test/3_yukicoder/2858.test.cpp
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: string/manacher.hpp
---
