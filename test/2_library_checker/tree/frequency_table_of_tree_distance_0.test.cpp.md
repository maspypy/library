---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/centroid_decomposition.hpp\"\
    \n#include \"poly/convolution.hpp\"\n\nvoid solve() {\n  LL(N);\n  Graph<int>\
    \ G(N);\n  G.read_tree(0, 0);\n  vi ANS(N);\n  auto f = [&](vc<int>& par, vc<int>&\
    \ V, vc<int>& indptr) -> void {\n    int N = len(par);\n    vc<int> dist(N);\n\
    \    FOR(i, 1, N) { dist[i] = dist[par[i]] + 1; }\n    auto calc = [&](int L,\
    \ int R, int sgn) -> void {\n      int mx = *max_element(dist.begin() + L, dist.begin()\
    \ + R);\n      vi f(mx + 1);\n      FOR(i, L, R) f[dist[i]]++;\n      f = convolution(f,\
    \ f);\n      FOR(i, len(f)) ANS[i] += sgn * f[i];\n    };\n    calc(0, N, +1);\n\
    \    FOR(k, 1, len(indptr) - 1) { calc(indptr[k], indptr[k + 1], -1); }\n  };\n\
    \  centroid_decomposition<0>(G, f);\n  for (auto& x: ANS) x /= 2;\n  ANS.erase(ANS.begin());\n\
    \  print(ANS);\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/2_library_checker/tree/frequency_table_of_tree_distance_0.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/tree/frequency_table_of_tree_distance_0.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/tree/frequency_table_of_tree_distance_0.test.cpp
- /verify/test/2_library_checker/tree/frequency_table_of_tree_distance_0.test.cpp.html
title: test/2_library_checker/tree/frequency_table_of_tree_distance_0.test.cpp
---
