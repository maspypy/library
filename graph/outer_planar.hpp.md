---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/outer_planar.test.cpp
    title: test/1_mytest/outer_planar.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/contest/1656/problem/I
  bundledCode: "#line 1 \"graph/outer_planar.hpp\"\n\n// N>=3, simple \u3092\u524D\
    \u63D0. return: biconnected planar?\nbool check_outerplanar(vc<int> cycle, Graph<int,\
    \ 0> G) {\n  int N = G.N;\n  if (N != len(cycle)) return {};\n  G = G.rearrange(cycle);\n\
    \  vc<pair<int, int>> LR;\n  vc<bool> exist(N);\n  for (auto& e : G.edges) {\n\
    \    int a = e.frm, b = e.to;\n    if (a > b) swap(a, b);\n    if (b == (a + 1)\
    \ % N) {\n      exist[a] = 1;\n    } else {\n      LR.eb(a, b);\n    }\n  }\n\
    \  sort(all(LR), [&](auto& a, auto& b) {\n    if (a.fi != b.fi) return a.fi <\
    \ b.fi;\n    return a.se > b.se;\n  });\n\n  vc<int> st;\n  for (auto [l, r] :\
    \ LR) {\n    while (!st.empty() && st.back() < l) st.pop_back();\n    if (!st.empty())\
    \ {\n      if (l < st.back() && st.back() < r) return false;\n    }\n    st.eb(r);\n\
    \  }\n  return true;\n}\n\n// N>=3. simple biconnected.\n// https://codeforces.com/contest/1656/problem/I\n\
    vc<int> hamilton_cycle_outerplanar(Graph<int, 0>& G) {\n  int N = G.N;\n  assert(N\
    \ >= 3);\n  vc<set<int>> adj(N);\n  for (auto& e : G.edges) {\n    adj[e.frm].emplace(e.to),\
    \ adj[e.to].emplace(e.frm);\n  }\n  vc<bool> exist(N, 1);\n  vc<int> que;\n  FOR(v,\
    \ N) if (len(adj[v]) == 2) que.eb(v);\n\n  vector<tuple<int, int, int>> history;\n\
    \  int n = N;\n  while (n > 2) {\n    if (que.empty()) return {};\n    int x =\
    \ POP(que);\n    if (!exist[x] || len(adj[x]) != 2) continue;\n    int a = *(adj[x].begin());\n\
    \    int b = *(next(adj[x].begin()));\n    if (a == x || b == x || a == b) return\
    \ {};\n    history.eb(x, a, b);\n    adj[x].clear(), exist[x] = 0, --n;\n    adj[a].erase(x),\
    \ adj[b].erase(x);\n    adj[a].emplace(b), adj[b].emplace(a);\n    que.eb(a),\
    \ que.eb(b);\n  }\n  int u = -1, v = -1;\n  FOR(i, N) {\n    if (exist[i]) (u\
    \ == -1 ? u : v) = i;\n  }\n\n  vector<int> nxt(N, -1), pre(N, -1);\n  nxt[u]\
    \ = v, pre[u] = v;\n  nxt[v] = u, pre[v] = u;\n\n  while (len(history)) {\n  \
    \  auto [x, a, b] = POP(history);\n    if (nxt[a] != b) swap(a, b);\n    if (nxt[a]\
    \ == b) {\n      nxt[a] = x, nxt[x] = b, pre[b] = x, pre[x] = a;\n    } else {\n\
    \      return {};\n    }\n  }\n\n  vc<int> V = {0};\n  FOR(N - 1) {\n    V.eb(nxt[V.back()]);\n\
    \    if (V.back() == 0) return {};\n  }\n  return V;\n}\n"
  code: "\n// N>=3, simple \u3092\u524D\u63D0. return: biconnected planar?\nbool check_outerplanar(vc<int>\
    \ cycle, Graph<int, 0> G) {\n  int N = G.N;\n  if (N != len(cycle)) return {};\n\
    \  G = G.rearrange(cycle);\n  vc<pair<int, int>> LR;\n  vc<bool> exist(N);\n \
    \ for (auto& e : G.edges) {\n    int a = e.frm, b = e.to;\n    if (a > b) swap(a,\
    \ b);\n    if (b == (a + 1) % N) {\n      exist[a] = 1;\n    } else {\n      LR.eb(a,\
    \ b);\n    }\n  }\n  sort(all(LR), [&](auto& a, auto& b) {\n    if (a.fi != b.fi)\
    \ return a.fi < b.fi;\n    return a.se > b.se;\n  });\n\n  vc<int> st;\n  for\
    \ (auto [l, r] : LR) {\n    while (!st.empty() && st.back() < l) st.pop_back();\n\
    \    if (!st.empty()) {\n      if (l < st.back() && st.back() < r) return false;\n\
    \    }\n    st.eb(r);\n  }\n  return true;\n}\n\n// N>=3. simple biconnected.\n\
    // https://codeforces.com/contest/1656/problem/I\nvc<int> hamilton_cycle_outerplanar(Graph<int,\
    \ 0>& G) {\n  int N = G.N;\n  assert(N >= 3);\n  vc<set<int>> adj(N);\n  for (auto&\
    \ e : G.edges) {\n    adj[e.frm].emplace(e.to), adj[e.to].emplace(e.frm);\n  }\n\
    \  vc<bool> exist(N, 1);\n  vc<int> que;\n  FOR(v, N) if (len(adj[v]) == 2) que.eb(v);\n\
    \n  vector<tuple<int, int, int>> history;\n  int n = N;\n  while (n > 2) {\n \
    \   if (que.empty()) return {};\n    int x = POP(que);\n    if (!exist[x] || len(adj[x])\
    \ != 2) continue;\n    int a = *(adj[x].begin());\n    int b = *(next(adj[x].begin()));\n\
    \    if (a == x || b == x || a == b) return {};\n    history.eb(x, a, b);\n  \
    \  adj[x].clear(), exist[x] = 0, --n;\n    adj[a].erase(x), adj[b].erase(x);\n\
    \    adj[a].emplace(b), adj[b].emplace(a);\n    que.eb(a), que.eb(b);\n  }\n \
    \ int u = -1, v = -1;\n  FOR(i, N) {\n    if (exist[i]) (u == -1 ? u : v) = i;\n\
    \  }\n\n  vector<int> nxt(N, -1), pre(N, -1);\n  nxt[u] = v, pre[u] = v;\n  nxt[v]\
    \ = u, pre[v] = u;\n\n  while (len(history)) {\n    auto [x, a, b] = POP(history);\n\
    \    if (nxt[a] != b) swap(a, b);\n    if (nxt[a] == b) {\n      nxt[a] = x, nxt[x]\
    \ = b, pre[b] = x, pre[x] = a;\n    } else {\n      return {};\n    }\n  }\n\n\
    \  vc<int> V = {0};\n  FOR(N - 1) {\n    V.eb(nxt[V.back()]);\n    if (V.back()\
    \ == 0) return {};\n  }\n  return V;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/outer_planar.hpp
  requiredBy: []
  timestamp: '2026-02-27 23:10:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/outer_planar.test.cpp
documentation_of: graph/outer_planar.hpp
layout: document
redirect_from:
- /library/graph/outer_planar.hpp
- /library/graph/outer_planar.hpp.html
title: graph/outer_planar.hpp
---
