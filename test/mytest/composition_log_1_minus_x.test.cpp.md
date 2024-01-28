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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: poly/fps_composition.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"poly/composition_f_log_1_minus_x.hpp\"\
    \n#include \"poly/fps_composition.hpp\"\n#include \"mod/modint.hpp\"\n\nusing\
    \ mint = modint998;\n\nvoid test() {\n  auto gen = [&](int n) -> vc<mint> {\n\
    \    vc<mint> f(n + 1);\n    FOR(i, n + 1) f[i] = RNG(mint::get_mod());\n    return\
    \ f;\n  };\n  FOR(n, 100) {\n    vc<mint> f = gen(n);\n    vc<mint> g(n + 1);\n\
    \    FOR(i, 1, n + 1) g[i] = -inv<mint>(i);\n    vc<mint> F = composition_f_log_1_minus_x(f);\n\
    \    vc<mint> G = fps_composition(f, g);\n    assert(F == G);\n  }\n}\n\nvoid\
    \ solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\n\
    signed main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/composition_log_1_minus_x.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/composition_log_1_minus_x.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/composition_log_1_minus_x.test.cpp
- /verify/test/mytest/composition_log_1_minus_x.test.cpp.html
title: test/mytest/composition_log_1_minus_x.test.cpp
---
