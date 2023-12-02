---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/ds/link_cut_commutative_monoid.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/ds/link_cut_tree.hpp\"\
    \n#include \"graph/ds/link_cut_commutative_monoid.hpp\"\n#include \"alg/monoid/add.hpp\"\
    \n\nusing Node = LCT_Node_Commutative_Monoid<Monoid_Add<ll>>;\n\nvoid solve()\
    \ {\n  LL(N, Q);\n  VEC(u64, A, N);\n  Link_Cut_Tree<Node> LCT(N);\n  FOR(i, N)\
    \ LCT.set_vdata(i, A[i]);\n  FOR(N - 1) {\n    INT(a, b);\n    LCT.link(a, b);\n\
    \  }\n  FOR(Q) {\n    LL(t);\n    if (t == 0) {\n      LL(a, b, c, d);\n     \
    \ LCT.cut(a, b), LCT.link(c, d);\n    }\n    if (t == 1) {\n      LL(i);\n   \
    \   u32 x;\n      read(x);\n      A[i] += x;\n      LCT.set_vdata(i, A[i]);\n\
    \    }\n    if (t == 2) {\n      LL(a, b);\n      u64 ans = LCT.prod_path(a, b);\n\
    \      print(ans);\n    }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
- /verify/test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp.html
title: test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
---
