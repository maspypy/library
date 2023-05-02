---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/all_inverse.hpp
    title: mod/all_inverse.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/all_inverse.hpp\"\ntemplate <typename mint>\nvc<mint>\
    \ all_inverse(vc<mint>& X) {\n  for (auto&& x: X) assert(x != mint(0));\n  int\
    \ N = len(X);\n  vc<mint> res(N + 1);\n  res[0] = mint(1);\n  FOR(i, N) res[i\
    \ + 1] = res[i] * X[i];\n  mint t = res.back().inverse();\n  res.pop_back();\n\
    \  FOR_R(i, N) {\n    res[i] *= t;\n    t *= X[i];\n  }\n  return res;\n}\n#line\
    \ 2 \"mod/q_analogue.hpp\"\n\ntemplate <typename mint>\nstruct q_Analogue {\n\
    \  const mint q;\n  const int LIM;\n  int D;\n  vc<mint> factorial, ifactorial;\n\
    \n  q_Analogue(mint q, int LIM) : q(q), LIM(LIM) {\n    assert(LIM < mint::get_mod());\n\
    \    build();\n  }\n\n  void build() {\n    factorial.reserve(LIM + 1);\n    factorial.eb(1);\n\
    \    mint x = 1;\n    FOR(i, 1, LIM + 1) {\n      if (x == mint(0)) break;\n \
    \     factorial.eb(factorial.back() * x);\n      x = q * x + mint(1);\n    }\n\
    \    ifactorial = all_inverse(factorial);\n    D = len(factorial);\n  }\n\n  mint\
    \ fact(int N) {\n    assert(0 <= N && N <= LIM);\n    return (N < D ? factorial[N]\
    \ : mint(0));\n  }\n  mint fact_inv(int N) {\n    assert(0 <= N && N < D);\n \
    \   return (N < D ? ifactorial[N] : mint(0));\n  }\n  mint binom(int N, int K)\
    \ {\n    assert(0 <= N && N <= LIM);\n    if (K < 0 || K > N) return mint(0);\n\
    \    if (N < D) return factorial[N] * ifactorial[K] * ifactorial[N - K];\n   \
    \ auto [n1, n2] = divmod(N, D);\n    auto [k1, k2] = divmod(K, D);\n    return\
    \ C<mint>(n1, k1) * binom(n2, k2);\n  }\n};\n"
  code: "#include \"mod/all_inverse.hpp\"\n\ntemplate <typename mint>\nstruct q_Analogue\
    \ {\n  const mint q;\n  const int LIM;\n  int D;\n  vc<mint> factorial, ifactorial;\n\
    \n  q_Analogue(mint q, int LIM) : q(q), LIM(LIM) {\n    assert(LIM < mint::get_mod());\n\
    \    build();\n  }\n\n  void build() {\n    factorial.reserve(LIM + 1);\n    factorial.eb(1);\n\
    \    mint x = 1;\n    FOR(i, 1, LIM + 1) {\n      if (x == mint(0)) break;\n \
    \     factorial.eb(factorial.back() * x);\n      x = q * x + mint(1);\n    }\n\
    \    ifactorial = all_inverse(factorial);\n    D = len(factorial);\n  }\n\n  mint\
    \ fact(int N) {\n    assert(0 <= N && N <= LIM);\n    return (N < D ? factorial[N]\
    \ : mint(0));\n  }\n  mint fact_inv(int N) {\n    assert(0 <= N && N < D);\n \
    \   return (N < D ? ifactorial[N] : mint(0));\n  }\n  mint binom(int N, int K)\
    \ {\n    assert(0 <= N && N <= LIM);\n    if (K < 0 || K > N) return mint(0);\n\
    \    if (N < D) return factorial[N] * ifactorial[K] * ifactorial[N - K];\n   \
    \ auto [n1, n2] = divmod(N, D);\n    auto [k1, k2] = divmod(K, D);\n    return\
    \ C<mint>(n1, k1) * binom(n2, k2);\n  }\n};\n"
  dependsOn:
  - mod/all_inverse.hpp
  isVerificationFile: false
  path: mod/q_analogue.hpp
  requiredBy: []
  timestamp: '2023-05-02 23:43:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/q_analogue.hpp
layout: document
redirect_from:
- /library/mod/q_analogue.hpp
- /library/mod/q_analogue.hpp.html
title: mod/q_analogue.hpp
---
