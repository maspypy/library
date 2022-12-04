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
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/swag.hpp: line\
    \ -1: no such header\n"
  code: "#pragma once\n\n#include \"seq/kth_term_of_p_recursive.hpp\"\n\n// \u5BFE\
    \u6570\u5FAE\u5206 F'/F = a(x)/b(x) \u304B\u3089 F \u3092\u5FA9\u5143\u3059\u308B\
    \u3002\n// a, b \u304C sparse \u3067\u3042\u308C\u3070\u3001O(N(K1+K2)) \u6642\
    \u9593\u3067\u3067\u304D\u308B\ntemplate <typename mint>\nvc<mint> from_log_differentiation(int\
    \ N, const vc<mint>& a, const vc<mint>& b) {\n  assert(b[0] == mint(1));\n  using\
    \ P = pair<int, mint>;\n\n  vc<P> dat_a, dat_b;\n  FOR(i, len(a)) if (a[i] !=\
    \ mint(0)) dat_a.eb(i, a[i]);\n  FOR(i, 1, len(b)) if (b[i] != mint(0)) dat_b.eb(i,\
    \ b[i]);\n\n  vc<mint> f(N + 1);\n  vc<mint> df(N);\n  f[0] = mint(1);\n  FOR(n,\
    \ N) {\n    mint v = 0;\n    for (auto&& [i, bi]: dat_b) {\n      if (i > n) break;\n\
    \      v -= bi * df[n - i];\n    }\n    for (auto&& [i, ai]: dat_a) {\n      if\
    \ (i > n) break;\n      v += ai * f[n - i];\n    }\n    df[n] = v;\n    f[n +\
    \ 1] = df[n] * inv<mint>(n + 1);\n  }\n  return f;\n}\n\n// F'/F = a/b \u306E\u89E3\
    \u306E\u3001[x^K]F \u3092\u6C42\u3081\u308B\u3002\u53F3\u8FBA\u306F\u4F4E\u6B21\
    \u306E\u6709\u7406\u5F0F\u3002\ntemplate <typename mint>\nmint from_log_differentiation_kth(int\
    \ K, vc<mint>& a, vc<mint>& b) {\n  assert(b[0] == mint(1));\n  int r = max(len(a),\
    \ len(b) - 1);\n  vvc<mint> c(r + 1);\n  FOR(i, r + 1) {\n    mint c0 = 0, c1\
    \ = 0;\n    if (i < len(b)) c0 += mint(r - i) * b[i];\n    if (i < len(b)) c1\
    \ += b[i];\n    if (0 <= i - 1 && i - 1 < len(b)) c0 -= a[i - 1];\n    c[i] =\
    \ {c0, c1};\n  }\n  auto f = from_log_differentiation(r - 1, a, b);\n  mint ANS\
    \ = kth_term_of_p_recursive(f, c, K);\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/from_log_differentiation.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/from_log_differentiation.hpp
layout: document
redirect_from:
- /library/poly/from_log_differentiation.hpp
- /library/poly/from_log_differentiation.hpp.html
title: poly/from_log_differentiation.hpp
---
