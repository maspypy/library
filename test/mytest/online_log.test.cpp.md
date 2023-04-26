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
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"mod/modint.hpp\"\n#include \"random/base.hpp\"\
    \n#include \"poly/fps_log.hpp\"\n#include \"poly/online/online_log.hpp\"\n\nusing\
    \ mint = modint998;\n\nvoid test() {\n  auto gen = [&](int n) -> vc<mint> {\n\
    \    vc<mint> f(n + 1);\n    FOR(i, n + 1) f[i] = RNG(mint::get_mod());\n    return\
    \ f;\n  };\n  FOR(n, 1000) {\n    vc<mint> f = gen(n);\n    f[0] = mint(1);\n\
    \    vc<mint> g = fps_log<mint>(f);\n    Online_Log<mint> X;\n    FOR(i, n + 1)\
    \ { assert(g[i] == X.query(i, f[i])); }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n\
    \  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/online_log.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/online_log.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/online_log.test.cpp
- /verify/test/mytest/online_log.test.cpp.html
title: test/mytest/online_log.test.cpp
---
