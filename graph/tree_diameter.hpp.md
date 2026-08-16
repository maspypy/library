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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/shortest_path/bfs01.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/shortest_path/bfs01.hpp\"\r\n#include \"graph/shortest_path/restore_path.hpp\"\
    \r\n\r\ntemplate <typename T, typename GT>\r\npair<T, vc<int>> tree_diameter(GT&\
    \ G) {\r\n  assert(G.is_prepared());\r\n  int A, B;\r\n  auto [distA, parA] =\
    \ bfs01<T>(G, 0);\r\n  A = max_element(all(distA)) - distA.begin();\r\n  auto\
    \ [dist, par] = bfs01<T>(G, A);\r\n  B = max_element(all(dist)) - dist.begin();\r\
    \n  vc<int> P = restore_path(par, B);\r\n  return {dist[B], P};\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_diameter.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_diameter.hpp
layout: document
redirect_from:
- /library/graph/tree_diameter.hpp
- /library/graph/tree_diameter.hpp.html
title: graph/tree_diameter.hpp
---
