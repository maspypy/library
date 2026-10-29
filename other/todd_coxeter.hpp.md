---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/other/todd_coxeter.hpp
  bundledCode: "#line 1 \"other/todd_coxeter.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/other/todd_coxeter.hpp\n\
    #line 1 \"ds/unionfind/unionfind.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/unionfind/unionfind.hpp\n\
    \nstruct UnionFind {\n  int n, n_comp;\n  vc<int> dat;  // par or (-size)\n  UnionFind(int\
    \ n = 0) { build(n); }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n,\
    \ -1);\n  }\n\n  void reset() { build(n); }\n\n  int add_vertex() {\n    ++n_comp,\
    \ dat.eb(-1);\n    return n++;\n  }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) {\n        return dat[x];\n\
    \      }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x)\
    \ {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int\
    \ y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n \
    \   if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i,\
    \ n) A[i] = (*this)[i];\n    return A;\n  }\n};\n#line 3 \"other/todd_coxeter.hpp\"\
    \n\n// \u6709\u9650\u30E2\u30CE\u30A4\u30C9\u3067\u3042\u308B\u3053\u3068\u3092\
    \u524D\u63D0\u3068\u3057\u3066\uFF0C\u9077\u79FB\u8868\u3092\u8FD4\u3059\ntemplate\
    \ <int K>\nvc<array<int, K>> todd_coxeter(const vc<pair<vc<int>, vc<int>>> &R)\
    \ {\n  int N = 0;\n\n  vector<array<int, K>> T;\n  UnionFind uf;\n  vc<bool> done;\n\
    \n  auto add_vertex = [&]() -> int {\n    int v = N++;\n    T.emplace_back().fill(-1);\n\
    \    uf.add_vertex();\n    done.eb(false);\n    return v;\n  };\n\n  auto step\
    \ = [&](int v, int x) -> int {\n    v = uf[v];\n    if (T[v][x] == -1) return\
    \ T[v][x] = add_vertex();\n    return uf[T[v][x]];\n  };\n\n  auto walk = [&](int\
    \ v, const vc<int> &s) -> int {\n    for (int x : s) v = step(v, x);\n    return\
    \ v;\n  };\n\n  auto merge = [&](int p, int q) -> void {\n    vc<pair<int, int>>\
    \ que;\n    que.eb(p, q);\n    while (len(que)) {\n      auto [p, q] = POP(que);\n\
    \      p = uf[p], q = uf[q];\n      if (p == q) continue;\n      uf.merge(p, q);\n\
    \      int r = uf[p];\n      done[r] = done[p] | done[q];\n      FOR(x, K) {\n\
    \        int a = T[p][x], b = T[q][x];\n        T[r][x] = max(a, b);\n       \
    \ if (a != -1 && b != -1) que.eb(a, b);\n      }\n    }\n  };\n\n  add_vertex();\n\
    \  for (int p = 0; p < len(T); ++p) {\n    for (auto &[u, v] : R) merge(walk(p,\
    \ u), walk(p, v));\n    FOR(x, K) step(p, x);\n    done[uf[p]] = true;\n  }\n\n\
    \  // \u4EE3\u8868\u5143\u3060\u3051\u3092\u6B8B\u3057\u3066\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u3092\u3064\u3051\u306A\u304A\u3057\uFF0C\u9077\u79FB\u8868\
    \u3092\u8FD4\u3059\n  vc<int> root;\n  FOR(v, N) if (uf[v] == v) root.emplace_back(v);\n\
    \  int n = len(root);\n  vc<int> new_idx(N);\n  FOR(i, n) new_idx[root[i]] = i;\n\
    \  for (int v : root) {\n    FOR(x, K) T[v][x] = new_idx[uf[T[v][x]]];\n  }\n\
    \  FOR(i, n) T[i] = T[root[i]];\n  T.resize(n);\n  return T;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/other/todd_coxeter.hpp\n\
    #include \"ds/unionfind/unionfind.hpp\"\n\n// \u6709\u9650\u30E2\u30CE\u30A4\u30C9\
    \u3067\u3042\u308B\u3053\u3068\u3092\u524D\u63D0\u3068\u3057\u3066\uFF0C\u9077\
    \u79FB\u8868\u3092\u8FD4\u3059\ntemplate <int K>\nvc<array<int, K>> todd_coxeter(const\
    \ vc<pair<vc<int>, vc<int>>> &R) {\n  int N = 0;\n\n  vector<array<int, K>> T;\n\
    \  UnionFind uf;\n  vc<bool> done;\n\n  auto add_vertex = [&]() -> int {\n   \
    \ int v = N++;\n    T.emplace_back().fill(-1);\n    uf.add_vertex();\n    done.eb(false);\n\
    \    return v;\n  };\n\n  auto step = [&](int v, int x) -> int {\n    v = uf[v];\n\
    \    if (T[v][x] == -1) return T[v][x] = add_vertex();\n    return uf[T[v][x]];\n\
    \  };\n\n  auto walk = [&](int v, const vc<int> &s) -> int {\n    for (int x :\
    \ s) v = step(v, x);\n    return v;\n  };\n\n  auto merge = [&](int p, int q)\
    \ -> void {\n    vc<pair<int, int>> que;\n    que.eb(p, q);\n    while (len(que))\
    \ {\n      auto [p, q] = POP(que);\n      p = uf[p], q = uf[q];\n      if (p ==\
    \ q) continue;\n      uf.merge(p, q);\n      int r = uf[p];\n      done[r] = done[p]\
    \ | done[q];\n      FOR(x, K) {\n        int a = T[p][x], b = T[q][x];\n     \
    \   T[r][x] = max(a, b);\n        if (a != -1 && b != -1) que.eb(a, b);\n    \
    \  }\n    }\n  };\n\n  add_vertex();\n  for (int p = 0; p < len(T); ++p) {\n \
    \   for (auto &[u, v] : R) merge(walk(p, u), walk(p, v));\n    FOR(x, K) step(p,\
    \ x);\n    done[uf[p]] = true;\n  }\n\n  // \u4EE3\u8868\u5143\u3060\u3051\u3092\
    \u6B8B\u3057\u3066\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u3064\u3051\u306A\
    \u304A\u3057\uFF0C\u9077\u79FB\u8868\u3092\u8FD4\u3059\n  vc<int> root;\n  FOR(v,\
    \ N) if (uf[v] == v) root.emplace_back(v);\n  int n = len(root);\n  vc<int> new_idx(N);\n\
    \  FOR(i, n) new_idx[root[i]] = i;\n  for (int v : root) {\n    FOR(x, K) T[v][x]\
    \ = new_idx[uf[T[v][x]]];\n  }\n  FOR(i, n) T[i] = T[root[i]];\n  T.resize(n);\n\
    \  return T;\n}"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: other/todd_coxeter.hpp
  requiredBy: []
  timestamp: '2026-10-24 10:36:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/todd_coxeter.hpp
layout: document
redirect_from:
- /library/other/todd_coxeter.hpp
- /library/other/todd_coxeter.hpp.html
title: other/todd_coxeter.hpp
---
