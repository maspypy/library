---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: pds/rollbackunionfind.hpp
    title: pds/rollbackunionfind.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp
    title: test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"pds/rollbackarray.hpp\"\ntemplate <typename T>\r\nstruct\
    \ RollbackArray {\r\n  vc<T> dat;\r\n  vc<pair<int, T>> history;\r\n\r\n  RollbackArray(vc<T>\
    \ x) : dat(x) {}\r\n\r\n  int time() { return len(history); }\r\n  void rollback(int\
    \ t) {\r\n    FOR_R(i, t, time()) {\r\n      auto& [idx, v] = history[i];\r\n\
    \      dat[idx] = v;\r\n    }\r\n    history.resize(t);\r\n  }\r\n  T get(int\
    \ idx) { return dat[idx]; }\r\n  void set(int idx, T x) {\r\n    history.eb(idx,\
    \ dat[idx]);\r\n    dat[idx] = x;\r\n  }\r\n};\r\n"
  code: "template <typename T>\r\nstruct RollbackArray {\r\n  vc<T> dat;\r\n  vc<pair<int,\
    \ T>> history;\r\n\r\n  RollbackArray(vc<T> x) : dat(x) {}\r\n\r\n  int time()\
    \ { return len(history); }\r\n  void rollback(int t) {\r\n    FOR_R(i, t, time())\
    \ {\r\n      auto& [idx, v] = history[i];\r\n      dat[idx] = v;\r\n    }\r\n\
    \    history.resize(t);\r\n  }\r\n  T get(int idx) { return dat[idx]; }\r\n  void\
    \ set(int idx, T x) {\r\n    history.eb(idx, dat[idx]);\r\n    dat[idx] = x;\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: pds/rollbackarray.hpp
  requiredBy:
  - pds/rollbackunionfind.hpp
  timestamp: '2022-05-26 23:36:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp
documentation_of: pds/rollbackarray.hpp
layout: document
redirect_from:
- /library/pds/rollbackarray.hpp
- /library/pds/rollbackarray.hpp.html
title: pds/rollbackarray.hpp
---
