---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \    FOR(i, N) res[i] = get(i);\n    return res;\n  }\n};\n#line 2 \"ds/unionfind/rollback_potentialized_unionfind.hpp\"\
    \n\ntemplate <typename Group>\nstruct Rollback_Potentialized_UnionFind {\n  using\
    \ E = typename Group::value_type;\n  using P = pair<int, E>;\n  Rollback_Array<P>\
    \ dat; // parent or -size\n\n  Rollback_Potentialized_UnionFind(int n) : dat(vc<P>(n,\
    \ P(-1, Group::id()))) {}\n\n  P get(int v) {\n    // \u7D4C\u8DEF\u5727\u7E2E\
    \u306F\u3057\u306A\u3044\u3088\u3046\u306B\n    E val = Group::id();\n    while\
    \ (1) {\n      auto [p, x] = dat.get(v);\n      if (p < 0) { break; }\n      val\
    \ = Group::op(x, val);\n      v = p;\n    }\n    return {v, val};\n  }\n\n  int\
    \ time() { return dat.time(); }\n  void rollback(int t) { dat.rollback(t); }\n\
    \n  bool merge(int a, int b, E x) {\n    auto [v1, x1] = get(a);\n    auto [v2,\
    \ x2] = get(b);\n    if (v1 == v2) return false;\n    int s1 = -dat.get(v1).fi;\n\
    \    int s2 = -dat.get(v2).fi;\n    if (s1 < s2) {\n      swap(s1, s2), swap(v1,\
    \ v2), swap(x1, x2);\n      x = Group::inverse(x);\n    }\n    // v1 <- v2\n \
    \   x = Group::op(x1, x);\n    x = Group::op(x, Group::inverse(x2));\n    dat.set(v2,\
    \ P({v1, x}));\n    dat.set(v1, P({-(s1 + s2), Group::id()}));\n    return true;\n\
    \  }\n};\n"
  code: "#include \"ds/rollback_array.hpp\"\n\ntemplate <typename Group>\nstruct Rollback_Potentialized_UnionFind\
    \ {\n  using E = typename Group::value_type;\n  using P = pair<int, E>;\n  Rollback_Array<P>\
    \ dat; // parent or -size\n\n  Rollback_Potentialized_UnionFind(int n) : dat(vc<P>(n,\
    \ P(-1, Group::id()))) {}\n\n  P get(int v) {\n    // \u7D4C\u8DEF\u5727\u7E2E\
    \u306F\u3057\u306A\u3044\u3088\u3046\u306B\n    E val = Group::id();\n    while\
    \ (1) {\n      auto [p, x] = dat.get(v);\n      if (p < 0) { break; }\n      val\
    \ = Group::op(x, val);\n      v = p;\n    }\n    return {v, val};\n  }\n\n  int\
    \ time() { return dat.time(); }\n  void rollback(int t) { dat.rollback(t); }\n\
    \n  bool merge(int a, int b, E x) {\n    auto [v1, x1] = get(a);\n    auto [v2,\
    \ x2] = get(b);\n    if (v1 == v2) return false;\n    int s1 = -dat.get(v1).fi;\n\
    \    int s2 = -dat.get(v2).fi;\n    if (s1 < s2) {\n      swap(s1, s2), swap(v1,\
    \ v2), swap(x1, x2);\n      x = Group::inverse(x);\n    }\n    // v1 <- v2\n \
    \   x = Group::op(x1, x);\n    x = Group::op(x, Group::inverse(x2));\n    dat.set(v2,\
    \ P({v1, x}));\n    dat.set(v1, P({-(s1 + s2), Group::id()}));\n    return true;\n\
    \  }\n};\n"
  dependsOn:
  - ds/rollback_array.hpp
  isVerificationFile: false
  path: ds/unionfind/rollback_potentialized_unionfind.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2293.test.cpp
documentation_of: ds/unionfind/rollback_potentialized_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/rollback_potentialized_unionfind.hpp
- /library/ds/unionfind/rollback_potentialized_unionfind.hpp.html
title: ds/unionfind/rollback_potentialized_unionfind.hpp
---
