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
  - icon: ':heavy_check_mark:'
    path: graph/tree_diameter.hpp
    title: graph/tree_diameter.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/shortest_path.test.cpp
    title: test/2_library_checker/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/st_numbering.test.cpp
    title: test/2_library_checker/graph/st_numbering.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/tree_diameter.test.cpp
    title: test/2_library_checker/tree/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/graph/shortest_path/restore_path.hpp
  bundledCode: "#line 1 \"graph/shortest_path/restore_path.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/shortest_path/restore_path.hpp\n\
    vector<int> restore_path(const vector<int>& par, int t) {\n  vector<int> pth =\
    \ {t};\n  while (par[pth.back()] != -1) pth.eb(par[pth.back()]);\n  reverse(all(pth));\n\
    \  return pth;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/graph/shortest_path/restore_path.hpp\n\
    vector<int> restore_path(const vector<int>& par, int t) {\n  vector<int> pth =\
    \ {t};\n  while (par[pth.back()] != -1) pth.eb(par[pth.back()]);\n  reverse(all(pth));\n\
    \  return pth;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/restore_path.hpp
  requiredBy:
  - graph/tree_diameter.hpp
  - graph/tree_center.hpp
  - graph/st_numbering.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/graph/st_numbering.test.cpp
  - test/2_library_checker/graph/shortest_path.test.cpp
  - test/2_library_checker/tree/tree_diameter.test.cpp
documentation_of: graph/shortest_path/restore_path.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/restore_path.hpp
- /library/graph/shortest_path/restore_path.hpp.html
title: graph/shortest_path/restore_path.hpp
---
