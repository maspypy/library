---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/add_remove_query.test.cpp
    title: test/2_library_checker/data_structure/add_remove_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
    title: test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
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
    \    FOR(i, N) res[i] = get(i);\n    return res;\n  }\n};\n#line 2 \"ds/unionfind/rollback_unionfind.hpp\"\
    \n\r\nstruct Rollback_UnionFind {\r\n  int n;\r\n  Rollback_Array<int> dat; //\
    \ parent or size\r\n\r\n  Rollback_UnionFind(int n) : n(n), dat(vc<int>(n, -1))\
    \ {}\r\n\r\n  int operator[](int v) {\r\n    while (dat.get(v) >= 0) v = dat.get(v);\r\
    \n    return v;\r\n  }\r\n\r\n  ll size(int v) { return -dat.get((*this)[v]);\
    \ }\r\n  int time() { return dat.time(); }\r\n  void rollback(int t) { dat.rollback(t);\
    \ }\r\n  void reset() { rollback(0); }\r\n\r\n  bool merge(int a, int b) {\r\n\
    \    a = (*this)[a], b = (*this)[b];\r\n    if (a == b) return false;\r\n    if\
    \ (dat.get(a) > dat.get(b)) swap(a, b);\r\n    dat.set(a, dat.get(a) + dat.get(b));\r\
    \n    dat.set(b, a);\r\n    return true;\r\n  }\r\n  vc<int> get_all() {\r\n \
    \   vc<int> ANS(n);\r\n    FOR(i, n) ANS[i] = (*this)[i];\r\n    return ANS;\r\
    \n  }\r\n};\r\n"
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
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/graph/dynamic_graph_vertex_add_component_sum.test.cpp
  - test/2_library_checker/data_structure/add_remove_query.test.cpp
documentation_of: ds/unionfind/rollback_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/rollback_unionfind.hpp
- /library/ds/unionfind/rollback_unionfind.hpp.html
title: ds/unionfind/rollback_unionfind.hpp
---
