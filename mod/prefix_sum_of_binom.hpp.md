---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2206.test.cpp
    title: test/yukicoder/2206.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/prefix_sum_of_binom.hpp\"\n// \\sum_{k=0}^m binom(n,k)\
    \ \u3092\u6C42\u3081\u308B\u30AF\u30A8\u30EA\u306B\u30AA\u30F3\u30E9\u30A4\u30F3\
    \u3067\u7B54\u3048\u308B\ntemplate <typename mint>\nstruct Prefix_Sum_Of_Binom\
    \ {\n  const int MAX_N;\n  const int B;\n  vvc<mint> dat;\n\n  Prefix_Sum_Of_Binom(int\
    \ MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N + 1)) {\n    int K = ceil(MAX_N, B + B)\
    \ + 2;\n    dat.resize(K);\n    FOR(k, 1, K) {\n      // kB \u500B\u306E\u548C\
    \n      vc<mint>& f = dat[k];\n      f.resize(MAX_N + 1);\n      f[0] = mint(1);\n\
    \      FOR(i, MAX_N) f[i + 1] = f[i] + f[i] - C<mint>(i, k * B - 1);\n    }\n\
    \  }\n\n  // \\sum_{k=0}^m binom(n,k)\n  mint query(int n, int m) {\n    assert(0\
    \ <= m && m <= n + 1);\n    if (m == 0) return mint(0);\n    if (m + m > n + 1)\
    \ return mint(2).pow(n) - query(n, n + 1 - m);\n    int a = m / B;\n    mint t\
    \ = 0;\n    if (m <= a * B + (B / 2)) {\n      FOR(i, a * B, m) t += fact_inv<mint>(i)\
    \ * fact_inv<mint>(n - i);\n      return (a == 0 ? mint(0) : dat[a][n]) + t *\
    \ fact<mint>(n);\n    } else {\n      FOR(i, m, (a + 1) * B) t += fact_inv<mint>(i)\
    \ * fact_inv<mint>(n - i);\n      return dat[a + 1][n] - t * fact<mint>(n);\n\
    \    }\n    return 0;\n  }\n};\n"
  code: "// \\sum_{k=0}^m binom(n,k) \u3092\u6C42\u3081\u308B\u30AF\u30A8\u30EA\u306B\
    \u30AA\u30F3\u30E9\u30A4\u30F3\u3067\u7B54\u3048\u308B\ntemplate <typename mint>\n\
    struct Prefix_Sum_Of_Binom {\n  const int MAX_N;\n  const int B;\n  vvc<mint>\
    \ dat;\n\n  Prefix_Sum_Of_Binom(int MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N + 1))\
    \ {\n    int K = ceil(MAX_N, B + B) + 2;\n    dat.resize(K);\n    FOR(k, 1, K)\
    \ {\n      // kB \u500B\u306E\u548C\n      vc<mint>& f = dat[k];\n      f.resize(MAX_N\
    \ + 1);\n      f[0] = mint(1);\n      FOR(i, MAX_N) f[i + 1] = f[i] + f[i] - C<mint>(i,\
    \ k * B - 1);\n    }\n  }\n\n  // \\sum_{k=0}^m binom(n,k)\n  mint query(int n,\
    \ int m) {\n    assert(0 <= m && m <= n + 1);\n    if (m == 0) return mint(0);\n\
    \    if (m + m > n + 1) return mint(2).pow(n) - query(n, n + 1 - m);\n    int\
    \ a = m / B;\n    mint t = 0;\n    if (m <= a * B + (B / 2)) {\n      FOR(i, a\
    \ * B, m) t += fact_inv<mint>(i) * fact_inv<mint>(n - i);\n      return (a ==\
    \ 0 ? mint(0) : dat[a][n]) + t * fact<mint>(n);\n    } else {\n      FOR(i, m,\
    \ (a + 1) * B) t += fact_inv<mint>(i) * fact_inv<mint>(n - i);\n      return dat[a\
    \ + 1][n] - t * fact<mint>(n);\n    }\n    return 0;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mod/prefix_sum_of_binom.hpp
  requiredBy: []
  timestamp: '2023-02-04 01:43:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2206.test.cpp
documentation_of: mod/prefix_sum_of_binom.hpp
layout: document
redirect_from:
- /library/mod/prefix_sum_of_binom.hpp
- /library/mod/prefix_sum_of_binom.hpp.html
title: mod/prefix_sum_of_binom.hpp
---
