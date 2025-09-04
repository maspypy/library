---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/2293.test.cpp
    title: test/3_yukicoder/2293.test.cpp
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
    ds/unionfind/rollback_potentialized_unionfind.hpp\"\n\ntemplate <typename Group>\n\
    struct Rollback_Potentialized_UnionFind {\n  using E = typename Group::value_type;\n\
    \  using P = pair<int, E>;\n  Rollback_Array<P> dat; // parent or -size\n\n  Rollback_Potentialized_UnionFind(int\
    \ n) : dat(vc<P>(n, P(-1, Group::unit()))) {}\n\n  P get(int v) {\n    // \u7D4C\
    \u8DEF\u5727\u7E2E\u306F\u3057\u306A\u3044\u3088\u3046\u306B\n    E val = Group::unit();\n\
    \    while (1) {\n      auto [p, x] = dat.get(v);\n      if (p < 0) { break; }\n\
    \      val = Group::op(x, val);\n      v = p;\n    }\n    return {v, val};\n \
    \ }\n\n  int time() { return dat.time(); }\n  void rollback(int t) { dat.rollback(t);\
    \ }\n\n  bool merge(int a, int b, E x) {\n    auto [v1, x1] = get(a);\n    auto\
    \ [v2, x2] = get(b);\n    if (v1 == v2) return false;\n    int s1 = -dat.get(v1).fi;\n\
    \    int s2 = -dat.get(v2).fi;\n    if (s1 < s2) {\n      swap(s1, s2), swap(v1,\
    \ v2), swap(x1, x2);\n      x = Group::inverse(x);\n    }\n    // v1 <- v2\n \
    \   x = Group::op(x1, x);\n    x = Group::op(x, Group::inverse(x2));\n    dat.set(v2,\
    \ P({v1, x}));\n    dat.set(v1, P({-(s1 + s2), Group::unit()}));\n    return true;\n\
    \  }\n};\n"
  code: "#include \"ds/rollback_array.hpp\"\n\ntemplate <typename Group>\nstruct Rollback_Potentialized_UnionFind\
    \ {\n  using E = typename Group::value_type;\n  using P = pair<int, E>;\n  Rollback_Array<P>\
    \ dat; // parent or -size\n\n  Rollback_Potentialized_UnionFind(int n) : dat(vc<P>(n,\
    \ P(-1, Group::unit()))) {}\n\n  P get(int v) {\n    // \u7D4C\u8DEF\u5727\u7E2E\
    \u306F\u3057\u306A\u3044\u3088\u3046\u306B\n    E val = Group::unit();\n    while\
    \ (1) {\n      auto [p, x] = dat.get(v);\n      if (p < 0) { break; }\n      val\
    \ = Group::op(x, val);\n      v = p;\n    }\n    return {v, val};\n  }\n\n  int\
    \ time() { return dat.time(); }\n  void rollback(int t) { dat.rollback(t); }\n\
    \n  bool merge(int a, int b, E x) {\n    auto [v1, x1] = get(a);\n    auto [v2,\
    \ x2] = get(b);\n    if (v1 == v2) return false;\n    int s1 = -dat.get(v1).fi;\n\
    \    int s2 = -dat.get(v2).fi;\n    if (s1 < s2) {\n      swap(s1, s2), swap(v1,\
    \ v2), swap(x1, x2);\n      x = Group::inverse(x);\n    }\n    // v1 <- v2\n \
    \   x = Group::op(x1, x);\n    x = Group::op(x, Group::inverse(x2));\n    dat.set(v2,\
    \ P({v1, x}));\n    dat.set(v1, P({-(s1 + s2), Group::unit()}));\n    return true;\n\
    \  }\n};\n"
  dependsOn:
  - ds/rollback_array.hpp
  isVerificationFile: false
  path: ds/unionfind/rollback_potentialized_unionfind.hpp
  requiredBy: []
  timestamp: '2024-09-10 16:34:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/2293.test.cpp
documentation_of: ds/unionfind/rollback_potentialized_unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/rollback_potentialized_unionfind.hpp
- /library/ds/unionfind/rollback_potentialized_unionfind.hpp.html
title: ds/unionfind/rollback_potentialized_unionfind.hpp
---
