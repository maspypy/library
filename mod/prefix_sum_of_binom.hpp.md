---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/prefix_sum_of_binom.test.cpp
    title: test/1_mytest/prefix_sum_of_binom.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2206.test.cpp
    title: test/3_yukicoder/2206.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/prefix_sum_of_binom.hpp\"\ntemplate <typename mint>\n\
    struct Prefix_Sum_Of_Binom {\n  static constexpr u32 mod = mint::get_mod();\n\
    \  const int MAX_N;\n  const int B;\n  vc<mint> POW;\n  vvc<mint> dat;\n\n  Prefix_Sum_Of_Binom(int\
    \ MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N + 1)) {\n    assert(MAX_N >= 0);\n    int\
    \ K = ceil(MAX_N, B + B) + 2;\n    int p = max(MAX_N, K * B);\n    POW.assign(p\
    \ + 1, mint(1));\n    FOR(i, p) POW[i + 1] = POW[i] + POW[i];\n    dat.resize(K);\n\
    \    FOR(k, 0, K) {\n      // [0, kB] \u3067\u306E closed sum\n      vc<mint>\
    \ &f = dat[k];\n      if (MAX_N + 1 - k * B <= 0) continue;\n      f.resize(MAX_N\
    \ + 1 - k * B);\n      int m = k * B;\n      f[0] = POW[m] * fact<mint>(m);\n\
    \      FOR(i, MAX_N - m) {\n        f[i + 1] = f[i] + f[i] - fact<mint>(i + m)\
    \ * fact_inv<mint>(i);\n      }\n    }\n  }\n\n  // \\sum_{k=0}^{m-1} binom(n,k)\n\
    \  mint query(int n, int m) {\n    assert(0 <= m);\n    chmin(m, n + 1);\n   \
    \ if (m == 0) return mint(0);\n    if (m + m > n + 1) return POW[n] - query(n,\
    \ n + 1 - m);\n    --m;\n    int a = m / B;\n\n    if (m <= a * B + B / 2) {\n\
    \      u128 t = 0;\n      FOR(i, a * B + 1, m + 1) {\n        t += u64(fact_inv<mint>(i).val)\
    \ * (fact_inv<mint>(n - i).val);\n      }\n      return _get(n, a) + mint::raw(t\
    \ % mod) * fact<mint>(n);\n    } else {\n      u128 t = 0;\n      FOR(i, m + 1,\
    \ (a + 1) * B + 1) {\n        t += u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n\
    \ - i).val);\n      }\n      return _get(n, a + 1) - mint::raw(t % mod) * fact<mint>(n);\n\
    \    }\n    return 0;\n  }\n\nprivate:\n  mint _get(int n, int k) {\n    if (n\
    \ <= k * B) return POW[n];\n    return dat[k][n - k * B] * fact_inv<mint>(k *\
    \ B);\n  }\n};\n"
  code: "template <typename mint>\nstruct Prefix_Sum_Of_Binom {\n  static constexpr\
    \ u32 mod = mint::get_mod();\n  const int MAX_N;\n  const int B;\n  vc<mint> POW;\n\
    \  vvc<mint> dat;\n\n  Prefix_Sum_Of_Binom(int MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N\
    \ + 1)) {\n    assert(MAX_N >= 0);\n    int K = ceil(MAX_N, B + B) + 2;\n    int\
    \ p = max(MAX_N, K * B);\n    POW.assign(p + 1, mint(1));\n    FOR(i, p) POW[i\
    \ + 1] = POW[i] + POW[i];\n    dat.resize(K);\n    FOR(k, 0, K) {\n      // [0,\
    \ kB] \u3067\u306E closed sum\n      vc<mint> &f = dat[k];\n      if (MAX_N +\
    \ 1 - k * B <= 0) continue;\n      f.resize(MAX_N + 1 - k * B);\n      int m =\
    \ k * B;\n      f[0] = POW[m] * fact<mint>(m);\n      FOR(i, MAX_N - m) {\n  \
    \      f[i + 1] = f[i] + f[i] - fact<mint>(i + m) * fact_inv<mint>(i);\n     \
    \ }\n    }\n  }\n\n  // \\sum_{k=0}^{m-1} binom(n,k)\n  mint query(int n, int\
    \ m) {\n    assert(0 <= m);\n    chmin(m, n + 1);\n    if (m == 0) return mint(0);\n\
    \    if (m + m > n + 1) return POW[n] - query(n, n + 1 - m);\n    --m;\n    int\
    \ a = m / B;\n\n    if (m <= a * B + B / 2) {\n      u128 t = 0;\n      FOR(i,\
    \ a * B + 1, m + 1) {\n        t += u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n\
    \ - i).val);\n      }\n      return _get(n, a) + mint::raw(t % mod) * fact<mint>(n);\n\
    \    } else {\n      u128 t = 0;\n      FOR(i, m + 1, (a + 1) * B + 1) {\n   \
    \     t += u64(fact_inv<mint>(i).val) * (fact_inv<mint>(n - i).val);\n      }\n\
    \      return _get(n, a + 1) - mint::raw(t % mod) * fact<mint>(n);\n    }\n  \
    \  return 0;\n  }\n\nprivate:\n  mint _get(int n, int k) {\n    if (n <= k * B)\
    \ return POW[n];\n    return dat[k][n - k * B] * fact_inv<mint>(k * B);\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: mod/prefix_sum_of_binom.hpp
  requiredBy: []
  timestamp: '2024-04-12 12:45:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/prefix_sum_of_binom.test.cpp
  - test/3_yukicoder/2206.test.cpp
documentation_of: mod/prefix_sum_of_binom.hpp
layout: document
redirect_from:
- /library/mod/prefix_sum_of_binom.hpp
- /library/mod/prefix_sum_of_binom.hpp.html
title: mod/prefix_sum_of_binom.hpp
---
