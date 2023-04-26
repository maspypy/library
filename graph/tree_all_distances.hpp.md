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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/centroid.hpp\"\r\n#include \"poly/convolution.hpp\"\r\n\r\
    \n// frequency table of distance of all directed pairs.\r\n// sum of result array\
    \ = N^2\r\ntemplate <typename Graph>\r\nvi tree_all_distances(Graph& G) {\r\n\
    \  assert(G.is_prepared());\r\n  assert(!G.is_directed());\r\n  Centroid_Decomposition\
    \ CD(G);\r\n\r\n  ll N = G.N;\r\n  vi ANS(N);\r\n  FOR(root, N) {\r\n    auto\
    \ data = CD.collect_dist(root);\r\n    FOR(i, len(data)) {\r\n      int n = 0;\r\
    \n      FOR(j, len(data[i])) chmax(n, data[i][j].se + 1);\r\n      vi A(n);\r\n\
    \      FOR(j, len(data[i])) A[data[i][j].se]++;\r\n      auto B = convolution(A,\
    \ A);\r\n      FOR(j, min(N, len(B))) ANS[j] += (i == 0 ? B[j] : -B[j]);\r\n \
    \   }\r\n  }\r\n  return ANS;\r\n}"
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
