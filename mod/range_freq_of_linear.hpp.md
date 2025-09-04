---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/floor_sum_of_linear.hpp
    title: mod/floor_sum_of_linear.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_freq_of_linear.test.cpp
    title: test/1_mytest/range_freq_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/min_of_mod_of_linear_2.test.cpp
    title: test/2_library_checker/number_theory/min_of_mod_of_linear_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2280.test.cpp
    title: test/3_yukicoder/2280.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/floor_sum_of_linear.hpp\"\n\n// sum_{x in [L,R)} floor(ax\
    \ + b, mod)\n// I \u306F\u7BC4\u56F2\u5185\u3067 ax+b \u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u7A0B\u5EA6\ntemplate <typename O =\
    \ i128, typename I = long long>\nO floor_sum_of_linear(I L, I R, I a, I b, I mod)\
    \ {\n  assert(L <= R);\n  O res = 0;\n  b += L * a;\n  I N = R - L;\n\n  if (b\
    \ < 0) {\n    I k = ceil(-b, mod);\n    b += k * mod;\n    res -= O(N) * O(k);\n\
    \  }\n\n  while (N) {\n    I q;\n    tie(q, a) = divmod(a, mod);\n    res += (N\
    \ & 1 ? O(N) * O((N - 1) / 2) * O(q) : O(N / 2) * O(N - 1) * O(q));\n    if (b\
    \ >= mod) {\n      tie(q, b) = divmod(b, mod);\n      res += O(N) * q;\n    }\n\
    \    tie(N, b) = divmod(a * N + b, mod);\n    tie(a, mod) = mp(mod, a);\n  }\n\
    \  return res;\n}\n#line 2 \"mod/range_freq_of_linear.hpp\"\n\n// sum_{x in [L,R)}\
    \ floor(ax + b, mod)\n// I \u306F\u7BC4\u56F2\u5185\u3067 ax+b \u304C\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u7A0B\u5EA6\ntemplate <typename\
    \ O = i128, typename I = long long>\nI range_freq_of_linear(I L, I R, I a, I b,\
    \ I mod, I lo, I hi) {\n  if (lo >= hi) return 0;\n  assert(0 <= lo && lo < hi\
    \ && hi <= mod);\n\n  O x1 = floor_sum_of_linear<O, I>(L, R, a, b - lo, mod);\n\
    \  O x2 = floor_sum_of_linear<O, I>(L, R, a, b - hi, mod);\n  return x1 - x2;\n\
    }\n"
  code: "#include \"mod/floor_sum_of_linear.hpp\"\n\n// sum_{x in [L,R)} floor(ax\
    \ + b, mod)\n// I \u306F\u7BC4\u56F2\u5185\u3067 ax+b \u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u7A0B\u5EA6\ntemplate <typename O =\
    \ i128, typename I = long long>\nI range_freq_of_linear(I L, I R, I a, I b, I\
    \ mod, I lo, I hi) {\n  if (lo >= hi) return 0;\n  assert(0 <= lo && lo < hi &&\
    \ hi <= mod);\n\n  O x1 = floor_sum_of_linear<O, I>(L, R, a, b - lo, mod);\n \
    \ O x2 = floor_sum_of_linear<O, I>(L, R, a, b - hi, mod);\n  return x1 - x2;\n\
    }\n"
  dependsOn:
  - mod/floor_sum_of_linear.hpp
  isVerificationFile: false
  path: mod/range_freq_of_linear.hpp
  requiredBy: []
  timestamp: '2024-01-26 14:07:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2280.test.cpp
  - test/2_library_checker/number_theory/min_of_mod_of_linear_2.test.cpp
  - test/1_mytest/range_freq_of_linear.test.cpp
documentation_of: mod/range_freq_of_linear.hpp
layout: document
redirect_from:
- /library/mod/range_freq_of_linear.hpp
- /library/mod/range_freq_of_linear.hpp.html
title: mod/range_freq_of_linear.hpp
---
