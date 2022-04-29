---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/tree_diameter.hpp
    title: graph/tree_diameter.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/shortest_path.test.cpp
    title: test/library_checker/graph/shortest_path.test.cpp
  - icon: ':x:'
    path: test/library_checker/tree/tree_diameter.test.cpp
    title: test/library_checker/tree/tree_diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  requiredBy:
  - graph/tree_diameter.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/graph/shortest_path.test.cpp
  - test/library_checker/tree/tree_diameter.test.cpp
documentation_of: graph/restore_path.hpp
layout: document
redirect_from:
- /library/graph/restore_path.hpp
- /library/graph/restore_path.hpp.html
title: graph/restore_path.hpp
---
