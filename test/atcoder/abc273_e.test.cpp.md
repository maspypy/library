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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/pds/array.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc273/tasks/abc273_e\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/pds/array.hpp\"\
    \n\nvoid solve() {\n  PersistentArray<int> PA;\n  using np = PersistentArray<int>::np;\n\
    \n  map<int, np> MP;\n  map<int, int> sz;\n\n  LL(Q);\n  vi ANS;\n\n  np now =\
    \ PA.get_root();\n  int now_sz = 0;\n\n  FOR(Q) {\n    STR(S);\n    if (S == \"\
    ADD\") {\n      INT(x);\n      now = PA.set(now, now_sz++, x);\n    }\n    if\
    \ (S == \"DELETE\") {\n      if (now_sz >= 1) --now_sz;\n    }\n    if (S == \"\
    SAVE\") {\n      INT(y);\n      MP[y] = now;\n      sz[y] = now_sz;\n    }\n \
    \   if (S == \"LOAD\") {\n      INT(z);\n      now = MP[z];\n      now_sz = sz[z];\n\
    \    }\n    ll x = -1;\n    if (now_sz) x = PA.get(now, now_sz - 1);\n    ANS.eb(x);\n\
    \  }\n  print(ANS);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc273_e.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc273_e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc273_e.test.cpp
- /verify/test/atcoder/abc273_e.test.cpp.html
title: test/atcoder/abc273_e.test.cpp
---
