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
  bundledCode: "#line 1 \"graph/restore_path.hpp\"\nvector<int> restore_path(vector<int>\
    \ par, int t){\r\n  vector<int> pth = {t};\r\n  while (par[pth.back()] != -1)\
    \ pth.eb(par[pth.back()]);\r\n  reverse(all(pth));\r\n  return pth;\r\n}\n"
  code: "vector<int> restore_path(vector<int> par, int t){\r\n  vector<int> pth =\
    \ {t};\r\n  while (par[pth.back()] != -1) pth.eb(par[pth.back()]);\r\n  reverse(all(pth));\r\
    \n  return pth;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/restore_path.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/restore_path.hpp
layout: document
redirect_from:
- /library/graph/restore_path.hpp
- /library/graph/restore_path.hpp.html
title: graph/restore_path.hpp
---
