---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/892/problem/E
  bundledCode: "#line 1 \"pds/rollbackunionfind.hpp\"\n// https://codeforces.com/contest/892/problem/E\r\
    \nstruct RollbackUnionFind {\r\n  vc<int> dat; // parent or size\r\n  vc<pair<int,\
    \ int>> st;\r\n\r\n  RollbackUnionFind(int n) : dat(n, -1) {}\r\n\r\n  int operator[](int\
    \ v) {\r\n    while (dat[v] >= 0) v = dat[v];\r\n    return v;\r\n  }\r\n\r\n\
    \  int size(int v) { return -dat[(*this)[v]]; }\r\n  int time() { return len(st);\
    \ }\r\n  void rollback(int t) {\r\n    for (int i = time(); i-- > t;) { dat[st[i].fi]\
    \ = st[i].se; }\r\n    st.resize(t);\r\n  }\r\n  bool merge(int a, int b) {\r\n\
    \    a = (*this)[a], b = (*this)[b];\r\n    if (a == b) return false;\r\n    if\
    \ (dat[a] > dat[b]) swap(a, b);\r\n    st.eb(a, dat[a]);\r\n    st.eb(b, dat[b]);\r\
    \n    dat[a] += dat[b];\r\n    dat[b] = a;\r\n    return true;\r\n  }\r\n};\r\n"
  code: "// https://codeforces.com/contest/892/problem/E\r\nstruct RollbackUnionFind\
    \ {\r\n  vc<int> dat; // parent or size\r\n  vc<pair<int, int>> st;\r\n\r\n  RollbackUnionFind(int\
    \ n) : dat(n, -1) {}\r\n\r\n  int operator[](int v) {\r\n    while (dat[v] >=\
    \ 0) v = dat[v];\r\n    return v;\r\n  }\r\n\r\n  int size(int v) { return -dat[(*this)[v]];\
    \ }\r\n  int time() { return len(st); }\r\n  void rollback(int t) {\r\n    for\
    \ (int i = time(); i-- > t;) { dat[st[i].fi] = st[i].se; }\r\n    st.resize(t);\r\
    \n  }\r\n  bool merge(int a, int b) {\r\n    a = (*this)[a], b = (*this)[b];\r\
    \n    if (a == b) return false;\r\n    if (dat[a] > dat[b]) swap(a, b);\r\n  \
    \  st.eb(a, dat[a]);\r\n    st.eb(b, dat[b]);\r\n    dat[a] += dat[b];\r\n   \
    \ dat[b] = a;\r\n    return true;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: pds/rollbackunionfind.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: pds/rollbackunionfind.hpp
layout: document
redirect_from:
- /library/pds/rollbackunionfind.hpp
- /library/pds/rollbackunionfind.hpp.html
title: pds/rollbackunionfind.hpp
---
