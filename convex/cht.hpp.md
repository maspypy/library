---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/line_add_get_min.test.cpp
    title: test/2_library_checker/data_structure/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1297.test.cpp
    title: test/3_yukicoder/1297.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2012.test.cpp
    title: test/3_yukicoder/2012.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"convex/cht.hpp\"\nnamespace CHT {\r\ntemplate <typename\
    \ T>\r\nstruct Line {\r\n  mutable T k, m, p;\r\n  bool operator<(const Line&\
    \ o) const { return k < o.k; }\r\n  bool operator<(T x) const { return p < x;\
    \ }\r\n};\r\n\r\ntemplate <typename T>\r\nT lc_inf() {\r\n  return numeric_limits<T>::max();\r\
    \n}\r\ntemplate <>\r\nlong double lc_inf<long double>() {\r\n  return 1 / .0;\r\
    \n}\r\n\r\ntemplate <typename T>\r\nT lc_div(T a, T b) {\r\n  return a / b - ((a\
    \ ^ b) < 0 and a % b);\r\n}\r\ntemplate <>\r\nlong double lc_div(long double a,\
    \ long double b) {\r\n  return a / b;\r\n};\r\ntemplate <>\r\ndouble lc_div(double\
    \ a, double b) {\r\n  return a / b;\r\n};\r\n\r\ntemplate <typename T, bool MINIMIZE\
    \ = true>\r\nstruct LineContainer : multiset<Line<T>, less<>> {\r\n  using super\
    \ = multiset<Line<T>, less<>>;\r\n  using super::begin, super::end, super::insert,\
    \ super::erase;\r\n  using super::empty, super::lower_bound;\r\n  T inf = lc_inf<T>();\r\
    \n  bool insect(typename super::iterator x, typename super::iterator y) {\r\n\
    \    if (y == end()) return x->p = inf, false;\r\n    if (x->k == y->k)\r\n  \
    \    x->p = (x->m > y->m ? inf : -inf);\r\n    else\r\n      x->p = lc_div(y->m\
    \ - x->m, x->k - y->k);\r\n    return x->p >= y->p;\r\n  }\r\n  void add(T k,\
    \ T m) {\r\n    if (MINIMIZE) { k = -k, m = -m; }\r\n    auto z = insert({k, m,\
    \ 0}), y = z++, x = y;\r\n    while (insect(y, z)) z = erase(z);\r\n    if (x\
    \ != begin() and insect(--x, y)) insect(x, y = erase(y));\r\n    while ((y = x)\
    \ != begin() and (--x)->p >= y->p) insect(x, erase(y));\r\n  }\r\n  T query(T\
    \ x) {\r\n    assert(!empty());\r\n    auto l = *lower_bound(x);\r\n    T v =\
    \ (l.k * x + l.m);\r\n    return (MINIMIZE ? -v : v);\r\n  }\r\n};\r\n}; // namespace\
    \ CHT\r\n\r\nusing namespace CHT;\r\ntemplate <typename T>\r\nusing CHT_min =\
    \ LineContainer<T, true>;\r\ntemplate <typename T>\r\nusing CHT_max = LineContainer<T,\
    \ false>;\r\n\r\n/*\r\nlong long / double \u3067\u52D5\u304F\u3068\u601D\u3046\
    \u3002\u30AF\u30A8\u30EA\u3042\u305F\u308A O(log N)\r\n\u30FBadd(a, b, i=-1)\uFF1A\
    ax + by \u306E\u8FFD\u52A0 (index=i)\r\n\u30FBget_max(x,y)\uFF1A(ax + by,i)\r\n\
    \u30FBget_min(x,y)\uFF1A(ax + by,i)\r\n*/\r\ntemplate <typename T>\r\nstruct CHT_xy\
    \ {\r\n  static_assert(is_same_v<T, ll> || std::is_floating_point_v<T>);\r\n \
    \ using ld = long double;\r\n  CHT_min<ld> cht_min;\r\n  CHT_max<ld> cht_max;\r\
    \n  T amax = -infty<T>, amin = infty<T>;\r\n  T bmax = -infty<T>, bmin = infty<T>;\r\
    \n  int amax_idx = -1, amin_idx = -1;\r\n  int bmax_idx = -1, bmin_idx = -1;\r\
    \n  bool empty = true;\r\n  map<pair<T, T>, int> MP;\r\n\r\n  void clear() {\r\
    \n    empty = true;\r\n    cht_min.clear();\r\n    cht_max.clear();\r\n  }\r\n\
    \  void add(T a, T b, int i = -1) {\r\n    empty = false;\r\n    cht_min.add(b,\
    \ a);\r\n    cht_max.add(b, a);\r\n    pair<T, T> p = {a, b};\r\n    MP[p] = i;\r\
    \n\r\n    if (chmax(amax, a)) amax_idx = i;\r\n    if (chmin(amin, a)) amin_idx\
    \ = i;\r\n    if (chmax(bmax, b)) bmax_idx = i;\r\n    if (chmin(bmin, b)) bmin_idx\
    \ = i;\r\n  }\r\n\r\n  // max, idx\r\n  pair<T, int> get_max(T x, T y) {\r\n \
    \   if (cht_min.empty()) return {-infty<T>, -1};\r\n\r\n    if (x == 0) {\r\n\
    \      if (bmax * y > bmin * y) { return {bmax * y, bmax_idx}; }\r\n      return\
    \ {bmin * y, bmin_idx};\r\n    }\r\n    ld z = ld(y) / x;\r\n    if (x > 0) {\r\
    \n      auto l = cht_max.lower_bound(z);\r\n      T a = l->m, b = l->k;\r\n  \
    \    pair<T, T> p = {a, b};\r\n      int idx = MP[p];\r\n      return {a * x +\
    \ b * y, idx};\r\n    }\r\n    auto l = cht_min.lower_bound(z);\r\n    T a = -(l->m),\
    \ b = -(l->k);\r\n    pair<T, T> p = {a, b};\r\n    int idx = MP[p];\r\n    return\
    \ {a * x + b * y, idx};\r\n  }\r\n\r\n  // min, idx\r\n  pair<T, int> get_min(T\
    \ x, T y) {\r\n    auto [f, i] = get_max(-x, -y);\r\n    return {-f, i};\r\n \
    \ }\r\n};\r\n"
  code: "namespace CHT {\r\ntemplate <typename T>\r\nstruct Line {\r\n  mutable T\
    \ k, m, p;\r\n  bool operator<(const Line& o) const { return k < o.k; }\r\n  bool\
    \ operator<(T x) const { return p < x; }\r\n};\r\n\r\ntemplate <typename T>\r\n\
    T lc_inf() {\r\n  return numeric_limits<T>::max();\r\n}\r\ntemplate <>\r\nlong\
    \ double lc_inf<long double>() {\r\n  return 1 / .0;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nT lc_div(T a, T b) {\r\n  return a / b - ((a ^ b) < 0 and a % b);\r\n\
    }\r\ntemplate <>\r\nlong double lc_div(long double a, long double b) {\r\n  return\
    \ a / b;\r\n};\r\ntemplate <>\r\ndouble lc_div(double a, double b) {\r\n  return\
    \ a / b;\r\n};\r\n\r\ntemplate <typename T, bool MINIMIZE = true>\r\nstruct LineContainer\
    \ : multiset<Line<T>, less<>> {\r\n  using super = multiset<Line<T>, less<>>;\r\
    \n  using super::begin, super::end, super::insert, super::erase;\r\n  using super::empty,\
    \ super::lower_bound;\r\n  T inf = lc_inf<T>();\r\n  bool insect(typename super::iterator\
    \ x, typename super::iterator y) {\r\n    if (y == end()) return x->p = inf, false;\r\
    \n    if (x->k == y->k)\r\n      x->p = (x->m > y->m ? inf : -inf);\r\n    else\r\
    \n      x->p = lc_div(y->m - x->m, x->k - y->k);\r\n    return x->p >= y->p;\r\
    \n  }\r\n  void add(T k, T m) {\r\n    if (MINIMIZE) { k = -k, m = -m; }\r\n \
    \   auto z = insert({k, m, 0}), y = z++, x = y;\r\n    while (insect(y, z)) z\
    \ = erase(z);\r\n    if (x != begin() and insect(--x, y)) insect(x, y = erase(y));\r\
    \n    while ((y = x) != begin() and (--x)->p >= y->p) insect(x, erase(y));\r\n\
    \  }\r\n  T query(T x) {\r\n    assert(!empty());\r\n    auto l = *lower_bound(x);\r\
    \n    T v = (l.k * x + l.m);\r\n    return (MINIMIZE ? -v : v);\r\n  }\r\n};\r\
    \n}; // namespace CHT\r\n\r\nusing namespace CHT;\r\ntemplate <typename T>\r\n\
    using CHT_min = LineContainer<T, true>;\r\ntemplate <typename T>\r\nusing CHT_max\
    \ = LineContainer<T, false>;\r\n\r\n/*\r\nlong long / double \u3067\u52D5\u304F\
    \u3068\u601D\u3046\u3002\u30AF\u30A8\u30EA\u3042\u305F\u308A O(log N)\r\n\u30FB\
    add(a, b, i=-1)\uFF1Aax + by \u306E\u8FFD\u52A0 (index=i)\r\n\u30FBget_max(x,y)\uFF1A\
    (ax + by,i)\r\n\u30FBget_min(x,y)\uFF1A(ax + by,i)\r\n*/\r\ntemplate <typename\
    \ T>\r\nstruct CHT_xy {\r\n  static_assert(is_same_v<T, ll> || std::is_floating_point_v<T>);\r\
    \n  using ld = long double;\r\n  CHT_min<ld> cht_min;\r\n  CHT_max<ld> cht_max;\r\
    \n  T amax = -infty<T>, amin = infty<T>;\r\n  T bmax = -infty<T>, bmin = infty<T>;\r\
    \n  int amax_idx = -1, amin_idx = -1;\r\n  int bmax_idx = -1, bmin_idx = -1;\r\
    \n  bool empty = true;\r\n  map<pair<T, T>, int> MP;\r\n\r\n  void clear() {\r\
    \n    empty = true;\r\n    cht_min.clear();\r\n    cht_max.clear();\r\n  }\r\n\
    \  void add(T a, T b, int i = -1) {\r\n    empty = false;\r\n    cht_min.add(b,\
    \ a);\r\n    cht_max.add(b, a);\r\n    pair<T, T> p = {a, b};\r\n    MP[p] = i;\r\
    \n\r\n    if (chmax(amax, a)) amax_idx = i;\r\n    if (chmin(amin, a)) amin_idx\
    \ = i;\r\n    if (chmax(bmax, b)) bmax_idx = i;\r\n    if (chmin(bmin, b)) bmin_idx\
    \ = i;\r\n  }\r\n\r\n  // max, idx\r\n  pair<T, int> get_max(T x, T y) {\r\n \
    \   if (cht_min.empty()) return {-infty<T>, -1};\r\n\r\n    if (x == 0) {\r\n\
    \      if (bmax * y > bmin * y) { return {bmax * y, bmax_idx}; }\r\n      return\
    \ {bmin * y, bmin_idx};\r\n    }\r\n    ld z = ld(y) / x;\r\n    if (x > 0) {\r\
    \n      auto l = cht_max.lower_bound(z);\r\n      T a = l->m, b = l->k;\r\n  \
    \    pair<T, T> p = {a, b};\r\n      int idx = MP[p];\r\n      return {a * x +\
    \ b * y, idx};\r\n    }\r\n    auto l = cht_min.lower_bound(z);\r\n    T a = -(l->m),\
    \ b = -(l->k);\r\n    pair<T, T> p = {a, b};\r\n    int idx = MP[p];\r\n    return\
    \ {a * x + b * y, idx};\r\n  }\r\n\r\n  // min, idx\r\n  pair<T, int> get_min(T\
    \ x, T y) {\r\n    auto [f, i] = get_max(-x, -y);\r\n    return {-f, i};\r\n \
    \ }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/cht.hpp
  requiredBy: []
  timestamp: '2025-05-05 02:10:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/2012.test.cpp
  - test/3_yukicoder/1297.test.cpp
  - test/2_library_checker/data_structure/line_add_get_min.test.cpp
documentation_of: convex/cht.hpp
layout: document
redirect_from:
- /library/convex/cht.hpp
- /library/convex/cht.hpp.html
title: convex/cht.hpp
---
