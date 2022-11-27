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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/affine.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/group/affine.hpp\"\
    \n#include \"mod/modint.hpp\"\n#include \"graph/ds/treemonoid.hpp\"\n\nusing mint\
    \ = modint998;\n\nvoid solve() {\n  LL(N, Q);\n  using Mono = Group_Affine<mint>;\n\
    \  using E = pair<mint, mint>;\n  vc<E> A(N);\n  FOR(i, N) {\n    LL(a, b);\n\
    \    A[i] = E({a, b});\n  }\n\n  Graph<int> G(N);\n  G.read_tree(0, 0);\n\n  TREE\
    \ tree(G);\n  TreeMonoid<decltype(tree), Mono, false> TM(tree, A);\n\n  FOR(_,\
    \ Q) {\n    LL(t);\n    if (t == 0) {\n      LL(v, c, d);\n      TM.set(v, E({mint(c),\
    \ mint(d)}));\n    } else {\n      LL(u, v, x);\n      auto e = TM.prod_path(u,\
    \ v);\n      print(Mono::eval(e, mint(x)));\n    }\n  }\n}\n\nsigned main() {\n\
    \  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
- /verify/test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp.html
title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
---
