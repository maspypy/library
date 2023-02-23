---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linalg/spmat_min_poly.hpp
    title: linalg/spmat_min_poly.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':x:'
    path: seq/find_linear_rec.hpp
    title: seq/find_linear_rec.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/matrix/sparse_matrix_det.test.cpp
    title: test/library_checker/matrix/sparse_matrix_det.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"seq/find_linear_rec.hpp\"\n\r\ntemplate <typename mint>\r\
    \nvector<mint> find_linear_rec(vector<mint>& A) {\r\n  int N = len(A);\r\n  vc<mint>\
    \ B = {1}, C = {1};\r\n  int l = 0, m = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\
    \n    mint d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }\r\n  \
    \  if (d == 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\n    auto tmp = C;\r\
    \n    mint q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(), len(B)\
    \ + m - len(C), 0);\r\n    FOR(j, len(B)) C[j + m] -= q * B[j];\r\n    if (l +\
    \ l <= i) {\r\n      B = tmp;\r\n      l = i + 1 - l, m = 1;\r\n      p = d;\r\
    \n    } else {\r\n      ++m;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n#line 2 \"\
    random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"linalg/spmat_min_poly.hpp\"\
    \n\r\ntemplate <typename mint>\r\nvc<mint> spmat_min_poly(int N, vc<tuple<int,\
    \ int, mint>> dat) {\r\n  vc<mint> S(N + N + 10);\r\n  vc<mint> c(N);\r\n  vc<mint>\
    \ v(N);\r\n  FOR(i, N) c[i] = RNG(0, mint::get_mod());\r\n  FOR(i, N) v[i] = RNG(0,\
    \ mint::get_mod());\r\n  FOR(k, N + N + 10) {\r\n    FOR(i, N) S[k] += c[i] *\
    \ v[i];\r\n    vc<mint> w(N);\r\n    for (auto&& [i, j, x]: dat) w[j] += x * v[i];\r\
    \n    swap(v, w);\r\n  }\r\n  return find_linear_rec(S);\r\n}\r\n#line 2 \"linalg/spmat_det.hpp\"\
    \n\r\ntemplate <typename T>\r\nT spmat_det(int N, vc<tuple<int, int, T>> dat)\
    \ {\r\n  vc<T> c(N);\r\n  FOR(i, N) c[i] = RNG(1, T::get_mod());\r\n  T r = 1;\r\
    \n  FOR(i, N) r *= c[i];\r\n  for (auto&& [i, j, x]: dat) x *= c[i];\r\n  auto\
    \ f = spmat_min_poly(N, dat);\r\n  f.resize(N + 1);\r\n  T det = f.back();\r\n\
    \  if (N & 1) det *= -1;\r\n  det /= r;\r\n  return det;\r\n}\r\n"
  code: "#include \"linalg/spmat_min_poly.hpp\"\r\n\r\ntemplate <typename T>\r\nT\
    \ spmat_det(int N, vc<tuple<int, int, T>> dat) {\r\n  vc<T> c(N);\r\n  FOR(i,\
    \ N) c[i] = RNG(1, T::get_mod());\r\n  T r = 1;\r\n  FOR(i, N) r *= c[i];\r\n\
    \  for (auto&& [i, j, x]: dat) x *= c[i];\r\n  auto f = spmat_min_poly(N, dat);\r\
    \n  f.resize(N + 1);\r\n  T det = f.back();\r\n  if (N & 1) det *= -1;\r\n  det\
    \ /= r;\r\n  return det;\r\n}\r\n"
  dependsOn:
  - linalg/spmat_min_poly.hpp
  - seq/find_linear_rec.hpp
  - random/base.hpp
  isVerificationFile: false
  path: linalg/spmat_det.hpp
  requiredBy: []
  timestamp: '2022-10-23 11:21:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/matrix/sparse_matrix_det.test.cpp
documentation_of: linalg/spmat_det.hpp
layout: document
redirect_from:
- /library/linalg/spmat_det.hpp
- /library/linalg/spmat_det.hpp.html
title: linalg/spmat_det.hpp
---
