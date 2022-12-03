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
  bundledCode: "#line 2 \"ds/union_find/union_find.hpp\"\n\nstruct Union_Find {\n\
    \  int n;\n  int n_comp;\n  vector<int> dat; // par or (-size)\n  Union_Find(int\
    \ n) : n(n), n_comp(n), dat(n, -1) {}\n\n  int operator[](int x) {\n    while\
    \ (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x];\
    \ }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  int size(int x) {\n\
    \    assert(dat[x] < 0);\n    return -dat[x];\n  }\n\n  bool merge(int x, int\
    \ y) {\n    x = (*this)[x];\n    y = (*this)[y];\n    if (x == y) { return false;\
    \ }\n    n_comp--;\n    if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y],\
    \ dat[y] = x;\n    return true;\n  }\n\n  vector<int> get_all() {\n    vector<int>\
    \ A(n);\n    for (int i = 0; i < n; ++i) A[i] = (*this)[i];\n    return A;\n \
    \ }\n};\n"
  code: "#pragma once\n\nstruct Union_Find {\n  int n;\n  int n_comp;\n  vector<int>\
    \ dat; // par or (-size)\n  Union_Find(int n) : n(n), n_comp(n), dat(n, -1) {}\n\
    \n  int operator[](int x) {\n    while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n\
    \      if (pp < 0) { return dat[x]; }\n      x = dat[x] = pp;\n    }\n    return\
    \ x;\n  }\n\n  int size(int x) {\n    assert(dat[x] < 0);\n    return -dat[x];\n\
    \  }\n\n  bool merge(int x, int y) {\n    x = (*this)[x];\n    y = (*this)[y];\n\
    \    if (x == y) { return false; }\n    n_comp--;\n    if (-dat[x] < -dat[y])\
    \ swap(x, y);\n    dat[x] += dat[y], dat[y] = x;\n    return true;\n  }\n\n  vector<int>\
    \ get_all() {\n    vector<int> A(n);\n    for (int i = 0; i < n; ++i) A[i] = (*this)[i];\n\
    \    return A;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/union_find/union_find.hpp
  requiredBy: []
  timestamp: '2022-12-03 09:59:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/union_find/union_find.hpp
layout: document
redirect_from:
- /library/ds/union_find/union_find.hpp
- /library/ds/union_find/union_find.hpp.html
title: ds/union_find/union_find.hpp
---
