---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/static_range_inversions_mo.test.cpp
    title: test/library_checker/datastructure/static_range_inversions_mo.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/offline_query/mo.hpp\"\nstruct Mo {\r\n  vc<pair<int,\
    \ int>> LR;\r\n  void add(int L, int R) { LR.emplace_back(L, R); }\r\n\r\n  template\
    \ <typename AL, typename AR, typename EL, typename ER, typename O>\r\n  void calc(const\
    \ AL &add_left, const AR &add_right, const EL &erase_left,\r\n            const\
    \ ER &erase_right, const O &query) {\r\n    int n = 1;\r\n    for (auto &&[l,\
    \ r]: LR) chmax(n, r);\r\n    int q = (int)LR.size();\r\n    int bs = n / min<int>(n,\
    \ sqrt(q));\r\n    vector<int> ord(q);\r\n    iota(begin(ord), end(ord), 0);\r\
    \n    sort(begin(ord), end(ord), [&](int a, int b) {\r\n      int ablock = LR[a].first\
    \ / bs, bblock = LR[b].first / bs;\r\n      if (ablock != bblock) return ablock\
    \ < bblock;\r\n      return (ablock & 1) ? LR[a].second > LR[b].second\r\n   \
    \                       : LR[a].second < LR[b].second;\r\n    });\r\n    int l\
    \ = 0, r = 0;\r\n    for (auto idx: ord) {\r\n      while (l > LR[idx].first)\
    \ add_left(--l);\r\n      while (r < LR[idx].second) add_right(r++);\r\n     \
    \ while (l < LR[idx].first) erase_left(l++);\r\n      while (r > LR[idx].second)\
    \ erase_right(--r);\r\n      query(idx);\r\n    }\r\n  }\r\n\r\n  template <typename\
    \ A, typename E, typename O>\r\n  void calc(const A &add, const E &erase, const\
    \ O &query) {\r\n    calc(add, add, erase, erase, query);\r\n  }\r\n};\r\n"
  code: "struct Mo {\r\n  vc<pair<int, int>> LR;\r\n  void add(int L, int R) { LR.emplace_back(L,\
    \ R); }\r\n\r\n  template <typename AL, typename AR, typename EL, typename ER,\
    \ typename O>\r\n  void calc(const AL &add_left, const AR &add_right, const EL\
    \ &erase_left,\r\n            const ER &erase_right, const O &query) {\r\n   \
    \ int n = 1;\r\n    for (auto &&[l, r]: LR) chmax(n, r);\r\n    int q = (int)LR.size();\r\
    \n    int bs = n / min<int>(n, sqrt(q));\r\n    vector<int> ord(q);\r\n    iota(begin(ord),\
    \ end(ord), 0);\r\n    sort(begin(ord), end(ord), [&](int a, int b) {\r\n    \
    \  int ablock = LR[a].first / bs, bblock = LR[b].first / bs;\r\n      if (ablock\
    \ != bblock) return ablock < bblock;\r\n      return (ablock & 1) ? LR[a].second\
    \ > LR[b].second\r\n                          : LR[a].second < LR[b].second;\r\
    \n    });\r\n    int l = 0, r = 0;\r\n    for (auto idx: ord) {\r\n      while\
    \ (l > LR[idx].first) add_left(--l);\r\n      while (r < LR[idx].second) add_right(r++);\r\
    \n      while (l < LR[idx].first) erase_left(l++);\r\n      while (r > LR[idx].second)\
    \ erase_right(--r);\r\n      query(idx);\r\n    }\r\n  }\r\n\r\n  template <typename\
    \ A, typename E, typename O>\r\n  void calc(const A &add, const E &erase, const\
    \ O &query) {\r\n    calc(add, add, erase, erase, query);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/mo.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1270.test.cpp
  - test/library_checker/datastructure/static_range_inversions_mo.test.cpp
documentation_of: ds/offline_query/mo.hpp
layout: document
redirect_from:
- /library/ds/offline_query/mo.hpp
- /library/ds/offline_query/mo.hpp.html
title: ds/offline_query/mo.hpp
---
