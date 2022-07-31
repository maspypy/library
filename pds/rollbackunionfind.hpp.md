---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: pds/rollbackarray.hpp
    title: pds/rollbackarray.hpp
  _extendedRequiredBy: []
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
    \ dat[idx]);\r\n    dat[idx] = x;\r\n  }\r\n};\r\n#line 2 \"pds/rollbackunionfind.hpp\"\
    \n\r\nstruct RollbackUnionFind {\r\n  RollbackArray<int> dat; // parent or size\r\
    \n\r\n  RollbackUnionFind(int n) : dat(vc<int>(n, -1)) {}\r\n\r\n  int operator[](int\
    \ v) {\r\n    while (dat.get(v) >= 0) v = dat.get(v);\r\n    return v;\r\n  }\r\
    \n\r\n  int size(int v) { return -dat.get((*this)[v]); }\r\n  int time() { return\
    \ dat.time(); }\r\n  void rollback(int t) { dat.rollback(t); }\r\n\r\n  bool merge(int\
    \ a, int b) {\r\n    a = (*this)[a], b = (*this)[b];\r\n    if (a == b) return\
    \ false;\r\n    if (dat.get(a) > dat.get(b)) swap(a, b);\r\n    dat.set(a, dat.get(a)\
    \ + dat.get(b));\r\n    dat.set(b, a);\r\n    return true;\r\n  }\r\n};\r\n"
  code: "#include \"pds/rollbackarray.hpp\"\r\n\r\nstruct RollbackUnionFind {\r\n\
    \  RollbackArray<int> dat; // parent or size\r\n\r\n  RollbackUnionFind(int n)\
    \ : dat(vc<int>(n, -1)) {}\r\n\r\n  int operator[](int v) {\r\n    while (dat.get(v)\
    \ >= 0) v = dat.get(v);\r\n    return v;\r\n  }\r\n\r\n  int size(int v) { return\
    \ -dat.get((*this)[v]); }\r\n  int time() { return dat.time(); }\r\n  void rollback(int\
    \ t) { dat.rollback(t); }\r\n\r\n  bool merge(int a, int b) {\r\n    a = (*this)[a],\
    \ b = (*this)[b];\r\n    if (a == b) return false;\r\n    if (dat.get(a) > dat.get(b))\
    \ swap(a, b);\r\n    dat.set(a, dat.get(a) + dat.get(b));\r\n    dat.set(b, a);\r\
    \n    return true;\r\n  }\r\n};\r\n"
  dependsOn:
  - pds/rollbackarray.hpp
  isVerificationFile: false
  path: pds/rollbackunionfind.hpp
  requiredBy: []
  timestamp: '2022-05-26 23:36:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/dynamic_graph_vertex_add_component_sum.test.cpp
documentation_of: pds/rollbackunionfind.hpp
layout: document
redirect_from:
- /library/pds/rollbackunionfind.hpp
- /library/pds/rollbackunionfind.hpp.html
title: pds/rollbackunionfind.hpp
---
