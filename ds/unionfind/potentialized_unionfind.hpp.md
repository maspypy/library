---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/unionfind_with_potential_group.test.cpp
    title: test/2_library_checker/data_structure/unionfind_with_potential_group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/unionfind_with_potential.test.cpp
    title: test/2_library_checker/unionfind_with_potential.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1502.test.cpp
    title: test/3_yukicoder/1502.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2294.test.cpp
    title: test/3_yukicoder/2294.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/DSL_1_B.test.cpp
    title: test/4_aoj/DSL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/unionfind/potentialized_unionfind.hpp\"\ntemplate <typename\
    \ Group>\r\nstruct Potentialized_UnionFind {\r\n  using E = typename Group::value_type;\r\
    \n  int N;\r\n  int n_comp;\r\n  vc<E> vals;\r\n  vc<int> par;\r\n  vc<int> size;\r\
    \n\r\n  Potentialized_UnionFind(int N) : N(N), n_comp(N), vals(N, Group::unit()),\
    \ size(N, 1) {\r\n    par.resize(N);\r\n    iota(all(par), 0);\r\n  }\r\n\r\n\
    \  // (root, P[root]^{-1}P[v])\r\n  pair<int, E> get(int v) {\r\n    E res = Group::unit();\r\
    \n    while (v != par[v]) {\r\n      res = Group::op(vals[v], res);\r\n      res\
    \ = Group::op(vals[par[v]], res);\r\n      vals[v] = Group::op(vals[par[v]], vals[v]);\r\
    \n      v = par[v] = par[par[v]];\r\n    }\r\n    return {v, res};\r\n  }\r\n\r\
    \n  pair<int, E> operator[](int v) { return get(v); }\r\n\r\n  // is_same / path\
    \ value\r\n  pair<bool, E> get_path(int u, int v) {\r\n    auto [ru, xu] = get(u);\r\
    \n    auto [rv, xv] = get(v);\r\n    if (ru != rv) return {false, Group::unit()};\r\
    \n    return {true, Group::op(Group::inverse(xu), xv)};\r\n  }\r\n\r\n  // if\
    \ same : do nothing.\r\n  // P[to]==P[frm]x\r\n  bool merge(int frm, int to, E\
    \ x) {\r\n    auto [v1, x1] = get(frm);\r\n    auto [v2, x2] = get(to);\r\n  \
    \  if (v1 == v2) return false; // same\r\n    if (size[v1] < size[v2]) {\r\n \
    \     swap(v1, v2);\r\n      swap(x1, x2);\r\n      x = Group::inverse(x);\r\n\
    \    }\r\n    x = Group::op(x1, x);\r\n    x = Group::op(x, Group::inverse(x2));\r\
    \n    vals[v2] = x;\r\n    par[v2] = v1;\r\n    size[v1] += size[v2];\r\n    --n_comp;\r\
    \n    return true;\r\n  }\r\n};\n"
  code: "template <typename Group>\r\nstruct Potentialized_UnionFind {\r\n  using\
    \ E = typename Group::value_type;\r\n  int N;\r\n  int n_comp;\r\n  vc<E> vals;\r\
    \n  vc<int> par;\r\n  vc<int> size;\r\n\r\n  Potentialized_UnionFind(int N) :\
    \ N(N), n_comp(N), vals(N, Group::unit()), size(N, 1) {\r\n    par.resize(N);\r\
    \n    iota(all(par), 0);\r\n  }\r\n\r\n  // (root, P[root]^{-1}P[v])\r\n  pair<int,\
    \ E> get(int v) {\r\n    E res = Group::unit();\r\n    while (v != par[v]) {\r\
    \n      res = Group::op(vals[v], res);\r\n      res = Group::op(vals[par[v]],\
    \ res);\r\n      vals[v] = Group::op(vals[par[v]], vals[v]);\r\n      v = par[v]\
    \ = par[par[v]];\r\n    }\r\n    return {v, res};\r\n  }\r\n\r\n  pair<int, E>\
    \ operator[](int v) { return get(v); }\r\n\r\n  // is_same / path value\r\n  pair<bool,\
    \ E> get_path(int u, int v) {\r\n    auto [ru, xu] = get(u);\r\n    auto [rv,\
    \ xv] = get(v);\r\n    if (ru != rv) return {false, Group::unit()};\r\n    return\
    \ {true, Group::op(Group::inverse(xu), xv)};\r\n  }\r\n\r\n  // if same : do nothing.\r\
    \n  // P[to]==P[frm]x\r\n  bool merge(int frm, int to, E x) {\r\n    auto [v1,\
    \ x1] = get(frm);\r\n    auto [v2, x2] = get(to);\r\n    if (v1 == v2) return\
    \ false; // same\r\n    if (size[v1] < size[v2]) {\r\n      swap(v1, v2);\r\n\
    \      swap(x1, x2);\r\n      x = Group::inverse(x);\r\n    }\r\n    x = Group::op(x1,\
    \ x);\r\n    x = Group::op(x, Group::inverse(x2));\r\n    vals[v2] = x;\r\n  \
    \  par[v2] = v1;\r\n    size[v1] += size[v2];\r\n    --n_comp;\r\n    return true;\r\
    \n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind/potentialized_unionfind.hpp
  requiredBy: []
  timestamp: '2024-09-10 11:48:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/4_aoj/DSL_1_B.test.cpp
  - test/2_library_checker/unionfind_with_potential.test.cpp
  - test/2_library_checker/data_structure/unionfind_with_potential_group.test.cpp
  - test/3_yukicoder/1502.test.cpp
  - test/3_yukicoder/2294.test.cpp
documentation_of: ds/unionfind/potentialized_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/potentialized_unionfind.hpp
- /library/ds/unionfind/potentialized_unionfind.hpp.html
title: ds/unionfind/potentialized_unionfind.hpp
---
