---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/offline_query/offline_set_intersection.hpp
    title: ds/offline_query/offline_set_intersection.hpp
  - icon: ':warning:'
    path: graph/degree_sequence.hpp
    title: graph/degree_sequence.hpp
  - icon: ':warning:'
    path: string/enumerate_occurrence.hpp
    title: string/enumerate_occurrence.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/csr.hpp\"\n\ntemplate <typename T>\nstruct CSR {\n  int\
    \ n;\n  bool prepared;\n  vc<int> ptr;\n  vc<int> I;\n  vc<T> dat;\n\n  CSR(int\
    \ n = 0) : n(n), prepared(false) {}\n  void reserve(int n) { dat.reserve(n); }\n\
    \n  void add(int i, const T& x) {\n    assert(0 <= i && i < n && !prepared);\n\
    \    I.eb(i), dat.eb(x);\n  }\n\n  void build() {\n    assert(!prepared);\n  \
    \  prepared = 1;\n    ptr.assign(n + 1, 0);\n    for (auto& i : I) ptr[1 + i]++;\n\
    \    FOR(i, len(ptr) - 1) ptr[i + 1] += ptr[i];\n    vc<T> tmp(len(dat));\n  \
    \  FOR(k, len(dat)) {\n      int i = I[k];\n      tmp[ptr[i]++] = dat[k];\n  \
    \  }\n    swap(dat, tmp);\n    ptr.pop_back();\n    ptr.insert(ptr.begin(), 0);\n\
    \    I.clear();\n  }\n\n  struct range {\n    T *first, *last;\n    T* begin()\
    \ const { return first; }\n    T* end() const { return last; }\n    bool empty()\
    \ const { return first == last; }\n    int size() const { return last - first;\
    \ }\n  };\n\n  range operator[](int i) {\n    assert(prepared);\n    return range{dat.data()\
    \ + ptr[i], dat.data() + ptr[i + 1]};\n  }\n};\n"
  code: "\ntemplate <typename T>\nstruct CSR {\n  int n;\n  bool prepared;\n  vc<int>\
    \ ptr;\n  vc<int> I;\n  vc<T> dat;\n\n  CSR(int n = 0) : n(n), prepared(false)\
    \ {}\n  void reserve(int n) { dat.reserve(n); }\n\n  void add(int i, const T&\
    \ x) {\n    assert(0 <= i && i < n && !prepared);\n    I.eb(i), dat.eb(x);\n \
    \ }\n\n  void build() {\n    assert(!prepared);\n    prepared = 1;\n    ptr.assign(n\
    \ + 1, 0);\n    for (auto& i : I) ptr[1 + i]++;\n    FOR(i, len(ptr) - 1) ptr[i\
    \ + 1] += ptr[i];\n    vc<T> tmp(len(dat));\n    FOR(k, len(dat)) {\n      int\
    \ i = I[k];\n      tmp[ptr[i]++] = dat[k];\n    }\n    swap(dat, tmp);\n    ptr.pop_back();\n\
    \    ptr.insert(ptr.begin(), 0);\n    I.clear();\n  }\n\n  struct range {\n  \
    \  T *first, *last;\n    T* begin() const { return first; }\n    T* end() const\
    \ { return last; }\n    bool empty() const { return first == last; }\n    int\
    \ size() const { return last - first; }\n  };\n\n  range operator[](int i) {\n\
    \    assert(prepared);\n    return range{dat.data() + ptr[i], dat.data() + ptr[i\
    \ + 1]};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/csr.hpp
  requiredBy:
  - graph/degree_sequence.hpp
  - ds/offline_query/offline_set_intersection.hpp
  - string/enumerate_occurrence.hpp
  timestamp: '2026-08-01 03:11:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/csr.hpp
layout: document
redirect_from:
- /library/ds/csr.hpp
- /library/ds/csr.hpp.html
title: ds/csr.hpp
---
