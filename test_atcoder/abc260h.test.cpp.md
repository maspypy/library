---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linalg/implicit_matrix/pascal.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc260/tasks/abc260_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"poly/convolution_all.hpp\"\n#include \"linalg/implicit_matrix/pascal.hpp\"\
    \n#include \"linalg/implicit_matrix/vandermonde.hpp\"\n\nusing mint = modint998;\n\
    \nvoid solve() {\n  LL(N, M);\n  VEC(int, A, N);\n  vc<int> CNT(N);\n  for (auto&&\
    \ x: A) CNT[x - 1]++;\n  // \u5305\u9664\u30EB\u30FC\u30EB\u306E\u500B\u6570 ->\
    \ \u30EB\u30FC\u30EB\u306E\u6C7A\u3081\u65B9\n  vvc<mint> polys;\n  FOR(x, N)\
    \ {\n    int n = CNT[x];\n    if (n <= 1) continue;\n    vc<mint> f(n);\n    FOR(i,\
    \ n) f[i] = C<mint>(n - 1, i) * fact_inv<mint>(n - i);\n    polys.eb(f);\n  }\n\
    \  vc<mint> f = convolution_all(polys);\n\n  FOR(i, len(f)) f[i] *= fact<mint>(N\
    \ - i);\n  f = pascal(f, true, true);\n\n  {\n    mint cf = 1;\n    for (auto&&\
    \ x: CNT) cf *= fact<mint>(x);\n    for (auto&& x: f) x *= cf;\n  }\n\n  int L\
    \ = max(N, M + 1);\n  vc<mint> g(N);\n  FOR(i, len(f)) g[N - 1 - i] = f[i];\n\
    \  g.resize(L);\n\n  vc<mint> x(L);\n  FOR(i, L) x[i] = i;\n  vc<mint> ANS = vandermonde(g,\
    \ x, true, false);\n  ANS.erase(ANS.begin());\n  ANS.resize(M);\n  print(ANS);\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/abc260h.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc260h.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc260h.test.cpp
- /verify/test_atcoder/abc260h.test.cpp.html
title: test_atcoder/abc260h.test.cpp
---
