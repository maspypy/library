---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/zalgorithm.hpp
    title: string/zalgorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \u7DDA\u5F62\u6642\u9593\ntemplate <typename STRING>\nbool is_substring(STRING\
    \ S, STRING T) {\n  int n = len(S), m = len(T);\n  S += T;\n  auto Z = zalgorithm(S);\n\
    \  FOR3(i, n, n + m) {\n    if (Z[i] >= n) return true;\n  }\n  return false;\n\
    }\n"
  code: "#include \"string/zalgorithm.hpp\"\n\n// \u9023\u7D9A\u90E8\u5206\u5217\u306B\
    \u542B\u3080\u304B\u3069\u3046\u304B\u3002z-algo \u3067\u7DDA\u5F62\u6642\u9593\
    \ntemplate <typename STRING>\nbool is_substring(STRING S, STRING T) {\n  int n\
    \ = len(S), m = len(T);\n  S += T;\n  auto Z = zalgorithm(S);\n  FOR3(i, n, n\
    \ + m) {\n    if (Z[i] >= n) return true;\n  }\n  return false;\n}"
  dependsOn:
  - string/zalgorithm.hpp
  isVerificationFile: false
  path: string/is_substring.hpp
  requiredBy: []
  timestamp: '2022-05-01 01:11:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/is_substring.hpp
layout: document
redirect_from:
- /library/string/is_substring.hpp
- /library/string/is_substring.hpp.html
title: string/is_substring.hpp
---
