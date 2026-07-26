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
    \n\n#include \"string/suffix_lcp_change.hpp\"\n#include \"random/base.hpp\"\n\n\
    /*\nsuffix array \u9806 suffix s[0],...,s[n-1]. L_p: s[p] \u3068\u306E lcp.\n\
    sum_k min(L_p[k], r-l) * [l<=SA[k]<r].\n\nL_p[] \u304C\u5927\u304D\u3044\u306E\
    \u306F\u533A\u9593 [L,R)\n\nsum_{0<=k<L} (r-l) * [l<=SA[k]<r]\nsum_{L<=k<R} L_p[k]\
    \ * [l<=SA[k]<r]\nsum_{R<=k<N} (r-l) * [l<=SA[k]<r]\n*/\nvoid test() {\n  FOR(N,\
    \ 1, 30) {\n    FOR(K, 1, 20) {\n      FOR(1000) {\n        string S;\n      \
    \  FOR(N) S += 'a' + RNG(0, K);\n        Suffix_Array<0> X(S);\n        auto [A,\
    \ change] = suffix_lcp_change(X);\n        auto& SA = X.SA;\n        FOR(i, N)\
    \ { assert(A[i] == X.lcp(SA[0], SA[i])); }\n        FOR(k, N - 1) {\n        \
    \  for (auto [l, r, x]: change[k]) {\n            FOR(i, l, r) {\n           \
    \   assert(A[i] != x);\n              A[i] = x;\n            }\n          }\n\
    \          FOR(i, N) { assert(A[i] == X.lcp(SA[k + 1], SA[i])); }\n        }\n\
    \      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return\
    \ 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/suffix_lcp_change.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/suffix_lcp_change.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/suffix_lcp_change.test.cpp
- /verify/test/1_mytest/suffix_lcp_change.test.cpp.html
title: test/1_mytest/suffix_lcp_change.test.cpp
---
