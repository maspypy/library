---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/chromatic.hpp
    title: graph/chromatic.hpp
  - icon: ':heavy_check_mark:'
    path: mod/binomial.hpp
    title: mod/binomial.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':heavy_check_mark:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':heavy_check_mark:'
    path: mod/tetration.hpp
    title: mod/tetration.hpp
  - icon: ':heavy_check_mark:'
    path: nt/crt.hpp
    title: nt/crt.hpp
  - icon: ':x:'
    path: nt/divisors.hpp
    title: nt/divisors.hpp
  - icon: ':heavy_check_mark:'
    path: nt/euler_phi.hpp
    title: nt/euler_phi.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/function_on_divisors.hpp
    title: nt/function_on_divisors.hpp
  - icon: ':heavy_check_mark:'
    path: nt/gaussian_integers.hpp
    title: nt/gaussian_integers.hpp
  - icon: ':heavy_check_mark:'
    path: nt/lcm.hpp
    title: nt/lcm.hpp
  - icon: ':heavy_check_mark:'
    path: poly/multivar_convolution_cyclic.hpp
    title: poly/multivar_convolution_cyclic.hpp
  - icon: ':heavy_check_mark:'
    path: seq/famous/stirling_number_query.hpp
    title: seq/famous/stirling_number_query.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_1_C.test.cpp
    title: test/aoj/ALDS1_1_C.test.cpp
  - icon: ':x:'
    path: test/aoj/ITP1_D_D.test.cpp
    title: test/aoj/ITP1_D_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/chromatic_number.test.cpp
    title: test/library_checker/graph/chromatic_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/binomial_coefficient.test.cpp
    title: test/library_checker/math/binomial_coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/factorize.test.cpp
    title: test/library_checker/math/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
    title: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/primitive_root.test.cpp
    title: test/library_checker/math/primitive_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/stirling_mod_p_1.test.cpp
    title: test/library_checker/math/stirling_mod_p_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/stirling_mod_p_2.test.cpp
    title: test/library_checker/math/stirling_mod_p_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/tetration.test.cpp
    title: test/library_checker/math/tetration.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1025.test.cpp
    title: test/yukicoder/1025.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1262.test.cpp
    title: test/yukicoder/1262.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1411.test.cpp
    title: test/yukicoder/1411.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1593.test.cpp
    title: test/yukicoder/1593.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1728.test.cpp
    title: test/yukicoder/1728.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/187.test.cpp
    title: test/yukicoder/187.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1881.test.cpp
    title: test/yukicoder/1881.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1956.test.cpp
    title: test/yukicoder/1956.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2119.test.cpp
    title: test/yukicoder/2119.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2120.test.cpp
    title: test/yukicoder/2120.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/590.test.cpp
    title: test/yukicoder/590.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/primetest.hpp\"\nstruct m64 {\r\n  using i64 = int64_t;\r\
    \n  using u64 = uint64_t;\r\n  using u128 = __uint128_t;\r\n\r\n  inline static\
    \ u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod m)\r\n  static void\
    \ set_mod(u64 m) {\r\n    assert(m < (1ull << 62));\r\n    assert((m & 1) == 1);\r\
    \n    m64::m = m;\r\n    n2 = -u128(m) % m;\r\n    r = m;\r\n    FOR(_, 5) r *=\
    \ 2 - m * r;\r\n    r = -r;\r\n    assert(r * m == -1ull);\r\n  }\r\n  static\
    \ u64 reduce(u128 b) { return (b + u128(u64(b) * r) * m) >> 64; }\r\n\r\n  u64\
    \ x;\r\n  m64() : x(0) {}\r\n  m64(u64 x) : x(reduce(u128(x) * n2)){};\r\n  u64\
    \ val() const {\r\n    u64 y = reduce(x);\r\n    return y >= m ? y - m : y;\r\n\
    \  }\r\n  m64 &operator+=(m64 y) {\r\n    x += y.x - (m << 1);\r\n    x = (i64(x)\
    \ < 0 ? x + (m << 1) : x);\r\n    return *this;\r\n  }\r\n  m64 &operator-=(m64\
    \ y) {\r\n    x -= y.x;\r\n    x = (i64(x) < 0 ? x + (m << 1) : x);\r\n    return\
    \ *this;\r\n  }\r\n  m64 &operator*=(m64 y) {\r\n    x = reduce(u128(x) * y.x);\r\
    \n    return *this;\r\n  }\r\n  m64 operator+(m64 y) const { return m64(*this)\
    \ += y; }\r\n  m64 operator-(m64 y) const { return m64(*this) -= y; }\r\n  m64\
    \ operator*(m64 y) const { return m64(*this) *= y; }\r\n  bool operator==(m64\
    \ y) const {\r\n    return (x >= m ? x - m : x) == (y.x >= m ? y.x - m : y.x);\r\
    \n  }\r\n  bool operator!=(m64 y) const { return not operator==(y); }\r\n  m64\
    \ pow(u64 n) const {\r\n    m64 y = 1, z = *this;\r\n    for (; n; n >>= 1, z\
    \ *= z)\r\n      if (n & 1) y *= z;\r\n    return y;\r\n  }\r\n};\r\n\r\nbool\
    \ primetest(const uint64_t x) {\r\n  using u64 = uint64_t;\r\n  if (x == 2 or\
    \ x == 3 or x == 5 or x == 7) return true;\r\n  if (x % 2 == 0 or x % 3 == 0 or\
    \ x % 5 == 0 or x % 7 == 0) return false;\r\n  if (x < 121) return x > 1;\r\n\
    \  const u64 d = (x - 1) >> __builtin_ctzll(x - 1);\r\n  m64::set_mod(x);\r\n\
    \  const m64 one(1), minus_one(x - 1);\r\n  auto ok = [&](u64 a) {\r\n    auto\
    \ y = m64(a).pow(d);\r\n    u64 t = d;\r\n    while (y != one and y != minus_one\
    \ and t != x - 1) y *= y, t <<= 1;\r\n    if (y != minus_one and t % 2 == 0) return\
    \ false;\r\n    return true;\r\n  };\r\n  if (x < (1ull << 32)) {\r\n    for (u64\
    \ a: {2, 7, 61})\r\n      if (not ok(a)) return false;\r\n  } else {\r\n    for\
    \ (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\r\n      if (x\
    \ <= a) return true;\r\n      if (not ok(a)) return false;\r\n    }\r\n  }\r\n\
    \  return true;\r\n}\n"
  code: "#pragma once\r\nstruct m64 {\r\n  using i64 = int64_t;\r\n  using u64 = uint64_t;\r\
    \n  using u128 = __uint128_t;\r\n\r\n  inline static u64 m, r, n2; // r * m =\
    \ -1 (mod 1<<64), n2 = 1<<128 (mod m)\r\n  static void set_mod(u64 m) {\r\n  \
    \  assert(m < (1ull << 62));\r\n    assert((m & 1) == 1);\r\n    m64::m = m;\r\
    \n    n2 = -u128(m) % m;\r\n    r = m;\r\n    FOR(_, 5) r *= 2 - m * r;\r\n  \
    \  r = -r;\r\n    assert(r * m == -1ull);\r\n  }\r\n  static u64 reduce(u128 b)\
    \ { return (b + u128(u64(b) * r) * m) >> 64; }\r\n\r\n  u64 x;\r\n  m64() : x(0)\
    \ {}\r\n  m64(u64 x) : x(reduce(u128(x) * n2)){};\r\n  u64 val() const {\r\n \
    \   u64 y = reduce(x);\r\n    return y >= m ? y - m : y;\r\n  }\r\n  m64 &operator+=(m64\
    \ y) {\r\n    x += y.x - (m << 1);\r\n    x = (i64(x) < 0 ? x + (m << 1) : x);\r\
    \n    return *this;\r\n  }\r\n  m64 &operator-=(m64 y) {\r\n    x -= y.x;\r\n\
    \    x = (i64(x) < 0 ? x + (m << 1) : x);\r\n    return *this;\r\n  }\r\n  m64\
    \ &operator*=(m64 y) {\r\n    x = reduce(u128(x) * y.x);\r\n    return *this;\r\
    \n  }\r\n  m64 operator+(m64 y) const { return m64(*this) += y; }\r\n  m64 operator-(m64\
    \ y) const { return m64(*this) -= y; }\r\n  m64 operator*(m64 y) const { return\
    \ m64(*this) *= y; }\r\n  bool operator==(m64 y) const {\r\n    return (x >= m\
    \ ? x - m : x) == (y.x >= m ? y.x - m : y.x);\r\n  }\r\n  bool operator!=(m64\
    \ y) const { return not operator==(y); }\r\n  m64 pow(u64 n) const {\r\n    m64\
    \ y = 1, z = *this;\r\n    for (; n; n >>= 1, z *= z)\r\n      if (n & 1) y *=\
    \ z;\r\n    return y;\r\n  }\r\n};\r\n\r\nbool primetest(const uint64_t x) {\r\
    \n  using u64 = uint64_t;\r\n  if (x == 2 or x == 3 or x == 5 or x == 7) return\
    \ true;\r\n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return\
    \ false;\r\n  if (x < 121) return x > 1;\r\n  const u64 d = (x - 1) >> __builtin_ctzll(x\
    \ - 1);\r\n  m64::set_mod(x);\r\n  const m64 one(1), minus_one(x - 1);\r\n  auto\
    \ ok = [&](u64 a) {\r\n    auto y = m64(a).pow(d);\r\n    u64 t = d;\r\n    while\
    \ (y != one and y != minus_one and t != x - 1) y *= y, t <<= 1;\r\n    if (y !=\
    \ minus_one and t % 2 == 0) return false;\r\n    return true;\r\n  };\r\n  if\
    \ (x < (1ull << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if (not ok(a))\
    \ return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\r\n      if (x <= a) return true;\r\n      if (not ok(a))\
    \ return false;\r\n    }\r\n  }\r\n  return true;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/primetest.hpp
  requiredBy:
  - poly/multivar_convolution_cyclic.hpp
  - graph/chromatic.hpp
  - nt/function_on_divisors.hpp
  - nt/gaussian_integers.hpp
  - nt/euler_phi.hpp
  - nt/crt.hpp
  - nt/lcm.hpp
  - nt/divisors.hpp
  - nt/factor.hpp
  - mod/tetration.hpp
  - mod/binomial.hpp
  - mod/mod_kth_root.hpp
  - mod/primitive_root.hpp
  - seq/famous/stirling_number_query.hpp
  timestamp: '2022-04-27 05:09:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/NTL_1_D.test.cpp
  - test/aoj/ALDS1_1_C.test.cpp
  - test/aoj/ITP1_D_D.test.cpp
  - test/yukicoder/1025.test.cpp
  - test/yukicoder/590.test.cpp
  - test/yukicoder/2120.test.cpp
  - test/yukicoder/1262.test.cpp
  - test/yukicoder/1593.test.cpp
  - test/yukicoder/187.test.cpp
  - test/yukicoder/1728.test.cpp
  - test/yukicoder/1956.test.cpp
  - test/yukicoder/1881.test.cpp
  - test/yukicoder/1411.test.cpp
  - test/yukicoder/2119.test.cpp
  - test/library_checker/graph/chromatic_number.test.cpp
  - test/library_checker/math/kth_root_mod.test.cpp
  - test/library_checker/math/factorize.test.cpp
  - test/library_checker/math/stirling_mod_p_1.test.cpp
  - test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - test/library_checker/math/primitive_root.test.cpp
  - test/library_checker/math/binomial_coefficient.test.cpp
  - test/library_checker/math/stirling_mod_p_2.test.cpp
  - test/library_checker/math/tetration.test.cpp
documentation_of: nt/primetest.hpp
layout: document
redirect_from:
- /library/nt/primetest.hpp
- /library/nt/primetest.hpp.html
title: nt/primetest.hpp
---
