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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/powertable.hpp:\
    \ line -1: no such header\n"
  code: "#include \"seq/famous/bernoulli.hpp\"\n\n// 2 \u4EE5\u4E0A N \u4EE5\u4E0B\
    \u306E\u5076\u6570\u306B\u5BFE\u3057\u3066, zeta(n) = c pi^n \u3068\u306A\u308B\
    \ c\n// [0,0,1/6,0,1/90,...]\ntemplate <typename mint>\nvc<mint> riemann_zeta_even(int\
    \ N) {\n  auto B = bernoulli_number<mint>(N);\n  mint pow = inv<mint>(4);\n  FOR(n,\
    \ N + 1) {\n    pow += pow;\n    if (n <= 1 || n & 1) {\n      B[n] = 0;\n   \
    \   continue;\n    }\n    B[n] *= fact_inv<mint>(n);\n    B[n] *= pow;\n    if\
    \ (!(n & 2)) B[n] = -B[n];\n  }\n  return B;\n}\n\n// n-th of [0,0,1/6,0,1/90,...]\n\
    template <typename mint>\nmint single_riemann_zeta_even(int n) {\n  assert(n %\
    \ 2 == 0);\n  mint x = single_bernoulli<mint>(n);\n  x *= mint(2).pow(n);\n  x\
    \ *= fact_inv<mint>(n);\n  if (n % 4 == 0) x = -x;\n  x *= inv<mint>(2);\n  return\
    \ x;\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/riemann_zeta_even.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/famous/riemann_zeta_even.hpp
layout: document
redirect_from:
- /library/seq/famous/riemann_zeta_even.hpp
- /library/seq/famous/riemann_zeta_even.hpp.html
title: seq/famous/riemann_zeta_even.hpp
---
