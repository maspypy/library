---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/ds/treeabelgroup.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\r\
    \n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n\r\n#include \"\
    graph/ds/treeabelgroup.hpp\"\r\n#include \"alg/monoid/add.hpp\"\r\n\r\nvoid solve()\
    \ {\r\n  LL(N, Q);\r\n  VEC(ll, A, N);\r\n  Graph G(N);\r\n  G.read_tree(0, 0);\r\
    \n\r\n  TREE tree(G);\r\n  TreeAbelGroup<decltype(tree), Monoid_Add<ll>, false,\
    \ true, false> TA(tree, A);\r\n\r\n  FOR(_, Q) {\r\n    LL(t);\r\n    if (t ==\
    \ 0) {\r\n      LL(v, x);\r\n      TA.add(v, x);\r\n    } else {\r\n      LL(u,\
    \ v);\r\n      print(TA.prod_path(u, v));\r\n    }\r\n  }\r\n}\r\n\r\nsigned main()\
    \ {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\
    \n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
- /verify/test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp.html
title: test/library_checker/datastructure/vertex_add_path_sum_abelgroup.test.cpp
---
