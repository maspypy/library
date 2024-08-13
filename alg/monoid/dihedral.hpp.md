---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/arc153b2.test.cpp
    title: test_atcoder/arc153b2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://qoj.ac/contest/1576/problem/8512
  bundledCode: "#line 1 \"alg/monoid/dihedral.hpp\"\n\n/*\n2 \u9762\u4F53\u7FA4. \u9577\
    \u3055 n \u306E\u6587\u5B57\u5217\u306B\u4F5C\u7528\u3059\u308B.\n(0,k): i \u6587\
    \u5B57\u76EE\u304C i+k \u6587\u5B57\u76EE\u306B\u79FB\u52D5. S \u306F S[-i:N-i)\
    \ \u306B\u5909\u5316.\n(1,k): i \u6587\u5B57\u76EE\u304C k-i \u6587\u5B57\u76EE\
    \u306B\u79FB\u52D5. S \u306F S[k:k-N).\n\u3053\u308C\u306F revS[N-1-k:N-1-k+N]\
    \ \u3068\u3082\u8A00\u3048\u308B.\nhttps://qoj.ac/contest/1576/problem/8512\n\
    */\ntemplate <int id>\nstruct Dihedral {\n  using value_type = pair<int, int>;\n\
    \  using X = value_type;\n\n  static inline int n = 0;\n  static void set_n(int\
    \ m) { n = m; }\n\n  static X op(X x, X y) {\n    // x \u3092\u3084\u3063\u305F\
    \u3042\u3068 y\n    auto [t1, k1] = x;\n    auto [t2, k2] = y;\n    int t = t1\
    \ ^ t2;\n    int k = (t2 == 0 ? k1 + k2 : k2 - k1 + n);\n    if (k >= n) k -=\
    \ n;\n    return {t, k};\n  }\n  static X inverse(X x) {\n    if (x.fi == 0) x.se\
    \ = (x.se == 0 ? 0 : n - x.se);\n    return x;\n  }\n  static constexpr X unit()\
    \ { return {0, 0}; }\n  static constexpr bool commute = 0;\n\n  static X cyclic_shift_left(ll\
    \ k) { return cyclic_shift_right(-k); }\n  static X cyclic_shift_right(ll k) {\n\
    \    k %= n;\n    if (k < 0) k += n;\n    return {0, k};\n  }\n  static X reverse()\
    \ { return {1, n - 1}; }\n  template <typename STRING>\n  static STRING apply(X\
    \ f, STRING A) {\n    assert(len(A) == n);\n    auto [t, x] = f;\n    if (!t)\
    \ {\n      rotate(A.begin(), A.begin() + n - x, A.end());\n      return A;\n \
    \   }\n    std::reverse(all(A));\n    rotate(A.begin(), A.begin() + (n - 1 - x),\
    \ A.end());\n    return A;\n  }\n};\n"
  code: "\n/*\n2 \u9762\u4F53\u7FA4. \u9577\u3055 n \u306E\u6587\u5B57\u5217\u306B\
    \u4F5C\u7528\u3059\u308B.\n(0,k): i \u6587\u5B57\u76EE\u304C i+k \u6587\u5B57\u76EE\
    \u306B\u79FB\u52D5. S \u306F S[-i:N-i) \u306B\u5909\u5316.\n(1,k): i \u6587\u5B57\
    \u76EE\u304C k-i \u6587\u5B57\u76EE\u306B\u79FB\u52D5. S \u306F S[k:k-N).\n\u3053\
    \u308C\u306F revS[N-1-k:N-1-k+N] \u3068\u3082\u8A00\u3048\u308B.\nhttps://qoj.ac/contest/1576/problem/8512\n\
    */\ntemplate <int id>\nstruct Dihedral {\n  using value_type = pair<int, int>;\n\
    \  using X = value_type;\n\n  static inline int n = 0;\n  static void set_n(int\
    \ m) { n = m; }\n\n  static X op(X x, X y) {\n    // x \u3092\u3084\u3063\u305F\
    \u3042\u3068 y\n    auto [t1, k1] = x;\n    auto [t2, k2] = y;\n    int t = t1\
    \ ^ t2;\n    int k = (t2 == 0 ? k1 + k2 : k2 - k1 + n);\n    if (k >= n) k -=\
    \ n;\n    return {t, k};\n  }\n  static X inverse(X x) {\n    if (x.fi == 0) x.se\
    \ = (x.se == 0 ? 0 : n - x.se);\n    return x;\n  }\n  static constexpr X unit()\
    \ { return {0, 0}; }\n  static constexpr bool commute = 0;\n\n  static X cyclic_shift_left(ll\
    \ k) { return cyclic_shift_right(-k); }\n  static X cyclic_shift_right(ll k) {\n\
    \    k %= n;\n    if (k < 0) k += n;\n    return {0, k};\n  }\n  static X reverse()\
    \ { return {1, n - 1}; }\n  template <typename STRING>\n  static STRING apply(X\
    \ f, STRING A) {\n    assert(len(A) == n);\n    auto [t, x] = f;\n    if (!t)\
    \ {\n      rotate(A.begin(), A.begin() + n - x, A.end());\n      return A;\n \
    \   }\n    std::reverse(all(A));\n    rotate(A.begin(), A.begin() + (n - 1 - x),\
    \ A.end());\n    return A;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/dihedral.hpp
  requiredBy: []
  timestamp: '2024-04-04 05:59:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/arc153b2.test.cpp
documentation_of: alg/monoid/dihedral.hpp
layout: document
redirect_from:
- /library/alg/monoid/dihedral.hpp
- /library/alg/monoid/dihedral.hpp.html
title: alg/monoid/dihedral.hpp
---
