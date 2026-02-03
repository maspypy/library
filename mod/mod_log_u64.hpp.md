---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: mod/mod_inv_u64.hpp
    title: mod/mod_inv_u64.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://contest.ucup.ac/contest/2693/problem/15032
  bundledCode: "#line 1 \"mod/mod_inv_u64.hpp\"\nu64 mod_inv_u64(u64 a) {\n  assert(a\
    \ & 1);\n  u64 x = 1;\n  x = x * (2ULL - a * x);\n  x = x * (2ULL - a * x);\n\
    \  x = x * (2ULL - a * x);\n  x = x * (2ULL - a * x);\n  x = x * (2ULL - a * x);\n\
    \  x = x * (2ULL - a * x);\n  assert(a * x == 1);\n  return x;\n}\n#line 2 \"\
    mod/mod_log_u64.hpp\"\n\n// https://contest.ucup.ac/contest/2693/problem/15032\n\
    pair<u64, u64> mod_log_u64_primitive_root(u64 a) {\n  assert(a & 1);\n  u64 sgn\
    \ = 0;\n  if (a & 2) sgn = 1, a = -a;\n  // X=5^K mod 2^n\n  ll n = 2;\n  u64\
    \ K = 0;\n  u64 X = 1;\n  u64 Y = 5;  // pow(5,2^{n-2})\n  FOR(62) {\n    if ((X\
    \ - a) >> n & 1) {\n      K += u64(1) << (n - 2);\n      X *= Y;\n    }\n    Y\
    \ *= Y;\n    ++n;\n  }\n  return {sgn, K};\n}\n\n// find smallest n such that\
    \ a^n=b or return -1\nll mod_log_u64(u64 a, u64 b) {\n  if (a % 2 == 0) {\n  \
    \  u64 x = 1;\n    FOR(n, 65) {\n      if (x == b) return n;\n      x *= a;\n\
    \    }\n  }\n  if (a * b % 2 == 0) return -1;\n\n  auto [X1, Y1] = mod_log_u64_primitive_root(a);\n\
    \  auto [X2, Y2] = mod_log_u64_primitive_root(b);\n  /*\n  X1 * n = X2 mod 2\n\
    \  Y1 * n = Y2 mod 2^{62}\n  */\n  u64 mod = u64(1) << 62;\n  ll k = lowbit(Y1);\n\
    \  k = (k == -1 ? 62 : k);\n  if (Y2 & ((u64(1) << k) - 1)) return -1;\n  Y1 >>=\
    \ k;\n  Y2 >>= k;\n  mod >>= k;\n  u64 n = (mod == 1 ? 0 : mod_inv_u64(Y1) * Y2\
    \ % mod);\n\n  FOR(2) {\n    if (X1 * n % 2 == X2) return n;\n    n += mod;\n\
    \  }\n  return -1;\n}\n"
  code: "#include \"mod/mod_inv_u64.hpp\"\n\n// https://contest.ucup.ac/contest/2693/problem/15032\n\
    pair<u64, u64> mod_log_u64_primitive_root(u64 a) {\n  assert(a & 1);\n  u64 sgn\
    \ = 0;\n  if (a & 2) sgn = 1, a = -a;\n  // X=5^K mod 2^n\n  ll n = 2;\n  u64\
    \ K = 0;\n  u64 X = 1;\n  u64 Y = 5;  // pow(5,2^{n-2})\n  FOR(62) {\n    if ((X\
    \ - a) >> n & 1) {\n      K += u64(1) << (n - 2);\n      X *= Y;\n    }\n    Y\
    \ *= Y;\n    ++n;\n  }\n  return {sgn, K};\n}\n\n// find smallest n such that\
    \ a^n=b or return -1\nll mod_log_u64(u64 a, u64 b) {\n  if (a % 2 == 0) {\n  \
    \  u64 x = 1;\n    FOR(n, 65) {\n      if (x == b) return n;\n      x *= a;\n\
    \    }\n  }\n  if (a * b % 2 == 0) return -1;\n\n  auto [X1, Y1] = mod_log_u64_primitive_root(a);\n\
    \  auto [X2, Y2] = mod_log_u64_primitive_root(b);\n  /*\n  X1 * n = X2 mod 2\n\
    \  Y1 * n = Y2 mod 2^{62}\n  */\n  u64 mod = u64(1) << 62;\n  ll k = lowbit(Y1);\n\
    \  k = (k == -1 ? 62 : k);\n  if (Y2 & ((u64(1) << k) - 1)) return -1;\n  Y1 >>=\
    \ k;\n  Y2 >>= k;\n  mod >>= k;\n  u64 n = (mod == 1 ? 0 : mod_inv_u64(Y1) * Y2\
    \ % mod);\n\n  FOR(2) {\n    if (X1 * n % 2 == X2) return n;\n    n += mod;\n\
    \  }\n  return -1;\n}\n"
  dependsOn:
  - mod/mod_inv_u64.hpp
  isVerificationFile: false
  path: mod/mod_log_u64.hpp
  requiredBy: []
  timestamp: '2026-02-03 22:59:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/mod_log_u64.hpp
layout: document
redirect_from:
- /library/mod/mod_log_u64.hpp
- /library/mod/mod_log_u64.hpp.html
title: mod/mod_log_u64.hpp
---
