---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/ds/mo_on_tree.hpp
    title: graph/ds/mo_on_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/mo_on_tree.test.cpp
    title: test/1_mytest/mo_on_tree.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/static_range_inversions_mo.test.cpp
    title: test/2_library_checker/data_structure/static_range_inversions_mo.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/static_range_inversions_mo_3.test.cpp
    title: test/2_library_checker/data_structure/static_range_inversions_mo_3.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1270.test.cpp
    title: test/3_yukicoder/1270.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/offline_query/mo.hpp\"\n// Nsqrt(Q)\r\nstruct Mo {\r\n\
    \  vc<pair<int, int>> LR;\r\n  void add(int L, int R) { LR.emplace_back(L, R);\
    \ }\r\n\r\n  static vc<int> get_mo_order(vc<pair<int, int>> LR) {\r\n    int N\
    \ = 1;\r\n    for (auto &&[l, r]: LR) chmax(N, l), chmax(N, r);\r\n    int Q =\
    \ len(LR);\r\n    if (Q == 0) return {};\r\n    int bs = sqrt(3) * N / sqrt(2\
    \ * Q);\r\n    chmax(bs, 1);\r\n    vc<int> I(Q);\r\n    iota(all(I), 0);\r\n\
    \    sort(all(I), [&](int a, int b) {\r\n      int aa = LR[a].fi / bs, bb = LR[b].fi\
    \ / bs;\r\n      if (aa != bb) return aa < bb;\r\n      return (aa & 1) ? LR[a].se\
    \ > LR[b].se : LR[a].se < LR[b].se;\r\n    });\r\n\r\n    auto cost = [&](int\
    \ a, int b) -> int {\r\n      return abs(LR[I[a]].fi - LR[I[b]].fi) + abs(LR[I[a]].se\
    \ - LR[I[b]].se);\r\n    };\r\n\r\n    // \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\
    \u30B9\u3067\u6570\u30D1\u30FC\u30BB\u30F3\u30C8\r\n    FOR(k, Q - 5) {\r\n  \
    \    if (cost(k, k + 2) + cost(k + 1, k + 3)\r\n          < cost(k, k + 1) + cost(k\
    \ + 2, k + 3)) {\r\n        swap(I[k + 1], I[k + 2]);\r\n      }\r\n      if (cost(k,\
    \ k + 3) + cost(k + 1, k + 4)\r\n          < cost(k, k + 1) + cost(k + 3, k +\
    \ 4)) {\r\n        swap(I[k + 1], I[k + 3]);\r\n      }\r\n    }\r\n    return\
    \ I;\r\n  }\r\n\r\n  template <typename F1, typename F2, typename F3, typename\
    \ F4, typename F5>\r\n  void calc(F1 add_l, F2 add_r, F3 rm_l, F4 rm_r, F5 query)\
    \ {\r\n    auto I = get_mo_order(LR);\r\n    int l = 0, r = 0;\r\n    for (auto\
    \ idx: I) {\r\n      while (l > LR[idx].fi) add_l(--l);\r\n      while (r < LR[idx].se)\
    \ add_r(r++);\r\n      while (l < LR[idx].fi) rm_l(l++);\r\n      while (r > LR[idx].se)\
    \ rm_r(--r);\r\n      query(idx);\r\n    }\r\n  }\r\n};\r\n"
  code: "// Nsqrt(Q)\r\nstruct Mo {\r\n  vc<pair<int, int>> LR;\r\n  void add(int\
    \ L, int R) { LR.emplace_back(L, R); }\r\n\r\n  static vc<int> get_mo_order(vc<pair<int,\
    \ int>> LR) {\r\n    int N = 1;\r\n    for (auto &&[l, r]: LR) chmax(N, l), chmax(N,\
    \ r);\r\n    int Q = len(LR);\r\n    if (Q == 0) return {};\r\n    int bs = sqrt(3)\
    \ * N / sqrt(2 * Q);\r\n    chmax(bs, 1);\r\n    vc<int> I(Q);\r\n    iota(all(I),\
    \ 0);\r\n    sort(all(I), [&](int a, int b) {\r\n      int aa = LR[a].fi / bs,\
    \ bb = LR[b].fi / bs;\r\n      if (aa != bb) return aa < bb;\r\n      return (aa\
    \ & 1) ? LR[a].se > LR[b].se : LR[a].se < LR[b].se;\r\n    });\r\n\r\n    auto\
    \ cost = [&](int a, int b) -> int {\r\n      return abs(LR[I[a]].fi - LR[I[b]].fi)\
    \ + abs(LR[I[a]].se - LR[I[b]].se);\r\n    };\r\n\r\n    // \u30E9\u30F3\u30C0\
    \u30E0\u30B1\u30FC\u30B9\u3067\u6570\u30D1\u30FC\u30BB\u30F3\u30C8\r\n    FOR(k,\
    \ Q - 5) {\r\n      if (cost(k, k + 2) + cost(k + 1, k + 3)\r\n          < cost(k,\
    \ k + 1) + cost(k + 2, k + 3)) {\r\n        swap(I[k + 1], I[k + 2]);\r\n    \
    \  }\r\n      if (cost(k, k + 3) + cost(k + 1, k + 4)\r\n          < cost(k, k\
    \ + 1) + cost(k + 3, k + 4)) {\r\n        swap(I[k + 1], I[k + 3]);\r\n      }\r\
    \n    }\r\n    return I;\r\n  }\r\n\r\n  template <typename F1, typename F2, typename\
    \ F3, typename F4, typename F5>\r\n  void calc(F1 add_l, F2 add_r, F3 rm_l, F4\
    \ rm_r, F5 query) {\r\n    auto I = get_mo_order(LR);\r\n    int l = 0, r = 0;\r\
    \n    for (auto idx: I) {\r\n      while (l > LR[idx].fi) add_l(--l);\r\n    \
    \  while (r < LR[idx].se) add_r(r++);\r\n      while (l < LR[idx].fi) rm_l(l++);\r\
    \n      while (r > LR[idx].se) rm_r(--r);\r\n      query(idx);\r\n    }\r\n  }\r\
    \n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/mo.hpp
  requiredBy:
  - graph/ds/mo_on_tree.hpp
  timestamp: '2023-10-29 16:22:13+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1270.test.cpp
  - test/1_mytest/mo_on_tree.test.cpp
  - test/2_library_checker/data_structure/static_range_inversions_mo.test.cpp
  - test/2_library_checker/data_structure/static_range_inversions_mo_3.test.cpp
documentation_of: ds/offline_query/mo.hpp
layout: document
redirect_from:
- /library/ds/offline_query/mo.hpp
- /library/ds/offline_query/mo.hpp.html
title: ds/offline_query/mo.hpp
---
