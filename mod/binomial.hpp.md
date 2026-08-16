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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#include \"mod/primitive_root.hpp\"\r\n#include \"mod/mod_inv.hpp\"\r\n\r\
    \nstruct Binomial_PrimePower {\r\n  int p, e;\r\n  int pp;\r\n  int root;\r\n\
    \  int ord;\r\n  vc<int> exp;\r\n  vc<int> log_fact;\r\n  vc<int> power;\r\n \
    \ Barrett bt_p, bt_pp;\r\n\r\n  Binomial_PrimePower(int p, int e) : p(p), e(e),\
    \ power(e + 1, 1) {\r\n    FOR(i, e) power[i + 1] = power[i] * p;\r\n    pp =\
    \ power[e];\r\n    bt_p = Barrett(p), bt_pp = Barrett(pp);\r\n    vc<int> log;\r\
    \n    if (p == 2) {\r\n      if (e <= 1) { return; }\r\n      root = 5;\r\n  \
    \    ord = pp / 4;\r\n      exp.assign(ord, 1);\r\n      log.assign(pp, 0);\r\n\
    \      FOR(i, ord - 1) { exp[i + 1] = (exp[i] * root) & (pp - 1); }\r\n      FOR(i,\
    \ ord) log[exp[i]] = log[pp - exp[i]] = i;\r\n    } else {\r\n      root = primitive_root(p);\r\
    \n      ord = pp / p * (p - 1);\r\n      exp.assign(ord, 1);\r\n      log.assign(pp,\
    \ 0);\r\n      FOR(i, ord - 1) { exp[i + 1] = bt_pp.mul(exp[i], root); }\r\n \
    \     FOR(i, ord) log[exp[i]] = i;\r\n    }\r\n    log_fact.assign(pp, 0);\r\n\
    \    FOR(i, 1, pp) {\r\n      log_fact[i] = log_fact[i - 1] + log[i];\r\n    \
    \  if (log_fact[i] >= ord) log_fact[i] -= ord;\r\n    }\r\n  }\r\n\r\n  int C(ll\
    \ n, ll i) {\r\n    assert(n >= 0);\r\n    if (i < 0 || i > n) return 0;\r\n \
    \   ll a = i, b = n - i;\r\n    if (pp == 2) { return ((a & b) == 0 ? 1 : 0);\
    \ }\r\n    int log = 0, cnt_p = 0, sgn = 0;\r\n    if (e > 1) {\r\n      while\
    \ (n && cnt_p < e) {\r\n        auto [n1, nr1] = bt_pp.divmod(n);\r\n        auto\
    \ [a1, ar1] = bt_pp.divmod(a);\r\n        auto [b1, br1] = bt_pp.divmod(b);\r\n\
    \        log += log_fact[nr1] - log_fact[ar1] - log_fact[br1];\r\n        if (p\
    \ > 2) {\r\n          sgn += (n1 & 1) + (a1 & 1) + (b1 & 1);\r\n        } else\
    \ {\r\n          sgn += (((nr1 + 1) & 4) + ((ar1 + 1) & 4) + ((br1 + 1) & 4))\
    \ / 4;\r\n        }\r\n        n = bt_p.floor(n), a = bt_p.floor(a), b = bt_p.floor(b);\r\
    \n        cnt_p += n - a - b;\r\n      }\r\n    } else {\r\n      while (n &&\
    \ cnt_p < e) {\r\n        auto [n1, nr1] = bt_pp.divmod(n);\r\n        auto [a1,\
    \ ar1] = bt_pp.divmod(a);\r\n        auto [b1, br1] = bt_pp.divmod(b);\r\n   \
    \     log += log_fact[nr1] - log_fact[ar1] - log_fact[br1];\r\n        if (p >\
    \ 2) {\r\n          sgn += (n1 & 1) + (a1 & 1) + (b1 & 1);\r\n        } else {\r\
    \n          sgn += ((nr1 + 1) >> 2 & 1) + ((ar1 + 1) >> 2 & 1)\r\n           \
    \      + ((br1 + 1) >> 2 & 1);\r\n        }\r\n        n = n1, a = a1, b = b1;\r\
    \n        cnt_p += n - a - b;\r\n      }\r\n    }\r\n    if (cnt_p >= e) return\
    \ 0;\r\n    log %= ord;\r\n    if (log < 0) log += ord;\r\n    int res = exp[log];\r\
    \n    if (sgn & 1) res = pp - res;\r\n    return bt_pp.mul(power[cnt_p], res);\r\
    \n  }\r\n};\r\n\r\nstruct Binomial {\r\n  int mod;\r\n  vc<Binomial_PrimePower>\
    \ BPP;\r\n  vc<int> crt_coef;\r\n  Barrett bt;\r\n\r\n  Binomial(int mod) : mod(mod),\
    \ bt(mod) {\r\n    for (auto&& [p, e]: factor(mod)) {\r\n      int pp = 1;\r\n\
    \      FOR(e) pp *= p;\r\n      BPP.eb(Binomial_PrimePower(p, e));\r\n      int\
    \ other = mod / pp;\r\n      crt_coef.eb(ll(other) * mod_inv(other, pp) % mod);\r\
    \n    }\r\n  }\r\n\r\n  int C(ll n, ll k) {\r\n    assert(n >= 0);\r\n    if (k\
    \ < 0 || k > n) return 0;\r\n    int ANS = 0;\r\n    FOR(s, len(crt_coef)) {\r\
    \n      ANS = bt.modulo(ANS + u64(BPP[s].C(n, k)) * crt_coef[s]);\r\n    }\r\n\
    \    return ANS;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: mod/binomial.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/binomial.hpp
layout: document
redirect_from:
- /library/mod/binomial.hpp
- /library/mod/binomial.hpp.html
title: mod/binomial.hpp
---
