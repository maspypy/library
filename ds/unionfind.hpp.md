---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: flow/bipartite.hpp
    title: flow/bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: graph/check_bipartite.hpp
    title: graph/check_bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dag_path_cover.hpp
    title: graph/dag_path_cover.hpp
  - icon: ':warning:'
    path: graph/functional.hpp
    title: graph/functional.hpp
  - icon: ':heavy_check_mark:'
    path: graph/maximum_antichain.hpp
    title: graph/maximum_antichain.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/online_unionfind.hpp
    title: graph/online_unionfind.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_dag_path_cover.test.cpp
    title: test/aoj/2251_dag_path_cover.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_maxantichain.test.cpp
    title: test/aoj/2251_maxantichain.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A_mst.test.cpp
    title: test/aoj/GRL_2_A_mst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/unionfind.test.cpp
    title: test/library_checker/datastructure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/bipartitematching.test.cpp
    title: test/library_checker/graph/bipartitematching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/114_steriner_tree.test.cpp
    title: test/yukicoder/114_steriner_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1170_online_uf.test.cpp
    title: test/yukicoder/1170_online_uf.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1479_bipartite_vertex_cover.test.cpp
    title: test/yukicoder/1479_bipartite_vertex_cover.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind.hpp\"\n\nstruct UnionFind {\n  int num;\n \
    \ int comp;\n  vc<int> size, par;\n  UnionFind(int n) : num(n), comp(n), size(n,\
    \ 1), par(n) {\n    iota(par.begin(), par.end(), 0);\n  }\n  int find(int x) {\n\
    \    while (par[x] != x) {\n      par[x] = par[par[x]];\n      x = par[x];\n \
    \   }\n    return x;\n  }\n\n  int operator[](int x) { return find(x); }\n\n \
    \ bool merge(ll x, ll y) {\n    x = find(x);\n    y = find(y);\n    if (x == y)\
    \ { return false; }\n    comp--;\n    if (size[x] < size[y]) swap(x, y);\n   \
    \ size[x] += size[y];\n    size[y] = 0;\n    par[y] = x;\n    return true;\n \
    \ }\n\n  vc<int> find_all() {\n    vc<int> A(num);\n    FOR(i, num) A[i] = find(i);\n\
    \    return A;\n  }\n\n  void reset(){\n    comp = num;\n    size.assign(num,\
    \ 1);\n    iota(all(par), 0);\n  }\n};\n"
  code: "#pragma once\n\nstruct UnionFind {\n  int num;\n  int comp;\n  vc<int> size,\
    \ par;\n  UnionFind(int n) : num(n), comp(n), size(n, 1), par(n) {\n    iota(par.begin(),\
    \ par.end(), 0);\n  }\n  int find(int x) {\n    while (par[x] != x) {\n      par[x]\
    \ = par[par[x]];\n      x = par[x];\n    }\n    return x;\n  }\n\n  int operator[](int\
    \ x) { return find(x); }\n\n  bool merge(ll x, ll y) {\n    x = find(x);\n   \
    \ y = find(y);\n    if (x == y) { return false; }\n    comp--;\n    if (size[x]\
    \ < size[y]) swap(x, y);\n    size[x] += size[y];\n    size[y] = 0;\n    par[y]\
    \ = x;\n    return true;\n  }\n\n  vc<int> find_all() {\n    vc<int> A(num);\n\
    \    FOR(i, num) A[i] = find(i);\n    return A;\n  }\n\n  void reset(){\n    comp\
    \ = num;\n    size.assign(num, 1);\n    iota(all(par), 0);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind.hpp
  requiredBy:
  - graph/online_unionfind.hpp
  - graph/check_bipartite.hpp
  - graph/functional.hpp
  - graph/minimum_spanning_tree.hpp
  - graph/dag_path_cover.hpp
  - graph/maximum_antichain.hpp
  - flow/bipartite.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/114_steriner_tree.test.cpp
  - test/yukicoder/1479_bipartite_vertex_cover.test.cpp
  - test/yukicoder/1170_online_uf.test.cpp
  - test/library_checker/datastructure/unionfind.test.cpp
  - test/library_checker/graph/bipartitematching.test.cpp
  - test/aoj/2251_dag_path_cover.test.cpp
  - test/aoj/2251_maxantichain.test.cpp
  - test/aoj/GRL_2_A_mst.test.cpp
documentation_of: ds/unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind.hpp
- /library/ds/unionfind.hpp.html
title: ds/unionfind.hpp
---
