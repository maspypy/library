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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial_limit\"\
    \r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"seq/limit_poly_exp_sum.hpp\"\
    \r\n#include \"mod/powertable.hpp\"\r\n\r\nusing mint = modint998;\r\nvoid solve()\
    \ {\r\n  mint r;\r\n  read(r);\r\n  LL(d);\r\n  int L = d + 5;\r\n  vc<mint> a\
    \ = powertable_2<mint>(d, L - 1);\r\n  mint p = 1;\r\n  FOR(i, L) {\r\n    a[i]\
    \ *= p;\r\n    p *= r;\r\n  }\r\n  a = cumsum<mint>(a, 0);\r\n  print(limit_poly_exp_sum(a,\
    \ r));\r\n}\r\n\r\nsigned main() {\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/2_library_checker/other/sum_of_exp_times_poly_limit.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/other/sum_of_exp_times_poly_limit.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/other/sum_of_exp_times_poly_limit.test.cpp
- /verify/test/2_library_checker/other/sum_of_exp_times_poly_limit.test.cpp.html
title: test/2_library_checker/other/sum_of_exp_times_poly_limit.test.cpp
---
