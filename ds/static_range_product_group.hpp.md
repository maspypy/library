---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/wavelet_matrix.test.cpp
    title: test/1_mytest/wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/static_range_sum.test.cpp
    title: test/2_library_checker/data_structure/static_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2065.test.cpp
    title: test/3_yukicoder/2065.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/924.test.cpp
    title: test/3_yukicoder/924.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/static_range_product_group.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct Static_Range_Product_Group {\n  using MX\
    \ = Monoid;\n  using X = typename MX::value_type;\n  int n;\n  vc<X> dat;\n  Static_Range_Product_Group()\
    \ {}\n  template <typename F>\n  Static_Range_Product_Group(int m, F f) {\n  \
    \  build(m, f);\n  }\n  template <typename F>\n  void build(int m, F f) {\n  \
    \  n = m;\n    dat.assign(n + 1, MX::unit());\n    for (int i = 0; i < n; ++i)\
    \ dat[i + 1] = MX::op(dat[i], f(i));\n  }\n  void build(vc<X>& A) {\n    n = len(A);\n\
    \    dat.assign(n + 1, MX::unit());\n    for (int i = 0; i < n; ++i) dat[i + 1]\
    \ = MX::op(dat[i], A[i]);\n  }\n  X prod(int l, int r) { return MX::op(MX::inverse(dat[l]),\
    \ dat[r]); }\n};\n\ntemplate <typename T>\nusing Prefix_Sum = Static_Range_Product_Group<Monoid_Add<T>>;\n"
  code: "#include \"alg/monoid/add.hpp\"\n\ntemplate <typename Monoid>\nstruct Static_Range_Product_Group\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  int n;\n  vc<X>\
    \ dat;\n  Static_Range_Product_Group() {}\n  template <typename F>\n  Static_Range_Product_Group(int\
    \ m, F f) {\n    build(m, f);\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m;\n    dat.assign(n + 1, MX::unit());\n    for (int i =\
    \ 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], f(i));\n  }\n  void build(vc<X>&\
    \ A) {\n    n = len(A);\n    dat.assign(n + 1, MX::unit());\n    for (int i =\
    \ 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], A[i]);\n  }\n  X prod(int l, int\
    \ r) { return MX::op(MX::inverse(dat[l]), dat[r]); }\n};\n\ntemplate <typename\
    \ T>\nusing Prefix_Sum = Static_Range_Product_Group<Monoid_Add<T>>;\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/static_range_product_group.hpp
  requiredBy: []
  timestamp: '2024-07-20 04:13:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/wavelet_matrix.test.cpp
  - test/3_yukicoder/2065.test.cpp
  - test/3_yukicoder/924.test.cpp
  - test/2_library_checker/data_structure/static_range_sum.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
documentation_of: ds/static_range_product_group.hpp
layout: document
redirect_from:
- /library/ds/static_range_product_group.hpp
- /library/ds/static_range_product_group.hpp.html
title: ds/static_range_product_group.hpp
---
