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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/beats_summaxmin_chminchmax.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include\
    \ \"ds/beats_summaxmin_chminchmax.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\
    \n  VEC(ll, A, N);\r\n  Beats_SumMaxMin_ChminChmax seg(A);\r\n  FOR(_, Q) {\r\n\
    \    LL(t, L, R);\r\n    if (t == 0) {\r\n      LL(x);\r\n      seg.chmin(L, R,\
    \ x);\r\n    }\r\n    elif (t == 1) {\r\n      LL(x);\r\n      seg.chmax(L, R,\
    \ x);\r\n    }\r\n    elif (t == 2) {\r\n      LL(x);\r\n      seg.add(L, R, x);\r\
    \n    }\r\n    elif (t == 3) {\r\n      auto x = seg.prod(L, R);\r\n      print(x.sum);\r\
    \n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/library_checker/datastructure/range_chmin_chmax_add_range_sum.test.cpp
---
