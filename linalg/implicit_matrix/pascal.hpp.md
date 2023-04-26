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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/convolution.hpp\"\n\n// transpose = 0\uFF1Ag[i] = sum binom(i,j)\
    \ f[j]\n// transpose = 1\uFF1Ag[i] = sum binom(j,i) f[j]\ntemplate <typename mint>\n\
    vc<mint> pascal(vc<mint> f, bool transpose, bool inverse) {\n  if (!transpose)\
    \ {\n    int n = len(f);\n    vc<mint> g(n);\n    FOR(i, n) g[i] = fact_inv<mint>(i);\n\
    \    if (inverse) FOR(i, n) if (i & 1) g[i] = -g[i];\n    FOR(i, n) f[i] *= fact_inv<mint>(i);\n\
    \    f = convolution(f, g);\n    f.resize(n);\n    FOR(i, n) f[i] *= fact<mint>(i);\n\
    \    return f;\n  }\n  int n = len(f);\n  FOR(i, n) f[i] *= fact<mint>(i);\n \
    \ reverse(all(f));\n  vc<mint> g(n);\n  FOR(i, n) g[i] = fact_inv<mint>(i);\n\
    \  if (inverse) FOR(i, n) if (i & 1) g[i] = -g[i];\n  f = convolution(f, g);\n\
    \  f.resize(n);\n  reverse(all(f));\n  FOR(i, n) f[i] *= fact_inv<mint>(i);\n\
    \  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/implicit_matrix/pascal.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/implicit_matrix/pascal.hpp
layout: document
redirect_from:
- /library/linalg/implicit_matrix/pascal.hpp
- /library/linalg/implicit_matrix/pascal.hpp.html
title: linalg/implicit_matrix/pascal.hpp
---
