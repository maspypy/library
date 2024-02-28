---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1319.test.cpp
    title: test/yukicoder/1319.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geo/definite_integral.hpp\"\ntemplate <typename Re, typename\
    \ F>\nRe definite_integral(Re a, Re b, F f, int n) {\n  Re I = 0;\n  Re dx = (b\
    \ - a) / n;\n  Re fl = 0, fr = f(a);\n  FOR(i, n) {\n    Re lx = a + dx * i;\n\
    \    Re rx = lx + dx;\n    fl = fr;\n    fr = f(rx);\n    Re fm = f((lx + rx)\
    \ / 2);\n    I += fl + 4 * fm + fr;\n  }\n  return I * dx / 6;\n}\n"
  code: "template <typename Re, typename F>\nRe definite_integral(Re a, Re b, F f,\
    \ int n) {\n  Re I = 0;\n  Re dx = (b - a) / n;\n  Re fl = 0, fr = f(a);\n  FOR(i,\
    \ n) {\n    Re lx = a + dx * i;\n    Re rx = lx + dx;\n    fl = fr;\n    fr =\
    \ f(rx);\n    Re fm = f((lx + rx) / 2);\n    I += fl + 4 * fm + fr;\n  }\n  return\
    \ I * dx / 6;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geo/definite_integral.hpp
  requiredBy: []
  timestamp: '2023-09-03 02:59:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1319.test.cpp
documentation_of: geo/definite_integral.hpp
layout: document
redirect_from:
- /library/geo/definite_integral.hpp
- /library/geo/definite_integral.hpp.html
title: geo/definite_integral.hpp
---
