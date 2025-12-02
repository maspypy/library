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
  bundledCode: "#line 1 \"ds/csr.hpp\"\n\ntemplate <typename T>\nstruct CSR {\n  int\
    \ n;\n  bool prepared;\n  vc<int> ptr;\n  vc<int> I;\n  vc<T> dat;\n\n  CSR(int\
    \ n = 0) : n(n), prepared(false) {}\n  void add(int i, const T& x) {\n    assert(0\
    \ <= i && i < n && !prepared);\n    I.eb(i), dat.eb(x);\n  }\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = 1;\n    ptr.assign(n + 1, 0);\n  \
    \  for (auto& i : I) ptr[1 + i]++;\n    FOR(i, len(ptr) - 1) ptr[i + 1] += ptr[i];\n\
    \    vc<T> tmp(len(dat));\n    FOR(k, len(dat)) {\n      int i = I[k];\n     \
    \ tmp[ptr[i]++] = dat[k];\n    }\n    swap(dat, tmp);\n    ptr.pop_back();\n \
    \   ptr.insert(ptr.begin(), 0);\n    I.clear(), I.shrink_to_fit();\n  }\n\n  struct\
    \ range {\n    T *first, *last;\n    T* begin() const { return first; }\n    T*\
    \ end() const { return last; }\n  };\n\n  range operator[](int i) {\n    assert(prepared);\n\
    \    return range{dat.data() + ptr[i], dat.data() + ptr[i + 1]};\n  }\n};\n"
  code: "\ntemplate <typename T>\nstruct CSR {\n  int n;\n  bool prepared;\n  vc<int>\
    \ ptr;\n  vc<int> I;\n  vc<T> dat;\n\n  CSR(int n = 0) : n(n), prepared(false)\
    \ {}\n  void add(int i, const T& x) {\n    assert(0 <= i && i < n && !prepared);\n\
    \    I.eb(i), dat.eb(x);\n  }\n\n  void build() {\n    assert(!prepared);\n  \
    \  prepared = 1;\n    ptr.assign(n + 1, 0);\n    for (auto& i : I) ptr[1 + i]++;\n\
    \    FOR(i, len(ptr) - 1) ptr[i + 1] += ptr[i];\n    vc<T> tmp(len(dat));\n  \
    \  FOR(k, len(dat)) {\n      int i = I[k];\n      tmp[ptr[i]++] = dat[k];\n  \
    \  }\n    swap(dat, tmp);\n    ptr.pop_back();\n    ptr.insert(ptr.begin(), 0);\n\
    \    I.clear(), I.shrink_to_fit();\n  }\n\n  struct range {\n    T *first, *last;\n\
    \    T* begin() const { return first; }\n    T* end() const { return last; }\n\
    \  };\n\n  range operator[](int i) {\n    assert(prepared);\n    return range{dat.data()\
    \ + ptr[i], dat.data() + ptr[i + 1]};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/csr.hpp
  requiredBy: []
  timestamp: '2025-12-02 17:14:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/csr.hpp
layout: document
redirect_from:
- /library/ds/csr.hpp
- /library/ds/csr.hpp.html
title: ds/csr.hpp
---
