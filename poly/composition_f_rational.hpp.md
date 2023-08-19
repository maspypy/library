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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: poly/composition_f_polynomial_1.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/composition_f_polynomial_1.hpp\"\n#include \"poly/fps_pow.hpp\"\
    \n\n// f((a+bx)/(c+dx))\n// only_numerator = true\n//    -> (c+dx)^N f((a+bx)/(c+dx))\
    \ = sum f[i](a+bx)^i(c+dx)^{N-i}\ntemplate <typename mint, bool only_numerator>\n\
    vc<mint> composition_f_rational_1(vc<mint> f, mint a, mint b, mint c, mint d)\
    \ {\n  int N = len(f) - 1;\n\n  if constexpr (!only_numerator) {\n    assert(c\
    \ != mint(0));\n    vc<mint> F = composition_f_rational_1<mint, true>(f, a, b,\
    \ c, d);\n    d /= c;\n    c = c.inverse().pow(N);\n    // c(1+dx)^{-N}\n    vc<mint>\
    \ g = {1, d};\n    g.resize(N + 1);\n    g = fps_pow_1_sparse<mint>(g, -N);\n\
    \    F = convolution(F, g);\n    F.resize(N + 1);\n    FOR(i, N + 1) F[i] *= c;\n\
    \    return F;\n  }\n\n  if (mint(d) == 0) {\n    mint pow_c = 1;\n    FOR_R(i,\
    \ N + 1) f[i] *= pow_c, pow_c *= c;\n    return composition_f_polynomial_1<mint>(f,\
    \ a, b);\n  }\n  // t = c+dx\n  a = (a * d - b * c) / d, b = b / d;\n  // sum\
    \ f[i] (a+bt)^i t^{N-i}\n  f = composition_f_polynomial_1(f, b, a);\n  reverse(all(f));\n\
    \  return composition_f_polynomial_1(f, c, d);\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/composition_f_rational.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/composition_f_rational.hpp
layout: document
redirect_from:
- /library/poly/composition_f_rational.hpp
- /library/poly/composition_f_rational.hpp.html
title: poly/composition_f_rational.hpp
---
