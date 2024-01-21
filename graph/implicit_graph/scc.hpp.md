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
    \ reverse graph \u306B\u5BFE\u3057\u3066 dfs \u3092\u884C\u3046\n// \u63A2\u7D22\
    \u3067\u898B\u305F\u8FBA\u3092\u96C6\u3081\u3066\u3082 scc_dag \u306F\u5F97\u3089\
    \u308C\u306A\u3044\u306E\u3067\u6CE8\u610F\n// set_used(int v, bool rev)\n// find_used(int\
    \ v, bool rev)\ntemplate <typename F1, typename F2>\npair<int, vc<int>> implicit_graph_scc(int\
    \ N, F1 set_used, F2 find_unused) {\n  vc<int> ord(N);\n  {\n    int nxt = N;\n\
    \    vc<bool> vis(N);\n    auto dfs = [&](auto& dfs, int v) -> void {\n      assert(v\
    \ < N && !vis[v]);\n      vis[v] = 1, set_used(v, false);\n      while (1) {\n\
    \        int to = find_unused(v, false);\n        assert(to < N);\n        if\
    \ (to == -1) break;\n        dfs(dfs, to);\n      }\n      ord[--nxt] = v;\n \
    \   };\n    FOR(v, N) if (!vis[v]) dfs(dfs, v);\n  }\n  vc<int> comp(N);\n  int\
    \ nc = 0;\n  vc<bool> vis(N);\n  auto dfs = [&](auto& dfs, int v) -> void {\n\
    \    vis[v] = 1, comp[v] = nc, set_used(v, true);\n    while (1) {\n      int\
    \ to = find_unused(v, true);\n      if (to == -1) break;\n      dfs(dfs, to);\n\
    \    }\n  };\n  for (auto&& v: ord) {\n    if (!vis[v]) dfs(dfs, v), ++nc;\n \
    \ }\n  return {nc, comp};\n}\n"
  code: "\n// G \u3068\u305D\u306E reverse graph \u306B\u5BFE\u3057\u3066 dfs \u3092\
    \u884C\u3046\n// \u63A2\u7D22\u3067\u898B\u305F\u8FBA\u3092\u96C6\u3081\u3066\u3082\
    \ scc_dag \u306F\u5F97\u3089\u308C\u306A\u3044\u306E\u3067\u6CE8\u610F\n// set_used(int\
    \ v, bool rev)\n// find_used(int v, bool rev)\ntemplate <typename F1, typename\
    \ F2>\npair<int, vc<int>> implicit_graph_scc(int N, F1 set_used, F2 find_unused)\
    \ {\n  vc<int> ord(N);\n  {\n    int nxt = N;\n    vc<bool> vis(N);\n    auto\
    \ dfs = [&](auto& dfs, int v) -> void {\n      assert(v < N && !vis[v]);\n   \
    \   vis[v] = 1, set_used(v, false);\n      while (1) {\n        int to = find_unused(v,\
    \ false);\n        assert(to < N);\n        if (to == -1) break;\n        dfs(dfs,\
    \ to);\n      }\n      ord[--nxt] = v;\n    };\n    FOR(v, N) if (!vis[v]) dfs(dfs,\
    \ v);\n  }\n  vc<int> comp(N);\n  int nc = 0;\n  vc<bool> vis(N);\n  auto dfs\
    \ = [&](auto& dfs, int v) -> void {\n    vis[v] = 1, comp[v] = nc, set_used(v,\
    \ true);\n    while (1) {\n      int to = find_unused(v, true);\n      if (to\
    \ == -1) break;\n      dfs(dfs, to);\n    }\n  };\n  for (auto&& v: ord) {\n \
    \   if (!vis[v]) dfs(dfs, v), ++nc;\n  }\n  return {nc, comp};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/implicit_graph/scc.hpp
  requiredBy: []
  timestamp: '2023-12-21 22:18:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/implicit_graph/scc.hpp
layout: document
redirect_from:
- /library/graph/implicit_graph/scc.hpp
- /library/graph/implicit_graph/scc.hpp.html
title: graph/implicit_graph/scc.hpp
---