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
    - https://codeforces.com/contest/164/problem/D
  bundledCode: "#line 1 \"graph/find_vertex_cover.hpp\"\n\n// \u5927\u304D\u3055 K\
    \ \u4EE5\u4E0B\u306E\u9802\u70B9\u88AB\u8986\u304C\u3042\u308C\u3070\u305D\u308C\
    \u3092\u8FD4\u3059\n// NK*1.618^K \u304F\u3089\u3044\n// path-cycle \u3092\u4F55\
    \u3068\u304B\u3059\u308B\u3068\u3082\u3063\u3068\u65E9\u304F\u306A\u308B\n// \u30B0\
    \u30E9\u30D5\u306E\u6301\u3061\u65B9\u304C\u3044\u307E\u3044\u3061\u304B\u3082\
    \n// https://codeforces.com/contest/164/problem/D\ntemplate <typename GT>\nvc<int>\
    \ find_vertex_cover(GT G, int K) {\n  int N = G.N;\n  vv(bool, adj, N, N);\n \
    \ for (auto& e: G.edges) {\n    assert(e.frm != e.to);\n    adj[e.frm][e.to] =\
    \ adj[e.to][e.frm] = 1;\n  }\n  vc<int> deg(N);\n  FOR(v, N) deg[v] = SUM<int>(adj[v]);\n\
    \n  if (K == 0) return {};\n\n  vc<bool> used(N);\n  vc<int> S;\n  bool end =\
    \ 0;\n  int M = SUM<int>(deg) / 2;\n\n  auto on = [&](int v) -> void {\n    assert(!used[v]);\n\
    \    M -= deg[v];\n    FOR(w, N) {\n      if (!used[w] && adj[v][w]) { deg[v]--,\
    \ deg[w]--; }\n    }\n    assert(deg[v] == 0);\n    used[v] = 1;\n    S.eb(v);\n\
    \  };\n  auto off = [&](int v) -> void {\n    assert(S.back() == v);\n    S.pop_back();\n\
    \    used[v] = 0;\n    FOR(w, N) {\n      if (!used[w] && adj[v][w]) { deg[v]++,\
    \ deg[w]++; }\n    }\n    M += deg[v];\n  };\n\n  auto dfs = [&](auto& dfs) ->\
    \ void {\n    if (end) return;\n    int c = max_element(all(deg)) - deg.begin();\n\
    \    if (deg[c] * (K - len(S)) < M) { return; }\n    if (deg[c] == 0) {\n    \
    \  assert(M == 0);\n      end = 1;\n      return;\n    }\n    if (len(S) == K)\
    \ { return; }\n    on(c);\n    dfs(dfs);\n    if (end) return;\n    off(c);\n\
    \    if (deg[c] == 1) return;\n    if (len(S) + deg[c] > K) return;\n    int k\
    \ = len(S);\n    FOR(v, N) {\n      if (adj[v][c] && !used[v]) { on(v); }\n  \
    \  }\n    dfs(dfs);\n    if (end) return;\n    while (len(S) > k) { off(S.back());\
    \ }\n  };\n  dfs(dfs);\n  if (!end) assert(S.empty());\n  return S;\n}\n"
  code: "\n// \u5927\u304D\u3055 K \u4EE5\u4E0B\u306E\u9802\u70B9\u88AB\u8986\u304C\
    \u3042\u308C\u3070\u305D\u308C\u3092\u8FD4\u3059\n// NK*1.618^K \u304F\u3089\u3044\
    \n// path-cycle \u3092\u4F55\u3068\u304B\u3059\u308B\u3068\u3082\u3063\u3068\u65E9\
    \u304F\u306A\u308B\n// \u30B0\u30E9\u30D5\u306E\u6301\u3061\u65B9\u304C\u3044\u307E\
    \u3044\u3061\u304B\u3082\n// https://codeforces.com/contest/164/problem/D\ntemplate\
    \ <typename GT>\nvc<int> find_vertex_cover(GT G, int K) {\n  int N = G.N;\n  vv(bool,\
    \ adj, N, N);\n  for (auto& e: G.edges) {\n    assert(e.frm != e.to);\n    adj[e.frm][e.to]\
    \ = adj[e.to][e.frm] = 1;\n  }\n  vc<int> deg(N);\n  FOR(v, N) deg[v] = SUM<int>(adj[v]);\n\
    \n  if (K == 0) return {};\n\n  vc<bool> used(N);\n  vc<int> S;\n  bool end =\
    \ 0;\n  int M = SUM<int>(deg) / 2;\n\n  auto on = [&](int v) -> void {\n    assert(!used[v]);\n\
    \    M -= deg[v];\n    FOR(w, N) {\n      if (!used[w] && adj[v][w]) { deg[v]--,\
    \ deg[w]--; }\n    }\n    assert(deg[v] == 0);\n    used[v] = 1;\n    S.eb(v);\n\
    \  };\n  auto off = [&](int v) -> void {\n    assert(S.back() == v);\n    S.pop_back();\n\
    \    used[v] = 0;\n    FOR(w, N) {\n      if (!used[w] && adj[v][w]) { deg[v]++,\
    \ deg[w]++; }\n    }\n    M += deg[v];\n  };\n\n  auto dfs = [&](auto& dfs) ->\
    \ void {\n    if (end) return;\n    int c = max_element(all(deg)) - deg.begin();\n\
    \    if (deg[c] * (K - len(S)) < M) { return; }\n    if (deg[c] == 0) {\n    \
    \  assert(M == 0);\n      end = 1;\n      return;\n    }\n    if (len(S) == K)\
    \ { return; }\n    on(c);\n    dfs(dfs);\n    if (end) return;\n    off(c);\n\
    \    if (deg[c] == 1) return;\n    if (len(S) + deg[c] > K) return;\n    int k\
    \ = len(S);\n    FOR(v, N) {\n      if (adj[v][c] && !used[v]) { on(v); }\n  \
    \  }\n    dfs(dfs);\n    if (end) return;\n    while (len(S) > k) { off(S.back());\
    \ }\n  };\n  dfs(dfs);\n  if (!end) assert(S.empty());\n  return S;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/find_vertex_cover.hpp
  requiredBy: []
  timestamp: '2024-03-29 11:46:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/find_vertex_cover.hpp
layout: document
redirect_from:
- /library/graph/find_vertex_cover.hpp
- /library/graph/find_vertex_cover.hpp.html
title: graph/find_vertex_cover.hpp
---
