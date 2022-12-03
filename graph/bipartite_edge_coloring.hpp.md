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
  code: "#include \"graph/check_bipartite.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\
    \n#include \"flow/bipartite.hpp\"\n\nstruct RegularBipartiteColoring {\n  using\
    \ P = pair<int, int>;\n  int N, M;\n  vc<P> edges;\n\n  vvc<int> solve(int n,\
    \ int k, vc<P> G) {\n    N = n;\n    M = len(G);\n    edges = G;\n    vc<int>\
    \ A(M);\n    iota(all(A), 0);\n    return solve_inner(M / N, A);\n  }\n\n  vvc<int>\
    \ solve_inner(int k, vc<int> A) {\n    return (k % 2 == 0 ? solve_even(k, A) :\
    \ solve_odd(k, A));\n  }\n\n  vvc<int> solve_even(int k, vc<int> A) {\n    assert(k\
    \ % 2 == 0);\n    if (k == 0) return {};\n    // 2^m <= k < 2^{m+1}\n    int m\
    \ = 0;\n    while (1 << (m + 1) <= k) ++m;\n    vvc<int> res;\n    if (k != 1\
    \ << m) {\n      auto [B, C] = split(k, A);\n      auto dat = solve_inner(k /\
    \ 2, C);\n      FOR(j, k - (1 << m)) { res.eb(dat[j]); }\n      FOR(j, k - (1\
    \ << m), len(dat)) {\n        for (auto&& idx: dat[j]) B.eb(idx);\n      }\n \
    \     k = 1 << m;\n      swap(A, B);\n    }\n    auto dfs = [&](auto& dfs, int\
    \ K, vc<int> A) -> void {\n      if (K == 1) {\n        res.eb(A);\n        return;\n\
    \      }\n      auto [B, C] = split(k, A);\n      dfs(dfs, K / 2, B);\n      dfs(dfs,\
    \ K / 2, C);\n    };\n    dfs(dfs, k, A);\n    return res;\n  }\n\n  vvc<int>\
    \ solve_odd(int k, vc<int> A) {\n    assert(k % 2 == 1);\n    if (k == 1) { return\
    \ {A}; }\n    vc<bool> match = matching(k, A);\n    vc<int> B;\n    B.reserve(len(A)\
    \ - N);\n    vc<int> es;\n    FOR(i, len(A)) {\n      if (match[i]) es.eb(A[i]);\n\
    \      if (!match[i]) B.eb(A[i]);\n    }\n    vvc<int> res = solve_inner(k - 1,\
    \ B);\n    res.eb(es);\n    return res;\n  }\n\n  vc<bool> matching(int k, vc<int>\
    \ A) {\n    Graph<bool, 0> G(N + N);\n    vc<int> color(N + N);\n    FOR(v, N)\
    \ color[v] = 0;\n    for (auto&& eid: A) {\n      auto [a, b] = edges[eid];\n\
    \      G.add(a, b);\n    }\n    G.build();\n    BipartiteMatching<decltype(G)>\
    \ BM(G);\n    auto& match = BM.match;\n    vc<bool> res(len(A));\n    FOR(i, len(A))\
    \ {\n      auto idx = A[i];\n      auto [a, b] = edges[idx];\n      if (match[a]\
    \ == b) {\n        match[a] = -1;\n        res[i] = 1;\n      }\n    }\n    return\
    \ res;\n  }\n\n  pair<vc<int>, vc<int>> split(int k, vc<int> A) {\n    assert(k\
    \ % 2 == 0);\n    // 2 \u3064\u306E k/2 - regular \u306B\u5206\u5272\u3059\u308B\
    \u3002\n    int n = len(A);\n    vc<bool> rest(n);\n    vc<int> A0, A1;\n    A0.reserve(n\
    \ / 2), A1.reserve(n / 2);\n    vvc<P> G(N + N);\n    FOR(i, n) {\n      rest[i]\
    \ = 1;\n      auto [a, b] = edges[A[i]];\n      G[a].eb(i, b);\n      G[b].eb(i,\
    \ a);\n    }\n    auto dfs = [&](auto& dfs, int v, int color) -> void {\n    \
    \  while (len(G[v])) {\n        auto [i, to] = pick(G[v]);\n        if (!rest[i])\
    \ continue;\n        rest[i] = 0;\n        if (color == 0) A0.eb(A[i]);\n    \
    \    if (color == 1) A1.eb(A[i]);\n        dfs(dfs, to, 1 ^ color);\n      }\n\
    \    };\n    FOR(v, N) dfs(dfs, v, 0);\n    return {A0, A1};\n  }\n};\n\ntemplate\
    \ <typename GT>\npair<int, vc<int>> bipartite_edge_coloring(GT& G) {\n  auto vcolor\
    \ = check_bipartite<decltype(G)>(G);\n  auto deg = G.deg_array();\n  int D = MAX(deg);\n\
    \n  UnionFind uf(G.N);\n  FOR(c, 2) {\n    pqg<pair<int, int>> que;\n    FOR(v,\
    \ G.N) {\n      if (vcolor[v] == c) que.emplace(deg[v], v);\n    }\n    while\
    \ (len(que) > 1) {\n      auto [d1, v1] = pick(que);\n      auto [d2, v2] = pick(que);\n\
    \      if (d1 + d2 > D) break;\n      uf.merge(v1, v2);\n      int r = uf[v1];\n\
    \      que.emplace(d1 + d2, r);\n    }\n  }\n\n  vc<int> LV, RV;\n  FOR(v, G.N)\
    \ if (uf[v] == v) {\n    if (vcolor[v] == 0) LV.eb(v);\n    if (vcolor[v] == 1)\
    \ RV.eb(v);\n  }\n  int X = max(len(LV), len(RV));\n  vc<int> degL(X), degR(X);\n\
    \n  vc<pair<int, int>> edges;\n  for (auto&& e: G.edges) {\n    int a = e.frm,\
    \ b = e.to;\n    a = uf[a], b = uf[b];\n    a = LB(LV, a);\n    b = LB(RV, b);\n\
    \    degL[a]++, degR[b]++;\n    edges.eb(a, X + b);\n  }\n  int p = 0, q = 0;\n\
    \  while (p < X && q < X) {\n    if (degL[p] == D) {\n      ++p;\n      continue;\n\
    \    }\n    if (degR[q] == D) {\n      ++q;\n      continue;\n    }\n    edges.eb(p,\
    \ X + q);\n    degL[p]++, degR[q]++;\n  }\n  RegularBipartiteColoring RBC;\n \
    \ vvc<int> res = RBC.solve(X, D, edges);\n  vc<int> ecolor(len(edges));\n  FOR(i,\
    \ len(res)) {\n    for (auto&& j: res[i]) ecolor[j] = i;\n  }\n  ecolor.resize(G.M);\n\
    \  return {D, ecolor};\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/bipartite_edge_coloring.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/bipartite_edge_coloring.hpp
layout: document
redirect_from:
- /library/graph/bipartite_edge_coloring.hpp
- /library/graph/bipartite_edge_coloring.hpp.html
title: graph/bipartite_edge_coloring.hpp
---
