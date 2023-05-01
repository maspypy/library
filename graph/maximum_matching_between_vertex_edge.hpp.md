---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/maximum_matching_between_vertex_edge.hpp\"\n// (v_i,\
    \ e_i)\ntemplate <typename GT>\nvector<pair<int, int>> maximum_matching_between_vertex_edge(GT&\
    \ G) {\n  assert(!G.is_directed());\n  assert(G.is_prepared());\n  const int N\
    \ = G.N, M = G.M;\n  vc<int> match(M, -1);\n  vc<int> par(N, -1); // eid\n  vc<bool>\
    \ used(M);\n  vc<bool> vis(N);\n\n  FOR(root, N) {\n    if (vis[root]) continue;\n\
    \    int back_e = -1;\n    int frm = -1, to = -1;\n    auto dfs = [&](auto& dfs,\
    \ int v) -> void {\n      for (auto&& e: G[v]) {\n        if (used[e.id]) continue;\n\
    \        used[e.id] = 1;\n        if (vis[e.to]) {\n          back_e = e.id;\n\
    \          frm = v, to = e.to;\n        } else {\n          match[e.id] = e.to;\n\
    \          vis[e.to] = 1;\n          par[e.to] = e.id;\n          dfs(dfs, e.to);\n\
    \        }\n      }\n    };\n    vis[root] = 1;\n    dfs(dfs, root);\n    if (back_e\
    \ == -1) continue;\n    match[back_e] = to;\n    int x = to;\n    while (x !=\
    \ root) {\n      int eid = par[x];\n      x = G.edges[eid].frm + G.edges[eid].to\
    \ - x;\n      match[eid] = x;\n    }\n  }\n  vc<pair<int, int>> ANS;\n  FOR(i,\
    \ M) if (match[i] != -1) ANS.eb(match[i], i);\n  return ANS;\n}\n"
  code: "// (v_i, e_i)\ntemplate <typename GT>\nvector<pair<int, int>> maximum_matching_between_vertex_edge(GT&\
    \ G) {\n  assert(!G.is_directed());\n  assert(G.is_prepared());\n  const int N\
    \ = G.N, M = G.M;\n  vc<int> match(M, -1);\n  vc<int> par(N, -1); // eid\n  vc<bool>\
    \ used(M);\n  vc<bool> vis(N);\n\n  FOR(root, N) {\n    if (vis[root]) continue;\n\
    \    int back_e = -1;\n    int frm = -1, to = -1;\n    auto dfs = [&](auto& dfs,\
    \ int v) -> void {\n      for (auto&& e: G[v]) {\n        if (used[e.id]) continue;\n\
    \        used[e.id] = 1;\n        if (vis[e.to]) {\n          back_e = e.id;\n\
    \          frm = v, to = e.to;\n        } else {\n          match[e.id] = e.to;\n\
    \          vis[e.to] = 1;\n          par[e.to] = e.id;\n          dfs(dfs, e.to);\n\
    \        }\n      }\n    };\n    vis[root] = 1;\n    dfs(dfs, root);\n    if (back_e\
    \ == -1) continue;\n    match[back_e] = to;\n    int x = to;\n    while (x !=\
    \ root) {\n      int eid = par[x];\n      x = G.edges[eid].frm + G.edges[eid].to\
    \ - x;\n      match[eid] = x;\n    }\n  }\n  vc<pair<int, int>> ANS;\n  FOR(i,\
    \ M) if (match[i] != -1) ANS.eb(match[i], i);\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/maximum_matching_between_vertex_edge.hpp
  requiredBy: []
  timestamp: '2023-05-01 17:28:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/maximum_matching_between_vertex_edge.hpp
layout: document
redirect_from:
- /library/graph/maximum_matching_between_vertex_edge.hpp
- /library/graph/maximum_matching_between_vertex_edge.hpp.html
title: graph/maximum_matching_between_vertex_edge.hpp
---
