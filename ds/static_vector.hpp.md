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
  bundledCode: "#line 1 \"ds/static_vector.hpp\"\n// \u56FA\u5B9A\u306E\u30B5\u30A4\
    \u30BA\u4E0A\u9650\u3092\u3082\u3064 vector\ntemplate <typename T, int N>\nstruct\
    \ Static_Vector {\n  array<T, N> dat;\n  int n = 0;\n\n  int size() const { return\
    \ n; }\n  bool empty() const { return n == 0; }\n\n  T& operator[](int i) { return\
    \ dat[i]; }\n  const T& operator[](int i) const { return dat[i]; }\n\n  void push_back(const\
    \ T& x) { dat[n++] = x; }\n  void push_back(T&& x) { dat[n++] = move(x); }\n\n\
    \  template <typename... Args>\n  T& emplace_back(Args&&... args) {\n    return\
    \ dat[n++] = T(forward<Args>(args)...);\n  }\n\n  auto begin() { return dat.begin();\
    \ }\n  auto end() { return dat.begin() + n; }\n  auto begin() const { return dat.begin();\
    \ }\n  auto end() const { return dat.begin() + n; }\n  void clear() { n = 0; }\n\
    \  using iterator = typename array<T, N>::iterator;\n  iterator insert(iterator\
    \ pos, const T& x) {\n    assert(n < N);\n    int k = pos - begin();\n    dat[n++]\
    \ = x;\n    rotate(begin() + k, end() - 1, end());\n    return begin() + k;\n\
    \  }\n};\n"
  code: "// \u56FA\u5B9A\u306E\u30B5\u30A4\u30BA\u4E0A\u9650\u3092\u3082\u3064 vector\n\
    template <typename T, int N>\nstruct Static_Vector {\n  array<T, N> dat;\n  int\
    \ n = 0;\n\n  int size() const { return n; }\n  bool empty() const { return n\
    \ == 0; }\n\n  T& operator[](int i) { return dat[i]; }\n  const T& operator[](int\
    \ i) const { return dat[i]; }\n\n  void push_back(const T& x) { dat[n++] = x;\
    \ }\n  void push_back(T&& x) { dat[n++] = move(x); }\n\n  template <typename...\
    \ Args>\n  T& emplace_back(Args&&... args) {\n    return dat[n++] = T(forward<Args>(args)...);\n\
    \  }\n\n  auto begin() { return dat.begin(); }\n  auto end() { return dat.begin()\
    \ + n; }\n  auto begin() const { return dat.begin(); }\n  auto end() const { return\
    \ dat.begin() + n; }\n  void clear() { n = 0; }\n  using iterator = typename array<T,\
    \ N>::iterator;\n  iterator insert(iterator pos, const T& x) {\n    assert(n <\
    \ N);\n    int k = pos - begin();\n    dat[n++] = x;\n    rotate(begin() + k,\
    \ end() - 1, end());\n    return begin() + k;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/static_vector.hpp
  requiredBy: []
  timestamp: '2026-08-09 03:02:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/static_vector.hpp
layout: document
redirect_from:
- /library/ds/static_vector.hpp
- /library/ds/static_vector.hpp.html
title: ds/static_vector.hpp
---
