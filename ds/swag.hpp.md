---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':x:'
    path: seq/interpolate_poly_exp_sum.hpp
    title: seq/interpolate_poly_exp_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
    title: test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1036_swag.test.cpp
    title: test/yukicoder/1036_swag.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/swag.hpp\"\ntemplate <class Monoid>\nstruct SWAG {\n\
    \  using X = typename Monoid::value_type;\n  using value_type = X;\n  int sz =\
    \ 0;\n  vc<X> dat;\n  vc<X> cum_l;\n  X cum_r;\n\n  SWAG() : cum_l({Monoid::unit()}),\
    \ cum_r(Monoid::unit()) {}\n\n  int size() { return sz; }\n\n  void push(X x)\
    \ {\n    ++sz;\n    cum_r = Monoid::op(cum_r, x);\n    dat.eb(x);\n  }\n\n  void\
    \ pop() {\n    --sz;\n    cum_l.pop_back();\n    if (len(cum_l) == 0) {\n    \
    \  cum_l = {Monoid::unit()};\n      cum_r = Monoid::unit();\n      while (len(dat)\
    \ > 1) {\n        cum_l.eb(Monoid::op(dat.back(), cum_l.back()));\n        dat.pop_back();\n\
    \      }\n      dat.pop_back();\n    }\n  }\n\n  X prod() { return Monoid::op(cum_l.back(),\
    \ cum_r); }\n\n  void debug() {\n    print(\"swag\");\n    print(\"dat\", dat);\n\
    \    print(\"cum_l\", cum_l);\n    print(\"cum_r\", cum_r);\n  }\n};\n"
  code: "template <class Monoid>\nstruct SWAG {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  int sz = 0;\n  vc<X> dat;\n  vc<X> cum_l;\n  X cum_r;\n\
    \n  SWAG() : cum_l({Monoid::unit()}), cum_r(Monoid::unit()) {}\n\n  int size()\
    \ { return sz; }\n\n  void push(X x) {\n    ++sz;\n    cum_r = Monoid::op(cum_r,\
    \ x);\n    dat.eb(x);\n  }\n\n  void pop() {\n    --sz;\n    cum_l.pop_back();\n\
    \    if (len(cum_l) == 0) {\n      cum_l = {Monoid::unit()};\n      cum_r = Monoid::unit();\n\
    \      while (len(dat) > 1) {\n        cum_l.eb(Monoid::op(dat.back(), cum_l.back()));\n\
    \        dat.pop_back();\n      }\n      dat.pop_back();\n    }\n  }\n\n  X prod()\
    \ { return Monoid::op(cum_l.back(), cum_r); }\n\n  void debug() {\n    print(\"\
    swag\");\n    print(\"dat\", dat);\n    print(\"cum_l\", cum_l);\n    print(\"\
    cum_r\", cum_r);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/swag.hpp
  requiredBy:
  - poly/lagrange_interpolate_iota.hpp
  - seq/interpolate_poly_exp_sum.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1036_swag.test.cpp
  - test/library_checker/datastructure/queue_operate_all_composite.test.cpp
  - test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
documentation_of: ds/swag.hpp
layout: document
redirect_from:
- /library/ds/swag.hpp
- /library/ds/swag.hpp.html
title: ds/swag.hpp
---
