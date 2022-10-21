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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/random.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"other/random.hpp\"\
    \n#include \"mod/modint61.hpp\"\n#include \"string/rollinghash_2d.hpp\"\n\nvoid\
    \ solve() {\n  LL(H, W);\n  VEC(string, A, H);\n  RollingHash_2D RH;\n  auto AH\
    \ = RH.build(A);\n  LL(H2, W2);\n  VEC(string, B, H2);\n  auto BH = RH.build(B);\n\
    \  auto b = RH.query(BH, 0, 0, H2, W2);\n\n  FOR(x, H - H2 + 1) FOR(y, W - W2\
    \ + 1) {\n    auto a = RH.query(AH, x, y, x + H2, y + W2);\n    if (a == b) {\
    \ print(x, y); }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/ALDS1_14_C.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_C.test.cpp
- /verify/test/aoj/ALDS1_14_C.test.cpp.html
title: test/aoj/ALDS1_14_C.test.cpp
---
