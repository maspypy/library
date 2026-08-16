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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/shortest_path/bfs01.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp\"\
    \n#include \"poly/convolution_all.hpp\"\n\n// \u30EB\u30FC\u30D7\u306A\u3057\uFF1A\
    1600ms(N=10^5)\n// \u30EB\u30FC\u30D7\u3042\u308A\uFF1A3300ms(N=10^5)\ntemplate\
    \ <bool ALLOW_LOOP, typename mint, typename F>\npair<vc<mint>, vc<mint>> tree_walk_generating_function(Graph<int,\
    \ 0>& G, int s, int t, F weight) {\n  int N = G.N;\n  // \u5206\u6BCD\n  auto\
    \ f = characteristic_poly_of_tree_adjacency_matrix<ALLOW_LOOP, mint>(G, weight);\n\
    \  // \u5206\u5B50\n  // (s,t) \u30D1\u30B9\u306B\u6CBF\u3063\u3066\u6210\u5206\
    \u3092\u304B\u3051\u305F\u3082\u306E\u306E\u7B26\u53F7\u8ABF\u6574 + \u4ED6\u306E\
    \u6210\u5206\n  using poly = vc<mint>;\n  vc<poly> polys;\n  pair<int, mint> path_poly\
    \ = {0, mint(1)};\n  vc<bool> on_path(N);\n  auto [dist, par] = bfs01<int>(G,\
    \ s);\n  on_path[t] = 1;\n  while (t != s) {\n    mint w = weight(par[t], t);\n\
    \    t = par[t], on_path[t] = 1;\n    path_poly.fi += 1, path_poly.se *= w; //\
    \ +wx\n  }\n  UnionFind uf(N);\n  for (auto& e: G.edges) {\n    if (on_path[e.frm]\
    \ || on_path[e.to]) continue;\n    uf.merge(e.frm, e.to);\n  }\n  vvc<int> comp(N);\n\
    \  FOR(v, N) comp[uf[v]].eb(v);\n  FOR(r, N) {\n    if (on_path[r] || uf[r] !=\
    \ r) continue;\n    vc<int>& V = comp[r];\n    Graph<int, 0> H = G.rearrange(V);\n\
    \    poly f = characteristic_poly_of_tree_adjacency_matrix<ALLOW_LOOP, mint>(H,\
    \ [&](int i, int j) -> mint { return weight(V[i], V[j]); });\n    polys.eb(f);\n\
    \  }\n  poly B = convolution_all<mint>(polys);\n  int m = path_poly.fi;\n  poly\
    \ g(len(B) + m);\n  FOR(i, len(B)) g[m + i] = path_poly.se * B[i];\n  return {g,\
    \ f};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_walk_generating_function.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_walk_generating_function.hpp
layout: document
redirect_from:
- /library/graph/tree_walk_generating_function.hpp
- /library/graph/tree_walk_generating_function.hpp.html
title: graph/tree_walk_generating_function.hpp
---
