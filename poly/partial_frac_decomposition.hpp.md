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
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/multipoint.hpp\"\n// O(Nlog^2N)\n// \u5206\u6BCD\u306F\u76F8\
    \u7570\u306A\u308B 1 \u6B21\u5F0F\u306E\u7A4D\u9650\u5B9A\u3068\u3059\u308B\n\
    // f / prod(ax+b) = sum c/(ax+b) \u3068\u3044\u3046 C \u3092\u8FD4\u3059\ntemplate\
    \ <typename mint>\nvc<mint> partial_frac_decomposition(vc<mint> f, vc<mint> A)\
    \ {\n  assert(len(f) <= len(A));\n  if (len(f) == 0) return vc<mint>(len(A));\n\
    \  SubproductTree<mint> X(A);\n  vc<mint> g = X.T[1]; // prod(1-ax)\n  g.resize(len(A)\
    \ + 1);\n  reverse(all(g));\n  FOR(i, len(g) - 1) g[i] = g[i + 1] * mint(i + 1);\n\
    \  g.pop_back();\n\n  auto num = X.evaluation(f);\n  auto den = X.evaluation(g);\n\
    \  vc<mint> B(len(A));\n  FOR(i, len(A)) B[i] = num[i] / den[i];\n  return B;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/partial_frac_decomposition.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/partial_frac_decomposition.hpp
layout: document
redirect_from:
- /library/poly/partial_frac_decomposition.hpp
- /library/poly/partial_frac_decomposition.hpp.html
title: poly/partial_frac_decomposition.hpp
---
