---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_4_B.test.cpp
    title: test/aoj/DPL_4_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"knapsack/subset_sum_count.hpp\"\n\n/*\nO(2^{N/2})\nsubset\
    \ sum 2^N \u901A\u308A\u306E\u3046\u3061\u3001[lo, hi) \u306B\u5165\u308B\u3082\
    \u306E\u306E\u500B\u6570\n*/\ntemplate <typename T = ll>\nll subset_sum_count(vc<T>\
    \ A, T lo, T hi) {\n  int n = len(A);\n  auto gen = [&](vc<T> A) -> vc<T> {\n\
    \    vc<T> dp = {0};\n    for (auto&& a: A) {\n      vc<T> dp1 = dp;\n      for\
    \ (auto&& t: dp1) t += a;\n      vc<T> newdp;\n      merge(all(dp), all(dp1),\
    \ back_inserter(newdp));\n      swap(dp, newdp);\n    }\n    return dp;\n  };\n\
    \  vc<T> AL = {A.begin(), A.begin() + n / 2};\n  vc<T> AR = {A.begin() + n / 2,\
    \ A.end()};\n  auto dp1 = gen(AL);\n  auto dp2 = gen(AR);\n  auto f = [&](T lim)\
    \ -> ll {\n    int q = len(dp2);\n    ll res = 0;\n    FOR(p, len(dp1)) {\n  \
    \    while (q && dp1[p] + dp2[q - 1] >= lim) --q;\n      res += q;\n    }\n  \
    \  return res;\n  };\n  return f(hi) - f(lo);\n}\n\n/*\nO(2^{N/2})\nsubset sum\
    \ 2^N \u901A\u308A\u306E\u3046\u3061\u3001[lo, hi) \u306B\u5165\u308B\u3082\u306E\
    \u306E\u500B\u6570\u3002\n\u3092\u4F7F\u3046\u500B\u6570\u3054\u3068\u306B\u6C42\
    \u3081\u308B\u3002\n*/\ntemplate <typename T = ll>\nvc<ll> subset_sum_count_by_size(vc<T>\
    \ A, T lo, T hi) {\n  int n = len(A);\n  using P = pair<T, int>;\n  auto gen =\
    \ [&](vc<T> A) -> vc<vc<T>> {\n    vc<P> dp;\n    dp.eb(0, 0);\n    for (auto&&\
    \ a: A) {\n      vc<P> dp1 = dp;\n      for (auto&& t: dp1) t.fi += a, t.se +=\
    \ 1;\n      vc<P> newdp;\n      merge(all(dp), all(dp1), back_inserter(newdp));\n\
    \      swap(dp, newdp);\n    }\n    vc<vc<T>> res(len(A) + 1);\n    for (auto&&\
    \ p: dp) res[p.se].eb(p.fi);\n    return res;\n  };\n  vc<T> AL = {A.begin(),\
    \ A.begin() + n / 2};\n  vc<T> AR = {A.begin() + n / 2, A.end()};\n  auto dp1\
    \ = gen(AL);\n  auto dp2 = gen(AR);\n\n  auto f = [&](T lim) -> vi {\n    vi res(n\
    \ + 1);\n    FOR(s1, len(dp1)) FOR(s2, len(dp2)) {\n      auto& X = dp1[s1];\n\
    \      auto& Y = dp2[s2];\n      int q = len(Y);\n      ll& cnt = res[s1 + s2];\n\
    \      for (auto&& x: X) {\n        while (q && x + Y[q - 1] >= lim) --q;\n  \
    \      cnt += q;\n      }\n    }\n    return res;\n  };\n  auto CNT1 = f(hi);\n\
    \  auto CNT2 = f(lo);\n  FOR(i, len(CNT1)) CNT1[i] -= CNT2[i];\n  return CNT1;\n\
    }\n"
  code: "#pragma once\n\n/*\nO(2^{N/2})\nsubset sum 2^N \u901A\u308A\u306E\u3046\u3061\
    \u3001[lo, hi) \u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\n*/\ntemplate\
    \ <typename T = ll>\nll subset_sum_count(vc<T> A, T lo, T hi) {\n  int n = len(A);\n\
    \  auto gen = [&](vc<T> A) -> vc<T> {\n    vc<T> dp = {0};\n    for (auto&& a:\
    \ A) {\n      vc<T> dp1 = dp;\n      for (auto&& t: dp1) t += a;\n      vc<T>\
    \ newdp;\n      merge(all(dp), all(dp1), back_inserter(newdp));\n      swap(dp,\
    \ newdp);\n    }\n    return dp;\n  };\n  vc<T> AL = {A.begin(), A.begin() + n\
    \ / 2};\n  vc<T> AR = {A.begin() + n / 2, A.end()};\n  auto dp1 = gen(AL);\n \
    \ auto dp2 = gen(AR);\n  auto f = [&](T lim) -> ll {\n    int q = len(dp2);\n\
    \    ll res = 0;\n    FOR(p, len(dp1)) {\n      while (q && dp1[p] + dp2[q - 1]\
    \ >= lim) --q;\n      res += q;\n    }\n    return res;\n  };\n  return f(hi)\
    \ - f(lo);\n}\n\n/*\nO(2^{N/2})\nsubset sum 2^N \u901A\u308A\u306E\u3046\u3061\
    \u3001[lo, hi) \u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\u3002\n\u3092\u4F7F\
    \u3046\u500B\u6570\u3054\u3068\u306B\u6C42\u3081\u308B\u3002\n*/\ntemplate <typename\
    \ T = ll>\nvc<ll> subset_sum_count_by_size(vc<T> A, T lo, T hi) {\n  int n = len(A);\n\
    \  using P = pair<T, int>;\n  auto gen = [&](vc<T> A) -> vc<vc<T>> {\n    vc<P>\
    \ dp;\n    dp.eb(0, 0);\n    for (auto&& a: A) {\n      vc<P> dp1 = dp;\n    \
    \  for (auto&& t: dp1) t.fi += a, t.se += 1;\n      vc<P> newdp;\n      merge(all(dp),\
    \ all(dp1), back_inserter(newdp));\n      swap(dp, newdp);\n    }\n    vc<vc<T>>\
    \ res(len(A) + 1);\n    for (auto&& p: dp) res[p.se].eb(p.fi);\n    return res;\n\
    \  };\n  vc<T> AL = {A.begin(), A.begin() + n / 2};\n  vc<T> AR = {A.begin() +\
    \ n / 2, A.end()};\n  auto dp1 = gen(AL);\n  auto dp2 = gen(AR);\n\n  auto f =\
    \ [&](T lim) -> vi {\n    vi res(n + 1);\n    FOR(s1, len(dp1)) FOR(s2, len(dp2))\
    \ {\n      auto& X = dp1[s1];\n      auto& Y = dp2[s2];\n      int q = len(Y);\n\
    \      ll& cnt = res[s1 + s2];\n      for (auto&& x: X) {\n        while (q &&\
    \ x + Y[q - 1] >= lim) --q;\n        cnt += q;\n      }\n    }\n    return res;\n\
    \  };\n  auto CNT1 = f(hi);\n  auto CNT2 = f(lo);\n  FOR(i, len(CNT1)) CNT1[i]\
    \ -= CNT2[i];\n  return CNT1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: knapsack/subset_sum_count.hpp
  requiredBy: []
  timestamp: '2023-03-24 19:49:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_4_B.test.cpp
documentation_of: knapsack/subset_sum_count.hpp
layout: document
redirect_from:
- /library/knapsack/subset_sum_count.hpp
- /library/knapsack/subset_sum_count.hpp.html
title: knapsack/subset_sum_count.hpp
---
