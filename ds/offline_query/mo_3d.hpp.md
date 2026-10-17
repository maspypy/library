---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/cf940f.test.cpp
    title: test/1_mytest/cf940f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/contest/1476/problem/G
    - https://codeforces.com/contest/940/problem/F
    - https://github.com/maspypy/library/blob/main/ds/offline_query/mo_3d.hpp
  bundledCode: "#line 1 \"ds/offline_query/mo_3d.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/offline_query/mo_3d.hpp\n\
    // https://codeforces.com/contest/940/problem/F\n// https://codeforces.com/contest/1476/problem/G\n\
    struct Mo_3D {\n  vc<tuple<int, int, int>> query;\n\n  void add_query(int t, int\
    \ l, int r) { query.eb(t, l, r); }\n\n  vc<int> get_mo_order(ll block_sz) {\n\
    \    constexpr ll K = 1 << 20;\n    int Q = len(query);\n    vi key(Q);\n    FOR(q,\
    \ Q) {\n      auto [t, l, r] = query[q];\n      t /= block_sz;\n      l /= block_sz;\n\
    \      ll x = r;\n      if (l & 1) x = -x;\n      x += l * K;\n      if (t & 1)\
    \ x = -x;\n      x += t * K * K;\n      key[q] = x;\n    }\n    vc<int> I = argsort(key);\n\
    \n    // \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\u30B9\u30675\u30D1\u30FC\u30BB\u30F3\
    \u30C8\u7A0B\u5EA6\n    auto cost = [&](int a, int b) -> int {\n      auto [t1,\
    \ x1, y1] = query[I[a]];\n      auto [t2, x2, y2] = query[I[b]];\n      return\
    \ abs(t1 - t2) + abs(x1 - x2) + abs(y1 - y2);\n    };\n    FOR(k, Q - 5) {\n \
    \     if (cost(k, k + 2) + cost(k + 1, k + 3) <\n          cost(k, k + 1) + cost(k\
    \ + 2, k + 3)) {\n        swap(I[k + 1], I[k + 2]);\n      }\n      if (cost(k,\
    \ k + 3) + cost(k + 1, k + 4) <\n          cost(k, k + 1) + cost(k + 3, k + 4))\
    \ {\n        swap(I[k + 1], I[k + 3]);\n      }\n    }\n    return I;\n  }\n\n\
    \  template <typename F1, typename F2, typename F3, typename F4, typename F5,\n\
    \            typename F6, typename F7>\n  void calc(F1 ADD_L, F2 ADD_R, F3 RM_L,\
    \ F4 RM_R, F5 ADD_CHANGE, F6 RM_CHANGE,\n            F7 CALC, ll block_sz = -1)\
    \ {\n    if (block_sz == -1) {\n      ll Q = max(1LL, len(query));\n      while\
    \ (block_sz * block_sz * block_sz < Q * Q) {\n        block_sz++;\n      }\n \
    \   }\n    auto I = get_mo_order(block_sz);\n    ll t = 0, l = 0, r = 0;\n   \
    \ for (auto&& qid : I) {\n      auto [nt, nl, nr] = query[qid];\n      while (l\
    \ > nl) ADD_L(--l);\n      while (r < nr) ADD_R(r++);\n      while (l < nl) RM_L(l++);\n\
    \      while (r > nr) RM_R(--r);\n      while (t < nt) ADD_CHANGE(t++, l, r);\n\
    \      while (t > nt) RM_CHANGE(--t, l, r);\n      CALC(qid);\n    }\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/offline_query/mo_3d.hpp\n\
    // https://codeforces.com/contest/940/problem/F\n// https://codeforces.com/contest/1476/problem/G\n\
    struct Mo_3D {\n  vc<tuple<int, int, int>> query;\n\n  void add_query(int t, int\
    \ l, int r) { query.eb(t, l, r); }\n\n  vc<int> get_mo_order(ll block_sz) {\n\
    \    constexpr ll K = 1 << 20;\n    int Q = len(query);\n    vi key(Q);\n    FOR(q,\
    \ Q) {\n      auto [t, l, r] = query[q];\n      t /= block_sz;\n      l /= block_sz;\n\
    \      ll x = r;\n      if (l & 1) x = -x;\n      x += l * K;\n      if (t & 1)\
    \ x = -x;\n      x += t * K * K;\n      key[q] = x;\n    }\n    vc<int> I = argsort(key);\n\
    \n    // \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\u30B9\u30675\u30D1\u30FC\u30BB\u30F3\
    \u30C8\u7A0B\u5EA6\n    auto cost = [&](int a, int b) -> int {\n      auto [t1,\
    \ x1, y1] = query[I[a]];\n      auto [t2, x2, y2] = query[I[b]];\n      return\
    \ abs(t1 - t2) + abs(x1 - x2) + abs(y1 - y2);\n    };\n    FOR(k, Q - 5) {\n \
    \     if (cost(k, k + 2) + cost(k + 1, k + 3) <\n          cost(k, k + 1) + cost(k\
    \ + 2, k + 3)) {\n        swap(I[k + 1], I[k + 2]);\n      }\n      if (cost(k,\
    \ k + 3) + cost(k + 1, k + 4) <\n          cost(k, k + 1) + cost(k + 3, k + 4))\
    \ {\n        swap(I[k + 1], I[k + 3]);\n      }\n    }\n    return I;\n  }\n\n\
    \  template <typename F1, typename F2, typename F3, typename F4, typename F5,\n\
    \            typename F6, typename F7>\n  void calc(F1 ADD_L, F2 ADD_R, F3 RM_L,\
    \ F4 RM_R, F5 ADD_CHANGE, F6 RM_CHANGE,\n            F7 CALC, ll block_sz = -1)\
    \ {\n    if (block_sz == -1) {\n      ll Q = max(1LL, len(query));\n      while\
    \ (block_sz * block_sz * block_sz < Q * Q) {\n        block_sz++;\n      }\n \
    \   }\n    auto I = get_mo_order(block_sz);\n    ll t = 0, l = 0, r = 0;\n   \
    \ for (auto&& qid : I) {\n      auto [nt, nl, nr] = query[qid];\n      while (l\
    \ > nl) ADD_L(--l);\n      while (r < nr) ADD_R(r++);\n      while (l < nl) RM_L(l++);\n\
    \      while (r > nr) RM_R(--r);\n      while (t < nt) ADD_CHANGE(t++, l, r);\n\
    \      while (t > nt) RM_CHANGE(--t, l, r);\n      CALC(qid);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/mo_3d.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/cf940f.test.cpp
documentation_of: ds/offline_query/mo_3d.hpp
layout: document
redirect_from:
- /library/ds/offline_query/mo_3d.hpp
- /library/ds/offline_query/mo_3d.hpp.html
title: ds/offline_query/mo_3d.hpp
---
