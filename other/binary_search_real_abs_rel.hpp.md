---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/binary_search_real_abs_rel.hpp\"\n\n// \u7D76\u5BFE\
    \u8AA4\u5DEE\u307E\u305F\u306F\u76F8\u5BFE\u8AA4\u5DEE\u3092\u5C0F\u3055\u304F\
    \u3059\u308B\u3068\u304D\u306B\u56DE\u6570\u3092\u9811\u5F35\u3063\u3066\u6E1B\
    \u3089\u3059\n// ok, ng \u304C\u975E\u8CA0\u3067\u3042\u308B\u3053\u3068\u3092\
    \u4EEE\u5B9A\ntemplate <typename F>\ndouble binary_search_real_abs_rel(F check,\
    \ double ok, double ng, double eps) {\n  using Re = double;\n  Re l, r;\n  bool\
    \ l_is_ok;\n  if (ok > ng) {\n    l = ng, r = ok, l_is_ok = false;\n  } else {\n\
    \    l = ok, r = ng, l_is_ok = true;\n  }\n  auto upd = [&](Re x) -> void { (check(x)\
    \ ^ l_is_ok ? r : l) = x; };\n\n  if (l <= 1 && 1 <= r) upd(1);\n\n  if (1 <=\
    \ l) {\n    // \u76F8\u5BFE\u8AA4\u5DEE\u3092\u72D9\u3046\n    while (r / l >\
    \ 1.0 + eps) upd(sqrt(l) * sqrt(r));\n    return sqrt(l) * sqrt(r);\n  } else\
    \ {\n    // \u7D76\u5BFE\u8AA4\u5DEE\u3092\u72D9\u3046\n    while (r - l > eps)\
    \ upd((l + r) / 2);\n    return (l + r) / 2;\n  }\n}\n"
  code: "\n// \u7D76\u5BFE\u8AA4\u5DEE\u307E\u305F\u306F\u76F8\u5BFE\u8AA4\u5DEE\u3092\
    \u5C0F\u3055\u304F\u3059\u308B\u3068\u304D\u306B\u56DE\u6570\u3092\u9811\u5F35\
    \u3063\u3066\u6E1B\u3089\u3059\n// ok, ng \u304C\u975E\u8CA0\u3067\u3042\u308B\
    \u3053\u3068\u3092\u4EEE\u5B9A\ntemplate <typename F>\ndouble binary_search_real_abs_rel(F\
    \ check, double ok, double ng, double eps) {\n  using Re = double;\n  Re l, r;\n\
    \  bool l_is_ok;\n  if (ok > ng) {\n    l = ng, r = ok, l_is_ok = false;\n  }\
    \ else {\n    l = ok, r = ng, l_is_ok = true;\n  }\n  auto upd = [&](Re x) ->\
    \ void { (check(x) ^ l_is_ok ? r : l) = x; };\n\n  if (l <= 1 && 1 <= r) upd(1);\n\
    \n  if (1 <= l) {\n    // \u76F8\u5BFE\u8AA4\u5DEE\u3092\u72D9\u3046\n    while\
    \ (r / l > 1.0 + eps) upd(sqrt(l) * sqrt(r));\n    return sqrt(l) * sqrt(r);\n\
    \  } else {\n    // \u7D76\u5BFE\u8AA4\u5DEE\u3092\u72D9\u3046\n    while (r -\
    \ l > eps) upd((l + r) / 2);\n    return (l + r) / 2;\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/binary_search_real_abs_rel.hpp
  requiredBy: []
  timestamp: '2026-08-13 01:21:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/binary_search_real_abs_rel.hpp
layout: document
redirect_from:
- /library/other/binary_search_real_abs_rel.hpp
- /library/other/binary_search_real_abs_rel.hpp.html
title: other/binary_search_real_abs_rel.hpp
---
