---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/data_structure/staticrmq_sqrt_tree.test.cpp
    title: test/2_library_checker/data_structure/staticrmq_sqrt_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/sqrt_tree.hpp\"\n\n// \u6298\u89D2\u306A\u306E\u3067\u4F5C\
    \u3063\u3066\u307F\u305F\u304C\uFF0C\u4F7F\u308F\u306A\u3055\u305D\u3046\ntemplate\
    \ <typename Monoid>\nstruct SQRT_Tree {\n  using MX = Monoid;\n  using X = typename\
    \ MX::value_type;\n\n  static constexpr int K = 3;\n  static constexpr u32 SZ[]\
    \ = {8, 64, 4096};\n  static constexpr u32 MASK[] = {7, 63, 4095};\n\n  int N;\n\
    \  // \u5143\u3068\u306A\u308B\u9759\u7684\u306A\u5217\n  vc<X> A;\n  // \u5404\
    \u968E\u5C64\u306B\u5BFE\u3057\u3066\uFF0C\u30D6\u30ED\u30C3\u30AF\u5148\u982D\
    \u304B\u3089\u3042\u308B\u8981\u7D20\u307E\u3067 [s,i]\n  // \u5404\u968E\u5C64\
    \u306B\u5BFE\u3057\u3066\uFF0C\u3042\u308B\u8981\u7D20\u304B\u3089\u30D6\u30ED\
    \u30C3\u30AF\u672B\u5C3E\u307E\u3067 [i,t]\n  vvc<X> PREF, SUFF;\n  // \u5404\u968E\
    \u5C64\u306B\u5BFE\u3057\u3066\uFF0C\u3042\u308B\u30D6\u30ED\u30C3\u30AF\u304B\
    \u3089\u3042\u308B\u30D6\u30ED\u30C3\u30AF\u307E\u3067\n  vvc<X> BETWEEN;\n\n\
    \  SQRT_Tree() {}\n  template <typename F>\n  SQRT_Tree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SQRT_Tree(const vc<X>& v) {\n    build(len(v), [&](int i) -> X {\
    \ return v[i]; });\n  }\n\n  template <typename F>\n  void build(int n_, F f)\
    \ {\n    N = n_;\n    assert(N <= (1 << 24));\n    A.reserve(N);\n    FOR(i, N)\
    \ A.eb(f(i));\n    // \u307E\u305A prefix, suffix \u306E\u69CB\u7BC9\n    PREF.assign(K,\
    \ A), SUFF.assign(K, A);\n    FOR(k, K) {\n      FOR(i, N) {\n        if (i &\
    \ MASK[k]) PREF[k][i] = MX::op(PREF[k][i - 1], A[i]);\n      }\n      FOR_R(i,\
    \ N) {\n        if (i & MASK[k]) SUFF[k][i - 1] = MX::op(A[i - 1], SUFF[k][i]);\n\
    \      }\n    }\n    // between \u306E\u69CB\u7BC9\n    BETWEEN.resize(K);\n \
    \   FOR(k, K) {\n      // n : \u5168\u4F53\u306E\u5C0F\u30D6\u30ED\u30C3\u30AF\
    \u306E\u500B\u6570\n      auto get = [&](int i) -> X { return SUFF[k][SZ[k] *\
    \ i]; };\n      int n = N / SZ[k];\n      int s = 0;\n      FOR(r, n) {\n    \
    \    if (r % SZ[k] == 0) s = r;\n        BETWEEN[k].eb(get(r));\n        FOR_R(l,\
    \ s, r) { BETWEEN[k].eb(MX::op(get(l), BETWEEN[k].back())); }\n      }\n    }\n\
    \  }\n\n  static constexpr int BIT_TO_LAYER[] = {0, 0, 0, 1, 1, 1, 2, 2, 2, 2,\
    \ 2, 2,\n                                         3, 3, 3, 3, 3, 3, 3, 3, 3, 3,\
    \ 3, 3};\n\n  X prod(int L, int R) {\n    assert(0 <= L && L <= R && R <= N);\n\
    \    if (L == R) return MX::unit();\n    if (L + 1 == R) return A[L];\n    --R;\n\
    \    int k = BIT_TO_LAYER[topbit(L ^ R)];\n    if (k == 0) {\n      // \u9577\u3055\
    \ SZ[0] \u306E\u30D6\u30ED\u30C3\u30AF\u306B\u30AF\u30A8\u30EA\u304C\u53CE\u307E\
    \u3063\u3066\u3044\u308B. \u611A\u76F4\u306B.\n      X x = A[L];\n      FOR(i,\
    \ L + 1, R + 1) x = MX::op(x, A[i]);\n      return x;\n    }\n    --k;\n    //\
    \ \u540C\u3058\u9577\u3055 SZ[k+1] \u306E\u30D6\u30ED\u30C3\u30AF\u5185\u306B\u3042\
    \u308B. \u9055\u3046 SZ[k] \u30D6\u30ED\u30C3\u30AF\u5185\u306B\u3042\u308B.\n\
    \    u32 a = L / SZ[k], b = R / SZ[k];\n    assert(a < b);\n    X &x1 = SUFF[k][L],\
    \ &x2 = PREF[k][R];\n    if (a + 1 == b) return MX::op(x1, x2);\n    ++a, --b;\n\
    \    // [a,b] \u756A\u76EE\u306E SZ[k]-block \u306E\u9593\u3092\u53D6\u5F97\u3059\
    \u308B\n    // BETWEEN \u306E\u3069\u3053\u306B\u30C7\u30FC\u30BF\u304C\u7F6E\u3044\
    \u3066\u3042\u308B\u304B\u8ABF\u3079\u308B\n    u32 m = a / SZ[k];\n    a &= MASK[k],\
    \ b &= MASK[k];\n    u32 idx = m * (SZ[k] / 2) * (SZ[k] + 1);\n    idx += (b +\
    \ 1) * (b + 2) / 2 - 1 - a;\n    return MX::op(x1, MX::op(BETWEEN[k][idx], x2));\n\
    \  }\n};\n"
  code: "\n// \u6298\u89D2\u306A\u306E\u3067\u4F5C\u3063\u3066\u307F\u305F\u304C\uFF0C\
    \u4F7F\u308F\u306A\u3055\u305D\u3046\ntemplate <typename Monoid>\nstruct SQRT_Tree\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\n  static constexpr\
    \ int K = 3;\n  static constexpr u32 SZ[] = {8, 64, 4096};\n  static constexpr\
    \ u32 MASK[] = {7, 63, 4095};\n\n  int N;\n  // \u5143\u3068\u306A\u308B\u9759\
    \u7684\u306A\u5217\n  vc<X> A;\n  // \u5404\u968E\u5C64\u306B\u5BFE\u3057\u3066\
    \uFF0C\u30D6\u30ED\u30C3\u30AF\u5148\u982D\u304B\u3089\u3042\u308B\u8981\u7D20\
    \u307E\u3067 [s,i]\n  // \u5404\u968E\u5C64\u306B\u5BFE\u3057\u3066\uFF0C\u3042\
    \u308B\u8981\u7D20\u304B\u3089\u30D6\u30ED\u30C3\u30AF\u672B\u5C3E\u307E\u3067\
    \ [i,t]\n  vvc<X> PREF, SUFF;\n  // \u5404\u968E\u5C64\u306B\u5BFE\u3057\u3066\
    \uFF0C\u3042\u308B\u30D6\u30ED\u30C3\u30AF\u304B\u3089\u3042\u308B\u30D6\u30ED\
    \u30C3\u30AF\u307E\u3067\n  vvc<X> BETWEEN;\n\n  SQRT_Tree() {}\n  template <typename\
    \ F>\n  SQRT_Tree(int n, F f) {\n    build(n, f);\n  }\n  SQRT_Tree(const vc<X>&\
    \ v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n\n  template\
    \ <typename F>\n  void build(int n_, F f) {\n    N = n_;\n    assert(N <= (1 <<\
    \ 24));\n    A.reserve(N);\n    FOR(i, N) A.eb(f(i));\n    // \u307E\u305A prefix,\
    \ suffix \u306E\u69CB\u7BC9\n    PREF.assign(K, A), SUFF.assign(K, A);\n    FOR(k,\
    \ K) {\n      FOR(i, N) {\n        if (i & MASK[k]) PREF[k][i] = MX::op(PREF[k][i\
    \ - 1], A[i]);\n      }\n      FOR_R(i, N) {\n        if (i & MASK[k]) SUFF[k][i\
    \ - 1] = MX::op(A[i - 1], SUFF[k][i]);\n      }\n    }\n    // between \u306E\u69CB\
    \u7BC9\n    BETWEEN.resize(K);\n    FOR(k, K) {\n      // n : \u5168\u4F53\u306E\
    \u5C0F\u30D6\u30ED\u30C3\u30AF\u306E\u500B\u6570\n      auto get = [&](int i)\
    \ -> X { return SUFF[k][SZ[k] * i]; };\n      int n = N / SZ[k];\n      int s\
    \ = 0;\n      FOR(r, n) {\n        if (r % SZ[k] == 0) s = r;\n        BETWEEN[k].eb(get(r));\n\
    \        FOR_R(l, s, r) { BETWEEN[k].eb(MX::op(get(l), BETWEEN[k].back())); }\n\
    \      }\n    }\n  }\n\n  static constexpr int BIT_TO_LAYER[] = {0, 0, 0, 1, 1,\
    \ 1, 2, 2, 2, 2, 2, 2,\n                                         3, 3, 3, 3, 3,\
    \ 3, 3, 3, 3, 3, 3, 3};\n\n  X prod(int L, int R) {\n    assert(0 <= L && L <=\
    \ R && R <= N);\n    if (L == R) return MX::unit();\n    if (L + 1 == R) return\
    \ A[L];\n    --R;\n    int k = BIT_TO_LAYER[topbit(L ^ R)];\n    if (k == 0) {\n\
    \      // \u9577\u3055 SZ[0] \u306E\u30D6\u30ED\u30C3\u30AF\u306B\u30AF\u30A8\u30EA\
    \u304C\u53CE\u307E\u3063\u3066\u3044\u308B. \u611A\u76F4\u306B.\n      X x = A[L];\n\
    \      FOR(i, L + 1, R + 1) x = MX::op(x, A[i]);\n      return x;\n    }\n   \
    \ --k;\n    // \u540C\u3058\u9577\u3055 SZ[k+1] \u306E\u30D6\u30ED\u30C3\u30AF\
    \u5185\u306B\u3042\u308B. \u9055\u3046 SZ[k] \u30D6\u30ED\u30C3\u30AF\u5185\u306B\
    \u3042\u308B.\n    u32 a = L / SZ[k], b = R / SZ[k];\n    assert(a < b);\n   \
    \ X &x1 = SUFF[k][L], &x2 = PREF[k][R];\n    if (a + 1 == b) return MX::op(x1,\
    \ x2);\n    ++a, --b;\n    // [a,b] \u756A\u76EE\u306E SZ[k]-block \u306E\u9593\
    \u3092\u53D6\u5F97\u3059\u308B\n    // BETWEEN \u306E\u3069\u3053\u306B\u30C7\u30FC\
    \u30BF\u304C\u7F6E\u3044\u3066\u3042\u308B\u304B\u8ABF\u3079\u308B\n    u32 m\
    \ = a / SZ[k];\n    a &= MASK[k], b &= MASK[k];\n    u32 idx = m * (SZ[k] / 2)\
    \ * (SZ[k] + 1);\n    idx += (b + 1) * (b + 2) / 2 - 1 - a;\n    return MX::op(x1,\
    \ MX::op(BETWEEN[k][idx], x2));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/sqrt_tree.hpp
  requiredBy: []
  timestamp: '2024-02-06 13:07:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/data_structure/staticrmq_sqrt_tree.test.cpp
documentation_of: ds/sqrt_tree.hpp
layout: document
redirect_from:
- /library/ds/sqrt_tree.hpp
- /library/ds/sqrt_tree.hpp.html
title: ds/sqrt_tree.hpp
---
