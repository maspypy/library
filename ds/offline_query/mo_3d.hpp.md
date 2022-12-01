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
    - https://codeforces.com/contest/940/problem/F
  bundledCode: "#line 1 \"ds/offline_query/mo_3d.hpp\"\n// https://codeforces.com/contest/940/problem/F\r\
    \ntemplate <typename CHANGE>\r\nstruct Mo_3d {\r\n  int n;\r\n  vc<CHANGE> change;\r\
    \n  vc<tuple<int, int, int>> query;\r\n  vector<pair<int, int>> lr;\r\n\r\n  explicit\
    \ Mo_3d() {}\r\n  int size() { return query.size(); }\r\n\r\n  void add_query(int\
    \ l, int r) {\r\n    int t = len(change) - 1;\r\n    query.eb(t, l, r);\r\n  }\r\
    \n\r\n  void add_change(CHANGE x) { change.eb(x); }\r\n\r\n  vc<int> get_mo_order(ll\
    \ block_sz) {\r\n    constexpr ll K = 1 << 20;\r\n    int Q = len(query);\r\n\
    \    vi key(Q);\r\n    FOR(q, Q) {\r\n      auto [t, l, r] = query[q];\r\n   \
    \   t /= block_sz;\r\n      l /= block_sz;\r\n      ll x = r;\r\n      if (l &\
    \ 1) x = -x;\r\n      x += l * K;\r\n      if (t & 1) x = -x;\r\n      x += t\
    \ * K * K;\r\n      key[q] = x;\r\n    }\r\n    return argsort(key);\r\n  }\r\n\
    \r\n  template <typename F1, typename F2, typename F3, typename F4, typename F5,\r\
    \n            typename F6, typename F7>\r\n  void calc(F1 ADD_L, F2 ADD_R, F3\
    \ RM_L, F4 RM_R, F5 ADD_T, F6 RM_T, F7 CALC,\r\n            ll block_sz = -1)\
    \ {\r\n    if (block_sz == -1) {\r\n      ll Q = max(1LL, len(query));\r\n   \
    \   while (block_sz * block_sz * block_sz < Q * Q) { block_sz++; }\r\n    }\r\n\
    \    auto I = get_mo_order(block_sz);\r\n    ll t = -1, l = 0, r = 0;\r\n    for\
    \ (auto&& qid: I) {\r\n      auto [nt, nl, nr] = query[qid];\r\n      while (l\
    \ > nl) ADD_L(--l);\r\n      while (r < nr) ADD_R(r++);\r\n      while (l < nl)\
    \ RM_L(l++);\r\n      while (r > nr) RM_R(--r);\r\n      while (t < nt) ADD_T(change[++t],\
    \ l, r);\r\n      while (t > nt) RM_T(change[t--], l, r);\r\n      CALC(qid);\r\
    \n    }\r\n  }\r\n};\n"
  code: "// https://codeforces.com/contest/940/problem/F\r\ntemplate <typename CHANGE>\r\
    \nstruct Mo_3d {\r\n  int n;\r\n  vc<CHANGE> change;\r\n  vc<tuple<int, int, int>>\
    \ query;\r\n  vector<pair<int, int>> lr;\r\n\r\n  explicit Mo_3d() {}\r\n  int\
    \ size() { return query.size(); }\r\n\r\n  void add_query(int l, int r) {\r\n\
    \    int t = len(change) - 1;\r\n    query.eb(t, l, r);\r\n  }\r\n\r\n  void add_change(CHANGE\
    \ x) { change.eb(x); }\r\n\r\n  vc<int> get_mo_order(ll block_sz) {\r\n    constexpr\
    \ ll K = 1 << 20;\r\n    int Q = len(query);\r\n    vi key(Q);\r\n    FOR(q, Q)\
    \ {\r\n      auto [t, l, r] = query[q];\r\n      t /= block_sz;\r\n      l /=\
    \ block_sz;\r\n      ll x = r;\r\n      if (l & 1) x = -x;\r\n      x += l * K;\r\
    \n      if (t & 1) x = -x;\r\n      x += t * K * K;\r\n      key[q] = x;\r\n \
    \   }\r\n    return argsort(key);\r\n  }\r\n\r\n  template <typename F1, typename\
    \ F2, typename F3, typename F4, typename F5,\r\n            typename F6, typename\
    \ F7>\r\n  void calc(F1 ADD_L, F2 ADD_R, F3 RM_L, F4 RM_R, F5 ADD_T, F6 RM_T,\
    \ F7 CALC,\r\n            ll block_sz = -1) {\r\n    if (block_sz == -1) {\r\n\
    \      ll Q = max(1LL, len(query));\r\n      while (block_sz * block_sz * block_sz\
    \ < Q * Q) { block_sz++; }\r\n    }\r\n    auto I = get_mo_order(block_sz);\r\n\
    \    ll t = -1, l = 0, r = 0;\r\n    for (auto&& qid: I) {\r\n      auto [nt,\
    \ nl, nr] = query[qid];\r\n      while (l > nl) ADD_L(--l);\r\n      while (r\
    \ < nr) ADD_R(r++);\r\n      while (l < nl) RM_L(l++);\r\n      while (r > nr)\
    \ RM_R(--r);\r\n      while (t < nt) ADD_T(change[++t], l, r);\r\n      while\
    \ (t > nt) RM_T(change[t--], l, r);\r\n      CALC(qid);\r\n    }\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/offline_query/mo_3d.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/offline_query/mo_3d.hpp
layout: document
redirect_from:
- /library/ds/offline_query/mo_3d.hpp
- /library/ds/offline_query/mo_3d.hpp.html
title: ds/offline_query/mo_3d.hpp
---
