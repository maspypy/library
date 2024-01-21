---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: poly/from_log_differentiation.hpp
    title: poly/from_log_differentiation.hpp
  - icon: ':heavy_check_mark:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':heavy_check_mark:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':heavy_check_mark:'
    path: poly/sparse_exp_of_div.hpp
    title: poly/sparse_exp_of_div.hpp
  - icon: ':heavy_check_mark:'
    path: poly/sum_of_C_negative.hpp
    title: poly/sum_of_C_negative.hpp
  - icon: ':heavy_check_mark:'
    path: seq/interpolate_poly_exp_sum.hpp
    title: seq/interpolate_poly_exp_sum.hpp
  - icon: ':heavy_check_mark:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
    title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/factorial.test.cpp
    title: test/library_checker/math/factorial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/factorial_998.test.cpp
    title: test/mytest/factorial_998.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1036_3.test.cpp
    title: test/yukicoder/1036_3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1080_2.test.cpp
    title: test/yukicoder/1080_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1117.test.cpp
    title: test/yukicoder/1117.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1435_2.test.cpp
    title: test/yukicoder/1435_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2026.test.cpp
    title: test/yukicoder/2026.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2166.test.cpp
    title: test/yukicoder/2166.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/502_2.test.cpp
    title: test/yukicoder/502_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc222h_2.test.cpp
    title: test_atcoder/abc222h_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc276_g.test.cpp
    title: test_atcoder/abc276_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc276_g_2.test.cpp
    title: test_atcoder/abc276_g_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/arc144d.test.cpp
    title: test_atcoder/arc144d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/arc160d.test.cpp
    title: test_atcoder/arc160d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/sliding_window_aggregation.hpp\"\ntemplate <class Monoid>\n\
    struct Sliding_Window_Aggregation {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  int sz = 0;\n  vc<X> dat;\n  vc<X> cum_l;\n  X cum_r;\n\
    \n  Sliding_Window_Aggregation()\n      : cum_l({Monoid::unit()}), cum_r(Monoid::unit())\
    \ {}\n\n  int size() { return sz; }\n\n  void push(X x) {\n    ++sz;\n    cum_r\
    \ = Monoid::op(cum_r, x);\n    dat.eb(x);\n  }\n\n  void pop() {\n    --sz;\n\
    \    cum_l.pop_back();\n    if (len(cum_l) == 0) {\n      cum_l = {Monoid::unit()};\n\
    \      cum_r = Monoid::unit();\n      while (len(dat) > 1) {\n        cum_l.eb(Monoid::op(dat.back(),\
    \ cum_l.back()));\n        dat.pop_back();\n      }\n      dat.pop_back();\n \
    \   }\n  }\n\n  X lprod() { return cum_l.back(); }\n  X rprod() { return cum_r;\
    \ }\n\n  X prod() { return Monoid::op(cum_l.back(), cum_r); }\n};\n\n// \u5B9A\
    \u6570\u500D\u306F\u76EE\u306B\u898B\u3048\u3066\u9045\u304F\u306A\u308B\u306E\
    \u3067\u3001queue \u3067\u3088\u3044\u3068\u304D\u306F\u4F7F\u308F\u306A\u3044\
    \ntemplate <class Monoid>\nstruct SWAG_deque {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  int sz;\n  vc<X> dat_l, dat_r;\n  vc<X> cum_l, cum_r;\n\
    \n  SWAG_deque() : sz(0), cum_l({Monoid::unit()}), cum_r({Monoid::unit()}) {}\n\
    \n  int size() { return sz; }\n\n  void push_back(X x) {\n    ++sz;\n    dat_r.eb(x);\n\
    \    cum_r.eb(Monoid::op(cum_r.back(), x));\n  }\n\n  void push_front(X x) {\n\
    \    ++sz;\n    dat_l.eb(x);\n    cum_l.eb(Monoid::op(x, cum_l.back()));\n  }\n\
    \n  void push(X x) { push_back(x); }\n\n  void clear() {\n    sz = 0;\n    dat_l.clear(),\
    \ dat_r.clear();\n    cum_l = {Monoid::unit()}, cum_r = {Monoid::unit()};\n  }\n\
    \n  void pop_front() {\n    if (sz == 1) return clear();\n    if (dat_l.empty())\
    \ rebuild();\n    --sz;\n    dat_l.pop_back();\n    cum_l.pop_back();\n  }\n\n\
    \  void pop_back() {\n    if (sz == 1) return clear();\n    if (dat_r.empty())\
    \ rebuild();\n    --sz;\n    dat_r.pop_back();\n    cum_r.pop_back();\n  }\n\n\
    \  void pop() { pop_front(); }\n\n  X lprod() { return cum_l.back(); }\n  X rprod()\
    \ { return cum_r.back(); }\n  X prod() { return Monoid::op(cum_l.back(), cum_r.back());\
    \ }\n  X prod_all() { return prod(); }\n\nprivate:\n  void rebuild() {\n    vc<X>\
    \ X;\n    FOR_R(i, len(dat_l)) X.eb(dat_l[i]);\n    X.insert(X.end(), all(dat_r));\n\
    \    clear();\n    int m = len(X) / 2;\n    FOR_R(i, m) push_front(X[i]);\n  \
    \  FOR(i, m, len(X)) push_back(X[i]);\n    assert(sz == len(X));\n  }\n};\n"
  code: "template <class Monoid>\nstruct Sliding_Window_Aggregation {\n  using X =\
    \ typename Monoid::value_type;\n  using value_type = X;\n  int sz = 0;\n  vc<X>\
    \ dat;\n  vc<X> cum_l;\n  X cum_r;\n\n  Sliding_Window_Aggregation()\n      :\
    \ cum_l({Monoid::unit()}), cum_r(Monoid::unit()) {}\n\n  int size() { return sz;\
    \ }\n\n  void push(X x) {\n    ++sz;\n    cum_r = Monoid::op(cum_r, x);\n    dat.eb(x);\n\
    \  }\n\n  void pop() {\n    --sz;\n    cum_l.pop_back();\n    if (len(cum_l) ==\
    \ 0) {\n      cum_l = {Monoid::unit()};\n      cum_r = Monoid::unit();\n     \
    \ while (len(dat) > 1) {\n        cum_l.eb(Monoid::op(dat.back(), cum_l.back()));\n\
    \        dat.pop_back();\n      }\n      dat.pop_back();\n    }\n  }\n\n  X lprod()\
    \ { return cum_l.back(); }\n  X rprod() { return cum_r; }\n\n  X prod() { return\
    \ Monoid::op(cum_l.back(), cum_r); }\n};\n\n// \u5B9A\u6570\u500D\u306F\u76EE\u306B\
    \u898B\u3048\u3066\u9045\u304F\u306A\u308B\u306E\u3067\u3001queue \u3067\u3088\
    \u3044\u3068\u304D\u306F\u4F7F\u308F\u306A\u3044\ntemplate <class Monoid>\nstruct\
    \ SWAG_deque {\n  using X = typename Monoid::value_type;\n  using value_type =\
    \ X;\n  int sz;\n  vc<X> dat_l, dat_r;\n  vc<X> cum_l, cum_r;\n\n  SWAG_deque()\
    \ : sz(0), cum_l({Monoid::unit()}), cum_r({Monoid::unit()}) {}\n\n  int size()\
    \ { return sz; }\n\n  void push_back(X x) {\n    ++sz;\n    dat_r.eb(x);\n   \
    \ cum_r.eb(Monoid::op(cum_r.back(), x));\n  }\n\n  void push_front(X x) {\n  \
    \  ++sz;\n    dat_l.eb(x);\n    cum_l.eb(Monoid::op(x, cum_l.back()));\n  }\n\n\
    \  void push(X x) { push_back(x); }\n\n  void clear() {\n    sz = 0;\n    dat_l.clear(),\
    \ dat_r.clear();\n    cum_l = {Monoid::unit()}, cum_r = {Monoid::unit()};\n  }\n\
    \n  void pop_front() {\n    if (sz == 1) return clear();\n    if (dat_l.empty())\
    \ rebuild();\n    --sz;\n    dat_l.pop_back();\n    cum_l.pop_back();\n  }\n\n\
    \  void pop_back() {\n    if (sz == 1) return clear();\n    if (dat_r.empty())\
    \ rebuild();\n    --sz;\n    dat_r.pop_back();\n    cum_r.pop_back();\n  }\n\n\
    \  void pop() { pop_front(); }\n\n  X lprod() { return cum_l.back(); }\n  X rprod()\
    \ { return cum_r.back(); }\n  X prod() { return Monoid::op(cum_l.back(), cum_r.back());\
    \ }\n  X prod_all() { return prod(); }\n\nprivate:\n  void rebuild() {\n    vc<X>\
    \ X;\n    FOR_R(i, len(dat_l)) X.eb(dat_l[i]);\n    X.insert(X.end(), all(dat_r));\n\
    \    clear();\n    int m = len(X) / 2;\n    FOR_R(i, m) push_front(X[i]);\n  \
    \  FOR(i, m, len(X)) push_back(X[i]);\n    assert(sz == len(X));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/sliding_window_aggregation.hpp
  requiredBy:
  - seq/kth_term_of_p_recursive.hpp
  - seq/interpolate_poly_exp_sum.hpp
  - poly/from_log_differentiation.hpp
  - poly/sparse_exp_of_div.hpp
  - poly/lagrange_interpolate_iota.hpp
  - poly/prefix_product_of_poly.hpp
  - poly/sum_of_C_negative.hpp
  timestamp: '2023-11-10 12:47:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - test/library_checker/math/factorial.test.cpp
  - test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - test/mytest/factorial_998.test.cpp
  - test/yukicoder/1080_2.test.cpp
  - test/yukicoder/2026.test.cpp
  - test/yukicoder/2166.test.cpp
  - test/yukicoder/1435_2.test.cpp
  - test/yukicoder/1036_3.test.cpp
  - test/yukicoder/1117.test.cpp
  - test/yukicoder/502_2.test.cpp
  - test_atcoder/arc160d.test.cpp
  - test_atcoder/arc144d.test.cpp
  - test_atcoder/abc276_g.test.cpp
  - test_atcoder/abc276_g_2.test.cpp
  - test_atcoder/abc222h_2.test.cpp
documentation_of: ds/sliding_window_aggregation.hpp
layout: document
redirect_from:
- /library/ds/sliding_window_aggregation.hpp
- /library/ds/sliding_window_aggregation.hpp.html
title: ds/sliding_window_aggregation.hpp
---