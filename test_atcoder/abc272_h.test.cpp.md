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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc272/tasks/abc272_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"mod/modint.hpp\"\
    \n#include \"poly/convolution.hpp\"\n#include \"poly/convolution_all.hpp\"\n#include\
    \ \"poly/multipoint.hpp\"\n\nusing mint = modint998;\n\nvoid solve() {\n  LL(N);\n\
    \  VEC(int, A, N);\n  sort(all(A));\n  vc<mint> f(N + 1);\n  FOR(i, N + 1) f[i]\
    \ = fact_inv<mint>(i);\n  vvc<mint> polys;\n  FOR(k, N) {\n    vc<mint> p = {mint(A[k]\
    \ - k), mint(1)};\n    polys.eb(p);\n  }\n  auto p = convolution_all(polys);\n\
    \  vc<mint> X(N + 1);\n  FOR(i, N + 1) X[i] = mint(i);\n  auto Y = multipoint_eval(p,\
    \ X);\n  FOR(i, N + 1) f[i] *= Y[i];\n  {\n    vc<mint> g(N + 1);\n    FOR(i,\
    \ N + 1) g[i] = fact_inv<mint>(i) * (i % 2 == 1 ? mint(-1) : mint(1));\n    f\
    \ = convolution(f, g);\n    f.resize(N + 1);\n  }\n  reverse(all(f));\n\n  FOR(k,\
    \ N + 1) f[k] *= fact<mint>(N - k);\n  FOR(k, N + 1) f[k] *= fact<mint>(k);\n\
    \  reverse(all(f));\n  vc<mint> g(N + 1);\n  FOR(i, N + 1) g[i] = fact_inv<mint>(i)\
    \ * (i % 2 == 1 ? mint(-1) : mint(1));\n  f = convolution(f, g);\n  f.resize(N\
    \ + 1);\n  reverse(all(f));\n  FOR(k, N + 1) f[k] *= fact_inv<mint>(k);\n\n  mint\
    \ ANS = 0;\n  FOR(k, N + 1) if (k % 2 == 1) ANS += f[k];\n  ANS *= fact_inv<mint>(N)\
    \ * mint(N);\n  print(ANS);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/abc272_h.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc272_h.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc272_h.test.cpp
- /verify/test_atcoder/abc272_h.test.cpp.html
title: test_atcoder/abc272_h.test.cpp
---
