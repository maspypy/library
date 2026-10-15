---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/ds/mo_on_tree.hpp
    title: graph/ds/mo_on_tree.hpp
  - icon: ':question:'
    path: mod/prefix_sum_of_binom.hpp
    title: mod/prefix_sum_of_binom.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/mo_on_tree.test.cpp
    title: test/1_mytest/mo_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/prefix_sum_of_binom.test.cpp
    title: test/1_mytest/prefix_sum_of_binom.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/static_range_inversions_mo.test.cpp
    title: test/2_library_checker/data_structure/static_range_inversions_mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/static_range_inversions_mo_3.test.cpp
    title: test/2_library_checker/data_structure/static_range_inversions_mo_3.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1270.test.cpp
    title: test/3_yukicoder/1270.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2206.test.cpp
    title: test/3_yukicoder/2206.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2206_2.test.cpp
    title: test/3_yukicoder/2206_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/offline_query/mo.hpp
  bundledCode: "#line 1 \"ds/offline_query/mo.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/offline_query/mo.hpp\n\
    // Nsqrt(Q)\nstruct Mo {\n  vc<pair<int, int>> LR;\n  void add(int L, int R) {\
    \ LR.emplace_back(L, R); }\n\n  static vc<int> get_mo_order(vc<pair<int, int>>\
    \ LR) {\n    int N = 1;\n    for (auto &&[l, r] : LR) chmax(N, l), chmax(N, r);\n\
    \    int Q = len(LR);\n    if (Q == 0) return {};\n    int bs = sqrt(3) * N /\
    \ sqrt(2 * Q);\n    chmax(bs, 1);\n    vc<int> I(Q);\n    iota(all(I), 0);\n \
    \   sort(all(I), [&](int a, int b) {\n      int aa = LR[a].fi / bs, bb = LR[b].fi\
    \ / bs;\n      if (aa != bb) return aa < bb;\n      return (aa & 1) ? LR[a].se\
    \ > LR[b].se : LR[a].se < LR[b].se;\n    });\n\n    auto cost = [&](int a, int\
    \ b) -> int {\n      return abs(LR[I[a]].fi - LR[I[b]].fi) + abs(LR[I[a]].se -\
    \ LR[I[b]].se);\n    };\n\n    // \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\u30B9\u3067\
    6%\u7A0B\u5EA6\u6539\u5584\n    auto work = [&](int k) -> void {\n      if (cost(k,\
    \ k + 2) + cost(k + 1, k + 3) <\n          cost(k, k + 1) + cost(k + 2, k + 3))\
    \ {\n        swap(I[k + 1], I[k + 2]);\n      }\n      if (cost(k, k + 3) + cost(k\
    \ + 1, k + 4) <\n          cost(k, k + 1) + cost(k + 3, k + 4)) {\n        swap(I[k\
    \ + 1], I[k + 3]);\n      }\n    };\n    FOR(k, Q - 5) work(k);\n    FOR_R(k,\
    \ Q - 5) work(k);\n    return I;\n  }\n\n  template <typename F1, typename F2,\
    \ typename F3, typename F4, typename F5>\n  void calc(F1 add_l, F2 add_r, F3 rm_l,\
    \ F4 rm_r, F5 query) {\n    auto I = get_mo_order(LR);\n    int l = 0, r = 0;\n\
    \    for (auto idx : I) {\n      while (l > LR[idx].fi) add_l(--l);\n      while\
    \ (r < LR[idx].se) add_r(r++);\n      while (l < LR[idx].fi) rm_l(l++);\n    \
    \  while (r > LR[idx].se) rm_r(--r);\n      query(idx);\n    }\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/offline_query/mo.hpp\n\
    // Nsqrt(Q)\nstruct Mo {\n  vc<pair<int, int>> LR;\n  void add(int L, int R) {\
    \ LR.emplace_back(L, R); }\n\n  static vc<int> get_mo_order(vc<pair<int, int>>\
    \ LR) {\n    int N = 1;\n    for (auto &&[l, r] : LR) chmax(N, l), chmax(N, r);\n\
    \    int Q = len(LR);\n    if (Q == 0) return {};\n    int bs = sqrt(3) * N /\
    \ sqrt(2 * Q);\n    chmax(bs, 1);\n    vc<int> I(Q);\n    iota(all(I), 0);\n \
    \   sort(all(I), [&](int a, int b) {\n      int aa = LR[a].fi / bs, bb = LR[b].fi\
    \ / bs;\n      if (aa != bb) return aa < bb;\n      return (aa & 1) ? LR[a].se\
    \ > LR[b].se : LR[a].se < LR[b].se;\n    });\n\n    auto cost = [&](int a, int\
    \ b) -> int {\n      return abs(LR[I[a]].fi - LR[I[b]].fi) + abs(LR[I[a]].se -\
    \ LR[I[b]].se);\n    };\n\n    // \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\u30B9\u3067\
    6%\u7A0B\u5EA6\u6539\u5584\n    auto work = [&](int k) -> void {\n      if (cost(k,\
    \ k + 2) + cost(k + 1, k + 3) <\n          cost(k, k + 1) + cost(k + 2, k + 3))\
    \ {\n        swap(I[k + 1], I[k + 2]);\n      }\n      if (cost(k, k + 3) + cost(k\
    \ + 1, k + 4) <\n          cost(k, k + 1) + cost(k + 3, k + 4)) {\n        swap(I[k\
    \ + 1], I[k + 3]);\n      }\n    };\n    FOR(k, Q - 5) work(k);\n    FOR_R(k,\
    \ Q - 5) work(k);\n    return I;\n  }\n\n  template <typename F1, typename F2,\
    \ typename F3, typename F4, typename F5>\n  void calc(F1 add_l, F2 add_r, F3 rm_l,\
    \ F4 rm_r, F5 query) {\n    auto I = get_mo_order(LR);\n    int l = 0, r = 0;\n\
    \    for (auto idx : I) {\n      while (l > LR[idx].fi) add_l(--l);\n      while\
    \ (r < LR[idx].se) add_r(r++);\n      while (l < LR[idx].fi) rm_l(l++);\n    \
    \  while (r > LR[idx].se) rm_r(--r);\n      query(idx);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/mo.hpp
  requiredBy:
  - graph/ds/mo_on_tree.hpp
  - mod/prefix_sum_of_binom.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/mo_on_tree.test.cpp
  - test/1_mytest/prefix_sum_of_binom.test.cpp
  - test/3_yukicoder/2206.test.cpp
  - test/3_yukicoder/1270.test.cpp
  - test/3_yukicoder/2206_2.test.cpp
  - test/2_library_checker/data_structure/static_range_inversions_mo.test.cpp
  - test/2_library_checker/data_structure/static_range_inversions_mo_3.test.cpp
documentation_of: ds/offline_query/mo.hpp
layout: document
redirect_from:
- /library/ds/offline_query/mo.hpp
- /library/ds/offline_query/mo.hpp.html
title: ds/offline_query/mo.hpp
---
