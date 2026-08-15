---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/segtree/rollback_lazy_segtree.hpp
    title: ds/segtree/rollback_lazy_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/rollback_potentialized_unionfind.hpp
    title: ds/unionfind/rollback_potentialized_unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/rollback_unionfind.hpp
    title: ds/unionfind/rollback_unionfind.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/add_remove_query.test.cpp
    title: test/2_library_checker/data_structure/add_remove_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
    title: test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2293.test.cpp
    title: test/3_yukicoder/2293.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/rollback_array.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Rollback_Array {\n  int N;\n  vc<T> dat;\n  vc<pair<int, T>> history;\n\n  Rollback_Array()\
    \ {}\n  Rollback_Array(vc<T> x) : N(len(x)), dat(x) {}\n  Rollback_Array(int N)\
    \ : N(N), dat(N) {}\n  template <typename F>\n  Rollback_Array(int N, F f) : N(N)\
    \ {\n    dat.reserve(N);\n    FOR(i, N) dat.eb(f(i));\n  }\n\n  int time() { return\
    \ len(history); }\n  void rollback(int t) {\n    FOR_R(i, t, time()) {\n     \
    \ auto& [idx, v] = history[i];\n      dat[idx] = v;\n    }\n    history.resize(t);\n\
    \  }\n  T get(int idx) { return dat[idx]; }\n  void set(int idx, T x) {\n    history.eb(idx,\
    \ dat[idx]);\n    dat[idx] = x;\n  }\n\n  vc<T> get_all() {\n    vc<T> res(N);\n\
    \    FOR(i, N) res[i] = get(i);\n    return res;\n  }\n};\n"
  code: "\ntemplate <typename T>\nstruct Rollback_Array {\n  int N;\n  vc<T> dat;\n\
    \  vc<pair<int, T>> history;\n\n  Rollback_Array() {}\n  Rollback_Array(vc<T>\
    \ x) : N(len(x)), dat(x) {}\n  Rollback_Array(int N) : N(N), dat(N) {}\n  template\
    \ <typename F>\n  Rollback_Array(int N, F f) : N(N) {\n    dat.reserve(N);\n \
    \   FOR(i, N) dat.eb(f(i));\n  }\n\n  int time() { return len(history); }\n  void\
    \ rollback(int t) {\n    FOR_R(i, t, time()) {\n      auto& [idx, v] = history[i];\n\
    \      dat[idx] = v;\n    }\n    history.resize(t);\n  }\n  T get(int idx) { return\
    \ dat[idx]; }\n  void set(int idx, T x) {\n    history.eb(idx, dat[idx]);\n  \
    \  dat[idx] = x;\n  }\n\n  vc<T> get_all() {\n    vc<T> res(N);\n    FOR(i, N)\
    \ res[i] = get(i);\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/rollback_array.hpp
  requiredBy:
  - ds/unionfind/rollback_potentialized_unionfind.hpp
  - ds/unionfind/rollback_unionfind.hpp
  - ds/segtree/rollback_lazy_segtree.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
  - test/2_library_checker/data_structure/add_remove_query.test.cpp
  - test/3_yukicoder/2293.test.cpp
documentation_of: ds/rollback_array.hpp
layout: document
redirect_from:
- /library/ds/rollback_array.hpp
- /library/ds/rollback_array.hpp.html
title: ds/rollback_array.hpp
---
