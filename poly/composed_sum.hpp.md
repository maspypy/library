---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/blog/entry/103136
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 3 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/sum_of_power_of_roots.hpp\"\n#include \"poly/fps_exp.hpp\"\
    \n\n// https://codeforces.com/blog/entry/103136\n// f(x) = prod(1-a_i x), g(x)\
    \ = prod(1-b_j x) \u306E\u3068\u304D\n// prod_{i,j} (1-(a_i+b_j)x) \u3092\u8A08\
    \u7B97\u3059\u308B\u3002\ntemplate <typename mint>\nvc<mint> composed_sum(vc<mint>\
    \ f, vc<mint> g) {\n  int n = len(f) - 1, m = len(g) - 1;\n  vc<mint> A = sum_of_power_of_roots(f,\
    \ n * m);\n  vc<mint> B = sum_of_power_of_roots(g, n * m);\n  FOR(i, n * m + 1)\
    \ A[i] *= fact_inv<mint>(i), B[i] *= fact_inv<mint>(i);\n  A = convolution(A,\
    \ B);\n  A.resize(n * m + 1);\n  FOR(i, n * m + 1) A[i] *= fact<mint>(i);\n  FOR(i,\
    \ len(A)) A[i] = -A[i];\n  A[0] += mint(n * m);\n  // A.erase(A.begin()); -> f'/f\
    \ = (log f)'\n  FOR(i, 1, n * m + 1) A[i] *= inv<mint>(i);\n  return fps_exp(A);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: poly/composed_sum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/composed_sum.hpp
layout: document
redirect_from:
- /library/poly/composed_sum.hpp
- /library/poly/composed_sum.hpp.html
title: poly/composed_sum.hpp
---
