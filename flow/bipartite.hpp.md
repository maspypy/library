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
    - http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf
    - https://en.wikipedia.org/wiki/Dulmage%E2%80%93Mendelsohn_decomposition
    - https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp.html
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/unionfind/unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/base.hpp\"\r\n#include \"graph/check_bipartite.hpp\"\r\n\
    #include \"graph/strongly_connected_component.hpp\"\r\n\r\ntemplate <typename\
    \ GT>\r\nstruct BipartiteMatching {\r\n  int N;\r\n  GT& G;\r\n  vc<int> color;\r\
    \n  vc<int> dist, match;\r\n  vc<int> vis;\r\n\r\n  BipartiteMatching(GT& G) :\
    \ N(G.N), G(G), dist(G.N, -1), match(G.N, -1) {\r\n    color = check_bipartite(G);\r\
    \n    assert(!color.empty());\r\n    while (1) {\r\n      bfs();\r\n      vis.assign(N,\
    \ false);\r\n      int flow = 0;\r\n      FOR(v, N) if (!color[v] && match[v]\
    \ == -1 && dfs(v))++ flow;\r\n      if (!flow) break;\r\n    }\r\n  }\r\n\r\n\
    \  BipartiteMatching(GT& G, vc<int> color)\r\n      : N(G.N), G(G), color(color),\
    \ dist(G.N, -1), match(G.N, -1) {\r\n    while (1) {\r\n      bfs();\r\n     \
    \ vis.assign(N, false);\r\n      int flow = 0;\r\n      FOR(v, N) if (!color[v]\
    \ && match[v] == -1 && dfs(v))++ flow;\r\n      if (!flow) break;\r\n    }\r\n\
    \  }\r\n\r\n  void bfs() {\r\n    dist.assign(N, -1);\r\n    queue<int> que;\r\
    \n    FOR(v, N) if (!color[v] && match[v] == -1) que.emplace(v), dist[v] = 0;\r\
    \n    while (!que.empty()) {\r\n      int v = que.front();\r\n      que.pop();\r\
    \n      for (auto&& e: G[v]) {\r\n        dist[e.to] = 0;\r\n        int w = match[e.to];\r\
    \n        if (w != -1 && dist[w] == -1) dist[w] = dist[v] + 1, que.emplace(w);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  bool dfs(int v) {\r\n    vis[v] = 1;\r\n  \
    \  for (auto&& e: G[v]) {\r\n      int w = match[e.to];\r\n      if (w == -1 ||\
    \ (!vis[w] && dist[w] == dist[v] + 1 && dfs(w))) {\r\n        match[e.to] = v,\
    \ match[v] = e.to;\r\n        return true;\r\n      }\r\n    }\r\n    return false;\r\
    \n  }\r\n\r\n  vc<pair<int, int>> matching() {\r\n    vc<pair<int, int>> res;\r\
    \n    FOR(v, N) if (v < match[v]) res.eb(v, match[v]);\r\n    return res;\r\n\
    \  }\r\n\r\n  vc<int> vertex_cover() {\r\n    vc<int> res;\r\n    FOR(v, N) if\
    \ (color[v] ^ (dist[v] == -1)) { res.eb(v); }\r\n    return res;\r\n  }\r\n\r\n\
    \  vc<int> independent_set() {\r\n    vc<int> res;\r\n    FOR(v, N) if (!(color[v]\
    \ ^ (dist[v] == -1))) { res.eb(v); }\r\n    return res;\r\n  }\r\n\r\n  vc<int>\
    \ edge_cover() {\r\n    vc<bool> done(N);\r\n    vc<int> res;\r\n    for (auto&&\
    \ e: G.edges) {\r\n      if (done[e.frm] || done[e.to]) continue;\r\n      if\
    \ (match[e.frm] == e.to) {\r\n        res.eb(e.id);\r\n        done[e.frm] = done[e.to]\
    \ = 1;\r\n      }\r\n    }\r\n    for (auto&& e: G.edges) {\r\n      if (!done[e.frm])\
    \ {\r\n        res.eb(e.id);\r\n        done[e.frm] = 1;\r\n      }\r\n      if\
    \ (!done[e.to]) {\r\n        res.eb(e.id);\r\n        done[e.to] = 1;\r\n    \
    \  }\r\n    }\r\n    sort(all(res));\r\n    return res;\r\n  }\r\n\r\n  /* Dulmage\u2013\
    Mendelsohn decomposition\r\n  https://en.wikipedia.org/wiki/Dulmage%E2%80%93Mendelsohn_decomposition\r\
    \n  http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf\r\
    \n  https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp.html\r\
    \n  - \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u3068\u3057\u3066\u3042\u308A\
    \u3046\u308B iff \u540C\u3058 W \u3092\u6301\u3064\r\n  - \u8FBA uv \u304C\u5FC5\
    \u305A\u4F7F\u308F\u308C\u308B\uFF1A\u540C\u3058 W \u3092\u6301\u3064\u8FBA\u304C\
    \u552F\u4E00\r\n  - color=0 \u304B\u3089 1 \u3078\u306E\u8FBA\uFF1AW[l] <= W[r]\r\
    \n  - color=0 \u306E\u70B9\u304C\u5FC5\u305A\u4F7F\u308F\u308C\u308B\uFF1AW=0,1,...,K-1\r\
    \n  - color=1 \u306E\u70B9\u304C\u5FC5\u305A\u4F7F\u308F\u308C\u308B\uFF1AW=1,2,...,K\r\
    \n  */\r\n  pair<int, vc<int>> DM_decomposition() {\r\n    // \u975E\u98FD\u548C\
    \u70B9\u304B\u3089\u306E\u63A2\u7D22\r\n    vc<int> W(N, -1);\r\n    int INF =\
    \ N + 10;\r\n    vc<int> que;\r\n    auto add = [&](int v, int x) -> void {\r\n\
    \      if (W[v] == -1) {\r\n        W[v] = x;\r\n        que.eb(v);\r\n      }\r\
    \n    };\r\n    FOR(v, N) if (match[v] == -1 && color[v] == 0) add(v, 0);\r\n\
    \    FOR(v, N) if (match[v] == -1 && color[v] == 1) add(v, INF);\r\n    while\
    \ (len(que)) {\r\n      auto v = pick(que);\r\n      if (match[v] != -1) add(match[v],\
    \ W[v]);\r\n      if (color[v] == 0 && W[v] == 0) {\r\n        for (auto&& e:\
    \ G[v]) { add(e.to, W[v]); }\r\n      }\r\n      if (color[v] == 1 && W[v] ==\
    \ INF) {\r\n        for (auto&& e: G[v]) { add(e.to, W[v]); }\r\n      }\r\n \
    \   }\r\n    // \u6B8B\u3063\u305F\u70B9\u304B\u3089\u306A\u308B\u30B0\u30E9\u30D5\
    \u3092\u4F5C\u3063\u3066\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\r\n    vc<int>\
    \ V;\r\n    FOR(v, N) if (W[v] == -1) V.eb(v);\r\n    int n = len(V);\r\n    Graph<bool,\
    \ 1> DG(n);\r\n    FOR(i, n) {\r\n      int v = V[i];\r\n      if (match[v] !=\
    \ -1) {\r\n        int j = LB(V, match[v]);\r\n        DG.add(i, j);\r\n     \
    \ }\r\n      if (color[v] == 0) {\r\n        for (auto&& e: G[v]) {\r\n      \
    \    if (W[e.to] != -1 || e.to == match[v]) continue;\r\n          int j = LB(V,\
    \ e.to);\r\n          DG.add(i, j);\r\n        }\r\n      }\r\n    }\r\n    DG.build();\r\
    \n    auto [K, comp] = strongly_connected_component(DG);\r\n    K += 1;\r\n  \
    \  // \u7B54\r\n    FOR(i, n) { W[V[i]] = 1 + comp[i]; }\r\n    FOR(v, N) if (W[v]\
    \ == INF) W[v] = K;\r\n    return {K, W};\r\n  }\r\n\r\n  void debug() {\r\n \
    \   print(\"match\", match);\r\n    print(\"min vertex covor\", vertex_cover());\r\
    \n    print(\"max indep set\", independent_set());\r\n    print(\"min edge cover\"\
    , edge_cover());\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/bipartite.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/bipartite.hpp
layout: document
redirect_from:
- /library/flow/bipartite.hpp
- /library/flow/bipartite.hpp.html
title: flow/bipartite.hpp
---
