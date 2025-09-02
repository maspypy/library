---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/data_structure/add_remove_query.test.cpp
    title: test/2_library_checker/data_structure/add_remove_query.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
    title: test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \    FOR(i, N) res[i] = get(i);\r\n    return res;\r\n  }\r\n};\r\n#line 2 \"\
    ds/unionfind/rollback_unionfind.hpp\"\n\r\nstruct Rollback_UnionFind {\r\n  int\
    \ n;\r\n  Rollback_Array<int> dat; // parent or size\r\n\r\n  Rollback_UnionFind(int\
    \ n) : n(n), dat(vc<int>(n, -1)) {}\r\n\r\n  int operator[](int v) {\r\n    while\
    \ (dat.get(v) >= 0) v = dat.get(v);\r\n    return v;\r\n  }\r\n\r\n  ll size(int\
    \ v) { return -dat.get((*this)[v]); }\r\n  int time() { return dat.time(); }\r\
    \n  void rollback(int t) { dat.rollback(t); }\r\n  void reset() { rollback(0);\
    \ }\r\n\r\n  bool merge(int a, int b) {\r\n    a = (*this)[a], b = (*this)[b];\r\
    \n    if (a == b) return false;\r\n    if (dat.get(a) > dat.get(b)) swap(a, b);\r\
    \n    dat.set(a, dat.get(a) + dat.get(b));\r\n    dat.set(b, a);\r\n    return\
    \ true;\r\n  }\r\n  vc<int> get_all() {\r\n    vc<int> ANS(n);\r\n    FOR(i, n)\
    \ ANS[i] = (*this)[i];\r\n    return ANS;\r\n  }\r\n};\r\n"
  code: "#include \"ds/rollback_array.hpp\"\r\n\r\nstruct Rollback_UnionFind {\r\n\
    \  int n;\r\n  Rollback_Array<int> dat; // parent or size\r\n\r\n  Rollback_UnionFind(int\
    \ n) : n(n), dat(vc<int>(n, -1)) {}\r\n\r\n  int operator[](int v) {\r\n    while\
    \ (dat.get(v) >= 0) v = dat.get(v);\r\n    return v;\r\n  }\r\n\r\n  ll size(int\
    \ v) { return -dat.get((*this)[v]); }\r\n  int time() { return dat.time(); }\r\
    \n  void rollback(int t) { dat.rollback(t); }\r\n  void reset() { rollback(0);\
    \ }\r\n\r\n  bool merge(int a, int b) {\r\n    a = (*this)[a], b = (*this)[b];\r\
    \n    if (a == b) return false;\r\n    if (dat.get(a) > dat.get(b)) swap(a, b);\r\
    \n    dat.set(a, dat.get(a) + dat.get(b));\r\n    dat.set(b, a);\r\n    return\
    \ true;\r\n  }\r\n  vc<int> get_all() {\r\n    vc<int> ANS(n);\r\n    FOR(i, n)\
    \ ANS[i] = (*this)[i];\r\n    return ANS;\r\n  }\r\n};\r\n"
  dependsOn:
  - ds/rollback_array.hpp
  isVerificationFile: false
  path: ds/unionfind/rollback_unionfind.hpp
  requiredBy: []
  timestamp: '2024-12-17 23:15:20+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/data_structure/add_remove_query.test.cpp
  - test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
documentation_of: ds/unionfind/rollback_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/rollback_unionfind.hpp
- /library/ds/unionfind/rollback_unionfind.hpp.html
title: ds/unionfind/rollback_unionfind.hpp
---
