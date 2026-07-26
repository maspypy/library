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
    \n#include \"random/base.hpp\"\n#include \"string/longest_common_substring.hpp\"\
    \n\nvoid test_pair(string A, string B) {\n  auto [a1, a2, b1, b2] = longest_common_substring<string>(A,\
    \ B);\n  {\n    assert(0 <= a1 && a1 <= a2 && a2 <= len(A));\n    assert(0 <=\
    \ b1 && b1 <= b2 && b2 <= len(B));\n    string x = A.substr(a1, a2 - a1);\n  \
    \  string y = B.substr(b1, b2 - b1);\n    assert(x == y);\n  }\n  int n = a2 -\
    \ a1 + 1;\n  set<string> ss;\n  FOR(i, len(A) - n + 1) { ss.insert(A.substr(i,\
    \ n)); }\n  FOR(i, len(B) - n + 1) { assert(!ss.count(B.substr(i, n))); }\n}\n\
    \nvoid test() {\n  FOR(n, 1, 20) FOR(m, 1, 20) {\n    FOR(100) {\n      string\
    \ s, t;\n      FOR(n) {\n        int x = RNG(0, 3);\n        s += 'a' + x;\n \
    \     }\n      FOR(m) {\n        int x = RNG(0, 3);\n        t += 'a' + x;\n \
    \     }\n      test_pair(s, t);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/longest_common_substr.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/longest_common_substr.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/longest_common_substr.test.cpp
- /verify/test/1_mytest/longest_common_substr.test.cpp.html
title: test/1_mytest/longest_common_substr.test.cpp
---
