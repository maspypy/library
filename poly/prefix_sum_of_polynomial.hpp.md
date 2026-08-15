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
  code: "#include \"seq/famous/bernoulli.hpp\"\n\n// f: polynomial.\n// sum_{k in\
    \ [0,n)}f(k)=g(n) \u3068\u306A\u308B g \u3092\u8FD4\u3059\ntemplate <typename\
    \ mint>\nvc<mint> prefix_sum_of_polynomial(vc<mint> f, bool include_right_end)\
    \ {\n  if (!include_right_end) {\n    auto F = prefix_sum_of_polynomial(f, true);\n\
    \    FOR(i, len(f)) F[i] -= f[i];\n    return F;\n  }\n  if (f.empty()) return\
    \ {0};\n  if (len(f) == 1) return {f[0], f[0]};\n  static vc<mint> B = {1};\n\
    \  ll d = len(f) - 1;\n  if (d >= len(B)) {\n    ll n = max(d, len(B) * 2);\n\
    \    B = bernoulli_number<mint>(n);\n    B[1] = inv<mint>(2);\n  }\n  FOR(i, d\
    \ + 1) f[i] *= fact<mint>(i);\n  vc<mint> b(d + 1);\n  FOR(i, d + 1) b[d - i]\
    \ = B[i] * fact_inv<mint>(i);\n  vc<mint> F = convolution<mint>(f, b);\n  F =\
    \ {F.begin() + d - 1, F.end()};\n  F[0] = f[0];\n  FOR(i, len(F)) F[i] *= fact_inv<mint>(i);\n\
    \  return F;\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/prefix_sum_of_polynomial.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/prefix_sum_of_polynomial.hpp
layout: document
redirect_from:
- /library/poly/prefix_sum_of_polynomial.hpp
- /library/poly/prefix_sum_of_polynomial.hpp.html
title: poly/prefix_sum_of_polynomial.hpp
---
