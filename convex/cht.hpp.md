---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/line_add_get_min.test.cpp
    title: test/2_library_checker/data_structure/line_add_get_min.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1297.test.cpp
    title: test/3_yukicoder/1297.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2012.test.cpp
    title: test/3_yukicoder/2012.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/convex/cht.hpp
  bundledCode: "#line 1 \"convex/cht.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/convex/cht.hpp\n\
    namespace CHT {\ntemplate <typename T>\nstruct Line {\n  mutable T k, m, p;\n\
    \  bool operator<(const Line& o) const { return k < o.k; }\n  bool operator<(T\
    \ x) const { return p < x; }\n};\n\ntemplate <typename T>\nT lc_inf() {\n  return\
    \ numeric_limits<T>::max();\n}\ntemplate <>\nlong double lc_inf<long double>()\
    \ {\n  return 1 / .0;\n}\n\ntemplate <typename T>\nT lc_div(T a, T b) {\n  return\
    \ a / b - ((a ^ b) < 0 and a % b);\n}\ntemplate <>\nlong double lc_div(long double\
    \ a, long double b) {\n  return a / b;\n};\ntemplate <>\ndouble lc_div(double\
    \ a, double b) {\n  return a / b;\n};\n\ntemplate <typename T, bool MINIMIZE =\
    \ true>\nstruct Line_Container : multiset<Line<T>, less<>> {\n  using super =\
    \ multiset<Line<T>, less<>>;\n  using super::begin, super::end, super::insert,\
    \ super::erase;\n  using super::empty, super::lower_bound;\n  T inf = lc_inf<T>();\n\
    \  bool insect(typename super::iterator x, typename super::iterator y) {\n   \
    \ if (y == end()) return x->p = inf, false;\n    if (x->k == y->k)\n      x->p\
    \ = (x->m > y->m ? inf : -inf);\n    else\n      x->p = lc_div(y->m - x->m, x->k\
    \ - y->k);\n    return x->p >= y->p;\n  }\n  void add(T k, T m) {\n    if (MINIMIZE)\
    \ {\n      k = -k, m = -m;\n    }\n    auto z = insert({k, m, 0}), y = z++, x\
    \ = y;\n    while (insect(y, z)) z = erase(z);\n    if (x != begin() and insect(--x,\
    \ y)) insect(x, y = erase(y));\n    while ((y = x) != begin() and (--x)->p >=\
    \ y->p) insect(x, erase(y));\n  }\n  T query(T x) {\n    assert(!empty());\n \
    \   auto l = *lower_bound(x);\n    T v = (l.k * x + l.m);\n    return (MINIMIZE\
    \ ? -v : v);\n  }\n};\n};  // namespace CHT\n\nusing namespace CHT;\ntemplate\
    \ <typename T>\nusing CHT_Min = Line_Container<T, true>;\ntemplate <typename T>\n\
    using CHT_Max = Line_Container<T, false>;\n\n/*\nlong long / double \u3067\u52D5\
    \u304F\u3068\u601D\u3046\u3002\u30AF\u30A8\u30EA\u3042\u305F\u308A O(log N)\n\u30FB\
    add(a, b, i=-1)\uFF1Aax + by \u306E\u8FFD\u52A0 (index=i)\n\u30FBget_max(x,y)\uFF1A\
    (ax + by,i)\n\u30FBget_min(x,y)\uFF1A(ax + by,i)\n*/\ntemplate <typename T>\n\
    struct CHT_XY {\n  static_assert(is_same_v<T, ll> || std::is_floating_point_v<T>);\n\
    \  using ld = long double;\n  CHT_Min<ld> cht_min;\n  CHT_Max<ld> cht_max;\n \
    \ T amax = -infty<T>, amin = infty<T>;\n  T bmax = -infty<T>, bmin = infty<T>;\n\
    \  int amax_idx = -1, amin_idx = -1;\n  int bmax_idx = -1, bmin_idx = -1;\n  bool\
    \ empty = true;\n  map<pair<T, T>, int> MP;\n\n  void clear() {\n    empty = true;\n\
    \    cht_min.clear();\n    cht_max.clear();\n  }\n  void add(T a, T b, int i =\
    \ -1) {\n    empty = false;\n    cht_min.add(b, a);\n    cht_max.add(b, a);\n\
    \    pair<T, T> p = {a, b};\n    MP[p] = i;\n\n    if (chmax(amax, a)) amax_idx\
    \ = i;\n    if (chmin(amin, a)) amin_idx = i;\n    if (chmax(bmax, b)) bmax_idx\
    \ = i;\n    if (chmin(bmin, b)) bmin_idx = i;\n  }\n\n  // max, idx\n  pair<T,\
    \ int> get_max(T x, T y) {\n    if (cht_min.empty()) return {-infty<T>, -1};\n\
    \n    if (x == 0) {\n      if (bmax * y > bmin * y) {\n        return {bmax *\
    \ y, bmax_idx};\n      }\n      return {bmin * y, bmin_idx};\n    }\n    ld z\
    \ = ld(y) / x;\n    if (x > 0) {\n      auto l = cht_max.lower_bound(z);\n   \
    \   T a = l->m, b = l->k;\n      pair<T, T> p = {a, b};\n      int idx = MP[p];\n\
    \      return {a * x + b * y, idx};\n    }\n    auto l = cht_min.lower_bound(z);\n\
    \    T a = -(l->m), b = -(l->k);\n    pair<T, T> p = {a, b};\n    int idx = MP[p];\n\
    \    return {a * x + b * y, idx};\n  }\n\n  // min, idx\n  pair<T, int> get_min(T\
    \ x, T y) {\n    auto [f, i] = get_max(-x, -y);\n    return {-f, i};\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/convex/cht.hpp\n\
    namespace CHT {\ntemplate <typename T>\nstruct Line {\n  mutable T k, m, p;\n\
    \  bool operator<(const Line& o) const { return k < o.k; }\n  bool operator<(T\
    \ x) const { return p < x; }\n};\n\ntemplate <typename T>\nT lc_inf() {\n  return\
    \ numeric_limits<T>::max();\n}\ntemplate <>\nlong double lc_inf<long double>()\
    \ {\n  return 1 / .0;\n}\n\ntemplate <typename T>\nT lc_div(T a, T b) {\n  return\
    \ a / b - ((a ^ b) < 0 and a % b);\n}\ntemplate <>\nlong double lc_div(long double\
    \ a, long double b) {\n  return a / b;\n};\ntemplate <>\ndouble lc_div(double\
    \ a, double b) {\n  return a / b;\n};\n\ntemplate <typename T, bool MINIMIZE =\
    \ true>\nstruct Line_Container : multiset<Line<T>, less<>> {\n  using super =\
    \ multiset<Line<T>, less<>>;\n  using super::begin, super::end, super::insert,\
    \ super::erase;\n  using super::empty, super::lower_bound;\n  T inf = lc_inf<T>();\n\
    \  bool insect(typename super::iterator x, typename super::iterator y) {\n   \
    \ if (y == end()) return x->p = inf, false;\n    if (x->k == y->k)\n      x->p\
    \ = (x->m > y->m ? inf : -inf);\n    else\n      x->p = lc_div(y->m - x->m, x->k\
    \ - y->k);\n    return x->p >= y->p;\n  }\n  void add(T k, T m) {\n    if (MINIMIZE)\
    \ {\n      k = -k, m = -m;\n    }\n    auto z = insert({k, m, 0}), y = z++, x\
    \ = y;\n    while (insect(y, z)) z = erase(z);\n    if (x != begin() and insect(--x,\
    \ y)) insect(x, y = erase(y));\n    while ((y = x) != begin() and (--x)->p >=\
    \ y->p) insect(x, erase(y));\n  }\n  T query(T x) {\n    assert(!empty());\n \
    \   auto l = *lower_bound(x);\n    T v = (l.k * x + l.m);\n    return (MINIMIZE\
    \ ? -v : v);\n  }\n};\n};  // namespace CHT\n\nusing namespace CHT;\ntemplate\
    \ <typename T>\nusing CHT_Min = Line_Container<T, true>;\ntemplate <typename T>\n\
    using CHT_Max = Line_Container<T, false>;\n\n/*\nlong long / double \u3067\u52D5\
    \u304F\u3068\u601D\u3046\u3002\u30AF\u30A8\u30EA\u3042\u305F\u308A O(log N)\n\u30FB\
    add(a, b, i=-1)\uFF1Aax + by \u306E\u8FFD\u52A0 (index=i)\n\u30FBget_max(x,y)\uFF1A\
    (ax + by,i)\n\u30FBget_min(x,y)\uFF1A(ax + by,i)\n*/\ntemplate <typename T>\n\
    struct CHT_XY {\n  static_assert(is_same_v<T, ll> || std::is_floating_point_v<T>);\n\
    \  using ld = long double;\n  CHT_Min<ld> cht_min;\n  CHT_Max<ld> cht_max;\n \
    \ T amax = -infty<T>, amin = infty<T>;\n  T bmax = -infty<T>, bmin = infty<T>;\n\
    \  int amax_idx = -1, amin_idx = -1;\n  int bmax_idx = -1, bmin_idx = -1;\n  bool\
    \ empty = true;\n  map<pair<T, T>, int> MP;\n\n  void clear() {\n    empty = true;\n\
    \    cht_min.clear();\n    cht_max.clear();\n  }\n  void add(T a, T b, int i =\
    \ -1) {\n    empty = false;\n    cht_min.add(b, a);\n    cht_max.add(b, a);\n\
    \    pair<T, T> p = {a, b};\n    MP[p] = i;\n\n    if (chmax(amax, a)) amax_idx\
    \ = i;\n    if (chmin(amin, a)) amin_idx = i;\n    if (chmax(bmax, b)) bmax_idx\
    \ = i;\n    if (chmin(bmin, b)) bmin_idx = i;\n  }\n\n  // max, idx\n  pair<T,\
    \ int> get_max(T x, T y) {\n    if (cht_min.empty()) return {-infty<T>, -1};\n\
    \n    if (x == 0) {\n      if (bmax * y > bmin * y) {\n        return {bmax *\
    \ y, bmax_idx};\n      }\n      return {bmin * y, bmin_idx};\n    }\n    ld z\
    \ = ld(y) / x;\n    if (x > 0) {\n      auto l = cht_max.lower_bound(z);\n   \
    \   T a = l->m, b = l->k;\n      pair<T, T> p = {a, b};\n      int idx = MP[p];\n\
    \      return {a * x + b * y, idx};\n    }\n    auto l = cht_min.lower_bound(z);\n\
    \    T a = -(l->m), b = -(l->k);\n    pair<T, T> p = {a, b};\n    int idx = MP[p];\n\
    \    return {a * x + b * y, idx};\n  }\n\n  // min, idx\n  pair<T, int> get_min(T\
    \ x, T y) {\n    auto [f, i] = get_max(-x, -y);\n    return {-f, i};\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/cht.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
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
