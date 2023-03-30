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
    - https://atcoder.jp/contests/tkppc2/tasks/tkppc2016_h
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/count_C3_C4.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/count_C3_C4.hpp\"\n\n// \u5404 v \u306B\u5BFE\u3057\u3066\
    \u3001v \u3092\u59CB\u70B9\u3068\u3059\u308B P3, P4 \u3092\u6570\u3048\u308B\n\
    // https://atcoder.jp/contests/tkppc2/tasks/tkppc2016_h\ntemplate <typename GT>\n\
    pair<vi, vi> count_P3_P4_pointwise(GT& G) {\n  int N = G.N;\n  auto deg = G.deg_array();\n\
    \  auto [C3, C4] = count_C3_C4_pointwise(G);\n\n  vi P2(N), P3(N), P4(N);\n  using\
    \ ARR = array<ll, 5>;\n  vc<ARR> path(N, {1, 0, 0, 0, 0});\n  FOR(v, N) path[v][1]\
    \ = deg[v];\n\n  FOR(v, N) {\n    for (auto&& e: G[v]) P2[v] += deg[e.to] - 1;\n\
    \  }\n\n  FOR(v, N) {\n    for (auto&& e: G[v]) { P3[v] += P2[e.to] - (deg[v]\
    \ - 1); }\n    P3[v] -= C3[v] * 2;\n  }\n\n  FOR(v, N) {\n    for (auto&& e: G[v])\
    \ { P4[v] += P3[e.to]; }\n    P4[v] -= C4[v] * 2;\n    P4[v] -= C3[v] * 2 * (deg[v]\
    \ - 3);\n    P4[v] -= P2[v] * (deg[v] - 1);\n  }\n  return {P3, P4};\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_P3_P4.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_P3_P4.hpp
layout: document
redirect_from:
- /library/graph/count/count_P3_P4.hpp
- /library/graph/count/count_P3_P4.hpp.html
title: graph/count/count_P3_P4.hpp
---
