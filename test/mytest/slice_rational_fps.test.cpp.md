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
    \n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n\n#include \"mod/modint.hpp\"\
    \n#include \"poly/slice_rational_fps.hpp\"\n\nusing mint = modint998;\n\nvc<mint>\
    \ gen(int n) {\n  vc<mint> f(n);\n  FOR(i, n) f[i] = RNG(0, 100);\n  return f;\n\
    }\n\nvoid test() {\n  using poly = vc<mint>;\n  FOR(n, 1, 10) FOR(m, n) {\n  \
    \  poly P = gen(m), Q = gen(n);\n    Q[0] = mint(1);\n    poly f = P, g = Q;\n\
    \    f.resize(100), g.resize(100);\n    vc<mint> F = fps_div(f, g);\n    FOR(i,\
    \ 50) {\n      poly A = slice_rational_fps(P, Q, i);\n      poly B = {F.begin()\
    \ + i, F.begin() + i + n - 1};\n      assert(A == B);\n    }\n  }\n  int n = 500;\n\
    \  int m = 499;\n  poly P = gen(m), Q = gen(n);\n  Q[0] = mint(1);\n  poly f =\
    \ P, g = Q;\n  f.resize(1000), g.resize(1000);\n  vc<mint> F = fps_div(f, g);\n\
    \  FOR(i, 500) {\n    auto A = slice_rational_fps(P, Q, i);\n    poly B = {F.begin()\
    \ + i, F.begin() + i + n - 1};\n    assert(A == B);\n  }\n}\n\nvoid solve() {\n\
    \  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n \
    \ return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/slice_rational_fps.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/slice_rational_fps.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/slice_rational_fps.test.cpp
- /verify/test/mytest/slice_rational_fps.test.cpp.html
title: test/mytest/slice_rational_fps.test.cpp
---
