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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/add.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/group/add.hpp\"\
    \n#include \"graph/ds/link_cut_path.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll,\
    \ A, N);\n\n  LinkCutTree_Path<Group_Add<ll>, 200000> X(A);\n\n  FOR(N - 1) {\n\
    \    LL(u, v);\n    X.link(u, v);\n  }\n\n  FOR(Q) {\n    LL(t);\n    if (t ==\
    \ 0) {\n      LL(a, b, c, d);\n      X.cut(a, b);\n      X.link(c, d);\n    }\n\
    \    if (t == 1) {\n      LL(p, x);\n      X.multiply(p, x);\n    }\n    if (t\
    \ == 2) {\n      LL(a, b);\n      print(X.prod_path(a, b));\n    }\n  }\n}\n\n\
    signed main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout <<\
    \ setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\n  return\
    \ 0;\n}"
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
