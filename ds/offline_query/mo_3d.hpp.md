---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1476/problem/G
    - https://codeforces.com/contest/940/problem/F
  bundledCode: "#line 1 \"ds/offline_query/mo_3d.hpp\"\n// https://codeforces.com/contest/940/problem/F\r\
    \n// https://codeforces.com/contest/1476/problem/G\r\nstruct Mo_3d {\r\n  vc<tuple<int,\
    \ int, int>> query;\r\n\r\n  void add_query(int t, int l, int r) { query.eb(t,\
    \ l, r); }\r\n\r\n  vc<int> get_mo_order(ll block_sz) {\r\n    constexpr ll K\
    \ = 1 << 20;\r\n    int Q = len(query);\r\n    vi key(Q);\r\n    FOR(q, Q) {\r\
    \n      auto [t, l, r] = query[q];\r\n      t /= block_sz;\r\n      l /= block_sz;\r\
    \n      ll x = r;\r\n      if (l & 1) x = -x;\r\n      x += l * K;\r\n      if\
    \ (t & 1) x = -x;\r\n      x += t * K * K;\r\n      key[q] = x;\r\n    }\r\n \
    \   vc<int> I = argsort(key);\r\n\r\n    // \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\
    \u30B9\u30675\u30D1\u30FC\u30BB\u30F3\u30C8\u7A0B\u5EA6\r\n    auto cost = [&](int\
    \ a, int b) -> int {\r\n      auto [t1, x1, y1] = query[I[a]];\r\n      auto [t2,\
    \ x2, y2] = query[I[b]];\r\n      return abs(t1 - t2) + abs(x1 - x2) + abs(y1\
    \ - y2);\r\n    };\r\n    FOR(k, Q - 5) {\r\n      if (cost(k, k + 2) + cost(k\
    \ + 1, k + 3)\r\n          < cost(k, k + 1) + cost(k + 2, k + 3)) {\r\n      \
    \  swap(I[k + 1], I[k + 2]);\r\n      }\r\n      if (cost(k, k + 3) + cost(k +\
    \ 1, k + 4)\r\n          < cost(k, k + 1) + cost(k + 3, k + 4)) {\r\n        swap(I[k\
    \ + 1], I[k + 3]);\r\n      }\r\n    }\r\n    return I;\r\n  }\r\n\r\n  template\
    \ <typename F1, typename F2, typename F3, typename F4, typename F5,\r\n      \
    \      typename F6, typename F7>\r\n  void calc(F1 ADD_L, F2 ADD_R, F3 RM_L, F4\
    \ RM_R, F5 ADD_CHANGE, F6 RM_CHANGE,\r\n            F7 CALC, ll block_sz = -1)\
    \ {\r\n    if (block_sz == -1) {\r\n      ll Q = max(1LL, len(query));\r\n   \
    \   while (block_sz * block_sz * block_sz < Q * Q) { block_sz++; }\r\n    }\r\n\
    \    auto I = get_mo_order(block_sz);\r\n    ll t = 0, l = 0, r = 0;\r\n    for\
    \ (auto&& qid: I) {\r\n      auto [nt, nl, nr] = query[qid];\r\n      while (l\
    \ > nl) ADD_L(--l);\r\n      while (r < nr) ADD_R(r++);\r\n      while (l < nl)\
    \ RM_L(l++);\r\n      while (r > nr) RM_R(--r);\r\n      while (t < nt) ADD_CHANGE(t++,\
    \ l, r);\r\n      while (t > nt) RM_CHANGE(--t, l, r);\r\n      CALC(qid);\r\n\
    \    }\r\n  }\r\n};\n"
  code: "// https://codeforces.com/contest/940/problem/F\r\n// https://codeforces.com/contest/1476/problem/G\r\
    \nstruct Mo_3d {\r\n  vc<tuple<int, int, int>> query;\r\n\r\n  void add_query(int\
    \ t, int l, int r) { query.eb(t, l, r); }\r\n\r\n  vc<int> get_mo_order(ll block_sz)\
    \ {\r\n    constexpr ll K = 1 << 20;\r\n    int Q = len(query);\r\n    vi key(Q);\r\
    \n    FOR(q, Q) {\r\n      auto [t, l, r] = query[q];\r\n      t /= block_sz;\r\
    \n      l /= block_sz;\r\n      ll x = r;\r\n      if (l & 1) x = -x;\r\n    \
    \  x += l * K;\r\n      if (t & 1) x = -x;\r\n      x += t * K * K;\r\n      key[q]\
    \ = x;\r\n    }\r\n    vc<int> I = argsort(key);\r\n\r\n    // \u30E9\u30F3\u30C0\
    \u30E0\u30B1\u30FC\u30B9\u30675\u30D1\u30FC\u30BB\u30F3\u30C8\u7A0B\u5EA6\r\n\
    \    auto cost = [&](int a, int b) -> int {\r\n      auto [t1, x1, y1] = query[I[a]];\r\
    \n      auto [t2, x2, y2] = query[I[b]];\r\n      return abs(t1 - t2) + abs(x1\
    \ - x2) + abs(y1 - y2);\r\n    };\r\n    FOR(k, Q - 5) {\r\n      if (cost(k,\
    \ k + 2) + cost(k + 1, k + 3)\r\n          < cost(k, k + 1) + cost(k + 2, k +\
    \ 3)) {\r\n        swap(I[k + 1], I[k + 2]);\r\n      }\r\n      if (cost(k, k\
    \ + 3) + cost(k + 1, k + 4)\r\n          < cost(k, k + 1) + cost(k + 3, k + 4))\
    \ {\r\n        swap(I[k + 1], I[k + 3]);\r\n      }\r\n    }\r\n    return I;\r\
    \n  }\r\n\r\n  template <typename F1, typename F2, typename F3, typename F4, typename\
    \ F5,\r\n            typename F6, typename F7>\r\n  void calc(F1 ADD_L, F2 ADD_R,\
    \ F3 RM_L, F4 RM_R, F5 ADD_CHANGE, F6 RM_CHANGE,\r\n            F7 CALC, ll block_sz\
    \ = -1) {\r\n    if (block_sz == -1) {\r\n      ll Q = max(1LL, len(query));\r\
    \n      while (block_sz * block_sz * block_sz < Q * Q) { block_sz++; }\r\n   \
    \ }\r\n    auto I = get_mo_order(block_sz);\r\n    ll t = 0, l = 0, r = 0;\r\n\
    \    for (auto&& qid: I) {\r\n      auto [nt, nl, nr] = query[qid];\r\n      while\
    \ (l > nl) ADD_L(--l);\r\n      while (r < nr) ADD_R(r++);\r\n      while (l <\
    \ nl) RM_L(l++);\r\n      while (r > nr) RM_R(--r);\r\n      while (t < nt) ADD_CHANGE(t++,\
    \ l, r);\r\n      while (t > nt) RM_CHANGE(--t, l, r);\r\n      CALC(qid);\r\n\
    \    }\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/mo_3d.hpp
  requiredBy: []
  timestamp: '2023-01-25 18:10:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/offline_query/mo_3d.hpp
layout: document
redirect_from:
- /library/ds/offline_query/mo_3d.hpp
- /library/ds/offline_query/mo_3d.hpp.html
title: ds/offline_query/mo_3d.hpp
---
