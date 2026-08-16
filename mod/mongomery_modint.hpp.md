---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/count/count_labeled_bipartite.hpp
    title: graph/count/count_labeled_bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
  - icon: ':warning:'
    path: nt/prime_test.hpp
    title: nt/prime_test.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_bipartite.test.cpp
    title: test/1_mytest/count_bipartite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/enumerative_combinatorics/factorial_mongomery.test.cpp
    title: test/2_library_checker/enumerative_combinatorics/factorial_mongomery.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/sqrt_mod.test.cpp
    title: test/2_library_checker/number_theory/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/2_library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/2_library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/3229.test.cpp
    title: test/3_yukicoder/3229.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/mongomery_modint.hpp\"\n\n// odd mod.\n// x \u306E\u4EE3\
    \u308F\u308A\u306B rx \u3092\u6301\u3064\ntemplate <int id, typename U1, typename\
    \ U2>\nstruct Mongomery_modint {\n  using mint = Mongomery_modint;\n  inline static\
    \ U1 m, r, n2;\n  static constexpr int W = numeric_limits<U1>::digits;\n\n  static\
    \ void set_mod(U1 mod) {\n    assert(mod & 1 && mod <= U1(1) << (W - 2));\n  \
    \  m = mod, n2 = -U2(m) % m, r = m;\n    FOR(5) r *= 2 - m * r;\n    r = -r;\n\
    \    assert(r * m == U1(-1));\n  }\n  static U1 reduce(U2 b) { return (b + U2(U1(b)\
    \ * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint() : x(0) {}\n  Mongomery_modint(U1\
    \ x) : x(reduce(U2(x) * n2)){};\n  U1 val() const {\n    U1 y = reduce(x);\n \
    \   return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint y) {\n    x = ((x\
    \ += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint &operator-=(mint\
    \ y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n  }\n  mint &operator*=(mint\
    \ y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n  }\n  mint operator+(mint\
    \ y) const { return mint(*this) += y; }\n  mint operator-(mint y) const { return\
    \ mint(*this) -= y; }\n  mint operator*(mint y) const { return mint(*this) *=\
    \ y; }\n  bool operator==(mint y) const {\n    return (x >= m ? x - m : x) ==\
    \ (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const { return not\
    \ operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n    mint y\
    \ = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1) y *= z;\n\
    \    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32 = Mongomery_modint<id,\
    \ u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64 = Mongomery_modint<id,\
    \ u64, u128>;\n"
  code: "\n// odd mod.\n// x \u306E\u4EE3\u308F\u308A\u306B rx \u3092\u6301\u3064\n\
    template <int id, typename U1, typename U2>\nstruct Mongomery_modint {\n  using\
    \ mint = Mongomery_modint;\n  inline static U1 m, r, n2;\n  static constexpr int\
    \ W = numeric_limits<U1>::digits;\n\n  static void set_mod(U1 mod) {\n    assert(mod\
    \ & 1 && mod <= U1(1) << (W - 2));\n    m = mod, n2 = -U2(m) % m, r = m;\n   \
    \ FOR(5) r *= 2 - m * r;\n    r = -r;\n    assert(r * m == U1(-1));\n  }\n  static\
    \ U1 reduce(U2 b) { return (b + U2(U1(b) * r) * m) >> W; }\n\n  U1 x;\n  Mongomery_modint()\
    \ : x(0) {}\n  Mongomery_modint(U1 x) : x(reduce(U2(x) * n2)){};\n  U1 val() const\
    \ {\n    U1 y = reduce(x);\n    return y >= m ? y - m : y;\n  }\n  mint &operator+=(mint\
    \ y) {\n    x = ((x += y.x) >= m ? x - m : x);\n    return *this;\n  }\n  mint\
    \ &operator-=(mint y) {\n    x -= (x >= y.x ? y.x : y.x - m);\n    return *this;\n\
    \  }\n  mint &operator*=(mint y) {\n    x = reduce(U2(x) * y.x);\n    return *this;\n\
    \  }\n  mint operator+(mint y) const { return mint(*this) += y; }\n  mint operator-(mint\
    \ y) const { return mint(*this) -= y; }\n  mint operator*(mint y) const { return\
    \ mint(*this) *= y; }\n  bool operator==(mint y) const {\n    return (x >= m ?\
    \ x - m : x) == (y.x >= m ? y.x - m : y.x);\n  }\n  bool operator!=(mint y) const\
    \ { return not operator==(y); }\n  mint pow(ll n) const {\n    assert(n >= 0);\n\
    \    mint y = 1, z = *this;\n    for (; n; n >>= 1, z *= z)\n      if (n & 1)\
    \ y *= z;\n    return y;\n  }\n};\n\ntemplate <int id>\nusing Mongomery_modint_32\
    \ = Mongomery_modint<id, u32, u64>;\ntemplate <int id>\nusing Mongomery_modint_64\
    \ = Mongomery_modint<id, u64, u128>;\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/mongomery_modint.hpp
  requiredBy:
  - nt/prime_test.hpp
  - graph/count/count_labeled_bipartite.hpp
  - poly/fps_sqrt.hpp
  - mod/mod_pow.hpp
  - mod/mod_sqrt.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/count_bipartite.test.cpp
  - test/2_library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/2_library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/2_library_checker/number_theory/sqrt_mod.test.cpp
  - test/2_library_checker/enumerative_combinatorics/factorial_mongomery.test.cpp
  - test/3_yukicoder/3229.test.cpp
documentation_of: mod/mongomery_modint.hpp
layout: document
redirect_from:
- /library/mod/mongomery_modint.hpp
- /library/mod/mongomery_modint.hpp.html
title: mod/mongomery_modint.hpp
---
