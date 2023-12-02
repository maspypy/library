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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/ds/link_cut_monoid.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/ds/link_cut_tree.hpp\"\
    \n#include \"graph/ds/link_cut_monoid.hpp\"\n#include \"alg/monoid/affine.hpp\"\
    \n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\nusing Mono = Monoid_Affine<mint>;\n\
    using Node = LCT_Node_Monoid<Mono>;\n\nvoid solve() {\n  LL(N, Q);\n  Link_Cut_Tree<Node>\
    \ LCT(N);\n  FOR(i, N) {\n    mint a, b;\n    read(a, b);\n    LCT.set(i, {a,\
    \ b});\n  }\n  FOR(N - 1) {\n    INT(a, b);\n    LCT.link(a, b);\n  }\n\n  FOR(Q)\
    \ {\n    LL(t);\n    if (t == 0) {\n      LL(a, b, c, d);\n      LCT.cut(a, b),\
    \ LCT.link(c, d);\n    }\n    if (t == 1) {\n      LL(i);\n      mint a, b;\n\
    \      read(a, b);\n      LCT.set(i, {a, b});\n    }\n    if (t == 2) {\n    \
    \  LL(a, b);\n      auto f = LCT.prod_path(a, b);\n      u32 x;\n      read(x);\n\
    \      mint ans = Mono::eval(f, mint::raw(x));\n      print(ans);\n    }\n  }\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/dynamic_tree_vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/dynamic_tree_vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/dynamic_tree_vertex_set_path_composite.test.cpp
- /verify/test/library_checker/datastructure/dynamic_tree_vertex_set_path_composite.test.cpp.html
title: test/library_checker/datastructure/dynamic_tree_vertex_set_path_composite.test.cpp
---
