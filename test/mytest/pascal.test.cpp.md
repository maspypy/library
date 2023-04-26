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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n#include\
    \ \"mod/modint.hpp\"\n#include \"linalg/implicit_matrix/pascal.hpp\"\n\nusing\
    \ mint = modint998;\n\nvc<mint> gen(int N) {\n  int mod = mint::get_mod();\n \
    \ vc<mint> f(N);\n  FOR(i, N) f[i] = RNG(mod);\n  return f;\n}\n\nvc<mint> pascal_naive(vc<mint>\
    \ f, bool transpose) {\n  int N = len(f);\n  vc<mint> g(N);\n  if (!transpose)\
    \ {\n    FOR(i, N) FOR(j, N) if (i >= j) g[i] += C<mint>(i, j) * f[j];\n  }\n\
    \  if (transpose) {\n    FOR(i, N) FOR(j, N) if (i <= j) g[i] += C<mint>(j, i)\
    \ * f[j];\n  }\n  return g;\n}\n\nvoid test() {\n  FOR(t, 2) {\n    FOR(N, 1,\
    \ 100) {\n      vc<mint> f = gen(N);\n      vc<mint> g1 = pascal<mint>(f, t, 0);\n\
    \      vc<mint> g2 = pascal_naive(f, t);\n      assert(g1 == g2);\n      vc<mint>\
    \ h = pascal<mint>(g1, t, 1);\n      assert(f == h);\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/pascal.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/pascal.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/pascal.test.cpp
- /verify/test/mytest/pascal.test.cpp.html
title: test/mytest/pascal.test.cpp
---
