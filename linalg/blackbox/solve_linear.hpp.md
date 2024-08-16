---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/blackbox_solve_linear.test.cpp
    title: test/1_mytest/blackbox_solve_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://arxiv.org/pdf/1204.3735
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"linalg/blackbox/solve_linear.hpp\"\
    \n\n// https://arxiv.org/pdf/1204.3735\ntemplate <typename mint, typename F1,\
    \ typename F2>\nvc<mint> blackbox_solve_linear(int N, int M, F1 apply_A, F2 apply_AT,\n\
    \                               vc<mint> b) {\n  assert(len(b) == N);\n  vc<mint>\
    \ D1(M), D2(N);\n  FOR(i, M) D1[i] = RNG(0, mint::get_mod());\n  FOR(i, N) D2[i]\
    \ = RNG(0, mint::get_mod());\n  auto apply_D1 = [&](vc<mint> &v) -> void { FOR(i,\
    \ M) v[i] *= D1[i]; };\n  auto apply_D2 = [&](vc<mint> &v) -> void { FOR(i, N)\
    \ v[i] *= D2[i]; };\n  auto apply_tilde_A = [&](vc<mint> v) -> vc<mint> {\n  \
    \  apply_D1(v);\n    v = apply_A(v);\n    apply_D2(v);\n    v = apply_AT(v);\n\
    \    apply_D1(v);\n    return v;\n  };\n  vc<mint> v(M);\n  FOR(i, M) v[i] = RNG(0,\
    \ mint::get_mod());\n  vc<mint> tilde_b = apply_tilde_A(v);\n  vc<mint> c = b;\n\
    \  apply_D2(c);\n  c = apply_AT(c);\n  apply_D1(c);\n  FOR(i, M) tilde_b[i] +=\
    \ c[i];\n\n  auto dot = [&](vc<mint> &a, vc<mint> &b) -> mint {\n    mint ans\
    \ = 0;\n    FOR(i, len(a)) ans += a[i] * b[i];\n    return ans;\n  };\n  auto\
    \ is_zero = [&](vc<mint> &a) -> bool {\n    FOR(i, M) if (a[i] != mint(0)) return\
    \ false;\n    return true;\n  };\n\n  auto solve_symmetric = [&](vc<mint> b) ->\
    \ vc<mint> {\n    if (is_zero(b)) return vc<mint>(M);\n    vc<mint> w0(M), v0(M);\n\
    \    mint t0 = 1;\n    vc<mint> w1 = b, v1 = apply_tilde_A(b);\n    mint t1 =\
    \ dot(v1, w1);\n    if (t1 == mint(0)) return {};\n    vc<mint> x(M);\n    mint\
    \ c = dot(b, w1) / t1;\n    FOR(i, M) x[i] = c * w1[i];\n    while (1) {\n   \
    \   vc<mint> w2(M);\n      mint c1 = dot(v1, v1) / t1, c0 = dot(v1, v0) / t0;\n\
    \      FOR(i, M) w2[i] = v1[i] - c1 * w1[i] - c0 * w0[i];\n      if (is_zero(w2))\
    \ return x;\n      vc<mint> v2 = apply_tilde_A(w2);\n      mint t2 = dot(w2, v2);\n\
    \      if (t2 == mint(0)) return {};\n      mint c = dot(b, w2) / t2;\n      FOR(i,\
    \ M) x[i] += c * w2[i];\n      swap(v0, v1), swap(v1, v2);\n      swap(w0, w1),\
    \ swap(w1, w2);\n      swap(t0, t1), swap(t1, t2);\n    }\n  };\n\n  // tilde(A)x=tilde(b)\n\
    \  vc<mint> x = solve_symmetric(tilde_b);\n  if (x.empty()) return {};\n  FOR(i,\
    \ M) x[i] -= v[i];\n  apply_D1(x);\n\n  // check\n  if (apply_A(x) != b) return\
    \ {};\n  return x;\n}\n\n// Ax=b\ntemplate <typename mint>\nvc<mint> sparse_solve_linear(int\
    \ N, int M, vc<tuple<int, int, mint>> mat,\n                             vc<mint>\
    \ b) {\n  assert(len(b) == N);\n  auto apply = [&](vc<mint> a) -> vc<mint> {\n\
    \    assert(len(a) == M);\n    vc<mint> b(N);\n    for (auto &[i, j, x]: mat)\
    \ b[i] += a[j] * x;\n    return b;\n  };\n  auto apply_T = [&](vc<mint> a) ->\
    \ vc<mint> {\n    assert(len(a) == N);\n    vc<mint> b(M);\n    for (auto &[i,\
    \ j, x]: mat) b[j] += a[i] * x;\n    return b;\n  };\n  return blackbox_solve_linear<mint>(N,\
    \ M, apply, apply_T, b);\n}\n"
  code: "#include \"random/base.hpp\"\n\n// https://arxiv.org/pdf/1204.3735\ntemplate\
    \ <typename mint, typename F1, typename F2>\nvc<mint> blackbox_solve_linear(int\
    \ N, int M, F1 apply_A, F2 apply_AT,\n                               vc<mint>\
    \ b) {\n  assert(len(b) == N);\n  vc<mint> D1(M), D2(N);\n  FOR(i, M) D1[i] =\
    \ RNG(0, mint::get_mod());\n  FOR(i, N) D2[i] = RNG(0, mint::get_mod());\n  auto\
    \ apply_D1 = [&](vc<mint> &v) -> void { FOR(i, M) v[i] *= D1[i]; };\n  auto apply_D2\
    \ = [&](vc<mint> &v) -> void { FOR(i, N) v[i] *= D2[i]; };\n  auto apply_tilde_A\
    \ = [&](vc<mint> v) -> vc<mint> {\n    apply_D1(v);\n    v = apply_A(v);\n   \
    \ apply_D2(v);\n    v = apply_AT(v);\n    apply_D1(v);\n    return v;\n  };\n\
    \  vc<mint> v(M);\n  FOR(i, M) v[i] = RNG(0, mint::get_mod());\n  vc<mint> tilde_b\
    \ = apply_tilde_A(v);\n  vc<mint> c = b;\n  apply_D2(c);\n  c = apply_AT(c);\n\
    \  apply_D1(c);\n  FOR(i, M) tilde_b[i] += c[i];\n\n  auto dot = [&](vc<mint>\
    \ &a, vc<mint> &b) -> mint {\n    mint ans = 0;\n    FOR(i, len(a)) ans += a[i]\
    \ * b[i];\n    return ans;\n  };\n  auto is_zero = [&](vc<mint> &a) -> bool {\n\
    \    FOR(i, M) if (a[i] != mint(0)) return false;\n    return true;\n  };\n\n\
    \  auto solve_symmetric = [&](vc<mint> b) -> vc<mint> {\n    if (is_zero(b)) return\
    \ vc<mint>(M);\n    vc<mint> w0(M), v0(M);\n    mint t0 = 1;\n    vc<mint> w1\
    \ = b, v1 = apply_tilde_A(b);\n    mint t1 = dot(v1, w1);\n    if (t1 == mint(0))\
    \ return {};\n    vc<mint> x(M);\n    mint c = dot(b, w1) / t1;\n    FOR(i, M)\
    \ x[i] = c * w1[i];\n    while (1) {\n      vc<mint> w2(M);\n      mint c1 = dot(v1,\
    \ v1) / t1, c0 = dot(v1, v0) / t0;\n      FOR(i, M) w2[i] = v1[i] - c1 * w1[i]\
    \ - c0 * w0[i];\n      if (is_zero(w2)) return x;\n      vc<mint> v2 = apply_tilde_A(w2);\n\
    \      mint t2 = dot(w2, v2);\n      if (t2 == mint(0)) return {};\n      mint\
    \ c = dot(b, w2) / t2;\n      FOR(i, M) x[i] += c * w2[i];\n      swap(v0, v1),\
    \ swap(v1, v2);\n      swap(w0, w1), swap(w1, w2);\n      swap(t0, t1), swap(t1,\
    \ t2);\n    }\n  };\n\n  // tilde(A)x=tilde(b)\n  vc<mint> x = solve_symmetric(tilde_b);\n\
    \  if (x.empty()) return {};\n  FOR(i, M) x[i] -= v[i];\n  apply_D1(x);\n\n  //\
    \ check\n  if (apply_A(x) != b) return {};\n  return x;\n}\n\n// Ax=b\ntemplate\
    \ <typename mint>\nvc<mint> sparse_solve_linear(int N, int M, vc<tuple<int, int,\
    \ mint>> mat,\n                             vc<mint> b) {\n  assert(len(b) ==\
    \ N);\n  auto apply = [&](vc<mint> a) -> vc<mint> {\n    assert(len(a) == M);\n\
    \    vc<mint> b(N);\n    for (auto &[i, j, x]: mat) b[i] += a[j] * x;\n    return\
    \ b;\n  };\n  auto apply_T = [&](vc<mint> a) -> vc<mint> {\n    assert(len(a)\
    \ == N);\n    vc<mint> b(M);\n    for (auto &[i, j, x]: mat) b[j] += a[i] * x;\n\
    \    return b;\n  };\n  return blackbox_solve_linear<mint>(N, M, apply, apply_T,\
    \ b);\n}\n"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: linalg/blackbox/solve_linear.hpp
  requiredBy: []
  timestamp: '2024-06-14 05:06:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/blackbox_solve_linear.test.cpp
documentation_of: linalg/blackbox/solve_linear.hpp
layout: document
redirect_from:
- /library/linalg/blackbox/solve_linear.hpp
- /library/linalg/blackbox/solve_linear.hpp.html
title: linalg/blackbox/solve_linear.hpp
---
