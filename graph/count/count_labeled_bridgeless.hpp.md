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
    - https://atcoder.jp/contests/ttpc2023/tasks/ttpc2023_p
    - https://oeis.org/A095983
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
  code: "#include \"graph/count/count_labeled_connected.hpp\"\n#include \"poly/compositional_inverse.hpp\"\
    \n#include \"poly/composition.hpp\"\n#include \"poly/fps_exp.hpp\"\n#include \"\
    poly/fps_pow.hpp\"\n\n// \u6A4B\u306E\u306A\u3044\u9023\u7D50\u30B0\u30E9\u30D5\
    \n// https://oeis.org/A095983\n// N=1: 1\n// O(Nlog^2N)\n// https://atcoder.jp/contests/ttpc2023/tasks/ttpc2023_p\n\
    template <typename mint>\nvc<mint> count_labeled_bridgeless(int N) {\n  vc<mint>\
    \ C = count_labeled_connected<mint>(N);\n  FOR(i, N + 1) C[i] *= fact_inv<mint>(i);\n\
    \n  vc<mint> D(N + 1);\n  FOR(i, N + 1) D[i] = mint(i) * C[i];\n\n  vc<mint> E\
    \ = fps_exp(D);\n  E.insert(E.begin(), mint(0));\n  E.pop_back();\n\n  // D(x)=B(E(x))\n\
    \  vc<mint> IE = compositional_inverse(E);\n  vc<mint> B = composition(D, IE);\n\
    \n  vc<mint> A(N + 1);\n  FOR(i, 1, N + 1) A[i] = B[i] * inv<mint>(i);\n\n  FOR(i,\
    \ 1, N + 1) A[i] *= fact<mint>(i);\n  return A;\n}\n\n// https://oeis.org/A095983\n\
    // N \u3067\u306E\u5024\u306E\u307F, O(NlogN)\ntemplate <typename mint>\nmint\
    \ count_labeled_bridgeless_single(int N) {\n  if (N == 0) return 0;\n  vc<mint>\
    \ C = count_labeled_connected<mint>(N);\n  FOR(i, N + 1) C[i] *= fact_inv<mint>(i);\n\
    \n  vc<mint> D(N + 1);\n  FOR(i, N + 1) D[i] = mint(i) * C[i];\n\n  vc<mint> E\
    \ = fps_exp(D);\n  E.insert(E.begin(), mint(0));\n  E.pop_back();\n\n  // D(x)=B(E(x))\n\
    \  // [x^N]B(x) \u3092\u6C42\u3081\u305F\u3044\n  // Lagrange Inversion\n  //\
    \ N[x^N]D(IE(x))=[x^{-1}]D'(x)E(x)^{-N}\n  // =[x^{N-1}]D'(x)(E(x)/x)^{-N}\n\n\
    \  E.erase(E.begin());\n  E = fps_pow_1<mint>(E, -N);\n  D = differentiate(D);\n\
    \  mint ANS = 0;\n  FOR(i, N) ANS += D[i] * E[N - 1 - i];\n  ANS *= inv<mint>(N);\n\
    \n  // [x^N]B(x) \u304C\u51FA\u305F\n  ANS *= inv<mint>(N);\n  ANS *= fact<mint>(N);\n\
    \  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_labeled_bridgeless.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_labeled_bridgeless.hpp
layout: document
redirect_from:
- /library/graph/count/count_labeled_bridgeless.hpp
- /library/graph/count/count_labeled_bridgeless.hpp.html
title: graph/count/count_labeled_bridgeless.hpp
---
