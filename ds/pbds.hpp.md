---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: seq/kth_next_permutation.hpp
    title: seq/kth_next_permutation.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/0343.test.cpp
    title: test/aoj/0343.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/pbds.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    using namespace __gnu_pbds;\n\n// \u304A\u624B\u8EFD\u3060\u3051\u3069\u3001\u5EA7\
    \u5727\uFF0BBIT\u3068\u304B\u306E\u65B9\u304C\u304B\u306A\u308A\u901F\u3044\u306E\
    \u3067\u6CE8\u610F\uFF01\ntemplate <typename KEY>\nusing pbds_set = tree<KEY,\
    \ null_type, less<KEY>, rb_tree_tag,\n                      tree_order_statistics_node_update>;\n"
  code: "#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    #include <ext/pb_ds/tag_and_trait.hpp>\nusing namespace __gnu_pbds;\n\n// \u304A\
    \u624B\u8EFD\u3060\u3051\u3069\u3001\u5EA7\u5727\uFF0BBIT\u3068\u304B\u306E\u65B9\
    \u304C\u304B\u306A\u308A\u901F\u3044\u306E\u3067\u6CE8\u610F\uFF01\ntemplate <typename\
    \ KEY>\nusing pbds_set = tree<KEY, null_type, less<KEY>, rb_tree_tag,\n      \
    \                tree_order_statistics_node_update>;\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/pbds.hpp
  requiredBy:
  - seq/kth_next_permutation.hpp
  timestamp: '2022-08-27 23:26:12+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/0343.test.cpp
documentation_of: ds/pbds.hpp
layout: document
redirect_from:
- /library/ds/pbds.hpp
- /library/ds/pbds.hpp.html
title: ds/pbds.hpp
---
