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
    \n#include \"poly/multipoint.hpp\"\n\nvoid test() {\n  using mint = modint998;\n\
    \  const int mod = mint::get_mod();\n  auto gen = [&](int n) -> vc<mint> {\n \
    \   vc<mint> f(n);\n    FOR(i, n) f[i] = RNG(0, mod);\n    return f;\n  };\n \
    \ auto naive = [&](vc<mint> f, mint a, mint r, int m) -> vc<mint> {\n    vc<mint>\
    \ g(m);\n    FOR(j, m) {\n      mint pow = 1;\n      FOR(i, len(f)) g[j] += f[i]\
    \ * pow, pow *= a;\n      a *= r;\n    }\n    return g;\n  };\n  FOR(n, 1, 100)\
    \ FOR(m, 1, 100) {\n    vc<mint> f = gen(n);\n    mint a = RNG(1, mod);\n    mint\
    \ r = RNG(1, mod);\n    auto A = multipoint_eval_on_geom_seq(f, a, r, m);\n  \
    \  auto B = naive(f, a, r, m);\n    assert(A == B);\n  }\n  FOR(n, 1, 100) FOR(m,\
    \ 1, 100) {\n    vc<mint> f = gen(n);\n    mint a = 0;\n    mint r = RNG(1, mod);\n\
    \    auto A = multipoint_eval_on_geom_seq(f, a, r, m);\n    auto B = naive(f,\
    \ a, r, m);\n    assert(A == B);\n  }\n}\n\nvoid solve() {\n  test();\n  LL(a,\
    \ b);\n  print(a + b);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/chirp_z.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/chirp_z.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/chirp_z.test.cpp
- /verify/test/mytest/chirp_z.test.cpp.html
title: test/mytest/chirp_z.test.cpp
---
