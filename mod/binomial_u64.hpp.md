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
  bundledCode: "#line 1 \"mod/binomial_u64.hpp\"\n\nstruct Binomial_u64 {\n  int LIM;\n\
    \  vc<u64> fact, ifact, exp;\n  Binomial_u64(int LIM)\n      : LIM(LIM), fact(LIM\
    \ + 1), ifact(LIM + 1), exp(LIM + 1) {\n    fact[0] = 1;\n    for (int i = 1;\
    \ i <= LIM; ++i) {\n      int k = lowbit(i);\n      fact[i] = fact[i - 1] * (i\
    \ >> k);\n      exp[i] = exp[i - 1] + k;\n    }\n    ifact[LIM] = mod_inv_u64(fact[LIM]);\n\
    \    for (u64 i = LIM; i >= 1; --i) {\n      int k = lowbit(i);\n      ifact[i\
    \ - 1] = ifact[i] * (i >> k);\n    }\n  }\n\n  u64 C(int n, int k) {\n    assert(0\
    \ <= n);\n    if (k < 0 || n < k) return 0;\n    int e = exp[n] - exp[k] - exp[n\
    \ - k];\n    u64 x = fact[n] * ifact[k] * ifact[n - k];\n    return x << e;\n\
    \  }\n};\n"
  code: "\nstruct Binomial_u64 {\n  int LIM;\n  vc<u64> fact, ifact, exp;\n  Binomial_u64(int\
    \ LIM)\n      : LIM(LIM), fact(LIM + 1), ifact(LIM + 1), exp(LIM + 1) {\n    fact[0]\
    \ = 1;\n    for (int i = 1; i <= LIM; ++i) {\n      int k = lowbit(i);\n     \
    \ fact[i] = fact[i - 1] * (i >> k);\n      exp[i] = exp[i - 1] + k;\n    }\n \
    \   ifact[LIM] = mod_inv_u64(fact[LIM]);\n    for (u64 i = LIM; i >= 1; --i) {\n\
    \      int k = lowbit(i);\n      ifact[i - 1] = ifact[i] * (i >> k);\n    }\n\
    \  }\n\n  u64 C(int n, int k) {\n    assert(0 <= n);\n    if (k < 0 || n < k)\
    \ return 0;\n    int e = exp[n] - exp[k] - exp[n - k];\n    u64 x = fact[n] *\
    \ ifact[k] * ifact[n - k];\n    return x << e;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mod/binomial_u64.hpp
  requiredBy: []
  timestamp: '2026-09-28 10:13:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/binomial_u64.hpp
layout: document
redirect_from:
- /library/mod/binomial_u64.hpp
- /library/mod/binomial_u64.hpp.html
title: mod/binomial_u64.hpp
---
