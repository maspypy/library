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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/bbst/rbst_lazy.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/acted_monoid/cntsum_affine.hpp\"\
    \n#include \"mod/modint.hpp\"\n#include \"ds/bbst/rbst_lazy.hpp\"\n\nusing mint\
    \ = modint998;\n\nvoid solve() {\n  LL(N, Q);\n  VEC(mint, A, N);\n  RBST_Lazy<ActedMonoid_CntSum_Affine<mint>>\
    \ X;\n  vc<pair<mint, mint>> seg_raw(N);\n  FOR(i, N) seg_raw[i] = {mint(1), A[i]};\n\
    \  auto root = X.new_node(seg_raw);\n\n  FOR(Q) {\n    LL(t);\n    if (t == 0)\
    \ {\n      LL(i, x);\n      auto [a, b] = X.split(root, i);\n      root = X.merge3(a,\
    \ X.new_node({mint(1), mint(x)}), b);\n    }\n    if (t == 1) {\n      LL(i);\n\
    \      auto [a, b, c] = X.split3(root, i, i + 1);\n      root = X.merge(a, c);\n\
    \    }\n    if (t == 2) {\n      LL(l, r);\n      root = X.reverse(root, l, r);\n\
    \    }\n    if (t == 3) {\n      LL(l, r, b, c);\n      root = X.apply(root, l,\
    \ r, {mint(b), mint(c)});\n    }\n    if (t == 4) {\n      LL(l, r);\n      print(X.prod(root,\
    \ l, r).se);\n    }\n  }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
- /verify/test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp.html
title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
---
