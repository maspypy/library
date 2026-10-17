---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/data_structure/unionfind_with_potential_group.test.cpp
    title: test/2_library_checker/data_structure/unionfind_with_potential_group.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/unionfind_with_potential.test.cpp
    title: test/2_library_checker/unionfind_with_potential.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1502.test.cpp
    title: test/3_yukicoder/1502.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2294.test.cpp
    title: test/3_yukicoder/2294.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DSL_1_B.test.cpp
    title: test/4_aoj/DSL_1_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/unionfind/potentialized_unionfind.hpp
  bundledCode: "#line 1 \"ds/unionfind/potentialized_unionfind.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/unionfind/potentialized_unionfind.hpp\n\
    template <typename Group>\nstruct Potentialized_UnionFind {\n  using E = typename\
    \ Group::value_type;\n  int N;\n  int n_comp;\n  vc<E> vals;\n  vc<int> par;\n\
    \  vc<int> size;\n\n  Potentialized_UnionFind(int N) : N(N), n_comp(N), vals(N,\
    \ Group::id()), size(N, 1) {\n    par.resize(N);\n    iota(all(par), 0);\n  }\n\
    \n  // (root, P[root]^{-1}P[v])\n  pair<int, E> get(int v) {\n    E res = Group::id();\n\
    \    while (v != par[v]) {\n      res = Group::op(vals[v], res);\n      res =\
    \ Group::op(vals[par[v]], res);\n      vals[v] = Group::op(vals[par[v]], vals[v]);\n\
    \      v = par[v] = par[par[v]];\n    }\n    return {v, res};\n  }\n\n  pair<int,\
    \ E> operator[](int v) { return get(v); }\n\n  // is_same / path value\n  pair<bool,\
    \ E> get_path(int u, int v) {\n    auto [ru, xu] = get(u);\n    auto [rv, xv]\
    \ = get(v);\n    if (ru != rv) return {false, Group::id()};\n    return {true,\
    \ Group::op(Group::inverse(xu), xv)};\n  }\n\n  // if same : do nothing.\n  //\
    \ P[to]==P[frm]x\n  bool merge(int frm, int to, E x) {\n    auto [v1, x1] = get(frm);\n\
    \    auto [v2, x2] = get(to);\n    if (v1 == v2) return false; // same\n    if\
    \ (size[v1] < size[v2]) {\n      swap(v1, v2);\n      swap(x1, x2);\n      x =\
    \ Group::inverse(x);\n    }\n    x = Group::op(x1, x);\n    x = Group::op(x, Group::inverse(x2));\n\
    \    vals[v2] = x;\n    par[v2] = v1;\n    size[v1] += size[v2];\n    --n_comp;\n\
    \    return true;\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/unionfind/potentialized_unionfind.hpp\n\
    template <typename Group>\nstruct Potentialized_UnionFind {\n  using E = typename\
    \ Group::value_type;\n  int N;\n  int n_comp;\n  vc<E> vals;\n  vc<int> par;\n\
    \  vc<int> size;\n\n  Potentialized_UnionFind(int N) : N(N), n_comp(N), vals(N,\
    \ Group::id()), size(N, 1) {\n    par.resize(N);\n    iota(all(par), 0);\n  }\n\
    \n  // (root, P[root]^{-1}P[v])\n  pair<int, E> get(int v) {\n    E res = Group::id();\n\
    \    while (v != par[v]) {\n      res = Group::op(vals[v], res);\n      res =\
    \ Group::op(vals[par[v]], res);\n      vals[v] = Group::op(vals[par[v]], vals[v]);\n\
    \      v = par[v] = par[par[v]];\n    }\n    return {v, res};\n  }\n\n  pair<int,\
    \ E> operator[](int v) { return get(v); }\n\n  // is_same / path value\n  pair<bool,\
    \ E> get_path(int u, int v) {\n    auto [ru, xu] = get(u);\n    auto [rv, xv]\
    \ = get(v);\n    if (ru != rv) return {false, Group::id()};\n    return {true,\
    \ Group::op(Group::inverse(xu), xv)};\n  }\n\n  // if same : do nothing.\n  //\
    \ P[to]==P[frm]x\n  bool merge(int frm, int to, E x) {\n    auto [v1, x1] = get(frm);\n\
    \    auto [v2, x2] = get(to);\n    if (v1 == v2) return false; // same\n    if\
    \ (size[v1] < size[v2]) {\n      swap(v1, v2);\n      swap(x1, x2);\n      x =\
    \ Group::inverse(x);\n    }\n    x = Group::op(x1, x);\n    x = Group::op(x, Group::inverse(x2));\n\
    \    vals[v2] = x;\n    par[v2] = v1;\n    size[v1] += size[v2];\n    --n_comp;\n\
    \    return true;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind/potentialized_unionfind.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/2294.test.cpp
  - test/3_yukicoder/1502.test.cpp
  - test/2_library_checker/data_structure/unionfind_with_potential_group.test.cpp
  - test/2_library_checker/unionfind_with_potential.test.cpp
  - test/4_aoj/DSL_1_B.test.cpp
documentation_of: ds/unionfind/potentialized_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/potentialized_unionfind.hpp
- /library/ds/unionfind/potentialized_unionfind.hpp.html
title: ds/unionfind/potentialized_unionfind.hpp
---
