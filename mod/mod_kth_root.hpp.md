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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/random.hpp:\
    \ line -1: no such header\n"
  code: "#include \"nt/primetest.hpp\"\r\n#include \"mod/primitive_root.hpp\"\r\n\
    #include \"mod/mod_inv.hpp\"\r\n#include \"ds/hashmap.hpp\"\r\n\r\n// mod \u306F\
    \ int\r\nint mod_kth_root(ll k, ll a, int mod) {\r\n  assert(primetest(mod) &&\
    \ 0 <= a && a < mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a ==\
    \ 0) return 0;\r\n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n  fast_div fd(mod);\r\
    \n\r\n  ll g = gcd(k, mod - 1);\r\n  if (mod_pow(a, (mod - 1) / g, mod) != 1)\
    \ return -1;\r\n\r\n  ll c = mod_inv(k / g, (mod - 1) / g);\r\n  a = mod_pow(a,\
    \ c, mod);\r\n  k = (k * c) % (mod - 1);\r\n  if (k == 0) return 1;\r\n\r\n  g\
    \ = primitive_root(mod);\r\n\r\n  auto solve_pp = [&](ll p, int e, ll a) -> ll\
    \ {\r\n    int f = 0;\r\n    ll pf = 1;\r\n    while ((mod - 1) % (pf * p) ==\
    \ 0) ++f, pf *= p;\r\n    ll m = (mod - 1) / pf;\r\n    /*\r\n    \u30FB\u4F4D\
    \u6570 Qm \u306E\u5DE1\u56DE\u7FA4\r\n    \u30FBa \u306E p^e \u4E57\u6839\u3092\
    \u3068\u308A\u305F\u3044\u3002\u6301\u3064\u3053\u3068\u306F\u5206\u304B\u3063\
    \u3066\u3044\u308B\r\n    \u30FBa / x^{p^e} = b \u3092\u7DAD\u6301\u3059\u308B\
    \u3002\u307E\u305A\u306F\u3001b \u304C p \u3067\u5272\u308C\u308B\u56DE\u6570\u3092\
    \u5897\u3084\u3057\u3066\u3044\u304F\u3002\r\n    */\r\n    ll x = 1, b = a, c\
    \ = f - e; // b ^ {mp^c} = 1\r\n    int pc = 1;\r\n    FOR(c) pc *= p;\r\n   \
    \ int pe = 1;\r\n    FOR(e) pe *= p;\r\n    // \u5FC5\u8981\u306A\u3089\u3070\u539F\
    \u59CB p \u4E57\u6839\u306B\u95A2\u3059\u308B\u96E2\u6563\u5BFE\u6570\u554F\u984C\
    \u306E\u30BB\u30C3\u30C8\u30A2\u30C3\u30D7\r\n    ll G = mod_pow(g, (mod - 1)\
    \ / p, mod);\r\n    int M = 0;\r\n    unordered_map<ll, int> MP;\r\n    ll GM_inv\
    \ = -1;\r\n    if (c) {\r\n      while (M * M < p) ++M;\r\n      MP.reserve(M\
    \ + 1);\r\n      ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow] = m;\r\n\
    \        Gpow = Gpow * G % fd;\r\n      }\r\n      GM_inv = mod_pow(Gpow, mod\
    \ - 2, mod);\r\n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c} = 1\
    \ \u304C\u5206\u304B\u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}} = 1\
    \ \u306B\u3057\u305F\u3044\u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\u3066\
    \u63A2\u3059\u3002\u539F\u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B B\
    \ = G^k \u306B\u5E30\u7740\u3002\r\n      */\r\n      ll B = mod_pow(b, m * pc\
    \ / p, mod);\r\n      int k = [&](ll B) -> int {\r\n        FOR(m, M + 1) {\r\n\
    \          if (MP.count(B)) return m * M + MP[B];\r\n          B = B * GM_inv\
    \ % fd;\r\n        }\r\n        return -1;\r\n      }(B);\r\n      x = x * mod_pow(g,\
    \ pf / pc / pe * k, mod) % fd;\r\n      ll exp = pf / pc * k % (mod - 1);\r\n\
    \      b = b * mod_pow(g, mod - 1 - exp, mod) % fd;\r\n      --c;\r\n      pc\
    \ /= p;\r\n    }\r\n    int k = pe - mod_inv(m, pe);\r\n    k = (k * m + 1) /\
    \ pe;\r\n    ll y = mod_pow(b, k, mod);\r\n    x = x * y % fd;\r\n    return x;\r\
    \n  };\r\n\r\n  auto pf = factor(k);\r\n  for (auto&& [p, e]: pf) a = solve_pp(p,\
    \ e, a);\r\n  return a;\r\n}\r\n\r\nll mod_kth_root_long(ll k, ll a, ll mod) {\r\
    \n  static HashMapLL<ll, 20> MP;\r\n\r\n  assert(primetest(mod) && 0 <= a && a\
    \ < mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a == 0) return 0;\r\
    \n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n\r\n  ll g = gcd(k, mod - 1);\r\
    \n  if (mod_pow_long(a, (mod - 1) / g, mod) != 1) return -1;\r\n\r\n  ll c = mod_inv(k\
    \ / g, (mod - 1) / g);\r\n  a = mod_pow_long(a, c, mod);\r\n  k = i128(k) * c\
    \ % (mod - 1);\r\n  if (k == 0) return 1;\r\n\r\n  g = primitive_root_long(mod);\r\
    \n\r\n  auto solve_pp = [&](ll p, ll e, ll a) -> ll {\r\n    ll f = 0;\r\n   \
    \ ll pf = 1;\r\n    while (((mod - 1) / pf) % p == 0) ++f, pf *= p;\r\n    ll\
    \ m = (mod - 1) / pf;\r\n    /*\r\n    \u30FB\u4F4D\u6570 Qm \u306E\u5DE1\u56DE\
    \u7FA4\r\n    \u30FBa \u306E p^e \u4E57\u6839\u3092\u3068\u308A\u305F\u3044\u3002\
    \u6301\u3064\u3053\u3068\u306F\u5206\u304B\u3063\u3066\u3044\u308B\r\n    \u30FB\
    a / x^{p^e} = b \u3092\u7DAD\u6301\u3059\u308B\u3002\u307E\u305A\u306F\u3001b\
    \ \u304C p \u3067\u5272\u308C\u308B\u56DE\u6570\u3092\u5897\u3084\u3057\u3066\u3044\
    \u304F\u3002\r\n    */\r\n    ll x = 1, b = a, c = f - e; // b ^ {mp^c} = 1\r\n\
    \    ll pc = 1;\r\n    FOR(c) pc *= p;\r\n    ll pe = 1;\r\n    FOR(e) pe *= p;\r\
    \n    // \u5FC5\u8981\u306A\u3089\u3070\u539F\u59CB p \u4E57\u6839\u306B\u95A2\
    \u3059\u308B\u96E2\u6563\u5BFE\u6570\u554F\u984C\u306E\u30BB\u30C3\u30C8\u30A2\
    \u30C3\u30D7\r\n    ll G = mod_pow_long(g, (mod - 1) / p, mod);\r\n    ll M =\
    \ 0;\r\n    ll GM_inv = -1;\r\n    if (c) {\r\n      while (M * M < p) ++M;\r\n\
    \      MP.reset();\r\n      ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow]\
    \ = m;\r\n        Gpow = i128(Gpow) * G % mod;\r\n      }\r\n      GM_inv = mod_pow_long(Gpow,\
    \ mod - 2, mod);\r\n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c}\
    \ = 1 \u304C\u5206\u304B\u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}}\
    \ = 1 \u306B\u3057\u305F\u3044\u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\
    \u3066\u63A2\u3059\u3002\u539F\u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B\
    \ B = G^k \u306B\u5E30\u7740\u3002\r\n      */\r\n      ll B = mod_pow_long(b,\
    \ pc / p * m, mod);\r\n      ll k = [&](ll B) -> ll {\r\n        FOR(m, M + 1)\
    \ {\r\n          if (MP.count(B)) return m * M + MP[B];\r\n          B = i128(B)\
    \ * GM_inv % mod;\r\n        }\r\n        return -1;\r\n      }(B);\r\n      x\
    \ = i128(x) * mod_pow_long(g, pf / pc / pe * k, mod) % mod;\r\n\r\n      ll exp\
    \ = pf / pc * i128(k) % (mod - 1);\r\n      b = i128(b) * mod_pow_long(g, mod\
    \ - 1 - exp, mod) % mod;\r\n      --c;\r\n      pc /= p;\r\n    }\r\n    ll k\
    \ = pe - mod_inv(m, pe);\r\n    k = (i128(k) * m + 1) / pe;\r\n    ll y = mod_pow_long(b,\
    \ k, mod);\r\n    x = i128(x) * y % mod;\r\n    return x;\r\n  };\r\n\r\n  auto\
    \ pf = factor(k);\r\n  for (auto&& [p, e]: pf) a = solve_pp(p, e, a);\r\n  return\
    \ a;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/mod_kth_root.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_kth_root.hpp
layout: document
redirect_from:
- /library/mod/mod_kth_root.hpp
- /library/mod/mod_kth_root.hpp.html
title: mod/mod_kth_root.hpp
---
