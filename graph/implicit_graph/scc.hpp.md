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
  bundledCode: "#line 1 \"graph/implicit_graph/scc.hpp\"\n\n// G \u3068\u305D\u306E\
    \ reverse graph \u306B\u5BFE\u3057\u3066 dfs \u3092\u884C\u3046\n// set_used(int\
    \ v, bool rev)\n// find_used(int v, bool rev)\ntemplate <typename F1, typename\
    \ F2>\npair<int, vc<int>> implicit_graph_scc(int N, F1 set_used, F2 find_unused)\
    \ {\n  vc<int> ord(N);\n  {\n    int nxt = N;\n    vc<bool> vis(N);\n    auto\
    \ dfs = [&](auto& dfs, int v) -> void {\n      vis[v] = 1, set_used(v, false);\n\
    \      while (1) {\n        int to = find_unused(v, false);\n        if (to ==\
    \ -1) break;\n        dfs(dfs, to);\n      }\n      ord[--nxt] = v;\n    };\n\
    \    FOR(v, N) if (!vis[v]) dfs(dfs, v);\n  }\n  vc<int> comp(N);\n  int nc =\
    \ 0;\n  vc<bool> vis(N);\n  auto dfs = [&](auto& dfs, int v) -> void {\n    vis[v]\
    \ = 1, comp[v] = nc, set_used(v, true);\n    while (1) {\n      int to = find_unused(v,\
    \ true);\n      if (to == -1) break;\n      dfs(dfs, to);\n    }\n  };\n  for\
    \ (auto&& v: ord) {\n    if (!vis[v]) dfs(dfs, v), ++nc;\n  }\n  return {nc, comp};\n\
    }\n"
  code: "\n// G \u3068\u305D\u306E reverse graph \u306B\u5BFE\u3057\u3066 dfs \u3092\
    \u884C\u3046\n// set_used(int v, bool rev)\n// find_used(int v, bool rev)\ntemplate\
    \ <typename F1, typename F2>\npair<int, vc<int>> implicit_graph_scc(int N, F1\
    \ set_used, F2 find_unused) {\n  vc<int> ord(N);\n  {\n    int nxt = N;\n    vc<bool>\
    \ vis(N);\n    auto dfs = [&](auto& dfs, int v) -> void {\n      vis[v] = 1, set_used(v,\
    \ false);\n      while (1) {\n        int to = find_unused(v, false);\n      \
    \  if (to == -1) break;\n        dfs(dfs, to);\n      }\n      ord[--nxt] = v;\n\
    \    };\n    FOR(v, N) if (!vis[v]) dfs(dfs, v);\n  }\n  vc<int> comp(N);\n  int\
    \ nc = 0;\n  vc<bool> vis(N);\n  auto dfs = [&](auto& dfs, int v) -> void {\n\
    \    vis[v] = 1, comp[v] = nc, set_used(v, true);\n    while (1) {\n      int\
    \ to = find_unused(v, true);\n      if (to == -1) break;\n      dfs(dfs, to);\n\
    \    }\n  };\n  for (auto&& v: ord) {\n    if (!vis[v]) dfs(dfs, v), ++nc;\n \
    \ }\n  return {nc, comp};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/implicit_graph/scc.hpp
  requiredBy: []
  timestamp: '2023-06-11 17:12:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/implicit_graph/scc.hpp
layout: document
redirect_from:
- /library/graph/implicit_graph/scc.hpp
- /library/graph/implicit_graph/scc.hpp.html
title: graph/implicit_graph/scc.hpp
---
