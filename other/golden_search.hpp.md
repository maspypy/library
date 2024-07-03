---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc314.test.cpp
    title: test_atcoder/abc314.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/golden_search.hpp\"\n// return : (fx, x)\n// f \u304C\
    \u8A55\u4FA1\u3055\u308C\u308B\u56DE\u6570\uFF1A2 + iter\n// \u5E45\u304C 1/phi^{iter}\
    \ \u500D\u306B\u306A\u308B. iter = 44: 1e-9.\ntemplate <typename Re, bool MINIMIZE,\
    \ typename F>\npair<Re, Re> golden_search(F f, Re lx, Re rx, int iter = 50) {\n\
    \  assert(lx <= rx);\n  Re inv_phi = (sqrtl(5) - 1.0) * 0.5;\n  Re inv_phi_2 =\
    \ inv_phi * inv_phi;\n  Re x1 = lx, x4 = rx;\n  Re x2 = x1 + inv_phi_2 * (x4 -\
    \ x1);\n  Re x3 = x1 + inv_phi * (x4 - x1);\n  Re y2 = f(x2), y3 = f(x3);\n  auto\
    \ comp = [&](Re a, Re b) -> bool {\n    if constexpr (MINIMIZE)\n      return\
    \ a < b;\n    else\n      return a > b;\n  };\n\n  FOR(iter) {\n    if (comp(y2,\
    \ y3)) {\n      x4 = x3, x3 = x2, y3 = y2;\n      x2 = x1 + inv_phi_2 * (x4 -\
    \ x1);\n      y2 = f(x2);\n    } else {\n      x1 = x2, x2 = x3, y2 = y3;\n  \
    \    x3 = x1 + inv_phi * (x4 - x1);\n      y3 = f(x3);\n    }\n  }\n  return (comp(y2,\
    \ y3) ? pair<Re, Re>{y2, x2} : pair<Re, Re>{y3, x3});\n}\n"
  code: "// return : (fx, x)\n// f \u304C\u8A55\u4FA1\u3055\u308C\u308B\u56DE\u6570\
    \uFF1A2 + iter\n// \u5E45\u304C 1/phi^{iter} \u500D\u306B\u306A\u308B. iter =\
    \ 44: 1e-9.\ntemplate <typename Re, bool MINIMIZE, typename F>\npair<Re, Re> golden_search(F\
    \ f, Re lx, Re rx, int iter = 50) {\n  assert(lx <= rx);\n  Re inv_phi = (sqrtl(5)\
    \ - 1.0) * 0.5;\n  Re inv_phi_2 = inv_phi * inv_phi;\n  Re x1 = lx, x4 = rx;\n\
    \  Re x2 = x1 + inv_phi_2 * (x4 - x1);\n  Re x3 = x1 + inv_phi * (x4 - x1);\n\
    \  Re y2 = f(x2), y3 = f(x3);\n  auto comp = [&](Re a, Re b) -> bool {\n    if\
    \ constexpr (MINIMIZE)\n      return a < b;\n    else\n      return a > b;\n \
    \ };\n\n  FOR(iter) {\n    if (comp(y2, y3)) {\n      x4 = x3, x3 = x2, y3 = y2;\n\
    \      x2 = x1 + inv_phi_2 * (x4 - x1);\n      y2 = f(x2);\n    } else {\n   \
    \   x1 = x2, x2 = x3, y2 = y3;\n      x3 = x1 + inv_phi * (x4 - x1);\n      y3\
    \ = f(x3);\n    }\n  }\n  return (comp(y2, y3) ? pair<Re, Re>{y2, x2} : pair<Re,\
    \ Re>{y3, x3});\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/golden_search.hpp
  requiredBy: []
  timestamp: '2024-06-28 09:49:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc314.test.cpp
documentation_of: other/golden_search.hpp
layout: document
redirect_from:
- /library/other/golden_search.hpp
- /library/other/golden_search.hpp.html
title: other/golden_search.hpp
---
