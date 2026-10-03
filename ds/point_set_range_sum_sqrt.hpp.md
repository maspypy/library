---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Add\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\n  static constexpr X id() { return X(0); }\n\
    \  static constexpr bool commute = true;\n};\n#line 2 \"ds/point_set_range_sum_sqrt.hpp\"\
    \n\n// update O(1) / query O(sqrt N)\n// b_sz \u306F sqrt(N/2) \u304C\u76EE\u5B89\
    \ntemplate <typename AbelGroup, int b_sz = 256>\nstruct Point_Set_Range_Sum_Sqrt\
    \ {\n  using G = AbelGroup;\n  static_assert(G::commute);\n  using MX = AbelGroup;\n\
    \  using E = typename G::value_type;\n  int n, b_num;\n  vc<E> A, B;\n  E total;\n\
    \n  Point_Set_Range_Sum_Sqrt(int N = 0) { build(N); }\n  template <typename F>\n\
    \  Point_Set_Range_Sum_Sqrt(int N, F f) {\n    build(N, f);\n  }\n\n  void build(int\
    \ N) {\n    build(N, [&](int i) -> E { return G::id(); });\n  }\n  void build(const\
    \ vc<E> &v) {\n    build(len(v), [&](int i) -> E { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m;\n    b_num = ceil<int>(n,\
    \ b_sz);\n    A.assign(b_sz * b_num, G::id()), B.assign(b_num, G::id());\n   \
    \ FOR(i, n) A[i] = f(i);\n    for (int l = 0, b = 0; b < b_num; ++b, l += b_sz)\
    \ {\n      E x = G::id();\n      FOR(i, l, l + b_sz) x = G::op(x, A[i]);\n   \
    \   B[b] = x;\n    }\n    total = G::id();\n    for (E x : B) total = G::op(total,\
    \ x);\n  }\n\n  E prod_all() const { return total; }\n  E sum_all() const { return\
    \ total; }\n  E sum(int k) const { return sum(0, k); }\n  E prod(int k) const\
    \ { return sum(0, k); }\n  E sum(int L, int R) const { return prod(L, R); }\n\
    \  E prod(int L, int R) const {\n    assert(0 <= L && L <= R && R <= n);\n   \
    \ auto [b1, k1] = divmod<int>(L, b_sz);\n    E add = G::id(), sub = G::id();\n\
    \    if (k1 <= b_sz / 2) {\n      FOR(i, b1 * b_sz, L) sub = G::op(sub, A[i]);\n\
    \    } else {\n      ++b1;\n      FOR(i, L, b1 * b_sz) add = G::op(add, A[i]);\n\
    \    }\n    auto [b2, k2] = divmod<int>(R, b_sz);\n    if (k2 <= b_sz / 2) {\n\
    \      FOR(i, b2 * b_sz, R) add = G::op(add, A[i]);\n    } else {\n      ++b2;\n\
    \      FOR(i, R, b2 * b_sz) sub = G::op(sub, A[i]);\n    }\n    // [b1,b2) \u3092\
    \u8DB3\u3059\n    if (b2 - b1 <= b_num / 2) {\n      FOR(b, b1, b2) add = G::op(add,\
    \ B[b]);\n    } else {\n      add = G::op(add, total);\n      FOR(b, b1) sub =\
    \ G::op(sub, B[b]);\n      FOR(b, b2, b_num) sub = G::op(sub, B[b]);\n    }\n\
    \    return G::op(add, G::inverse(sub));\n  }\n\n  void add(int k, E x) { multiply(k,\
    \ x); }\n  void multiply(int k, E x) {\n    assert(0 <= k && k < n);\n    total\
    \ = G::op(total, x);\n    A[k] = G::op(A[k], x), B[k / b_sz] = G::op(B[k / b_sz],\
    \ x);\n  }\n  void set(int k, E x) {\n    assert(0 <= k && k < n);\n    x = G::op(x,\
    \ G::inverse(A[k]));\n    add(k, x);\n  }\n};\n"
  code: "#include \"alg/monoid/add.hpp\"\n\n// update O(1) / query O(sqrt N)\n// b_sz\
    \ \u306F sqrt(N/2) \u304C\u76EE\u5B89\ntemplate <typename AbelGroup, int b_sz\
    \ = 256>\nstruct Point_Set_Range_Sum_Sqrt {\n  using G = AbelGroup;\n  static_assert(G::commute);\n\
    \  using MX = AbelGroup;\n  using E = typename G::value_type;\n  int n, b_num;\n\
    \  vc<E> A, B;\n  E total;\n\n  Point_Set_Range_Sum_Sqrt(int N = 0) { build(N);\
    \ }\n  template <typename F>\n  Point_Set_Range_Sum_Sqrt(int N, F f) {\n    build(N,\
    \ f);\n  }\n\n  void build(int N) {\n    build(N, [&](int i) -> E { return G::id();\
    \ });\n  }\n  void build(const vc<E> &v) {\n    build(len(v), [&](int i) -> E\
    \ { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n\
    \    n = m;\n    b_num = ceil<int>(n, b_sz);\n    A.assign(b_sz * b_num, G::id()),\
    \ B.assign(b_num, G::id());\n    FOR(i, n) A[i] = f(i);\n    for (int l = 0, b\
    \ = 0; b < b_num; ++b, l += b_sz) {\n      E x = G::id();\n      FOR(i, l, l +\
    \ b_sz) x = G::op(x, A[i]);\n      B[b] = x;\n    }\n    total = G::id();\n  \
    \  for (E x : B) total = G::op(total, x);\n  }\n\n  E prod_all() const { return\
    \ total; }\n  E sum_all() const { return total; }\n  E sum(int k) const { return\
    \ sum(0, k); }\n  E prod(int k) const { return sum(0, k); }\n  E sum(int L, int\
    \ R) const { return prod(L, R); }\n  E prod(int L, int R) const {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    auto [b1, k1] = divmod<int>(L, b_sz);\n    E\
    \ add = G::id(), sub = G::id();\n    if (k1 <= b_sz / 2) {\n      FOR(i, b1 *\
    \ b_sz, L) sub = G::op(sub, A[i]);\n    } else {\n      ++b1;\n      FOR(i, L,\
    \ b1 * b_sz) add = G::op(add, A[i]);\n    }\n    auto [b2, k2] = divmod<int>(R,\
    \ b_sz);\n    if (k2 <= b_sz / 2) {\n      FOR(i, b2 * b_sz, R) add = G::op(add,\
    \ A[i]);\n    } else {\n      ++b2;\n      FOR(i, R, b2 * b_sz) sub = G::op(sub,\
    \ A[i]);\n    }\n    // [b1,b2) \u3092\u8DB3\u3059\n    if (b2 - b1 <= b_num /\
    \ 2) {\n      FOR(b, b1, b2) add = G::op(add, B[b]);\n    } else {\n      add\
    \ = G::op(add, total);\n      FOR(b, b1) sub = G::op(sub, B[b]);\n      FOR(b,\
    \ b2, b_num) sub = G::op(sub, B[b]);\n    }\n    return G::op(add, G::inverse(sub));\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    assert(0 <= k && k < n);\n    total = G::op(total, x);\n    A[k] = G::op(A[k],\
    \ x), B[k / b_sz] = G::op(B[k / b_sz], x);\n  }\n  void set(int k, E x) {\n  \
    \  assert(0 <= k && k < n);\n    x = G::op(x, G::inverse(A[k]));\n    add(k, x);\n\
    \  }\n};"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/point_set_range_sum_sqrt.hpp
  requiredBy: []
  timestamp: '2026-09-28 15:32:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/point_set_range_sum_sqrt.hpp
layout: document
redirect_from:
- /library/ds/point_set_range_sum_sqrt.hpp
- /library/ds/point_set_range_sum_sqrt.hpp.html
title: ds/point_set_range_sum_sqrt.hpp
---
