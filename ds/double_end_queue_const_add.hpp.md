---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convex/slope_trick/slope_trick_1.hpp
    title: convex/slope_trick/slope_trick_1.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1077_2.test.cpp
    title: test/3_yukicoder/1077_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/double_end_queue_const_add.hpp\"\n// \u5168\u4F53\u52A0\
    \u7B97\u3082\u3067\u304D\u308B\u3088\u3046\u306B\u3057\u3088\u3046\n// Monoid_Add<T>\
    \ \u3092\u6E21\u3059\u611F\u3058\u3067. T \u306F operator< \u304C\u5B9A\u7FA9\u3055\
    \u308C\u3066\u3044\u308B\u5FC5\u8981\u3042\u308A.\ntemplate <typename Monoid>\n\
    struct Double_End_Queue_Const_Add {\n  using MX = Monoid;\n  using T = typename\
    \ MX::value_type;\n  vector<T> dat;\n  T add;\n\n  Double_End_Queue_Const_Add()\
    \ : add(MX::unit()) {}\n  Double_End_Queue_Const_Add(vc<T>& A) : add(MX::unit())\
    \ { build(A); }\n\n  int size() { return dat.size(); }\n  bool empty() { return\
    \ dat.empty(); }\n  T min() { return MX::op(dat[0], add); }\n  T max() { return\
    \ MX::op(add, (len(dat) == 1 ? dat[0] : dat[1])); }\n\n  void build(vc<T>& A)\
    \ {\n    add = MX::unit();\n    dat = A;\n    int n = len(dat);\n    FOR_R(i,\
    \ n) { down(i); }\n  }\n  void clear() {\n    dat.clear(), dat.shrink_to_fit();\n\
    \    add = 0;\n  }\n\n  void push(T x) { dat.eb(x - add), up(); }\n\n  T pop_min()\
    \ {\n    assert(!dat.empty());\n    swap(dat[0], dat.back());\n    T res = POP(dat);\n\
    \    down(0);\n    return res + add;\n  }\n\n  T pop_max() {\n    assert(!dat.empty());\n\
    \    if (len(dat) <= 2) { return POP(dat) + add; }\n    swap(dat[1], dat.back());\n\
    \    T res = POP(dat);\n    down(1);\n    return res + add;\n  }\n\n  template\
    \ <typename F>\n  void enumerate_all(F f) {\n    for (auto& x: dat) f(x + add);\n\
    \  }\n\nprivate:\n  inline int parent(int i) { return (i - 4 + (i & 3)) / 2; }\n\
    \n  void down(int i) {\n    int n = len(dat);\n    if (i % 2 == 0) {\n      while\
    \ (1) {\n        if (i + 1 < n && dat[i + 1] < dat[i]) swap(dat[i], dat[i + 1]);\n\
    \        int j = i, l = 2 * i + 2, r = 2 * i + 4;\n        if (l < n && dat[l]\
    \ < dat[j]) j = l;\n        if (r < n && dat[r] < dat[j]) j = r;\n        if (i\
    \ == j) break;\n        swap(dat[i], dat[j]), i = j;\n      }\n    } else {\n\
    \      while (1) {\n        if (dat[i] < dat[i - 1]) swap(dat[i - 1], dat[i]);\n\
    \        int j = i, l = 2 * i + 1, r = 2 * i + 3;\n        if (r >= n) --r;\n\
    \        if (l >= n) --l;\n        if (l < n && dat[j] < dat[l]) j = l;\n    \
    \    if (r < n && dat[j] < dat[r]) j = r;\n        if (i == j) break;\n      \
    \  swap(dat[i], dat[j]), i = j;\n        if (i % 2 == 0) break;\n      }\n   \
    \ }\n  }\n\n  void up() {\n    int i = len(dat) - 1;\n    if (2 <= i && i % 2\
    \ == 0) {\n      int p = parent(i) ^ 1;\n      if (dat[p] < dat[i]) { swap(dat[i],\
    \ dat[p]), i = p; }\n    }\n    if (i % 2 == 1 && dat[i] < dat[i - 1]) { swap(dat[i\
    \ - 1], dat[i]), --i; }\n    if (i % 2 == 0) {\n      while (i >= 2) {\n     \
    \   int p = parent(i);\n        if (!(dat[i] < dat[p])) break;\n        swap(dat[p],\
    \ dat[i]), i = p;\n      }\n      return;\n    }\n    while (i >= 3) {\n     \
    \ int p = parent(i);\n      if (!(dat[p] < dat[i])) break;\n      swap(dat[p],\
    \ dat[i]), i = p;\n    }\n  }\n};\n"
  code: "// \u5168\u4F53\u52A0\u7B97\u3082\u3067\u304D\u308B\u3088\u3046\u306B\u3057\
    \u3088\u3046\n// Monoid_Add<T> \u3092\u6E21\u3059\u611F\u3058\u3067. T \u306F\
    \ operator< \u304C\u5B9A\u7FA9\u3055\u308C\u3066\u3044\u308B\u5FC5\u8981\u3042\
    \u308A.\ntemplate <typename Monoid>\nstruct Double_End_Queue_Const_Add {\n  using\
    \ MX = Monoid;\n  using T = typename MX::value_type;\n  vector<T> dat;\n  T add;\n\
    \n  Double_End_Queue_Const_Add() : add(MX::unit()) {}\n  Double_End_Queue_Const_Add(vc<T>&\
    \ A) : add(MX::unit()) { build(A); }\n\n  int size() { return dat.size(); }\n\
    \  bool empty() { return dat.empty(); }\n  T min() { return MX::op(dat[0], add);\
    \ }\n  T max() { return MX::op(add, (len(dat) == 1 ? dat[0] : dat[1])); }\n\n\
    \  void build(vc<T>& A) {\n    add = MX::unit();\n    dat = A;\n    int n = len(dat);\n\
    \    FOR_R(i, n) { down(i); }\n  }\n  void clear() {\n    dat.clear(), dat.shrink_to_fit();\n\
    \    add = 0;\n  }\n\n  void push(T x) { dat.eb(x - add), up(); }\n\n  T pop_min()\
    \ {\n    assert(!dat.empty());\n    swap(dat[0], dat.back());\n    T res = POP(dat);\n\
    \    down(0);\n    return res + add;\n  }\n\n  T pop_max() {\n    assert(!dat.empty());\n\
    \    if (len(dat) <= 2) { return POP(dat) + add; }\n    swap(dat[1], dat.back());\n\
    \    T res = POP(dat);\n    down(1);\n    return res + add;\n  }\n\n  template\
    \ <typename F>\n  void enumerate_all(F f) {\n    for (auto& x: dat) f(x + add);\n\
    \  }\n\nprivate:\n  inline int parent(int i) { return (i - 4 + (i & 3)) / 2; }\n\
    \n  void down(int i) {\n    int n = len(dat);\n    if (i % 2 == 0) {\n      while\
    \ (1) {\n        if (i + 1 < n && dat[i + 1] < dat[i]) swap(dat[i], dat[i + 1]);\n\
    \        int j = i, l = 2 * i + 2, r = 2 * i + 4;\n        if (l < n && dat[l]\
    \ < dat[j]) j = l;\n        if (r < n && dat[r] < dat[j]) j = r;\n        if (i\
    \ == j) break;\n        swap(dat[i], dat[j]), i = j;\n      }\n    } else {\n\
    \      while (1) {\n        if (dat[i] < dat[i - 1]) swap(dat[i - 1], dat[i]);\n\
    \        int j = i, l = 2 * i + 1, r = 2 * i + 3;\n        if (r >= n) --r;\n\
    \        if (l >= n) --l;\n        if (l < n && dat[j] < dat[l]) j = l;\n    \
    \    if (r < n && dat[j] < dat[r]) j = r;\n        if (i == j) break;\n      \
    \  swap(dat[i], dat[j]), i = j;\n        if (i % 2 == 0) break;\n      }\n   \
    \ }\n  }\n\n  void up() {\n    int i = len(dat) - 1;\n    if (2 <= i && i % 2\
    \ == 0) {\n      int p = parent(i) ^ 1;\n      if (dat[p] < dat[i]) { swap(dat[i],\
    \ dat[p]), i = p; }\n    }\n    if (i % 2 == 1 && dat[i] < dat[i - 1]) { swap(dat[i\
    \ - 1], dat[i]), --i; }\n    if (i % 2 == 0) {\n      while (i >= 2) {\n     \
    \   int p = parent(i);\n        if (!(dat[i] < dat[p])) break;\n        swap(dat[p],\
    \ dat[i]), i = p;\n      }\n      return;\n    }\n    while (i >= 3) {\n     \
    \ int p = parent(i);\n      if (!(dat[p] < dat[i])) break;\n      swap(dat[p],\
    \ dat[i]), i = p;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/double_end_queue_const_add.hpp
  requiredBy:
  - convex/slope_trick/slope_trick_1.hpp
  timestamp: '2024-10-23 21:57:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1077_2.test.cpp
documentation_of: ds/double_end_queue_const_add.hpp
layout: document
redirect_from:
- /library/ds/double_end_queue_const_add.hpp
- /library/ds/double_end_queue_const_add.hpp.html
title: ds/double_end_queue_const_add.hpp
---
