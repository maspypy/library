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
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/convolution_all.hpp\"\n#include \"poly/fps_log.hpp\"\n#include\
    \ \"poly/sum_of_rationals.hpp\"\n\n// sum_{a in A} a^n \u3092\u3001n = 0, 1, ...,\
    \ N \u3067\u5217\u6319\ntemplate <typename T>\nvc<T> sum_of_powers(const vc<T>&\
    \ A, ll N) {\n  vvc<T> polys;\n  for (auto&& a: A) polys.eb(vc<T>({T(1), -a}));\n\
    \  auto f = convolution_all(polys);\n  f.resize(N + 1);\n  f = fps_log(f);\n \
    \ FOR(i, len(f)) f[i] = -f[i] * T(i);\n  f[0] = len(A);\n  return f;\n}\n\n//\
    \ sum ca^n \u3092 n=0,1,...,N \u3067\u5217\u6319\ntemplate <typename T>\nvc<T>\
    \ sum_of_powers_with_coef(const vc<T>& A, const vc<T>& C, int N) {\n  using P\
    \ = pair<vc<T>, vc<T>>;\n  vc<P> dat;\n  FOR(i, len(A)) { dat.eb(vc<T>({C[i]}),\
    \ vc<T>({1, -A[i]})); }\n  auto [num, den] = sum_of_rationals(dat);\n  num.resize(N\
    \ + 1);\n  den.resize(N + 1);\n  auto f = fps_inv(den);\n  f = convolution(f,\
    \ num);\n  f.resize(N + 1);\n  return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/sum_of_powers.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/sum_of_powers.hpp
layout: document
redirect_from:
- /library/seq/sum_of_powers.hpp
- /library/seq/sum_of_powers.hpp.html
title: seq/sum_of_powers.hpp
---
