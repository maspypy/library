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
    - https://oeis.org/A013922
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.5/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: poly/compositional.hpp:\
    \ line -1: no such header\n"
  code: "#include \"graph/count/count_labeled_connected.hpp\"\n#include \"poly/compositional_inverse.hpp\"\
    \n#include \"poly/compositional.hpp\"\n#include \"poly/integrate.hpp\"\n#include\
    \ \"poly/fps_pow.hpp\"\n\n// https://oeis.org/A013922\ntemplate <typename mint>\n\
    vc<mint> count_labeled_biconnected(int N) {\n  vc<mint> C = count_labeled_connected<mint>(N);\n\
    \  FOR(i, N + 1) C[i] *= fact_inv<mint>(i);\n\n  vc<mint> D(N);\n  FOR(i, N) D[i]\
    \ = C[i + 1] * mint(i + 1);\n\n  vc<mint> E(N);\n  FOR(i, N) E[i] = C[i] * mint(i);\n\
    \n  vc<mint> G = fps_log(D);\n\n  vc<mint> IE = compositional_inverse(E);\n  vc<mint>\
    \ B = composition(G, IE);\n  vc<mint> A = integrate(B);\n\n  FOR(i, N + 1) A[i]\
    \ *= fact<mint>(i);\n  return A;\n}\n\n// https://oeis.org/A013922\ntemplate <typename\
    \ mint>\nmint count_labeled_biconnected_single(int N) {\n  if (N < 2) return 0;\n\
    \  vc<mint> C = count_labeled_connected<mint>(N);\n  FOR(i, N + 1) C[i] *= fact_inv<mint>(i);\n\
    \n  vc<mint> D(N);\n  FOR(i, N) D[i] = C[i + 1] * mint(i + 1);\n\n  vc<mint> E(N);\n\
    \  FOR(i, N) E[i] = C[i] * mint(i);\n\n  vc<mint> G = fps_log(D);\n\n  // (N-1)[x^{N-1}]G(IE(x))=[x^{-1}]G'(x)E(x)^{-(N-1)}\n\
    \  // =[x^{N-2}]G'(x)(E(x)/x)^{-(N-1)}\n  G = differentiate(G);\n  E.erase(E.begin());\n\
    \  E = fps_pow_1<mint>(E, -(N - 1));\n  mint ANS = 0;\n  FOR(i, N - 1) ANS +=\
    \ G[i] * E[N - 2 - i];\n\n  ANS *= inv<mint>(N - 1);\n  ANS *= inv<mint>(N);\n\
    \  ANS *= fact<mint>(N);\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_labeled_biconnected.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_labeled_biconnected.hpp
layout: document
redirect_from:
- /library/graph/count/count_labeled_biconnected.hpp
- /library/graph/count/count_labeled_biconnected.hpp.html
title: graph/count/count_labeled_biconnected.hpp
---
