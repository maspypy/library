---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convex/minplus_convolution_convex.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"random/base.hpp\"\n#include \"convex/minplus_convolution_of_triples.hpp\"\
    \n\nvoid test() {\n  FOR(N, 0, 300) {\n    vi A(N), B(N), C(N);\n    FOR(i, N)\
    \ A[i] = RNG(1, 1 << 30);\n    FOR(i, N) B[i] = RNG(1, 1 << 30);\n    FOR(i, N)\
    \ C[i] = RNG(1, 1 << 30);\n    // \u611A\u76F4\n    vi dp(2 * N + 1, infty<ll>);\n\
    \    dp[0] = 0;\n    FOR(i, N) {\n      ll a = A[i], b = B[i], c = C[i];\n   \
    \   vi newdp(2 * N + 1, infty<ll>);\n      FOR(i, len(dp)) {\n        if (i +\
    \ 0 <= 2 * N) chmin(newdp[i + 0], dp[i] + a);\n        if (i + 1 <= 2 * N) chmin(newdp[i\
    \ + 1], dp[i] + b);\n        if (i + 2 <= 2 * N) chmin(newdp[i + 2], dp[i] + c);\n\
    \      }\n      swap(dp, newdp);\n    }\n\n    MinPlus_Convolution_of_Triples<ll>\
    \ X;\n    FOR(i, N) X.add(A[i], B[i], C[i]);\n    X.solve();\n    FOR(K, 2 * N\
    \ + 1) {\n      ll val = X[K];\n      vc<int> x = X.restore(K);\n      assert(SUM<int>(x)\
    \ == K);\n      ll sm = 0;\n      FOR(i, N) {\n        assert(0 <= x[i] && x[i]\
    \ <= 2);\n        if (x[i] == 0) sm += A[i];\n        if (x[i] == 1) sm += B[i];\n\
    \        if (x[i] == 2) sm += C[i];\n      }\n      assert(sm == val && val ==\
    \ dp[K]);\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\n\
    signed main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/minplus_conv_triple.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/minplus_conv_triple.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/minplus_conv_triple.test.cpp
- /verify/test/mytest/minplus_conv_triple.test.cpp.html
title: test/mytest/minplus_conv_triple.test.cpp
---
