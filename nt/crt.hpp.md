---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/187.test.cpp
    title: test/yukicoder/187.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1956.test.cpp
    title: test/yukicoder/1956.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2119.test.cpp
    title: test/yukicoder/2119.test.cpp
  - icon: ':x:'
    path: test/yukicoder/590.test.cpp
    title: test/yukicoder/590.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/crt.hpp\"\n\n// \u975E\u8CA0\u6700\u5C0F\u89E3\u3092\
    \ mod new_mod \u3067\u8FD4\u3059 (garner)\ntemplate <typename T>\ni128 CRT(vc<T>\
    \ vals, vc<T> mods, ll new_mod = -1, bool coprime = false) {\n  int n = len(vals);\n\
    \  FOR(i, n) {\n    vals[i] = ((vals[i] %= mods[i]) >= 0 ? vals[i] : vals[i] +\
    \ mods[i]);\n  }\n  if (!coprime) {\n    auto [basis, pfs] = coprime_factorization<T>(mods);\n\
    \    int k = len(basis);\n    vc<int> max_exp(k);\n    FOR(i, n) {\n      for\
    \ (auto&& [pid, exp]: pfs[i]) { chmax(max_exp[pid], exp); }\n    }\n    vc<T>\
    \ xx(k), mm(k);\n    FOR(i, n) {\n      for (auto&& [pid, exp]: pfs[i]) {\n  \
    \      if (exp == max_exp[pid]) {\n          mm[pid] = 1;\n          FOR(exp)\
    \ mm[pid] *= basis[pid];\n          xx[pid] = vals[i] % mm[pid];\n        }\n\
    \      }\n    }\n    FOR(i, n) {\n      for (auto&& [pid, exp]: pfs[i]) {\n  \
    \      T mod = 1;\n        FOR(exp) mod *= basis[pid];\n        if (xx[pid] %\
    \ mod != vals[i] % mod) return -1;\n      }\n    }\n    swap(vals, xx);\n    swap(mods,\
    \ mm);\n    n = len(vals);\n  }\n\n  vc<ll> cfs(n);\n  FOR(i, n) {\n    ll a =\
    \ vals[i];\n    ll prod = 1;\n    FOR(j, i) {\n      a = (a + i128(cfs[j]) * (mods[i]\
    \ - prod)) % mods[i];\n      prod = i128(prod) * mods[j] % mods[i];\n    }\n \
    \   cfs[i] = mod_inv(prod, mods[i]) * i128(a) % mods[i];\n  }\n  i128 ret = 0,\
    \ prod = 1;\n  FOR(i, n) {\n    ret += prod * cfs[i], prod *= mods[i];\n    if\
    \ (new_mod != -1) { ret %= new_mod, prod %= new_mod; }\n  }\n  return ret;\n}\n"
  code: "\n// \u975E\u8CA0\u6700\u5C0F\u89E3\u3092 mod new_mod \u3067\u8FD4\u3059\
    \ (garner)\ntemplate <typename T>\ni128 CRT(vc<T> vals, vc<T> mods, ll new_mod\
    \ = -1, bool coprime = false) {\n  int n = len(vals);\n  FOR(i, n) {\n    vals[i]\
    \ = ((vals[i] %= mods[i]) >= 0 ? vals[i] : vals[i] + mods[i]);\n  }\n  if (!coprime)\
    \ {\n    auto [basis, pfs] = coprime_factorization<T>(mods);\n    int k = len(basis);\n\
    \    vc<int> max_exp(k);\n    FOR(i, n) {\n      for (auto&& [pid, exp]: pfs[i])\
    \ { chmax(max_exp[pid], exp); }\n    }\n    vc<T> xx(k), mm(k);\n    FOR(i, n)\
    \ {\n      for (auto&& [pid, exp]: pfs[i]) {\n        if (exp == max_exp[pid])\
    \ {\n          mm[pid] = 1;\n          FOR(exp) mm[pid] *= basis[pid];\n     \
    \     xx[pid] = vals[i] % mm[pid];\n        }\n      }\n    }\n    FOR(i, n) {\n\
    \      for (auto&& [pid, exp]: pfs[i]) {\n        T mod = 1;\n        FOR(exp)\
    \ mod *= basis[pid];\n        if (xx[pid] % mod != vals[i] % mod) return -1;\n\
    \      }\n    }\n    swap(vals, xx);\n    swap(mods, mm);\n    n = len(vals);\n\
    \  }\n\n  vc<ll> cfs(n);\n  FOR(i, n) {\n    ll a = vals[i];\n    ll prod = 1;\n\
    \    FOR(j, i) {\n      a = (a + i128(cfs[j]) * (mods[i] - prod)) % mods[i];\n\
    \      prod = i128(prod) * mods[j] % mods[i];\n    }\n    cfs[i] = mod_inv(prod,\
    \ mods[i]) * i128(a) % mods[i];\n  }\n  i128 ret = 0, prod = 1;\n  FOR(i, n) {\n\
    \    ret += prod * cfs[i], prod *= mods[i];\n    if (new_mod != -1) { ret %= new_mod,\
    \ prod %= new_mod; }\n  }\n  return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/crt.hpp
  requiredBy: []
  timestamp: '2023-08-20 12:15:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/187.test.cpp
  - test/yukicoder/2119.test.cpp
  - test/yukicoder/1956.test.cpp
  - test/yukicoder/590.test.cpp
documentation_of: nt/crt.hpp
layout: document
redirect_from:
- /library/nt/crt.hpp
- /library/nt/crt.hpp.html
title: nt/crt.hpp
---
