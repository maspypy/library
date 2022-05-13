---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/monoid_rollinghash.hpp
    title: alg/monoid_rollinghash.hpp
  - icon: ':heavy_check_mark:'
    path: graph/chromatic.hpp
    title: graph/chromatic.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/spmat_det.hpp
    title: linalg/spmat_det.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/spmat_min_poly.hpp
    title: linalg/spmat_min_poly.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
  - icon: ':x:'
    path: mod/modular_subset_sum.hpp
    title: mod/modular_subset_sum.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: string/rollinghash.hpp
    title: string/rollinghash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/chromatic_number.test.cpp
    title: test/library_checker/graph/chromatic_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sqrt_mod.test.cpp
    title: test/library_checker/math/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/sparse_matrix_det.test.cpp
    title: test/library_checker/matrix/sparse_matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - icon: ':x:'
    path: test/yukicoder/4_modular_subset_sum.test.cpp
    title: test/yukicoder/4_modular_subset_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/random.hpp\"\nstruct RandomNumberGenerator {\n  mt19937\
    \ mt;\n\n  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n  ll operator()(ll a, ll b) {  // [a, b)\n    uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n    return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0,\
    \ b)\n    return (*this)(0, b);\n  }\n};\n"
  code: "struct RandomNumberGenerator {\n  mt19937 mt;\n\n  RandomNumberGenerator()\
    \ : mt(chrono::steady_clock::now().time_since_epoch().count()) {}\n\n  ll operator()(ll\
    \ a, ll b) {  // [a, b)\n    uniform_int_distribution<ll> dist(a, b - 1);\n  \
    \  return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0, b)\n    return (*this)(0,\
    \ b);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/random.hpp
  requiredBy:
  - alg/monoid_rollinghash.hpp
  - mod/modular_subset_sum.hpp
  - mod/mod_sqrt.hpp
  - graph/chromatic.hpp
  - string/rollinghash.hpp
  - linalg/spmat_min_poly.hpp
  - linalg/spmat_det.hpp
  - poly/fps_sqrt.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/4_modular_subset_sum.test.cpp
  - test/library_checker/matrix/sparse_matrix_det.test.cpp
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/graph/chromatic_number.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
documentation_of: other/random.hpp
layout: document
redirect_from:
- /library/other/random.hpp
- /library/other/random.hpp.html
title: other/random.hpp
---
