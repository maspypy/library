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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/acted_monoid/cntsum_affine.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/acted_monoid/cntsum_affine.hpp\"\
    \n#include \"mod/modint.hpp\"\n#include \"ds/splay/splaytree_acted_monoid.hpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  using AM = ActedMonoid_CntSum_Affine<mint>;\n\
    \  SplayTree_ActedMonoid<AM, 1'000'000> X;\n  using P = typename AM::X;\n\n  INT(N,\
    \ Q);\n  vc<P> dat(N);\n  FOR(i, N) {\n    mint a;\n    read(a);\n    dat[i] =\
    \ {mint(1), a};\n  }\n\n  auto root = X.new_node(dat);\n\n  FOR(Q) {\n    INT(t);\n\
    \    if (t == 0) {\n      INT(i, x);\n      auto [a, b] = X.split(root, i);\n\
    \      root = X.merge3(a, X.new_node({mint(1), mint(x)}), b);\n    }\n    if (t\
    \ == 1) {\n      INT(i);\n      auto [a, b, c] = X.split3(root, i, i + 1);\n \
    \     root = X.merge(a, c);\n    }\n    if (t == 2) {\n      INT(L, R);\n    \
    \  X.reverse(root, L, R);\n    }\n    if (t == 3) {\n      INT(L, R, b, c);\n\
    \      X.apply(root, L, R, {mint(b), mint(c)});\n    }\n    if (t == 4) {\n  \
    \    INT(L, R);\n      print(X.prod(root, L, R).se);\n    }\n  }\n}\n\nsigned\
    \ main() {\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
- /verify/test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp.html
title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
---
