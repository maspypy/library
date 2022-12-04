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
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 269, in update\n    raise BundleErrorAt(path, -1, \"cycle found in inclusion\
    \ relations\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/segtree/dynamic_segtree.hpp:\
    \ line -1: cycle found in inclusion relations\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/segtree/dynamic_segtree.hpp\"\
    \n#include \"alg/monoid/affine.hpp\"\n#include \"mod/modint.hpp\"\n\nusing mint\
    \ = modint998;\n\nvoid solve() {\n  using Mono = Monoid_Affine<mint>;\n  using\
    \ X = Mono::value_type;\n  LL(N, Q);\n  VEC(X, dat, N);\n\n  Dynamic_SegTree<Mono,\
    \ false, 1000000> seg(N);\n  auto root = seg.new_node(dat);\n\n  FOR(Q) {\n  \
    \  LL(t, a, b, c);\n    if (t == 0) { seg.set(root, a, {b, c}); }\n    if (t ==\
    \ 1) { print(Mono::eval(seg.prod(root, a, b), c)); }\n  }\n}\n\nsigned main()\
    \ {\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/point_set_range_composite_dynamic.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/point_set_range_composite_dynamic.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/point_set_range_composite_dynamic.test.cpp
- /verify/test/library_checker/datastructure/point_set_range_composite_dynamic.test.cpp.html
title: test/library_checker/datastructure/point_set_range_composite_dynamic.test.cpp
---
