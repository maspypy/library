---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':heavy_check_mark:'
    path: nt/coprime_factorization.hpp
    title: nt/coprime_factorization.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/187.test.cpp
    title: test/yukicoder/187.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1956.test.cpp
    title: test/yukicoder/1956.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2119.test.cpp
    title: test/yukicoder/2119.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/590.test.cpp
    title: test/yukicoder/590.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/mod_inv.hpp\"\n// long \u3067\u3082\u5927\u4E08\u592B\
    \r\n// (val * x - 1) \u304C mod \u306E\u500D\u6570\u306B\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308B\r\n// \u7279\u306B mod=0 \u306A\u3089 x=0 \u304C\u6E80\u305F\
    \u3059\r\nll mod_inv(ll val, ll mod) {\r\n  if (mod == 0) return 0;\r\n  mod =\
    \ abs(mod);\r\n  val %= mod;\r\n  if (val < 0) val += mod;\r\n  ll a = val, b\
    \ = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a\
    \ -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u += mod;\r\n  return\
    \ u;\r\n}\r\n#line 1 \"nt/coprime_factorization.hpp\"\n\n/*\n\u4E92\u3044\u306B\
    \u7D20\u306A\u6574\u6570 p1, p2, ..., pk \u3092\u7528\u3044\u3066 n_i = prod p_i^e_i\
    \ \u3068\u8868\u3059.\n[21,60,140,400]\n[3,7,20], [[(0,1),(1,1)],[(0,1),(2,1)],[(1,1),(2,1)],[(2,2)]]\n\
    */\ntemplate <typename T>\npair<vc<T>, vvc<pair<int, int>>> coprime_factorization(vc<T>\
    \ nums) {\n  vc<T> basis;\n  for (T val: nums) {\n    vc<T> new_basis;\n    for\
    \ (T x: basis) {\n      if (val == 1) {\n        new_basis.eb(x);\n        continue;\n\
    \      }\n      vc<T> dat = {val, x};\n      FOR(p, 1, len(dat)) {\n        FOR(i,\
    \ p) {\n          while (1) {\n            if (dat[p] > 1 && dat[i] % dat[p] ==\
    \ 0) dat[i] /= dat[p];\n            elif (dat[i] > 1 && dat[p] % dat[i] == 0)\
    \ dat[p] /= dat[i];\n            else break;\n          }\n          T g = gcd(dat[i],\
    \ dat[p]);\n          if (g == 1 || g == dat[i] || g == dat[p]) continue;\n  \
    \        dat[i] /= g, dat[p] /= g, dat.eb(g);\n        }\n      }\n      val =\
    \ dat[0];\n      FOR(i, 1, len(dat)) if (dat[i] != 1) new_basis.eb(dat[i]);\n\
    \    }\n    if (val > 1) new_basis.eb(val);\n    swap(basis, new_basis);\n  }\n\
    \n  sort(all(basis));\n\n  vvc<pair<int, int>> res(len(nums));\n  FOR(i, len(nums))\
    \ {\n    T x = nums[i];\n    FOR(j, len(basis)) {\n      int e = 0;\n      while\
    \ (x % basis[j] == 0) x /= basis[j], ++e;\n      if (e) res[i].eb(j, e);\n   \
    \ }\n  }\n  return {basis, res};\n}\n#line 3 \"nt/crt.hpp\"\n\n// \u975E\u8CA0\
    \u6700\u5C0F\u89E3\u3092 mod new_mod \u3067\u8FD4\u3059 (garner)\ntemplate <typename\
    \ T>\ni128 CRT(vc<T> vals, vc<T> mods, ll new_mod = -1, bool coprime = false)\
    \ {\n  int n = len(vals);\n  FOR(i, n) {\n    vals[i] = ((vals[i] %= mods[i])\
    \ >= 0 ? vals[i] : vals[i] + mods[i]);\n  }\n  if (!coprime) {\n    auto [basis,\
    \ pfs] = coprime_factorization<T>(mods);\n    int k = len(basis);\n    vc<int>\
    \ max_exp(k);\n    FOR(i, n) {\n      for (auto&& [pid, exp]: pfs[i]) { chmax(max_exp[pid],\
    \ exp); }\n    }\n    vc<T> xx(k), mm(k);\n    FOR(i, n) {\n      for (auto&&\
    \ [pid, exp]: pfs[i]) {\n        if (exp == max_exp[pid]) {\n          mm[pid]\
    \ = 1;\n          FOR(exp) mm[pid] *= basis[pid];\n          xx[pid] = vals[i]\
    \ % mm[pid];\n        }\n      }\n    }\n    FOR(i, n) {\n      for (auto&& [pid,\
    \ exp]: pfs[i]) {\n        T mod = 1;\n        FOR(exp) mod *= basis[pid];\n \
    \       if (xx[pid] % mod != vals[i] % mod) return -1;\n      }\n    }\n    swap(vals,\
    \ xx);\n    swap(mods, mm);\n    n = len(vals);\n  }\n\n  vc<ll> cfs(n);\n  FOR(i,\
    \ n) {\n    ll a = vals[i];\n    ll prod = 1;\n    FOR(j, i) {\n      a = (a +\
    \ i128(cfs[j]) * (mods[i] - prod)) % mods[i];\n      prod = i128(prod) * mods[j]\
    \ % mods[i];\n    }\n    cfs[i] = mod_inv(prod, mods[i]) * i128(a) % mods[i];\n\
    \  }\n  i128 ret = 0, prod = 1;\n  FOR(i, n) {\n    ret += prod * cfs[i], prod\
    \ *= mods[i];\n    if (new_mod != -1) { ret %= new_mod, prod %= new_mod; }\n \
    \ }\n  return ret;\n}\n"
  code: "#include \"mod/mod_inv.hpp\"\n#include \"nt/coprime_factorization.hpp\"\n\
    \n// \u975E\u8CA0\u6700\u5C0F\u89E3\u3092 mod new_mod \u3067\u8FD4\u3059 (garner)\n\
    template <typename T>\ni128 CRT(vc<T> vals, vc<T> mods, ll new_mod = -1, bool\
    \ coprime = false) {\n  int n = len(vals);\n  FOR(i, n) {\n    vals[i] = ((vals[i]\
    \ %= mods[i]) >= 0 ? vals[i] : vals[i] + mods[i]);\n  }\n  if (!coprime) {\n \
    \   auto [basis, pfs] = coprime_factorization<T>(mods);\n    int k = len(basis);\n\
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
  dependsOn:
  - mod/mod_inv.hpp
  - nt/coprime_factorization.hpp
  isVerificationFile: false
  path: nt/crt.hpp
  requiredBy: []
  timestamp: '2023-08-20 12:53:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2119.test.cpp
  - test/yukicoder/1956.test.cpp
  - test/yukicoder/187.test.cpp
  - test/yukicoder/590.test.cpp
documentation_of: nt/crt.hpp
layout: document
redirect_from:
- /library/nt/crt.hpp
- /library/nt/crt.hpp.html
title: nt/crt.hpp
---
