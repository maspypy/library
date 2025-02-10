---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/st_numbering.hpp
    title: graph/st_numbering.hpp
  - icon: ':warning:'
    path: graph/tree_center.hpp
    title: graph/tree_center.hpp
  - icon: ':x:'
    path: graph/tree_diameter.hpp
    title: graph/tree_diameter.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/st_numbering.test.cpp
    title: test/1_mytest/st_numbering.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/shortest_path.test.cpp
    title: test/2_library_checker/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/st_numbering.test.cpp
    title: test/2_library_checker/graph/st_numbering.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/tree/tree_diameter.test.cpp
    title: test/2_library_checker/tree/tree_diameter.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest_path/restore_path.hpp\"\nvector<int> restore_path(vector<int>\
    \ par, int t){\r\n  vector<int> pth = {t};\r\n  while (par[pth.back()] != -1)\
    \ pth.eb(par[pth.back()]);\r\n  reverse(all(pth));\r\n  return pth;\r\n}\n"
  code: "vector<int> restore_path(vector<int> par, int t){\r\n  vector<int> pth =\
    \ {t};\r\n  while (par[pth.back()] != -1) pth.eb(par[pth.back()]);\r\n  reverse(all(pth));\r\
    \n  return pth;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/restore_path.hpp
  requiredBy:
  - graph/tree_center.hpp
  - graph/st_numbering.hpp
  - graph/tree_diameter.hpp
  timestamp: '2022-10-21 18:11:46+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/graph/shortest_path.test.cpp
  - test/2_library_checker/graph/st_numbering.test.cpp
  - test/2_library_checker/tree/tree_diameter.test.cpp
  - test/1_mytest/st_numbering.test.cpp
documentation_of: graph/shortest_path/restore_path.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/restore_path.hpp
- /library/graph/shortest_path/restore_path.hpp.html
title: graph/shortest_path/restore_path.hpp
---
