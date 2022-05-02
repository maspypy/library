---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/scc.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\r\n#include \"\
    my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"graph/twosat.hpp\"\
    \r\n\r\nvoid solve() {\r\n  STR(p, cnf);\r\n  LL(N, M);\r\n  TwoSat ts(N);\r\n\
    \  FOR(i, M) {\r\n    LL(a, b, c);\r\n    a = (a > 0 ? a - 1 : a);\r\n    b =\
    \ (b > 0 ? b - 1 : b);\r\n    ts.add(a, b);\r\n  }\r\n  bool ok = ts.calc();\r\
    \n  auto A = ts.values;\r\n  if (ok) {\r\n    print(\"s SATISFIABLE\");\r\n  \
    \  vc<int> ANS(N);\r\n    FOR(i, N) ANS[i] = (A[i] ? i + 1 : -(i + 1));\r\n  \
    \  print(\"v\", ANS, \"0\");\r\n  } else {\r\n    print(\"s UNSATISFIABLE\");\r\
    \n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  // LL(T);\r\n  ll T = 1;\r\n  FOR(_, T)\
    \ solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/math/twosat.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/math/twosat.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/twosat.test.cpp
- /verify/test/library_checker/math/twosat.test.cpp.html
title: test/library_checker/math/twosat.test.cpp
---
