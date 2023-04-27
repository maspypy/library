---
data:
  _extendedDependsOn: []
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
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
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
    path: test/library_checker/convolution/convolution_mod_107_amint.test.cpp
    title: test/library_checker/convolution/convolution_mod_107_amint.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
    title: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/inv_of_fps.test.cpp
    title: test/library_checker/polynomial/inv_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
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
    links:
    - https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp
  bundledCode: "#line 2 \"mod/barrett.hpp\"\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m) : m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64\
    \ z) {\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n    u64 y = x *\
    \ m;\n    return (u32)(z - y + (z < y ? m : 0));\n  }\n  u32 mul(u32 a, u32 b)\
    \ { return modulo(u64(a) * b); }\n};\n"
  code: "#pragma once\n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m) : m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64\
    \ z) {\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n    u64 y = x *\
    \ m;\n    return (u32)(z - y + (z < y ? m : 0));\n  }\n  u32 mul(u32 a, u32 b)\
    \ { return modulo(u64(a) * b); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: mod/barrett.hpp
  requiredBy:
  - mod/primitive_root.hpp
  - mod/mod_pow.hpp
  - mod/mod_log.hpp
  - mod/dynamic_modint.hpp
  - mod/mod_kth_root.hpp
  - nt/gaussian_integers.hpp
  - nt/four_square.hpp
  - test/library_checker/polynomial/inv_of_fps_sparse_dmint.cpp
  - test/library_checker/convolution/convolution_mod_dmint.cpp
  - poly/multivar_convolution_cyclic.hpp
  timestamp: '2023-04-27 04:51:44+09:00'
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
  - test/library_checker/convolution/convolution_mod_107_amint.test.cpp
  - test/library_checker/convolution/convolution_mod_setntt.test.cpp
  - test/mytest/four_square.test.cpp
documentation_of: mod/barrett.hpp
layout: document
redirect_from:
- /library/mod/barrett.hpp
- /library/mod/barrett.hpp.html
title: mod/barrett.hpp
---
