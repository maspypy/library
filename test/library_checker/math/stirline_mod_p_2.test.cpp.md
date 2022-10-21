---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: seq/stirling_number_query.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_small_p_large_n\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"seq/stirling_number_query.hpp\"\
    \n\nvoid solve() {\n  LL(T, p);\n  Stirling_Number_Query X(p, 0, 1);\n  FOR(T)\
    \ {\n    LL(n, k);\n    print(X.S2(n, k));\n  }\n}\n\nsigned main() {\n  cout\
    \ << fixed << setprecision(15);\n\n  // LL(T);\n  ll T = 1;\n  FOR(T) solve();\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/math/stirline_mod_p_2.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/math/stirline_mod_p_2.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/stirline_mod_p_2.test.cpp
- /verify/test/library_checker/math/stirline_mod_p_2.test.cpp.html
title: test/library_checker/math/stirline_mod_p_2.test.cpp
---
