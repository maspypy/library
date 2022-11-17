---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/max_of_linear_segments.hpp
    title: mod/max_of_linear_segments.hpp
  - icon: ':heavy_check_mark:'
    path: mod/min_of_linear.hpp
    title: mod/min_of_linear.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/min_of_mod_of_linear.test.cpp
    title: test/library_checker/math/min_of_mod_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_of_linear_segments.test.cpp
    title: test/mytest/max_of_linear_segments.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/min_of_linear_segments.test.cpp
    title: test/mytest/min_of_linear_segments.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/min_of_linear_segments.hpp\"\n\n/*\nax + b (x>=0) \u304C\
    \u6700\u5C0F\u3068\u306A\u308B\u3068\u3053\u308D\u306E\u60C5\u5831\u3092\u8FD4\
    \u3059\u3002\nprefix min \u3092\u66F4\u65B0\u3059\u308B x \u5168\u4F53\u304C\u3001\
    \u7B49\u5DEE\u6570\u5217\u306E\u548C\u96C6\u5408\u3002\u6B21\u3092\u8FD4\u3059\
    \u3002\n\u30FB\u7B49\u5DEE\u6570\u5217\u306E\u5883\u754C\u3068\u306A\u308B x_0,\
    \ x_1, ..., x_n\n\u30FB\u5404\u5883\u754C\u306E\u9593\u3067\u306E\u4EA4\u5DEE\
    \ dx_0, ..., dx_{n-1}\n*/\npair<vc<int>, vc<int>> min_of_linear_segments(int a,\
    \ int b, int mod) {\n  assert(0 <= a && a < mod);\n  assert(0 <= b && b < mod);\n\
    \  vc<int> X = {0};\n  vc<int> DX;\n  int g = gcd(a, mod);\n  a /= g, b /= g,\
    \ mod /= g;\n  // p/q <= (mod-a)/mod <= r/s\n  int p = 0, q = 1, r = 1, s = 1;\n\
    \  int det_l = mod - a, det_r = a;\n  int x = 0, y = b;\n\n  while (y) {\n   \
    \ // upd r/s\n    int k = det_r / det_l;\n    det_r %= det_l;\n    if (det_r ==\
    \ 0) {\n      --k;\n      det_r = det_l;\n    }\n    r += k * p;\n    s += k *\
    \ q;\n    while (1) {\n      int k = max(0, ceil(det_l - y, det_r));\n      if\
    \ (det_l - k * det_r <= 0) break;\n      det_l -= k * det_r;\n      p += k * r;\n\
    \      q += k * s;\n      // p/q <= a/mod\n      // (aq - pmod) = det_l \u3092\
    \ y \u304B\u3089\u5F15\u304F\n      k = y / det_l;\n      y -= k * det_l;\n  \
    \    x += q * k;\n      X.eb(x);\n      DX.eb(q);\n    }\n    k = det_l / det_r;\n\
    \    det_l -= k * det_r;\n    p += k * r;\n    q += k * s;\n    assert(min({p,\
    \ q, r, s}) >= 0);\n  }\n  return {X, DX};\n}\n"
  code: "#pragma once\n\n/*\nax + b (x>=0) \u304C\u6700\u5C0F\u3068\u306A\u308B\u3068\
    \u3053\u308D\u306E\u60C5\u5831\u3092\u8FD4\u3059\u3002\nprefix min \u3092\u66F4\
    \u65B0\u3059\u308B x \u5168\u4F53\u304C\u3001\u7B49\u5DEE\u6570\u5217\u306E\u548C\
    \u96C6\u5408\u3002\u6B21\u3092\u8FD4\u3059\u3002\n\u30FB\u7B49\u5DEE\u6570\u5217\
    \u306E\u5883\u754C\u3068\u306A\u308B x_0, x_1, ..., x_n\n\u30FB\u5404\u5883\u754C\
    \u306E\u9593\u3067\u306E\u4EA4\u5DEE dx_0, ..., dx_{n-1}\n*/\npair<vc<int>, vc<int>>\
    \ min_of_linear_segments(int a, int b, int mod) {\n  assert(0 <= a && a < mod);\n\
    \  assert(0 <= b && b < mod);\n  vc<int> X = {0};\n  vc<int> DX;\n  int g = gcd(a,\
    \ mod);\n  a /= g, b /= g, mod /= g;\n  // p/q <= (mod-a)/mod <= r/s\n  int p\
    \ = 0, q = 1, r = 1, s = 1;\n  int det_l = mod - a, det_r = a;\n  int x = 0, y\
    \ = b;\n\n  while (y) {\n    // upd r/s\n    int k = det_r / det_l;\n    det_r\
    \ %= det_l;\n    if (det_r == 0) {\n      --k;\n      det_r = det_l;\n    }\n\
    \    r += k * p;\n    s += k * q;\n    while (1) {\n      int k = max(0, ceil(det_l\
    \ - y, det_r));\n      if (det_l - k * det_r <= 0) break;\n      det_l -= k *\
    \ det_r;\n      p += k * r;\n      q += k * s;\n      // p/q <= a/mod\n      //\
    \ (aq - pmod) = det_l \u3092 y \u304B\u3089\u5F15\u304F\n      k = y / det_l;\n\
    \      y -= k * det_l;\n      x += q * k;\n      X.eb(x);\n      DX.eb(q);\n \
    \   }\n    k = det_l / det_r;\n    det_l -= k * det_r;\n    p += k * r;\n    q\
    \ += k * s;\n    assert(min({p, q, r, s}) >= 0);\n  }\n  return {X, DX};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/min_of_linear_segments.hpp
  requiredBy:
  - mod/max_of_linear_segments.hpp
  - mod/min_of_linear.hpp
  timestamp: '2022-08-16 06:06:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/min_of_mod_of_linear.test.cpp
  - test/mytest/min_of_linear_segments.test.cpp
  - test/mytest/max_of_linear_segments.test.cpp
documentation_of: mod/min_of_linear_segments.hpp
layout: document
redirect_from:
- /library/mod/min_of_linear_segments.hpp
- /library/mod/min_of_linear_segments.hpp.html
title: mod/min_of_linear_segments.hpp
---
