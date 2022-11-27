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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/mul.hpp:\
    \ line -1: no such header\n"
  code: "#include \"mod/modint.hpp\"\r\n#include \"nt/discrete_log.hpp\"\r\n#include\
    \ \"alg/group/mul.hpp\"\r\n\r\nint mod_log(int mod, ll a, ll b) {\r\n  a = divmod(a,\
    \ mod).se;\r\n  b = divmod(b, mod).se;\r\n  // \u307E\u305A\u7FA4\u306B\u5E30\u7740\
    \u3059\u308B\u3002\u5C0F\u3055\u3044\u5834\u5408\u306F\u8ABF\u3079\u308B\r\n \
    \ ll p = 1 % mod;\r\n  FOR(k, 32) {\r\n    if (p == b) return k;\r\n    p = p\
    \ * a % mod;\r\n  }\r\n  if (a == 0 || b == 0) return -1;\r\n  ll g = gcd(mod,\
    \ p);\r\n  if (b % g != 0) return -1;\r\n  mod /= g;\r\n  a %= mod, b %= mod;\r\
    \n  if (gcd(b, mod) > 1) return -1;\r\n  // \u7FA4\u306B\u5E30\u7740\u3055\u308C\
    \u305F\r\n  amint::set_mod(mod);\r\n  return discrete_log<Group_Mul<amint>>(\r\
    \n      amint(a), amint(b), [](auto x) { return x.val; }, 32, mod);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/mod_log.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_log.hpp
layout: document
redirect_from:
- /library/mod/mod_log.hpp
- /library/mod/mod_log.hpp.html
title: mod/mod_log.hpp
---
