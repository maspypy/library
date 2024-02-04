---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/segtree/rollback_lazy_segtree.hpp
    title: ds/segtree/rollback_lazy_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/rollback_unionfind.hpp
    title: ds/unionfind/rollback_unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/rollback_weighted_unionfind.hpp
    title: ds/unionfind/rollback_weighted_unionfind.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/add_remove_query.test.cpp
    title: test/library_checker/datastructure/add_remove_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_graph_vertex_add_component_sum.test.cpp
    title: test/library_checker/datastructure/dynamic_graph_vertex_add_component_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2293.test.cpp
    title: test/yukicoder/2293.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/rollback_array.hpp\"\n\r\ntemplate <typename T>\r\nstruct\
    \ Rollback_Array {\r\n  int N;\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\
    \n\r\n  Rollback_Array() {}\r\n  Rollback_Array(vc<T> x) : N(len(x)), dat(x) {}\r\
    \n  Rollback_Array(int N) : N(N), dat(N) {}\r\n  template <typename F>\r\n  Rollback_Array(int\
    \ N, F f) : N(N) {\r\n    dat.reserve(N);\r\n    FOR(i, N) dat.eb(f(i));\r\n \
    \ }\r\n\r\n  int time() { return len(history); }\r\n  void rollback(int t) {\r\
    \n    FOR_R(i, t, time()) {\r\n      auto& [idx, v] = history[i];\r\n      dat[idx]\
    \ = v;\r\n    }\r\n    history.resize(t);\r\n  }\r\n  T get(int idx) { return\
    \ dat[idx]; }\r\n  void set(int idx, T x) {\r\n    history.eb(idx, dat[idx]);\r\
    \n    dat[idx] = x;\r\n  }\r\n\r\n  vc<T> get_all() {\r\n    vc<T> res(N);\r\n\
    \    FOR(i, N) res[i] = get(i);\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nstruct Rollback_Array {\r\n\
    \  int N;\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\n\r\n  Rollback_Array()\
    \ {}\r\n  Rollback_Array(vc<T> x) : N(len(x)), dat(x) {}\r\n  Rollback_Array(int\
    \ N) : N(N), dat(N) {}\r\n  template <typename F>\r\n  Rollback_Array(int N, F\
    \ f) : N(N) {\r\n    dat.reserve(N);\r\n    FOR(i, N) dat.eb(f(i));\r\n  }\r\n\
    \r\n  int time() { return len(history); }\r\n  void rollback(int t) {\r\n    FOR_R(i,\
    \ t, time()) {\r\n      auto& [idx, v] = history[i];\r\n      dat[idx] = v;\r\n\
    \    }\r\n    history.resize(t);\r\n  }\r\n  T get(int idx) { return dat[idx];\
    \ }\r\n  void set(int idx, T x) {\r\n    history.eb(idx, dat[idx]);\r\n    dat[idx]\
    \ = x;\r\n  }\r\n\r\n  vc<T> get_all() {\r\n    vc<T> res(N);\r\n    FOR(i, N)\
    \ res[i] = get(i);\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/rollback_array.hpp
  requiredBy:
  - ds/segtree/rollback_lazy_segtree.hpp
  - ds/unionfind/rollback_unionfind.hpp
  - ds/unionfind/rollback_weighted_unionfind.hpp
  timestamp: '2023-06-23 23:19:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/add_remove_query.test.cpp
  - test/library_checker/datastructure/dynamic_graph_vertex_add_component_sum.test.cpp
  - test/yukicoder/2293.test.cpp
documentation_of: ds/rollback_array.hpp
layout: document
redirect_from:
- /library/ds/rollback_array.hpp
- /library/ds/rollback_array.hpp.html
title: ds/rollback_array.hpp
---