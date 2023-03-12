---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/2206.test.cpp
    title: test/yukicoder/2206.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/prefix_sum_of_binom.hpp\"\ntemplate <typename mint>\n\
    struct Prefix_Sum_Of_Binom {\n  static constexpr int mod = mint::get_mod();\n\
    \  const int MAX_N;\n  const int B;\n  vc<mint> POW;\n  vvc<mint> dat;\n\n  Prefix_Sum_Of_Binom(int\
    \ MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N + 1)) {\n    POW.resize(MAX_N + 1, mint(1));\n\
    \    FOR(i, MAX_N) POW[i + 1] = POW[i] + POW[i];\n    int K = ceil(MAX_N, B +\
    \ B) + 2;\n    dat.resize(K);\n    FOR(k, 0, K) {\n      // [0, kB] \u3067\u306E\
    \ closed sum\n      vc<mint>& f = dat[k];\n      f.resize(MAX_N + 1 - k * B);\n\
    \      int m = k * B;\n      f[0] = POW[m] * fact<mint>(m);\n      FOR(i, MAX_N\
    \ - m) {\n        f[i + 1] = f[i] + f[i] - fact<mint>(i + m) * fact_inv<mint>(i);\n\
    \      }\n    }\n  }\n\n  // \\sum_{k=0}^m binom(n,k)\n  mint query(int n, int\
    \ m) {\n    assert(0 <= m && m <= n + 1);\n    if (m == 0) return mint(0);\n \
    \   if (m + m > n + 1) return POW[n] - query(n, n + 1 - m);\n    --m;\n    int\
    \ a = m / B;\n    if (m <= a * B + B / 2) {\n      ll t = 0;\n      FOR(i, a *\
    \ B + 1, m + 1) {\n        t += ll(fact_inv<mint>(i).val)\n             * (fact_inv<mint>(n\
    \ - i).val + (t <= 0 ? 0 : -mod));\n      }\n      return get(n, a) + mint(t)\
    \ * fact<mint>(n);\n    } else {\n      ll t = 0;\n      FOR(i, m + 1, (a + 1)\
    \ * B + 1) {\n        t += ll(fact_inv<mint>(i).val)\n             * (fact_inv<mint>(n\
    \ - i).val + (t <= 0 ? 0 : -mod));\n      }\n      return get(n, a + 1) - mint(t)\
    \ * fact<mint>(n);\n    }\n    return 0;\n  }\n\n  mint get(int n, int k) {\n\
    \    if (n <= k * B) return POW[n];\n    return dat[k][n - k * B] * fact_inv<mint>(k\
    \ * B);\n  }\n};\n"
  code: "template <typename mint>\nstruct Prefix_Sum_Of_Binom {\n  static constexpr\
    \ int mod = mint::get_mod();\n  const int MAX_N;\n  const int B;\n  vc<mint> POW;\n\
    \  vvc<mint> dat;\n\n  Prefix_Sum_Of_Binom(int MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N\
    \ + 1)) {\n    POW.resize(MAX_N + 1, mint(1));\n    FOR(i, MAX_N) POW[i + 1] =\
    \ POW[i] + POW[i];\n    int K = ceil(MAX_N, B + B) + 2;\n    dat.resize(K);\n\
    \    FOR(k, 0, K) {\n      // [0, kB] \u3067\u306E closed sum\n      vc<mint>&\
    \ f = dat[k];\n      f.resize(MAX_N + 1 - k * B);\n      int m = k * B;\n    \
    \  f[0] = POW[m] * fact<mint>(m);\n      FOR(i, MAX_N - m) {\n        f[i + 1]\
    \ = f[i] + f[i] - fact<mint>(i + m) * fact_inv<mint>(i);\n      }\n    }\n  }\n\
    \n  // \\sum_{k=0}^m binom(n,k)\n  mint query(int n, int m) {\n    assert(0 <=\
    \ m && m <= n + 1);\n    if (m == 0) return mint(0);\n    if (m + m > n + 1) return\
    \ POW[n] - query(n, n + 1 - m);\n    --m;\n    int a = m / B;\n    if (m <= a\
    \ * B + B / 2) {\n      ll t = 0;\n      FOR(i, a * B + 1, m + 1) {\n        t\
    \ += ll(fact_inv<mint>(i).val)\n             * (fact_inv<mint>(n - i).val + (t\
    \ <= 0 ? 0 : -mod));\n      }\n      return get(n, a) + mint(t) * fact<mint>(n);\n\
    \    } else {\n      ll t = 0;\n      FOR(i, m + 1, (a + 1) * B + 1) {\n     \
    \   t += ll(fact_inv<mint>(i).val)\n             * (fact_inv<mint>(n - i).val\
    \ + (t <= 0 ? 0 : -mod));\n      }\n      return get(n, a + 1) - mint(t) * fact<mint>(n);\n\
    \    }\n    return 0;\n  }\n\n  mint get(int n, int k) {\n    if (n <= k * B)\
    \ return POW[n];\n    return dat[k][n - k * B] * fact_inv<mint>(k * B);\n  }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/prefix_sum_of_binom.hpp
  requiredBy: []
  timestamp: '2023-02-22 17:01:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2206.test.cpp
documentation_of: mod/prefix_sum_of_binom.hpp
layout: document
redirect_from:
- /library/mod/prefix_sum_of_binom.hpp
- /library/mod/prefix_sum_of_binom.hpp.html
title: mod/prefix_sum_of_binom.hpp
---
