---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/unionfind/weighted_unionfind.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_frequency\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/unionfind/weighted_unionfind.hpp\"\
    \n#include \"alg/monoid/add.hpp\"\n#include \"mod/modint.hpp\"\n\nusing mint =\
    \ modint998;\n\nvoid solve() {\n  LL(N, Q);\n  Weighted_UnionFind<Monoid_Add<mint>>\
    \ uf(N);\n\n  FOR(Q) {\n    INT(t);\n    if (t == 0) { INT(u, v, x); }\n  }\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/2_library_checker/data_structure/point_set_range_freq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/point_set_range_freq.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/point_set_range_freq.test.cpp
- /verify/test/2_library_checker/data_structure/point_set_range_freq.test.cpp.html
title: test/2_library_checker/data_structure/point_set_range_freq.test.cpp
---
