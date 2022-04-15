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
  bundledCode: "#line 1 \"other/generate_multisets.hpp\"\n// \u9577\u3055 n \u306E\
    \u975E\u8CA0\u6574\u6570\u5217\u3067\u3001\u7DCF\u548C\u304C k \u306E\u3082\u306E\
    \u3092\u5168\u90E8\u751F\u6210\u3059\u308B\r\nvc<vc<int>> generate_multisets(int\
    \ n, int k) {\r\n  vc<vc<int>> res;\r\n  vc<int> A(n);\r\n  auto dfs = [&](auto\
    \ self, ll p, ll s) -> void {\r\n    if (p == n - 1) {\r\n      A[p] = s;\r\n\
    \      res.eb(A);\r\n      return;\r\n    }\r\n    FOR(x, s + 1) {\r\n      A[p]\
    \ = x;\r\n      self(self, p + 1, s - x);\r\n    }\r\n  };\r\n  dfs(dfs, 0, k);\r\
    \n  return res;\r\n}\r\n"
  code: "// \u9577\u3055 n \u306E\u975E\u8CA0\u6574\u6570\u5217\u3067\u3001\u7DCF\u548C\
    \u304C k \u306E\u3082\u306E\u3092\u5168\u90E8\u751F\u6210\u3059\u308B\r\nvc<vc<int>>\
    \ generate_multisets(int n, int k) {\r\n  vc<vc<int>> res;\r\n  vc<int> A(n);\r\
    \n  auto dfs = [&](auto self, ll p, ll s) -> void {\r\n    if (p == n - 1) {\r\
    \n      A[p] = s;\r\n      res.eb(A);\r\n      return;\r\n    }\r\n    FOR(x,\
    \ s + 1) {\r\n      A[p] = x;\r\n      self(self, p + 1, s - x);\r\n    }\r\n\
    \  };\r\n  dfs(dfs, 0, k);\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/generate_multisets.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/generate_multisets.hpp
layout: document
redirect_from:
- /library/other/generate_multisets.hpp
- /library/other/generate_multisets.hpp.html
title: other/generate_multisets.hpp
---
