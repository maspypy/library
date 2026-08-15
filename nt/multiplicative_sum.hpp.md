---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
  code: "#include \"nt/primetable.hpp\"\r\n\r\n// f_pe\uFF1AT(int p,int e), f(p^e)\r\
    \n// f_psum\uFF1A[1, x] \u3067\u306E f(p) \u306E\u548C\r\ntemplate <typename T,\
    \ typename F1, typename F2>\r\nT multiplicative_sum(ll N, F1 f_pe, F2 f_psum)\
    \ {\r\n  ll sqN = sqrtl(N);\r\n  auto P = primetable<int>(sqN);\r\n\r\n  T ANS\
    \ = T(1) + f_psum(N); // 1 and prime\r\n  // t = up_i^k \u306E\u3068\u304D\u306B\
    \u3001(t, i, k, f(t), f(u)) \u3092\u6301\u305F\u305B\u308B\r\n\r\n  auto dfs =\
    \ [&](auto self, ll t, ll i, ll k, T ft, T fu) -> void {\r\n    T f_nxt = fu *\
    \ f_pe(P[i], k + 1);\r\n    // \u5B50\u30CE\u30FC\u30C9\u3092\u5168\u90E8\u52A0\
    \u7B97\r\n    ANS += f_nxt;\r\n    ANS += ft * (f_psum(double(N) / t) - f_psum(P[i]));\r\
    \n\r\n    ll lim = sqrtl(double(N) / t);\r\n    if (P[i] <= lim) { self(self,\
    \ t * P[i], i, k + 1, f_nxt, fu); }\r\n    FOR3(j, i + 1, len(P)) {\r\n      if\
    \ (P[j] > lim) break;\r\n      self(self, t * P[j], j, 1, ft * f_pe(P[j], 1),\
    \ ft);\r\n    }\r\n  };\r\n  FOR(i, len(P)) if (P[i] <= sqN) dfs(dfs, P[i], i,\
    \ 1, f_pe(P[i], 1), 1);\r\n  return ANS;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/multiplicative_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/multiplicative_sum.hpp
layout: document
redirect_from:
- /library/nt/multiplicative_sum.hpp
- /library/nt/multiplicative_sum.hpp.html
title: nt/multiplicative_sum.hpp
---
