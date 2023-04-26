---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barret.hpp
    title: mod/barret.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':x:'
    path: poly/middle_product.hpp
    title: poly/middle_product.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/2231.test.cpp
    title: test/yukicoder/2231.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"mod/modint.hpp\"\n#include \"poly/ntt.hpp\"\n#include \"poly/middle_product.hpp\"\
    \n\nvc<bool> wildcard_pattern_matching(string S, string T, char WILD = '?') {\n\
    \  using mint = modint998;\n  int N = len(S), M = len(T);\n  int mi = 1024;\n\
    \  for (auto&& x: S)\n    if (x != '?') chmin(mi, x);\n  for (auto&& x: T)\n \
    \   if (x != '?') chmin(mi, x);\n  vc<mint> f1(N), g1(M);\n  FOR(i, N) f1[i] =\
    \ (S[i] == '?' ? 0 : S[i] - mi + 1);\n  FOR(i, M) g1[i] = (T[i] == '?' ? 0 : T[i]\
    \ - mi + 1);\n  vc<mint> f2(N), f3(N), g2(M), g3(M);\n  FOR(i, N) f2[i] = f1[i]\
    \ * f1[i], f3[i] = f2[i] * f1[i];\n  FOR(i, M) g2[i] = g1[i] * g1[i], g3[i] =\
    \ g2[i] * g1[i];\n  vc<mint> A = middle_product(f1, g3);\n  vc<mint> B = middle_product(f2,\
    \ g2);\n  vc<mint> C = middle_product(f3, g1);\n  FOR(i, len(A)) A[i] = A[i] -\
    \ B[i] - B[i] + C[i];\n  vc<bool> res(len(A));\n  FOR(i, len(res)) res[i] = A[i]\
    \ == mint(0);\n  return res;\n}"
  dependsOn:
  - mod/modint.hpp
  - mod/modint_common.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/middle_product.hpp
  isVerificationFile: false
  path: string/wildcard_pattern_matching.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2231.test.cpp
documentation_of: string/wildcard_pattern_matching.hpp
layout: document
redirect_from:
- /library/string/wildcard_pattern_matching.hpp
- /library/string/wildcard_pattern_matching.hpp.html
title: string/wildcard_pattern_matching.hpp
---
