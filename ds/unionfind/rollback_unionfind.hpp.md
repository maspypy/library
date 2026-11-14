---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    links:
    - https://github.com/maspypy/library/blob/main/ds/unionfind/rollback_unionfind.hpp
  bundledCode: "#line 1 \"ds/unionfind/rollback_unionfind.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/unionfind/rollback_unionfind.hpp\n\
    #line 1 \"ds/rollback_array.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/rollback_array.hpp\n\
    \ntemplate <typename T>\nstruct Rollback_Array {\n  int N;\n  vc<T> dat;\n  vc<pair<int,\
    \ T>> history;\n\n  Rollback_Array() {}\n  Rollback_Array(vc<T> x) : N(len(x)),\
    \ dat(x) {}\n  Rollback_Array(int N) : N(N), dat(N) {}\n  template <typename F>\n\
    \  Rollback_Array(int N, F f) : N(N) {\n    dat.reserve(N);\n    FOR(i, N) dat.eb(f(i));\n\
    \  }\n\n  int time() { return len(history); }\n  void rollback(int t) {\n    while\
    \ (t < time()) {\n      auto [idx, v] = POP(history);\n      dat[idx] = v;\n \
    \   }\n  }\n  T get(int idx) { return dat[idx]; }\n  void set(int idx, T x) {\n\
    \    history.eb(idx, dat[idx]);\n    dat[idx] = x;\n  }\n\n  vc<T> get_all() {\
    \ return dat; }\n};\n#line 3 \"ds/unionfind/rollback_unionfind.hpp\"\n\nstruct\
    \ Rollback_UnionFind {\n  int n;\n  Rollback_Array<int> dat; // parent or size\n\
    \n  Rollback_UnionFind(int n) : n(n), dat(vc<int>(n, -1)) {}\n\n  int operator[](int\
    \ v) {\n    while (dat.get(v) >= 0) v = dat.get(v);\n    return v;\n  }\n\n  ll\
    \ size(int v) { return -dat.get((*this)[v]); }\n  int time() { return dat.time();\
    \ }\n  void rollback(int t) { dat.rollback(t); }\n  void reset() { rollback(0);\
    \ }\n\n  bool merge(int a, int b) {\n    a = (*this)[a], b = (*this)[b];\n   \
    \ if (a == b) return false;\n    if (dat.get(a) > dat.get(b)) swap(a, b);\n  \
    \  dat.set(a, dat.get(a) + dat.get(b));\n    dat.set(b, a);\n    return true;\n\
    \  }\n  vc<int> get_all() {\n    vc<int> ANS(n);\n    FOR(i, n) ANS[i] = (*this)[i];\n\
    \    return ANS;\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/unionfind/rollback_unionfind.hpp\n\
    #include \"ds/rollback_array.hpp\"\n\nstruct Rollback_UnionFind {\n  int n;\n\
    \  Rollback_Array<int> dat; // parent or size\n\n  Rollback_UnionFind(int n) :\
    \ n(n), dat(vc<int>(n, -1)) {}\n\n  int operator[](int v) {\n    while (dat.get(v)\
    \ >= 0) v = dat.get(v);\n    return v;\n  }\n\n  ll size(int v) { return -dat.get((*this)[v]);\
    \ }\n  int time() { return dat.time(); }\n  void rollback(int t) { dat.rollback(t);\
    \ }\n  void reset() { rollback(0); }\n\n  bool merge(int a, int b) {\n    a =\
    \ (*this)[a], b = (*this)[b];\n    if (a == b) return false;\n    if (dat.get(a)\
    \ > dat.get(b)) swap(a, b);\n    dat.set(a, dat.get(a) + dat.get(b));\n    dat.set(b,\
    \ a);\n    return true;\n  }\n  vc<int> get_all() {\n    vc<int> ANS(n);\n   \
    \ FOR(i, n) ANS[i] = (*this)[i];\n    return ANS;\n  }\n};\n"
  dependsOn:
  - ds/rollback_array.hpp
  isVerificationFile: false
  path: ds/unionfind/rollback_unionfind.hpp
  requiredBy: []
  timestamp: '2026-10-27 03:17:11+09:00'
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
