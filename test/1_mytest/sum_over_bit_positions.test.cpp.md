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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/my_bitset.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"ds/my_bitset.hpp\"\n#include \"random/base.hpp\"\n#include \"ds/sum_over_bit_positions.hpp\"\
    \n\nvoid test(int N, int Q, bool check = true) {\n  vector<int> A(N);\n  My_Bitset\
    \ bs(N);\n  FOR(i, N) A[i] = RNG(0, N), bs[i] = RNG(0, 2);\n  Sum_Over_Bit_Positions<int,\
    \ 100'000> SB(N, [&](int i) -> int { return A[i]; });\n\n  FOR(Q) {\n    FOR(100)\
    \ {\n      int i = RNG(0, N);\n      bs[i].flip();\n    }\n    ll ans = SB.query<ll>(bs,\
    \ 0, N);\n    if (check) {\n      ll god = 0;\n      FOR(i, N) if (bs[i]) god\
    \ += A[i];\n      assert(ans == god);\n    }\n  }\n}\n\nvoid solve() {\n  int\
    \ a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n\
    \  // test(100'000, 10'000, false);\n  FOR(N, 1, 150) FOR(Q, 1, 150) test(N, Q,\
    \ true);\n  solve();\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/sum_over_bit_positions.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/sum_over_bit_positions.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/sum_over_bit_positions.test.cpp
- /verify/test/1_mytest/sum_over_bit_positions.test.cpp.html
title: test/1_mytest/sum_over_bit_positions.test.cpp
---
