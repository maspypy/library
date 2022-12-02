---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/staticrmq_dc.test.cpp
    title: test/library_checker/datastructure/staticrmq_dc.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/contest/1100/submission/153353485
  bundledCode: "#line 2 \"ds/offline_query/divide_conquer_range_query.hpp\"\n\n/*\n\
    \u30FB\u5404 i \u306B\u5BFE\u3057\u3066\u3001[i, m) \u306B\u5BFE\u3059\u308B\u8A08\
    \u7B97\u7D50\u679C\n\u30FB\u5404 j \u306B\u5BFE\u3057\u3066\u3001[m, j) \u306B\
    \u5BFE\u3059\u308B\u8A08\u7B97\u7D50\u679C\n\u304C\u967D\u306B\u6301\u3066\u3066\
    \u3001\u305D\u3053\u304B\u3089\u30AF\u30A8\u30EA [i, j) \u306B\u7B54\u3048\u3089\
    \u308C\u308B\u3068\u304D\u306B\u4F7F\u3048\u308B\u3002\n----\n\u30FB1\u8981\u7D20\
    \u306E\u8FFD\u52A0\uFF1AO(NlogN) \u56DE\u3001\u30C7\u30FC\u30BF\u306E\u30DE\u30FC\
    \u30B8\uFF1AO(Q) \u56DE\u3002\n\u30FB\u5927\u304D\u306A\u30DE\u30FC\u30B8\u306B\
    \u6642\u9593\u304C\u304B\u304B\u308B\u3068\u304D\u306B\u306F\u30BB\u30B0\u6728\
    \u3088\u308A\u9AD8\u901F\u3002\n\u30FBdisjoint sparse table \u3068\u540C\u3058\
    \u4ED5\u7D44\u307F\u3060\u304C\u3001\u7701\u30E1\u30E2\u30EA\u3002\n----\nexample\uFF1A\
    xor basis \u306E\u30DE\u30FC\u30B8\nhttps://codeforces.com/contest/1100/submission/153353485\n\
    */\ntemplate <typename Data>\nstruct Divide_Conquer_Range_Query {\n  int n;\n\
    \  vc<pair<int, int>> query;\n  vc<Data> dat;\n\n  Divide_Conquer_Range_Query(int\
    \ n) : n(n) {}\n  void add(int l, int r) {\n    assert(0 <= l && l < r && r <=\
    \ n);\n    query.eb(l, r);\n  }\n\n  // add_left\uFF1A(i, data) -> data\n  //\
    \ add_right\uFF1A(i, data) -> data\n  // calc\uFF1A(q, data_l, data_r) -> data\n\
    \  template <typename AL, typename AR, typename CALC>\n  void calc(Data empty_data,\
    \ AL add_left, AR add_right, CALC calc) {\n    auto dfs = [&](auto self, int L,\
    \ int R, vc<int>& I) -> void {\n      vc<int> left, right;\n      int M = (L +\
    \ R) / 2;\n      // [i, M) \u306B\u5BFE\u3059\u308B\u8A08\u7B97\u30C7\u30FC\u30BF\
    \n      dat[M] = empty_data;\n      FOR_R(i, L, M) { dat[i] = add_left(i, dat[i\
    \ + 1]); }\n      // [M, R) \u306B\u5BFE\u3059\u308B\u8A08\u7B97\u30C7\u30FC\u30BF\
    \n      int k = M;\n      Data data_r = empty_data;\n      for (auto&& q: I) {\n\
    \        auto [l, r] = query[q];\n        if (r <= M) left.eb(q);\n        elif\
    \ (M < l) right.eb(q);\n        else {\n          while (k < r) data_r = add_right(k++,\
    \ data_r);\n          calc(q, dat[l], data_r);\n        }\n      }\n      if (len(left))\
    \ self(self, L, M, left);\n      if (len(right)) self(self, M, R, right);\n  \
    \  };\n    dat.resize(n + 1);\n    vc<int> I(len(query));\n    iota(all(I), 0);\n\
    \    sort(all(I), [&](auto& x, auto& y) { return query[x].se < query[y].se; });\n\
    \    dfs(dfs, 0, n, I);\n  }\n};\n"
  code: "#pragma once\n\n/*\n\u30FB\u5404 i \u306B\u5BFE\u3057\u3066\u3001[i, m) \u306B\
    \u5BFE\u3059\u308B\u8A08\u7B97\u7D50\u679C\n\u30FB\u5404 j \u306B\u5BFE\u3057\u3066\
    \u3001[m, j) \u306B\u5BFE\u3059\u308B\u8A08\u7B97\u7D50\u679C\n\u304C\u967D\u306B\
    \u6301\u3066\u3066\u3001\u305D\u3053\u304B\u3089\u30AF\u30A8\u30EA [i, j) \u306B\
    \u7B54\u3048\u3089\u308C\u308B\u3068\u304D\u306B\u4F7F\u3048\u308B\u3002\n----\n\
    \u30FB1\u8981\u7D20\u306E\u8FFD\u52A0\uFF1AO(NlogN) \u56DE\u3001\u30C7\u30FC\u30BF\
    \u306E\u30DE\u30FC\u30B8\uFF1AO(Q) \u56DE\u3002\n\u30FB\u5927\u304D\u306A\u30DE\
    \u30FC\u30B8\u306B\u6642\u9593\u304C\u304B\u304B\u308B\u3068\u304D\u306B\u306F\
    \u30BB\u30B0\u6728\u3088\u308A\u9AD8\u901F\u3002\n\u30FBdisjoint sparse table\
    \ \u3068\u540C\u3058\u4ED5\u7D44\u307F\u3060\u304C\u3001\u7701\u30E1\u30E2\u30EA\
    \u3002\n----\nexample\uFF1Axor basis \u306E\u30DE\u30FC\u30B8\nhttps://codeforces.com/contest/1100/submission/153353485\n\
    */\ntemplate <typename Data>\nstruct Divide_Conquer_Range_Query {\n  int n;\n\
    \  vc<pair<int, int>> query;\n  vc<Data> dat;\n\n  Divide_Conquer_Range_Query(int\
    \ n) : n(n) {}\n  void add(int l, int r) {\n    assert(0 <= l && l < r && r <=\
    \ n);\n    query.eb(l, r);\n  }\n\n  // add_left\uFF1A(i, data) -> data\n  //\
    \ add_right\uFF1A(i, data) -> data\n  // calc\uFF1A(q, data_l, data_r) -> data\n\
    \  template <typename AL, typename AR, typename CALC>\n  void calc(Data empty_data,\
    \ AL add_left, AR add_right, CALC calc) {\n    auto dfs = [&](auto self, int L,\
    \ int R, vc<int>& I) -> void {\n      vc<int> left, right;\n      int M = (L +\
    \ R) / 2;\n      // [i, M) \u306B\u5BFE\u3059\u308B\u8A08\u7B97\u30C7\u30FC\u30BF\
    \n      dat[M] = empty_data;\n      FOR_R(i, L, M) { dat[i] = add_left(i, dat[i\
    \ + 1]); }\n      // [M, R) \u306B\u5BFE\u3059\u308B\u8A08\u7B97\u30C7\u30FC\u30BF\
    \n      int k = M;\n      Data data_r = empty_data;\n      for (auto&& q: I) {\n\
    \        auto [l, r] = query[q];\n        if (r <= M) left.eb(q);\n        elif\
    \ (M < l) right.eb(q);\n        else {\n          while (k < r) data_r = add_right(k++,\
    \ data_r);\n          calc(q, dat[l], data_r);\n        }\n      }\n      if (len(left))\
    \ self(self, L, M, left);\n      if (len(right)) self(self, M, R, right);\n  \
    \  };\n    dat.resize(n + 1);\n    vc<int> I(len(query));\n    iota(all(I), 0);\n\
    \    sort(all(I), [&](auto& x, auto& y) { return query[x].se < query[y].se; });\n\
    \    dfs(dfs, 0, n, I);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/divide_conquer_range_query.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/staticrmq_dc.test.cpp
documentation_of: ds/offline_query/divide_conquer_range_query.hpp
layout: document
redirect_from:
- /library/ds/offline_query/divide_conquer_range_query.hpp
- /library/ds/offline_query/divide_conquer_range_query.hpp.html
title: ds/offline_query/divide_conquer_range_query.hpp
---
