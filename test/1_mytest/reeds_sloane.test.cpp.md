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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\n#include \"random/base.hpp\"\
    \n#include \"poly/convolution.hpp\"\n#include \"mod/dynamic_modint.hpp\"\n#include\
    \ \"seq/reeds_sloane.hpp\"\n\ntemplate <typename mint>\nvc<mint> from_PQ(int N,\
    \ vc<mint> P, vc<mint> Q) {\n  P.resize(N), Q.resize(N);\n  vc<mint> S(N);\n \
    \ FOR(i, N) {\n    S[i] += P[i];\n    FOR(j, 1, len(Q)) {\n      int k = i - j;\n\
    \      if (0 <= k) S[i] -= S[k] * Q[j];\n    }\n  }\n  return S;\n}\n\ntemplate\
    \ <int mod>\nvoid test(int T) {\n  using mint = modint<mod>;\n  auto pfs = factor(mod);\n\
    \n  FOR(T) {\n    int N = RNG(1, 20);\n    int L = RNG(0, N + 1);\n    vc<mint>\
    \ QQ(L + 1);\n    vc<mint> PP(L);\n    QQ[0] = 1;\n    FOR(i, L) PP[i] = RNG(0,\
    \ mod), QQ[1 + i] = RNG(0, mod);\n    auto S = from_PQ(N, PP, QQ);\n    auto [P,\
    \ Q] = Reeds_Sloane<mint>(S, pfs);\n    assert(len(P) <= L);\n    assert(len(Q)\
    \ - 1 <= L);\n    assert(Q[0] == 1);\n    assert(S == from_PQ(N, P, Q));\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  int T = 1 << 13;\n  test<1>(T);\n  test<2>(T);\n  test<3>(T);\n\
    \  test<4>(T);\n  test<5>(T);\n  test<6>(T);\n  test<7>(T);\n  test<8>(T);\n \
    \ test<9>(T);\n  test<10>(T);\n  test<12>(T);\n  test<16>(T);\n  test<32>(T);\n\
    \  test<64>(T);\n  test<60>(T);\n  test<100>(T);\n  test<210>(T);\n  solve();\n\
    \  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/reeds_sloane.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/reeds_sloane.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/reeds_sloane.test.cpp
- /verify/test/1_mytest/reeds_sloane.test.cpp.html
title: test/1_mytest/reeds_sloane.test.cpp
---
