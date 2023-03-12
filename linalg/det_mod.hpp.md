---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/fast_div.hpp
    title: mod/fast_div.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: linalg/det.hpp
    title: linalg/det.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/det_mod.test.cpp
    title: test/library_checker/matrix/det_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_det.test.cpp
    title: test/library_checker/matrix/matrix_det.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/fast_div.hpp\"\nstruct fast_div {\r\n  // Min25 https://judge.yosupo.jp/submission/46090\r\
    \n  // \u540C\u3058\u5B9A\u6570\u3067\u4F55\u5EA6\u3082\u9664\u7B97\u3059\u308B\
    \u3068\u304D\u306E\u9AD8\u901F\u5316\u306B\u4F7F\u3048\u308B\r\n  using i64 =\
    \ long long;\r\n  using u64 = unsigned long long;\r\n  using u128 = __uint128_t;\r\
    \n  constexpr fast_div() : m(), s(), x() {}\r\n  constexpr fast_div(int n)\r\n\
    \      : m(n), s(std::__lg(n - 1)), x(((u128(1) << (s + 64)) + n - 1) / n) {}\r\
    \n  constexpr friend u64 operator/(u64 n, const fast_div& d) {\r\n    return (u128(n)\
    \ * d.x >> d.s) >> 64;\r\n  }\r\n  constexpr friend int operator%(u64 n, const\
    \ fast_div& d) {\r\n    return n - n / d * d.m;\r\n  }\r\n  constexpr std::pair<i64,\
    \ int> divmod(u64 n) const {\r\n    u64 q = n / *this;\r\n    return {q, n - q\
    \ * m};\r\n  }\r\n\r\n  int m;\r\n  int s;\r\n  u64 x;\r\n};\r\n#line 2 \"linalg/det_mod.hpp\"\
    \n\nint det_mod(vvc<int> A, int m) {\n  fast_div mod(m);\n  const int n = len(A);\n\
    \  ll det = 1;\n  FOR(i, n) {\n    FOR(j, i, n) {\n      if (A[j][i] == 0) continue;\n\
    \      if (i != j) { swap(A[i], A[j]), det = m - det; }\n      break;\n    }\n\
    \    FOR(j, i + 1, n) {\n      while (A[i][i] != 0) {\n        ll c = m - A[j][i]\
    \ / A[i][i];\n        FOR_R(k, i, n) { A[j][k] = (A[j][k] + A[i][k] * c) % mod;\
    \ }\n        swap(A[i], A[j]), det = m - det;\n      }\n      swap(A[i], A[j]),\
    \ det = m - det;\n    }\n  }\n  FOR(i, n) det = det * A[i][i] % mod;\n  return\
    \ det;\n}\n"
  code: "#include \"mod/fast_div.hpp\"\n\nint det_mod(vvc<int> A, int m) {\n  fast_div\
    \ mod(m);\n  const int n = len(A);\n  ll det = 1;\n  FOR(i, n) {\n    FOR(j, i,\
    \ n) {\n      if (A[j][i] == 0) continue;\n      if (i != j) { swap(A[i], A[j]),\
    \ det = m - det; }\n      break;\n    }\n    FOR(j, i + 1, n) {\n      while (A[i][i]\
    \ != 0) {\n        ll c = m - A[j][i] / A[i][i];\n        FOR_R(k, i, n) { A[j][k]\
    \ = (A[j][k] + A[i][k] * c) % mod; }\n        swap(A[i], A[j]), det = m - det;\n\
    \      }\n      swap(A[i], A[j]), det = m - det;\n    }\n  }\n  FOR(i, n) det\
    \ = det * A[i][i] % mod;\n  return det;\n}"
  dependsOn:
  - mod/fast_div.hpp
  isVerificationFile: false
  path: linalg/det_mod.hpp
  requiredBy:
  - linalg/det.hpp
  timestamp: '2022-10-23 15:28:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1303.test.cpp
  - test/library_checker/matrix/matrix_det.test.cpp
  - test/library_checker/matrix/det_mod.test.cpp
documentation_of: linalg/det_mod.hpp
layout: document
redirect_from:
- /library/linalg/det_mod.hpp
- /library/linalg/det_mod.hpp.html
title: linalg/det_mod.hpp
---
