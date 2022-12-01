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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_3_B\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/segtree.hpp\"\
    \n#include \"alg/monoid/minmax.hpp\"\n\nvoid solve() {\n  LL(N);\n  VEC(int, A,\
    \ N);\n  using Mono = Monoid_MinMax<int>;\n  SegTree<Mono> seg(N, [&](int i) {\
    \ return Mono::from_element(A[i]); });\n  LL(Q);\n  FOR(Q) {\n    LL(t, b, e);\n\
    \    if (t == 0) print(seg.prod(b, e).fi);\n    if (t == 1) print(seg.prod(b,\
    \ e).se);\n  }\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\n\
    \  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/ITP2_3_B.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ITP2_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP2_3_B.test.cpp
- /verify/test/aoj/ITP2_3_B.test.cpp.html
title: test/aoj/ITP2_3_B.test.cpp
---
