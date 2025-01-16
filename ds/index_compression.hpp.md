---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - icon: ':warning:'
    path: graph/ds/tree_wavelet_matrix.hpp
    title: graph/ds/tree_wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: string/prefix_substring_LCS.hpp
    title: string/prefix_substring_LCS.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/index_compression.test.cpp
    title: test/1_mytest/index_compression.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/wavelet_matrix.test.cpp
    title: test/1_mytest/wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
    title: test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/prefix_substring_lcs.test.cpp
    title: test/2_library_checker/string/prefix_substring_lcs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1332.test.cpp
    title: test/3_yukicoder/1332.test.cpp
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
    path: test/3_yukicoder/2065.test.cpp
    title: test/3_yukicoder/2065.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2859.test.cpp
    title: test/3_yukicoder/2859.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/919.test.cpp
    title: test/3_yukicoder/919.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/924.test.cpp
    title: test/3_yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/index_compression.hpp\"\ntemplate <typename T>\nstruct\
    \ Index_Compression_DISTINCT_SMALL {\n  static_assert(is_same_v<T, int>);\n  int\
    \ mi, ma;\n  vc<int> dat;\n  vc<int> build(vc<int> X) {\n    mi = 0, ma = -1;\n\
    \    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n\
    \    for (auto& x: X) dat[x - mi + 1]++;\n    FOR(i, len(dat) - 1) dat[i + 1]\
    \ += dat[i];\n    for (auto& x: X) { x = dat[x - mi]++; }\n    FOR_R(i, 1, len(dat))\
    \ dat[i] = dat[i - 1];\n    dat[0] = 0;\n    return X;\n  }\n  int operator()(ll\
    \ x) { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)]; }\n};\n\ntemplate <typename\
    \ T>\nstruct Index_Compression_SAME_SMALL {\n  static_assert(is_same_v<T, int>);\n\
    \  int mi, ma;\n  vc<int> dat;\n  vc<int> build(vc<int> X) {\n    mi = 0, ma =\
    \ -1;\n    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n    dat.assign(ma - mi +\
    \ 2, 0);\n    for (auto& x: X) dat[x - mi + 1] = 1;\n    FOR(i, len(dat) - 1)\
    \ dat[i + 1] += dat[i];\n    for (auto& x: X) { x = dat[x - mi]; }\n    return\
    \ X;\n  }\n  int operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi +\
    \ 1)]; }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_LARGE {\n\
    \  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n    vc<int>\
    \ res(len(X));\n    for (auto& i: I) {\n      if (!dat.empty() && dat.back() ==\
    \ X[i]) {\n        res[i] = len(dat) - 1;\n      } else {\n        res[i] = len(dat);\n\
    \        dat.eb(X[i]);\n      }\n    }\n    dat.shrink_to_fit();\n    return res;\n\
    \  }\n  int operator()(T x) { return LB(dat, x); }\n};\n\ntemplate <typename T>\n\
    struct Index_Compression_DISTINCT_LARGE {\n  vc<T> dat;\n  vc<int> build(vc<T>\
    \ X) {\n    vc<int> I = argsort(X);\n    vc<int> res(len(X));\n    for (auto&\
    \ i: I) { res[i] = len(dat), dat.eb(X[i]); }\n    dat.shrink_to_fit();\n    return\
    \ res;\n  }\n  int operator()(T x) { return LB(dat, x); }\n};\n\ntemplate <typename\
    \ T, bool SMALL>\nusing Index_Compression_DISTINCT =\n    typename std::conditional<SMALL,\
    \ Index_Compression_DISTINCT_SMALL<T>,\n                              Index_Compression_DISTINCT_LARGE<T>>::type;\n\
    template <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename\
    \ std::conditional<SMALL, Index_Compression_SAME_SMALL<T>,\n                 \
    \             Index_Compression_SAME_LARGE<T>>::type;\n\n// SAME: [2,3,2] -> [0,1,0]\n\
    // DISTINCT: [2,2,3] -> [0,2,1]\n// (x): lower_bound(X,x) \u3092\u304B\u3048\u3059\
    \ntemplate <typename T, bool SAME, bool SMALL>\nusing Index_Compression =\n  \
    \  typename std::conditional<SAME, Index_Compression_SAME<T, SMALL>,\n       \
    \                       Index_Compression_DISTINCT<T, SMALL>>::type;\n"
  code: "template <typename T>\nstruct Index_Compression_DISTINCT_SMALL {\n  static_assert(is_same_v<T,\
    \ int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int> build(vc<int> X) {\n    mi\
    \ = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n    dat.assign(ma\
    \ - mi + 2, 0);\n    for (auto& x: X) dat[x - mi + 1]++;\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1] += dat[i];\n    for (auto& x: X) { x = dat[x - mi]++; }\n  \
    \  FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];\n    dat[0] = 0;\n    return X;\n\
    \  }\n  int operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)];\
    \ }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_SMALL {\n  static_assert(is_same_v<T,\
    \ int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int> build(vc<int> X) {\n    mi\
    \ = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n    dat.assign(ma\
    \ - mi + 2, 0);\n    for (auto& x: X) dat[x - mi + 1] = 1;\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1] += dat[i];\n    for (auto& x: X) { x = dat[x - mi]; }\n    return\
    \ X;\n  }\n  int operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi +\
    \ 1)]; }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_LARGE {\n\
    \  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n    vc<int>\
    \ res(len(X));\n    for (auto& i: I) {\n      if (!dat.empty() && dat.back() ==\
    \ X[i]) {\n        res[i] = len(dat) - 1;\n      } else {\n        res[i] = len(dat);\n\
    \        dat.eb(X[i]);\n      }\n    }\n    dat.shrink_to_fit();\n    return res;\n\
    \  }\n  int operator()(T x) { return LB(dat, x); }\n};\n\ntemplate <typename T>\n\
    struct Index_Compression_DISTINCT_LARGE {\n  vc<T> dat;\n  vc<int> build(vc<T>\
    \ X) {\n    vc<int> I = argsort(X);\n    vc<int> res(len(X));\n    for (auto&\
    \ i: I) { res[i] = len(dat), dat.eb(X[i]); }\n    dat.shrink_to_fit();\n    return\
    \ res;\n  }\n  int operator()(T x) { return LB(dat, x); }\n};\n\ntemplate <typename\
    \ T, bool SMALL>\nusing Index_Compression_DISTINCT =\n    typename std::conditional<SMALL,\
    \ Index_Compression_DISTINCT_SMALL<T>,\n                              Index_Compression_DISTINCT_LARGE<T>>::type;\n\
    template <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename\
    \ std::conditional<SMALL, Index_Compression_SAME_SMALL<T>,\n                 \
    \             Index_Compression_SAME_LARGE<T>>::type;\n\n// SAME: [2,3,2] -> [0,1,0]\n\
    // DISTINCT: [2,2,3] -> [0,2,1]\n// (x): lower_bound(X,x) \u3092\u304B\u3048\u3059\
    \ntemplate <typename T, bool SAME, bool SMALL>\nusing Index_Compression =\n  \
    \  typename std::conditional<SAME, Index_Compression_SAME<T, SMALL>,\n       \
    \                       Index_Compression_DISTINCT<T, SMALL>>::type;\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/index_compression.hpp
  requiredBy:
  - string/prefix_substring_LCS.hpp
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - graph/ds/tree_wavelet_matrix.hpp
  timestamp: '2024-07-19 14:53:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/string/prefix_substring_lcs.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
  - test/3_yukicoder/919.test.cpp
  - test/3_yukicoder/924.test.cpp
  - test/3_yukicoder/1332.test.cpp
  - test/3_yukicoder/1625_2.test.cpp
  - test/3_yukicoder/2859.test.cpp
  - test/3_yukicoder/2065.test.cpp
  - test/3_yukicoder/1919_2.test.cpp
  - test/1_mytest/index_compression.test.cpp
  - test/1_mytest/wavelet_matrix.test.cpp
documentation_of: ds/index_compression.hpp
layout: document
redirect_from:
- /library/ds/index_compression.hpp
- /library/ds/index_compression.hpp.html
title: ds/index_compression.hpp
---
