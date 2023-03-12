---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: nt/four_square.hpp
    title: nt/four_square.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sqrt_mod.test.cpp
    title: test/library_checker/math/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - icon: ':x:'
    path: test/mytest/four_square.test.cpp
    title: test/mytest/four_square.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/mod_sqrt.hpp\"\
    \n\r\ntemplate <typename mint>\r\nmint mod_sqrt(mint a) {\r\n  int p = mint::get_mod();\r\
    \n  if (p == 2) return a;\r\n  if (a == 0) return 0;\r\n  int k = (p - 1) / 2;\r\
    \n  if (a.pow(k) != 1) return 0;\r\n  auto find = [&]() -> pair<mint, mint> {\r\
    \n    while (1) {\r\n      mint b = RNG(2, p);\r\n      mint D = b * b - a;\r\n\
    \      if (D == 0) return {b, D};\r\n      if (D.pow(k) != mint(1)) return {b,\
    \ D};\r\n    }\r\n  };\r\n  auto [b, D] = find();\r\n  if (D == 0) return b;\r\
    \n  ++k;\r\n  // (b + sqrt(D))^k\r\n  mint f0 = b, f1 = 1;\r\n  mint g0 = 1, g1\
    \ = 0;\r\n  while (k) {\r\n    if (k & 1) { tie(g0, g1) = mp(f0 * g0 + D * f1\
    \ * g1, f1 * g0 + f0 * g1); }\r\n    tie(f0, f1) = mp(f0 * f0 + D * f1 * f1, mint(2)\
    \ * f0 * f1);\r\n    k >>= 1;\r\n  }\r\n  return g0;\r\n}\r\n"
  code: "#include \"random/base.hpp\"\r\n\r\ntemplate <typename mint>\r\nmint mod_sqrt(mint\
    \ a) {\r\n  int p = mint::get_mod();\r\n  if (p == 2) return a;\r\n  if (a ==\
    \ 0) return 0;\r\n  int k = (p - 1) / 2;\r\n  if (a.pow(k) != 1) return 0;\r\n\
    \  auto find = [&]() -> pair<mint, mint> {\r\n    while (1) {\r\n      mint b\
    \ = RNG(2, p);\r\n      mint D = b * b - a;\r\n      if (D == 0) return {b, D};\r\
    \n      if (D.pow(k) != mint(1)) return {b, D};\r\n    }\r\n  };\r\n  auto [b,\
    \ D] = find();\r\n  if (D == 0) return b;\r\n  ++k;\r\n  // (b + sqrt(D))^k\r\n\
    \  mint f0 = b, f1 = 1;\r\n  mint g0 = 1, g1 = 0;\r\n  while (k) {\r\n    if (k\
    \ & 1) { tie(g0, g1) = mp(f0 * g0 + D * f1 * g1, f1 * g0 + f0 * g1); }\r\n   \
    \ tie(f0, f1) = mp(f0 * f0 + D * f1 * f1, mint(2) * f0 * f1);\r\n    k >>= 1;\r\
    \n  }\r\n  return g0;\r\n}\r\n"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: mod/mod_sqrt.hpp
  requiredBy:
  - poly/fps_sqrt.hpp
  - nt/four_square.hpp
  timestamp: '2023-03-12 12:41:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/four_square.test.cpp
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
documentation_of: mod/mod_sqrt.hpp
layout: document
redirect_from:
- /library/mod/mod_sqrt.hpp
- /library/mod/mod_sqrt.hpp.html
title: mod/mod_sqrt.hpp
---
