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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bit.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"string/lex_min_suffix_for_all_prefix.hpp\"\
    \n#include \"string/lex_max_suffix_for_all_prefix.hpp\"\n\nvoid test_str(string\
    \ S) {\n  vc<int> A = lex_min_suffix_for_all_prefix(S);\n  vc<int> B = lex_max_suffix_for_all_prefix(S);\n\
    \  FOR(n, 1, len(S) + 1) {\n    string t = S.substr(0, n);\n    vc<string> suffix;\n\
    \    FOR(i, len(t)) suffix.eb(t.substr(i));\n    int a = min_element(all(suffix))\
    \ - suffix.begin();\n    int b = max_element(all(suffix)) - suffix.begin();\n\
    \    assert(A[n] == len(t) - a);\n    assert(B[n] == len(t) - b);\n  }\n}\n\n\
    void test() {\n  FOR(N, 1, 20) {\n    FOR(K, 1, 10) {\n      FOR(1000) {\n   \
    \     string S;\n        FOR(N) S += 'a' + RNG(0, K);\n        test_str(S);\n\
    \      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/lex_minmax_suffix.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/lex_minmax_suffix.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/lex_minmax_suffix.test.cpp
- /verify/test/1_mytest/lex_minmax_suffix.test.cpp.html
title: test/1_mytest/lex_minmax_suffix.test.cpp
---
