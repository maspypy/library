---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':question:'
    path: seq/find_linear_rec.hpp
    title: seq/find_linear_rec.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: linalg/implicit_matrix/det.hpp
    title: linalg/implicit_matrix/det.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/matrix/implicit_matrix.test.cpp
    title: test/library_checker/matrix/implicit_matrix.test.cpp
  - icon: ':x:'
    path: test/yukicoder/310.test.cpp
    title: test/yukicoder/310.test.cpp
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
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"linalg/implicit_matrix/min_poly.hpp\"\
    \n\r\n// \u884C\u5217 A \u3092\u304B\u3051\u308B\u3053\u3068\u3092\u8868\u3059\
    \u7DDA\u5F62\u5909\u63DB f \u3092\u6E21\u3059\r\n// auto f = [&](vc<mint> v) ->\
    \ vc<mint> {};\r\ntemplate <typename mint, typename F>\r\nvc<mint> implicit_matrix_min_poly(int\
    \ N, F f) {\r\n  vc<mint> S(N + N + 10);\r\n  vc<mint> c(N);\r\n  vc<mint> v(N);\r\
    \n  FOR(i, N) c[i] = RNG(0, mint::get_mod());\r\n  FOR(i, N) v[i] = RNG(0, mint::get_mod());\r\
    \n  FOR(k, N + N + 10) {\r\n    FOR(i, N) S[k] += c[i] * v[i];\r\n    v = f(v);\r\
    \n  }\r\n  return find_linear_rec(S);\r\n}\r\n"
  code: "#include \"seq/find_linear_rec.hpp\"\r\n#include \"random/base.hpp\"\r\n\r\
    \n// \u884C\u5217 A \u3092\u304B\u3051\u308B\u3053\u3068\u3092\u8868\u3059\u7DDA\
    \u5F62\u5909\u63DB f \u3092\u6E21\u3059\r\n// auto f = [&](vc<mint> v) -> vc<mint>\
    \ {};\r\ntemplate <typename mint, typename F>\r\nvc<mint> implicit_matrix_min_poly(int\
    \ N, F f) {\r\n  vc<mint> S(N + N + 10);\r\n  vc<mint> c(N);\r\n  vc<mint> v(N);\r\
    \n  FOR(i, N) c[i] = RNG(0, mint::get_mod());\r\n  FOR(i, N) v[i] = RNG(0, mint::get_mod());\r\
    \n  FOR(k, N + N + 10) {\r\n    FOR(i, N) S[k] += c[i] * v[i];\r\n    v = f(v);\r\
    \n  }\r\n  return find_linear_rec(S);\r\n}\r\n"
  dependsOn:
  - seq/find_linear_rec.hpp
  - random/base.hpp
  isVerificationFile: false
  path: linalg/implicit_matrix/min_poly.hpp
  requiredBy:
  - linalg/implicit_matrix/det.hpp
  timestamp: '2022-10-23 11:21:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/matrix/implicit_matrix.test.cpp
  - test/yukicoder/310.test.cpp
documentation_of: linalg/implicit_matrix/min_poly.hpp
layout: document
redirect_from:
- /library/linalg/implicit_matrix/min_poly.hpp
- /library/linalg/implicit_matrix/min_poly.hpp.html
title: linalg/implicit_matrix/min_poly.hpp
---
