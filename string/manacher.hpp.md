---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/enumerate_palindromes.test.cpp
    title: test/2_library_checker/string/enumerate_palindromes.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2858.test.cpp
    title: test/3_yukicoder/2858.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_c
    - https://github.com/maspypy/library/blob/main/string/manacher.hpp
  bundledCode: "#line 1 \"string/manacher.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/string/manacher.hpp\n\
    \n// i<=j \u306B\u5BFE\u3057\u3066 match(i,j) \u304C\u5B9A\u7FA9\u3055\u308C\u3066\
    \u3044\u308B\u3068\u304D\u6975\u5927\u56DE\u6587 [L,R) \u3092\u5217\u6319\u3059\
    \u308B\n// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_c\n\
    template <typename F>\nvc<pair<int, int>> manacher(int n, F match) {\n  if (n\
    \ == 0) return {};\n  assert(n > 0);\n  auto f = [&](int i, int j) -> bool {\n\
    \    if (i > j) return 0;\n    assert((i + j) % 2 == 0);\n    if (i & 1) return\
    \ 1;\n    return match(i / 2, j / 2);\n  };\n  vector<int> dp(2 * n - 1);\n  int\
    \ i = 0, j = 0;\n  while (i < 2 * n - 1) {\n    while (i - j >= 0 && i + j < 2\
    \ * n - 1 && f(i - j, i + j)) ++j;\n    dp[i] = j;\n    int k = 1;\n    while\
    \ (i - k >= 0 && i + k < 2 * n - 1 && k < j && dp[i - k] != j - k) {\n      dp[i\
    \ + k] = min(j - k, dp[i - k]), ++k;\n    }\n    i += k, j = max(j - k, 0);\n\
    \  }\n  vc<pair<int, int>> res;\n  FOR(i, len(dp)) {\n    if (dp[i] == 0) continue;\n\
    \    int l = ceil<int>(i - dp[i] + 1, 2);\n    int r = floor<int>(i + dp[i] -\
    \ 1, 2);\n    if (l <= r) res.eb(l, r + 1);\n  }\n  return res;\n}\n\n// \u6975\
    \u5927\u56DE\u6587 [L, R) \u3092\u5217\u6319\u3059\u308B\ntemplate <typename STRING>\n\
    vc<pair<int, int>> manacher(STRING s) {\n  int n = len(s);\n  if (n == 0) return\
    \ {};\n  return manacher(n, [&](int i, int j) -> bool { return s[i] == s[j]; });\n\
    }\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/string/manacher.hpp\n\
    \n// i<=j \u306B\u5BFE\u3057\u3066 match(i,j) \u304C\u5B9A\u7FA9\u3055\u308C\u3066\
    \u3044\u308B\u3068\u304D\u6975\u5927\u56DE\u6587 [L,R) \u3092\u5217\u6319\u3059\
    \u308B\n// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_c\n\
    template <typename F>\nvc<pair<int, int>> manacher(int n, F match) {\n  if (n\
    \ == 0) return {};\n  assert(n > 0);\n  auto f = [&](int i, int j) -> bool {\n\
    \    if (i > j) return 0;\n    assert((i + j) % 2 == 0);\n    if (i & 1) return\
    \ 1;\n    return match(i / 2, j / 2);\n  };\n  vector<int> dp(2 * n - 1);\n  int\
    \ i = 0, j = 0;\n  while (i < 2 * n - 1) {\n    while (i - j >= 0 && i + j < 2\
    \ * n - 1 && f(i - j, i + j)) ++j;\n    dp[i] = j;\n    int k = 1;\n    while\
    \ (i - k >= 0 && i + k < 2 * n - 1 && k < j && dp[i - k] != j - k) {\n      dp[i\
    \ + k] = min(j - k, dp[i - k]), ++k;\n    }\n    i += k, j = max(j - k, 0);\n\
    \  }\n  vc<pair<int, int>> res;\n  FOR(i, len(dp)) {\n    if (dp[i] == 0) continue;\n\
    \    int l = ceil<int>(i - dp[i] + 1, 2);\n    int r = floor<int>(i + dp[i] -\
    \ 1, 2);\n    if (l <= r) res.eb(l, r + 1);\n  }\n  return res;\n}\n\n// \u6975\
    \u5927\u56DE\u6587 [L, R) \u3092\u5217\u6319\u3059\u308B\ntemplate <typename STRING>\n\
    vc<pair<int, int>> manacher(STRING s) {\n  int n = len(s);\n  if (n == 0) return\
    \ {};\n  return manacher(n, [&](int i, int j) -> bool { return s[i] == s[j]; });\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: string/manacher.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2858.test.cpp
  - test/2_library_checker/string/enumerate_palindromes.test.cpp
documentation_of: string/manacher.hpp
layout: document
redirect_from:
- /library/string/manacher.hpp
- /library/string/manacher.hpp.html
title: string/manacher.hpp
---
