---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: pds/rollbackunionfind.hpp
    title: pds/rollbackunionfind.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/add_remove_query.test.cpp
    title: test/library_checker/add_remove_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp
    title: test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"pds/rollbackarray.hpp\"\n\r\ntemplate <typename T>\r\nstruct\
    \ RollbackArray {\r\n  int N;\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\
    \n\r\n  RollbackArray(vc<T> x) : N(len(x)), dat(x) {}\r\n\r\n  int time() { return\
    \ len(history); }\r\n  void rollback(int t) {\r\n    FOR_R(i, t, time()) {\r\n\
    \      auto& [idx, v] = history[i];\r\n      dat[idx] = v;\r\n    }\r\n    history.resize(t);\r\
    \n  }\r\n  T get(int idx) { return dat[idx]; }\r\n  void set(int idx, T x) {\r\
    \n    history.eb(idx, dat[idx]);\r\n    dat[idx] = x;\r\n  }\r\n\r\n  vc<T> get_all()\
    \ {\r\n    vc<T> res(N);\r\n    FOR(i, N) res[i] = get(i);\r\n    return res;\r\
    \n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nstruct RollbackArray {\r\n \
    \ int N;\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\n\r\n  RollbackArray(vc<T>\
    \ x) : N(len(x)), dat(x) {}\r\n\r\n  int time() { return len(history); }\r\n \
    \ void rollback(int t) {\r\n    FOR_R(i, t, time()) {\r\n      auto& [idx, v]\
    \ = history[i];\r\n      dat[idx] = v;\r\n    }\r\n    history.resize(t);\r\n\
    \  }\r\n  T get(int idx) { return dat[idx]; }\r\n  void set(int idx, T x) {\r\n\
    \    history.eb(idx, dat[idx]);\r\n    dat[idx] = x;\r\n  }\r\n\r\n  vc<T> get_all()\
    \ {\r\n    vc<T> res(N);\r\n    FOR(i, N) res[i] = get(i);\r\n    return res;\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: pds/rollbackarray.hpp
  requiredBy:
  - pds/rollbackunionfind.hpp
  timestamp: '2022-08-18 20:34:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/add_remove_query.test.cpp
  - test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp
documentation_of: pds/rollbackarray.hpp
layout: document
redirect_from:
- /library/pds/rollbackarray.hpp
- /library/pds/rollbackarray.hpp.html
title: pds/rollbackarray.hpp
---
