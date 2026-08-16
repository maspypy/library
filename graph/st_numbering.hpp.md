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
    - https://en.wikipedia.org/wiki/Bipolar_orientation
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/shortest_path/bfs01.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"graph/base.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\n\
    #include \"graph/block_cut.hpp\"\n#include \"graph/shortest_path/bfs01.hpp\"\n\
    #include \"graph/shortest_path/restore_path.hpp\"\n\n// https://en.wikipedia.org/wiki/Bipolar_orientation\n\
    // \u9806\u5217 p \u3092\u6C42\u3081\u308B. p[s]=0,p[t]=n-1.\n// p[u]<p[v] \u3068\
    \u306A\u308B\u5411\u304D\u306B\u8FBA\u3092\u5411\u304D\u4ED8\u3051\u308B\u3068\
    \u4EFB\u610F\u306E v \u306B\u5BFE\u3057\u3066 svt \u30D1\u30B9\u304C\u5B58\u5728\
    .\n// \u5B58\u5728\u6761\u4EF6\uFF1ABCT \u3067\u5168\u90E8\u306E\u6210\u5206\u3092\
    \u901A\u308B st \u30D1\u30B9\u304C\u3042\u308B \u4E0D\u53EF\u80FD\u306A\u3089\u3070\
    \ empty \u3092\u304B\u3048\u3059.\ntemplate <typename GT>\nvc<int> st_numbering(GT\
    \ &G, int s, int t) {\n  static_assert(!GT::is_directed);\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  if (N == 1) return {0};\n  if (s == t) return {};\n  vc<int>\
    \ par(N, -1), pre(N, -1), low(N, -1);\n  vc<int> V;\n\n  auto dfs = [&](auto &dfs,\
    \ int v) -> void {\n    pre[v] = len(V), V.eb(v);\n    low[v] = v;\n    for (auto\
    \ &e: G[v]) {\n      int w = e.to;\n      if (v == w) continue;\n      if (pre[w]\
    \ == -1) {\n        dfs(dfs, w);\n        par[w] = v;\n        if (pre[low[w]]\
    \ < pre[low[v]]) { low[v] = low[w]; }\n      }\n      elif (pre[w] < pre[low[v]])\
    \ { low[v] = w; }\n    }\n  };\n\n  pre[s] = 0, V.eb(s);\n  dfs(dfs, t);\n  if\
    \ (len(V) != N) return {};\n  vc<int> nxt(N, -1), prev(N);\n  nxt[s] = t, prev[t]\
    \ = s;\n\n  vc<int> sgn(N);\n  sgn[s] = -1;\n  FOR(i, 2, len(V)) {\n    int v\
    \ = V[i];\n    int p = par[v];\n    if (sgn[low[v]] == -1) {\n      int q = prev[p];\n\
    \      if (q == -1) return {};\n      nxt[q] = v, nxt[v] = p;\n      prev[v] =\
    \ q, prev[p] = v;\n      sgn[p] = 1;\n    } else {\n      int q = nxt[p];\n  \
    \    if (q == -1) return {};\n      nxt[p] = v, nxt[v] = q;\n      prev[v] = p,\
    \ prev[q] = v;\n      sgn[p] = -1;\n    }\n  }\n  vc<int> A = {s};\n  while (A.back()\
    \ != t) { A.eb(nxt[A.back()]); }\n  // \u4F5C\u308C\u3066\u3044\u308B\u304B\u5224\
    \u5B9A\n  if (len(A) < N) return {};\n  assert(A[0] == s && A.back() == t);\n\
    \  vc<int> rk(N, -1);\n  FOR(i, N) rk[A[i]] = i;\n  assert(MIN(rk) != -1);\n \
    \ FOR(i, N) {\n    bool l = 0, r = 0;\n    int v = A[i];\n    for (auto &e: G[v])\
    \ {\n      if (rk[e.to] < rk[v]) l = 1;\n      if (rk[v] < rk[e.to]) r = 1;\n\
    \    }\n    if (i > 0 && !l) return {};\n    if (i < N - 1 && !r) return {};\n\
    \  }\n  vc<int> res(N);\n  FOR(i, N) res[A[i]] = i;\n  return res;\n}\n\nbool\
    \ check_st_numbering(Graph<int, 0> G, int s, int t) {\n  int N = G.N;\n  assert(N\
    \ >= 2);\n  if (s == t) return 0;\n\n  UnionFind uf(N);\n  for (auto &e: G.edges)\
    \ uf.merge(e.frm, e.to);\n  if (uf.n_comp >= 2) return 0; // disconnected\n\n\
    \  // BCT \u306B\u304A\u3044\u3066 st \u30D1\u30B9\u304C\u3059\u3079\u3066\u306E\
    \ block \u3092\u901A\u308B\u3053\u3068\u304C\u5FC5\u8981\n  auto BCT = block_cut(G);\n\
    \  auto [dist, par] = bfs01<int>(BCT, s);\n  vc<int> path = restore_path(par,\
    \ t);\n\n  vc<int> vis(BCT.N);\n  for (auto &x: path) vis[x] = 1;\n\n  FOR(i,\
    \ N, BCT.N) {\n    if (!vis[i]) return 0;\n  }\n  return 1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/st_numbering.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/st_numbering.hpp
layout: document
redirect_from:
- /library/graph/st_numbering.hpp
- /library/graph/st_numbering.hpp.html
title: graph/st_numbering.hpp
---
