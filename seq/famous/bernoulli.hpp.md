---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/xmascon23/tasks/xmascon23_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/fps_div.hpp\"\n#include \"mod/powertable.hpp\"\n\ntemplate\
    \ <typename mint>\nvc<mint> bernoulli_number(int N) {\n  int n = N / 2;\n  vc<mint>\
    \ F(n + 1), G(n + 1);\n  mint pow = 1;\n  FOR(i, n + 1) {\n    F[i] = fact_inv<mint>(2\
    \ * i) * pow;\n    G[i] = fact_inv<mint>(2 * i + 1) * pow;\n    pow *= inv<mint>(4);\n\
    \  }\n  F = fps_div<mint>(F, G);\n  vc<mint> B(N + 1);\n  if (1 <= N) B[1] = -inv<mint>(2);\n\
    \  FOR(i, n + 1) B[2 * i] = F[i] * fact<mint>(2 * i);\n  return B;\n}\n\ntemplate\
    \ <typename mint>\nmint single_bernoulli(int n) {\n  // https://atcoder.jp/contests/xmascon23/tasks/xmascon23_e\n\
    \  if (n == 0) return 1;\n  if (n == 1) return -inv<mint>(2);\n  /*\n  B_n = [x^n/n!]\
    \ x / (exp(x)-1) = F(1-e^x)\n  F(x) = 1+(1/2)x+(1/3)x^2+...\n  \u3053\u308C\u3092\
    \ x^n \u3067\u6253\u3061\u5207\u308B\n  F(x) = 1+(1/2)x+(1/3)x^2+...+(1/n+1)x^n,\
    \ G(x) = F(1-x)\n  (xF(x)) d/dx = 1-x^{n+1}/1-x\n  ((1-x)G(x)) -d/dx = 1-(1-x)^{n+1}/x\
    \ = H(x)\n  */\n  vc<mint> G(n + 2);\n  mint sm = 0;\n  FOR(i, 1, n + 2) {\n \
    \   mint c = C<mint>(n + 1, i);\n    mint h = (i % 2 == 0 ? c : -c);\n    // H(x)\
    \ = ... gx^{i-1}\n    G[i] = h * inv<mint>(i);\n    sm += inv<mint>(i);\n  }\n\
    \  G[0] = sm;\n  FOR(i, n) G[i + 1] += G[i];\n  vc<mint> pow = powertable_2<mint>(n,\
    \ n);\n  mint ans = 0;\n  FOR(i, n + 1) { ans += pow[i] * G[i]; }\n  return ans;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/bernoulli.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/famous/bernoulli.hpp
layout: document
redirect_from:
- /library/seq/famous/bernoulli.hpp
- /library/seq/famous/bernoulli.hpp.html
title: seq/famous/bernoulli.hpp
---
