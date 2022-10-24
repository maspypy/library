---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/tdpc_grid_dp.test.cpp
    title: test/mytest/tdpc_grid_dp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1561.test.cpp
    title: test/yukicoder/1561.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"connected_dp/squares.hpp\"\nnamespace connected_dp_squares\
    \ {\n// pair<\u65B0\u3057\u3044\u72B6\u614B\u3001\u4ECA\u306E\u6210\u5206 \u2192\
    \ \u65B0\u3057\u3044\u6210\u5206>\nvc<pair<vc<int>, vc<int>>> next_states(const\
    \ vc<int>& now) {\n  int N = len(now);\n  vc<pair<vc<int>, vc<int>>> res;\n  FOR(s,\
    \ 1 << N) {\n    vc<int> par(N + N);\n    FOR(i, N) par[i] = (s & 1 << i ? i :\
    \ -1);\n    FOR(i, N) par[N + i] = (now[i] == -1 ? -1 : now[i] + N);\n    auto\
    \ find = [&](int x) -> int {\n      while (par[x] != x) { x = par[x] = par[par[x]];\
    \ }\n      return x;\n    };\n    auto merge = [&](int a, int b) -> void {\n \
    \     a = find(a), b = find(b);\n      if (a == b) return;\n      if (a > b) swap(a,\
    \ b);\n      par[b] = a;\n    };\n\n    FOR(i, N - 1) if (par[i] != -1 && par[i\
    \ + 1] != -1) merge(i, i + 1);\n    FOR(i, N) if (par[i] != -1 && par[N + i] !=\
    \ -1) merge(i, N + i);\n    FOR(i, N + N) if (par[i] != -1) par[i] = find(i);\n\
    \    FOR(i, N, N + N) if (par[i] >= N) par[i] = -1;\n    res.eb(vc<int>(par.begin(),\
    \ par.begin() + N),\n           vc<int>(par.begin() + N, par.end()));\n  }\n \
    \ return res;\n}\n\nvc<int> reverse_state(const vc<int>& now) {\n  int N = len(now);\n\
    \  vc<int> max_i(N, -1);\n  FOR(i, N) if (now[i] != -1) max_i[now[i]] = i;\n \
    \ vc<int> rev(N, -1);\n  FOR(i, N) {\n    if (now[i] == -1) continue;\n    int\
    \ x = max_i[now[i]];\n    rev[N - 1 - i] = N - 1 - x;\n  }\n  return rev;\n}\n\
    \n// 0, 1 \uFF1A\u7A7A\u306E\u5217\u3001\u9818\u57DF\u306E\u624B\u524D\u3001\u5F8C\
    \u308D\n// \u9023\u7D50\u9818\u57DF\u3092\u3072\u3068\u3064\u4F5C\u308B\u3002\u591A\
    \u89D2\u5F62\u3068\u306F\u9650\u3089\u306A\u3044\u3002\npair<vvc<int>, vc<pair<int,\
    \ int>>> connedted_dp_graph(int N,\n                                         \
    \             bool merge_reverse) {\n  static HashMapLL<int> MP;\n  MP.reset();\n\
    \  vvc<int> states;\n  vc<pair<int, int>> edges;\n\n  states.eb(vc<int>(N, -1));\n\
    \  states.eb(vc<int>(N, -1));\n  MP[hash_vector<int>(states[0])] = 0;\n\n  int\
    \ p = -1;\n  while (1) {\n    if (++p == len(states)) break;\n    if (p == 1)\
    \ {\n      edges.eb(1, 1);\n      continue;\n    }\n    vc<int> now = states[p];\n\
    \    for (auto&& [nxt, convert]: next_states(now)) {\n      // \u4ECA\u306E\u6210\
    \u5206\u6570\u3001\u6D88\u3048\u308B\u6210\u5206\u6570\n      int a = 0, b = 0;\n\
    \      FOR(v, N) if (now[v] == v) {\n        ++a;\n        if (convert[v] == -1)\
    \ ++b;\n      }\n      // \u6D88\u3048\u308B\u6210\u5206\u304C\u3042\u3063\u3066\
    \u3088\u3044\u306E\u306F\u3001\u7D42\u72B6\u614B\u306B\u3044\u304F\u3068\u304D\
    \u306E\u307F\n      if (b >= 2) continue;\n      if (b == 1) {\n        if (MAX(nxt)\
    \ != -1) continue;\n        edges.eb(p, 1);\n        continue;\n      }\n    \
    \  ll h = hash_vector<int>(nxt);\n      if (merge_reverse) { chmin(h, hash_vector<int>(reverse_state(nxt)));\
    \ }\n      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt);\n\
    \      }\n      edges.eb(p, MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\
    } // namespace connected_dp_squares\n"
  code: "namespace connected_dp_squares {\n// pair<\u65B0\u3057\u3044\u72B6\u614B\u3001\
    \u4ECA\u306E\u6210\u5206 \u2192 \u65B0\u3057\u3044\u6210\u5206>\nvc<pair<vc<int>,\
    \ vc<int>>> next_states(const vc<int>& now) {\n  int N = len(now);\n  vc<pair<vc<int>,\
    \ vc<int>>> res;\n  FOR(s, 1 << N) {\n    vc<int> par(N + N);\n    FOR(i, N) par[i]\
    \ = (s & 1 << i ? i : -1);\n    FOR(i, N) par[N + i] = (now[i] == -1 ? -1 : now[i]\
    \ + N);\n    auto find = [&](int x) -> int {\n      while (par[x] != x) { x =\
    \ par[x] = par[par[x]]; }\n      return x;\n    };\n    auto merge = [&](int a,\
    \ int b) -> void {\n      a = find(a), b = find(b);\n      if (a == b) return;\n\
    \      if (a > b) swap(a, b);\n      par[b] = a;\n    };\n\n    FOR(i, N - 1)\
    \ if (par[i] != -1 && par[i + 1] != -1) merge(i, i + 1);\n    FOR(i, N) if (par[i]\
    \ != -1 && par[N + i] != -1) merge(i, N + i);\n    FOR(i, N + N) if (par[i] !=\
    \ -1) par[i] = find(i);\n    FOR(i, N, N + N) if (par[i] >= N) par[i] = -1;\n\
    \    res.eb(vc<int>(par.begin(), par.begin() + N),\n           vc<int>(par.begin()\
    \ + N, par.end()));\n  }\n  return res;\n}\n\nvc<int> reverse_state(const vc<int>&\
    \ now) {\n  int N = len(now);\n  vc<int> max_i(N, -1);\n  FOR(i, N) if (now[i]\
    \ != -1) max_i[now[i]] = i;\n  vc<int> rev(N, -1);\n  FOR(i, N) {\n    if (now[i]\
    \ == -1) continue;\n    int x = max_i[now[i]];\n    rev[N - 1 - i] = N - 1 - x;\n\
    \  }\n  return rev;\n}\n\n// 0, 1 \uFF1A\u7A7A\u306E\u5217\u3001\u9818\u57DF\u306E\
    \u624B\u524D\u3001\u5F8C\u308D\n// \u9023\u7D50\u9818\u57DF\u3092\u3072\u3068\u3064\
    \u4F5C\u308B\u3002\u591A\u89D2\u5F62\u3068\u306F\u9650\u3089\u306A\u3044\u3002\
    \npair<vvc<int>, vc<pair<int, int>>> connedted_dp_graph(int N,\n             \
    \                                         bool merge_reverse) {\n  static HashMapLL<int>\
    \ MP;\n  MP.reset();\n  vvc<int> states;\n  vc<pair<int, int>> edges;\n\n  states.eb(vc<int>(N,\
    \ -1));\n  states.eb(vc<int>(N, -1));\n  MP[hash_vector<int>(states[0])] = 0;\n\
    \n  int p = -1;\n  while (1) {\n    if (++p == len(states)) break;\n    if (p\
    \ == 1) {\n      edges.eb(1, 1);\n      continue;\n    }\n    vc<int> now = states[p];\n\
    \    for (auto&& [nxt, convert]: next_states(now)) {\n      // \u4ECA\u306E\u6210\
    \u5206\u6570\u3001\u6D88\u3048\u308B\u6210\u5206\u6570\n      int a = 0, b = 0;\n\
    \      FOR(v, N) if (now[v] == v) {\n        ++a;\n        if (convert[v] == -1)\
    \ ++b;\n      }\n      // \u6D88\u3048\u308B\u6210\u5206\u304C\u3042\u3063\u3066\
    \u3088\u3044\u306E\u306F\u3001\u7D42\u72B6\u614B\u306B\u3044\u304F\u3068\u304D\
    \u306E\u307F\n      if (b >= 2) continue;\n      if (b == 1) {\n        if (MAX(nxt)\
    \ != -1) continue;\n        edges.eb(p, 1);\n        continue;\n      }\n    \
    \  ll h = hash_vector<int>(nxt);\n      if (merge_reverse) { chmin(h, hash_vector<int>(reverse_state(nxt)));\
    \ }\n      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt);\n\
    \      }\n      edges.eb(p, MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\
    } // namespace connected_dp_squares"
  dependsOn: []
  isVerificationFile: false
  path: connected_dp/squares.hpp
  requiredBy: []
  timestamp: '2022-10-24 20:02:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/tdpc_grid_dp.test.cpp
  - test/yukicoder/1561.test.cpp
documentation_of: connected_dp/squares.hpp
layout: document
redirect_from:
- /library/connected_dp/squares.hpp
- /library/connected_dp/squares.hpp.html
title: connected_dp/squares.hpp
---
