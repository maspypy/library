---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/segment_add_get_min.test.cpp
    title: test/library_checker/datastructure/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/lichao.hpp\"\ntemplate <typename T>\r\nstruct LiChaoTree\
    \ {\r\n  struct Line {\r\n    T a, b;\r\n    Line(T a, T b) : a(a), b(b) {}\r\n\
    \    inline T eval(T x) const { return a * x + b; }\r\n    inline bool over(const\
    \ Line &other, const T &x) const {\r\n      return eval(x) < other.eval(x);\r\n\
    \    }\r\n  };\r\n\r\n  vector<T> xs;\r\n  vector<Line> seg;\r\n  int size;\r\n\
    \  const T INF;\r\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3002\u30AF\
    \u30A8\u30EA\u306E\u6765\u308B x \u5168\u4F53\u3092\u6E21\u3059\u3002\u30BD\u30FC\
    \u30C8\u4E0D\u8981\u3002\r\n  LiChaoTree(const vector<T> &_xs, T INF = numeric_limits<T>::max()\
    \ / 2)\r\n      : xs(_xs), INF(INF) {\r\n    if (len(xs) == 0) xs.eb(0);\r\n \
    \   UNIQUE(xs);\r\n    size = 1;\r\n    while (size < len(xs)) size *= 2;\r\n\
    \    while (len(xs) < size) xs.eb(xs.back());\r\n    seg.assign(2 * size, Line(0,\
    \ INF));\r\n  }\r\n\r\n  // y = ax + b\u306A\u308B\u76F4\u7DDA\u3092\u8FFD\u52A0\
    \r\n  void add(T a, T b) { inner_update(a, b, 0, size, 1); }\r\n\r\n  // [lx,\
    \ rx) \u306B\u7DDA\u5206 y = ax + b \u3092\u8FFD\u52A0\r\n  void add(T lx, T rx,\
    \ T a, T b) {\r\n    int l = LB(xs, lx) + size;\r\n    int r = LB(xs, rx) + size;\r\
    \n    while (l < r) {\r\n      if (l & 1) inner_update(a, b, l++);\r\n      if\
    \ (r & 1) inner_update(a, b, --r);\r\n      l >>= 1, r >>= 1;\r\n    }\r\n  }\r\
    \n\r\n  T get_min(T x) {\r\n    int i = LB(xs, x);\r\n    assert(xs[i] == x);\r\
    \n    return inner_query(x, i + size);\r\n  }\r\n\r\n  T get_min_by_idx(int i)\
    \ { return inner_query(xs[i], i + size); }\r\n\r\n  void debug() {\r\n    print(\"\
    xs\", xs);\r\n    print(\"seg\");\r\n    FOR(i, len(seg)) print(i, seg[i].a, seg[i].b);\r\
    \n  }\r\n\r\nprivate:\r\n  void inner_update(T a, T b, int l, int r, int idx)\
    \ {\r\n    Line line(a, b);\r\n    while (1) {\r\n      int m = (l + r) >> 1;\r\
    \n      bool l_over = line.over(seg[idx], xs[l]);\r\n      bool r_over = line.over(seg[idx],\
    \ xs[r - 1]);\r\n      if (l_over == r_over) {\r\n        if (l_over) swap(seg[idx],\
    \ line);\r\n        return;\r\n      }\r\n      bool m_over = line.over(seg[idx],\
    \ xs[m]);\r\n      if (m_over) swap(seg[idx], line);\r\n      if (l_over != m_over)\r\
    \n        idx = (idx << 1) | 0, r = m;\r\n      else\r\n        idx = (idx <<\
    \ 1) | 1, l = m;\r\n    }\r\n  }\r\n\r\n  void inner_update(T a, T b, int seg_idx)\
    \ {\r\n    int left, right;\r\n    int upper_bit = 31 - __builtin_clz(seg_idx);\r\
    \n    left = (size >> upper_bit) * (seg_idx - (1 << upper_bit));\r\n    right\
    \ = left + (size >> upper_bit);\r\n    inner_update(a, b, left, right, seg_idx);\r\
    \n  }\r\n\r\n  T inner_query(T x, int idx) {\r\n    T ret = INF;\r\n    while\
    \ (idx >= 1) {\r\n      chmin(ret, seg[idx].eval(x));\r\n      idx >>= 1;\r\n\
    \    }\r\n    return ret;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\ntemplate <typename T>\r\nstruct LiChaoTree {\r\n  struct\
    \ Line {\r\n    T a, b;\r\n    Line(T a, T b) : a(a), b(b) {}\r\n    inline T\
    \ eval(T x) const { return a * x + b; }\r\n    inline bool over(const Line &other,\
    \ const T &x) const {\r\n      return eval(x) < other.eval(x);\r\n    }\r\n  };\r\
    \n\r\n  vector<T> xs;\r\n  vector<Line> seg;\r\n  int size;\r\n  const T INF;\r\
    \n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3002\u30AF\u30A8\u30EA\u306E\
    \u6765\u308B x \u5168\u4F53\u3092\u6E21\u3059\u3002\u30BD\u30FC\u30C8\u4E0D\u8981\
    \u3002\r\n  LiChaoTree(const vector<T> &_xs, T INF = numeric_limits<T>::max()\
    \ / 2)\r\n      : xs(_xs), INF(INF) {\r\n    if (len(xs) == 0) xs.eb(0);\r\n \
    \   UNIQUE(xs);\r\n    size = 1;\r\n    while (size < len(xs)) size *= 2;\r\n\
    \    while (len(xs) < size) xs.eb(xs.back());\r\n    seg.assign(2 * size, Line(0,\
    \ INF));\r\n  }\r\n\r\n  // y = ax + b\u306A\u308B\u76F4\u7DDA\u3092\u8FFD\u52A0\
    \r\n  void add(T a, T b) { inner_update(a, b, 0, size, 1); }\r\n\r\n  // [lx,\
    \ rx) \u306B\u7DDA\u5206 y = ax + b \u3092\u8FFD\u52A0\r\n  void add(T lx, T rx,\
    \ T a, T b) {\r\n    int l = LB(xs, lx) + size;\r\n    int r = LB(xs, rx) + size;\r\
    \n    while (l < r) {\r\n      if (l & 1) inner_update(a, b, l++);\r\n      if\
    \ (r & 1) inner_update(a, b, --r);\r\n      l >>= 1, r >>= 1;\r\n    }\r\n  }\r\
    \n\r\n  T get_min(T x) {\r\n    int i = LB(xs, x);\r\n    assert(xs[i] == x);\r\
    \n    return inner_query(x, i + size);\r\n  }\r\n\r\n  T get_min_by_idx(int i)\
    \ { return inner_query(xs[i], i + size); }\r\n\r\n  void debug() {\r\n    print(\"\
    xs\", xs);\r\n    print(\"seg\");\r\n    FOR(i, len(seg)) print(i, seg[i].a, seg[i].b);\r\
    \n  }\r\n\r\nprivate:\r\n  void inner_update(T a, T b, int l, int r, int idx)\
    \ {\r\n    Line line(a, b);\r\n    while (1) {\r\n      int m = (l + r) >> 1;\r\
    \n      bool l_over = line.over(seg[idx], xs[l]);\r\n      bool r_over = line.over(seg[idx],\
    \ xs[r - 1]);\r\n      if (l_over == r_over) {\r\n        if (l_over) swap(seg[idx],\
    \ line);\r\n        return;\r\n      }\r\n      bool m_over = line.over(seg[idx],\
    \ xs[m]);\r\n      if (m_over) swap(seg[idx], line);\r\n      if (l_over != m_over)\r\
    \n        idx = (idx << 1) | 0, r = m;\r\n      else\r\n        idx = (idx <<\
    \ 1) | 1, l = m;\r\n    }\r\n  }\r\n\r\n  void inner_update(T a, T b, int seg_idx)\
    \ {\r\n    int left, right;\r\n    int upper_bit = 31 - __builtin_clz(seg_idx);\r\
    \n    left = (size >> upper_bit) * (seg_idx - (1 << upper_bit));\r\n    right\
    \ = left + (size >> upper_bit);\r\n    inner_update(a, b, left, right, seg_idx);\r\
    \n  }\r\n\r\n  T inner_query(T x, int idx) {\r\n    T ret = INF;\r\n    while\
    \ (idx >= 1) {\r\n      chmin(ret, seg[idx].eval(x));\r\n      idx >>= 1;\r\n\
    \    }\r\n    return ret;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/lichao.hpp
  requiredBy: []
  timestamp: '2022-12-15 05:37:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/segment_add_get_min.test.cpp
documentation_of: convex/lichao.hpp
layout: document
redirect_from:
- /library/convex/lichao.hpp
- /library/convex/lichao.hpp.html
title: convex/lichao.hpp
---
