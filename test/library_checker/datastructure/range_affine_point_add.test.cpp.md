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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/dualsegtree.hpp\"\
    \n#include \"alg/group/affine.hpp\"\n#include \"mod/modint.hpp\"\n\nusing mint\
    \ = modint998;\n\nvoid solve() {\n  LL(N, Q);\n  VEC(mint, A, N);\n  DualSegTree<Group_Affine<mint>>\
    \ seg(N);\n  FOR(Q) {\n    LL(t);\n    if (t == 0) {\n      LL(l, r, b, c);\n\
    \      seg.apply(l, r, {mint(b), mint(c)});\n    }\n    if (t == 1) {\n      LL(idx);\n\
    \      mint x = A[idx];\n      auto [a, b] = seg.get(idx);\n      print(a * x\
    \ + b);\n    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/range_affine_point_add.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/range_affine_point_add.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/range_affine_point_add.test.cpp
- /verify/test/library_checker/datastructure/range_affine_point_add.test.cpp.html
title: test/library_checker/datastructure/range_affine_point_add.test.cpp
---
