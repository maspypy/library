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
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/mul.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/sum_of_exponential_times_polynomial\"\
    \r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"seq/interpolate_poly_exp_sum.hpp\"\
    \r\n#include \"mod/powertable.hpp\"\r\n\r\nusing mint = modint998;\r\nvoid solve()\
    \ {\r\n  mint r;\r\n  scanner.read(r);\r\n  LL(d, n);\r\n  int L = d + 5;\r\n\
    \  vc<mint> a = powertable_2<mint>(d, L - 1);\r\n  mint p = 1;\r\n  FOR(i, L)\
    \ {\r\n    a[i] *= p;\r\n    p *= r;\r\n  }\r\n  a = cumsum<mint>(a, 0);\r\n \
    \ if (n == 0) return print(0);\r\n  print(interpolate_poly_exp_sum(a, r, n - 1));\r\
    \n}\r\n\r\nsigned main() {\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/math/sum_of_exp_times_poly.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/sum_of_exp_times_poly.test.cpp
- /verify/test/library_checker/math/sum_of_exp_times_poly.test.cpp.html
title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
---
