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
    - https://atcoder.jp/contests/xmascon20/tasks/xmascon20_d
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#include \"nt/primetable.hpp\"\n#include \"nt/primesum.hpp\"\n\n// factor\
    \ type: \u964D\u9806 270 -> (3,1,1)\n// N=10^9: 1324 \u7A2E\u985E, 0.4sec\n//\
    \ https://atcoder.jp/contests/xmascon20/tasks/xmascon20_d\nmap<vc<int>, ll> count_by_factor_type(ll\
    \ N) {\n  ll sqN = sqrtl(N);\n  auto P = primetable<int>(sqN);\n  PrimeSum<ll>\
    \ X(N);\n  X.calc_count();\n\n  // 1 and prime\n  map<vc<int>, ll> ANS;\n  ANS[vc<int>()]\
    \ = 1;\n  if (X[N] > 0) ANS[vc<int>({1})] = X[N];\n\n  auto add = [&](vc<int>\
    \ F, int k) -> vc<int> {\n    int p = len(F);\n    F.eb(k);\n    while (0 < p\
    \ && F[p - 1] < F[p]) { swap(F[p - 1], F[p]), --p; }\n    return F;\n  };\n\n\
    \  // t = up_i^k \u306E\u3068\u304D\u306B\n  auto dfs = [&](auto& dfs, ll t, ll\
    \ i, ll k, vc<int> U) -> void {\n    // U * primes \u3092\u8FFD\u52A0\u3059\u308B\
    \n    vc<int> nxt1 = add(U, k + 1);\n    ANS[nxt1]++;\n    vc<int> Uk = add(U,\
    \ k);\n    vc<int> nxt2 = add(Uk, 1);\n    ll cnt = X[N / t] - X[P[i]];\n    if\
    \ (cnt > 0) ANS[nxt2] += X[N / t] - X[P[i]];\n    ll lim = sqrtl(double(N) / t);\n\
    \    if (P[i] <= lim) { dfs(dfs, t * P[i], i, k + 1, U); }\n    FOR(j, i + 1,\
    \ len(P)) {\n      if (P[j] > lim) break;\n      dfs(dfs, t * P[j], j, 1, Uk);\n\
    \    }\n  };\n  FOR(i, len(P)) if (P[i] <= sqN) dfs(dfs, P[i], i, 1, {});\n  return\
    \ ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/count_by_factor_type.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/count_by_factor_type.hpp
layout: document
redirect_from:
- /library/nt/count_by_factor_type.hpp
- /library/nt/count_by_factor_type.hpp.html
title: nt/count_by_factor_type.hpp
---
