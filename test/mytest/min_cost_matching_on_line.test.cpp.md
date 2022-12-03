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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/func/slope.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"flow/min_cost_matching_on_line.hpp\"\n\
    \nvoid test() {\n  // https://atcoder.jp/contests/kupc2016/tasks/kupc2016_h\n\
    \  vi A = {3, 1}, B = {1, 5};\n  assert(min_cost_matching_on_line_1(A, B) == 2);\n\
    \  A = {3, 3, 1, 1, 1}, B = {1, 2, 3, 4, 5};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 6);\n  A = {10, 2, 5, 6, 2, 6, 3,  2, 2,  5, 3, 11, 13, 2,\n       2,\
    \  7, 7, 3, 9, 5, 13, 4, 17, 2, 2, 2,  4},\n  B = {46, 3, 4, 2, 10, 2, 5, 2, 6,\
    \ 7,  20, 13, 9, 49,\n       3,  8, 4, 3, 19, 9, 3, 5, 4, 13, 9,  5,  7};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 48);\n  A = {1236501, 770807,  4003004, 131688,  1965412, 266841,\n  \
    \     3980782, 565060,  816313,  192940,  541896,  250801,\n       217586,  3806049,\
    \ 1220252, 1161079, 31168,   2008961},\n  B = {3878348, 423911,  8031742, 1035156,\
    \ 24256,    10344593,\n       19379,   3867285, 4481365, 1475384, 1959412,  1383457,\n\
    \       164869,  4633165, 6674637, 9732852, 10459147, 2810788};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 6302172);\n  A = {1234567891, 1}, B = {1, 99999999999};\n  assert(min_cost_matching_on_line_1(A,\
    \ B) == 1234567890);\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\n\
    signed main() {\n  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/min_cost_matching_on_line.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/min_cost_matching_on_line.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/min_cost_matching_on_line.test.cpp
- /verify/test/mytest/min_cost_matching_on_line.test.cpp.html
title: test/mytest/min_cost_matching_on_line.test.cpp
---
