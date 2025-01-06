---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/shortest_path/top2_dijkstra.hpp
    title: graph/shortest_path/top2_dijkstra.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/min2.hpp\"\n\ntemplate <typename T, typename\
    \ KEY>\nstruct Monoid_Min2 {\n  struct Data {\n    T min1, min2;\n    KEY key1,\
    \ key2;\n    bool add_element(T x, KEY key) {\n      if (key1 == key) { return\
    \ chmin(min1, x); }\n      if (key2 == key) {\n        bool upd = chmin(min2,\
    \ x);\n        if (min1 > min2) swap(min1, min2), swap(key1, key2);\n        return\
    \ upd;\n      }\n      if (min1 > x) {\n        min2 = min1, key2 = key1, min1\
    \ = x, key1 = key;\n        return 1;\n      }\n      elif (min2 > x) {\n    \
    \    min2 = x, key2 = key;\n        return 1;\n      }\n      return 0;\n    }\n\
    \  };\n  using value_type = Data;\n  using X = value_type;\n\n  static X op(X\
    \ x, X y) {\n    x.add_element(y.min1, y.key1);\n    x.add_element(y.min2, y.key2);\n\
    \    return x;\n  }\n  static constexpr X unit() { return {infty<T>, infty<T>,\
    \ -1, -1}; }\n  static constexpr bool commute = true;\n};\n"
  code: "#pragma once\n\ntemplate <typename T, typename KEY>\nstruct Monoid_Min2 {\n\
    \  struct Data {\n    T min1, min2;\n    KEY key1, key2;\n    bool add_element(T\
    \ x, KEY key) {\n      if (key1 == key) { return chmin(min1, x); }\n      if (key2\
    \ == key) {\n        bool upd = chmin(min2, x);\n        if (min1 > min2) swap(min1,\
    \ min2), swap(key1, key2);\n        return upd;\n      }\n      if (min1 > x)\
    \ {\n        min2 = min1, key2 = key1, min1 = x, key1 = key;\n        return 1;\n\
    \      }\n      elif (min2 > x) {\n        min2 = x, key2 = key;\n        return\
    \ 1;\n      }\n      return 0;\n    }\n  };\n  using value_type = Data;\n  using\
    \ X = value_type;\n\n  static X op(X x, X y) {\n    x.add_element(y.min1, y.key1);\n\
    \    x.add_element(y.min2, y.key2);\n    return x;\n  }\n  static constexpr X\
    \ unit() { return {infty<T>, infty<T>, -1, -1}; }\n  static constexpr bool commute\
    \ = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/min2.hpp
  requiredBy:
  - graph/shortest_path/top2_dijkstra.hpp
  timestamp: '2023-12-23 11:53:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: alg/monoid/min2.hpp
layout: document
redirect_from:
- /library/alg/monoid/min2.hpp
- /library/alg/monoid/min2.hpp.html
title: alg/monoid/min2.hpp
---
