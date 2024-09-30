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
  bundledCode: "#line 1 \"seq/famous/de_bruijn.hpp\"\nstring de_bruijn(int n) {\n\
    \  vc<int> a(2 * n, 0);\n  string ANS;\n  auto dfs = [&](auto& dfs, int t, int\
    \ p) -> void {\n    if (t > n) {\n      if (n % p == 0) {\n        FOR(j, 1, p\
    \ + 1) { ANS += '0' + a[j]; }\n      }\n      return;\n    }\n    a[t] = a[t -\
    \ p];\n    dfs(dfs, t + 1, p);\n    FOR(j, a[t - p] + 1, 2) {\n      a[t] = j;\n\
    \      dfs(dfs, t + 1, t);\n    }\n  };\n  dfs(dfs, 1, 1);\n  return ANS;\n}\n"
  code: "string de_bruijn(int n) {\n  vc<int> a(2 * n, 0);\n  string ANS;\n  auto\
    \ dfs = [&](auto& dfs, int t, int p) -> void {\n    if (t > n) {\n      if (n\
    \ % p == 0) {\n        FOR(j, 1, p + 1) { ANS += '0' + a[j]; }\n      }\n    \
    \  return;\n    }\n    a[t] = a[t - p];\n    dfs(dfs, t + 1, p);\n    FOR(j, a[t\
    \ - p] + 1, 2) {\n      a[t] = j;\n      dfs(dfs, t + 1, t);\n    }\n  };\n  dfs(dfs,\
    \ 1, 1);\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/de_bruijn.hpp
  requiredBy: []
  timestamp: '2024-09-30 22:44:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/famous/de_bruijn.hpp
layout: document
redirect_from:
- /library/seq/famous/de_bruijn.hpp
- /library/seq/famous/de_bruijn.hpp.html
title: seq/famous/de_bruijn.hpp
---
