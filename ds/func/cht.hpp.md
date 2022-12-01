---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/2012.test.cpp
    title: test/yukicoder/2012.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/func/cht.hpp\"\n\r\ntemplate <typename T>\r\nstruct Line\
    \ {\r\n  mutable T k, m, p;\r\n  bool operator<(const Line& o) const { return\
    \ k < o.k; }\r\n  bool operator<(T x) const { return p < x; }\r\n};\r\n\r\ntemplate\
    \ <typename T>\r\nT lc_inf() {\r\n  return numeric_limits<T>::max();\r\n}\r\n\
    template <>\r\nlong double lc_inf<long double>() {\r\n  return 1 / .0;\r\n}\r\n\
    \r\ntemplate <typename T>\r\nT lc_div(T a, T b) {\r\n  return a / b - ((a ^ b)\
    \ < 0 and a % b);\r\n}\r\ntemplate <>\r\nlong double lc_div(long double a, long\
    \ double b) {\r\n  return a / b;\r\n};\r\ntemplate <>\r\ndouble lc_div(double\
    \ a, double b) {\r\n  return a / b;\r\n};\r\n\r\ntemplate <typename T, bool MINIMIZE\
    \ = true>\r\nstruct LineContainer : multiset<Line<T>, less<>> {\r\n  using super\
    \ = multiset<Line<T>, less<>>;\r\n  using super::begin, super::end, super::insert,\
    \ super::erase;\r\n  using super::empty, super::lower_bound;\r\n  const T inf\
    \ = lc_inf<T>();\r\n  bool insect(typename super::iterator x, typename super::iterator\
    \ y) {\r\n    if (y == end()) return x->p = inf, false;\r\n    if (x->k == y->k)\r\
    \n      x->p = (x->m > y->m ? inf : -inf);\r\n    else\r\n      x->p = lc_div(y->m\
    \ - x->m, x->k - y->k);\r\n    return x->p >= y->p;\r\n  }\r\n  void add(T k,\
    \ T m) {\r\n    if (MINIMIZE) { k = -k, m = -m; }\r\n    auto z = insert({k, m,\
    \ 0}), y = z++, x = y;\r\n    while (insect(y, z)) z = erase(z);\r\n    if (x\
    \ != begin() and insect(--x, y)) insect(x, y = erase(y));\r\n    while ((y = x)\
    \ != begin() and (--x)->p >= y->p) insect(x, erase(y));\r\n  }\r\n  T query(T\
    \ x) {\r\n    assert(!empty());\r\n    auto l = *lower_bound(x);\r\n    T v =\
    \ (l.k * x + l.m);\r\n    return (MINIMIZE ? -v : v);\r\n  }\r\n};\r\n\r\ntemplate\
    \ <typename T>\r\nusing CHT_min = LineContainer<T, true>;\r\ntemplate <typename\
    \ T>\r\nusing CHT_max = LineContainer<T, false>;\r\n\r\n/*\r\nlong long / double\
    \ \u3067\u52D5\u304F\u3068\u601D\u3046\u3002\u30AF\u30A8\u30EA\u3042\u305F\u308A\
    \ O(log N)\r\n\u30FBadd(a, b)\uFF1Aax + by \u306E\u8FFD\u52A0\r\n\u30FBget_max(x,y)\uFF1A\
    max_{a,b} (ax + by)\r\n\u30FBget_min(x,y)\uFF1Amax_{a,b} (ax + by)\r\n*/\r\ntemplate\
    \ <typename T>\r\nstruct CHT_xy {\r\n  using ld = long double;\r\n  CHT_min<ld>\
    \ cht_min;\r\n  CHT_max<ld> cht_max;\r\n  T amax = -1e18, amin = 1e18, bmax =\
    \ -1e18, bmin = 1e18;\r\n  void add(T a, T b) {\r\n    cht_min.add(b, a);\r\n\
    \    cht_max.add(b, a);\r\n    chmax(amax, a), chmin(amin, a), chmax(bmax, b),\
    \ chmin(bmin, b);\r\n  }\r\n\r\n  T get_max(T x, T y) {\r\n    if (x == 0) { return\
    \ max(bmax * y, bmin * y); }\r\n    ld z = ld(y) / x;\r\n    if (x > 0) {\r\n\
    \      auto l = cht_max.lower_bound(z);\r\n      ll a = l->m, b = l->k;\r\n  \
    \    return a * x + b * y;\r\n    }\r\n    auto l = cht_min.lower_bound(z);\r\n\
    \    ll a = -(l->m), b = -(l->k);\r\n    return a * x + b * y;\r\n  }\r\n\r\n\
    \  T get_min(T x, T y) { return -get_max(-x, -y); }\r\n};\r\n"
  code: "\r\ntemplate <typename T>\r\nstruct Line {\r\n  mutable T k, m, p;\r\n  bool\
    \ operator<(const Line& o) const { return k < o.k; }\r\n  bool operator<(T x)\
    \ const { return p < x; }\r\n};\r\n\r\ntemplate <typename T>\r\nT lc_inf() {\r\
    \n  return numeric_limits<T>::max();\r\n}\r\ntemplate <>\r\nlong double lc_inf<long\
    \ double>() {\r\n  return 1 / .0;\r\n}\r\n\r\ntemplate <typename T>\r\nT lc_div(T\
    \ a, T b) {\r\n  return a / b - ((a ^ b) < 0 and a % b);\r\n}\r\ntemplate <>\r\
    \nlong double lc_div(long double a, long double b) {\r\n  return a / b;\r\n};\r\
    \ntemplate <>\r\ndouble lc_div(double a, double b) {\r\n  return a / b;\r\n};\r\
    \n\r\ntemplate <typename T, bool MINIMIZE = true>\r\nstruct LineContainer : multiset<Line<T>,\
    \ less<>> {\r\n  using super = multiset<Line<T>, less<>>;\r\n  using super::begin,\
    \ super::end, super::insert, super::erase;\r\n  using super::empty, super::lower_bound;\r\
    \n  const T inf = lc_inf<T>();\r\n  bool insect(typename super::iterator x, typename\
    \ super::iterator y) {\r\n    if (y == end()) return x->p = inf, false;\r\n  \
    \  if (x->k == y->k)\r\n      x->p = (x->m > y->m ? inf : -inf);\r\n    else\r\
    \n      x->p = lc_div(y->m - x->m, x->k - y->k);\r\n    return x->p >= y->p;\r\
    \n  }\r\n  void add(T k, T m) {\r\n    if (MINIMIZE) { k = -k, m = -m; }\r\n \
    \   auto z = insert({k, m, 0}), y = z++, x = y;\r\n    while (insect(y, z)) z\
    \ = erase(z);\r\n    if (x != begin() and insect(--x, y)) insect(x, y = erase(y));\r\
    \n    while ((y = x) != begin() and (--x)->p >= y->p) insect(x, erase(y));\r\n\
    \  }\r\n  T query(T x) {\r\n    assert(!empty());\r\n    auto l = *lower_bound(x);\r\
    \n    T v = (l.k * x + l.m);\r\n    return (MINIMIZE ? -v : v);\r\n  }\r\n};\r\
    \n\r\ntemplate <typename T>\r\nusing CHT_min = LineContainer<T, true>;\r\ntemplate\
    \ <typename T>\r\nusing CHT_max = LineContainer<T, false>;\r\n\r\n/*\r\nlong long\
    \ / double \u3067\u52D5\u304F\u3068\u601D\u3046\u3002\u30AF\u30A8\u30EA\u3042\u305F\
    \u308A O(log N)\r\n\u30FBadd(a, b)\uFF1Aax + by \u306E\u8FFD\u52A0\r\n\u30FBget_max(x,y)\uFF1A\
    max_{a,b} (ax + by)\r\n\u30FBget_min(x,y)\uFF1Amax_{a,b} (ax + by)\r\n*/\r\ntemplate\
    \ <typename T>\r\nstruct CHT_xy {\r\n  using ld = long double;\r\n  CHT_min<ld>\
    \ cht_min;\r\n  CHT_max<ld> cht_max;\r\n  T amax = -1e18, amin = 1e18, bmax =\
    \ -1e18, bmin = 1e18;\r\n  void add(T a, T b) {\r\n    cht_min.add(b, a);\r\n\
    \    cht_max.add(b, a);\r\n    chmax(amax, a), chmin(amin, a), chmax(bmax, b),\
    \ chmin(bmin, b);\r\n  }\r\n\r\n  T get_max(T x, T y) {\r\n    if (x == 0) { return\
    \ max(bmax * y, bmin * y); }\r\n    ld z = ld(y) / x;\r\n    if (x > 0) {\r\n\
    \      auto l = cht_max.lower_bound(z);\r\n      ll a = l->m, b = l->k;\r\n  \
    \    return a * x + b * y;\r\n    }\r\n    auto l = cht_min.lower_bound(z);\r\n\
    \    ll a = -(l->m), b = -(l->k);\r\n    return a * x + b * y;\r\n  }\r\n\r\n\
    \  T get_min(T x, T y) { return -get_max(-x, -y); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/func/cht.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2012.test.cpp
documentation_of: ds/func/cht.hpp
layout: document
redirect_from:
- /library/ds/func/cht.hpp
- /library/ds/func/cht.hpp.html
title: ds/func/cht.hpp
---
