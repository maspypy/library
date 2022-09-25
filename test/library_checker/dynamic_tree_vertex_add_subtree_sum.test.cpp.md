---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.7/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/link_cut_subtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/link_cut_subtree.hpp\"\
    \n#include \"alg/group_add.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A,\
    \ N);\n  using Node = LCT_Subtree_Node<Group_Add<ll>>;\n  LinkCutTree_SubTree<Node,\
    \ 200'000> LCT(A);\n\n  FOR(N - 1) {\n    LL(a, b);\n    LCT.link(a, b);\n  }\n\
    \  FOR(Q) {\n    LL(t);\n    if (t == 0) {\n      LL(a, b, c, d);\n      LCT.cut(a,\
    \ b);\n      LCT.link(c, d);\n    }\n    if (t == 1) {\n      LL(a, x);\n    \
    \  LCT.add(a, x);\n    }\n    if (t == 2) {\n      LL(v, p);\n      LCT.evert(p);\n\
    \      print(LCT.sum(v));\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  ll T = 1;\n\
    \  // LL(T);\n  FOR(_, T) solve();\n\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/dynamic_tree_vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/dynamic_tree_vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/dynamic_tree_vertex_add_subtree_sum.test.cpp
- /verify/test/library_checker/dynamic_tree_vertex_add_subtree_sum.test.cpp.html
title: test/library_checker/dynamic_tree_vertex_add_subtree_sum.test.cpp
---
