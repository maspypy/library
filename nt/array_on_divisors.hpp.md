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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#include \"nt/factor.hpp\"\n#include \"ds/hashmap.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Array_On_Divisors {\n  vc<pair<ll, int>> pf;\n  vc<ll> divs;\n  vc<T>\
    \ dat;\n  HashMap<int> MP;\n\n  Array_On_Divisors(ll N = 1) { build(N); }\n  Array_On_Divisors(vc<pair<ll,\
    \ int>> pf) { build(pf); }\n\n  void build(ll N) { build(factor(N)); }\n  void\
    \ build(vc<pair<ll, int>> pfs) {\n    if (!pf.empty() && pf == pfs) return;\n\
    \    pf = pfs;\n    ll n = 1;\n    for (auto&& [p, e] : pf) n *= (e + 1);\n  \
    \  divs.assign(n, 1);\n    dat.assign(n, T{});\n    int nxt = 1;\n    for (auto&&\
    \ [p, e] : pf) {\n      int L = nxt;\n      ll q = p;\n      FOR(e) {\n      \
    \  FOR(i, L) { divs[nxt++] = divs[i] * q; }\n        q *= p;\n      }\n    }\n\
    \    MP.build(n);\n    FOR(i, n) MP[divs[i]] = i;\n  }\n\n  T& operator[](ll d)\
    \ { return dat[MP[d]]; }\n\n  // f(p, k) \u3092\u4E0E\u3048\u308B \u2192 \u4E57\
    \u6CD5\u7684\u306B\u62E1\u5F35\n  template <typename F>\n  void set_multiplicative(F\
    \ f) {\n    dat.reserve(len(divs));\n    dat = {T(1)};\n    for (auto&& [p, e]\
    \ : pf) {\n      int n = len(divs);\n      FOR(k, 1, e + 1) { FOR(i, n) dat.eb(dat[i]\
    \ * f(p, k)); }\n    }\n  }\n\n  void set_euler_phi() {\n    dat.resize(len(divs));\n\
    \    FOR(i, len(divs)) dat[i] = T(divs[i]);\n    divisor_mobius();\n  }\n\n  void\
    \ set_mobius() {\n    set_multiplicative([&](ll p, int k) -> T {\n      if (k\
    \ >= 2) return T(0);\n      return (k == 1 ? T(-1) : T(0));\n    });\n  }\n\n\
    \  void multiple_zeta() {\n    ll k = 1;\n    for (auto&& [p, e] : pf) {\n   \
    \   ll mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n        FOR_R(j, mod\
    \ - k) { dat[mod * i + j] += dat[mod * i + j + k]; }\n      }\n      k *= (e +\
    \ 1);\n    }\n  }\n\n  void multiple_mobius() {\n    ll k = 1;\n    for (auto&&\
    \ [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n\
    \        FOR(j, mod - k) { dat[mod * i + j] -= dat[mod * i + j + k]; }\n     \
    \ }\n      k *= (e + 1);\n    }\n  }\n\n  void divisor_zeta() {\n    ll k = 1;\n\
    \    for (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs)\
    \ / mod) {\n        FOR(j, mod - k) { dat[mod * i + j + k] += dat[mod * i + j];\
    \ }\n      }\n      k *= (e + 1);\n    }\n  }\n\n  void divisor_mobius() {\n \
    \   ll k = 1;\n    for (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n \
    \     FOR(i, len(divs) / mod) {\n        FOR_R(j, mod - k) { dat[mod * i + j +\
    \ k] -= dat[mod * i + j]; }\n      }\n      k *= (e + 1);\n    }\n  }\n\n  //\
    \ (Ta,Tb)->T : a-b\n  template <typename F>\n  void divisor_mobius(F SUB) {\n\
    \    ll k = 1;\n    for (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n\
    \      FOR(i, len(divs) / mod) {\n        FOR_R(j, mod - k) {\n          dat[mod\
    \ * i + j + k] = SUB(dat[mod * i + j + k], dat[mod * i + j]);\n        }\n   \
    \   }\n      k *= (e + 1);\n    }\n  }\n\n  // ADD(Ta,Tb)->T : a+b\n  template\
    \ <typename F>\n  void multiplier_zeta(F ADD) {\n    ll k = 1;\n    for (auto&&\
    \ [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs) / mod) {\n\
    \        FOR_R(j, mod - k) {\n          dat[mod * i + j] = ADD(dat[mod * i + j],\
    \ dat[mod * i + j + k]);\n        }\n      }\n      k *= (e + 1);\n    }\n  }\n\
    \n  // SUB(Ta,Tb)->T : a-=b\n  template <typename F>\n  void multiplier_mobius(F\
    \ SUB) {\n    ll k = 1;\n    for (auto&& [p, e] : pf) {\n      ll mod = k * (e\
    \ + 1);\n      FOR(i, len(divs) / mod) {\n        FOR(j, mod - k) {\n        \
    \  dat[mod * i + j] = SUB(dat[mod * i + j], dat[mod * i + j + k]);\n        }\n\
    \      }\n      k *= (e + 1);\n    }\n  }\n\n  // ADD(T&a,Tb)->void : a+=b\n \
    \ template <typename F>\n  void divisor_zeta(F ADD) {\n    ll k = 1;\n    for\
    \ (auto&& [p, e] : pf) {\n      ll mod = k * (e + 1);\n      FOR(i, len(divs)\
    \ / mod) {\n        FOR(j, mod - k) {\n          dat[mod * i + j + k] = ADD(dat[mod\
    \ * i + j + k], dat[mod * i + j]);\n        }\n      }\n      k *= (e + 1);\n\
    \    }\n  }\n\n  template <typename F>\n  void set(F f) {\n    FOR(i, len(divs))\
    \ { dat[i] = f(divs[i]); }\n  }\n\n  // (d, fd)\n  // &fd \u3067\u53D7\u3051\u53D6\
    \u308C\u3070\u4EE3\u5165\u3068\u304B\u3082\u3067\u304D\u307E\u3059\n  template\
    \ <typename F>\n  void enumerate(F f) {\n    FOR(i, len(divs)) { f(divs[i], dat[i]);\
    \ }\n  }\n\n  // n \u306E\u7D04\u6570\u5168\u4F53\n  vi get_divisors(ll n) {\n\
    \    assert(divs.back() % n == 0);\n    vi dp = {1};\n    for (auto& [p, f] :\
    \ pf) {\n      ll e = 0;\n      while (n % p == 0) n /= p, ++e;\n      ll m =\
    \ len(dp);\n      FOR(i, m) {\n        ll x = dp[i];\n        FOR(j, 1, e + 1)\
    \ x *= p, dp.eb(x);\n      }\n    }\n    return dp;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/array_on_divisors.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: nt/array_on_divisors.hpp
layout: document
redirect_from:
- /library/nt/array_on_divisors.hpp
- /library/nt/array_on_divisors.hpp.html
title: nt/array_on_divisors.hpp
---
