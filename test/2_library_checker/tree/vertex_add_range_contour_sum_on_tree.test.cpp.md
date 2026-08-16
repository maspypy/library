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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/shortest_path/bfs01.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/fenwicktree/fenwicktree.hpp\"\
    \n#include \"graph/ds/contour_query_range.hpp\"\n\n#include \"alg/monoid/add.hpp\"\
    \n\nvoid solve() {\n  INT(N, Q);\n  VEC(ll, A, N);\n  Graph<int, 0> G(N);\n  G.read_tree(0,\
    \ 0);\n  Contour_Query_Range<decltype(G), false> CQ(G);\n  vi dat_raw(len(CQ));\n\
    \  FOR(v, N) {\n    for (auto& p: CQ.get_indices(v)) { dat_raw[p] += A[v]; }\n\
    \  }\n  FenwickTree<Monoid_Add<ll>> bit(dat_raw);\n\n  FOR(Q) {\n    INT(t);\n\
    \    if (t == 0) {\n      INT(v, x);\n      A[v] += x;\n      for (auto& p: CQ.get_indices(v))\
    \ bit.add(p, x);\n    }\n    if (t == 1) {\n      INT(v, l, r);\n      ll ans\
    \ = 0;\n      if (l <= 0 && 0 < r) ans += A[v];\n      for (auto& [a, b]: CQ.get_contour_range(v,\
    \ l, r)) {\n        ans += bit.sum(a, b);\n      }\n      print(ans);\n    }\n\
    \  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/2_library_checker/tree/vertex_add_range_contour_sum_on_tree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/tree/vertex_add_range_contour_sum_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/tree/vertex_add_range_contour_sum_on_tree.test.cpp
- /verify/test/2_library_checker/tree/vertex_add_range_contour_sum_on_tree.test.cpp.html
title: test/2_library_checker/tree/vertex_add_range_contour_sum_on_tree.test.cpp
---
