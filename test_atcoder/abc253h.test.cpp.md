---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: setfunc/transposed_sps_composition.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc253/tasks/abc253_Ex\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"setfunc/sps_exp.hpp\"\n#include \"setfunc/transposed_sps_composition.hpp\"\
    \n\nconst int LIM = 14;\nusing mint = modint998;\n\nvoid solve() {\n  LL(N, M);\n\
    \n  vv(int, mat, N, N);\n  FOR(M) {\n    INT(a, b);\n    --a, --b;\n    mat[a][b]++,\
    \ mat[b][a]++;\n  }\n\n  // count tree\n  vc<mint> dp(1 << N);\n  dp[0] = 0;\n\
    \  FOR(i, N) {\n    vc<mint> a = {dp.begin(), dp.begin() + (1 << i)};\n    FOR(s,\
    \ 1 << i) {\n      int k = 0;\n      FOR(j, i) if (s >> j & 1) k += mat[i][j];\n\
    \      a[s] *= mint(k);\n    }\n    a = sps_exp<mint, LIM>(a);\n    copy(all(a),\
    \ dp.begin() + (1 << i));\n  }\n\n  vc<mint> x(1 << N);\n  x.back() = mint(1);\n\
    \  auto y = transposed_sps_composition_egf<mint, LIM>(dp, x);\n\n  FOR(k, 1, N)\
    \ {\n    // k edges = N-k component\n    mint ans = y[N - k];\n    ans *= inv<mint>(M).pow(k)\
    \ * fact<mint>(k);\n    print(ans);\n  }\n}\n\nsigned main() {\n  solve();\n \
    \ return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/abc253h.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc253h.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc253h.test.cpp
- /verify/test_atcoder/abc253h.test.cpp.html
title: test_atcoder/abc253h.test.cpp
---
