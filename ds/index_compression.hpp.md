---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/coefficient_query_2d.hpp
    title: ds/offline_query/coefficient_query_2d.hpp
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/rectangle_add_rectangle_sum.hpp
    title: ds/offline_query/rectangle_add_rectangle_sum.hpp
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/index_compression.test.cpp
    title: test/1_mytest/index_compression.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_cf2d.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_cf2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/static_rectangle_add_rectangle_sum.test.cpp
    title: test/2_library_checker/data_structure/static_rectangle_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1490.test.cpp
    title: test/3_yukicoder/1490.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1600_2.test.cpp
    title: test/3_yukicoder/1600_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1625_2.test.cpp
    title: test/3_yukicoder/1625_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1919_2.test.cpp
    title: test/3_yukicoder/1919_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2859.test.cpp
    title: test/3_yukicoder/2859.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/index_compression.hpp\"\ntemplate <typename T>\nstruct\
    \ Index_Compression_DISTINCT_SMALL {\n  int mi, ma;\n  vc<T> dat;\n  vc<T> build(vc<int>\
    \ X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n\
    \    dat.assign(ma - mi + 2, 0);\n    for (auto& x : X) dat[x - mi + 1]++;\n \
    \   FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x : X) {\n    \
    \  x = dat[x - mi]++;\n    }\n    FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];\n\
    \    dat[0] = 0;\n    return X;\n  }\n  int size() const { return len(dat); }\n\
    \  int val_to_idx(T x) const { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)];\
    \ }\n  int idx_to_val(int i) const { return dat[i]; }\n};\n\ntemplate <typename\
    \ T>\nstruct Index_Compression_SAME_SMALL {\n  int mi, ma;\n  vc<T> dat;\n  vc<T>\
    \ build(vc<T> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x : X) dat[x - mi\
    \ + 1] = 1;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x\
    \ : X) {\n      x = dat[x - mi];\n    }\n    return X;\n  }\n  int size() const\
    \ { return len(dat); }\n  int val_to_idx(T x) const { return dat[clamp<ll>(x -\
    \ mi, 0, ma - mi + 1)]; }\n  int idx_to_val(int i) const { return dat[i]; }\n\
    };\n\ntemplate <typename T>\nstruct Index_Compression_SAME_LARGE {\n  vc<T> dat;\n\
    \  vc<int> build(const vc<T>& X) {\n    dat.reserve(len(X));\n    vc<pair<T, int>>\
    \ tmp(len(X));\n    FOR(i, len(X)) tmp[i] = {X[i], i};\n    sort(all(tmp));\n\
    \    vc<int> ANS(len(X));\n    for (auto [x, j] : tmp) {\n      if (dat.empty()\
    \ || dat.back() != x) dat.eb(x);\n      ANS[j] = len(dat) - 1;\n    }\n    return\
    \ ANS;\n  }\n  int size() const { return len(dat); }\n  int val_to_idx(T x) const\
    \ { return LB(dat, x); }\n  int idx_to_val(int i) const { return dat[i]; }\n};\n\
    \ntemplate <typename T>\nstruct Index_Compression_DISTINCT_LARGE {\n  vc<T> dat;\n\
    \  vc<int> build(vc<T> X) {\n    dat.reserve(len(X));\n    vc<pair<T, int>> tmp(len(X));\n\
    \    FOR(i, len(X)) tmp[i] = {X[i], i};\n    sort(all(tmp));\n    vc<int> ANS(len(X));\n\
    \    for (auto [x, j] : tmp) {\n      dat.eb(x);\n      ANS[j] = len(dat) - 1;\n\
    \    }\n    return ANS;\n  }\n  int size() const { return len(dat); }\n  int val_to_idx(T\
    \ x) const { return LB(dat, x); }\n  int idx_to_val(int i) const { return dat[i];\
    \ }\n};\n\ntemplate <typename T, bool SMALL>\nusing Index_Compression_DISTINCT\
    \ =\n    typename std::conditional<SMALL, Index_Compression_DISTINCT_SMALL<T>,\n\
    \                              Index_Compression_DISTINCT_LARGE<T>>::type;\ntemplate\
    \ <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename std::conditional<SMALL,\
    \ Index_Compression_SAME_SMALL<T>,\n                              Index_Compression_SAME_LARGE<T>>::type;\n\
    \n// SAME: [2,3,2] -> [0,1,0]\n// DISTINCT: [2,2,3] -> [0,2,1]\n// build \u3067\
    \u5217\u3092\u5727\u7E2E\u3057\u3066\u304F\u308C\u308B. \u305D\u306E\u3042\u3068\
    \n// (x): lower_bound(X,x) \u3092\u304B\u3048\u3059\ntemplate <typename T, bool\
    \ SAME, bool SMALL>\nusing Index_Compression =\n    typename std::conditional<SAME,\
    \ Index_Compression_SAME<T, SMALL>,\n                              Index_Compression_DISTINCT<T,\
    \ SMALL>>::type;\n"
  code: "template <typename T>\nstruct Index_Compression_DISTINCT_SMALL {\n  int mi,\
    \ ma;\n  vc<T> dat;\n  vc<T> build(vc<int> X) {\n    mi = 0, ma = -1;\n    if\
    \ (!X.empty()) mi = MIN(X), ma = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n  \
    \  for (auto& x : X) dat[x - mi + 1]++;\n    FOR(i, len(dat) - 1) dat[i + 1] +=\
    \ dat[i];\n    for (auto& x : X) {\n      x = dat[x - mi]++;\n    }\n    FOR_R(i,\
    \ 1, len(dat)) dat[i] = dat[i - 1];\n    dat[0] = 0;\n    return X;\n  }\n  int\
    \ size() const { return len(dat); }\n  int val_to_idx(T x) const { return dat[clamp<ll>(x\
    \ - mi, 0, ma - mi + 1)]; }\n  int idx_to_val(int i) const { return dat[i]; }\n\
    };\n\ntemplate <typename T>\nstruct Index_Compression_SAME_SMALL {\n  int mi,\
    \ ma;\n  vc<T> dat;\n  vc<T> build(vc<T> X) {\n    mi = 0, ma = -1;\n    if (!X.empty())\
    \ mi = MIN(X), ma = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x\
    \ : X) dat[x - mi + 1] = 1;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n\
    \    for (auto& x : X) {\n      x = dat[x - mi];\n    }\n    return X;\n  }\n\
    \  int size() const { return len(dat); }\n  int val_to_idx(T x) const { return\
    \ dat[clamp<ll>(x - mi, 0, ma - mi + 1)]; }\n  int idx_to_val(int i) const { return\
    \ dat[i]; }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_LARGE\
    \ {\n  vc<T> dat;\n  vc<int> build(const vc<T>& X) {\n    dat.reserve(len(X));\n\
    \    vc<pair<T, int>> tmp(len(X));\n    FOR(i, len(X)) tmp[i] = {X[i], i};\n \
    \   sort(all(tmp));\n    vc<int> ANS(len(X));\n    for (auto [x, j] : tmp) {\n\
    \      if (dat.empty() || dat.back() != x) dat.eb(x);\n      ANS[j] = len(dat)\
    \ - 1;\n    }\n    return ANS;\n  }\n  int size() const { return len(dat); }\n\
    \  int val_to_idx(T x) const { return LB(dat, x); }\n  int idx_to_val(int i) const\
    \ { return dat[i]; }\n};\n\ntemplate <typename T>\nstruct Index_Compression_DISTINCT_LARGE\
    \ {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    dat.reserve(len(X));\n    vc<pair<T,\
    \ int>> tmp(len(X));\n    FOR(i, len(X)) tmp[i] = {X[i], i};\n    sort(all(tmp));\n\
    \    vc<int> ANS(len(X));\n    for (auto [x, j] : tmp) {\n      dat.eb(x);\n \
    \     ANS[j] = len(dat) - 1;\n    }\n    return ANS;\n  }\n  int size() const\
    \ { return len(dat); }\n  int val_to_idx(T x) const { return LB(dat, x); }\n \
    \ int idx_to_val(int i) const { return dat[i]; }\n};\n\ntemplate <typename T,\
    \ bool SMALL>\nusing Index_Compression_DISTINCT =\n    typename std::conditional<SMALL,\
    \ Index_Compression_DISTINCT_SMALL<T>,\n                              Index_Compression_DISTINCT_LARGE<T>>::type;\n\
    template <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename\
    \ std::conditional<SMALL, Index_Compression_SAME_SMALL<T>,\n                 \
    \             Index_Compression_SAME_LARGE<T>>::type;\n\n// SAME: [2,3,2] -> [0,1,0]\n\
    // DISTINCT: [2,2,3] -> [0,2,1]\n// build \u3067\u5217\u3092\u5727\u7E2E\u3057\
    \u3066\u304F\u308C\u308B. \u305D\u306E\u3042\u3068\n// (x): lower_bound(X,x) \u3092\
    \u304B\u3048\u3059\ntemplate <typename T, bool SAME, bool SMALL>\nusing Index_Compression\
    \ =\n    typename std::conditional<SAME, Index_Compression_SAME<T, SMALL>,\n \
    \                             Index_Compression_DISTINCT<T, SMALL>>::type;\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/index_compression.hpp
  requiredBy:
  - ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - ds/offline_query/rectangle_add_rectangle_sum.hpp
  - ds/offline_query/coefficient_query_2d.hpp
  timestamp: '2026-08-01 03:11:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/index_compression.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_cf2d.test.cpp
  - test/2_library_checker/data_structure/static_rectangle_add_rectangle_sum.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - test/3_yukicoder/2859.test.cpp
  - test/3_yukicoder/1490.test.cpp
  - test/3_yukicoder/1625_2.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
  - test/3_yukicoder/1919_2.test.cpp
documentation_of: ds/index_compression.hpp
layout: document
redirect_from:
- /library/ds/index_compression.hpp
- /library/ds/index_compression.hpp.html
title: ds/index_compression.hpp
---
