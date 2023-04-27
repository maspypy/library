---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: mod/dynamic_modint.hpp
    title: mod/dynamic_modint.hpp
  - icon: ':x:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':question:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':x:'
    path: nt/four_square.hpp
    title: nt/four_square.hpp
  - icon: ':x:'
    path: nt/gaussian_integers.hpp
    title: nt/gaussian_integers.hpp
  - icon: ':x:'
    path: poly/multivar_convolution_cyclic.hpp
    title: poly/multivar_convolution_cyclic.hpp
  - icon: ':warning:'
    path: test/library_checker/convolution/convolution_mod_dmint.cpp
    title: test/library_checker/convolution/convolution_mod_dmint.cpp
  - icon: ':warning:'
    path: test/library_checker/polynomial/inv_of_fps_sparse_dmint.cpp
    title: test/library_checker/polynomial/inv_of_fps_sparse_dmint.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/convolution_mod_107_dmint.test.cpp
    title: test/library_checker/convolution/convolution_mod_107_dmint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/convolution_mod_setntt.test.cpp
    title: test/library_checker/convolution/convolution_mod_setntt.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
    title: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/primitive_root.test.cpp
    title: test/library_checker/math/primitive_root.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sqrt_mod.test.cpp
    title: test/library_checker/math/sqrt_mod.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
    title: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/inv_of_fps.test.cpp
    title: test/library_checker/polynomial/inv_of_fps.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/inv_of_fps_dmint.test.cpp
    title: test/library_checker/polynomial/inv_of_fps_dmint.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/pow_of_fps_mint.test.cpp
    title: test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - icon: ':x:'
    path: test/mytest/four_square.test.cpp
    title: test/mytest/four_square.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1025.test.cpp
    title: test/yukicoder/1025.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1593.test.cpp
    title: test/yukicoder/1593.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1667.test.cpp
    title: test/yukicoder/1667.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc222g.test.cpp
    title: test_atcoder/abc222g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc270_g.test.cpp
    title: test_atcoder/abc270_g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m) : m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64\
    \ z) {\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n    u64 y = x *\
    \ m;\n    return (u32)(z - y + (z < y ? m : 0));\n  }\n  u32 mul(u32 a, u32 b)\
    \ { return modulo(u64(a) * b); }\n};\n#line 3 \"mod/mod_pow.hpp\"\n\r\n// int\r\
    \nll mod_pow(ll a, ll n, int mod) {\r\n  a %= mod;\r\n  Barrett bt(mod);\r\n \
    \ ll p = a;\r\n  ll v = 1;\r\n  while (n) {\r\n    if (n & 1) v = bt.mul(v, p);\r\
    \n    p = bt.mul(p, p);\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n\r\nll mod_pow_long(ll\
    \ a, ll n, ll mod) {\r\n  a %= mod;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while (n)\
    \ {\r\n    if (n & 1) v = i128(v) * p % mod;\r\n    p = i128(p) * p % mod;\r\n\
    \    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n"
  code: "#pragma once\r\n#include \"mod/barrett.hpp\"\r\n\r\n// int\r\nll mod_pow(ll\
    \ a, ll n, int mod) {\r\n  a %= mod;\r\n  Barrett bt(mod);\r\n  ll p = a;\r\n\
    \  ll v = 1;\r\n  while (n) {\r\n    if (n & 1) v = bt.mul(v, p);\r\n    p = bt.mul(p,\
    \ p);\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n\r\nll mod_pow_long(ll a,\
    \ ll n, ll mod) {\r\n  a %= mod;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while (n)\
    \ {\r\n    if (n & 1) v = i128(v) * p % mod;\r\n    p = i128(p) * p % mod;\r\n\
    \    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n"
  dependsOn:
  - mod/barrett.hpp
  isVerificationFile: false
  path: mod/mod_pow.hpp
  requiredBy:
  - mod/primitive_root.hpp
  - mod/mod_log.hpp
  - mod/dynamic_modint.hpp
  - mod/mod_kth_root.hpp
  - nt/gaussian_integers.hpp
  - nt/four_square.hpp
  - test/library_checker/polynomial/inv_of_fps_sparse_dmint.cpp
  - test/library_checker/convolution/convolution_mod_dmint.cpp
  - poly/multivar_convolution_cyclic.hpp
  timestamp: '2023-04-27 04:52:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc222g.test.cpp
  - test_atcoder/abc270_g.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/yukicoder/1025.test.cpp
  - test/yukicoder/1593.test.cpp
  - test/yukicoder/1667.test.cpp
  - test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - test/library_checker/polynomial/inv_of_fps_dmint.test.cpp
  - test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - test/library_checker/polynomial/inv_of_fps.test.cpp
  - test/library_checker/math/kth_root_mod.test.cpp
  - test/library_checker/math/primitive_root.test.cpp
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - test/library_checker/convolution/convolution_mod_setntt.test.cpp
  - test/library_checker/convolution/convolution_mod_107_dmint.test.cpp
  - test/mytest/four_square.test.cpp
documentation_of: mod/mod_pow.hpp
layout: document
redirect_from:
- /library/mod/mod_pow.hpp
- /library/mod/mod_pow.hpp.html
title: mod/mod_pow.hpp
---
