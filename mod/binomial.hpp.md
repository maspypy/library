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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/fast_div.hpp:\
    \ line -1: no such header\n"
  code: "#include \"nt/factor.hpp\"\r\n#include \"mod/fast_div.hpp\"\r\nstruct Binomial\
    \ {\r\n  // mod \u3092\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3066\u968E\u4E57\u3092\
    \u524D\u8A08\u7B97 \u2192 \u4E8C\u9805\u4FC2\u6570\u30AF\u30A8\u30EA\r\n  // O(mod)\
    \ \u6642\u9593\u524D\u8A08\u7B97\r\n  int mod;\r\n  vc<pair<ll, int>> pf;\r\n\
    \  vc<int> pp;\r\n  vc<vc<int>> fact;\r\n  vc<int> crt_coef;\r\n\r\n  Binomial(int\
    \ mod) : mod(mod) {\r\n    pf = factor(mod);\r\n    int S = len(pf);\r\n    pp.resize(S);\r\
    \n    fact.resize(S);\r\n    crt_coef.resize(S);\r\n    FOR(s, S) {\r\n      auto\
    \ [p, e] = pf[s];\r\n      pp[s] = 1;\r\n      FOR(e) pp[s] *= p;\r\n      auto&\
    \ F = fact[s];\r\n      // mod pp \u3067\u306E fact \u306E\u5468\u671F\r\n   \
    \   F.resize(pp[s] * 2);\r\n      F[0] = 1;\r\n      fast_div fd_p(p);\r\n   \
    \   fast_div fd_pp(pp[s]);\r\n      FOR(x, 1, len(F)) {\r\n        if (x % fd_p\
    \ == 0)\r\n          F[x] = F[x - 1];\r\n        else\r\n          F[x] = F[x\
    \ - 1] * x % fd_pp;\r\n      }\r\n      int other = mod / fd_pp;\r\n      while\
    \ (crt_coef[s] % fd_pp != 1) crt_coef[s] += other;\r\n    }\r\n  }\r\n\r\n  int\
    \ mod_pow(int a, int n, fast_div d) {\r\n    ll x = 1, p = a;\r\n    while (n)\
    \ {\r\n      if (n & 1) x = x * p % d;\r\n      p = p * p % d;\r\n      n >>=\
    \ 1;\r\n    }\r\n    return x;\r\n  }\r\n\r\n  int C(ll n, ll k) {\r\n    assert(n\
    \ >= 0);\r\n    if (k < 0 || k > n) return 0;\r\n    ll ANS = 0;\r\n    FOR(s,\
    \ len(pf)) {\r\n      int p = pf[s].fi;\r\n      fast_div fd_p(p);\r\n      fast_div\
    \ fd_pp(pp[s]);\r\n      fast_div fd_len(len(fact[s]));\r\n      auto get_fact\
    \ = [&](ll n) -> pi {\r\n        // p^e * x \u3068\u3057\u3066\u3001(e, x mod\
    \ pp) \u3092\u8FD4\u3059\r\n        ll x = 1, e = 0;\r\n        while (n) {\r\n\
    \          x = x * fact[s][n % fd_len] % fd_pp;\r\n          n = n / fd_p;\r\n\
    \          e += n;\r\n        }\r\n        return {e, x};\r\n      };\r\n    \
    \  auto a = get_fact(n);\r\n      auto b = get_fact(k);\r\n      auto c = get_fact(n\
    \ - k);\r\n      ll e = a.fi - b.fi - c.fi;\r\n      ll x = a.se;\r\n      ll\
    \ y = b.se * c.se % fd_pp;\r\n      int phi = pp[s] - pp[s] / pf[s].fi;\r\n  \
    \    x = x * mod_pow(y, phi - 1, fd_pp) % fd_pp;\r\n      FOR(min<int>(e, pf[s].se))\
    \ x *= p;\r\n      x = x % fd_pp;\r\n      ANS += x * crt_coef[s];\r\n    }\r\n\
    \    return ANS % mod;\r\n  }\r\n};\r\n"
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
