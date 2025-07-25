---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/bitset/scc_bitset.hpp
    title: graph/bitset/scc_bitset.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/blackbox/scc.hpp\"\n\n// G \u3068\u305D\u306E reverse\
    \ graph \u306B\u5BFE\u3057\u3066 dfs \u3092\u884C\u3046\n// topo\u9806\u306F\u6B63\
    \u3057\u3044\u304C, \u63A2\u7D22\u3067\u898B\u305F\u8FBA\u3092\u96C6\u3081\u3066\
    \u3082 scc_dag \u306F\u5F97\u3089\u308C\u306A\u3044\u306E\u3067\u6CE8\u610F\n\
    // set_used(int v, bool rev)\n// find_used(int v, bool rev)\n// find \u306F set\
    \ \u3088\u308A\u3042\u3068\u306B\u547C\u3070\u308C\u308B. rev=false\u30D5\u30A7\
    \u30FC\u30BA\u3068rev=true\u30D5\u30A7\u30FC\u30BA\u304C\u3042\u308B.\ntemplate\
    \ <typename F1, typename F2>\npair<int, vc<int>> blackbox_scc(int N, F1 set_used,\
    \ F2 find_unused) {\n  vc<int> ord(N);\n  {\n    int nxt = N;\n    vc<bool> vis(N);\n\
    \    auto dfs = [&](auto& dfs, int v) -> void {\n      assert(v < N && !vis[v]);\n\
    \      vis[v] = 1, set_used(v, false);\n      while (1) {\n        int to = find_unused(v,\
    \ false);\n        assert(to < N);\n        if (to == -1) break;\n        dfs(dfs,\
    \ to);\n      }\n      ord[--nxt] = v;\n    };\n    FOR(v, N) if (!vis[v]) dfs(dfs,\
    \ v);\n  }\n  vc<int> comp(N);\n  int nc = 0;\n  vc<bool> vis(N);\n  auto dfs\
    \ = [&](auto& dfs, int v) -> void {\n    vis[v] = 1, comp[v] = nc, set_used(v,\
    \ true);\n    while (1) {\n      int to = find_unused(v, true);\n      assert(to\
    \ < N);\n      if (to == -1) break;\n      dfs(dfs, to);\n    }\n  };\n  for (auto&&\
    \ v : ord) {\n    if (!vis[v]) dfs(dfs, v), ++nc;\n  }\n  return {nc, comp};\n\
    }\n"
  code: "\n// G \u3068\u305D\u306E reverse graph \u306B\u5BFE\u3057\u3066 dfs \u3092\
    \u884C\u3046\n// topo\u9806\u306F\u6B63\u3057\u3044\u304C, \u63A2\u7D22\u3067\u898B\
    \u305F\u8FBA\u3092\u96C6\u3081\u3066\u3082 scc_dag \u306F\u5F97\u3089\u308C\u306A\
    \u3044\u306E\u3067\u6CE8\u610F\n// set_used(int v, bool rev)\n// find_used(int\
    \ v, bool rev)\n// find \u306F set \u3088\u308A\u3042\u3068\u306B\u547C\u3070\u308C\
    \u308B. rev=false\u30D5\u30A7\u30FC\u30BA\u3068rev=true\u30D5\u30A7\u30FC\u30BA\
    \u304C\u3042\u308B.\ntemplate <typename F1, typename F2>\npair<int, vc<int>> blackbox_scc(int\
    \ N, F1 set_used, F2 find_unused) {\n  vc<int> ord(N);\n  {\n    int nxt = N;\n\
    \    vc<bool> vis(N);\n    auto dfs = [&](auto& dfs, int v) -> void {\n      assert(v\
    \ < N && !vis[v]);\n      vis[v] = 1, set_used(v, false);\n      while (1) {\n\
    \        int to = find_unused(v, false);\n        assert(to < N);\n        if\
    \ (to == -1) break;\n        dfs(dfs, to);\n      }\n      ord[--nxt] = v;\n \
    \   };\n    FOR(v, N) if (!vis[v]) dfs(dfs, v);\n  }\n  vc<int> comp(N);\n  int\
    \ nc = 0;\n  vc<bool> vis(N);\n  auto dfs = [&](auto& dfs, int v) -> void {\n\
    \    vis[v] = 1, comp[v] = nc, set_used(v, true);\n    while (1) {\n      int\
    \ to = find_unused(v, true);\n      assert(to < N);\n      if (to == -1) break;\n\
    \      dfs(dfs, to);\n    }\n  };\n  for (auto&& v : ord) {\n    if (!vis[v])\
    \ dfs(dfs, v), ++nc;\n  }\n  return {nc, comp};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/blackbox/scc.hpp
  requiredBy:
  - graph/bitset/scc_bitset.hpp
  timestamp: '2025-07-25 21:12:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/blackbox/scc.hpp
layout: document
redirect_from:
- /library/graph/blackbox/scc.hpp
- /library/graph/blackbox/scc.hpp.html
title: graph/blackbox/scc.hpp
---
