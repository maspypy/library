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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/range_add_range.sum.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\r\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"ds/range_add_range.sum.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  Range_Add_Range_Sum<Monoid_Add<ll>>\
    \ bit(N);\r\n  FOR(_, Q) {\r\n    LL(t, L, R);\r\n    --L;\r\n    if (t == 0)\
    \ {\r\n      LL(x);\r\n      bit.add(L, R, x);\r\n    } else {\r\n      print(bit.prod(L,\
    \ R));\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n\
    \  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  ll T =\
    \ 1;\r\n  // LL(T);\r\n  FOR(_, T) solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_G.test.cpp
- /verify/test/aoj/DSL_2_G.test.cpp.html
title: test/aoj/DSL_2_G.test.cpp
---
