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
    - https://yukicoder.me/problems/no/3621
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/composition.hpp\"\n#include \"poly/compositional_inverse.hpp\"\
    \n#include \"poly/fps_div.hpp\"\n\n// 0=[x^0]F, a=[x^1]F\n// [2,N) \u3067 a^i\
    \ != a\n// \u3053\u306E\u3068\u304D G, H \u306F\u4E92\u3044\u306B\u5408\u6210\u9006\
    \u3067\n// G(F(x))=aG(x), F(H(x))=H(ax)\n// https://yukicoder.me/problems/no/3621\n\
    template <typename mint>\nstruct Schroder {\n  int N;\n  vc<mint> F, G, H;\n \
    \ mint a;\n  vc<mint> pw;\n  Schroder(vc<mint> &F) : F(F) {\n    N = len(F);\n\
    \    a = (N <= 1 ? 1 : F[1]);\n    pw.resize(N + 1, 1);\n    FOR(i, N) pw[i +\
    \ 1] = pw[i] * a;\n    H.resize(2);\n    H[1] = 1;\n    while (len(H) < N) {\n\
    \      int m = len(H);\n      int M = min<int>(2 * m - 1, N);\n      H.resize(M);\n\
    \      vc<mint> f(M);\n      FOR(i, M) f[i] = F[i];\n      vc<mint> E = composition(f,\
    \ H);\n      E = {E.begin() + m, E.begin() + M};\n      vc<mint> den(M - m);\n\
    \      FOR(i, M - m) den[i] = H[i + 1] * pw[i] * (i + 1);\n      E = fps_div<mint>(E,\
    \ den);\n      FOR(i, M - m) E[i] /= pw[m + i] - a;\n      vc<mint> DH(M - m);\n\
    \      FOR(i, M - m) { DH[i] = H[i + 1] * (i + 1); }\n      E = convolution<mint>(E,\
    \ DH);\n      E.resize(M - m);\n      FOR(i, M - m) H[m + i] = E[i];\n    }\n\
    \    SHOW(H);\n    H.resize(N);\n    G = compositional_inverse(H);\n  }\n\n  //\
    \ F \u306E K \u56DE\u5408\u6210\n  vc<mint> iterated_composition(ll K) {\n   \
    \ mint c = a.pow(K);\n    vc<mint> g(N);\n    FOR(i, N) g[i] = G[i] * c;\n   \
    \ return composition(H, g);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: poly/schroder.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/schroder.hpp
layout: document
redirect_from:
- /library/poly/schroder.hpp
- /library/poly/schroder.hpp.html
title: poly/schroder.hpp
---
