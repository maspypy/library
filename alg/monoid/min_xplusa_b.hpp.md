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
  bundledCode: "#line 2 \"alg/monoid/min_xplusa_b.hpp\"\n\r\n// max(x+a, b) \u306E\
    \u5408\u6210\r\ntemplate <typename T>\r\nstruct Monoid_Min_xplusa_b {\r\n  using\
    \ value_type = pi;\r\n  using X = value_type;\r\n  static constexpr T apply(const\
    \ X& a, T& x){\r\n    return min(x + a.fi, a.se);\r\n  }\r\n  static constexpr\
    \ T add(const T& x, const T& y) {\r\n    if (x == numeric_limits<T>::max()) return\
    \ x;\r\n    if (y == numeric_limits<T>::max()) return y;\r\n    return x + y;\r\
    \n  }\r\n  static constexpr X op(const X& A, const X& B) {\r\n    auto& [a, b]\
    \ = A;\r\n    auto& [c, d] = B;\r\n    return {add(a, c), min(add(b, c), d)};\r\
    \n  }\r\n  static constexpr X unit() { return {0, numeric_limits<T>::lowest()};\
    \ }\r\n  static constexpr bool commute = false;\r\n};\n"
  code: "#pragma once\r\n\r\n// max(x+a, b) \u306E\u5408\u6210\r\ntemplate <typename\
    \ T>\r\nstruct Monoid_Min_xplusa_b {\r\n  using value_type = pi;\r\n  using X\
    \ = value_type;\r\n  static constexpr T apply(const X& a, T& x){\r\n    return\
    \ min(x + a.fi, a.se);\r\n  }\r\n  static constexpr T add(const T& x, const T&\
    \ y) {\r\n    if (x == numeric_limits<T>::max()) return x;\r\n    if (y == numeric_limits<T>::max())\
    \ return y;\r\n    return x + y;\r\n  }\r\n  static constexpr X op(const X& A,\
    \ const X& B) {\r\n    auto& [a, b] = A;\r\n    auto& [c, d] = B;\r\n    return\
    \ {add(a, c), min(add(b, c), d)};\r\n  }\r\n  static constexpr X unit() { return\
    \ {0, numeric_limits<T>::lowest()}; }\r\n  static constexpr bool commute = false;\r\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/min_xplusa_b.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/min_xplusa_b.hpp
layout: document
redirect_from:
- /library/alg/monoid/min_xplusa_b.hpp
- /library/alg/monoid/min_xplusa_b.hpp.html
title: alg/monoid/min_xplusa_b.hpp
---
