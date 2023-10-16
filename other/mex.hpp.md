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
  bundledCode: "#line 1 \"other/mex.hpp\"\nint mex(const vc<int>& A) {\n  int n =\
    \ len(A);\n  vc<bool> aru(n + 1);\n  for (auto& x: A)\n    if (x < n) aru[x] =\
    \ 1;\n  int mex = 0;\n  while (aru[mex]) ++mex;\n  return mex;\n}\n"
  code: "int mex(const vc<int>& A) {\n  int n = len(A);\n  vc<bool> aru(n + 1);\n\
    \  for (auto& x: A)\n    if (x < n) aru[x] = 1;\n  int mex = 0;\n  while (aru[mex])\
    \ ++mex;\n  return mex;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/mex.hpp
  requiredBy: []
  timestamp: '2023-10-17 07:10:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/mex.hpp
layout: document
redirect_from:
- /library/other/mex.hpp
- /library/other/mex.hpp.html
title: other/mex.hpp
---
