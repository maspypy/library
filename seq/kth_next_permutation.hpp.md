---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/pbds.hpp
    title: ds/pbds.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1443/problem/E
  bundledCode: "#line 1 \"ds/pbds.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n#include <ext/pb_ds/tag_and_trait.hpp>\n\
    using namespace __gnu_pbds;\n\n// \u304A\u624B\u8EFD\u3060\u3051\u3069\u3001\u5EA7\
    \u5727\uFF0BBIT\u3068\u304B\u306E\u65B9\u304C\u304B\u306A\u308A\u901F\u3044\u306E\
    \u3067\u6CE8\u610F\uFF01\ntemplate <typename KEY>\nusing pbds_set = tree<KEY,\
    \ null_type, less<KEY>, rb_tree_tag,\n                      tree_order_statistics_node_update>;\n\
    #line 2 \"seq/kth_next_permutation.hpp\"\n\n// P \u306E\u8981\u7D20\u306F distinct\u3002\
    \n// k \u500B\u5148\u304C\u306A\u3051\u308C\u3070 P \u304C empty \u306B\u306A\u308B\
    \n// \u3044\u3058\u3063\u305F\u9805\u6570\u3092\u8FD4\u3059\n// https://codeforces.com/contest/1443/problem/E\n\
    template <typename T>\nint kth_next_permutation(vc<T>& P, ll k) {\n  static vc<int>\
    \ rk;\n  vc<T> Q;\n  pbds_set<T> s;\n  while (k && len(P)) {\n    int n = len(rk)\
    \ + 1;\n    int p = P.back();\n    int now = s.order_of_key(p);\n    k += now;\n\
    \    int r = k % n;\n    k /= n;\n    rk.eb(r);\n    Q.eb(P.back());\n    s.insert(P.back());\n\
    \    P.pop_back();\n  }\n\n  if (k) return len(rk);\n  int res = len(rk);\n\n\
    \  while (len(rk)) {\n    int r = rk.back();\n    rk.pop_back();\n    auto it\
    \ = s.find_by_order(r);\n    P.eb((*it));\n    s.erase(it);\n  }\n  return res;\n\
    }\n"
  code: "#include \"ds/pbds.hpp\"\n\n// P \u306E\u8981\u7D20\u306F distinct\u3002\n\
    // k \u500B\u5148\u304C\u306A\u3051\u308C\u3070 P \u304C empty \u306B\u306A\u308B\
    \n// \u3044\u3058\u3063\u305F\u9805\u6570\u3092\u8FD4\u3059\n// https://codeforces.com/contest/1443/problem/E\n\
    template <typename T>\nint kth_next_permutation(vc<T>& P, ll k) {\n  static vc<int>\
    \ rk;\n  vc<T> Q;\n  pbds_set<T> s;\n  while (k && len(P)) {\n    int n = len(rk)\
    \ + 1;\n    int p = P.back();\n    int now = s.order_of_key(p);\n    k += now;\n\
    \    int r = k % n;\n    k /= n;\n    rk.eb(r);\n    Q.eb(P.back());\n    s.insert(P.back());\n\
    \    P.pop_back();\n  }\n\n  if (k) return len(rk);\n  int res = len(rk);\n\n\
    \  while (len(rk)) {\n    int r = rk.back();\n    rk.pop_back();\n    auto it\
    \ = s.find_by_order(r);\n    P.eb((*it));\n    s.erase(it);\n  }\n  return res;\n\
    }"
  dependsOn:
  - ds/pbds.hpp
  isVerificationFile: false
  path: seq/kth_next_permutation.hpp
  requiredBy: []
  timestamp: '2022-10-21 20:37:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/kth_next_permutation.hpp
layout: document
redirect_from:
- /library/seq/kth_next_permutation.hpp
- /library/seq/kth_next_permutation.hpp.html
title: seq/kth_next_permutation.hpp
---
