---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/offline_query/coeffient_query_2d.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/fenwicktree/fenwicktree.hpp\"\
    \n#include \"ds/offline_query/coeffient_query_2d.hpp\"\n\nvoid solve() {\n  LL(N,\
    \ Q);\n  Coefficient_Query_2D<1, 1, ll, true> X;\n  FOR(i, N) {\n    LL(x, y,\
    \ w);\n    X.add_query(x, y, w);\n  }\n  FOR(Q) {\n    LL(x1, y1, x2, y2);\n \
    \   --x1, --y1, --x2, --y2;\n    X.sum_query(x1, y1);\n    X.sum_query(x1, y2);\n\
    \    X.sum_query(x2, y1);\n    X.sum_query(x2, y2);\n  }\n  auto res = X.calc();\n\
    \  vi ANS(Q);\n  FOR(q, Q)\n  ANS[q] = res[4 * q] - res[4 * q + 1] - res[4 * q\
    \ + 2] + res[4 * q + 3];\n  print(ANS);\n}\n\nsigned main() {\n  solve();\n  return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/2_library_checker/data_structure/rectangle_sum_cf2d.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/rectangle_sum_cf2d.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/rectangle_sum_cf2d.test.cpp
- /verify/test/2_library_checker/data_structure/rectangle_sum_cf2d.test.cpp.html
title: test/2_library_checker/data_structure/rectangle_sum_cf2d.test.cpp
---
