---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/zalgorithm.hpp
    title: string/zalgorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/is_substring.test.cpp
    title: test/mytest/is_substring.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/zalgorithm.hpp\"\ntemplate <typename STRING>  //\
    \ string, vector \u3069\u3061\u3089\u3067\u3082\nvector<int> zalgorithm(const\
    \ STRING& s) {\n  int n = int(s.size());\n  if (n == 0) return {};\n  vector<int>\
    \ z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0; i < n; i++) {\n    int& k = z[i];\n\
    \    k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);\n    while (i + k\
    \ < n && s[k] == s[i + k]) k++;\n    if (j + z[j] < i + z[i]) j = i;\n  }\n  z[0]\
    \ = n;\n  return z;\n}\n#line 2 \"string/is_substring.hpp\"\n\n// \u9023\u7D9A\
    \u90E8\u5206\u5217\u306B\u542B\u3080\u304B\u3069\u3046\u304B\u3002z-algo \u3067\
    \u7DDA\u5F62\u6642\u9593\ntemplate <typename STRING>\nbool is_substring(STRING&\
    \ S, STRING& T) {\n  int n = int(S.size()), m = int(T.size());\n  STRING ST;\n\
    \  for (auto&& x: S) ST.push_back(x);\n  for (auto&& x: T) ST.push_back(x);\n\
    \  auto Z = zalgorithm(ST);\n  for (int i = n; i < n + m; ++i) {\n    if (Z[i]\
    \ >= n) return true;\n  }\n  return false;\n}\n"
  code: "#include \"string/zalgorithm.hpp\"\n\n// \u9023\u7D9A\u90E8\u5206\u5217\u306B\
    \u542B\u3080\u304B\u3069\u3046\u304B\u3002z-algo \u3067\u7DDA\u5F62\u6642\u9593\
    \ntemplate <typename STRING>\nbool is_substring(STRING& S, STRING& T) {\n  int\
    \ n = int(S.size()), m = int(T.size());\n  STRING ST;\n  for (auto&& x: S) ST.push_back(x);\n\
    \  for (auto&& x: T) ST.push_back(x);\n  auto Z = zalgorithm(ST);\n  for (int\
    \ i = n; i < n + m; ++i) {\n    if (Z[i] >= n) return true;\n  }\n  return false;\n\
    }\n"
  dependsOn:
  - string/zalgorithm.hpp
  isVerificationFile: false
  path: string/is_substring.hpp
  requiredBy: []
  timestamp: '2022-10-12 08:06:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/is_substring.test.cpp
documentation_of: string/is_substring.hpp
layout: document
redirect_from:
- /library/string/is_substring.hpp
- /library/string/is_substring.hpp.html
title: string/is_substring.hpp
---
