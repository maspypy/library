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
  bundledCode: "#line 1 \"poly/convolution_naive.hpp\"\ntemplate <class T>\r\nvector<T>\
    \ convolution_naive(const vector<T>& a, const vector<T>& b) {\r\n  int n = int(a.size()),\
    \ m = int(b.size());\r\n  vector<T> ans(n + m - 1);\r\n  if (n < m) {\r\n    FOR(j,\
    \ m) FOR(i, n) ans[i + j] += a[i] * b[j];\r\n  } else {\r\n    FOR(i, n) FOR(j,\
    \ m) ans[i + j] += a[i] * b[j];\r\n  }\r\n  return ans;\r\n}\r\n"
  code: "template <class T>\r\nvector<T> convolution_naive(const vector<T>& a, const\
    \ vector<T>& b) {\r\n  int n = int(a.size()), m = int(b.size());\r\n  vector<T>\
    \ ans(n + m - 1);\r\n  if (n < m) {\r\n    FOR(j, m) FOR(i, n) ans[i + j] += a[i]\
    \ * b[j];\r\n  } else {\r\n    FOR(i, n) FOR(j, m) ans[i + j] += a[i] * b[j];\r\
    \n  }\r\n  return ans;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/convolution_naive.hpp
  requiredBy: []
  timestamp: '2022-05-02 12:36:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/convolution_naive.hpp
layout: document
redirect_from:
- /library/poly/convolution_naive.hpp
- /library/poly/convolution_naive.hpp.html
title: poly/convolution_naive.hpp
---
