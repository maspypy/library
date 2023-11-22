---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc220g.test.cpp
    title: test_atcoder/abc220g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/max2.hpp\"\n\ntemplate <typename T, typename\
    \ KEY>\nstruct Monoid_Max2 {\n  struct Data {\n    T max1, max2;\n    KEY key1,\
    \ key2;\n    bool add_element(T x, KEY key) {\n      if (key1 == key) { return\
    \ chmax(max1, x); }\n      if (key2 == key) {\n        bool upd = chmax(max2,\
    \ x);\n        if (max1 < max2) swap(max1, max2), swap(key1, key2);\n        return\
    \ upd;\n      }\n      if (max1 < x) {\n        max2 = max1, key2 = key1, max1\
    \ = x, key1 = key;\n        return 1;\n      }\n      elif (max2 < x) {\n    \
    \    max2 = x, key2 = key;\n        return 1;\n      }\n      return 0;\n    }\n\
    \  };\n  using value_type = Data;\n  using X = value_type;\n\n  static X op(X\
    \ x, X y) {\n    x.add_element(y.max1, y.key1);\n    x.add_element(y.max2, y.key2);\n\
    \    return x;\n  }\n  static constexpr X unit() { return {-infty<T>, -infty<T>,\
    \ 0, 0}; }\n  static constexpr bool commute = true;\n};\n"
  code: "#pragma once\n\ntemplate <typename T, typename KEY>\nstruct Monoid_Max2 {\n\
    \  struct Data {\n    T max1, max2;\n    KEY key1, key2;\n    bool add_element(T\
    \ x, KEY key) {\n      if (key1 == key) { return chmax(max1, x); }\n      if (key2\
    \ == key) {\n        bool upd = chmax(max2, x);\n        if (max1 < max2) swap(max1,\
    \ max2), swap(key1, key2);\n        return upd;\n      }\n      if (max1 < x)\
    \ {\n        max2 = max1, key2 = key1, max1 = x, key1 = key;\n        return 1;\n\
    \      }\n      elif (max2 < x) {\n        max2 = x, key2 = key;\n        return\
    \ 1;\n      }\n      return 0;\n    }\n  };\n  using value_type = Data;\n  using\
    \ X = value_type;\n\n  static X op(X x, X y) {\n    x.add_element(y.max1, y.key1);\n\
    \    x.add_element(y.max2, y.key2);\n    return x;\n  }\n  static constexpr X\
    \ unit() { return {-infty<T>, -infty<T>, 0, 0}; }\n  static constexpr bool commute\
    \ = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/max2.hpp
  requiredBy: []
  timestamp: '2023-11-03 13:22:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc220g.test.cpp
documentation_of: alg/monoid/max2.hpp
layout: document
redirect_from:
- /library/alg/monoid/max2.hpp
- /library/alg/monoid/max2.hpp.html
title: alg/monoid/max2.hpp
---
