---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':heavy_check_mark:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
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
    path: test/yukicoder/1117.test.cpp
    title: test/yukicoder/1117.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1435_2.test.cpp
    title: test/yukicoder/1435_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/502_2.test.cpp
    title: test/yukicoder/502_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/swag.hpp\"\n\ntemplate <class Monoid>\nstruct SWAG {\n\
    \  using X = typename Monoid::value_type;\n  using value_type = X;\n  int sz;\n\
    \  vc<X> dat_l, dat_r;\n  vc<X> cum_l, cum_r;\n\n  SWAG() : sz(0), cum_l({Monoid::unit()}),\
    \ cum_r({Monoid::unit()}) {}\n\n  int size() { return sz; }\n\n  void push_back(X\
    \ x) {\n    ++sz;\n    dat_r.eb(x);\n    cum_r.eb(Monoid::op(cum_r.back(), x));\n\
    \  }\n\n  void push_front(X x) {\n    ++sz;\n    dat_l.eb(x);\n    cum_l.eb(Monoid::op(x,\
    \ cum_l.back()));\n  }\n\n  void push(X x) { push_back(x); }\n\n  void clear()\
    \ {\n    sz = 0;\n    dat_l.clear(), dat_r.clear();\n    cum_l = {Monoid::unit()},\
    \ cum_r = {Monoid::unit()};\n  }\n\n  void pop_front() {\n    if (sz == 1) return\
    \ clear();\n    if (dat_l.empty()) rebuild();\n    --sz;\n    dat_l.pop_back();\n\
    \    cum_l.pop_back();\n  }\n\n  void pop_back() {\n    if (sz == 1) return clear();\n\
    \    if (dat_r.empty()) rebuild();\n    --sz;\n    dat_r.pop_back();\n    cum_r.pop_back();\n\
    \  }\n  \n  void pop() { pop_front(); }\n\n  void rebuild() {\n    vc<X> X;\n\
    \    FOR_R(i, len(dat_l)) X.eb(dat_l[i]);\n    X.insert(X.end(), all(dat_r));\n\
    \    clear();\n    int m = len(X) / 2;\n    FOR_R(i, m) push_front(X[i]);\n  \
    \  FOR(i, m, len(X)) push_back(X[i]);\n    assert(sz == len(X));\n  }\n\n  X lprod()\
    \ { return cum_l.back(); }\n  X rprod() { return cum_r.back(); }\n  X prod() {\
    \ return Monoid::op(cum_l.back(), cum_r.back()); }\n  X prod_all() { return prod();\
    \ }\n\n  void debug() {\n    print(\"swag\");\n    print(\"dat_l\", dat_l);\n\
    \    print(\"dat_r\", dat_r);\n    print(\"cum_l\", cum_l);\n    print(\"cum_r\"\
    , cum_r);\n  }\n};\n"
  code: "\ntemplate <class Monoid>\nstruct SWAG {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  int sz;\n  vc<X> dat_l, dat_r;\n  vc<X> cum_l, cum_r;\n\
    \n  SWAG() : sz(0), cum_l({Monoid::unit()}), cum_r({Monoid::unit()}) {}\n\n  int\
    \ size() { return sz; }\n\n  void push_back(X x) {\n    ++sz;\n    dat_r.eb(x);\n\
    \    cum_r.eb(Monoid::op(cum_r.back(), x));\n  }\n\n  void push_front(X x) {\n\
    \    ++sz;\n    dat_l.eb(x);\n    cum_l.eb(Monoid::op(x, cum_l.back()));\n  }\n\
    \n  void push(X x) { push_back(x); }\n\n  void clear() {\n    sz = 0;\n    dat_l.clear(),\
    \ dat_r.clear();\n    cum_l = {Monoid::unit()}, cum_r = {Monoid::unit()};\n  }\n\
    \n  void pop_front() {\n    if (sz == 1) return clear();\n    if (dat_l.empty())\
    \ rebuild();\n    --sz;\n    dat_l.pop_back();\n    cum_l.pop_back();\n  }\n\n\
    \  void pop_back() {\n    if (sz == 1) return clear();\n    if (dat_r.empty())\
    \ rebuild();\n    --sz;\n    dat_r.pop_back();\n    cum_r.pop_back();\n  }\n \
    \ \n  void pop() { pop_front(); }\n\n  void rebuild() {\n    vc<X> X;\n    FOR_R(i,\
    \ len(dat_l)) X.eb(dat_l[i]);\n    X.insert(X.end(), all(dat_r));\n    clear();\n\
    \    int m = len(X) / 2;\n    FOR_R(i, m) push_front(X[i]);\n    FOR(i, m, len(X))\
    \ push_back(X[i]);\n    assert(sz == len(X));\n  }\n\n  X lprod() { return cum_l.back();\
    \ }\n  X rprod() { return cum_r.back(); }\n  X prod() { return Monoid::op(cum_l.back(),\
    \ cum_r.back()); }\n  X prod_all() { return prod(); }\n\n  void debug() {\n  \
    \  print(\"swag\");\n    print(\"dat_l\", dat_l);\n    print(\"dat_r\", dat_r);\n\
    \    print(\"cum_l\", cum_l);\n    print(\"cum_r\", cum_r);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/swag.hpp
  requiredBy:
  - poly/prefix_product_of_poly.hpp
  - poly/lagrange_interpolate_iota.hpp
  - seq/kth_term_of_p_recursive.hpp
  - seq/interpolate_poly_exp_sum.hpp
  timestamp: '2022-08-21 00:15:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1117.test.cpp
  - test/yukicoder/1435_2.test.cpp
  - test/yukicoder/1036_3.test.cpp
  - test/yukicoder/502_2.test.cpp
  - test/mytest/factorial_998.test.cpp
  - test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - test/library_checker/datastructure/queue_operate_all_composite.test.cpp
documentation_of: ds/swag.hpp
layout: document
redirect_from:
- /library/ds/swag.hpp
- /library/ds/swag.hpp.html
title: ds/swag.hpp
---
