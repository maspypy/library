---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barret.hpp
    title: mod/barret.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':x:'
    path: poly/convolution_all.hpp
    title: poly/convolution_all.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':x:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':x:'
    path: poly/fps_log.hpp
    title: poly/fps_log.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':x:'
    path: poly/sum_of_rationals.hpp
    title: poly/sum_of_rationals.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1145.test.cpp
    title: test/yukicoder/1145.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
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
  dependsOn:
  - poly/convolution_all.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  - poly/fps_log.hpp
  - poly/fps_inv.hpp
  - poly/count_terms.hpp
  - poly/sum_of_rationals.hpp
  isVerificationFile: false
  path: seq/sum_of_powers.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1145.test.cpp
documentation_of: seq/sum_of_powers.hpp
layout: document
redirect_from:
- /library/seq/sum_of_powers.hpp
- /library/seq/sum_of_powers.hpp.html
title: seq/sum_of_powers.hpp
---
