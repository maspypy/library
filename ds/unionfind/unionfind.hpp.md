---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n;\n  int n_comp;\n  std::vector<int> size, par;\n  UnionFind(int n) : n(n),\
    \ n_comp(n), size(n, 1), par(n) {\n    std::iota(par.begin(), par.end(), 0);\n\
    \  }\n  int find(int x) {\n    assert(0 <= x && x < n);\n    while (par[x] !=\
    \ x) { x = par[x] = par[par[x]]; }\n    return x;\n  }\n\n  int operator[](int\
    \ x) { return find(x); }\n\n  bool merge(int x, int y) {\n    x = find(x);\n \
    \   y = find(y);\n    if (x == y) { return false; }\n    n_comp--;\n    if (size[x]\
    \ < size[y]) std::swap(x, y);\n    size[x] += size[y];\n    size[y] = 0;\n   \
    \ par[y] = x;\n    return true;\n  }\n\n  std::vector<int> find_all() {\n    std::vector<int>\
    \ A(n);\n    for (int i = 0; i < n; ++i) A[i] = find(i);\n    return A;\n  }\n\
    \n  void reset() {\n    n_comp = n;\n    size.assign(n, 1);\n    std::iota(par.begin(),\
    \ par.end(), 0);\n  }\n};\n"
  code: "#pragma once\n\nstruct UnionFind {\n  int n;\n  int n_comp;\n  std::vector<int>\
    \ size, par;\n  UnionFind(int n) : n(n), n_comp(n), size(n, 1), par(n) {\n   \
    \ std::iota(par.begin(), par.end(), 0);\n  }\n  int find(int x) {\n    assert(0\
    \ <= x && x < n);\n    while (par[x] != x) { x = par[x] = par[par[x]]; }\n   \
    \ return x;\n  }\n\n  int operator[](int x) { return find(x); }\n\n  bool merge(int\
    \ x, int y) {\n    x = find(x);\n    y = find(y);\n    if (x == y) { return false;\
    \ }\n    n_comp--;\n    if (size[x] < size[y]) std::swap(x, y);\n    size[x] +=\
    \ size[y];\n    size[y] = 0;\n    par[y] = x;\n    return true;\n  }\n\n  std::vector<int>\
    \ find_all() {\n    std::vector<int> A(n);\n    for (int i = 0; i < n; ++i) A[i]\
    \ = find(i);\n    return A;\n  }\n\n  void reset() {\n    n_comp = n;\n    size.assign(n,\
    \ 1);\n    std::iota(par.begin(), par.end(), 0);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/unionfind/unionfind.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/unionfind/unionfind.hpp
layout: document
redirect_from:
- /library/ds/unionfind/unionfind.hpp
- /library/ds/unionfind/unionfind.hpp.html
title: ds/unionfind/unionfind.hpp
---
