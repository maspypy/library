---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/double_ended_q.test.cpp
    title: test/library_checker/datastructure/double_ended_q.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/double_end_queue.hpp\"\n// T \u306F operator< \u3092\u6301\
    \u3064\ntemplate <typename T>\nstruct Double_End_Queue {\n  // interval heap\n\
    \  // \u5B50\u3088\u308A\u3082\u89AA\u306E\u65B9\u304C\u5927\u304D\u306A\u533A\
    \u9593\u3092\u4F5C\u308B\u3088\u3046\u306B\u3059\u308B\n  // \u5947\u6570\u8981\
    \u7D20\u306E\u3068\u304D\u306F [a,a] \u3068\u3044\u3046\u533A\u9593\u304C\u3042\
    \u308B\u3068\u601D\u3046\n  // \u3059\u308B\u3068\u6839\u306E\u533A\u9593\u304C\
    \ min,max \u3092\u4E0E\u3048\u308B\n  vector<T> dat;\n\n  Double_End_Queue() {}\n\
    \  Double_End_Queue(vc<T>& A) { build(A); }\n\n  int size() { return dat.size();\
    \ }\n  bool empty() { return dat.empty(); }\n  T min() { return dat[0]; }\n  T\
    \ max() { return len(dat) == 1 ? dat[0] : dat[1]; }\n\n  void build(vc<T>& A)\
    \ {\n    dat = A;\n    int n = len(dat);\n    FOR_R(i, n) { down(i); }\n  }\n\n\
    \  void push(T x) { dat.eb(x), up(); }\n\n  T pop_min() {\n    assert(!dat.empty());\n\
    \    swap(dat[0], dat.back());\n    T res = POP(dat);\n    down(0);\n    return\
    \ res;\n  }\n\n  T pop_max() {\n    assert(!dat.empty());\n    if (len(dat) <=\
    \ 2) { return POP(dat); }\n    swap(dat[1], dat.back());\n    T res = POP(dat);\n\
    \    down(1);\n    return res;\n  }\n\n  void debug() {\n    print(\"debug dat=\"\
    , dat);\n    FOR(i, len(dat) - 1) if (i % 2 == 0) assert(!(dat[i + 1] < dat[i]));\n\
    \    FOR(i, 1, ceil<int>(len(dat), 2)) {\n      int p = (i - 1) / 2;\n      T\
    \ a = dat[2 * p + 0], b = dat[2 * p + 1];\n      T c = dat[2 * i + 0];\n     \
    \ T d = (2 * i + 1 >= len(dat) ? dat.back() : dat[2 * i + 1]);\n      assert(a\
    \ <= c && c <= d && d <= b);\n    }\n    print(\"heap condition ok\");\n  }\n\n\
    private:\n  inline int parent(int i) { return (i - 4 + (i & 3)) / 2; }\n\n  void\
    \ down(int i) {\n    int n = len(dat);\n    if (i % 2 == 0) {\n      while (1)\
    \ {\n        if (i + 1 < n && dat[i + 1] < dat[i]) swap(dat[i], dat[i + 1]);\n\
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
  code: "// T \u306F operator< \u3092\u6301\u3064\ntemplate <typename T>\nstruct Double_End_Queue\
    \ {\n  // interval heap\n  // \u5B50\u3088\u308A\u3082\u89AA\u306E\u65B9\u304C\
    \u5927\u304D\u306A\u533A\u9593\u3092\u4F5C\u308B\u3088\u3046\u306B\u3059\u308B\
    \n  // \u5947\u6570\u8981\u7D20\u306E\u3068\u304D\u306F [a,a] \u3068\u3044\u3046\
    \u533A\u9593\u304C\u3042\u308B\u3068\u601D\u3046\n  // \u3059\u308B\u3068\u6839\
    \u306E\u533A\u9593\u304C min,max \u3092\u4E0E\u3048\u308B\n  vector<T> dat;\n\n\
    \  Double_End_Queue() {}\n  Double_End_Queue(vc<T>& A) { build(A); }\n\n  int\
    \ size() { return dat.size(); }\n  bool empty() { return dat.empty(); }\n  T min()\
    \ { return dat[0]; }\n  T max() { return len(dat) == 1 ? dat[0] : dat[1]; }\n\n\
    \  void build(vc<T>& A) {\n    dat = A;\n    int n = len(dat);\n    FOR_R(i, n)\
    \ { down(i); }\n  }\n\n  void push(T x) { dat.eb(x), up(); }\n\n  T pop_min()\
    \ {\n    assert(!dat.empty());\n    swap(dat[0], dat.back());\n    T res = POP(dat);\n\
    \    down(0);\n    return res;\n  }\n\n  T pop_max() {\n    assert(!dat.empty());\n\
    \    if (len(dat) <= 2) { return POP(dat); }\n    swap(dat[1], dat.back());\n\
    \    T res = POP(dat);\n    down(1);\n    return res;\n  }\n\n  void debug() {\n\
    \    print(\"debug dat=\", dat);\n    FOR(i, len(dat) - 1) if (i % 2 == 0) assert(!(dat[i\
    \ + 1] < dat[i]));\n    FOR(i, 1, ceil<int>(len(dat), 2)) {\n      int p = (i\
    \ - 1) / 2;\n      T a = dat[2 * p + 0], b = dat[2 * p + 1];\n      T c = dat[2\
    \ * i + 0];\n      T d = (2 * i + 1 >= len(dat) ? dat.back() : dat[2 * i + 1]);\n\
    \      assert(a <= c && c <= d && d <= b);\n    }\n    print(\"heap condition\
    \ ok\");\n  }\n\nprivate:\n  inline int parent(int i) { return (i - 4 + (i & 3))\
    \ / 2; }\n\n  void down(int i) {\n    int n = len(dat);\n    if (i % 2 == 0) {\n\
    \      while (1) {\n        if (i + 1 < n && dat[i + 1] < dat[i]) swap(dat[i],\
    \ dat[i + 1]);\n        int j = i, l = 2 * i + 2, r = 2 * i + 4;\n        if (l\
    \ < n && dat[l] < dat[j]) j = l;\n        if (r < n && dat[r] < dat[j]) j = r;\n\
    \        if (i == j) break;\n        swap(dat[i], dat[j]), i = j;\n      }\n \
    \   } else {\n      while (1) {\n        if (dat[i] < dat[i - 1]) swap(dat[i -\
    \ 1], dat[i]);\n        int j = i, l = 2 * i + 1, r = 2 * i + 3;\n        if (r\
    \ >= n) --r;\n        if (l >= n) --l;\n        if (l < n && dat[j] < dat[l])\
    \ j = l;\n        if (r < n && dat[j] < dat[r]) j = r;\n        if (i == j) break;\n\
    \        swap(dat[i], dat[j]), i = j;\n        if (i % 2 == 0) break;\n      }\n\
    \    }\n  }\n\n  void up() {\n    int i = len(dat) - 1;\n    if (2 <= i && i %\
    \ 2 == 0) {\n      int p = parent(i) ^ 1;\n      if (dat[p] < dat[i]) { swap(dat[i],\
    \ dat[p]), i = p; }\n    }\n    if (i % 2 == 1 && dat[i] < dat[i - 1]) { swap(dat[i\
    \ - 1], dat[i]), --i; }\n    if (i % 2 == 0) {\n      while (i >= 2) {\n     \
    \   int p = parent(i);\n        if (!(dat[i] < dat[p])) break;\n        swap(dat[p],\
    \ dat[i]), i = p;\n      }\n      return;\n    }\n    while (i >= 3) {\n     \
    \ int p = parent(i);\n      if (!(dat[p] < dat[i])) break;\n      swap(dat[p],\
    \ dat[i]), i = p;\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/double_end_queue.hpp
  requiredBy: []
  timestamp: '2024-07-18 10:54:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/double_ended_q.test.cpp
documentation_of: ds/double_end_queue.hpp
layout: document
redirect_from:
- /library/ds/double_end_queue.hpp
- /library/ds/double_end_queue.hpp.html
title: ds/double_end_queue.hpp
---
