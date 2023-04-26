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
  bundledCode: "#line 2 \"poly/count_terms.hpp\"\ntemplate<typename mint>\r\nint count_terms(const\
    \ vc<mint>& f){\r\n  int t = 0;\r\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\
    \n  return t;\r\n}\n"
  code: "#pragma once\r\ntemplate<typename mint>\r\nint count_terms(const vc<mint>&\
    \ f){\r\n  int t = 0;\r\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\n  return\
    \ t;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/count_terms.hpp
  requiredBy: []
  timestamp: '2022-05-02 13:06:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/count_terms.hpp
layout: document
redirect_from:
- /library/poly/count_terms.hpp
- /library/poly/count_terms.hpp.html
title: poly/count_terms.hpp
---
