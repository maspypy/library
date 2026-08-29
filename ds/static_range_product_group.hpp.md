---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/static_range_sum.test.cpp
    title: test/2_library_checker/data_structure/static_range_sum.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2065.test.cpp
    title: test/3_yukicoder/2065.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/924.test.cpp
    title: test/3_yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct Monoid_Add\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n\
    \  static constexpr bool commute = true;\n};\n#line 2 \"ds/static_range_product_group.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct Static_Range_Product_Group {\n  using MX\
    \ = Monoid;\n  using X = typename MX::value_type;\n  int n;\n  vc<X> dat;\n  Static_Range_Product_Group()\
    \ {}\n  template <typename F>\n  Static_Range_Product_Group(int m, F f) {\n  \
    \  build(m, f);\n  }\n  Static_Range_Product_Group(vc<X>& A) {\n    build(len(A),\
    \ [&](int i) -> X { return A[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m;\n    dat.assign(n + 1, MX::unit());\n    for (int i =\
    \ 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], f(i));\n  }\n  void build(vc<X>&\
    \ A) {\n    n = len(A);\n    dat.assign(n + 1, MX::unit());\n    for (int i =\
    \ 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], A[i]);\n  }\n  X prod(int l, int\
    \ r) const { return MX::op(MX::inverse(dat[l]), dat[r]); }\n};\n\ntemplate <typename\
    \ T>\nusing Prefix_Sum = Static_Range_Product_Group<Monoid_Add<T>>;\n"
  code: "#include \"alg/monoid/add.hpp\"\n\ntemplate <typename Monoid>\nstruct Static_Range_Product_Group\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  int n;\n  vc<X>\
    \ dat;\n  Static_Range_Product_Group() {}\n  template <typename F>\n  Static_Range_Product_Group(int\
    \ m, F f) {\n    build(m, f);\n  }\n  Static_Range_Product_Group(vc<X>& A) {\n\
    \    build(len(A), [&](int i) -> X { return A[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m;\n    dat.assign(n + 1, MX::unit());\n\
    \    for (int i = 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], f(i));\n  }\n  void\
    \ build(vc<X>& A) {\n    n = len(A);\n    dat.assign(n + 1, MX::unit());\n   \
    \ for (int i = 0; i < n; ++i) dat[i + 1] = MX::op(dat[i], A[i]);\n  }\n  X prod(int\
    \ l, int r) const { return MX::op(MX::inverse(dat[l]), dat[r]); }\n};\n\ntemplate\
    \ <typename T>\nusing Prefix_Sum = Static_Range_Product_Group<Monoid_Add<T>>;\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/static_range_product_group.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/data_structure/static_range_sum.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - test/3_yukicoder/924.test.cpp
  - test/3_yukicoder/2065.test.cpp
documentation_of: ds/static_range_product_group.hpp
layout: document
redirect_from:
- /library/ds/static_range_product_group.hpp
- /library/ds/static_range_product_group.hpp.html
title: ds/static_range_product_group.hpp
---
