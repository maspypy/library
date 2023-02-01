---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/static_range_inversions_mo.test.cpp
    title: test/library_checker/datastructure/static_range_inversions_mo.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/offline_query/mo.hpp\"\nstruct Mo {\r\n  vc<pair<int,\
    \ int>> LR;\r\n  void add(int L, int R) { LR.emplace_back(L, R); }\r\n\r\n  vc<int>\
    \ get_mo_order() {\r\n    int N = 1;\r\n    for (auto &&[l, r]: LR) chmax(N, r);\r\
    \n    int Q = len(LR);\r\n    int bs = N / min<int>(N, sqrt(Q));\r\n    vc<int>\
    \ I(Q);\r\n    iota(all(I), 0);\r\n    sort(all(I), [&](int a, int b) {\r\n  \
    \    int aa = LR[a].fi / bs, bb = LR[b].fi / bs;\r\n      if (aa != bb) return\
    \ aa < bb;\r\n      return (aa & 1) ? LR[a].se > LR[b].se : LR[a].se < LR[b].se;\r\
    \n    });\r\n\r\n    auto cost = [&](int a, int b) -> int {\r\n      return abs(LR[I[a]].fi\
    \ - LR[I[b]].fi) + abs(LR[I[a]].se - LR[I[b]].se);\r\n    };\r\n\r\n    // \u30E9\
    \u30F3\u30C0\u30E0\u30B1\u30FC\u30B9\u3067\u6570\u30D1\u30FC\u30BB\u30F3\u30C8\
    \r\n    FOR(k, Q - 5) {\r\n      if (cost(k, k + 2) + cost(k + 1, k + 3)\r\n \
    \         < cost(k, k + 1) + cost(k + 2, k + 3)) {\r\n        swap(I[k + 1], I[k\
    \ + 2]);\r\n      }\r\n      if (cost(k, k + 3) + cost(k + 1, k + 4)\r\n     \
    \     < cost(k, k + 1) + cost(k + 3, k + 4)) {\r\n        swap(I[k + 1], I[k +\
    \ 3]);\r\n      }\r\n    }\r\n    return I;\r\n  }\r\n\r\n  template <typename\
    \ F1, typename F2, typename F3, typename F4, typename F5>\r\n  void calc(F1 add_l,\
    \ F2 add_r, F3 rm_l, F4 rm_r, F5 query) {\r\n    auto I = get_mo_order();\r\n\
    \    int l = 0, r = 0;\r\n    for (auto idx: I) {\r\n      while (l > LR[idx].fi)\
    \ add_l(--l);\r\n      while (r < LR[idx].se) add_r(r++);\r\n      while (l <\
    \ LR[idx].fi) rm_l(l++);\r\n      while (r > LR[idx].se) rm_r(--r);\r\n      query(idx);\r\
    \n    }\r\n  }\r\n};\r\n"
  code: "struct Mo {\r\n  vc<pair<int, int>> LR;\r\n  void add(int L, int R) { LR.emplace_back(L,\
    \ R); }\r\n\r\n  vc<int> get_mo_order() {\r\n    int N = 1;\r\n    for (auto &&[l,\
    \ r]: LR) chmax(N, r);\r\n    int Q = len(LR);\r\n    int bs = N / min<int>(N,\
    \ sqrt(Q));\r\n    vc<int> I(Q);\r\n    iota(all(I), 0);\r\n    sort(all(I), [&](int\
    \ a, int b) {\r\n      int aa = LR[a].fi / bs, bb = LR[b].fi / bs;\r\n      if\
    \ (aa != bb) return aa < bb;\r\n      return (aa & 1) ? LR[a].se > LR[b].se :\
    \ LR[a].se < LR[b].se;\r\n    });\r\n\r\n    auto cost = [&](int a, int b) ->\
    \ int {\r\n      return abs(LR[I[a]].fi - LR[I[b]].fi) + abs(LR[I[a]].se - LR[I[b]].se);\r\
    \n    };\r\n\r\n    // \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\u30B9\u3067\u6570\u30D1\
    \u30FC\u30BB\u30F3\u30C8\r\n    FOR(k, Q - 5) {\r\n      if (cost(k, k + 2) +\
    \ cost(k + 1, k + 3)\r\n          < cost(k, k + 1) + cost(k + 2, k + 3)) {\r\n\
    \        swap(I[k + 1], I[k + 2]);\r\n      }\r\n      if (cost(k, k + 3) + cost(k\
    \ + 1, k + 4)\r\n          < cost(k, k + 1) + cost(k + 3, k + 4)) {\r\n      \
    \  swap(I[k + 1], I[k + 3]);\r\n      }\r\n    }\r\n    return I;\r\n  }\r\n\r\
    \n  template <typename F1, typename F2, typename F3, typename F4, typename F5>\r\
    \n  void calc(F1 add_l, F2 add_r, F3 rm_l, F4 rm_r, F5 query) {\r\n    auto I\
    \ = get_mo_order();\r\n    int l = 0, r = 0;\r\n    for (auto idx: I) {\r\n  \
    \    while (l > LR[idx].fi) add_l(--l);\r\n      while (r < LR[idx].se) add_r(r++);\r\
    \n      while (l < LR[idx].fi) rm_l(l++);\r\n      while (r > LR[idx].se) rm_r(--r);\r\
    \n      query(idx);\r\n    }\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/mo.hpp
  requiredBy: []
  timestamp: '2023-01-25 06:10:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
