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
  bundledCode: "#line 1 \"string/minimum_cyclic_shift.hpp\"\n\n// \u59CB\u70B9\u3092\
    \u8FD4\u3059\nint minimum_cyclic_shift(string S) {\n  int n = len(S), i = 0, ans\
    \ = 0;\n  S += S;\n  while (i < n) {\n    ans = i;\n    int j = i + 1, k = i;\n\
    \    while (j < i + n && S[k] <= S[j]) {\n      if (S[k] < S[j])\n        k =\
    \ i;\n      else\n        k++;\n      j++;\n    }\n    while (i <= k) i += j -\
    \ k;\n  }\n  return ans;\n}\n"
  code: "\n// \u59CB\u70B9\u3092\u8FD4\u3059\nint minimum_cyclic_shift(string S) {\n\
    \  int n = len(S), i = 0, ans = 0;\n  S += S;\n  while (i < n) {\n    ans = i;\n\
    \    int j = i + 1, k = i;\n    while (j < i + n && S[k] <= S[j]) {\n      if\
    \ (S[k] < S[j])\n        k = i;\n      else\n        k++;\n      j++;\n    }\n\
    \    while (i <= k) i += j - k;\n  }\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/minimum_cyclic_shift.hpp
  requiredBy: []
  timestamp: '2025-05-18 17:51:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/minimum_cyclic_shift.hpp
layout: document
redirect_from:
- /library/string/minimum_cyclic_shift.hpp
- /library/string/minimum_cyclic_shift.hpp.html
title: string/minimum_cyclic_shift.hpp
---
