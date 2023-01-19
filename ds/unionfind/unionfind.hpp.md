---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: flow/bipartite.hpp
    title: flow/bipartite.hpp
  - icon: ':x:'
    path: geo/manhattan_mst.hpp
    title: geo/manhattan_mst.hpp
  - icon: ':x:'
    path: graph/bipartite_edge_coloring.hpp
    title: graph/bipartite_edge_coloring.hpp
  - icon: ':question:'
    path: graph/check_bipartite.hpp
    title: graph/check_bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dag_path_cover.hpp
    title: graph/dag_path_cover.hpp
  - icon: ':x:'
    path: graph/functional.hpp
    title: graph/functional.hpp
  - icon: ':heavy_check_mark:'
    path: graph/maximum_antichain.hpp
    title: graph/maximum_antichain.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  - icon: ':warning:'
    path: graph/online_mst.hpp
    title: graph/online_mst.hpp
  - icon: ':x:'
    path: graph/online_unionfind.hpp
    title: graph/online_unionfind.hpp
  - icon: ':x:'
    path: graph/tree_of_unionfind.hpp
    title: graph/tree_of_unionfind.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1566.test.cpp
    title: test/aoj/1566.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_1.test.cpp
    title: test/aoj/2251_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_2.test.cpp
    title: test/aoj/2251_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2995.test.cpp
    title: test/aoj/2995.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc270_f.test.cpp
    title: test/atcoder/abc270_f.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/unionfind.test.cpp
    title: test/library_checker/datastructure/unionfind.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/bipartite_edge_coloring.test.cpp
    title: test/library_checker/graph/bipartite_edge_coloring.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/bipartitematching.test.cpp
    title: test/library_checker/graph/bipartitematching.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/manhattan_mst.test.cpp
    title: test/library_checker/graph/manhattan_mst.test.cpp
  - icon: ':x:'
    path: test/mytest/tutte.test.cpp
    title: test/mytest/tutte.test.cpp
  - icon: ':x:'
    path: test/yukicoder/114.test.cpp
    title: test/yukicoder/114.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1170_2.test.cpp
    title: test/yukicoder/1170_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1211.test.cpp
    title: test/yukicoder/1211.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1242.test.cpp
    title: test/yukicoder/1242.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1392.test.cpp
    title: test/yukicoder/1392.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1451.test.cpp
    title: test/yukicoder/1451.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1479.test.cpp
    title: test/yukicoder/1479.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1600.test.cpp
    title: test/yukicoder/1600.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1744.test.cpp
    title: test/yukicoder/1744.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1745.test.cpp
    title: test/yukicoder/1745.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1911.test.cpp
    title: test/yukicoder/1911.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1983.test.cpp
    title: test/yukicoder/1983.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2122.test.cpp
    title: test/yukicoder/2122.test.cpp
  - icon: ':x:'
    path: test/yukicoder/590.test.cpp
    title: test/yukicoder/590.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  int operator[](int x) {\n    while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n\
    \      if (pp < 0) { return dat[x]; }\n      x = dat[x] = pp;\n    }\n    return\
    \ x;\n  }\n\n  ll size(int x) {\n    assert(dat[x] < 0);\n    return -dat[x];\n\
    \  }\n\n  bool merge(int x, int y) {\n    x = (*this)[x], y = (*this)[y];\n  \
    \  if (x == y) return false;\n    if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x]\
    \ += dat[y], dat[y] = x, n_comp--;\n    return true;\n  }\n};\n"
  code: "#pragma once\n\nstruct UnionFind {\n  int n, n_comp;\n  vc<int> dat; // par\
    \ or (-size)\n  UnionFind(int n = 0) { build(n); }\n\n  void build(int m) {\n\
    \    n = m, n_comp = m;\n    dat.assign(n, -1);\n  }\n\n  int operator[](int x)\
    \ {\n    while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0)\
    \ { return dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll\
    \ size(int x) {\n    assert(dat[x] < 0);\n    return -dat[x];\n  }\n\n  bool merge(int\
    \ x, int y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n\
    \    if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind/unionfind.hpp
  requiredBy:
  - graph/functional.hpp
  - graph/check_bipartite.hpp
  - graph/minimum_spanning_tree.hpp
  - graph/dag_path_cover.hpp
  - graph/online_unionfind.hpp
  - graph/maximum_antichain.hpp
  - graph/bipartite_edge_coloring.hpp
  - graph/tree_of_unionfind.hpp
  - graph/online_mst.hpp
  - geo/manhattan_mst.hpp
  - flow/bipartite.hpp
  timestamp: '2022-12-23 10:56:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/2995.test.cpp
  - test/aoj/2251_1.test.cpp
  - test/aoj/1566.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/2251_2.test.cpp
  - test/yukicoder/1479.test.cpp
  - test/yukicoder/1600.test.cpp
  - test/yukicoder/1170_2.test.cpp
  - test/yukicoder/1392.test.cpp
  - test/yukicoder/1242.test.cpp
  - test/yukicoder/1983.test.cpp
  - test/yukicoder/1303.test.cpp
  - test/yukicoder/1744.test.cpp
  - test/yukicoder/1911.test.cpp
  - test/yukicoder/1451.test.cpp
  - test/yukicoder/2122.test.cpp
  - test/yukicoder/1211.test.cpp
  - test/yukicoder/114.test.cpp
  - test/yukicoder/590.test.cpp
  - test/yukicoder/1745.test.cpp
  - test/library_checker/graph/manhattan_mst.test.cpp
  - test/library_checker/graph/bipartite_edge_coloring.test.cpp
  - test/library_checker/graph/bipartitematching.test.cpp
  - test/library_checker/datastructure/unionfind.test.cpp
  - test/mytest/tutte.test.cpp
  - test/atcoder/abc270_f.test.cpp
documentation_of: ds/unionfind/unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/unionfind.hpp
- /library/ds/unionfind/unionfind.hpp.html
title: ds/unionfind/unionfind.hpp
---
