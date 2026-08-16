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
    - https://math.stackexchange.com/questions/483101/rabin-and-shallit-algorithm
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#include \"nt/primetest.hpp\"\n#include \"nt/gaussian_integers.hpp\"\n\n\
    // https://math.stackexchange.com/questions/483101/rabin-and-shallit-algorithm\n\
    // ERH \u306E\u3082\u3068 O(log^2N) \uFF1F\ntuple<ll, ll, ll> three_square(ll\
    \ N) {\n  if (N == 0) return {0, 0, 0};\n  auto F = [&](ll n) -> tuple<ll, ll,\
    \ ll> {\n    if (N == 2) return {1, 1, 0};\n    if (N == 3) return {1, 1, 1};\n\
    \    if (N == 10) return {3, 1, 0};\n    if (N == 34) return {5, 3, 0};\n    if\
    \ (N == 58) return {7, 3, 0};\n    if (N == 85) return {9, 2, 0};\n    if (N ==\
    \ 130) return {11, 3, 0};\n    if (N == 214) return {14, 3, 3};\n    if (N ==\
    \ 226) return {15, 1, 0};\n    if (N == 370) return {19, 3, 0};\n    if (N ==\
    \ 526) return {21, 9, 2};\n    if (N == 706) return {25, 9, 0};\n    if (N ==\
    \ 730) return {27, 1, 0};\n    if (N == 1414) return {33, 18, 1};\n    if (N ==\
    \ 1906) return {41, 15, 0};\n    if (N == 2986) return {45, 31, 0};\n    if (N\
    \ == 9634) return {97, 15, 0};\n    ll x = sqrtl(N);\n    if (N == x * x) return\
    \ {x, 0, 0};\n    if (N % 4 != 1 && x % 2 == 0) --x;\n    if (N % 4 == 1 && x\
    \ % 2 == 1) --x;\n    x += 2;\n    while (1) {\n      x -= 2;\n      ll k = N\
    \ - x * x;\n      if (k < 0) break;\n      if (k % 2 == 1 && primetest(k)) {\n\
    \        auto [a, b] = solve_norm_equation_prime(k);\n        a = abs(a), b =\
    \ abs(b);\n        return {a, b, x};\n      }\n      if (k % 2 == 0 && primetest(k\
    \ / 2)) {\n        auto [a, b] = solve_norm_equation_prime(k / 2);\n        tie(a,\
    \ b) = mp(a + b, a - b);\n        a = abs(a), b = abs(b);\n        return {a,\
    \ b, x};\n      }\n    }\n    assert(0);\n    return {-1, -1, -1};\n  };\n  ll\
    \ e = 0;\n  while (N % 4 == 0) N /= 4, ++e;\n  if (N % 8 == 7) return {-1, -1,\
    \ -1};\n  auto [a, b, c] = F(N);\n  return {a << e, b << e, c << e};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/three_square.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/three_square.hpp
layout: document
redirect_from:
- /library/nt/three_square.hpp
- /library/nt/three_square.hpp.html
title: nt/three_square.hpp
---
