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
  bundledCode: "#line 1 \"string/z_algorithm.hpp\"\n\ntemplate <typename STRING> \
    \ // string, vector \u3069\u3061\u3089\u3067\u3082\nvector<int> z_algorithm(const\
    \ STRING& s) {\n  int n = int(s.size());\n  if (n == 0) return {};\n  vector<int>\
    \ z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0; i < n; i++) {\n    int& k = z[i];\n\
    \    k = (j + z[j] <= i) ? 0 : min(j + z[j] - i, z[i - j]);\n    while (i + k\
    \ < n && s[k] == s[i + k]) k++;\n    if (j + z[j] < i + z[i]) j = i;\n  }\n  z[0]\
    \ = n;\n  return z;\n}\n"
  code: "\ntemplate <typename STRING>  // string, vector \u3069\u3061\u3089\u3067\u3082\
    \nvector<int> z_algorithm(const STRING& s) {\n  int n = int(s.size());\n  if (n\
    \ == 0) return {};\n  vector<int> z(n);\n  z[0] = 0;\n  for (int i = 1, j = 0;\
    \ i < n; i++) {\n    int& k = z[i];\n    k = (j + z[j] <= i) ? 0 : min(j + z[j]\
    \ - i, z[i - j]);\n    while (i + k < n && s[k] == s[i + k]) k++;\n    if (j +\
    \ z[j] < i + z[i]) j = i;\n  }\n  z[0] = n;\n  return z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z_algorithm.hpp
  requiredBy: []
  timestamp: '2026-08-17 08:30:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/z_algorithm.hpp
layout: document
redirect_from:
- /library/string/z_algorithm.hpp
- /library/string/z_algorithm.hpp.html
title: string/z_algorithm.hpp
---
