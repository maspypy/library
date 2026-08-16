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
  code: "#include \"graph/centroid_decomposition.hpp\"\r\n#include \"poly/convolution.hpp\"\
    \r\n\r\n// sum of result array = binom(N,2)\r\ntemplate <typename GT>\r\nvi tree_all_distances(GT&\
    \ G) {\r\n  assert(G.is_prepared());\r\n  int N = G.N;\r\n  vi ANS(N);\r\n  auto\
    \ f = [&](vc<int>& par, vc<int>& V, int L1, int R1, int L2, int R2) -> void {\r\
    \n    int N = len(par);\r\n    vc<int> dist(N);\r\n    FOR(i, 1, N) { dist[i]\
    \ = 1 + dist[par[i]]; }\r\n    int mx = MAX(dist);\r\n    vi f(1 + mx), g(1 +\
    \ mx);\r\n    FOR(i, L1, R1) f[dist[i]]++;\r\n    FOR(i, L2, R2) g[dist[i]]++;\r\
    \n    while (len(f) && f.back() == 0) POP(f);\r\n    while (len(g) && g.back()\
    \ == 0) POP(g);\r\n    f = convolution(f, g);\r\n    FOR(i, len(f)) ANS[i] +=\
    \ f[i];\r\n  };\r\n  centroid_decomposition<1>(G, f);\r\n  ANS[1] = N - 1;\r\n\
    \  return ANS;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_all_distances.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_all_distances.hpp
layout: document
redirect_from:
- /library/graph/tree_all_distances.hpp
- /library/graph/tree_all_distances.hpp.html
title: graph/tree_all_distances.hpp
---
