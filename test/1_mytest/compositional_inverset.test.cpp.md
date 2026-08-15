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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"poly/compositional_inverse.hpp\"\n#include \"poly/compositional_inverse_old.hpp\"\
    \n#include \"poly/composition.hpp\"\n#include \"random/base.hpp\"\n\nusing mint\
    \ = modint998;\n\nvoid test() {\n  FOR(N, 100) {\n    vc<mint> f(N);\n    FOR(i,\
    \ 1, N) f[i] = RNG(1, 10);\n    vc<mint> A = compositional_inverse<mint>(f);\n\
    \    vc<mint> B = compositional_inverse_old<mint>(f);\n    assert(A == B);\n \
    \   vc<mint> F = composition<mint>(f, A);\n    vc<mint> G = composition<mint>(A,\
    \ f);\n    FOR(i, N) {\n      if (i == 1) {\n        assert(F[i] == mint(1));\n\
    \        assert(G[i] == mint(1));\n      } else {\n        assert(F[i] == mint(0));\n\
    \        assert(G[i] == mint(0));\n      }\n    }\n  }\n}\n\nvoid solve() {\n\
    \  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/compositional_inverset.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/compositional_inverset.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/compositional_inverset.test.cpp
- /verify/test/1_mytest/compositional_inverset.test.cpp.html
title: test/1_mytest/compositional_inverset.test.cpp
---
