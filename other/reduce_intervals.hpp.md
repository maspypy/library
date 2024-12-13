---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/reduce_intervals.test.cpp
    title: test/1_mytest/reduce_intervals.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/reduce_intervals.hpp\"\n\n// rm_included = true :\
    \ I < J \u3068\u306A\u308B J \u304C\u5B58\u5728\u3059\u308C\u3070 I \u3092\u6D88\
    \u3059\n// rm_included = false : I > J \u3068\u306A\u308B J \u304C\u5B58\u5728\
    \u3059\u308C\u3070 I \u3092\u6D88\u3059\n// \u6B8B\u3059\u533A\u9593\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u533A\u9593\u306E\u9806\u5E8F\u306B\u3064\
    \u3044\u3066\u30BD\u30FC\u30C8\u3057\u3066\u8FD4\u3059\ntemplate <typename T>\n\
    vc<int> reduce_intervals(vc<T> L, vc<T> R, bool rm_included) {\n  int N = len(L);\n\
    \  vc<int> ANS;\n  vc<int> I(N);\n  FOR(i, N) I[i] = i;\n  if (rm_included) {\n\
    \    sort(all(I), [&](auto& a, auto& b) -> bool {\n      if (L[a] != L[b]) return\
    \ L[a] < L[b];\n      return R[a] > R[b];\n    });\n    for (auto& j: I) {\n \
    \     if (!ANS.empty()) {\n        int i = ANS.back();\n        if (R[j] <= R[i]\
    \ && R[j] - L[j] < R[i] - L[i]) continue;\n      }\n      ANS.eb(j);\n    }\n\
    \  } else {\n    sort(all(I), [&](auto& a, auto& b) -> bool {\n      if (R[a]\
    \ != R[b]) return R[a] < R[b];\n      return L[a] > L[b];\n    });\n    for (auto&\
    \ j: I) {\n      if (!ANS.empty()) {\n        int i = ANS.back();\n        if\
    \ (L[j] <= L[i] && R[j] - L[j] > R[i] - L[i]) continue;\n      }\n      ANS.eb(j);\n\
    \    }\n  }\n  return ANS;\n}\n"
  code: "\n// rm_included = true : I < J \u3068\u306A\u308B J \u304C\u5B58\u5728\u3059\
    \u308C\u3070 I \u3092\u6D88\u3059\n// rm_included = false : I > J \u3068\u306A\
    \u308B J \u304C\u5B58\u5728\u3059\u308C\u3070 I \u3092\u6D88\u3059\n// \u6B8B\u3059\
    \u533A\u9593\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u533A\u9593\u306E\
    \u9806\u5E8F\u306B\u3064\u3044\u3066\u30BD\u30FC\u30C8\u3057\u3066\u8FD4\u3059\
    \ntemplate <typename T>\nvc<int> reduce_intervals(vc<T> L, vc<T> R, bool rm_included)\
    \ {\n  int N = len(L);\n  vc<int> ANS;\n  vc<int> I(N);\n  FOR(i, N) I[i] = i;\n\
    \  if (rm_included) {\n    sort(all(I), [&](auto& a, auto& b) -> bool {\n    \
    \  if (L[a] != L[b]) return L[a] < L[b];\n      return R[a] > R[b];\n    });\n\
    \    for (auto& j: I) {\n      if (!ANS.empty()) {\n        int i = ANS.back();\n\
    \        if (R[j] <= R[i] && R[j] - L[j] < R[i] - L[i]) continue;\n      }\n \
    \     ANS.eb(j);\n    }\n  } else {\n    sort(all(I), [&](auto& a, auto& b) ->\
    \ bool {\n      if (R[a] != R[b]) return R[a] < R[b];\n      return L[a] > L[b];\n\
    \    });\n    for (auto& j: I) {\n      if (!ANS.empty()) {\n        int i = ANS.back();\n\
    \        if (L[j] <= L[i] && R[j] - L[j] > R[i] - L[i]) continue;\n      }\n \
    \     ANS.eb(j);\n    }\n  }\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: other/reduce_intervals.hpp
  requiredBy: []
  timestamp: '2023-12-22 20:53:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/reduce_intervals.test.cpp
documentation_of: other/reduce_intervals.hpp
layout: document
redirect_from:
- /library/other/reduce_intervals.hpp
- /library/other/reduce_intervals.hpp.html
title: other/reduce_intervals.hpp
---
