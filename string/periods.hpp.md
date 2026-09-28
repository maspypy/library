---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/z_algorithm.hpp
    title: string/z_algorithm.hpp
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
    \ = n;\n  return z;\n}\n#line 2 \"string/periods.hpp\"\n\ntemplate <typename STRING>\n\
    vc<int> periods(const STRING& S, bool is_divisor) {\n  int N = len(S);\n  auto\
    \ Z = z_algorithm(S);\n  vc<int> res;\n  FOR(p, 1, N + 1) {\n    if (is_divisor\
    \ && (N % p != 0)) continue;\n    if (p == N || Z[p] == N - p) res.eb(p);\n  }\n\
    \  return res;\n}\n"
  code: "#include \"string/z_algorithm.hpp\"\n\ntemplate <typename STRING>\nvc<int>\
    \ periods(const STRING& S, bool is_divisor) {\n  int N = len(S);\n  auto Z = z_algorithm(S);\n\
    \  vc<int> res;\n  FOR(p, 1, N + 1) {\n    if (is_divisor && (N % p != 0)) continue;\n\
    \    if (p == N || Z[p] == N - p) res.eb(p);\n  }\n  return res;\n}"
  dependsOn:
  - string/z_algorithm.hpp
  isVerificationFile: false
  path: string/periods.hpp
  requiredBy: []
  timestamp: '2026-09-14 17:13:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/periods.hpp
layout: document
redirect_from:
- /library/string/periods.hpp
- /library/string/periods.hpp.html
title: string/periods.hpp
---
