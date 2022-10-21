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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: dp/longest_common_subsequence.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C&lang=ja\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"dp/longest_common_subsequence.hpp\"\
    \n\nvoid solve() {\n  STR(S, T);\n  ll LCS = longest_common_subsequence(S, T);\n\
    \  vc<pair<int, int>> pairs = longest_common_subsequence_restore(S, T);\n  assert(len(pairs)\
    \ == LCS);\n  for (auto&& [i, j]: pairs) assert(S[i] == T[j]);\n  FOR(i, LCS -\
    \ 1) {\n    assert(pairs[i].fi < pairs[i + 1].fi);\n    assert(pairs[i].se < pairs[i\
    \ + 1].se);\n  }\n  print(LCS);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n \
    \ ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  LL(T);\n  FOR(_,\
    \ T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/ALDS1_10_C.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/ALDS1_10_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_10_C.test.cpp
- /verify/test/aoj/ALDS1_10_C.test.cpp.html
title: test/aoj/ALDS1_10_C.test.cpp
---
