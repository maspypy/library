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
  code: "#pragma once\n#include \"poly/convolution.hpp\"\n\n/*\nquery(i)\uFF1Aa[i],\
    \ b[i] \u3092\u4E0E\u3048\u3066 ab[i] \u3092\u5F97\u308B\u3002\n2^{17}\uFF1A176ms\n\
    2^{18}\uFF1A370ms\n2^{19}\uFF1A800ms\n2^{20}\uFF1A1680ms\n*/\ntemplate <typename\
    \ mint>\nstruct Online_Convolution {\n  const int thresh = 3;\n  vc<mint> f, g,\
    \ h;\n  vc<vc<mint>> fft_f;\n  vc<vc<mint>> fft_g;\n\n  pair<vc<mint>, vc<mint>>\
    \ calc_fft(int k) {\n    // \u73FE\u6642\u70B9\u3067\u306E\u672B\u5C3E 2^k \u9805\
    \u306B\u5BFE\u3059\u308B fft \u30C7\u30FC\u30BF\u3092\u5F97\u308B\n    ll L =\
    \ 1 << k;\n    if (k <= thresh) {\n      vc<mint> f_suff(f.end() - L, f.end());\n\
    \      vc<mint> g_suff(g.end() - L, g.end());\n      return {f_suff, g_suff};\n\
    \    }\n    vc<mint> f_suff(2 * L), g_suff(2 * L);\n    FOR(i, 1 << k) { f_suff[i]\
    \ = f[len(f) - L + i]; }\n    FOR(i, 1 << k) { g_suff[i] = g[len(g) - L + i];\
    \ }\n    if (k <= thresh) return {f_suff, g_suff};\n    ntt(f_suff, 0);\n    ntt(g_suff,\
    \ 0);\n    return {f_suff, g_suff};\n  }\n\n  void calc(int k) {\n    // suffix\
    \ \u306E \u9577\u3055 2^k \u307E\u308F\u308A\u306E\u7573\u307F\u8FBC\u307F\u3092\
    \ h \u306B\u52A0\u7B97\u3059\u308B\n    auto [Ff, Fg] = calc_fft(k);\n    vc<mint>\
    \ Fh(1 << (k + 1));\n    bool square = k >= len(fft_f);\n    if (square) {\n \
    \     // \u9577\u3055 2^k \u306E\u306F\u3058\u3081\u3066\u306E\u584A\u3002\n \
    \     fft_f.eb(Ff);\n      fft_g.eb(Fg);\n    }\n\n    if (k > thresh && square)\
    \ {\n      FOR(i, 1 << (k + 1)) Fh[i] += Ff[i] * Fg[i];\n      ntt(Fh, 1);\n \
    \   }\n    elif (k > thresh && !square) {\n      FOR(i, 1 << (k + 1)) {\n    \
    \    Fh[i] += Ff[i] * fft_g[k][i];\n        Fh[i] += Fg[i] * fft_f[k][i];\n  \
    \    }\n      ntt(Fh, 1);\n    }\n    elif (k <= thresh && square) {\n      FOR(i,\
    \ 1 << k) FOR(j, 1 << k) Fh[i + j] += Ff[i] * Fg[j];\n    }\n    elif (k <= thresh\
    \ && !square) {\n      FOR(i, 1 << k) FOR(j, 1 << k) Fh[i + j] += Ff[i] * fft_g[k][j];\n\
    \      FOR(i, 1 << k) FOR(j, 1 << k) Fh[i + j] += Fg[i] * fft_f[k][j];\n    }\n\
    \    // \u9069\u5207\u306A\u5834\u6240\u306B\u8DB3\u3057\u3053\u3080\n    int\
    \ off = len(f) - 1;\n    FOR(i, len(Fh) - 1) {\n      if (len(h) <= off + i) h.eb(0);\n\
    \      h[off + i] += Fh[i];\n    }\n  }\n\n  mint query(int i, mint f_i, mint\
    \ g_i) {\n    assert(i == len(f));\n    f.eb(f_i);\n    g.eb(g_i);\n    FOR(k,\
    \ 30) {\n      // \u9577\u3055 2^k \u306E\u90E8\u5206\u3092\u51E6\u7406\u3059\u308B\
    \u304B\u3069\u3046\u304B\uFF1F\n      // i+2 \u304C 2^k \u306E\u500D\u6570\u304B\
    \u3064 i+2 >= 2^{k+1}\n      ll L = 1 << k;\n      bool bl = ((i + 2) % L == 0)\
    \ && (i + 2 >= 2 * L);\n      if (!bl) continue;\n      calc(k);\n    }\n    return\
    \ h[i];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: poly/online/online_convolution.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/online/online_convolution.hpp
layout: document
redirect_from:
- /library/poly/online/online_convolution.hpp
- /library/poly/online/online_convolution.hpp.html
title: poly/online/online_convolution.hpp
---
