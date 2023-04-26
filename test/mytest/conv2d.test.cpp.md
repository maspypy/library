---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"random/base.hpp\"\n#include \"mod/modint.hpp\"\
    \n#include \"poly/convolution2d.hpp\"\n\nusing mint = modint998;\n\nvoid test()\
    \ {\n  auto gen = [&](ll H, ll W) -> vvc<mint> {\n    vv(mint, A, H, W);\n   \
    \ FOR(i, H) FOR(j, W) A[i][j] = RNG(mint::get_mod());\n    return A;\n  };\n\n\
    \  auto naive_conv = [&](vvc<mint> A, vvc<mint> B) -> vvc<mint> {\n    ll H =\
    \ len(A) + len(B) - 1;\n    ll W = len(A[0]) + len(B[0]) - 1;\n    vv(mint, C,\
    \ H, W);\n    FOR(a, len(A)) FOR(b, len(A[0])) {\n      FOR(c, len(B)) FOR(d,\
    \ len(B[0])) { C[a + c][b + d] += A[a][b] * B[c][d]; }\n    }\n    return C;\n\
    \  };\n\n  ll LIM = 10;\n  FOR(H1, 1, LIM) FOR(W1, 1, LIM) FOR(H2, 1, LIM) FOR(W2,\
    \ 1, LIM) {\n    auto A = gen(H1, W1);\n    auto B = gen(H2, W2);\n    auto C1\
    \ = naive_conv(A, B);\n    auto C2 = convolution2d<mint>(A, B);\n    assert(C1\
    \ == C2);\n  }\n\n  ll H1 = RNG(50, 100);\n  ll W1 = RNG(50, 100);\n  ll H2 =\
    \ RNG(50, 100);\n  ll W2 = RNG(50, 100);\n  auto A = gen(H1, W1);\n  auto B =\
    \ gen(H2, W2);\n  auto C1 = naive_conv(A, B);\n  auto C2 = convolution2d<mint>(A,\
    \ B);\n  assert(C1 == C2);\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n\
    }\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\n  test();\n  solve();\n\
    \n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/conv2d.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/conv2d.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/conv2d.test.cpp
- /verify/test/mytest/conv2d.test.cpp.html
title: test/mytest/conv2d.test.cpp
---
