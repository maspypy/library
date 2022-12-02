---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: ds/unionfind/rollbackunionfind.hpp
    title: ds/unionfind/rollbackunionfind.hpp
  - icon: ':warning:'
    path: ds/unionfind/rollbackweighteduf.hpp
    title: ds/unionfind/rollbackweighteduf.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/add_remove_query.test.cpp
    title: test/library_checker/datastructure/add_remove_query.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/dynamic_graph_vertex_add_component_sum.test.cpp
    title: test/library_checker/datastructure/dynamic_graph_vertex_add_component_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/pds/rollbackarray.hpp\"\n\r\ntemplate <typename T>\r\n\
    struct RollbackArray {\r\n  int N;\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\
    \n\r\n  RollbackArray(vc<T> x) : N(len(x)), dat(x) {}\r\n  template <typename\
    \ F>\r\n  RollbackArray(int N, F f) : N(N) {\r\n    dat.reserve(N);\r\n    FOR(i,\
    \ N) dat.eb(f(i));\r\n  }\r\n\r\n  int time() { return len(history); }\r\n  void\
    \ rollback(int t) {\r\n    FOR_R(i, t, time()) {\r\n      auto& [idx, v] = history[i];\r\
    \n      dat[idx] = v;\r\n    }\r\n    history.resize(t);\r\n  }\r\n  T get(int\
    \ idx) { return dat[idx]; }\r\n  void set(int idx, T x) {\r\n    history.eb(idx,\
    \ dat[idx]);\r\n    dat[idx] = x;\r\n  }\r\n\r\n  vc<T> get_all() {\r\n    vc<T>\
    \ res(N);\r\n    FOR(i, N) res[i] = get(i);\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nstruct RollbackArray {\r\n \
    \ int N;\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\n\r\n  RollbackArray(vc<T>\
    \ x) : N(len(x)), dat(x) {}\r\n  template <typename F>\r\n  RollbackArray(int\
    \ N, F f) : N(N) {\r\n    dat.reserve(N);\r\n    FOR(i, N) dat.eb(f(i));\r\n \
    \ }\r\n\r\n  int time() { return len(history); }\r\n  void rollback(int t) {\r\
    \n    FOR_R(i, t, time()) {\r\n      auto& [idx, v] = history[i];\r\n      dat[idx]\
    \ = v;\r\n    }\r\n    history.resize(t);\r\n  }\r\n  T get(int idx) { return\
    \ dat[idx]; }\r\n  void set(int idx, T x) {\r\n    history.eb(idx, dat[idx]);\r\
    \n    dat[idx] = x;\r\n  }\r\n\r\n  vc<T> get_all() {\r\n    vc<T> res(N);\r\n\
    \    FOR(i, N) res[i] = get(i);\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/pds/rollbackarray.hpp
  requiredBy:
  - ds/unionfind/rollbackweighteduf.hpp
  - ds/unionfind/rollbackunionfind.hpp
  timestamp: '2022-11-23 08:10:34+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/add_remove_query.test.cpp
  - test/library_checker/datastructure/dynamic_graph_vertex_add_component_sum.test.cpp
documentation_of: ds/pds/rollbackarray.hpp
layout: document
redirect_from:
- /library/ds/pds/rollbackarray.hpp
- /library/ds/pds/rollbackarray.hpp.html
title: ds/pds/rollbackarray.hpp
---
