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
  bundledCode: "#line 1 \"geo/integral.hpp\"\ntemplate <typename Re, typename F>\n\
    Re integral(Re a, Re b, F f, int n) {\n  Re I = 0;\n  Re dx = (b - a) / n;\n \
    \ Re fl = 0, fr = f(a);\n  FOR(i, n) {\n    Re lx = a + dx * i;\n    Re rx = lx\
    \ + dx;\n    fl = fr;\n    fr = f(rx);\n    Re fm = f((lx + rx) / 2);\n    I +=\
    \ fl + 4 * fm + fr;\n  }\n  return I * dx / 6;\n}\n"
  code: "template <typename Re, typename F>\nRe integral(Re a, Re b, F f, int n) {\n\
    \  Re I = 0;\n  Re dx = (b - a) / n;\n  Re fl = 0, fr = f(a);\n  FOR(i, n) {\n\
    \    Re lx = a + dx * i;\n    Re rx = lx + dx;\n    fl = fr;\n    fr = f(rx);\n\
    \    Re fm = f((lx + rx) / 2);\n    I += fl + 4 * fm + fr;\n  }\n  return I *\
    \ dx / 6;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geo/integral.hpp
  requiredBy: []
  timestamp: '2022-09-24 23:43:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1319.test.cpp
documentation_of: geo/integral.hpp
layout: document
redirect_from:
- /library/geo/integral.hpp
- /library/geo/integral.hpp.html
title: geo/integral.hpp
---
