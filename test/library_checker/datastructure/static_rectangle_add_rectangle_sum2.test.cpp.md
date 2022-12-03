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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/fenwick/fenwick.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/static_rectangle_add_rectangle_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/offline_query/coeffient_query_2d.hpp\"\
    \n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\nvoid solve() {\n \
    \ LL(N, Q);\n  Coefficient_Query_2D<2, 2, mint> X;\n  FOR(N) {\n    LL(x1, y1,\
    \ x2, y2, w);\n    X.add(x1, y1, +w);\n    X.add(x1, y2, -w);\n    X.add(x2, y1,\
    \ -w);\n    X.add(x2, y2, +w);\n  }\n  FOR(Q) {\n    LL(x1, y1, x2, y2);\n   \
    \ --x1, --y1, --x2, --y2;\n    X.query(x1, y1);\n    X.query(x1, y2);\n    X.query(x2,\
    \ y1);\n    X.query(x2, y2);\n  }\n  auto res = X.calc();\n  FOR(q, Q) {\n   \
    \ mint ANS = 0;\n    ANS += res[4 * q + 0];\n    ANS -= res[4 * q + 1];\n    ANS\
    \ -= res[4 * q + 2];\n    ANS += res[4 * q + 3];\n    print(ANS);\n  }\n}\n\n\
    signed main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout <<\
    \ setprecision(15);\n\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/static_rectangle_add_rectangle_sum2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/static_rectangle_add_rectangle_sum2.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/static_rectangle_add_rectangle_sum2.test.cpp
- /verify/test/library_checker/datastructure/static_rectangle_add_rectangle_sum2.test.cpp.html
title: test/library_checker/datastructure/static_rectangle_add_rectangle_sum2.test.cpp
---
