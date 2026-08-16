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
  code: "#include \"graph/shortest_path/bfs01.hpp\"\n#include \"graph/shortest_path/restore_path.hpp\"\
    \n\n// verify \u3057\u3066\u306A\u3044\n// {a, b, d}\uFF1Aa \u304B\u3089 b \u306B\
    \ d \u9032\u3080 / {a, a, 0}\n// \u76F4\u5F84\u306E\u9577\u3055\u304C\u5076\u6570\
    \u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\uFF08\
    \u5FC5\u8981\u306A\u3089 2 \u500D\u3057\u3066\u304A\u304F\u3053\u3068\uFF09\n\
    template <typename T, typename GT>\ntuple<int, int, T> tree_center(GT& G) {\n\
    \  assert(G.is_prepared());\n  auto [distA, parA] = bfs01<T>(G, 0);\n  int a =\
    \ max_element(all(distA)) - distA.begin();\n  auto [dist, par] = bfs01<T>(G, A);\n\
    \  int b = max_element(all(dist)) - dist.begin();\n  T d = dist[b];\n  assert(d\
    \ % 2 == 0);\n  vc<int> path = restore_path(par, b);\n  FOR(i, len(path)) {\n\
    \    int v = path[i];\n    if (dist[v] == d / 2) return {v, v, 0};\n  }\n  FOR(i,\
    \ len(path) - 1) {\n    int a = path[i], b = path[i + 1];\n    if (dist[a] < d\
    \ / 2 && d / 2 < dist[b]) { return {a, b, d / 2 - dist[a]}; }\n  }\n  assert(0);\n\
    \  return {-1, -1, 0};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tree_center.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_center.hpp
layout: document
redirect_from:
- /library/graph/tree_center.hpp
- /library/graph/tree_center.hpp.html
title: graph/tree_center.hpp
---
