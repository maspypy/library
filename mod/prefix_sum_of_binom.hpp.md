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
  bundledCode: "#line 1 \"mod/prefix_sum_of_binom.hpp\"\ntemplate <typename mint>\n\
    struct Prefix_Sum_Of_Binom {\n  const int MAX_N;\n  const int B;\n  vvc<mint>\
    \ dat;\n\n  Prefix_Sum_Of_Binom(int MAX_N) : MAX_N(MAX_N), B(sqrt(MAX_N + 1))\
    \ {\n    int K = ceil(MAX_N, B + B) + 2;\n    dat.resize(K);\n    FOR(k, 0, K)\
    \ {\n      // [0, kB] \u3067\u306E closed sum\n      vc<mint>& f = dat[k];\n \
    \     f.resize(MAX_N + 1);\n      int m = k * B;\n      f[0] = fact<mint>(m);\n\
    \      FOR(i, MAX_N) {\n        f[i + 1] = f[i] + f[i]\n                   - (i\
    \ >= m ? fact<mint>(i) * fact_inv<mint>(i - m) : 0);\n      }\n    }\n  }\n\n\
    \  // \\sum_{k=0}^m binom(n,k)\n  mint query(int n, int m) {\n    assert(0 <=\
    \ m && m <= n + 1);\n    if (m == 0) return mint(0);\n    if (m + m > n + 1) return\
    \ mint(2).pow(n) - query(n, n + 1 - m);\n    --m;\n    int a = m / B;\n    if\
    \ (m <= a * B + B / 2) {\n      mint x = dat[a][n] * fact_inv<mint>(a * B);\n\
    \      mint t = 0;\n      FOR(i, a * B + 1, m + 1) t += fact_inv<mint>(i) * fact_inv<mint>(n\
    \ - i);\n      return x + t * fact<mint>(n);\n    } else {\n      mint x = dat[a\
    \ + 1][n] * fact_inv<mint>((a + 1) * B);\n      mint t = 0;\n      FOR(i, m +\
    \ 1, (a + 1) * B + 1)\n      t += fact_inv<mint>(i) * fact_inv<mint>(n - i);\n\
    \      return x - t * fact<mint>(n);\n    }\n    return 0;\n  }\n};\n"
  code: "template <typename mint>\nstruct Prefix_Sum_Of_Binom {\n  const int MAX_N;\n\
    \  const int B;\n  vvc<mint> dat;\n\n  Prefix_Sum_Of_Binom(int MAX_N) : MAX_N(MAX_N),\
    \ B(sqrt(MAX_N + 1)) {\n    int K = ceil(MAX_N, B + B) + 2;\n    dat.resize(K);\n\
    \    FOR(k, 0, K) {\n      // [0, kB] \u3067\u306E closed sum\n      vc<mint>&\
    \ f = dat[k];\n      f.resize(MAX_N + 1);\n      int m = k * B;\n      f[0] =\
    \ fact<mint>(m);\n      FOR(i, MAX_N) {\n        f[i + 1] = f[i] + f[i]\n    \
    \               - (i >= m ? fact<mint>(i) * fact_inv<mint>(i - m) : 0);\n    \
    \  }\n    }\n  }\n\n  // \\sum_{k=0}^m binom(n,k)\n  mint query(int n, int m)\
    \ {\n    assert(0 <= m && m <= n + 1);\n    if (m == 0) return mint(0);\n    if\
    \ (m + m > n + 1) return mint(2).pow(n) - query(n, n + 1 - m);\n    --m;\n   \
    \ int a = m / B;\n    if (m <= a * B + B / 2) {\n      mint x = dat[a][n] * fact_inv<mint>(a\
    \ * B);\n      mint t = 0;\n      FOR(i, a * B + 1, m + 1) t += fact_inv<mint>(i)\
    \ * fact_inv<mint>(n - i);\n      return x + t * fact<mint>(n);\n    } else {\n\
    \      mint x = dat[a + 1][n] * fact_inv<mint>((a + 1) * B);\n      mint t = 0;\n\
    \      FOR(i, m + 1, (a + 1) * B + 1)\n      t += fact_inv<mint>(i) * fact_inv<mint>(n\
    \ - i);\n      return x - t * fact<mint>(n);\n    }\n    return 0;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/prefix_sum_of_binom.hpp
  requiredBy: []
  timestamp: '2023-02-04 02:36:07+09:00'
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
