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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/zalgorithm.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"string/is_substring.hpp\"\n\nstring\
    \ gen(int n) {\n  string s;\n  FOR(n) { s += char('a' + RNG(3)); }\n  return s;\n\
    }\n\nbool naive(string S, string T) {\n  FOR(i, len(T)) if (T.substr(i, len(S))\
    \ == S) return true;\n  return false;\n}\n\nvoid test() {\n  FOR(1000) {\n   \
    \ FOR(n, 1, 10) FOR(m, 1, 10) {\n      string s = gen(n), t = gen(m);\n      bool\
    \ a = naive(s, t);\n      bool b = is_substring(s, t);\n      assert(a == b);\n\
    \    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a +\
    \ b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/is_substring.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/is_substring.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/is_substring.test.cpp
- /verify/test/1_mytest/is_substring.test.cpp.html
title: test/1_mytest/is_substring.test.cpp
---
