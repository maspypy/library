---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: other/kth_next_permutation.hpp
    title: other/kth_next_permutation.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/pbds.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    using namespace __gnu_pbds;\n\ntemplate <typename KEY>\nusing pbds_set = tree<KEY,\
    \ null_type, less<KEY>, rb_tree_tag,\n                      tree_order_statistics_node_update>;\n"
  code: "#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    #include <ext/pb_ds/tag_and_trait.hpp>\nusing namespace __gnu_pbds;\n\ntemplate\
    \ <typename KEY>\nusing pbds_set = tree<KEY, null_type, less<KEY>, rb_tree_tag,\n\
    \                      tree_order_statistics_node_update>;\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/pbds.hpp
  requiredBy:
  - other/kth_next_permutation.hpp
  timestamp: '2022-05-09 16:18:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/pbds.hpp
layout: document
redirect_from:
- /library/ds/pbds.hpp
- /library/ds/pbds.hpp.html
title: ds/pbds.hpp
---
