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
  bundledCode: "#line 1 \"alg/monoid/lcm.hpp\"\n\n// \u5927\u304D\u3044\u3068\u304D\
    \u306F infty<T>\ntemplate <typename T>\nstruct Monoid_Lcm {\n  using value_type\
    \ = T;\n  using X = value_type;\n  static X op(X x, X y) {\n    if (x == infty<T>\
    \ || y == infty<T>) return infty<T>;\n    x /= gcd(x, y);\n    if (x >= ceil(infty<T>,\
    \ y)) return infty<T>;\n    return x * y;\n  }\n  static constexpr X unit() {\
    \ return 1; }\n  static constexpr bool commute = 1;\n};\n"
  code: "\n// \u5927\u304D\u3044\u3068\u304D\u306F infty<T>\ntemplate <typename T>\n\
    struct Monoid_Lcm {\n  using value_type = T;\n  using X = value_type;\n  static\
    \ X op(X x, X y) {\n    if (x == infty<T> || y == infty<T>) return infty<T>;\n\
    \    x /= gcd(x, y);\n    if (x >= ceil(infty<T>, y)) return infty<T>;\n    return\
    \ x * y;\n  }\n  static constexpr X unit() { return 1; }\n  static constexpr bool\
    \ commute = 1;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/lcm.hpp
  requiredBy: []
  timestamp: '2023-07-03 05:47:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/lcm.hpp
layout: document
redirect_from:
- /library/alg/monoid/lcm.hpp
- /library/alg/monoid/lcm.hpp.html
title: alg/monoid/lcm.hpp
---
