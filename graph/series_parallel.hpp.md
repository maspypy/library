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
    - https://codeforces.com/problemset/problem/2206/G
  bundledCode: "#line 1 \"graph/series_parallel.hpp\"\n// https://codeforces.com/problemset/problem/2206/G\n\
    // two-terminal series parallel\n// series:\u6B21\u65702\u306E\u70B9\u304B\u3089\
    \u306A\u308B\u30D1\u30B9\u306E\u7E2E\u7D04\n// parallel:\u591A\u91CD\u8FBA\u306E\
    \u7E2E\u7D04\n// \u3053\u308C\u3092\u4F7F\u3063\u3066\u3072\u3068\u3064\u306E\u8FBA\
    \ st \u306B\u3059\u308B\u4EEE\u5B9A\u3092\u6728\u3067\u8868\u3059\nstruct Series_Parallel\
    \ {\n  enum Etype { EDGE, S, P };\n  struct Node {\n    int s, t;\n    Etype type;\n\
    \    vector<int> ch;\n  };\n\n  int N, M, root;\n  vector<Node> nodes;\n\n  template\
    \ <typename F>\n  Series_Parallel(int N, int M, F f) : N(N), M(M), root(-1) {\n\
    \    VtoE.resize(N), deg.resize(N);\n    FOR(i, M) {\n      auto [a, b] = f(i);\n\
    \      add_node(a, b, Etype::EDGE, {});\n    }\n  }\n\n  // SP graph \u3067\u306A\
    \u304B\u3063\u305F\u3089 false \u304C\u8FD4\u308B\n  bool build(int S, int T)\
    \ {\n    if (deg[S] == 0 || deg[T] == 0) return false;\n    while (1) {\n    \
    \  if (len(queS)) {\n        int v = POP(queS);\n        if (v == S || v == T\
    \ || deg[v] != 2) continue;\n        int a = -1, b = -1;\n        for (auto& idx\
    \ : VtoE[v]) {\n          if (!active[idx]) continue;\n          (a == -1 ? a\
    \ : b) = idx;\n        }\n        int s = nodes[a].s + nodes[a].t - v;\n     \
    \   int t = nodes[b].s + nodes[b].t - v;\n        if (s == t) return false;\n\
    \        deactivate(a), deactivate(b);\n        add_node(s, t, Etype::S, {a, b});\n\
    \        continue;\n      }\n      if (len(queP)) {\n        pair<int, int> k\
    \ = POP(queP);\n        vc<int> E = PtoE[k];\n        if (len(E) <= 1) continue;\n\
    \        assert(len(E) >= 2);\n        PtoE[k].clear();\n        for (auto& idx\
    \ : E) deactivate(idx);\n        add_node(k.fi, k.se, Etype::P, E);\n        continue;\n\
    \      }\n      break;\n    }\n    // success?\n    FOR(i, len(nodes) - 1) if\
    \ (active[i]) return false;\n\n    // normalize\n    vc<bool> vis(len(nodes));\n\
    \    auto dfs = [&](auto& dfs, int i, int s) -> void {\n      vis[i] = 1;\n  \
    \    // nodes[i] \u3092\u6B63\u898F\u5316\n      if (nodes[i].s != s) {\n    \
    \    swap(nodes[i].s, nodes[i].t);\n        reverse(all(nodes[i].ch));\n     \
    \ }\n      assert(nodes[i].s == s);\n      if (nodes[i].type == Etype::EDGE) return;\n\
    \      // \u9055\u3046\u30BF\u30A4\u30D7\u306E\u5B50\u3060\u3051\u3092\u6539\u3081\
    \u3066\u4E26\u3079\u308B\n      vc<int> ch;\n      auto F = [&](auto& F, int j,\
    \ int s) -> void {\n        if (nodes[j].s != s) {\n          swap(nodes[j].s,\
    \ nodes[j].t);\n          reverse(all(nodes[j].ch));\n        }\n        if (nodes[i].type\
    \ != nodes[j].type) {\n          ch.eb(j);\n        } else {\n          int v\
    \ = s;\n          for (int k : nodes[j].ch) {\n            F(F, k, v);\n     \
    \       v = (nodes[j].type == Etype::P ? v : nodes[k].t);\n          }\n     \
    \   }\n      };\n      F(F, i, s);\n      nodes[i].ch = ch;\n      int v = s;\n\
    \      for (auto& c : ch) {\n        dfs(dfs, c, v);\n        v = (nodes[i].type\
    \ == Etype::P ? v : nodes[c].t);\n      }\n    };\n    dfs(dfs, len(nodes) - 1,\
    \ S);\n\n    // \u7121\u8996\u3055\u308C\u305F\u30CE\u30FC\u30C9\u3092\u9664\u5916\
    \n    vc<int> new_idx(len(nodes), -1);\n    int p = 0;\n    FOR(i, len(nodes))\
    \ if (vis[i]) { new_idx[i] = p, nodes[p] = nodes[i], p++; }\n    nodes.resize(p);\n\
    \    FOR(i, p) {\n      for (auto& j : nodes[i].ch) j = new_idx[j];\n    }\n \
    \   root = p - 1;\n    return true;\n  }\n\n private:\n  vc<int> deg;\n  vc<bool>\
    \ active;\n  map<pair<int, int>, vc<int>> PtoE;\n  vvc<int> VtoE;\n  vc<pair<int,\
    \ int>> queP;\n  vc<int> queS;\n\n  void add_node(int s, int t, Etype type, vector<int>\
    \ ch) {\n    if (s > t) {\n      swap(s, t);\n      reverse(all(ch));\n    }\n\
    \    int idx = len(nodes);\n    nodes.eb(Node{s, t, type, ch});\n    active.eb(true);\n\
    \n    // pair -> edges\n    pair<int, int> k = {s, t};\n    PtoE[k].eb(idx);\n\
    \    VtoE[s].eb(idx), VtoE[t].eb(idx);\n    deg[s]++, deg[t]++;\n\n    if (len(PtoE[k])\
    \ >= 2) queP.eb(k);\n    if (deg[s] == 2) queS.eb(s);\n    if (deg[t] == 2) queS.eb(t);\n\
    \  }\n\n  void deactivate(int k) {\n    int s = nodes[k].s, t = nodes[k].t;\n\
    \    deg[s]--, deg[t]--, active[k] = false;\n  }\n};\n"
  code: "// https://codeforces.com/problemset/problem/2206/G\n// two-terminal series\
    \ parallel\n// series:\u6B21\u65702\u306E\u70B9\u304B\u3089\u306A\u308B\u30D1\u30B9\
    \u306E\u7E2E\u7D04\n// parallel:\u591A\u91CD\u8FBA\u306E\u7E2E\u7D04\n// \u3053\
    \u308C\u3092\u4F7F\u3063\u3066\u3072\u3068\u3064\u306E\u8FBA st \u306B\u3059\u308B\
    \u4EEE\u5B9A\u3092\u6728\u3067\u8868\u3059\nstruct Series_Parallel {\n  enum Etype\
    \ { EDGE, S, P };\n  struct Node {\n    int s, t;\n    Etype type;\n    vector<int>\
    \ ch;\n  };\n\n  int N, M, root;\n  vector<Node> nodes;\n\n  template <typename\
    \ F>\n  Series_Parallel(int N, int M, F f) : N(N), M(M), root(-1) {\n    VtoE.resize(N),\
    \ deg.resize(N);\n    FOR(i, M) {\n      auto [a, b] = f(i);\n      add_node(a,\
    \ b, Etype::EDGE, {});\n    }\n  }\n\n  // SP graph \u3067\u306A\u304B\u3063\u305F\
    \u3089 false \u304C\u8FD4\u308B\n  bool build(int S, int T) {\n    if (deg[S]\
    \ == 0 || deg[T] == 0) return false;\n    while (1) {\n      if (len(queS)) {\n\
    \        int v = POP(queS);\n        if (v == S || v == T || deg[v] != 2) continue;\n\
    \        int a = -1, b = -1;\n        for (auto& idx : VtoE[v]) {\n          if\
    \ (!active[idx]) continue;\n          (a == -1 ? a : b) = idx;\n        }\n  \
    \      int s = nodes[a].s + nodes[a].t - v;\n        int t = nodes[b].s + nodes[b].t\
    \ - v;\n        if (s == t) return false;\n        deactivate(a), deactivate(b);\n\
    \        add_node(s, t, Etype::S, {a, b});\n        continue;\n      }\n     \
    \ if (len(queP)) {\n        pair<int, int> k = POP(queP);\n        vc<int> E =\
    \ PtoE[k];\n        if (len(E) <= 1) continue;\n        assert(len(E) >= 2);\n\
    \        PtoE[k].clear();\n        for (auto& idx : E) deactivate(idx);\n    \
    \    add_node(k.fi, k.se, Etype::P, E);\n        continue;\n      }\n      break;\n\
    \    }\n    // success?\n    FOR(i, len(nodes) - 1) if (active[i]) return false;\n\
    \n    // normalize\n    vc<bool> vis(len(nodes));\n    auto dfs = [&](auto& dfs,\
    \ int i, int s) -> void {\n      vis[i] = 1;\n      // nodes[i] \u3092\u6B63\u898F\
    \u5316\n      if (nodes[i].s != s) {\n        swap(nodes[i].s, nodes[i].t);\n\
    \        reverse(all(nodes[i].ch));\n      }\n      assert(nodes[i].s == s);\n\
    \      if (nodes[i].type == Etype::EDGE) return;\n      // \u9055\u3046\u30BF\u30A4\
    \u30D7\u306E\u5B50\u3060\u3051\u3092\u6539\u3081\u3066\u4E26\u3079\u308B\n   \
    \   vc<int> ch;\n      auto F = [&](auto& F, int j, int s) -> void {\n       \
    \ if (nodes[j].s != s) {\n          swap(nodes[j].s, nodes[j].t);\n          reverse(all(nodes[j].ch));\n\
    \        }\n        if (nodes[i].type != nodes[j].type) {\n          ch.eb(j);\n\
    \        } else {\n          int v = s;\n          for (int k : nodes[j].ch) {\n\
    \            F(F, k, v);\n            v = (nodes[j].type == Etype::P ? v : nodes[k].t);\n\
    \          }\n        }\n      };\n      F(F, i, s);\n      nodes[i].ch = ch;\n\
    \      int v = s;\n      for (auto& c : ch) {\n        dfs(dfs, c, v);\n     \
    \   v = (nodes[i].type == Etype::P ? v : nodes[c].t);\n      }\n    };\n    dfs(dfs,\
    \ len(nodes) - 1, S);\n\n    // \u7121\u8996\u3055\u308C\u305F\u30CE\u30FC\u30C9\
    \u3092\u9664\u5916\n    vc<int> new_idx(len(nodes), -1);\n    int p = 0;\n   \
    \ FOR(i, len(nodes)) if (vis[i]) { new_idx[i] = p, nodes[p] = nodes[i], p++; }\n\
    \    nodes.resize(p);\n    FOR(i, p) {\n      for (auto& j : nodes[i].ch) j =\
    \ new_idx[j];\n    }\n    root = p - 1;\n    return true;\n  }\n\n private:\n\
    \  vc<int> deg;\n  vc<bool> active;\n  map<pair<int, int>, vc<int>> PtoE;\n  vvc<int>\
    \ VtoE;\n  vc<pair<int, int>> queP;\n  vc<int> queS;\n\n  void add_node(int s,\
    \ int t, Etype type, vector<int> ch) {\n    if (s > t) {\n      swap(s, t);\n\
    \      reverse(all(ch));\n    }\n    int idx = len(nodes);\n    nodes.eb(Node{s,\
    \ t, type, ch});\n    active.eb(true);\n\n    // pair -> edges\n    pair<int,\
    \ int> k = {s, t};\n    PtoE[k].eb(idx);\n    VtoE[s].eb(idx), VtoE[t].eb(idx);\n\
    \    deg[s]++, deg[t]++;\n\n    if (len(PtoE[k]) >= 2) queP.eb(k);\n    if (deg[s]\
    \ == 2) queS.eb(s);\n    if (deg[t] == 2) queS.eb(t);\n  }\n\n  void deactivate(int\
    \ k) {\n    int s = nodes[k].s, t = nodes[k].t;\n    deg[s]--, deg[t]--, active[k]\
    \ = false;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/series_parallel.hpp
  requiredBy: []
  timestamp: '2026-04-22 03:33:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/series_parallel.hpp
layout: document
redirect_from:
- /library/graph/series_parallel.hpp
- /library/graph/series_parallel.hpp.html
title: graph/series_parallel.hpp
---
