---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/static_range_inversions_mo2.test.cpp
    title: test/library_checker/datastructure/static_range_inversions_mo2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/620/problem/F
  bundledCode: "#line 1 \"ds/offline_query/rollback_mo.hpp\"\n// https://codeforces.com/contest/620/problem/F\n\
    struct Rollback_Mo {\n  vc<pair<int, int>> LR;\n  void add(int L, int R) { LR.emplace_back(L,\
    \ R); }\n\n  template <typename AL, typename AR, typename F1, typename F2, typename\
    \ F3,\n            typename O>\n  void calc(AL add_left, AR add_right, F1 reset,\
    \ F2 save, F3 rollback,\n            O query) {\n    const int Q = len(LR);\n\
    \    if (Q == 0) return;\n    int N = 0;\n    for (auto &&[L, R]: LR) chmax(N,\
    \ R);\n    const int b_num = sqrt(Q);\n    const int b_sz = ceil(N, b_num);\n\
    \    vvc<int> QID((N - 1) / b_sz + 1);\n    // \u5DE6\u7AEF\u306E\u5C5E\u3059\u308B\
    \u30D6\u30ED\u30C3\u30AF\u3067\u5206\u985E\n    // \u5DE6\u7AEF\u3068\u53F3\u7AEF\
    \u304C\u540C\u3058\u30D6\u30ED\u30C3\u30AF\u306B\u5C5E\u3059\u308B\u3082\u306E\
    \u306F\u3001\u5148\u306B\u51E6\u7406\u3057\u3066\u3057\u307E\u3046\u3002\n   \
    \ auto naive = [&](int qid) -> void {\n      save();\n      auto [L, R] = LR[qid];\n\
    \      FOR(i, L, R) add_right(i);\n      query(qid);\n      rollback();\n    };\n\
    \n    FOR(qid, Q) {\n      auto [L, R] = LR[qid];\n      int iL = L / b_sz, iR\
    \ = R / b_sz;\n      if (iL == iR) {\n        naive(qid);\n        continue;\n\
    \      }\n      QID[iL].eb(qid);\n    }\n\n    FOR(iL, len(QID)) {\n      auto\
    \ &I = QID[iL];\n      if (I.empty()) continue;\n      sort(all(I),\n        \
    \   [&](auto &a, auto &b) -> bool { return LR[a].se < LR[b].se; });\n      int\
    \ LMAX = 0;\n      for (auto &&qid: I) {\n        auto [L, R] = LR[qid];\n   \
    \     chmax(LMAX, L);\n      }\n      reset();\n      int l = LMAX, r = LMAX;\n\
    \      for (auto &&qid: I) {\n        auto [L, R] = LR[qid];\n        while (r\
    \ < R) add_right(r++);\n        save();\n        while (L < l) add_left(--l);\n\
    \        query(qid);\n        rollback();\n        l = LMAX;\n      }\n    }\n\
    \  }\n};\n"
  code: "// https://codeforces.com/contest/620/problem/F\nstruct Rollback_Mo {\n \
    \ vc<pair<int, int>> LR;\n  void add(int L, int R) { LR.emplace_back(L, R); }\n\
    \n  template <typename AL, typename AR, typename F1, typename F2, typename F3,\n\
    \            typename O>\n  void calc(AL add_left, AR add_right, F1 reset, F2\
    \ save, F3 rollback,\n            O query) {\n    const int Q = len(LR);\n   \
    \ if (Q == 0) return;\n    int N = 0;\n    for (auto &&[L, R]: LR) chmax(N, R);\n\
    \    const int b_num = sqrt(Q);\n    const int b_sz = ceil(N, b_num);\n    vvc<int>\
    \ QID((N - 1) / b_sz + 1);\n    // \u5DE6\u7AEF\u306E\u5C5E\u3059\u308B\u30D6\u30ED\
    \u30C3\u30AF\u3067\u5206\u985E\n    // \u5DE6\u7AEF\u3068\u53F3\u7AEF\u304C\u540C\
    \u3058\u30D6\u30ED\u30C3\u30AF\u306B\u5C5E\u3059\u308B\u3082\u306E\u306F\u3001\
    \u5148\u306B\u51E6\u7406\u3057\u3066\u3057\u307E\u3046\u3002\n    auto naive =\
    \ [&](int qid) -> void {\n      save();\n      auto [L, R] = LR[qid];\n      FOR(i,\
    \ L, R) add_right(i);\n      query(qid);\n      rollback();\n    };\n\n    FOR(qid,\
    \ Q) {\n      auto [L, R] = LR[qid];\n      int iL = L / b_sz, iR = R / b_sz;\n\
    \      if (iL == iR) {\n        naive(qid);\n        continue;\n      }\n    \
    \  QID[iL].eb(qid);\n    }\n\n    FOR(iL, len(QID)) {\n      auto &I = QID[iL];\n\
    \      if (I.empty()) continue;\n      sort(all(I),\n           [&](auto &a, auto\
    \ &b) -> bool { return LR[a].se < LR[b].se; });\n      int LMAX = 0;\n      for\
    \ (auto &&qid: I) {\n        auto [L, R] = LR[qid];\n        chmax(LMAX, L);\n\
    \      }\n      reset();\n      int l = LMAX, r = LMAX;\n      for (auto &&qid:\
    \ I) {\n        auto [L, R] = LR[qid];\n        while (r < R) add_right(r++);\n\
    \        save();\n        while (L < l) add_left(--l);\n        query(qid);\n\
    \        rollback();\n        l = LMAX;\n      }\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/rollback_mo.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/static_range_inversions_mo2.test.cpp
documentation_of: ds/offline_query/rollback_mo.hpp
layout: document
redirect_from:
- /library/ds/offline_query/rollback_mo.hpp
- /library/ds/offline_query/rollback_mo.hpp.html
title: ds/offline_query/rollback_mo.hpp
---
