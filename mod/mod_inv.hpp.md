---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"mod/mod_inv.hpp\"\nll mod_inv(ll val, ll mod) {\r\n  int\
    \ a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n    t = a / b;\r\n\
    \    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if(u < 0) u += mod;\r\
    \n  return u;\r\n}\r\n"
  code: "ll mod_inv(ll val, ll mod) {\r\n  int a = val, b = mod, u = 1, v = 0, t;\r\
    \n  while (b > 0) {\r\n    t = a / b;\r\n    swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\r\n  }\r\n  if(u < 0) u += mod;\r\n  return u;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: mod/mod_inv.hpp
  requiredBy:
  - mod/mod_kth_root.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/kth_root_mod.test.cpp
documentation_of: mod/mod_inv.hpp
layout: document
redirect_from:
- /library/mod/mod_inv.hpp
- /library/mod/mod_inv.hpp.html
title: mod/mod_inv.hpp
---
